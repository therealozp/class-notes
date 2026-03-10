denote "the **finite** prefix of $t$" as $\leq t$. then, rules for prefixes are:
- $\epsilon \leq t$ for any $t$
- $a\leq a$
- $a \leq a;t$
- $t_{1}\leq t_{1};t_{2}$ if $t_{1}$ is finite. 
- $a_{i};a_{j};\dots \not \leq a_{i};a_{j};\dots$ because LHS is infinite. (RHS does **not** have to be finite)

a [[properties|property]] $G$ is safety if and only if $$\forall t : t\in G\iff \text{prefixes}(t) \subseteq G$$where $\text{prefixes}(t)$ is the set of all finite prefixes. the set of prefixes can be infinite, but each prefix is finite. a safety says insecure traces are irremediable (or a bad thing can't be fixed). **an access-control property is a safety**. safety properties are closed under intersection, meaning you can create a new safety policy by enforcing both in parallel.

consider again, the no-null dereference policy. then, $G_{1}=\{ t \ | \ \text{read(0)}\not\in t \}$. take the trace $a_{1};a_{2};a_{3};\dots$ then, $\epsilon$ doesn't contain $\text{read(0)}$, and if $a_{1}$ isn't bad, then all the prefixes aren't bad, and so on.

$G_{1}$ is safety because a trace can only contain $\text{read(0)}$ if and only if one of its prefixes contain $\text{read(0)}$. a trace is in $G$ if and only if all of its prefixes are also in $G$. 

on the other hand, consider $G_{1}'=\{ t \ | \ \text{read(0)}\in t \}$. then, this is still a policy (you can construct this set of traces), but it is not safety. if we encounter the trace`r(1);r(1);r(0)`, then the first prefix is bad, meaning everything else is bad. once the prefix goes bad at a certain length, it stays bad for everything after.

so, a mechanism detecting safety can just monitor the actions for as long as it is good, and once it goes bad, the mechanism can step in.
## closures
- safety is closed under union
- closed under intersection (by enforcing both in parallel)
- NOT closed under complement (proof: $G_{1}=\{ t \ | \ \text{read(0)} \not\in t \}$ (safety) vs $G_{1}'=\{ t \ | \ \text{read(0)}\in t \}$ (liveness))
- NOT closed under concatenation