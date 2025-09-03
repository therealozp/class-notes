a reduction operation **reduces an array of values to one value**. these operations often have a well-defined identity, are associative, and commutative.

for example, take the sum operation. written linearly, it goes like:

```c
float sum = 0;
for (int i = 0; i < N; i++) {
	sum += input[i];
}
```

however, reduction operations are often defined by the existence of two variables: the **accumulator** and the **callback**. so, assuming that `f` is our summation function:

```c
acc = IDENTITY;
for (int i = 0; i < N; i++) {
	acc = f(acc, input[i]);
}
```

in situ computation

thread **anchored** position: a thread is always anchored somewhere in memory. in the following example

stride: for an anchored thread:
- it needs to read some other value
- perform any sort of computation (in register)
- write it to our anchored position

## fixing control divergence
if we apply the upper method, we see that it will be fragmented across the block, where some warps inside of a specific block will finish their work before others do. this leads to a lot of wasted resources, worse when it is spread across the bunch of blocks as the stride increases.

one way to fix it is to chunk everything up together, and essentially push all control divergence to the first warp. instead of referencing memory in strided accesses like

```
i % stride == 0
```

we instead want to change the loop conditions entirely. so:

```c
unsigned i = ????;
for (int stride = blockDim.x; stride >= 1; stride /= 2) {
	if (threadIdx.x < stride) {
		input[i] += input[i + stride]; 
	}
}
```

now, to find the value of `i`, we consider how data is accessed in this scheme. for a very big array of data, elements will be accessed in chunks of size $2\times \text{blockDim.x}$, as we want one block to compute data of double its size. then, to compute the offset in memory of each block, we also multiply that value by the `blockIdx.x`

now that we have accounted for the block level, we think about which offset in the array the thread should begin processing. for this, we can simply use the `threadIdx.x` variable. so, in total, our final code will be: 

```c
unsigned i = 2 * blockDim.x * blockIdx.x + threadIdx.x;
// also check if i is smaller than N to execute
for (int stride = blockDim.x; stride >= 1; stride /= 2) {
	if (threadIdx.x < stride) {
		input[i] += input[i + stride]; 
	}
	__syncthreads(); // after each iter
}
```

