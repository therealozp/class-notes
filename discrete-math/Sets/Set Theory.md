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

## Partitions
A partition of $A$ is a grouping of elements in set $A$, such that each element is included in exactly **one** subset.

### Disjoint sets
Sets $A_1, A_2, A_3,...$ are called **mutually disjoint** (or **pairwise disjoint** or **nonoverlapping**) if no two sets $A_i$ and $A_j$ with distinct subscripts have any elements in common. 

A finite or infinite collection of nonempty sets $\set{A_1, A_2, A_3,...}$ is called a *partition* of set $A$ when: 
- $A$ is the union of all $A_i$
- All the sets in the collection have to be **mutually disjoint.**

## Power sets
Let A be a set. The *power set* of A, denoted by $\mathcal{P}(A)$, is the set containing **all subsets** of A. 

| Set $A$       | $A$ | Power set                   | P(A) |
| ------------- | --- | --------------------------- | ---- | 
| $\varnothing$ | 0   | $\set{\varnothing}$         |  1     |   
| $\set{a}$     | 1   | $\set{\varnothing, \set{a}}$ | 2    |    

Then, the cardinality of the power set $|\mathcal{P}(A)|$ will be $2^{|A|}$ 

## Disproofs and Algebraic Proof

## Boolean Algebra
The set of statement forms, together with operations $\lor, \land, \lnot$ form and Boolean algebra. Similarly, power set of an $n$ element set, together with operations $\cap, \cup, \complement$ from another Boolean algebra.

![[Pasted image 20231004162611.png]]

So, in general, a Boolean algebra is defined as a set $\beta$ with operations $+, \cdot$ such that (at this point, this is literally just the Boolean identities in Comp Org): 
1. Commutativity: $\forall a, b \in \beta : a+b = b+a$ and $a\cdot b = b \cdot a$
2. Associativity: $\forall a, b, c \in \beta : (a+b)+c = a +(b+c)$ and $(a\cdot b) \cdot c = a\cdot (b \cdot c)$
3. Distributivity
4. Identity
5. Complements (Negation, Inverse)

**Theorem**: A Boolean algebra $\beta$ with operations $+$ and $\cdot$ satisfy: 
1. Unique complements
2. Unique identities
3. Double complement
4. Idempotent
5. Universal bound (Dominance)
6. De Morgan's laws
7. Absorption laws
8. Complements of 0 and 1
