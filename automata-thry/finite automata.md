## deterministic FA
a deterministic finite accepter (dfa) is determined by a quintuple $M = \set{Q, \Sigma, \delta, q_{0}, F}$, where: 
- $Q$ is a finite set of **internal states**
- $\Sigma$ is a finite set of symbols called the **input alphabet**
- $\delta: Q \times \Sigma \rightarrow Q$ is a **transition function**
- $q_{0}\in Q$ is the **initial state**
- $F \subseteq Q$ is the set of **final states.**

for example, take a dfa $M = \set{(q_{0}, q_{1}, q_{2}), (0, 1), \delta, q_{0}, \set{q_{1}}}$ 
- $\delta(q_{0}, 0) \rightarrow q_{0}$
- $\delta(q_{0}, 1) \rightarrow q_{1}$
- $\delta(q_{1}, 0) \rightarrow q_{0}$
- $\delta(q_{1}, 1) \rightarrow q_{2}$
- $\delta(q_{2}, 0) \rightarrow q_{2}$
- $\delta(q_{2}, 1) \rightarrow q_{1}$

$\delta^*$ represents multiple transitions that are stacked upon each other, so for example: if $\delta(q_{0}, a) \rightarrow q_{1}$ and $\delta(q_{1}, b) \rightarrow q_{2}$, then $\delta^{*}(q_{0}, ab) \rightarrow q_{2}$. 

![[finite automata 2024-02-02 11.19.32.excalidraw|1000]]

in this DFA, the strings **accepted** are strings that finish at the final state, and **rejected** otherwise. in this case, the accepted strings are the set $\set{1, 101, 111, 0001,...}$, and the strings rejected are $\set{0, 00, 100, 1111, 110, ...}$

the strings accepted by a DFA $M$ is the set of all strings on $\Sigma$ accepted by $M$. or, in formal notation: 
$$L(M) = \set{w \in \Sigma^{*}: \delta^{*} (q_{0}, w)\in F}$$
by contrast, the strings rejected by $M$ will look like: 
$$\overline{L(M)} = \set{w \in \Sigma^{*}: \delta^{*} (q_{0}, w)\not\in F}$$
if the **start state is also the final state**, then the string $\lambda$ is accepted by the DFA, else it will **never** be accepted.