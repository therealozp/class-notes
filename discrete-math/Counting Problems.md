If $a \leq b$, then the **integers** from a to b that are **divisible by $d$** can be obtained by using:
$$\lfloor\frac{b}{d}\rfloor -\lceil\frac{a}{d}\rceil + 1$$
So, for example, for the question: 
> How many numbers from 1 to 10000 are divisible by 2, 3, or 7? 

The procedure will be as follows.
Let:
- A be the numbers divisible by 2: there will be 5000 of them
- B be the numbers divisible by 3:  there are 3333 of them
- C be the numbers divisible by 7: there are 1428 of them
- $A \cap B$ are the numbers divisible by 6: 1666
- $A \cap C$ are the numbers divisible by 14: 714
- $C \cap B$ are the numbers divisible by 21: 476
- $A \cap B \cap C$ are the numbers divisible by 42: 238 numbers. 

Applying the intersection rule [[Probability# Inclusion - Exclusion]] onto these sets, we get the numbers divisible by 2, 3, and 7 is ($A \cup B \cup C$) are 7143 numbers.