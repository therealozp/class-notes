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

A string is regular if it is accepted by a DFA.

$L_{1} = \set{b^{n}ab^{m}: n \geq 0, m \geq 0}$
$L_{2}= \set{awa: w \in {a, b}^{*}}$
$L_{3}= \set{(ab)^{n} : n\geq 0}$

For any regular language $L$, then $\overline L$ is also regular. This can be yielded from the DFA by reversing all status of the nodes, e.g. if it is accepted, then revert it to be not accepted, and vice versa.

example: design a DFA that accepts all binary strings that are divisible by 5. 
to do this, we check for each possible state generated from each **modulo** of 5. 

for case modulo 0, if a string is followed by 0, the result would still be 00. hence, we point it back to itself. if it's 1, then the string becomes 01, so we point that to 1. 

for case modulo 1, if a string is followed by 1, the end result would be 11, so point it to 3. if it's 0, the result is 10, so point it to 2. so on and so forth, until we get the final DFA.
## irregular languages
these languages cannot be accepted by any DFA, if it is finite: 
- $\set{a^{n}b^{n}: n\geq 0}$
- $\set{w \in \set{a, b}^{*}}$, $w$ is a palindrome
- $\set{w \in {a, b}^{*}: n_{a}(w) = n_{b}(w)}$

> **All finite languages are regular.**
> A language **is regular if and only if it has an non-deterministic FA.**

## non-deterministic fa
an NFA $M = (Q, \Sigma, \delta, q_{0}, F)$. the main difference between an NFA and a DFA lies in the transition function:
$$\delta: Q \times(\Sigma \cup (\lambda))\rightarrow2^{Q}$$
essentially, what this means is apart from being able to read in anything from $\Sigma$, we can also **do nothing and move on to the next state.** we can also **read in 1 input and go to more than 1 possible states.** so, an NFA can either take the form: 

![[finite automata 2024-02-09 11.41.51.excalidraw|1000]]

an NFA still has 1 start state. in an NFA, a string will be accepted if **there is at least 1 path** from the start state to the final state. it is then rejected if there are **no feasible paths** made possible. 

meaning that to prove a language is regular, we don't have to draw the full DFA, but instead draw an NFA that takes in all paths and give **at least 1 path** to the accept state. for example, to prove "all strings ending in 001 are regular", we can simply have an NFA: 

![[finite automata 2024-02-09 12.27.14.excalidraw|1000]]

example: prove that all strings ending in "ab", "bc", and "ac" are regular on $\Sigma = \set{a, b, c}$. 

![[finite automata 2024-02-09 12.45.57.excalidraw]]
## converting an NFA to DFA
by doing this, we prove that all non-determinism and determinism is alike, we can achieve one from the other. to do this: 
1. write out all possible states of the system. for a system of $n$ states, there are $2^{n}$ possible combinations. ($\phi, q_{0}, q_{1}, q_{2}, q_{0}q_{1}, q_{1}q_{2}, q_{0}q_{2}, ...$)
2. from the NFA, check all possible states we can arrive from a certain node, or whether it goes to a trash state $\phi$. if there is any possible path from a node that does **not go to a trash state**, **preserve it.** if there are no possible paths, have it lead to the trash state.
3. for the accept state, whichever node **contains** the accept state from the original NFA, then it is also an accept state. if the original accept state is $q_{1}$, then in the resulting DFA, $q_{1}, q_{1}q_{2}, q_{0}q_{1}, q_{0}q_{1}q_{2}$ is also accepted.
4. remove all nodes that have no connections to it and write the final DFA.
