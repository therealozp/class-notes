When determining the validity of the argument, always look at the critical rows (e.g. **the consequent does not matter**)

## Modus Tollens
The form provided is called **modus tollens** or **denying the consequent**: 

If p then q       If Zeus is human, then he is mortal.
$\lnot q$                   Zeus is not mortal.
$\therefore \lnot p$               Zeus is not human.

| $p$ | $q$ | $p \rightarrow q$ | $\lnot q$ | $\lnot p$ |
| --- | --- | ----------------- | --------- | --------- |
| T   | T   | T                 | F         | F         |
| T   | F   | F                 | T         | F         |
| F   | T   | T                 | F         | T         |
| F   | F   | T                 | T         | T          |

The truth table demonstrates its validity, but if we replace the conditional with the equivalent contrapositive then it becomes modus ponens.

An argument form consisting of two premises, a *major and minor premise*, is called a **syllogism.**

## Rule of inference
An argument form, like modus ponens/tollens, that is valid. Although any valid argument form is a rule of inference, they are normal used to make **deductions** of a **sequence of arguments.**

For example, given that the premises $p \rightarrow q$, $q \rightarrow r$, $r \rightarrow s$, $s \rightarrow t$, and $p$ is true, can we deduce the truth of $t$? (yes)

### Generalization
$p$                             $q$
$\therefore p \lor q$                    $\therefore p \lor q$

That is, knowing either $p$ or $q$ is true is enough to confirm the disjunction $p \lor q$ is true.

### Specialization
$p \land q$
$\therefore p$ (and $\therefore q$)

That is, knowing **both** $p$ and $q$ is true, we can confirm that $p$ (or $q$) in particular is true.

### Elimination
$p \lor q$ 
$\lnot p$ 
$\therefore q$

That is, knowing **either** $p$ or $q$ is true, and later learning that $p$ is false, we can confirm that $q$ is true. 

### Transitivity
$p \rightarrow q$ 
$q \rightarrow r$
$\therefore p \rightarrow r$ 

That is, if $p$ implies $q$; and $q$ implies $r$, then $p$ implies $r$. 

### Division into cases
$p \lor q$
$p \rightarrow r$
$q \rightarrow r$
$\therefore r$

E.g. outline a proof that the product of two consecutive integers is always even. 
**Solution**: the product of two consecutive integers n(n+1) where n is any integer. Then, the statement $p$, $q$, and $r$ are as follows: 
- $p$: n is odd
- $q$: n is even
- $r$: n(n+1) is even

Since this is a valid argument form, $r$ can be shown if we: 
- Use either the fact that *n is even* ($q$) or ($\lor$) *n is odd* ($p$)
- Show that n being odd implies n(n+1) is even ($p \rightarrow r$) 
- Show that n being even implies n(n+1) is even ($q \rightarrow r$)


## Fallacy
A fallacy is an error in reasoning that results in a faulty argument. They could be used in argument form directly, using **ambiguous premises**, or **assuming the conclusion.**

