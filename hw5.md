## part 1
1. the memory bandwidth of the Bluegene processor is:
$$
\frac{204.8}{7.11} = 28.8 \text{ GB/s}
$$
2. the arithmetic intensity:
in the loop body, we are performing one multiplication and one addition, which amounts to 2 FLOPs.

for data movement, we are loading twice from `x` and `y`, as well as storing once into `y`. this is 3 operations with 8 bytes each, for a total of $\frac{2}{24} = 0.083\text{ FLOPs/byte}$. 

3. maximum achievable performance
because the arithmetic intensity of the loop execution is much less than the threshold where the computational roof starts, this program will fall under the **memory bandwidth limit**. so, the maximum performance we can achieve in this case is: 
$$28.8 \times 0.083 = 2.4 \text{ GFLOPs/s}$$
4. compare results

after calculating, we manage to get the data for performance in GFLOPs per second:

| # threads | time (s)  | GFLOPs | DDR traffic per node (bytes/cycle) | performance (GFLOPs/s) |
| --------- | --------- | ------ | ---------------------------------- | ---------------------- |
| 1         | 0.0879111 | 0.455  | 3.519                              | 5.18                   |
| 2         | 0.044039  | 0.907  | 7.022                              | 20.6                   |
| 4         | 0.022151  | 1.801  | 13.94                              | 81.3                   |
| 8         | 0.0174019 | 2.284  | 17.686                             | 131.3                  |
| 16        | 0.017477  | 2.287  | 17.719                             | 131.1                  |
|           |           |        |                                    |                        |
these results are not consistent with the data that we have received. for one, the maximum achievable performance of this particular program (ran on only one thread, at least) is only 2.4 GFLOPs/s, but the results suggest to be much higher.

moreover, performance seem to saturate at 131.3 GFLOPs/s, which is inconsistent with our measurements, which is supposed to saturate at a much higher level. therefore, although the scaling factor seems very reasonable, the eventual results we got do not agree with the computations we have made.

nonetheless, we can improve performance by:
- increasing the arithmetic intensity. at the moment, we are using very few FLOPs, but we are moving a lot of data. this forces us to be heavily memory bound, and we cannot use all of our architecture's resources
- use loop unrolling to boost the aforementioned intensity
- use vector operations (SIMD or similar) to make program more compute-intensive, more compute per byte of data.

5. if the ran program lands on the diagonal of the roofline model, this suggests that the program still has a lower arithmetic intensity than Bluegene needs for peak performance. the program is memory bound.

6. no program should ever have performance above the roof, assuming that the same architecture is used. the correct interpretation is all points above the roof projected (or, capped to) the maximum performance (in this case, 204.8 FLOPs/s). so, if we ever get a data point that is above the roof, the measurement is wrong.

## part 2
1. quantum gates vs. logical gates
quantum gates also operate on qubits, and whereas classical logic gates operate on classical (0 or 1) bits. 

quantum gates are **reversible** and represented by unitary matrices acting on amplitudes of qubit superpositions. 

classical logic gates (e.g. AND, OR) are generally **irreversible** Boolean functions mapping bits to bits. they also cannot create (nor make use of) superposition or entanglement.

2. 127 bit quantum computer
a register of 127 qubits encodes a state vector of size $2^{127}$, meaning it technically can represent $2^{127}$ states **at the same time**. furthermore, how qubits are used, this setup enables intrinsic **quantum parallelism** and **entanglement**. a classical machine, on the other hand, will only be able to represent one state at a time.

for certain problems like prime factoring, unstructured search, and various methods of cryptography, this exponential state space allows algorithms that can outpace even the largest classical machines. 

3. Hadamard function
Hadamard gates are used to bring qubits in and out of superposition. these gates, with the controlled NOT, can create entanglement, which is extremely useful.

4. challenges in non-linearity
because quantum mechanics are inherently linear, even the quantum gates are unitary matrices that are linearly multiplied, implementing non-linearity is very difficult. classical models, such as CNNs, require non-linear activations to perform well (without non-linearity, stacking layers is no different from being a single-layer). 

however, because of the nature of quantum mechanics, there is no way for us to encode non-linearity without using some sort of probabilistic process. we can't clone a quantum state, so arbitrary pointing to bits and conditionally transforming amplitudes is impossible. moreover, measuring bits will collapse the qubit in the first place, so we cannot achieve non-linearity in QNNs (yet!).

5. data encoding
data encoding (a.k.a. feature map) uses parameterized gates (e.g. rotations) or amplitude preparation to embed classical vectors into quantum states. the choice of encoding determines the circuit depth, expressivity of the quantum model, and its ability to capture correlations.

in more detail, we can rotate states parametrically, and apply even more rotations after entanglements, as per the following figure:

![[Pasted image 20250503203116.png]]

## part 3

a.
$$X|\Psi\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} a \\ b \end{bmatrix} = \begin{bmatrix} b \\ a \end{bmatrix}$$

b.
$$Y|\Psi\rangle = \begin{bmatrix} 0 & -i \\ i & 0 \end{bmatrix} \begin{bmatrix} a \\ b \end{bmatrix} = \begin{bmatrix} 0\cdot a-ib \\ ia + 0\cdot b \end{bmatrix} = \begin{bmatrix} -ib \\ ia \end{bmatrix}$$