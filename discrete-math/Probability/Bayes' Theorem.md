Suppose that $B_1, B_2, ..., B_n$ are mutually exclusive events whose union is a sample space $\mathcal{S}$. If A and **each** $B_k$ have nonzero probability, then for any $k, 1  \leq k \leq n$: 
$$P(B_k \mid A) = \frac{P(A\mid B_k)P(B_k)}{P(A\mid B_1)P(B_1)+P(A\mid B_2)P(B_2)+...+P(A\mid B_n)P(B_n)}$$
## Independent events
In general, events $A_1, A_2, A_3,... A_n$ are called **mutually independent** *(not pairwise independent)* if the intersection to any subcollection has probability equal to the product of their individual probabilities.

**Question**: let A, B, and C be pairwise independent, then, we have: 
$$P(A\cap B) = P(A)\cdot P(B),P(B\cap C) = P(B)\cdot P(C),... $$
But, it is **not** true that $P(A\cap B \cap C) = P(A) \cdot P(B) \cdot P(C)$. 