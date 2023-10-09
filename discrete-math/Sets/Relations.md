Relation is a way to relate an element $x \in  A$ for some $y \in B$ satisfying some kind of requirement. Formally, it is a subset $R$ of $A \times B$ if $x \in A$ is related to $y \in B$.
$$
\begin{split}
x \ R \ y \ or \ (x, y)  \in R \\
x \ \not R \ y \ or \ (x, y) \not \in R
\end{split}$$
The set $A$ is called the **domain** of $R$, and $B$ is the **co-domain**. Unlike a function, the domain of a relation does **not** need to have all elements in the domain related to some element in the co-domain.

When $x \ R \ y$ and $y \ R \ x$, then we call it **symmetric.** Not all relations have to be symmetric.

## Arrow Diagrams
Let $A = \set{1, 2, 3}$ and $B = \set{1, 3, 5}$, and let $S$ ad $T$ be relations from $A$ to $B$ satisfying: 
- $(x, y) \in S$ whenever $x < y$; and
- $T = \set{(2, 1), (2, 5)}$

![[Pasted image 20231009155755.png]]

## Functions
A **function** from A to B is a relation whose domain are $A$ and $B$ respectively, where: 
- For every $x \in A$, there exists an element in $B$ such as $(x, y)\in F$
- For all $x \in A$ and $y, z \in B$, if $(x, y)\in F \land (x, z) \in F \rightarrow y=z.$

A relation F is a function from A to B if every element of A is related to **exactly one** element of B. Thus, we get the function notation $y = F(x)$. 

![[Pasted image 20231009161244.png]]

- R is not a function since 4 is related to **more than one** element of B. 
- S is not a function since 6 is not related to something. It will be if the domain is only {2, 4}
- T is a function.

**Analogy**: a relation R from A to B can be encoded as a function from $A \times B$ to the set $\set{true, false}$, both in the sense of function and in the program. 
For example, let $A = \set{1, 2, 3, 4, 5}$ and L is the relation from $A$ to $A$ where $x\ L\ y$ if $x < y$

```python
def relations(A)
	mat = [[]]
	for i in A: 
		for j in A: 
			if (i < j): 
				mat[i][j] = true
```

Another example: Let $H$ be the set of all humans that ever lived and define the relation $x\ D\ y$ if x is a descendant of y. 

$D$ is transitive, meaning $x\ D\ y$ and $y\ D\ z$ implies $x\ D\ z$ should allow the relation to be more efficiently stored. 

## Relation on Sets
If $A$ is a set, we call a relation from A to itself is a relation on A. For example: 
- < is relation of $\mathbb{R}$ where, 1 < 2, $e < \pi$, etc. but $2 \not < 1$, etc, it consists of all points strictly above the line y = x. In set builder: 
$$'<' = {(x, y) \in R\times R : x < y}$$
- = is a relation on any A, where x = y when they are the same. This is also the identity relation.
$$'=' = \set{(x, x): x \in \mathbb{R}}$$
Recall that the power set $\mathcal{P}(x)$ is the set of all subsets of X. Let $X = \set{a, b, c}$ and the relation S to be $A\ S\ B$ when $|A| \geq |B|$ meaning A has at least as many elements as B. then: 
![[Pasted image 20231009163425.png]]
- $\subseteq$ is also a relation on any powerset.

Let $\mathcal{L}$ be the set of all statement forms in $p, q,$ and $r$. Then $\mathcal{L}$ has infinitely many requirements, but the equivalence relation $\equiv$ on $\mathcal{L}$ partitions it into $2^{2^3}$ classes, the number of possible columns for 3 variable statement forms, one being the set of all such tautologies, and another the set of all contradictions. 

## Inverse relation
Let R be a relation from A to B. Then, the **inverse relation** $R^{-1}$ from B to A is defined as: 
$$ R^{-1} = \set{(y, x) \in B \times A: (x, y) \in R}$$
As such, $x\ R\ y \Longleftrightarrow y\ R^{-1}\ x$. 

Note: $y \geq x$ is **NOT** an inverse relation to $x > y$, but $y > x$ is.  