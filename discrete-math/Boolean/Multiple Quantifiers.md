Consider the example: 
- There exists $(x, y) \in \mathbb{R}^2$ such that $x^2+y^2 = 1$. 
- There exists $x$ such that there exists $y$ such that $x^2+y^2 = 1$
- There exists $y$ such that there exists $x$ such that $x^2+y^2 = 1$

In essence, **universal statements are conjunctions**, and **existential statements are disjunctions**. For equivalence, the order of quantification does not matter, due to the rules of commutativity and associativity. 

## Negation
To form negations of multiple quantifiers, we apply the same rule for singly quantified statements, but do it **recursively** until everything is negated. For example:
$$
\begin{equation}
\begin{split}
\lnot [\forall x, \exists y:P(x, y)] \ &\  \equiv \exists x:\lnot[\ \exists y: P(x, y)\ ] \\
									 \ &\  \equiv \exists x: \forall y,\lnot P(x, y)
\end{split}
\end{equation}
$$
Go through every quantifier, and negate each step. Do it until you reach the final statement where a general form is not available.

## Quantified Arguments
### Universal rules of inference
(Also refer to [[Valid and Invalid arguments#Rules of inference]])
Under the universal operator, all rules of inference still apply: 

![[Pasted image 20230925222414.png]]
We have the **universal modus ponens**:
$\forall x, P(x) \rightarrow Q(x)$          (instantiation)
$P(a)$
$\therefore Q(a)$

We reason the validity with the **rule of universal instantiation**: if something is true for everything in a set, it is true for any *particular* thing in the set.

Consider the argument: 
All men are mortal
Socrates is a man
$\therefore$ Socrates is mortal.