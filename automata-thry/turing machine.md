consists of a control unit, tape, and a read/write head.
- there is only one symbol on the tape.
- read/write head moves right/left
- no separate input or output file. 

> all turning machines are deterministic

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
[]()