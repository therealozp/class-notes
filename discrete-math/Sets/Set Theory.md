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

## Procedural Versions
We have the following subset relations: 
1. Inclusion of intersection: $A \cap B \subseteq A$ and $A \cap B \subseteq B$
3. Inclusion in Union: $A \subseteq A \cup B$ and $B \subseteq A \cup B$
4. Transitivity of Subsets 

The procedural versions: 
1. $x \in A \cup B \Longleftrightarrow$ $x \in A$ or $x \in B$
2. $x \in A \cap B \Longleftrightarrow$ $x \in A$ and $x \in B$
3. $x \in A - B \Longleftrightarrow$ $x \in A$ and $x \not\in B$
4. $x \in A^\complement\Longleftrightarrow$ $x \in A$ or $x \not\in A$
5. $(x, y) \in X \times Y \Longleftrightarrow x \in X$ and $y \in Y$

## De Morgan's
1. $(A \cap B)^\complement = A^\complement \cup B^\complement$
2. $(A \cup B)^\complement = A^\complement \cap B^\complement$

This can be proved with logical equivalence, as essentially $x \not \in A\cup B$ means $\lnot x \in A\cup B$, and by procedure, $\lnot (x \in A \lor x \in B)$.

## Cartesian Products
Prove that $(A \times B) \cup (C \times D) \subseteq (A \cup C) \times (B \cup D)$
$\Longleftrightarrow (x, y) \in (A \times B) \cup (C \times D)$
$\Longleftrightarrow (x, y) \in (A \times B) \lor (x, y) \in (C \times D)$
$\Longleftrightarrow (x \in A \land y \in B) \lor (x \in C \land y \in D)$
$\Longleftrightarrow [(x \in A \land y \in B) \lor x \in C] \land [(x \in A \land y \in B) \lor y \in D]$
$\Longleftrightarrow [(x \in A) \lor x \in C] \land [(y \in B) \lor y \in D]$
$\Longleftrightarrow (x \in A \cup C) \land (y \in B \cup D)$
## Empty sets
**Fact**: The empty set is a subset of every set.
By definition, if $A \subseteq B \Longleftrightarrow \forall x$ if $x \in A$ then $x\in B$, and if $A = \varnothing$, then the universal conditional above is vacuously true since the empty set has no elements. 

**Fact**: the empty set is unique
If $E_1$ and $E_2$ are both empty sets, then the fact above gives us $E_1 \subseteq E_2$ and $E_2 \subseteq E_1$, which means $E_1 = E_2$

To prove a set empty, we assume it contains element, and derive a contradiction.

## For Indexed Collections
![[Pasted image 20231002162911.png]]

Alternatively, we also have $\cup^n_{i = 1}A_i$ is the same as $A_1 \cup A_2 \cup ...\cup A_n$, and $\cap^n_{i = 1}A_i$ is the same as $A_1 \cap A_2 \cap ...\cap A_n$