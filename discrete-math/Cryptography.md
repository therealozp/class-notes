## GCD, Relative Primality, and Euler's Totient
To produce invertible functions $E$ and $D$ on set $Z_n$ of integers mod some $n$, we need to  find $e$ and $d$ such that $x^{ed} = x$ for all x. 

The GCD is the largest integer $d$ that divides both $a$ and $b$. In case $gcd(a, b) = 1$, then the two numbers are **relatively prime.** An integer is prime if $gcd(a, p) = 1 \forall x < p$.  

For an integer $n > 1$, let $\phi(n)$ count the **number of positive integers smaller** than $n$ that are relatively prime to $n$. This is the Euler's Totient function.

We will have the following results from number theory that will be useful: 
- If $p$ and $q$ are 2 **distinct primes**, $\phi(p) = p-1$,  $\phi(q) = q-1$,  and $\phi(pq) = (p-1)(q -1)$.

We can generalize this as, for $p$ and $q$ being two distinct primes:
$$\phi(pq) = (p-1)(q-1)$$
The proof is simple, but yields a very strong formula: 

![[Pasted image 20231018163205.png]]

## Euler and Fermat Theorems
**Euler's Theorem**: If $a$ and $n$ are relatively prime, then $a^{\phi(n)} \equiv 1 (\mod n)$
**Fermat's Little Theorem**: If $p$ is prime and does not divide $a$ then $a^{p -1} \equiv 1 \mod p$. 

## Modular Inverses
For a modulus $n$, we say that $a$ and $b$ are (multiplicative) **inverses** modulo $n$ if $ab \equiv 1 (\mod n)$. Compare this to multiplicative inverses (reciprocals) of real numbers. 

**!! IMPORTANT !!** to find the modular inverse, the numbers **have to be coprime.**

Let $e$ and $d$ be integers such that $ed \equiv 1 (\mod \phi(n))$. Then, $ed  - 1 \equiv k\cdot \phi(n)$. By Euler's theorem, if $x$ and $n$ are relatively prime, then: 
$$x^{ed - 1} = x^{k\cdot\phi(n)} = 1^k (\mod n)$$
Multiply both sides by $x$, we get: 
$$x^{ed} = x \mod n$$
From this, we get the theorem: 

Let $p$ and $q$ be distinct primes and let $n = pq$ be a modulus. If $e$ is relatively prime to $\phi(n)$, and $d$ is the inverse of $e$ modulo $\phi(n)$, i.e. $ed \equiv 1(\mod \phi(n))$. Then, we have: 
$$x^{ed} = x \mod n$$

I legit do not understand why it's phrased so complicated. Basically, to calculate the modular inverse of a number $a \mod n$, we do the following steps: 

Do the [[#Extended Euclidean Algorithm]], and get the form $ax + by = gcd(a, b)$, where $a, b$ are numbers such as 73 and 660. 

Now, for example, if you are asked to find the **modular inverse** of $73 \mod 660$, we can begin evaluating the steps for the EEA, which yields $x$ and $y$ as $217$ and $-24$. The $x$ and $y$ we yield, respectively, **are** the modular inverses.

However, consider a more complicated case, where we are expected to find the least modular inverse: 
$$73u=130\mod 660$$


## Extended Euclidean Algorithm
The RSA algorithm relies on being able to find integers $e$ and $d$ that are inverse modulo $\phi(n)$ where $n = pq$ for distinct primes $p$ and $q$.

**Theorem (Bezout's identity)**: Let $a$ and $b$ be integers. Then, there exists integers $x$ and $y$ such that $gcd(a, b) = ax + by$.

In the special case that $a = \phi(n), \ b = e, \ y = d$ and $gcd(a, b) = 1$: 
$$gcd(a, b) = ax + by \rightarrow 1 = \phi(n)\cdot x+ed$$
or, in other words, $ed \equiv 1(\mod \phi(n))$.

In general, the EEA will allow us to, for any integers $a$ and $b$, compute the respective $x$ and $y$. 
How to: construct the EEA table. Work by filling in the columns with the quotient, remainder, $x$, and $y$.
The formula for getting $x_i = x_{i-2} - q \times x_{i - 1}$, and the similar goes for $y$.

## Injective vs Surjective functions
Let $f: X \rightarrow Y$ be a function with domain X and co-domain Y. For $x \in X$, the value $f(x)$ might be called: 
- f of x
- the value of $f$ at $x$
- the output of $f$ for the input $x$
- the image of $x$ under $f$

For a subset $A \subseteq X$, the image of $A$ under $f$ are the set of all $y$ values that are the image of some $x \in A$, i.e.
$$f(A) = \set{f(x) : x\in A}$$
The image f(X) of the whole domain is called the *range* of $f$. 
### Injective
So, let $f$. We call $f$ a **one-to-one** or **injective** if, for every $x_1, x_2$, we have: 
$$\begin{split}
 f(x_1) = f(x_2) &\rightarrow x_1 = x_2 \\
 x_1\not=x_2& \rightarrow f(x_1) \not=f(x_2)
\end{split}$$
### Surjective
We call $f$ **onto** or **surjective** if for every $y \in Y$ there is some $x\in X$ such that $y =f(x)$, or equivalently, the range and co-domain are equal. 

So, if a function satisfies both these requirements, then $f$ is a **one-to-one correspondence** function, or it is a **bijection.**

