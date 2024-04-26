consists of a control unit, tape, and a read/write head.
- there is only one symbol on the tape.
- read/write head moves right/left
- no separate input or output file. 

> all Turing machines are deterministic

a formal definition:  $M = \set{Q, \Sigma, \Gamma, \sigma, q_{0}, \square, F}$:
- $Q$: the finite set of internal states
- $\Sigma$: input alphabet. does not contain blanks (for
- $\Gamma$: tape alphabet
- $\sigma$: transition functions $\sigma: \Sigma\times \Gamma$
- $q_{0}\in Q$ is the initial state
- $\square$: the blank symbol
- $F\leq Q$: the set of final states 

### example: 
$\sigma(q_{0}, a) \rightarrow q_{1}, d, R$
![[Pasted image 20240412121724.png]]

TM1: replaces all a's with b's
$\sigma(q_{0}, a) \rightarrow q_{0}, b, R$
$\sigma(q_{0}, b) \rightarrow q_{0}, b, R$
$\sigma(q_{0}, \square) \rightarrow q_{1}, \square, R$

## examples
### adding 2 numbers in unary notation: 
$\sigma(q_{0}, 1) \rightarrow q_{0}, 1, R$
$\sigma(q_{0}, \square) \rightarrow q_{1}, 1, R$
$\sigma(q_{1}, 1) \rightarrow q_{1}, 1, R$
$\sigma(q_{1}, \square) \rightarrow q_{2}, \square, L$
$\sigma(q_{2}, 1) \rightarrow q_{3}, \square, R$

### multiplying a unary number by 2
use an intermediary symbol, say a $ sign. first, replace the entire number with only $, then we can go and replace $ with $11$ for each sign.

$\sigma(q_{0}, 1) \rightarrow q_{0}, \$, R$
$\sigma(q_{0}, \square) \rightarrow q_{1}, \square, L$
$\sigma(q_{1}, 1) \rightarrow q_{1}, 1, L$
$\sigma(q_{1}, \$) \rightarrow q_{2}, 1, R$
$\sigma(q_{2}, 1) \rightarrow q_{2}, 1, R$
$\sigma(q_{2}, \square) \rightarrow q_{1}, 1, L$
$\sigma(q_{1}, \square) \rightarrow q_{f}, \square, L$

### matches the string $a^{n}b^{n}$
$\sigma(q_{0}, a) \rightarrow q_{1}, x, R$
$\sigma(q_{1}, a) \rightarrow q_{1}, a, R$
$\sigma(q_{1}, y) \rightarrow q_{1}, y, R$
$\sigma(q_{1}, b) \rightarrow q_{2}, y, L$

$\sigma(q_{2}, y) \rightarrow q_{2}, y, L$
$\sigma(q_{2}, a) \rightarrow q_{2}, a, L$
$\sigma(q_{2}, x) \rightarrow q_{0}, x, R$

$\sigma(q_{0}, y) \rightarrow q_{3}, y, R$
$\sigma(q_{3}, y) \rightarrow q_{3}, y, R$
$\sigma(q_{3}, a) \rightarrow q_{4}, \square, R$

$q_{4}$ is our accept state.

> if the Turing machine **mutates** the string, then the content on the tape will matter. else, the tape content does not matter.