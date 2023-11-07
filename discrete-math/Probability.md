For the most part, we look at probability involving **finite** sample spaces, and those that have *equally likely* outcomes. If $\mathcal{S}$ is a sample space of all equally likely outcomes and $E \subseteq \mathcal{S}$ is any event, then: 
$$P(E) = \frac{|E|}{|\mathcal{S}|}$$
Where the $|E|$ simply is the number of outcomes in the event E and $|\mathcal{S}|$ is the number of outcomes in the sample space $\mathcal{S}$. So, consider the rolling dice: 
- if $E = \set{2, 4, 6}$ is the event that we roll an even number, $P(E) = \frac{1}{2}$
- if $O = \set{1, 3, 5}$ is the event that we roll an even number, $P(E) = \frac{1}{2}$
- since these events are both mutually exclusive, their probabilities add up to 1.

## Multiplication Rule
Allows you to get the **probability of sequential events** by multiplying the individual probabilities together. Suppose an operation or procedure can be performed in $k$ steps where: 
1. Step 1 can be performed $n_1$ ways
2. Step 2 can be performed $n_2$ ways, regardless of how step 1 was performed
3. and so on

Then, the entire operation can be performed $n_1 \cdot n_2 \cdot n_3 \cdot ... \cdot n_k$ ways.
## Addition rule: counting disjoint sets
For all disjoint sets $A$ and $B$, $|A \cup B| = |A| + |B|$. 

## The difference rule
If $B\subseteq A$ are sets, then $|A-B| = |A| - |B|$. Proof: if B is a subset of A, then $B$ and $A-B$ are disjoint sets whose union is A. And then you can apply the addition rule.

This can be used to make a subtraction-ish calculation, where you calculate all situations where a restriction is allowed, and subtract it by when the restriction MUST be applied.

## Inclusion - Exclusion
For an inclusion-exclusion of three sets, the cardinality of the **union** is the **sum of all 1-set intersections**, minus the **sum of all 2-set ints.**, plus **all 3-set intersections**.
$$|A \cup B \cup C| = |A| +|B|+|C| - |A\cap B| - |A\cap C| - |B\cap C| +|A\cap B \cap C|$$
