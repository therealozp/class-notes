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