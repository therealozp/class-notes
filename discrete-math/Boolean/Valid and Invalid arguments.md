| $p \rightarrow q$ | $p$ | $q$ |
| ----------------- | --- | --- |
| T                 | T   | F   |
| F                 | T   | F   |
| T                 | F   | T   |
| T                 | F   | F   |

We are considering the **premises** ($p \rightarrow q$, $p$) and the conclusion ($q$). The argument is only **valid** if any only where if **all of the premises are true**, and the **conclusion is also true.**

- An argument form is a sequence of statement forms, called **premises**, **assumptions**, or **hypotheses**, followed by a statement form called **conclusion**, which may be preceded by the symbol nom nom, meaning "therefore"
- Argument form is considered valid if **true premises always result in a true conclusion**
- Any argument made with a valid form is considered **valid**, even if the substitution made results in some false premise(s). 
- To be a **sound** argument, the argument must both be **valid** and have **all true premises.**
- Invalid arguments, made with an invalid form, are **never considered sound**, even if all the premises are true.
- For any valid argument, the conclusion **follows** from the premises. 

When we are talking about *validity*, we are talking about its form; when we are talking about *soundness*, we are talking about it's applications. 

## Modus Ponens (affirming the antecedent)

$p \rightarrow q$      If  you are in this class, then you are a USF student.
$p$             You are in this class.
$\therefore q$          You are a USF student.

| $p \rightarrow q$ | $p$ | $q$ |
| ----------------- | --- | --- |
| T                 | T   | F   |
| F                 | T   | F   |
| T                 | F   | T   |
| T                 | F   | F   |

- Case 2: If non-USF students could take this class, this argument would be **unsound.** 
So, a valid argument but with a **false premise** makes the argument **unsound.**

### Converse Error (affirming the consequent)
Let's make an invalid argument with a small change in form: 
$p \rightarrow q$      If  you are in this class, then you are a USF student.
$q$             You are a USF student
$\therefore p$          You are in this class.

- This invalid form is known as *affirming the consequent* or the *converse error.*
- To determine whether an argument form is valid or invalid, we can look at the **critical rows**, where *each premise is true.*
- If any critical row has a *false conclusion*, as is the case here, **the argument form is invalid**.

> To determine validity, you only have to look at the critical rows.

When determining the validity of the argument, always look at the critical rows (e.g. **the consequent does not matter**)

## Modus Tollens
The form provided is called **modus tollens** or **denying the consequent**: 

$p \rightarrow q$              If Zeus is human, then he is mortal.
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

### Inverse Error (denying the antecedent)
Another invalid argument form, taken under something like: 
$p \rightarrow q$      If  you are in this class, then you are a USF student.
$\lnot p$           You are not in this class
$\therefore \lnot q$        You are not a USF student.

Note that the **inverse** of $p \rightarrow q$ is $\lnot p \rightarrow \lnot q$, hence the name of the argument.
## Rules of inference
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
- Show that n being odd implies (n+1) is even ($p \rightarrow r$) 
- Show that n being even implies (n+1) is **still** even ($q \rightarrow r$)

## Fallacy
A fallacy is an error in reasoning that results in a faulty argument. They could be used in argument form directly, using **ambiguous premises**, or **assuming the consequent.**

We also have the inverse fallacy, or **denying the antecedent.** It has he invalid form: 
$p \rightarrow q$
$\lnot p$
$\therefore \lnot q$

If $p$ is false, the premises becomes true, but the conclusion cannot be deduced either way.

### Circular reasoning
$p \rightarrow q$
$q \rightarrow r$
$r \rightarrow p$
$\therefore p \land q \land r$

This can also work when all premises are vacuously true (aka when they are all false). To fill this void, another premises is needed: $p \lor q \lor r$

## The contradiction rule
$\lnot p \rightarrow c$, where c is a contradiction
$\therefore p$

This is especially powerful when a direct proof is not available, and a false reality such as this is needed to conclude the truth of $p$,


**Step 1**
$q \rightarrow r$    by premise (b)
$\lnot r$         by premise (d)
$\therefore \lnot q$      by modus tollens

**Step 2**
$p \lor q$       by premise (a)
$\lnot q$          by Step 1
$\therefore p$         by elimination

**Step 3**
$\lnot q \rightarrow u \land s$  by premise (e)
$\lnot q$               by Step 1
$\therefore u \land s$        by modus ponens
$\therefore s$              by specialization

**Step 4**
$p$                   by Step 2
$s$                   by Step 3
$p \land s \rightarrow t$      by premise (c)
$\therefore t$                by modus ponens