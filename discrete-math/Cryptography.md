## GCD, Relative Primality, and Euler's Totient
To produce invertible functions $E$ and $D$ on set $Z_n$ of integers mod some $n$, we need to  find $e$ and $d$ such that $x^{ed} = x$ for all x. 

The GCD is the largest integer $d$ that divides both $a$ and $b$. In case $gcd(a, b) = 1$, then the two numbers are **relatively prime.** An integer is prime if $gcd(a, p) = 1 \forall x < p$.  

For an integer $n > 1$, let $\phi(n)$ count the **number of positive integers smaller** than $n$ that are relatively prime to $n$. This is the Euler's Totient function.

We will have the following results from number theory that will be useful: 
- If $p$ and $q$ are 2 **distinct primes**, $\phi(p) = p-1$,  $\phi(q) = q-1$,  and $\phi(pq) = (p-1)(q -1)$.

The proof is simple, but yields a very strong formula: 

![[Pasted image 20231018163205.png]]

## Euler and Fermat Theorems
**Euler's Theorem**: If $a$ and $n$ are relatively prime, then $a^{\phi(n)} \equiv 1 (\mod n)$
**Fermat's Little Theorem**: If $p$ is prime and does not divide $a$ then $a^{p -1} \equiv 1 \mod p$. 

## Modular Inverses
For a modulus $n$, we say that $a$ and $b$ are (multiplicative) **inverses** modulo $n$ if $ab \equiv 1 (\mod n)$. Compare this to multiplicative inverses (reciprocals) of real numbers. 

Let $e$ and $d$ be integers such that $ed \equiv 1 (\mod \phi(n))$. Then, $ed  - 1 \equiv k\cdot \phi(n)$. By Euler's theorem, if $x$ and $n$ are relatively prime, then: 
$$x^{ed - 1} = x^{k\cdot\phi(n)} = 1^k (\mod n)$$
Multiply both sides by $x$, we get: 
$$x^{ed} = x \mod n$$
From this, we get the theorem: 

Let $p$ and $q$ be distinct primes and let $n = pq$ be a modulus. If $e$ is relatively prime to $\phi(n)$, and $d$ is the inverse of $e$ modulo $\phi(n)$, i.e. $ed \equiv 1(\mod \phi(n))$. Then, we have: 
$$x^{ed} = x \mod n$$
