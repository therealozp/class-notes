threads/blocks require resources to execute, so the **streaming multiprocessor (SMs)** can accommodate a limited number of threads/blocks at once, while *other blocks* have to wait before it is finished.

in reality, we can launch up to millions of threads, but only thousands of blocks. even then, we should launch the number of blocks in the thousands, not just 4 blocks. 

## architecture
threads are assigned to SMs at the granularity of the **block**, so all threads in a block are assigned **to the same SM**. this makes for *efficient collaboration*.

so, threads in the same block can collaborate in ways that threads in different blocks cannot:
- barrier synchronization
- shared memory
- other stuff

## scheduling considerations
all threads in a block assigned to an SM simultaneously, so it will only ever is assigned when SM secures enough resources. otherwise, running stuff at the same time **leads system to a deadlock**.

### transparent scalability
threads in **different blocks** are **asynchronous** (but threads in the *same block* are *synchronous*). 
- allows blocks to execute in any order
- parallel or sequentially. 

this allows massive code reuse, where the same code can be run on different devices with different amount of hardware parallelism.

so, when writing CUDA programs, we try to write code that **do not require synchronicity.**
## warps
these are **groups of threads**, and the basic unit of scheduling. blocks assigned to an SM are **further divided** into warps for the host to schedule. 

the size of warps are usually device-specific, but to date, it has always been 32 threads/warp. the index of a thread within a warp is also defined in CUDA as `laneID = threadIdx % 32`. 

threads in a warp are scheduled together, and executed following the SIMD (single instruction, multiple data) model. where:
- an instruction is fetched
- all threads in the warp executes the same instruction, but on different data

an advantage of the SIMD model is that it amortizes the cost of running the group of threads. 

however, it comes with a tradeoff:
- different threads taking different execution paths results in **control divergence**, where warp does a pass over each unique execution path (such as an if-else statement). so, in each pass, **threads taking** it will **execute**, **others** will be **disabled**.
- the percentage of threads/cores enabled during SIMD is called *SIMD efficiency.*

### control divergence
things like `if-else` statements and `for` loops will execute on some threads, and sleep on the other threads. this is not good, because this causes wasted resource.

for example, in this case (supposing that each `run` takes 10 time steps):

```c
if (threadIdx.x < 24) {
	run A;
} else {
	run B;
}
run C;
```

- the first 10 time steps, the threads from 0-24 take the A branch, while the other 24-32 sleeps.
- the second 10 time steps, the threads 24-32 finally get executed, while 0-24 sleeps.

this causes a lot of resources to be wasted, and should be avoided whenever possible.

### latency hiding
when a warp needs to wait for a high latency operation, the processor **selects another warp** on the ready queue, and schedule it for execution.

to achieve high degrees of parallelization, we need to have a high number of warps (so that we always have something to do). for this reason, an SM supports far more warps than the actual number of cores it has.