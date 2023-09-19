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