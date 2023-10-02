Let $p$ and $q$ be statements. A sentence of the form *If p then q* or *p implies q,* denoted symbolically, is $p \rightarrow q$ is called a conditional statement where: 
- $p$ is called the **hypothesis** or **antecedent**
- $q$ is called the **conclusion** or **consequent**

| $p$ | $q$ | $p \rightarrow q$ |
| --- | --- |:-----------------:|
| T   | T   |         F         |
| T   | F   |         F         |
| F   | T   |         F         |
| F   | F   |         T         |

Equivalent phrasings for $p \rightarrow q$ are: 
- $q$ if $p$
- $p$ only if $q$ / Only if $q$, $p$
- $p$ **is sufficient** for $q$
- $q$ **is necessary** for $p$

Consider the **vacuously true** statement: 
> If 0 = 1 then 1 = 3

This is true, but not usefully so. Like, if False, then False (which is True)

or (at present (Wednesday)): 
> If today is Sunday, then tomorrow is Friday. 

This is also true **by default**. Again, not useful (FFT)

## Truth tables with the Conditional
The precedence of $\rightarrow$ is low, so it will be resolved **last**. 
Constructing a truth table for $p \lor \lnot q \rightarrow \lnot p$

| $p$ | $q$ | $\lnot q$ | $p \lor \lnot q$ | $\lnot p$ | $p \lor \lnot q \rightarrow \lnot p$ |
| --- | --- | --------- |:----------------:| --------- |:------------------------------------:|
| T   | T   | F         |        T         | F         |                  F                   |
| T   | F   | T         |        T         | F         |                  F                   |
| F   | T   | F         |        F         | T         |                  T                   |
| F   | F   | T         |        T         | T         |                  T                   |

**Remark**: While $\lor$ and $\land$ are commutative, $\rightarrow$ is not. Be careful when determining truth table for conditionals. 

**Note:** there are two methods to attain the truth table when using conditionals: 
- Find the rows where the antecedent is True and the consequent is False, and put F's for every single one. Then, the rest is true.
- Alternatively, find all the rows where the antecedent is False, and mark T's. Then, copy the values of the consequent to the truth table.

## Equivalent Or, Contrapositive forms, and Negation

### Negation
Consider $p \rightarrow q$ and $\lnot p \lor q$. **These are logically equivalent.**
The disjunction $\lor$ is only false when $p$ is true, and $q$ is false. Which means that negating $p \rightarrow q$ will mean: 
$$
\begin{equation}
\begin{split}
\lnot (p \rightarrow q) & \equiv \lnot (\lnot p \lor q) \\
& \equiv \lnot (\lnot p) \land \lnot q \space \\ 
& \equiv p \land \lnot q
\end{split}
\end{equation}
$$

### The contrapositive
The contrapositive of "If $p$ then $q$" is *If not $q$, then not $p$*. Symbolically, the contrapositive of $p \rightarrow q$ is $\lnot q \rightarrow \lnot p$.

By equivalence, these three statements necessarily agree in truth: 
- If you are in this class, then you are a USF student.
- You're not in this class, or you are a USF student. ()
- If you are not a USF student, then you're not in this class. 

This statement necessarily disagrees in truth: 
- You are in this class, but you are not a USF student.

### Necessity and Sufficiency
Here are some equivalent ways to state a conditional $p \rightarrow q$ when using the terms *necessary* and *sufficient.*

| Sufficiency                       | Necessity                        |
| --------------------------------- | -------------------------------- |
| p is sufficient for q             | q is necessary for p             |
| p is a sufficient condition for q | q is a necessary condition for p |
| A sufficient condition for q is p | A necessary condition for p is q |

*Ex. 1*: A sufficient condition for being a USF student is to be in this class.
*Ex. 2*: A necessary condition for being in this class is to be USF student. (so you can be a USF student and NOT be in this class)

### Converse and inverse
If we have a conditional statement $p \rightarrow q$ then: 
- The **converse** is the statement $q \rightarrow p$
- The **inverse** is the statement $\lnot p \rightarrow \lnot q$

So, the **converse** is the **contrapositive** of the **inverse.**

## The Biconditional
The biconditional statement is defined as $p \leftrightarrow q$, or $(p \rightarrow q) \land (q \rightarrow p)$, and the **negation of the biconditional is the exclusive or**.

### Order of Operations
1. Evaluate negations $\lnot$ first. 
2. Evaluate $\lor$ and $\land$ second, using parentheses if both are present.
3. Evaluate $\rightarrow$ and $\leftrightarrow$ last, using parentheses if both are present.