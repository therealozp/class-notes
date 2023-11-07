## Permutations
Suppose we have an $n$ element set and we would like to arrange $r \leq n$ of these. Then, we have the **$r$-permutation of an $n$-element set** as follows:

The number of r-permutations of an $n$ element list is denoted $P(n,r)$. We can find it using the multiplication rule: 
1. Place one of $n$ elements first
2. Place one of the remaining $n-1$ elements second
3. Place one of the remaining $n-2$ elements third
4. ...
5. Place one of the remaining $n-r + 1$ elements at the $r - 1^{th}$ position. 
$$
\begin{split}
P(n, r) &= n\cdot (n-1)\cdot(n-2)\cdot...\cdot(n-r+1) \\
&= \frac{n!}{(n-r)!}
\end{split}
$$
For example, consider a round table with 6 diplomats ($A-F$), considering that rotating the table does not constitute a different position, how many ways can it be organized? 

> So, we understand, to organize 6 diplomats in 6 seats, there will be $6!$ 

## Combinations
This is useful when we want to count **subsets of a set**, or to count elements when **order does not matter.** Then, $C(n, r)$ is an *r*-**combination of an** *n* **element set.**
Let us count the number $P(n, r)$ of permutations in a different way, with this procedure: 
1. Select $r$ of the $n$ items. This can be done in some number of ways $C(n, r$)
2. Now, we put these r items in order, or assign them to different roles. There are $r$ slots, so there are $r!$ number of ways to do this. 

By definition, $P(n, r) = C(n, r) \cdot r!$. So, we get the formula: 
$$\begin{split}
C(n, r) = \frac{n!}{(n-r)!\times r!}
\end{split}$$
We also have the notation $\binom{n}{r}$ to represent the combinations. 