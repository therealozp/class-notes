owithin each warp, the hardware must **wait** for the longest-running thread to accomplish. this is called **barrier synchronization**, and is very similar to control divergence when some of the threads do not run, resulting in wasted resources. 

however, when considering it on the warp level, mismatching finish times do **NOT** affect performance as much as the thread level does. this is because threads will not be able have the same start anyway, and it will always release computing resources when it is done with execution.

## shared memory
shared memory is in the L1 cache of each streaming multiprocessor (SM). in essence, shared memory and L1 share the same space 
## type qualifiers

| variable declaration                     | memory   | scope  | lifetime    |     |
| ---------------------------------------- | -------- | ------ | ----------- | --- |
| `__device__ int globalVar`               | global   | grid   | application |     |
| `__device__ __constant__ int contantVar` | constant | grid   | application |     |
| `__device__ __shared__ int sharedVar`    | shared   | block  | block       |     |
| `int localVar`                           | register | thread | thread      |     |
| `int localVar[N}`                        | global   | thread | thread      |     |

unlike traditional C programming, where declaring `int local` allocates memory on the **stack**, e.g. main memory, the same decl. on the GPU will put the value in a **register**. 