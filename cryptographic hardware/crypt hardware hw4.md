	## problem 1
despite public-key cryptography having a lot of useful features and relatively simple processes, we still use symmetric-key cryptography for its security and speed. generally, symmetric key algorithms such as AES are much more performant when it comes to encrypting large volumes of data.

furthermore, symmetric key algorithms are much harder to break. for example, AES will require a brute force key search of $2^{n}$ bits, where $n$ can go up to 512, while public-key exchanges rely on hard mathematical problems such as discrete logarithms or prime factorization. while still difficult, these are much easier for an attacker to "guess" than something like AES.

## problem 2
1GB = 8Gbit
RSA decryption:
$$\frac{8\times 10^{9}}{100\times 10^{3}}= 80000s$$
AES decryption:
$$\frac{8\times 10^{9}}{17 \times 10^{6}}=470.59s$$

## problem 3
when Alice chooses case $a=1$:
- Alice's computed key: $A=g^{a}=g \mod p$
- Bob's computed key: $B=g^{b} \mod p$
- shared key: $k_{AB}=g^{b} \mod p$

now, the search range for the key is much less random, as the exponentiation is only reliant on $b$ instead of a large product $g^{ab}$.

when Alice chooses case $a=p-1$:
- Alice's key would now be $A=g^{p-1} \mod p$. because $p$ is a prime number, Fermat's Little Theorem states that $g^{p-1} \equiv 1 \mod p$. then, the shared key for both would now be 1. 
because this is such a special key with only a certain specific value, it is much easier for an attacker to guess the original $p-1$ private key.

## problem 4
the shared key for both Alice and Bob in this case would be $g(x)^{ab}$, reduced by the irreducible polynomial in $GF(2^{5}): x^{5}+x^{2}+1$
computing $g^a$: 

$$\begin{align}
(x^{2})^{3}  & =x^{6} \\
 & =x^{3}+x \text{ (reduced by } P(x) )
\end{align}$$
computing $g^{ab}$:
$$\begin{align}
(x^{3} +x)^{12}  & =(((x^{3}+x)^2)^2)^3 \\
 & = ((x^{6}+x^2)^{2})^{3} \\
 & =((x^{3}+x^{2}+x)^{2})^{3} \ \ \ \ (\text{ reduced by } P(x)) \\
 & =(x^{6}+x^{4}+x^{2})^{3} \\
 & =(x^{4}+x^{3}+x^{2}+x)^3\ \ \ \ (\text{ reduced by } P(x))  \\
 & =(x^{8}+x^{6}+x^{4}+x^{2})\times(x^{4}+x^{3}+x^{2}+x)  \\
 & =(x^{5}+x^{3}+x^{3}+x+x^{4}+x^{2})\times(x^{4}+x^{3}+x^{2}+x) \quad (\text{ reduced by } P(x))  \\
& =(x^{2}+1+x+x^{4}+x^{2})\times(x^{4}+x^{3}+x^{2}+x) \quad (\text{ reduced by } P(x))  \\ 
& =(x^{4}+x+1)\times(x^{4}+x^{3}+x^{2}+x) \quad (\text{ reduced by } P(x))  \\
 & =x^{8}+x^{7}+x^{6}+x^{5}+x^{5}+x^{4}+x^{3}+x^{2}+x^{4}+x^{3}+x^{2}+x \\
 & =x^{8}+x^{7}+x^{6}+x \\
 & =x^{5}+x^{3}+x^{4}+x^{2}+x^{3}+x \\
 & =x^{2}+1+x^{4}+x^{2}+x  \\
 & =x^{4}+x+1
\end{align}$$

## problem 5

| quotient   | remainder      | s                 | t                  |
| ---------- | -------------- | ----------------- | ------------------ |
|            | 26             | 1                 | 0                  |
|            | 7              | 0                 | 1                  |
| 26 / 7 = 3 | 26 - 7 x 3 = 5 | 1 - 0 x 3 = 1     | 0 - 1 x 3 = -3     |
| 7 / 5 = 1  | 7 - 5 x 1 = 2  | 0 - 1 x 1 = -1    | 1 - 1 x (-3) = 4   |
| 5 / 2 = 2  | 5 - 2 x 2 = 1  | 1 - (2 x -1) = 3  | -3 - (2 x 4) = -11 |

so, the inverse of 7 in the ring $Z_{26}$ is 26 - 11 = 15.

## problem 6
according to Fermat's Little Theorem: if $p$ is a prime number, $a^{p-1}\equiv 1 \mod p$, so $a \times a^{p-2}\equiv 1$. then, the inverse of $a$ would be $a^{p-2}$.

in this case, we are finding $6^{11}\mod 13$:
$$\begin{align} 
 & 6\times 6 \times \dots \times6 \mod 13 \\
 & =10 \times 10 \times 10 \times 10 \times 10 \times 6 \mod 13 \\
& =9 \times 9 \times 8 \mod 13 \\
 & =3 \times 8 \mod 13 \\
 & =11 \mod 13
\end{align}$$

so, the inverse of 6 mod 13 is 11.

## problem 7
a. 
on average, the number of clock cycles taken to run $1.5k$ multiplication operations is $1.5ck^{3}$. then comparing the ratios between running RSA with 1024 bits versus 512 bits:

$$\frac{1.5c\times 1024^{3}}{1.5c \times 512^{3}}=\frac{2^{30}}{2^{27}}=8 \text{ times}$$
so, 1024 bit RSA is 8 times slower than 512 bits.

b.
using Karatsuba's multiplication with a lesser weight on the exponent and calculating the ratio:
$$\frac{1024^{2.585}}{512^{2.585}}=2^{2.585}=6 \text{ times}$$
