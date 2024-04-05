a NDPA is determined by a tuple $M = \set{Q, \Sigma, \Gamma, \sigma, q_{0}, Z, F}$:
- $Q$ is the finite set of internal states
- $\Sigma$ input alphabet
- $\sigma: Qx(\Sigma \cup \set{\lambda})\times \Gamma$: the set of finite subsets of $Q \times \Gamma^{*}$ is the transition function
- $q_{0}\in Q$ is the initial state
- $Z \in \Gamma$: stack **start** symbol
- $F\leq Q$: the set of final states 

$P_{1}: \text{NDPA}: Q\rightarrow\set{q_{0}, q_{1}, q_{2}, q_{3}}, \Sigma=\set{a, b}, \Gamma={0, 1}, Z={0}, F={q_{3}}$
- $\sigma(q_{0}, a,0)\rightarrow q_{1},10$
- $\sigma(q_{0}, \lambda,0)\rightarrow q_{3},\lambda$
- $\sigma(q_{1}, a,1)\rightarrow q_{1},11$
- $\sigma(q_{1}, b,1)\rightarrow q_{2},\lambda$
- $\sigma(q_{2}, b,1)\rightarrow q_{2},\lambda$
- $\sigma(q_{2}, \lambda,0)\rightarrow q_{1},\lambda$


