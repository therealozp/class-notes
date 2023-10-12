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

Let F be a function from A to B. As a relation, $F$ has an inverse relation $F^{-1}$. However, do note that the inverse relation does NOT have an inverse relation. (e.g. $F(x) = x^2$, where the "inverse" $F^{-1}(x) = \sqrt{x}$ does not hold)

## n-ary relations
Relations discussed above are mostly **binary**, meaning that they are only subsets of the Cartesian product of two sets. For sets $A_1, A_2, A_3,... A_n$, then an **n-ary** relation is a subset of $A_1 \times A_2 \times A_3 \times ... \times A_n$, consisting of ordered n-tuples. 

Consider the following simplified version of a database, a quarternary relation $R$ of $A_1, A_2, A_3, A_4$ where: 
- $A_1$ is a set of positive integers, patient IDs `patient_id`
- $A_2$ is a set of names `string name`
- $A_3$ is a set of dates `date admmission`
- $A_4$ is a set of diagnoses `[diseases]`

## Equivalence relations and partitions
By definition, a partition of set S is a collection of subsets that: 
- every member of S belongs to some other set in the partition, or the union of all subsets yields S itself.
- all the sets are mutually disjoint.

An **equivalence relation** is a special type of relation in which all related pairs are grouped into the same partition called an **equivalence class.** Therefore, equivalence relations will form partitions - and conversely, any partition can also be used to form an equivalence by relating pairs whenever belong to the same set.

Consider the set of $\mathbb{Z}$ and the relation R, where $m \ R \ n$ occurs whenever m - n % 2 = 0.
- Then, the relation R consists of all ordered pairs where they have the same parity (both even and both odd)
- If $m$ and $n$ are related, then either **both** belong to $\mathbb{Z}_{even}$ or $\mathbb{Z}_{odd}$. Conversely, if they are part of the same partition, then they are related.
- If one of them belongs to another one, then they are not related. The converse is also true. 

> The equivalence relation is **reflexive, symmetric, and transitive.**
### Reflexive, symmetric, and transitive relations
A relation R on a set $S$ is called **reflexive** if for every $x \in S$, we have that $x\ R\ x$, or *every element is related to itself.* For example, $\leq$ is a reflexive relation on $\mathbb{R}$, while $<$ is not.

A relation R on a set $S$ is called **symmetric** where for every $x, y \in S$, if $x\ R\ y$ then $y\ R\ x$. 

A relation R on a set $S$ is called **transitive** if for every $x, y, z \in S$, if both $x\ R\ y$ and $y \ R\ z$ hold, then $x \ R \ z$. For example, both $\leq$ and $<$ are transitive. 

For any $x \in S$, the **equivalence class** of x, denoted $[x]$ or $[x]_R$. is the set of all $y \in S$ that are related to x: 
$$[x] = \set{y \in S : y\ R \ s}$$
Example: Let $S = \set{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}$ and the relation R on S where elements of S are related if they begin with the same letter. 
- Equivalence classes: $\set{\set{1}, \set{2, 3, 10}, \set{4, 5}, \set{6, 7}, \set{8}, \set{9}}$
- **Reflexivity**: all numbers have the same first letter as itself
- **Symmetric**: if $x \in S$ has the same letter as $y \in S$, then it has the same letter.
- **Transitivity**: pretty self explanatory.
Here, $[2], [3]$, and $[10]$ all refer to the same equivalence class. 