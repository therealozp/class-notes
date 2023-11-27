Let $\mathcal{S}$ be a sample space. A **probability function** is a function P from the set of **all events** in the sample space to the set of real n umbers which satisfy: 
1. $0 \leq P(E)\leq 1$ for all events $E \subseteq \mathcal{S}$
2. $P(\varnothing) = 0$ and $P(S) = 1$
3. If $E_1$ and $E_2$ are disjoint (i.e. mutually exclusive events), then $P(E_1\cup E_2) = P(E_1) + P(E_2)$. 

**Fact**: If $E\subseteq \mathcal{S}$ is an event, then $P(E^\complement) = 1-P(E)$
**Proof**: since $E$ and $E^\complement$ are disjoint in some universe $\mathcal{S}$, then by the theorem above they should sum to 1 because $P(\mathcal{S}) = 1$.

Another alternative of the set union: $P(A\cup B) = P(A) + P(B) - P(A\cap B)$ for all $A, B \subseteq \mathcal{S}$. Proven by using axiom 3. 

## Expected values
Often, an experiment or a random process, such as rolling a dice, will have numeric outcomes. The **expected** value of the such an experiment is the average of these outcomes, weighed by their probabilities. 

In a sample space of all equally likely outcome, the result is just the average: 

![[Pasted image 20231113162559.png]]

Suppose that the dice is rigged and the 6 shows up twice as often. Then, the expected value would be: 

