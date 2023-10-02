#discrete_math 
## 1. What?
---
A sentence that is either true or false, **but not both** (or neither). There is only one well-defined truth value, which **can be unknown**. Truth values can be: 
- evident from the sentence itself (e.g. 2 + 2 = 5 is False)
- evident from the sentence that is has one. "There are an odd number of stars in the universe." 
- assigned for the sake of argument or analysis

Some sentences should not be considered statements, either because: 
- it is a question (and assigning it a truth value does not make sense)
- it uses ambiguous, imprecise, unclear, or subjective terms (e.g. Math is the best subject)
- it uses undefined variables
- it refers to itself

### Compound statements
A statement formed from simpler statements with connective such as *and, or,* and *not*, symbolized with $\land$, $\lor$, and $\lnot$. As for order of operations, $\lnot$ is evaluated **first**. E.g: 
$$\lnot p \land q = (\lnot p) \land q $$
The negation of $p$ means $\lnot p$, where: 

| $p$ | $\lnot p$ |
| --- | --- |
| T | F |
| F | T |

The conjunction of $p$ and $q$ ($p \land q$) only returns *True* when both are true.

| $p$ | $q$ | $p \land q$ |
| --- | --- |:-----------:|
| T   | T   |      T      |
| T   | F   |      F      |
| F   | T   |      F      |
| F   | F   |      F      |

The disjunction of $p$ and $q$ ($p \lor q$) returns *True* if either $p$ or $q$ is true.

| $p$ | $q$ | $p \lor q$ |
| --- | --- |:----------:|
| T   | T   |     T      |
| T   | F   |     T      |
| F   | T   |     T      |
| F   | F   |     F      |

Also there is a difference between $=$ and $\equiv$, where the first means **correct for a certain setup**, where the second means **correct for EVERY setup.** So: 
$$ \lnot p \land \lnot q \equiv \lnot(p \lor q)$$
### The statement form
The statement (or propositional) form is an expression made up of statement variables and logical connectives that becomes a statement when **actual statements** are substituted for components. 

The truth table is basically what is drawn in [[#Compound statements]], where there are $2^n$ rows with n being the number of variables.

The disjunction $p \lor q$ is the *inclusive or*. *Exclusive or* only returns true when **either p or q** is true, **but not both.** This can also be represented as $(p \lor q) \land  \lnot(p \land q)$. 

| $p$ | $q$ | $p \lor q$ | $p \land q$ | $\lnot(p \land q)$ | $(p \lor q) \land  \lnot(p \land q)$ |
| --- | --- |:----------:|:-----------:|:------------------:|:------------------------------------:|
| T   | T   |     T      |      T      |         F          |                  F                   |
| T   | F   |     T      |      F      |         T          |                  T                   |
| F   | T   |     T      |      F      |         T          |                  T                   |
| F   | F   |     F      |      F      |         T          |                  F                   |

### Logical equivalency
If two statements give the same truth value no matter what the statements are changed to, we say that they have logical equivalency. For example, **double negatives** ($\lnot (\lnot p))$ and are exactly the same as **normal** statements, which means they have *logical equivalency*.

> It will rain today or it will rain tomorrow = It will rain tomorrow or it will rain today, 

### De Morgan's law of logic: 
1. The negation of conjunctions is the disjunction of negations, i.e. 
$$\lnot (p \land q) \equiv \lnot p \lor \lnot q$$
2. The negation of disjunctions is the conjunction of negations, i.e. 
$$\lnot (p \lor q) \equiv \lnot p \land \lnot q$$
### Tautologies and Contradiction
1. A tautology is a statement that takes a tautological form, which returns **True** regardless of the truth values of its components. 
2. A contradiction is a statement that is contradictory, which returns False regardless of the truth values of its components.

For example, $p \lor \lnot p$ is a tautology, while $p \land \lnot p$ is a contradiction. 

| $p$ | $\lnot p$ | $p \lor \lnot p$ | $p \land \lnot p$ |
| --- | --------- | ---------------- | ----------------- |
| T   | F         | T                | F                 |
| F   | T         | T                | F                 |

### Summary of logical equivalencies
![[Pasted image 20230828164949.png]]


[[Conditional]]
[[Inequalities]]
