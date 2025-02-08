this is the one true **fair-share** scheduler, which guarantees the system that each job will obtain a certain percentage of CPU time. however, a big drawback to this scheduler is that it performs **horrible in turnaround or response time**.

## basic concepts
the entire system revolves around the concepts of **tickets**, which is CPU currency that represents the share of a certain resource that a process should receive.

the **percent of tickets** represents its share of the system resource in question. for example, suppose that there are processes A, and B. suppose that:
- A receives 75 tickets -> receives 75% of the CPU
- B receives 25 tickets -> receives 25%.

### gambling (lottery scheduling)
after tickets are distributed, the scheduler then picks a **winning ticket**, loads the state of the winning process, and runs it.

we need to think about this in the long run, where the longer these two jobs compete, the closer they are to their designated percentages.

under the hood, the user allocates tickets among their own jobs in whatever **ticket currency** they choose, and then the system converts the currency into the correct **global value**. so, suppose that A and B receives 100 global tickets each.
- A allocates 500 to A1 -> converted to 50 in global currency
- A allocates 500 to A2 -> converted to 50 in global currency
- B allocates 10 B currency to B1 -> converted to 100 in global currency

a process can also perform **ticket transfer**, which temporarily hands off its tickets to *another process*, or go through **ticket inflation**, which temporarily raises or lowers the number of tickets it owns. 
- if a process needs more CPU time, it can boost its own tickets.

in implementation, the system probably keeps a list of processes and the number of allocated tickets: 

```
[(A, 100), (B, 50), (C, 250)]
```

and iterates through the array to find which winning tickets belongs to which process.

```c
int counter = 0;  
int winner = getrandom(0, totaltickets);  
node_t *current = head;

// loop until the sum of ticket values is > the winner
while (current) {  
	counter = counter + current->tickets;  
	if (counter > winner)  
		break; // found the winner  
	current = current->next;  
}  
```

the system will also keep an unfairness metric $U$, which is the time that the first job is complete divided by the time that the second job completes. the closer it is to 1, the closer the jobs are to finishing at the same time (better outcome).

suppose that there are two jobs, each with runtime 10.
- first job will finish at runtime 10
- second job at runtime 10

then:
$$U=\frac{10}{20}$$
in reality, what we observe is that $U$ will get closer to 1 the longer the jobs are. when it is not very long, unfairness can be quite severe.

### stride scheduling
a **stride** $S$ of a process is computed by taking an arbitrary large number, and divide it by the process tickets.
$$S=\frac{\text{large number}}{\text{num tickets of process}}$$
as the process runs, a counter called the **pass value** is incremented by the stride. so, the idea is to pick the process that has **the lowest pass value**.

suppose that A has a stride of 100, B = 200, and C = 40. 

| pass(A) / stride = 100 | pass(B) / stride = 200 | pass(C) / stride = 40 | **who runs?** |
| ---------------------- | ---------------------- | --------------------- | ------------- |
| 0                      | 0                      | 0                     | A             |
| 100                    | 0                      | 0                     | B             |
| 100                    | 200                    | 0                     | C             |
| 100                    | 200                    | 40                    | C             |
| 100                    | 200                    | 80                    | C             |
| 100                    | 200                    | 120                   | A             |
| 200                    | 200                    | 120                   | C             |
| 200                    | 200                    | 160                   | C             |
|                        |                        |                       |               |
once a new job enters with pass value of 0, it will **monopolize the CPU.**

## Linux completely fair scheduler (CFS)
as each process runs, it accumulates **virtual runtime** (`vruntime`). the CFS will pick the process with the **lowest** `vruntime` to run next.

immediately, we encounter two big issues: 
- switches too often: fairness is increased, but at the cost of performance
- switches less often: better performance, but less fair overall.

to resolve this, CFS manages a few parameters to help.
### `sched_latency`
the CFS will divide this value by the number of processes to determine the time slice. over this period, CFS will be **completely fair**. 

if `sched_latency` is 48ms and 4 processes are running, the time slice will be 12ms. 

however, if $n$ is large, a lot of context switching will occur, and costing performance. to resolve this, CFS manages another variable: `min_granularity`.
### `min_granularity`
the minimum allowed value of the time slice. also solves the problem of the time slice not being a perfect multiple of the timer interrupt, as CFS tracks `vruntime` precisely, and ideal CPU sharing will be approximated later.

### prioritization
to manage priority, CFS manage an array that maps the priority to weights, and then computers a weighted time slice.
$$\text{time slice}_{k} = \frac{\text{weight}_{k}}{\sum^{n-1}_{{i = 0}}\text{weight}_{i}}\times \text{sched latency}$$
in this case, `vruntime` must also be adapted.
$$\text{vruntime}_{i}+=\frac{\text{weight}_{0}}{\text{weight}_{i}}\cdot \text{runtime}_{i}$$
### efficiency
to do this quickly, CFS uses a red-black tree to run processes.

to prevent new processes or processes that sleep a lot from taking over the CPU, new and blocked processes enter the red-black tree with **minimum** `vruntime`, so jobs that sleep too frequently do not get their fair share.

### cost
context switching itself is fast, but deciding what to run next is expensive!
