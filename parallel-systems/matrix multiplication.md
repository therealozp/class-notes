vector addition, e.g. `z[i] = x[i] + y[i]`, is highly memory bound, because there is not much to compute. it does not see a massive speedup, because most of the ALUs are idle.
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

