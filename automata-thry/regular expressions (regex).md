## formal definition
let $\Sigma$ be an alphabet set. 
1. $\Phi, \lambda, 0$, and $\Sigma$ are regular expressions called primitive RE
2. if $r_1$ and $r_2$ are regexps $\rightarrow r_{1}+r_{2},\ r_{1}r_{2}, \ r_{1}^{*}$ on a $r$ are regexps
3. a string is an RE if it is derived from a primitive RE by a finite number of application of rules in (2). 

$L(r)$ is a language generated from regexp $r$. so, $a$ is an RE, $(a+b)^{*}$ is an RE, $a^{*}.(bb)^{*}$ is also an RE. in regexps, the $+$ notation represents any combination of the **set** of characters, and the $.$ represents the concatenation.

> if a language has an RE, **the language is regular.**

$L(r) \rightarrow M(r)$ 

![[regular expressions (regex) 2024-02-16 12.45.18.excalidraw|1000]]

$L(r_{1}+ r_{2}) = L(r_{1}) + L(r_{2})$

![[regular expressions (regex) 2024-02-16 12.48.42.excalidraw|1000]]

$L(r_{1}\cdot r_{2})$

![[regular expressions (regex) 2024-02-16 12.53.13.excalidraw|1000]]

$L(r_{1}^*) = (L(r_1))^*$

![[regular expressions (regex) 2024-02-16 12.58.24.excalidraw|1000]]