A universal conditional statement is a statement of the form: $\forall x$, if $P(x)$ then $Q(x)$.

E.g. "$\forall x \in R$ if $x$ > 2, then $x^2$ > 4."
- The square of any real number greater than 2 is larger than 4. 

The **predicate** "if $x$ > 2, then $x^2$ > 4" is valid for all real numbers $x$, so these statements are all true: 
- If $x$ > 2, then the conclusion is indeed true. 
- If $x \leq 2$, then the statement is **vacuously** true.

Every universal conditional statement with the form $\forall x \in U$, if $P(x)$ then $Q(x)$ can be rewritten as $\forall x \in D, Q(x)$ where $D$ is the truth set of $P(x)$.

### Bound variables and scope
Consider the following statements: 
(1) For every integer $x$, $x^2 \geq 0$
(2) There exists a real number $x$ such that $x^3 = 8$

Although both statements make a reference to the variable $x$, it serves a different function in this case. The variable is **bound** by the **quantifier** that introduces it, and its scope **ends** when the statement terminates.

### Implicit quantification
The universal statement *If a number is an integer, then it is rational* is an example of an **implicitly quantified** statement as it does not contain explicitly contain quantifying language. 

In this case, this can also mean $\forall x \in R$, if $x$ is an integer, then $x$ is rational. 

Existential statement can also be implicitly quantified, for example: *The number 24 is the product of two even integers.*

Explicitly, this is: *There exists m, n where mn = 24*, or $\exists m; n, m\cdot n = 24$ 
