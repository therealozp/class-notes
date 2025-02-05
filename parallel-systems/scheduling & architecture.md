in reality, we can launch up to millions of threads, but only thousands of blocks. even then, we should launch the number of blocks in the thousands, not just 4 blocks. 

threads in **different blocks** are **asynchronous** (but threads in the *same block* are *synchronous*). this allows blocks to execute in any order, parallel or sequentially. 

so, when writing CUDA programs, we try to write code that do not require synchronicity.
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
