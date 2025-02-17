to start with scheduling, we will set up a few assumptions in terms of workloads for each process, and then one by one violate them.
1. each job runs for the same amount of time
2. all jobs arrive at the same time
3. one started, **they run to completion**
4. they only use the CPU, and no IO
5. known run times

## metrics
the two key metrics we optimize for when building a scheduler is **turnaround** and **fairness**, which are at odds with each other and we need to find some sort of balance between them.
### turnaround time
defined as the period it takes since the job **arrives** on the job queue until the job is **completed**.
$$
T_{\text{turnaround}} = T_{\text{completion}} - T_{\text{arrival}}
$$
### fairness
how evenly CPU power is put toward each job. a scheduler that maximizes this metric is the [[proportional share scheduler]] and, especially. the [[proportional share scheduler#Linux completely fair scheduler (CFS)|completely fair scheduler]].
### response time
period from when job arrives until the first time it is **scheduled**.
$$
T_{\text{responose}} = T_{\text{scheduled}} - T_{\text{arrival}}
$$
## scheduling tactics
### first come, first served (FIFO)
very simple to implement. does exactly what the name says, process each job in the order it is received. 

**convoy effect**: when we relax assumption 1 and let every job take different times to complete, we get massive blockers in scheduling. for example, suppose that A, B, and C arrive in succession, A costs 100s, B and C each cost 10s.

```
|||||||||||||.|||.|||
      A        B   C
```

the, the turnaround time suddenly becomes horrible: 
- A takes 100s to complete
- B takes 110s to complete (blocked by A)
- C takes 120s to complete (blocked by A and B)

### shortest job first (SJF)
SJF always runs the shortest job first, then the next shortest, and so on. the non-preemptive invariant (meaning that each process will run until the end, uninterrupted) still holds.

in this case, suppose that A, B, and C arrive in the same succession, and the running times in the above example still apply.

then, the scheduler will prioritize B and C, meaning:
- B takes 10s to complete
- C takes 20s to complete
- A takes 120 to complete

but, suppose that assumption 2 (same arrival) is relaxed, and jobs arrive at any time. then, when:
- A arrives at $t = 0$
- B and C arrives at $t = 10$ and runs for 10 seconds.

then, A will get executed first, going for the entire 100 seconds, pushing B and C to the back.
### shortest time to completion first (STCF, PSJF)
now, let's violate assumption 3, and jobs do not have to run until completion. when a new job enters the system, we will try to **determine remaining jobs** as well as the new job, and **scheduler whichever has less time left.**

using the same example immediately above, PSJF (preemptive SJF) will run like:

```
||| ^ ||| ^ ||| ^ ||||||||||||||
 A  |  B     C       A finishes
[B and C arrives]
```

however, STCF and related schedulers are **horrible for response time**.
### round robin
is based on **time slices** (also named scheduling quantums). runs a job for a time slice, switch to the next job in the run queue. repeat until all jobs are finished.

the length of a time slice must be a **multiple** of the [[limited direct execution#non-cooperative|timer interrupt]]. RR is fair, but **is horrible with turnaround time**. 

the length of the time slice is critical.
- **longer** time slices amortizes process switching cost, but trades off response time.
- **shorter** time slices is very responsive, but cost of switching will dominate performance in general.

## incorporating I/O
now, let's relax assumption 4 and let jobs be able to perform I/O. 

take the following example:
- A and B needs 50ms of CPU time
- A runs for 10ms and issues an I/O request (10ms each for I/O)
- B uses CPU for 50ms and performs no I/O
- scheduler chooses to run A first, then B

non-overlapping processes waste a lot of resources:
```
AA    AA    AA    AA    AA BB BB BB BB BB
   IO    IO    IO    IO  
```

to maximize CPU utilization, we can execute B while we wait for IO of A:

```
AA BB AA BB AA BB AA BB AA BB
   IO    IO    IO    IO   
```

when a job initiates an I/O request, we change the state to **blocked** to wait for IO completion. the scheduler should then schedule another job on the CPU.

when that request is fulfilled, an interrupt is raised, and the OS moves the process from the **blocked** queue to the **ready** state.
## no more oracles
now, we violate the last assumption, and execution times of jobs **are unknown** to us.

with that change, it is clear that STCF does not work, because the scheduler would not know which job to prioritize. to resolve this, we use the **[[multi-level feedback queue (MLFQ)]]**.

