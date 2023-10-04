## Canon event
### Canonical sum of products
CSOP (canonical sum of products) can be found by finding the **minterms** $m_i$ of the boolean function such that $m_i = 1 \rightarrow F = 1$, that is, finding all rows of the truth table such that the **final function** equates to 1. From that point, find the values of individual statements and assemble the functions accordingly.

Here, **1 is dominant**. So, $x = 1$ and $x' = 0$
### Canonical product of sums
CPOS can be found by finding the **maxterms** $M_i$ instead, which is all the terms such that $M_i = 0 \rightarrow F = 0$. From that point, find the values of individual statements and assemble the product accordingly. 

Here, **0 is dominant.** So, the value of $x = 0$ and $x' = 1$

For example, consider the following truth table: 

## Logic gates
All logic design can be summed up with logic gates, namely **AND, OR, NOT.** Among these, there are the **NAND** and **NOR** gates, which produce complementary output to AND and OR respectively. 

Note that these two **NAND** and **NOR** gates are called *universal gates*, because a combination of these two can produce any combination of gates available. 

![[Pasted image 20231004105701.png]]
