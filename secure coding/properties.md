a policy $P$ is a property if and only if there exists a **precise** set of good traces $G$ such that:$$\forall \text{ programs }\mathcal{p}:\mathcal{p} \in P \iff\mathcal{p} \subseteq G$$in plain English: a program is only good only when it exhibits good traces. 

if the set of good traces $G$ is found, then the property is also automatically defined. so, we can describe a property with its set $G$.

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
to enforce a property, it needs to be the case where the enforcer is **dynamic**, as we need to be able to look at each trace in isolation. a dynamic enforcer is **not** able to enforce non-property policies.
## categorization
can be classified into **safety** or **liveness**, or into the CIA classification. CIA is only used **strictly for properties**, and used in infosec:
- subjects/principals are actors (active), meaning users, processes, threads, methods, etc.
- objects/resources are those that are accessed (passive) e.g. data, devices, memory, values in memory, etc.

CIA describes the following:
- confidentiality: constrains that some subjects **may not read** some objects. 
- integrity: constrains that some subjects **may not write** some objects.
- availability: some subjects may access some objects when needed.

a limitation of the CIA classification is that access control descriptions are strictly limited to **read and write**, whereas it can also be executed. then, *confidentiality* and *integrity* are **access-control properties** (some subjects may not access some objects in certain ways).

## safety
denote "the **finite** prefix of $t$" as $\leq t$. then, rules for prefixes are:
- $\epsilon \leq t$ for any $t$
- $a\leq a$
- $a \leq a;t$
- $t_{1}\leq t_{1};t_{2}$ if $t_{1}$ is finite. 
- $a_{i};a_{j};\dots \not \leq a_{i};a_{j};\dots$ (because LHS is infinite; RHS does **not** have to be finite).

a property $G$ is safety if and only if $$\forall t : t\in G\iff \text{prefixes}(t) \subseteq G$$where $\text{prefixes}(t)$ is the set of all finite prefixes. the set of prefixes can be infinite, but each prefix is finite. a safety says insecure traces are irremediable (or a bad thing can't be fixed). **an access-control property is a safety**.

consider again, the no-null dereference policy. then, $G_{1}=\{ t \ | \ \text{read(0)}\not\in t \}$. take the trace $a_{1};a_{2};a_{3};\dots$ then, $\epsilon$ doesn't contain $\text{read(0)}$, and if $a_{1}$ isn't bad, then all the prefixes aren't bad, and so on.

$G_{1}$ is safety because a trace can only contain $\text{read(0)}$ if and only if one of its prefixes contain $\text{read(0)}$. a trace is in $G$ if and only if all of its prefixes are also in $G$. 

on the other hand, consider $G_{1}'=\{ t \ | \ \text{read(0)}\not\in t \}$. then, this is still a policy (you can construct this set of traces), but it is not safety. if we encounter the trace`r(1);r(1);r(0)`, then the first prefix is bad, meaning everything else is bad. once the prefix goes bad at a certain length, it stays bad for everything after.

so, a mechanism detecting safety can just monitor the actions for as long as it is good, and once it goes bad, the mechanism can step in.

## liveness
a dual to safety. says that there is always a way to fix a bad trace. so, a property $G$ is liveness if and only if $$\forall \text{ finite }t_{1},\ \exists t_{2} : t_{1};t_{2}\in G$$to prove that a property is not liveness, we can simply find a $t_{1}$ such that there is no $t_{2}$ that can fix the problem. 

for example, consider $G_{1}$ from above. then, if $t_{1}$ is $\text{read(0)}$, then by definition of $G_{1}, \forall t_{2} : t_{1};t_{2}\not\in G_{1}$. we can prove the reverse similarly, to show that $G_{1}$ is not safety.

$G_{3}=\{ t \mid \text{req(i)} \in t \implies \text{send(i)} \in t \}$. 

consider $G_{4}=\{ t\mid t \text{ is finite} \}$. this is the "termination" property.
we can easily prove that $G_{4}$ is liveness. by definition of liveness, $t_{1}$ must already be finite. then, $t_{1} \in G_{4} \implies t_{1};\epsilon\in G_{4}$ (our $t_{2}$ in this case would be the empty trace $\epsilon$).

however, we can prove that this is not safety. suppose that there is an infinite trace $a_{1};a_{2};a_{3};\dots$ then, all the prefixes of this trace is finite (meaning $\text{prefixes(t)}\in G_{4}$); but **the trace itself** is infinite, meaning $t\not\in G_{4}$. so, this is not safety.
## $P_{all}$
there is **exactly one** policy that exhibits both safety and liveness. $P_{all}$ considers **all** traces good. then, because all traces are good, you can fix a trace by doing nothing (liveness); and all of its prefixes are also good (safety).
$$\begin{align}
P_{all}=\{ p\mid true \} \\
G_{all}=\{ t \mid true \}
\end{align}$$
## decomposing
any property can be uniquely identified by separating it into a safety component and a liveness component. also, we can conjoin (aka intersect) a safety and a liveness into a property **that is neither**.

consider $G_{1}$ and $G_{4}$, then let $G_{5}=G_{1}\cap G_{4}$. $G_{4}$ says that any trace can be fixed; but in $G_{5}$, we can't fix it with `read(0)`. so, it is not liveness. similarly, if we take the trace `r(1);r(1);...`, then this trace satisfies $G_{1}$, all of its prefixes are good, but it doesn't satisfy $G_{4}$. so, it is not safety either.

in practice, liveness is very hard to enforce. so, we typically would try to approximate this with a safety (i.e. by setting a deadline), so a conversion is needed. combining two safeties is far easier. if we have a safety $G_{1}$ that a trace does not have `read(0)`, and another safety $G_{1}''$ that a trace does not have `write(0)`, then, the combination of those safeties is just monitoring both for `read(0)` and `write(0)` at a time.

Theorem: $\forall \text{ props } G \ \exists \ G_{S}, G_{L}$ such that:
1. $G=G_{S}\cap G_{L}$
2. $G_{S}$ is safety, $G_{L}$ is liveness

proof: suppose we have two sets $G_{s}$ and $G_{L}$ such that:
$$\begin{align}
G_{s}=\{ t \mid& \ \text{a. }t\in G \text{, or}\\ 
&\ \text{b. } t\text{ is finite} + t \text{ is fixable acc. to } G \text{, or}\\
&\ \text{c. } t\text{ is infinite} + \text{all of t's prefixes have been included in }G_{S}. \\
\}
\end{align}$$
$$\begin{align}
G_{L}=\{ t \mid& \ \text{a. }t\in G \text{, or}\\ 
&\ \text{b. } t\text{ is finite} + t \text{ is unfixable acc. to } G \text{, or}\\
\}
\end{align}$$
