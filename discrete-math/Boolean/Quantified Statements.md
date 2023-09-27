## Predicates

Consider $x^2 + 2 = 11$. 
If we choose a particular real $x$, this sentence becomes a statement that is true when x = 3 or x = -3 and false otherwise. 

If we allow $P(x)$ to represent the sentence, then P is a function from set R to a set of statements with a truth value. E.g.
- $P(-3)$ is the **true** statement,
- $P(1)$ is the false statement,

This type of sentence $P(x)$ is called a *predicate, open sentence, or propositional function*.
The **domain** of the predicate is the set of all input values for consideration.
The **truth set** of a predicate is a subset of the domain for which the resulting statement is true. 

We can form predicates using more than one, but **finitely** many variables. Consider these, and their truth sets: 

| Symbol  | Domain | Predicate                          | Truth Set                                          |
| ------- | ------ | ---------------------------------- | -------------------------------------------------- |
| P(x)    | R      | $x^2 - 2 = 11$                     | {3; -3}                                            |
| Q(x, y) | R x R  | $x + y = 0$                        | The line in $R^2$ through the origin with slope -1 |
| E(n)    | Z      | If $n$ is even then $n^2$ is even. | Z                                                  |

### Procedures
```cpp
procedure Universal(D, P): 
	for all x in D do: 
		if not P(x) then
			return false
		end if
	end for
	return true
end procedure

procedure Existential(D, P): 
	for all x in D do: 
		if P(x) then
			return true
		end if
	end for
	return false
end procedure
```

These are examples of **quantified statements**, formed from predicates by adding quantifiers like **“some”** or **“all”**.

## Universal statement
Let $Q(x)$ be a predicate with domain $D$. Then, 
$$\forall x \in D,Q(x)$$
means “For all x in D, Q(x).” This sentence (or any semantic equivalent) is called a **universal statement**.

- This statement is *true* if $Q(x)$ is **true** for **all** $x$ in $D$, or the universal statement is true if the **truth set** **is equal to its domain**.
- This statement is *false* if $Q(x)$ is **false** for **some** $x$ in $D$, or the universal statement is false if $x$ is a **counterexample** to Q. 

## Existential statement
Let $Q(x)$ be a predicate with domain $D$. Then, 
$$\exists x \in D: Q(x)$$
means "There exists x in $D$ such as $Q(x)$". This sentence (or any semantic equivalent) is called a **existential statement**.

- This statement is *true* if $Q(x)$ is true for **some** (at least one) $x$ in $D$, or the universal statement is true if the **truth set is nonempty**.
- This statement is *false* if $Q(x)$ is false for **all** $x$ in $D$, or the universal statement is false if the **truth set is empty**. 

## Conditional statement
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

Explicitly, this is: *There exists m, n where $m \times n$ = 24*, or $$\exists \space m; n, m\cdot n = 24$$
We can also do this symbolically, by using the notion $\implies$. So in this case, $P(x) \implies Q(x)$ means every element in the truth set of P(x) is in the truth set of Q(x). Or, $$\forall x, P(x) \rightarrow Q(x)$$
Also $\Longleftrightarrow$ means that $P(x)$ and $Q(x)$ have exactly identical truth sets.

## Negation

### Of your average Quantified Statements
The negation of a quantified statement, such as *All mathematicians wear glasses* is *Not all mathematicians wear glasses* or *Some mathematicians do not wear glasses.*

So, for $P(x)$ being a predicate with the domain $D$, the negation of $P(x)$: $$\lnot [\forall x \in D, G(x)] \equiv \exists x \in D: \lnot G(x)$$ and $$\lnot [\exists x \in D, G(x)] \equiv \forall x \in D: \lnot G(x)$$
which sort of means that there exists an exception to the rule, or a counterexample to the given predicate.

Refer to [[#Procedures]], for every $P$ and $D$, then: **not** `Universal(D,P)` = `Existential(D, not P)`
This can also be proven with De Morgan's law.

### Of conditional statements
Recall that the negation of $p \rightarrow q$ has the equivalent negation of $p \land \lnot q$. Similarly, the negation of $\forall x, P(x) \rightarrow Q(x)$ negates to $P(x) \land \lnot Q(x)$. So,
$$\lnot[\forall x, P(x) \rightarrow Q(x)] \equiv \exists x,P(x) \land \lnot Q(x)$$
## Vacuous truth
If $D$ is an empty set, then: 
- The existential statement $\exists x \in D, A(x)$ is **false by default** for any predicate A, because nothing exists to prove it.
- On the contrary, the **universal** statement $\forall x\in D, B(x)$ is **true by default** for any predicate B.

## [[Multiple Quantifiers]]