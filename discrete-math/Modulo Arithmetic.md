The mod operator (%) gives you the remainder of a division operation. 

Let R be the relation on $\mathbb{Z}$ where $x\ R\ y$ whenever $x - y \mod 12 = 0$. There is an **equivalence relation** with 12 equivalence classes. 
When S is any equivalence class of a relation, we call any $a$ such that $[a] = S$ a **representative** of the class. (view [[Relations# Equivalence relations and partitions]])

## Congruence
Let $a$ and $b$ be integers, and $n$ is a positive integer. We say that $a$ is **congruent** to b modulo n: 
$$a \equiv b (\mod n) \ or \ a\equiv_nb$$
whenever $n$ divides $a  -b$. 
## Base truths
Given $a, b, n$ be any integers where $n > 1$. All the following are equivalent: 
1. $n \mid (a - b)$
2. $a \equiv b (\mod n)$
3. $a = b + kn$ for any integer k
4. $a$ [[Modulo Arithmetic]] and $b$ have the same remainder when divided by $n$
5. $a \mod n = b \mod n$
## Residues
Given integers $a$ and $n$ where $n>1$, the **residue** of $a \mod n$ is the remainder of said operation. 
The numbers 0, 1, 2, ... n - 1 are called a **complete set of residues** and are the least nonnegative set of complete residues. 
In clock arithmetic, we use 1, 2, 3,..., 12 as a complete set of residues modulo 12.
To *reduce a number **mod** n* is to set it equal to is residue mod n. 

> The equivalence classes of congruence modulo n are completely represented by the **residues mod n**. i.e. $[0], [1], [2], ...,[n-1]$ account for all equivalent classes.

## wtf is going on
Let $a, b, c, d$, and $n$ be integers with $n > 1$ and where $a \equiv c (\mod n)$ and $b\equiv d (\mod n)$
Then: 
1. $(a +b) \equiv (c+d) (\mod n)$
2. $(a-b) \equiv (c-d) (\mod n)$
3. $ab \equiv cd (\mod n)$
4. $a^m \equiv c^m (\mod n)$

## Modular Exponentiation and Repeated Squaring
Suppose that we would like to computer $10^{100} \mod 13$. Plugging this into any computer, we will get an overflow error, but we will have 2 methods to solve this: 
### Repeated squaring
The *general* method. We compute the square of 10 mod 13, and then keep doing that, and so on. So, we will eventually get: 

![[Pasted image 20231018155749.png]]

Now, we break down the exponent as powers of two: 100 = 64 + 32 + 4. And using the principle of exponents, we can get: $10^{100}=10^{64}\cdot 10^{32}\cdot10^4$. From this, we apply the same rule and multiply the mod: 3 * 9 * 3 = 81 (mod 13) = 3

### Modular exponentiation
We can also consider the fact that $10^3 \equiv -1 (\mod 13)$. From this, we can get: 
$$10^{100} = (10^{99})(10) = (10^3)^{33}(10) = (-1)^{33}\cdot 10 = -10 \equiv 3 \mod 13$$
So, the final value of $10^{100}\mod 13$ is 3. 
