when launching a kernel, we are launching a grid of threads, further subdivided into blocks, and further into warps of threads.

"device functions" mean `__device__`. 

`__device__` functions mean only GPU can can run. contrast with "functions executed on device", which comprises both `__device__` and `__global__`.

correct definition: a **kernel** is a function executed on the GPU (includes both `__device__` and `__global__`)

scratchpad vs. cache memory: the main question is "who controls it"? **cache** is controlled by the runtime system, and **scratchpad** is controlled by the user. so, shared memory is scratchpad, L1 cache is a cache.

thread synchronization are available at both grid level (with `deviceSynchronize`) and block level (with `__syncthreads()`). today, any kind of synchronization is possible.

shuffle instructions allow you to grab register (variable values) from sibling threads. dynamic parallelism allows kernel calling kernel.
26. c
27. d
28. a

parallel reduction kernel (line 29 onwards): `start` variable indicates the starting address of whichever chunk we want to process.

during the reduction scan, we notice that only the first thread will ever have divergence, because entire warps should have bailed out. i.e. 