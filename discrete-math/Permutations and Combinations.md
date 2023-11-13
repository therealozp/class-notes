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

## Permutations with Sets of Indistinguishable Objects
Example: How many ways to arrange the letters of the word **MISSISSIPPI?** Note: There are 11 slots.

$\rightarrow$ Although this sounds like a permutation problem, we see that there are a bunch of non-distinct objects, and as such is should be solved as a multiplication rule.

 \__ __ __ __ __ __ __ __ __ __  

We will have: 
- $\binom{11}{1}$ ways to choose where to place the M
- $\binom{10}{4}$ ways from the remaining 10 slots to place the I's
- $\binom{6}{4}$ ways to place the S's
- and $\binom{2}{2}$ remaining ways to place the P's

By the multiplication rule, there are 34650 such arrangements.

Alternatively, we can do it by using permutations and analyzing. Suppose that they are distinct, but then we will have to label them. So, we have $11!$ organizations, and: 
- 1 way to label the M
- $2! = 2$  ways to label the P
- $4! = 24$ ways to label the S
- $4! = 24$ ways to label the I

So, due to the equivalence classes, we have to take the division:
$$\frac{11!}{1!\times2!\times4! ^2} = 34650$$

We can derive the general formula for this, assuming: 
- $n_1$ being the number of elements of type 1
- $n_2$ being the number of elements of type 2
. . .
- $n_k$ being the number the elements of type k
$$P_u = \frac{n!}{n_1!n_2!...n_k!}$$
## Selection with Repetition
Consider selecting $n$ identical balls into $k$ distinguishable urns. How many ways can this be accomplished? 

![[Pasted image 20231108155812.png]]

Observe that we're only choosing from the $n + k - 1 = 9$ positions for the $n = 7$ positions of the balls. So, we can derive another formula for this:  
$$S_r =\binom{n+k-1}{n}$$
Variant: 
How many **positive** solutions to 
$$u + v + w + x + y + z = 35$$
One approach is to substitute $u = u' + 1$, etc. so that we can get: 
$$u' + v' + w' + x' + y' + z' + 6 = 35$$
After switching sides, we can solve it normally by using the formula above.

## Pascal's formula
Recall Pascal's Triangle, which gives the $r^{th}$ coefficient in the expansion of $(x + y)^n$: 

![[Pasted image 20231108163256.png|center]]

If the first row is the $0^{th}$ row whose first entry is the zeroth, then the $r^{th}$ entry in the $(n + 1)^{th}$ row for $0 \leq r \leq n$ is defined recursively as: 
$$\binom{n + 1}{r}=\binom{n}{r-1}+\binom{n}{r}$$
where otherwise $\binom{n+1}{n} = 1$. This is called **Pascal's identity.**

**Proof:** A bijective or combinatorial proof demonstrates a combinatorial identity by counting the same thing in two different ways, as we will do here. 

## The Binomial Theorem (Newton's Binomial)
For every integer $n \geq 0$ and real numbers $x, y$: 
$$(x+y)^n = \binom{n}{r}\sum^n_{r=0}x^ry^{n-r}$$
 Corollaries: 
 $$(x+y)^n = \binom{n}{r} = 2^n$$
 $$(x+y)^n = (-1)^r \binom{n}{r} = 0$$
  