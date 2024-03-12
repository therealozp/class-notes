Always look at the size of the matrix. It could be a column matrix, a row matrix, or it could be any other kind. For a **square** matrix, there will also be the **main diagonal** of the matrix.

## Addition / Subtraction
Matrices can be added if they are **the same size.** The algorithm to add two matrices is: 

```python
for i in range(len(row)):
	for j in range(len(col)): 
		C[i][j] = A[i][j] + B[i][j]
```

If they are of different sizes, the end result would be undefined.

## Multiplication
### By a scalar
Multiply all entries of the matrix by the same scalar. 

### By another matrix
**Theorem**: if A is an $m \times n$ matrix, and if $x$ is an $n \times 1$ column vector, then the product $Ax$ can be expressed as a linear combination of the column vectors of A in which the coefficients are the entries of x. 

## Matrix partitioning
## Transposes
**Theorem**: if $A$ is an $m \times n$ matrix, then the transpose of A, denoted $A^{T}$, can be obtained by **interchanging the rows and columns** to get size $n \times m$. This transformation changes size (unless it is a square matrix)
$$A = \begin{bmatrix} 1 & 2 & 3 & 4 \\ 5 & 6 & 7 & 8  \\ 9&10&11 & 12 \end{bmatrix}$$
$$A^{T}=\begin{bmatrix}1 & 5 & 9 \\ 2 & 6 & 10  \\ 3 & 7 & 11 \\ 4 & 8 & 12\end{bmatrix}$$
## Trace
The sum of all entries on the main diagonal (top left to bottom right). Only applies to square matrices.