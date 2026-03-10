any [[properties|property]] can be uniquely identified by separating it into a [[safety properties|safety]] component and a [[liveness properties|liveness]] component. also, we can conjoin (aka intersect) a safety and a liveness into a property **that is neither**.

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
&\ \text{b. } t\text{ is finite} + t \text{ is unfixable acc. to } G \\
\}
\end{align}$$
