a policy $P$ is a property if and only if there exists a **precise** set of good traces $G$ such that:$$\forall \text{ programs }\mathcal{p}:\mathcal{p} \in P \iff\mathcal{p} \subseteq G$$in plain English: a program is only good only when it exhibits good traces. 

for **properties**, you can look at every execution in isolation, and they should all be "good". **policies**, on the other hand, still require some sort of dependency in programs ("this program is good, given that this program is also able to do this").

### proving a policy
consider the example of the no null dereferencing policy $P_{1}=\{ \{ t_{1}, t_{2},\dots \}\ |\ \forall i: \text{read(0)}\not\in t_{i}\}$. how would we prove that this is a property?

the proof would involve constructing the set of good traces. let $G_{1}=\{ t \ |\ \text{read(0)}\not\in t \}$ (set of traces that does not contain null dereferences). then, consider any program $p$, prove:
1. if $p\in P$, then $p \subseteq G$
2. if then $p \subseteq G$, $p\in P$

for this particular problem:
1. if $p\in P_{1}$, then by the def. of $P_{1}$, $\forall t \in p: \text{read(0)}\not\in t$. then, $p\subseteq G_{1}$
2. consider any $p \subseteq G_{1}$. by def. of $G_{1}$, $\forall t \in p: \text{read(0)}\not\in t$. then, $p\in P$
### proving a non-policy
on the other hand, consider the non-property policy $P_{2}$, where a crypt key generator generates all 64-bit keys. $P_{2}=\{ \{ t_{1};\text{output}(k_{1}),t_{2};\text{output}(k_{2}),\dots \} \ |\ \{ k_{1}, k_{2}, \dots \}=\text{the set of all 64-bit numbers}\}$

then, proving that something is NOT a property involves a proof by contradiction. then, by way of contradiction, assume that $P_{2}$ is a property with good traces $G_{2}$, such that $\forall p: p\in P\iff p\subseteq G_{2}$.

then, let $t_{0}=\text{output}(00\dots 00)$. 
1. consider the case where $t_{0}\in G_{2}$. let $p=\{ t_{0} \}$, meaning $p\in G_{2}$. however, $p$ only ever outputs the key 00...00, and no matter how many times it is ran, it will only ever output that key. a property really concerns itself with **the whole universe** of traces. so in this case, $p\notin P_{2}$.
2. now, consider the case where $t_{0}\not\in G_{2}$. then, let $p=\{ t_{0}, \text{output(00...01)},\text{output(00...10)},\dots,\text{output(11...11)} \}$. in this case, $p\in P_{2}$, but we have already made the case where $p\not\in G_{2}$, because $t_{0}\not\in G_{2}$. 

in both cases, a contradiction occurs, so the original assumption was false. hence, $P_{2}$ is not a property. 

alternatively, with the same assumption, consider the program $p=\varnothing$. then, $p\subseteq G_{2}$, because a null set is a subset of every set. however, it outputs nothing, meaning $p\not\in P_{2}$. so, the assumption does not hold, and $P_2$ is not a property. 

also proves that, **for a policy to be an property, it needs to accept an empty set** (or a policy need to allow a program to do nothing.)
## enforcement
to enforce a property, it needs to be the case where the enforce is **dynamic**, as we need to be able to look at each trace in isolation. a dynamic enforcer is **not** able to enforce non-property policies.
## categorization
can be classified into **safety** or **liveness**, or into the CIA classification. CIA is only used **strictly for properties**, and used in infosec:
- subjects/principals are actors (active), meaning users, processes, threads, methods, etc.
- objects/resources are those that are accessed (passive) e.g. data, devices, memory, values in memory, etc.

- confidentiality: constrains that some subjects **may not read** some objects. 
- integrity: constrains that some subjects **may not write** some objects.
- availability: some subjects may access some objects when needed.
 
