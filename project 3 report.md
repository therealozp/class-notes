## optimizations done
Compared to the original CPU code, some of the modifications I have done include:
- created 2 new kernels to add strings into the bloom filter and check for string existence in the bloom filter
- added a new parameter to let user control the amount of threads per blocks launched
- switched from using `memcpy` inside device function to using bit manipulation, which has the same effect for a little bit faster speed
- changed from using a byte array to a bitmap, which cuts down memory usage by 8x (which is much better than wasting an entire byte for checking existence)

## results report
Because this task is very reminiscent of a perfectly-parallelizable task (and is more compute-heavy than memory-bandwidth heavy), the speedup generally scaled very well as the input size grows.

For this test, everything is ran on my local computer, which as an i5-12600K, and an NVIDIA 3070Ti as the CUDA device. I have also tested this on the GAIVI cluster, with additional reports below. In the interest of saving time, I conducted most of my tests on my local device.

Note that these graphs are plotted at a **logarithmic scale**, so the speedup between GPU and CPU actually **increases** with input.

![[Pasted image 20250423213026.png]]
![[Pasted image 20250423213042.png]]
![[Pasted image 20250423213052.png]]
![[Pasted image 20250423213106.png]]
![[Pasted image 20250423213119.png]]
![[Pasted image 20250423213131.png]]![[Pasted image 20250423213551.png]]

### comparing speedup ratios with respect to input size
As mentioned before, the speedup of the GPU over the CPU scales with the input size. so, while at the start, there isn't a massive speedup, by the input size of 100 million, the speedup has grown to nearly 400x.

I tried to run the same code with 1 billion inputs, however, that took prohibitively long. Moreover, with larger input sizes, there is a limitation with the bit width of the original value containing the input size, so I wasn't able to test the program with the 64-bit unsigned integer limit ($2^{64} - 1$).

![[Pasted image 20250423213748.png]]
### comparing performance between the GAIVI cluster and local GPU
This section serves more as proof that my program compiles and runs on the GAIVI cluster, but I also found some interesting results. For smaller inputs, the GAIVI cluster is extremely fast, but as the input scales, my local GPU seems to have a slight edge in speed. At 100 million inputs, my GPU is 4x faster than the GAIVI cluster.

![[Pasted image 20250423214318.png]]

### runtime at different FPRs
The difference might not seem entirely clear when input sizes are relatively smaller, However, as the input sizes scale, we can see a very big difference between the false positive rates and runtime. namely, lower false positive rates take longer to run than higher.

The biggest comparison here, runtime at 0.05 FPR takes 2x as long as 0.15 FPR, and 4x as long as >0.25 FPR. this has to do entirely with the number of that the algorithm has to process before insertion/checking: 0.05 FPR needs 4 hashes, 0.15 FPR needs 2 hashes, and anything > 0.25 FPR only needs 1 hash. 

So, we can confirm that the scaling results here makes sense.

![[Pasted image 20250423214752.png]]
![[Pasted image 20250423214826.png]]

## final notes
To summarize:
- running the bloom filter on GPU is massively more efficient than running on the CPU
- the speedup factor of the GPU (compared to CPU) scales **exponentially** with the input size
- lower FPRs requires more computation (more hashes) and a longer bitmask, so it takes longer than higher FPRs.

A few other remarks I had while doing this project is that the bit mask will gradually fill up with 1s, without ever having to un-set bits in between. Therefore, without checking strings from outside the originally generated set, one can simply set an entire bitmask of 1's and still receive relatively good results.

By the same token, the metric of FPRs were not really validated due to the lack of strings lying outside of the originally generated set. 