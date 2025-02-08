a MLFQ is a scheduler that learns from the past to predict the future. its primary objective is to: 
- optimize **turnaround time**, so try to run shorter jobs first
- minimize **response time**, without a priori (deducing from general principle) knowledge of job length.

### basic rules
a MLFQ has a number of distinct **queues**, that are assigned a different priority levels. when a job is ready to run, it is loaded on a single queue. 
- among the queues, jobs are chosen to run from **higher** queues..
- use [[scheduling#round robin|round robin]] scheduling among jobs in the same queue.

the priority of a job is based on how the scheduler observes its behavior. for example:
- if a job repeatedly relinquishes CPU to wait for I/Os, keep it **high priority**.
- if a job uses CPU for extensive amounts of time, **reduce its priority.**

MFLQ's adjustment algorithm is based on a couple of ground rules that helps it approximate SJF:
- when a job enters the system, it is placed at the highest priority
- if a job uses up **the entire time slice** while running, its priority is reduced. 
- if a job gives up the CPU before the time slice is used up, its priority remains unchanged.

the MLFQ always keep the interactive job at the highest priority.

### problems
with the naive MLFQ, if there are too many interactive jobs in the system, the long-running jobs will never receive any CPU time. 

or, the process can **game the scheduler**, and executes 99% of the time slice, and then issue an I/O request. this keeps it at near full utilization at the highest priority.

or another issue, where the program may start off as CPU-intensive, but then switches mode to being interactive with I/O. in this case, will it ever climb back to the necessary priority?

### solutions
to address the issue of too many interactive jobs, the MLFQ will often perform a priority reset, where it **moves all jobs to the topmost queue**. 

to prevent gaming the scheduler, we add in an additional rule: once a job uses its time slice at a given level (regardless of how many times it has relinquished CPU control), we reduce the CPU priority (push it to a lower queue).

### mlfq tuning
the higher-priority queue should have short time slices (< 10ms) to support interactive jobs. on the other hands, lower-priority queues should have longer time slices, to accommodate CPU-intensive jobs.

