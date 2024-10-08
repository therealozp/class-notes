## intuition
suppose that we have $m$ states and we have a language $a^{m+1}b^{c}$. this means that we will have to go over **at least one state** more than once. 

in more formal terms, if an **infinite language** is **regular**, some state must be repeated when processing a *sufficiently long* string. this repetition allows us to "pump" (repeat or delete) a section of string that corresponds to this cycle, thus creating **new strings** that **must also be in the language** should it be regular.

## the lemma statement
let $L$ be any infinite language. then, there exists a **positive** integer $m$, such that for any string $w \in L$ can be decomposed into $xyz$ where $\mid xy \mid \leq m$ and $\mid y\mid \gt 0$ such that: 
$$w_{i}=xy^{i}z \in L \ \text{for} \ i \geq0$$
for example, consider the language $L = a^{n}b$, then we can divide the language into the regex: 
$$(x\cdot a)\cdot(y\cdot a)\cdot(z\cdot a^{m-1}b)$$
then, the string $w_i$ defined above will hold true for all values of $i$.
## usage
the pumping lemma is used in proofs of contradiction to prove that a language is not regular. the end strategy is somewhat similar to a game: 
1. opponent picks the pumping length $m$
2. we pick $w \in L$ and $|w| \geq m$
3. opponent then decomposes $w = xyz$ where $\mid xy \mid \leq m$ and $\mid y\mid \geq 1$
4. we pick $i$ such that $w_{i}=xy^{i}z \not \in L$.

for example, consider the irregular language $a^{n}b^{n}$. then: 
1. opp. pick $m$.
2. we then pick $w = a^{m}b^{m}$. then, clearly $w \in L$ and $|w| \geq m$.
3. then, opp decomposes $w=xyz$ where $y = a^{k}: \ (1 \leq k \leq m)$.
4. we then find that $w_{0}=xy^{0}z=a^{m-k}b^{m} \not \in L$
therefore, the language $L$ is not regular.

another example we can pick is $L = \set{w \in \set{a, b}^{*}: n_{a}(w) < n_{b}(w)}$, or in human language, all strings on $\set{a, b}^{*}$ where the number of $a$'s is less than $b$'s. then: 
1. opp picks $m$.
2. we pick $w=a^{m}b^{m+1}$. then, it is clear that $w \in L$ and $|w| \geq m$.
3. the opponent then decomposes $w = xyz \rightarrow y = a^{k}: (1 \leq k \leq m)$
4. then: 
	- $w_{0}=xy^{0}z = a^{m}b^{m+1}$ (still in $L$)
	- $w_{0}=xy^{0}z = a^{m-k}a^{2k}b^{m+1}$ (not in $L$, because $m + k \geq m + 1$).

> the entire crux of the pumping lemma lies in **picking the right string** $w$.

## many, many more examples
let $L = \set{ww^{R}: w \in \set{a, b}^{*}}$
1. opp picks $m$.
2. we pick $w=a^{m}b^{m}b^{m}a^{m}$. then, it is clear that $w$ is in $L$. 
3. then, we are forced to decompose $w = xyz \rightarrow y = a^{k}: (1\leq k \leq m)$
4. then: 
	- $w_{0}= a^{m-k}b^{m}b^{m}a^{m}$, which is clearly not in $L$.

splitting into different cases: 
$L = \set{w \in \set{0, 1}^{*} \text{ such that } |w| \text{ is odd and 1 is the middle character}}$.
then: 
1. opp picks $m$. 
2. we pick $w = 0^{m}10^{m}$. 
3. decompose: $y = 0^k$.
4. then, we have 2 cases: 
	- if $k$ is even, then 1 is not the middle character
	- if $k$ is odd, then the string length is not odd.

$L = \set{w \in \set{a, b}^{*}: n_{a}(w) = n_{b}(w)}$.
1. opp picks $m$.
2. we pick $a^{m}b^{m}$.
3. decompose: $y = a^{k}: 1 \leq k \leq m$.
4. then, $w_{0}=a^{m-k}b^{m}$.

proof by complement: 
$L_{7} = \set{w \in \set{a, b}^{*}: n_{a}(w) \not = n_{b}(w)}$.
we already proved its complement above is irregular, hence it is also irregular.

fail cases: 
with the same example of $L_{7}$ above, we consider this: 
2. we pick $a^{m}b^{m + m}$
3. decompose $y = a^{k}$. 
4. then, we define $i = \frac{m}{k}+ 1$. then, $w_{i} = a^{m-k}a^{k(\frac{m}{k}+1)}b^{2m}$.
**this does not work.** because we have no guarantee that $\frac{m}{k}$ will be an actually integer, we cannot assign this to $i$.

alternatively, consider: 
2. we pick $a^{m}b^{m + m!}$
3. decompose $y = a^{k}$. 
4. then, we define $i = \frac{m!}{k}+ 1$. then, $w_{i} = a^{m-k}a^{k(\frac{m!}{k}+1)}b^{m+m!}$
**since $m!$** will always be divisible by $k$, this solution is correct.

$L = \set{a^{p}b^{q}: q \text{ is a multiple of } p}$
2. we pick $w = a^{m}b^{2m}$
3. decompose $y = a^{k}$
4. then, suppose that $i = 2m + 1$. then: 
	- $w_{2m+1} = a^{m-k}a^{k(2m+1)}b^{2m} = a^{2mk+m}b^{2m}$, which is not in $L$.

