## Operations
Let A and B be sets.
- Union: 
$$A\cup B = \set{x: x\in A \space \lor x\in B}$$
- Intersection
$$A\cap B = \set{x: x\in A \space \land x\in B}$$
- Difference (Relative Complement)
$$A- B = \set{x: x\in A \space \land x\not\in B}$$
## The universal set
The universal set, or universe, basically contain the context of the sets where they are both placed in. This is useful when we are taking the complement of the lone set, such as $A^\complement$, 

## Interval notation
Let $\mathbb{R}$ be the universal set. Then, **intervals** are subsets of $\mathbb{R}$ where for a < b, we have: 
$$
\begin{split}
& (a, b) = \set{x \in \mathbb{R} : a < x < b} \\
& [a, b] = \set{x \in \mathbb{R} : a \leq x \leq b}
\end{split}
$$
## Subsets: Proof and Disproof
If $A$ is a subset of $B$ ($A \subseteq B$), then: 
$$\forall x, x \in A \implies x\in B$$
Example: $A \subseteq B$ where: 
$$\begin{split}
& A = \set{m \in \mathbb{Z} : m = 6r + 12 , r \in Z} \\
& B = \set{n \in \mathbb{Z} : n = 3s, s \in Z}
\end{split}$$
[[Set Intro#Subsets and Equality]]

## Basic Set Facts
Let $U$ be a universal set containing sets A, B, and C. Then: 
1. $A\cup B = B \cup A$ and $A\cap B = B \cap A$
2. $(A\cup B) \cup C = A \cup (B \cup C)$ (also for intersection)
3. $A\cup (B \cap C) = (A \cup B) \cap (A\cup C)$
4. $A \cup U = U$
5. $A \cup \varnothing = A$, while $A \cap \varnothing = \varnothing$
6. $A \cup A^\complement = U$, while $A \cap A^\complement = \varnothing$
7. $A\cup (A \cap B) = A$ and $A\cap (A \cup B) = A$ **(Absorption)**
8. 