in a DFA, two states $p$ and $q$ are **indistinguishable** if
$$\delta^{*}(p, w) \in F \Rightarrow \delta^{*}(q, w) \in F$$
and 
$$\delta^{*}(p, w) \not\in F \Rightarrow \delta^{*}(q, w) \not\in F$$
they are distinguishable if any of the above conditions are not met. from here, we can derive a simple algorithm to merge all indistinguishable states: 
1. remove all states that are unreachable through the DFA
2. for each pair of states $q_{i}$ and $q_j$, if it satisfies the above properties, then it is indistinguishable, and thus can be merged. note that this also satisfies the equivalence relation, meaning if p and q and q and r can be merged, then all three states can be merged. []()