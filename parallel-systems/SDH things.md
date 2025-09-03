## algorithm 3: with privatization
keep a local copy of the output. `syncthreads()` wait for all threads to finish their computation, and copy the local copy into the global result, based on the thread ID.

use a local copy, then atomic add to the final result. if there is only 1 copy of the final histogram, we can do something like: `atomicAdd(&output[t], SHMOut[t]`. 
 - however, this assumes `num_threads` is greater than `num_buckets`. in the case that it isn't, all threads have to do a second round.

### with even more copies
sometimes, keeping a bunch of copies (2 or 4) can give us an even bigger boost.

professor's suggestion: do privatization first, then go to block-level input caching technique