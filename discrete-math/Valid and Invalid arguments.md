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
- Invalid arguments, made with an invalid form, are **never considered sound**, even if all the premises are true
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

### Invalid argument
Let's make an invalid argument with a small change in form: 
$p \rightarrow q$      If  you are in this class, then you are a USF student.
$q$             You are a USF student
$\therefore p$          You are in this class.

- This invalid form is known as *affirming the consequent* or the *converse error.*
- To determine whether an argument form is valid or invalid, we can look at the **critical rows**, where *each premise is true.*
- If any critical row has a *false conclusion*, as is the case here, **the argument form is invalid**.

> To determine validity, you only have to look at the critical rows.