when we launch a 1D kernel function from before to add in a sequence of numbers, the canonical way to do it was:

```c
kernelfn<<<numBlocks, numThreadsPerBlock>>>
```

however, this quickly becomes an issue when trying to run a kernel function on a higher-dimensional data structure, such as on an image (2D). thankfully, CUDA does support running kernel functions on higher-dimensional data, by using the `dim3` class to define dimensions.

for example, if we were to launch an image processing kernel on a 3D image, we can define something like:

```c
dim3 numThreadsPerBlock(32, 32); // defines 32 threads/b on x, 32 threads/b on y
int numBlocksx = (width + numThreadsPerBlock.x - 1) / numThreadsPerBlock.x;
int numBlocksY = (height + numThreadsPerBlock.y - 1) / numThreadsPerBlock.y;

dim3 numBlocks(numBlocksX, numBlocksY);
rgb2gray_kernel<<<numBlocks, numBlocksPerThread>>>; // calls kernel function, with numBlocksX blockson the X dimension, numBlocks Y blocks on the Y dimension, each with 32 threads each.
```

even multidimensional data is represented in a linear chunk. so, for example:

```
-----------------------------
| 0, 0 | 0, 1 | 0, 2 | 0, 3 |
-----------------------------
| 1, 0 | 1, 1 | 1, 2 | 1, 3 |
-----------------------------
| 2, 0 | 2, 1 | 2, 2 | 2, 3 |
-----------------------------
| 3, 0 | 3, 1 | 3, 2 | 3, 3 |
-----------------------------
```

the above array is represented like:

```
---------------------------------------------------------------
| 0, 0 | 0, 1 | 0, 2 | 0, 3 | 1, 0 | 1, 1 | 1, 2 | 1, 3 | ... |
---------------------------------------------------------------
```

so, to get the offset in memory of the correct element, we need to consider the following:
- which row are we on? -> how many rows do we have to skip?
- which column are we on? -> how many elements from the start of the row are we moving?

so, for any index `(i, j)` we are trying to reach, the actual element becomes

```
matrix[i][j] === memory_block[width * i + j]
```

so, a Gaussian blur code on CUDA may look something like:

```c
__global__ void blur_kernel(unsigned char* image, unsigned char* blurred, unsigned int width, unsigned int height) {  
	int outRow = blockIdx.y*blockDim.y + threadIdx.y;  
	int outCol = blockIdx.x*blockDim.x + threadIdx.x;
	  
	if (outRow < height && outCol < width) {  
		unsigned int average = 0;  
		for (int inRow = outRow - BLUR_SIZE;
		inRow < outRow + BLUR_SIZE + 1;
		++inRow) {  
			for (int inCol = outCol - BLUR_SIZE;
			inCol < outCol + BLUR_SIZE + 1;
			++inCol) {  
				average += image[inRow*width + inCol];  
			}  
		}  
		blurred[outRow*width + outCol] =  
		(unsigned char)(average/((2*BLUR_SIZE + 1)*(2*BLUR_SIZE + 1)));  
	}  
}
```

adding boundary checking to make sure that it does not go out of bounds, we end up with:

```c
if (inRow >= 0 && inRow < height && inCol >= 0 && inCol < width) {  
	average += image[inRow*width + inCol];  
}
```

> a good rule of thumb: **every memory access** must have a **corresponding guard** by **comparing its indices to the array dimensions.**

