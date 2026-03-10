a dual to [[safety properties|safety]]. says that there is always a way to fix a bad trace. so, a [[properties|property]] $G$ is liveness if and only if $$\forall \text{ finite }t_{1},\ \exists t_{2} : t_{1};t_{2}\in G$$to prove that a property is not liveness, we can simply find a $t_{1}$ such that there is no $t_{2}$ that can fix the problem. for example, consider $G_{1}=\{ t\mid \text{read(0)} \not\in t \}$. then, if $t_{1}$ is $\text{read(0)}$, then by definition of $G_{1}, \forall t_{2} : t_{1};t_{2}\not\in G_{1}$. we can prove the reverse similarly, to show that $G_{1}$ is not liveness.

however, the property $G_{1}'=\{ t \ | \ \text{read(0)}\in t \}$ is indeed liveness. for any $t_{1}$, you can make a valid trace by appending $\text{read(0)}$ at the end.

$G_{3}=\{ t \mid \text{req(i)} \in t \implies \text{send(i)} \in t \}$. 

consider $G_{4}=\{ t\mid t \text{ is finite} \}$. this is the "termination" property.
we can easily prove that $G_{4}$ is liveness. by definition of liveness, $t_{1}$ must already be finite. then, $t_{1} \in G_{4} \implies t_{1};\epsilon\in G_{4}$ (our $t_{2}$ in this case would be the empty trace $\epsilon$).

however, we can prove that this is **not** safety. suppose that there is an infinite trace $a_{1};a_{2};a_{3};\dots$ then, all the prefixes of this trace is finite (meaning $\text{prefixes(t)}\in G_{4}$); but **the trace itself** is infinite, meaning $t\not\in G_{4}$. so, this is not safety.