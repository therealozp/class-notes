Consider a sample space $\mathcal{S}$ containing an event A, where we may visualize $\mathcal{S}$ being an area $P(\mathcal{S}) = 1$ and $A$ having an area $P(A)$ in a Venn diagram. Then, consider another event B, which may or may not be mutually exclusive from A. 

Suppose that we know that event A has occurred, and in relation, event B, now limited to $B\cap A$ in that scenario. 

![[Pasted image 20231115160630.png]]

The **conditional probability of B give A**, denoted as $P(B\mid A)$, is the probability that B will occur given that A has occurred. If $P(A) \not = 0$, then we have the formula: 
$$P(B \mid A) = \frac{P(B\cap A)}{P(A)}$$
which yields the fraction of area that $B \cap A$ takes up in A, and hence the probability in question. 

## Dependence and Independence

Example 1: Two coins are tossed. What is the probability that the first is a head, and the second is a tail? 

To do this, we assume the normal probability techniques, and yield the conclusion that this probability will be 1/4. 

Now, for events A and B, **dependent** or **independent:**
$$P(B\cap A) = P(A)\cdot P(B\mid A)$$
Note: **mutually exclusive** means that the two events cannot occur at the same time. **Independent** means that the happening of one does not impact the occurrence of the other.