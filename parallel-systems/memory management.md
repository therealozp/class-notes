when threads in the same warps are b
## coalescing
the way memory is accessed in a GPU is roughly as follows:

![[Pasted image 20250219101649.png]]

so, one way we can optimize this section of memory addressing, is trying to use as little of the higher-level chunks as possible. so, when the row decoder gives a bunch of memory to be accessed, the multiplexer at the end can select which data to serve, based on the bits requested in the address.
### full coalescence
when **threads in the same warp** access **consecutive memory locations** in the **same burst**, access can be combined, and all the requested data can be served in one burst. in this way, only one DRAM transaction is needed.

```rust
[ x1 | x2 | x3 | x4 | x5 | x6 | ... | x8 ]
[ i  | i + 1 | i + 2 | ... ]
```
### no coalescence
by contrast, when the memory access is scattered (say, with a stride, or with some sort of kernel), then the GPU needs to issue multiple memory access, making it slower.

so, for example, if we were to access

```c
int idx = (threadIdx.x + blockIdx.x * blockDim.x) * 2; // Strided access
array[idx] = some_value;
```

if there are gaps here, we see that the memory accesses are not adjacent to each other. so, it is absolutely not coalesced.

```rust
[ x0 | x1 | x2 | x3 | x4 | x5 | x6 | ... | x8 ]
[  i | na | i + 1 | na | i + 2 | ... ]
```
### partial coalescence
if, for example, we are trying to access an array of structs:

```c
struct atom {
	int x;
	int y;
	int z;
}

atom atom_list[3];
atom_list[i] = {0, 1, 2};
...
```

then, although the memory accesses seem adjacent, the way that structs are set up means that there will always be holes in the middle of the accesses.

```rust
[ x0 | y0 | z0 || x1 | y1 | z1 || x2 | ... | z_n ]
[ i  |          | i + 1         | i + 2    | ... ]
```

this makes it a little bit more efficient, but not quite. instead, an optimization we can make is to separate each struct into its constituent parts, and create arrays of those components instead:

```c
float atom_x[3];
float atom_y[3];
float atom_z[3];
```
## examples
dividing warps in a 2D array means we go line by line until we reach the warp count. a 3 dimensional array means we go line-by-line **before** going plane-by-plane until we reach the warp count.

when talking about memory access and trying to find which terms stay constant across the warp for coalescing, we need to consider access **in the same time step**. don't worry about accesses in different times, but rather "at $t = 0$, what is happening?"

the key idea is, for the block of threads accessing memory, **find the bunch that belongs to the same warp**.

suppose that memory accesses are defined as follows

```c
int row = blockDim.y * blockIdx.y + threadIdx.y
int col = blockDim.x * blockIdx.x + threadIdx.x
```

we note that the multiplication `blockDim.y/x * blockIdx y/x` will be **the same for all threads in a warp**. so, calling the term `z`, we only have to worry about the `dx, dy`, which directly translates to `threadIdx.x` and `threadIdx.y`, respectively.

consider matrix multiplication:

```c
for (int i = 0; i < N; i++) {
	sum += A[row * N + i] + B[i * N + col]
}
```
