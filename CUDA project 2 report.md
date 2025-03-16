### Methodology
I conducted experiments with different optimization strategies and recorded execution times at different input sizes, at 10k, 50k, 100k, 250k, and 500k. The optimizations explored included:

To walk through the methods: 
1. **Baseline Implementation (No Optimizations)**: 
This is the same baseline code I submitted to project 1. Since this is the first optimization, code is very simplistic, and only consists of the `threadIdx`-based for loop. All updates are done atomically via `atomicAdd`, conducted straight to the global histogram.

2. **Shared Memory in LR Block**:  
This approach mirrors the one discussed in the paper. Namely, I started using shared memory here, and divided it into 2 sections, the left (currently processed) block, and the right (comparison) block. The main motivation behind this approach is that multiple different threads will run and compare with the same comparison block, so caching it to shared memory will reduce memory access time for these comparisons. 

This is divided into two sections, the inter-block computation versus the intra-block computation. Thus, the shared memory region is reused twice, once to load external blocks, then once to load the current block to be computed at the thread-level.

3. **Shared LR with One Local Copy**
This approach takes 2. and adds a local cache to it. This change is motivated by the main bottleneck of the `atomicAdd` operations to the global histogram, so instead, we keep a copy of the histogram in shared memory. At the end of all computations, this shared copy is atomically added back to the global histogram, which saves enormous amounts of time. 

4. **Shared LR with Multiple Dynamic Local Copies**
This uses the same idea as number 3, but is based on the fact that we can use multiple different copies in the shared memory to speed things up even more. At the end, we use a reduction block to sum everything up and atomically add it back to global histogram. The metric to determining the number of local copies to keep is taken from the original paper, and is as follows:

```c
if (num_buckets < 10) {
	num_copies = 32;
} else if (num_buckets < 30) {
	num_copies = 16;
} else if (num_buckets < 90) {
	num_copies = 8;
} else if (num_buckets < 150) {
	num_copies = 4;
} else if (num_buckets < 300) {
	num_copies = 2;
} else {
	num_copies = 1;
}
```

5. **Shared LR with Multiple Local Copies (Coalesced Memory Accesses)**
The last optimization I tried was based on the fact that `atoms` are only partially coalesced, in the fact that it is a struct made up of 3 doubles. Instead, I used 3 different `double` arrays as the `x`, `y`, and `z` coordinates of each atom.
### Results
The following table presents the execution times (in milliseconds) for different optimization techniques:

| Method Name                                 | 10k (ms) | 50k (ms) | 100k (ms) | 250k (ms) | 500k (ms) | 1M (ms)   |
| ------------------------------------------- | -------- | -------- | --------- | --------- | --------- | --------- |
| No optimizations                            | 53.68    | 916.51   | 3244.41   | 19829.87  | 79149.77  | 332838.47 |
| With shared memory in LR block              | 36.31    | 774.64   | 2943.98   | 18270.98  | 73083.99  | 307416.44 |
| Shared LR, 1 local copy                     | 22.83    | 293.25   | 1116.73   | 7079.74   | 28244.35  | 117791.40 |
| Shared LR, multiple (dynamic) local copies  | 19.91    | 304.54   | 1036.49   | 6571.75   | 26200.25  | 109177.33 |
| Shared LR, multiple local copies, coalesced | 19.84    | 272.68   | 1037.28   | 6580.90   | 26282.54  | 109273.33 |

Here are some plots of the running time:

![[Pasted image 20250316174849.png]]

![[Pasted image 20250316174903.png]]

![[Pasted image 20250316174918.png]]

![[Pasted image 20250316174928.png]]

![[Pasted image 20250316174940.png]]

![[Pasted image 20250316174951.png]]

### Findings
-  With regards to correctness, each implementation yields the same result as the previous ones, which are all similar to the CPU implementation. So, improving the program did not affect its correctness!

![[Pasted image 20250316180214.png]]

![[Pasted image 20250316180240.png]]

![[Pasted image 20250316180306.png]]

- Implementing shared memory (LR block) improved performance by reducing redundant global memory accesses. However, this improvement is not significant, as it only cuts the runtime by ~10%.
- The biggest improvement came from using the local copies to mitigate the global-memory atomic adds. Even only one copy is good enough, and reduces the runtime by ~3x, as it cuts down a lot of the bottleneck on having to write to global memory. Now, most reads and writes are done in the shared memory.
- Multiple local copies also improved performance slightly, but not significant compared to the 3x speedup we got from integrating shared memory.
- The difference between partially coalesced and fully coalesced access is nearly non-existent, as they are already incredibly close to each other in terms of memory accesses. 