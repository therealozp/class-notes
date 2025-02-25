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

## matrix multiplication (with shared memory)
conceptually, we define the process for tile-based `mmult` as follows: 

```txt
__global__ mmult(A, B, C, N) {
	allocate space for A_s, B_s tiles
	define row and column location
	loop over number of tiles {
		load the tile in question
		perform matrix mult by looping over the tiles
	}
}
```

```c
__shared__ float A_s[tile_size][tile_size];
__shared__ float B_s[tile_size][tile_size];

int row = blockIdx.y * blockDim.y + threadIdx.y;
int col = blockIdx.x * blockDim.x + threadIdx.x;

float = sum = 0.0f

for (int i = 0; i < N / tile_size; i ++) {
	A_s[dx][dy] = A[row * N + i * tile_size + dx];
	B_s[dx][dy] = B[(i * tile_size + dy) * N + col];
}
```

