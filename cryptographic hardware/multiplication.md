## Karatsuba multiplication
karatsuba multiplication aims to replace multiplication with more addition operations, under the assumption that multiplication is much costlier than addition.

for example, doing KOM over $GF(2^{128})$ means we can split the 128 bit multiplication into **three** KOM over $GF(2^{64})$

KOM is sub-quadratic in terms of space complexity, but it will increase the delay of the final operation. 
- if objective is delay: stop immediately after one reduction step.
- if objective is efficiency/power consumption: stop in the middle. 

## inversions (Fermat's little theorem)
### multiplicative inverse
given that $A \not=0 \in GF(2^{m})$: 
- we see that $A^{2m-1}=1,\forall A\not = 0\in GF(2^{m})$
- so, by multiplying $A$'s multiplicative inverse to both sides:
	- $A^{-1}=A^{2m-2}$
