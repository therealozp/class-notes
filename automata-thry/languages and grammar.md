## languages
1. we start with a finite non-empty set $\Sigma$ of symbols, called **alphabet**.
2. then we have stings, which are **finite** sequences of symbols from the alphabet, e.g $\Sigma = \set{a, b}$ then "abab" or "abbabab" are strings on $\Sigma$. 
3. the "=" notation means a certain variable will have a value "abaa". the length of a string is denoted with $\mid w \mid$.

If $\Sigma$ is the alphabet, then we use $\Sigma ^*$ to denote the set of strings obtained by concatenation zero or more symbols from $\Sigma$. $\Sigma ^*$ will always contain $\lambda$, while $\Sigma ^+$ does not contain $\lambda$. 

the set $\set{a,aa, bbb}$ is a language on $\Sigma$, and because it is finite, we call it the finite language. by contrast, the set $\set{a^{n}b^{n} : n \geq 0}$ is an infinite language.

since languages are sets, we can also define the union, intersection, and difference of the two. the complement is defined with respect to $\Sigma ^*$, so the complement of $L$ is $L^{C}= \Sigma ^*-L$.
### concatenation
concatenating $v$ and $w$ means to append the symbols of $v$ to the left of $w$. 
the concatenation of 2 sets $L_{1}$ and $L_{2}$ is obtained by concatenating any 2 elements in these 2 sets, meaning $L_{1}L_{2} = \set{xy : x \in L_{1} \land y \in L_{2}}$. 
we define $L^n$ as the language concatenated with itself $n$ times. by default, $L^{0} = \set{\lambda}$ and $L^{1}= L$ 
### reversal
write all symbols in reverse order. the reverse of an empty string is itself, and is often denoted by $\lambda$. 
the relation $\mid\lambda\mid = 0$, $w\lambda = \lambda w$ **always holds**. 
the reversal set of a language is the set of all string reversals, meaning $\set{w^{R}:w\in L}$.
### repetition
$w^{n}$ means the string obtained after repeating the string $n$ times. as a special case, $w^{0} = \lambda$ for all $w$. 
## prefixes and suffixes
any string of consecutive symbols in some $w$ is said to be a sub-string of $w$. if $w = vu$, then $v$ and $u$ are said to be the prefix and suffix, respectively, for example, if $w =$ $abab$, then $\set{\lambda, a, ab, aba, abab}$ is the set of all prefixes.
## closures
### the star 
the star closure of a language $L^{*}$ is $L^{0}\cup L^{1}\cup L^{2} \cdots$ meaning union of the infinite concatenations.
### the positive closure
basically star closure minus $L^0$.

## examples
$L_{1}= \set{\lambda, a, ab}$
$L_{2} = \set{a^{n}b^{n}: n \geq 0}$
$L_{3} = \set{(ab)^{n}: n \geq 0}$
$L_{4}= \set{a, b, ab, aab}$

Note, for $L_{2}$ and $L_3$, if the condition should change to be $n\geq 1$, the resulting language will not contain $\lambda$. Similarly, for finite languages such as $L_4$, if it is said to **not** contain $\lambda$, then the language does not contain $\lambda$. 

Suppose that $L_{1} = {a^{n}b^{n}: n\geq 0}$ and $L_2$ defined the same. Then, the concatenation of these two languages will not simply be $L_{3}=\set{a^{n}b^{n}a^{n}b^{n}:n\geq 0}$. Because the $n$ in $L_1$ and $L_2$ is can be out of phase (that is, $n_1$ can be 2 and $n_2$ can be 4 or literally any other value), we cannot simplify both to a single $n_3$.

Instead, the language $L_1L_{2} = \set{a^{n}b^{n}a^{m}b^{m}: n, m \geq 0}$.  

