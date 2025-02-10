historically, the GPU's performance has always been bottlenecked by the memory bandwidth. i.e. we always have a lot of computing power, but the data that the device is able to move has always been weak.

an application can be:
- **compute-bound**: performance is limited by the FLOPS rate (cores are always fully utilized)
- **memory-bound**: performance limited by memory bandwidth.cores are idling frequently, because memory does not supply data fast enough.

vector addition, e.g. `z[i] = x[i] + y[i]`, is highly memory bound, because there is not much to compute. it does not see a massive speedup, because most of the ALUs are idle.

| variable declaration                     | memory   | scope  | lifetime    |     |
| ---------------------------------------- | -------- | ------ | ----------- | --- |
| `__device__ int globalVar`               | global   | grid   | application |     |
| `__device__ __constant__ int contantVar` | constant | grid   | application |     |
| `__device__ __shared__ int sharedVar`    | shared   | block  | block       |     |
| `int localVar`                           | register | thread | thread      |     |
| `int localVar[N}`                        | global   | thread | thread      |     |

unlike traditional C programming, where declaring `int local` allocates memory on the **stack**, e.g. main memory, the same decl. on the GPU will put the value in a **register**. 

