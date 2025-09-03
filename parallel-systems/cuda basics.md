the increase in cores does not necessarily translate to an increase in power. rather, it all depends on how fast memory can be moved around, aka. **bandwidth**. 

instead of focusing on the TFLOPs, bandwidth would be a better measure of computation power, as **it is the bottleneck**.


## CUDA runtime (software)
**compute preemption** allows priority to be assigned to tasks to be ran on the GPU. it provides a way to avoid long-running kernels from blocking GPU usage to other processes, at the risk of **context-switching** overheads.

two-level thread organization: grid -> block -> threads
- each thread has its own register set
- a block can only be scheduled to **one multiprocessor**. (streaming multiprocessor extended, SMX). each block has access to its own shared memory accessible by its individual threads. we **configure the L1 cache** to get how much shared memory a block has access to. 
- everything inside the grid can access global memory.

|                           | latency (how long we need to wait) | bandwidth (how much data moved / period of time) |     |
| ------------------------- | ---------------------------------- | ------------------------------------------------ | --- |
| registers                 | 1 clock cycle (CC)                 | N/A (only meant to perform computations)         |     |
| L1 cache/shared memory    | 10-20 CC                           | ~10TB/s                                          |     |
| global memory             | 400-500 CC                         | 1.5TB/s (best performing GPU)                    |     |
| host memory (main memory) | -                                  | 200GB/s                                          |     |

although multiple grids can be run at the same time, we look at 1 grid running at a time in this example.

## types of parallelism
- **task parallelism:** where different operations performed on data (same or different). this is usually modest, so parallelism here is also little.
- **data parallelism**: same operations, performed on different data. potentially massive parallelism potential.

### cuda's "hello world"
adding two vectors. note that for correct processing to occur, the two vectors need to be the same dimension. 

a good, simple intuition to parallelize such a task is to let each thread run each addition on one unit, e.g. `a[0] + b[0]`, `a[1] + b[1]`, and so on; or assign one GPU **thread** per vector element.

but how do we know which index `i` we are processing? a strategy would be to map the thread ID to the specific index, e.g. `f(threadID) -> i`. we are given the following variables by the system:
- `blockIdx`
- `gridDim`: how many blocks are there?
- `threadIdx`
- `blockDim`

in the end, the function would look like:

```c
__global__ void vecadd_kernel(float* x, float* y, float* z, int N) {
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	z[i] = x[i] + y[i];
}
```

this program follows SPMD (single program, multiple data), and you're only writing a program to describe **one single thread**. in the above example, there is only `z[i] = x[i] + y[i]` that performs the actual computation.

if the number of threads is greater than the array length, we need to handle that case to do nothing. in this case:

```c
__global__ void vecadd_kernel(float* x, float* y, float* z, int N) {
	int i = blockDim.x * blockIdx.x + threadIdx.x;
	if (i < N) {
		z[i] = x[i] + y[i];
	} 
}
```

### procedure
there are 4 main parts to a GPU system, which consists of:
- the CPU, aka. the **host**
- the main memory (RAM), aka. **host** memory
- the GPU, or the **device**
- GPU memory, or **device memory**

since the GPU and CPU has separate memories, one cannot access the data of another. there is always a transfer process going on when you want a task to be performed in the GPU:
1. allocate GPU memory
2. copy data from host memory to GPU
3. perform computation on GPU
4. copy back from device memory to main memory
5. deallocate GPU memory

> the number one enemy of parallel programming is communication (because you have to transfer data)

```c
cudaError_t cudaMalloc(void **devPtr, size_t size)
```
- `devPtr`: pointer to the pointer to allocated device memory
- `size_t`: requested allocation size (in bytes)

## kernel
a **kernel** function is a function meant to run on many different threads on a grid. or, in other words, threads in the same grid execute the same function known as a **kernel**.

a grid can be launched by **calling a kernel** and configuring it with appropriate grid sizes and block sizes.

a kernel is similar to a C/C++ function, preceded by the keyword `__global__` to indicate that it is a GPU kernel. note that a kernel function will always have the `void` return type.

natively, CUDA uses special keywords to distinguish different threads from each other. 

| keyword      | called from    | executed on |
| ------------ | -------------- | ----------- |
| `__host__`   | host           | host        |
| `__global__` | host or device | device      |
| `__device__` | device         | device      |
a function can be both `__host__` and `__device__`, but it cannot be `__global__` with anything else.