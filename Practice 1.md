**Discrete Math Practice Test**

1. **Logical Equivalences and Rules of Inference**
   * Identify the name of the logical equivalence or rule of inference:
     a. $p \rightarrow q$ is equivalent to $\neg p \vee q$
     b. From $p$ and $p \rightarrow q$, infer $q$

2. **Identifying Statements**
   * Which of the following sentences should be considered statements?
     a. The moon is made of green cheese.
     b. What time is it?
     c. This statement is false.
     d. Water boils at 100°C under 1 atm pressure.

3. **Truth Tables**
   * Complete the truth table for $p \rightarrow (q \land \neg p)$

4. **Logical Equivalence**
   * Given the statement: $p \vee \neg q$
     Are the following statements logically equivalent?
     a. $\neg p \rightarrow q$
     b. $q \rightarrow p$
     c. $p \land q$

5. **Conditional Statements**
   * Given the conditional statement: If it rains, then the ground will be wet.
     a. Converse: 
     b. Contrapositive: 
     c. Inverse: 
   * Given: The compound statement $p \lor (q \land r)$ is true and $p$ is false. What can be deduced about $q$ and $r$?

6. **Negate Inequalities**
   * Negate the following inequalities (without using set theory or interval notation):
     a. $x > 5$
     b. $y \leq 8$

7. **Logical Equivalence**
   * Given the statement form $p \rightarrow (\neg q \lor r)$, apply logical equivalence rules to form an equivalent statement that uses only the 'and' $\land$ connective.

8. **Truth Tables for Argument Validity**
   * Given the argument: 
     $p \lor q$
     $\neg p$
     Therefore, $q$
   * Complete a truth table to determine the argument's validity.

9. **Valid Arguments**
   * Given major premise: All men are mortal.
     Select the minor premise and conclusion pairs that make the resulting argument valid:
     a. Socrates is a man. Therefore, Socrates is mortal.
     b. Socrates is mortal. Therefore, Socrates is a man.
     c. Socrates is not a man. Therefore, Socrates is not mortal.

10. **Equivalence of Statement Forms**
    * Determine whether the following pairs of statement forms are equivalent:
    a. $p \lor q$ and $q \lor p$
    b. $p \land (q \lor r)$ and $(p \land q) \lor (p \land r)$

11. **Deductive Reasoning**
    * Given the premises:
    $p \rightarrow q$
    $q \rightarrow r$
    Deduce $p \rightarrow r$ using rules of inference in a step-by-step manner.

12. **Quantified Statements**
    * Given the true statement: "All dogs bark."
    And its false negation: "No dogs bark."
    Demonstrate the true statement in symbolic form and the symbolic form for the false negation.

13. **Knights and Knaves**
    * On an island, there are only knights who always tell the truth and knaves who always lie. You meet two inhabitants: A and B. A says, "At least one of us is a knave." What are A and B?

14. **Mathematical Induction**
    * Prove via induction that for all positive integers $n$:
    $1^2 + 2^2 + 3^2 + ... + n^2 = \frac{n(n + 1)(2n + 1)}{6}$

---

**Answer Key**

1. a. Implication (or Material Conditional)
   b. Modus Ponens

2. a. Statement
   b. Not a statement
   c. Not a statement (it's a paradox)
   d. Statement

3. The completed truth table:

| T | T | F | F | F |
|---|---|---|---|---|
| T | F | F | F | T |
| F | T | T | T | T |
| F | F | T | F | T |

4. a. Yes
   b. No
   c. No

5. a. If the ground will be wet, then it rains.
   b. If it does not rain, then the ground will not be wet.
   c. If it does not rain, then the ground is not wet.
   $q$ and $r$ cannot both be false.

6. a. $x \leq 5$
   b. $y > 8$

7. $\neg p \land (q \lor \neg r)$

8. The argument is valid.

9. a. Valid
   b. Invalid
   c. Invalid

10. a. Equivalent
    b. Not equivalent

11. By Transitive (or Hypothetical Syllogism), $p \rightarrow r$

12. True statement: $\forall x (D(x) \rightarrow B(x))$
False negation: $\exists x (D(x) \land \neg B(x))$

13. A is a knight, and B can be either a knight or a knave.

14. Base Case: $n=1$ holds true. 
Inductive Step: Assume true for $n=k$ and prove for $n=k+1$.

Note: Some answers, especially those involving deduction, truth tables, and induction, are summarized for brevity and would need to be expanded upon in an actual answer key.