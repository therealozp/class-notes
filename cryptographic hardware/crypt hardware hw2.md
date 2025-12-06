## problem 1
## problem 1
$A(x) = x^{2}+ 1$, and $B(x)=x^{3}+x^{2}+1$
$$\begin{align}
\implies A(x) + B(x)  &= x^{2}+1+x^{3}+x^{2}+1 \\
& =x^3
\end{align}$$

$A(x) = x^{2}+ 1$, and $B(x)=x+1$
$$\begin{align}
\implies A(x) + B(x)  &= x^2+1+x+1 \\
& =x^2+x
\end{align}$$

## problem 2
Irreducible polynomial $P(x) = x^{4}+x+1$
#### $A(x) = x^{2}+ 1$, $B(x)=x^{3}+x^{2}+1$
$$\begin{align}
\implies A(x) \times B(x)  &= (x^{2}+1)(x^{3}+x^{2}+1) \\
& =x^5+x^{4}+x^{2}+x^3+x^{2}+1 \\
&=x^{5}+x^{4}+x^{3}+1 \\
\end{align}$$
Reducing $x^{5}\equiv x^{2}+x \mod P(x)$ and $x^{4}\equiv x + 1 \mod P(x)$:
$$
\begin{align}
\implies A(x) \times B(x)  &= x^{2}+x+x+1+x^{3}+1 \\
&=x^{3}+x^{2}
\end{align}
$$
#### $A(x) = x^{2}+ 1$, $B(x)=x+1$
$$\begin{align}
\implies A(x) \times B(x)  &= (x^2+1)(x+1) \\
& =x^{3}+x+x+1 \\
&=x^{3}+ 1
\end{align}$$
### problem 3
$$\begin{align}
&b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}x + b_{0}\\
&P(x) = x^{8}+x^{4}+x^{3}+x+1
\end{align}$$
### by 01
$$\begin{align}
1\times(b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}x + b_{0})
\end{align}$$
So: 
$$\begin{align}
d_{7} &= b_{7} \\
d_{6} &= b_{6} \\
d_{5} &= b_{5} \\
d_{4} &= b_{4} \\
d_{3} &= b_{3} \\
d_{2} &= b_{2} \\
d_{1} &= b_{1} \\
d_{0} &= b_{0} \\
\end{align}$$

Since there are no additions in the coefficients, 0 additional XOR gates are required.
### by 02
$$\begin{align}
&=x \times(b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}x+b_{0}) \\
&= b_{7}x^{8} + b_{6}x^{7} + b_{5}x^{6} + b_{4}x^{5} + b_{3}x^{4} + b_{2}x^{3} + b_{1}x^{2}+b_{0}x
\end{align}$$
Reducing $x^{8}\equiv x^{4}+x^{3}+x+1 \mod P(x)$ 
$$\begin{align}
&= b_{7}(x^{4}+x^{3}+x+1) + b_{6}x^{7} + b_{5}x^{6} + b_{4}x^{5} + b_{3}x^{4} + b_{2}x^{3} + b_{1}x^{2}+b_{0}x
\end{align}$$
So:
$$\begin{align}
d_{7} &= b_{6} \\
d_{6} &= b_{5} \\
d_{5} &= b_{4} \\
d_{4} &= b_{3} \oplus b_{7} \\
d_{3} &= b_{2} \oplus b_{7} \\
d_{2} &= b_{1} \\
d_{1} &= b_{0} \oplus b_{7} \\
d_{0} &= b_{7} \\
\end{align}$$
3 additional XOR gates are required.
### by 03
$$\begin{align}
&=(x+ 1) \times(b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}x+b_{0}) \\
&= b_{6}x^{7} + b_{5}x^{6} + b_{4}x^{5} + (b_{3} + b_{7})x^{4} + (b_{2}+b_{7})x^{3} + b_{1}x^{2}+(b_{7} +b_{0})x + b_{7} + \\
&\ \ \ \ \ b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} +  b_{1}x + b_{0} \\
\end{align}$$
So:
$$\begin{align}
d_{7} &= b_{6} \oplus b_{7} \\
d_{6} &= b_{5} \oplus b_{6} \\
d_{5} &= b_{4} \oplus b_{5} \\
d_{4} &= b_{3} \oplus b_{4}\oplus b_{7}  \\
d_{3} &= b_{2} \oplus b_{3} \oplus b_{7} \\
d_{2} &= b_{1}\oplus b_{2} \\
d_{1} &= b_{0} \oplus b_{1} \oplus b_{7} \\
d_{0} &= b_{7}\oplus b_{0} \\
\end{align}$$

11 additional XOR gates are required.

## problem 4
$$\begin{align}
B(x)&=b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}x + b_{0}\\
P(x) &= x^{8}+x^{4}+x^{3}+x+1
\end{align}$$
### by 09
`09 = 0000 1001`, which indicates $x^{3}+1$
$$\begin{align}
& =(x^{3} + 1)\times(b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}) \\
& = b_{7}x^{10} + b_{6}x^{9} + b_{5}x^{8} + b_{4}x^{7} + b_{3}x^{6} + b_{2}x^{5} + b_{1}x^4 + b_{0}x^{3}+ B(x)
\end{align}$$
Reducing:
- $x^{10}\equiv x^{6}+x^{5}+x^{3}+x^{2} \mod P(x)$
- $x^{9}\equiv x^{5}+x^{4}+x^{2}+x \mod P(x)$
- $x^{8}\equiv x^{4}+x^{3}+x+1 \mod P(x)$
$$\begin{align}
& = b_{7}(x^{6}+x^{5}+x^{3}+x^{2}) + b_{6}(x^{5}+x^{4}+x^{2}+x) + b_{5}(x^{4}+x^{3}+x+1) + b_{4}x^{7} + b_{3}x^{6} + \\
& \ \ \ \ \ b_{2}x^{5} + b_{1}x^{4} + b_{0}x^{3}+ b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1} \\
\end{align}$$
$$\begin{align}
d_{7} &= b_{4} \oplus b_{7} \\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{6} \\
d_{5} &= b_{2} \oplus b_{7} \oplus b_{6} \oplus b_{5}\\
d_{4} &= b_{1} \oplus b_{6} \oplus b_{5} \oplus b_{4}\\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{3} \oplus b_{7}\\
d_{2} &= b_{7} \oplus b_{2} \oplus b_{6} \\
d_{1} &= b_{6} \oplus b_{1} \oplus b_{5} \\
d_{0} &= b_{5} \oplus b_{0} \\
\end{align}$$
### by 0B
`0B = 0000 1011`, which means $x^{3}+x+1$, and coincidentally $0B=09\oplus 02$. in this case, we have computed the products:
- $09\times B(x)$
- $02\times B(x)$
so, we can get the product of multiplying $0B\times B(x)$ by XOR-ing 2 products together. in this case: 

for multiplication with $02$:
$$\begin{align}
d_{7} &= b_{6} \\
d_{6} &= b_{5} \\
d_{5} &= b_{4} \\
d_{4} &= b_{3} \oplus b_{7} \\
d_{3} &= b_{2} \oplus b_{7} \\
d_{2} &= b_{1} \\
d_{1} &= b_{0} \oplus b_{7} \\
d_{0} &= b_{7} \\
\end{align}$$

for multiplication with $09$:
$$\begin{align}
d_{7} &= b_{4} \oplus b_{7} \\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{6} \\
d_{5} &= b_{2} \oplus b_{7} \oplus b_{6} \oplus b_{5}\\
d_{4} &= b_{1} \oplus b_{6} \oplus b_{5} \oplus b_{4}\\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{3} \oplus b_{7}\\
d_{2} &= b_{7} \oplus b_{2} \oplus b_{6} \\
d_{1} &= b_{6} \oplus b_{1} \oplus b_{5} \\
d_{0} &= b_{5} \oplus b_{0} \\
\end{align}$$

so, the final result is:
$$\begin{align}
d_{7} &= b_{4} \oplus b_{7} \oplus b_{6} \\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{6} \oplus b_{5} \\
d_{5} &= b_{2} \oplus b_{7} \oplus b_{6} \oplus b_{5} \oplus b_{4}\\
d_{4} &= b_{1} \oplus b_{6} \oplus b_{5} \oplus b_{4} \oplus b_{3} \oplus b_{7}\\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{3} \oplus b_{2} \\
d_{2} &= b_{7} \oplus b_{2} \oplus b_{6} \oplus b_{1}\\
d_{1} &= b_{6} \oplus b_{1} \oplus b_{5} \oplus b_{0} \oplus b_{7}\\
d_{0} &= b_{5} \oplus b_{0} \oplus b_{7}\\
\end{align}$$
### by 0D
`0D = 0000 1101`, which indicates $x^{3}+x^{2}+1$. This is equivalent to XOR-ing the product of $09$ and $04 = 0000\ 0100$. so, computing and reducing the product with $04$:
$$\begin{align}
& =x^{2}\times(b_{7}x^{7} + b_{6}x^{6} + b_{5}x^{5} + b_{4}x^{4} + b_{3}x^{3} + b_{2}x^{2} + b_{1}) \\
& = b_{7}x^{9} + b_{6}x^{8} + b_{5}x^{7} + b_{4}x^{6} + b_{3}x^{5} + b_{2}x^{4} + b_{1}x^{3} + b_{0}x^{2} \\
& = b_{7}(x^{5}+x^{4}+x^{2}+x) + b_{6}(x^{4}+x^{3}+x+1) + b_{5}x^{7} + b_{4}x^{6} + b_{3}x^{5} + b_{2}x^{4} + b_{1}x^{3} + b_{0}x^{2} \\
\end{align}$$
so, for multiplication with $04$:
$$\begin{align}
d_{7} &= b_{5} \\
d_{6} &= b_{4} \\
d_{5} &= b_{3} \oplus b_{7} \\
d_{4} &= b_{2} \oplus b_{7} \oplus b_{6}\\
d_{3} &= b_{1} \oplus b_{6} \\
d_{2} &= b_{0} \oplus b_{7} \\
d_{1} &= b_{7} \oplus b_{6} \\
d_{0} &= b_{6} \\
\end{align}$$

for multiplication with $09$:
$$\begin{align}
d_{7} &= b_{4} \oplus b_{7} \\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{6} \\
d_{5} &= b_{2} \oplus b_{7} \oplus b_{6} \oplus b_{5}\\
d_{4} &= b_{1} \oplus b_{6} \oplus b_{5} \oplus b_{4}\\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{3} \oplus b_{7}\\
d_{2} &= b_{7} \oplus b_{2} \oplus b_{6} \\
d_{1} &= b_{6} \oplus b_{1} \oplus b_{5} \\
d_{0} &= b_{5} \oplus b_{0} \\
\end{align}$$
so, the final result is:
$$\begin{align}
d_{7} &= b_{4} \oplus b_{7} \oplus b_{5}\\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{6} \oplus b_{4} \\
d_{5} &= b_{2} \oplus b_{6} \oplus b_{5} \oplus b_{3} \\
d_{4} &= b_{1} \oplus b_{5} \oplus b_{4} \oplus b_{2} \oplus b_{7}  \\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{3} \oplus b_{1} \oplus b_{6} \oplus b_{7} \\
d_{2} &= b_{0} \oplus b_{2} \oplus b_{6}\\
d_{1} &= b_{1} \oplus b_{5} \oplus b_{7}\\
d_{0} &= b_{5} \oplus b_{0} \oplus b_{6}\\
\end{align}$$
### by 0E
`0E = 0000 1110`, which indicates $x^{3}+x^{2}+x$. however, $0E=0D\oplus 03$, so we can get the result by XOR-ing the products from $0D$ and $03$.

product with $03$:
$$\begin{align}
d_{7} &= b_{6} \oplus b_{7} \\
d_{6} &= b_{5} \oplus b_{6} \\
d_{5} &= b_{4} \oplus b_{5} \\
d_{4} &= b_{3} \oplus b_{4}\oplus b_{7}  \\
d_{3} &= b_{2} \oplus b_{3} \oplus b_{7} \\
d_{2} &= b_{1}\oplus b_{2} \\
d_{1} &= b_{0} \oplus b_{1} \oplus b_{7} \\
d_{0} &= b_{7}\oplus b_{0} \\
\end{align}$$

product with $0D$:
$$\begin{align}
d_{7} &= b_{4} \oplus b_{7} \oplus b_{5}\\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{6} \oplus b_{4} \\
d_{5} &= b_{2} \oplus b_{6} \oplus b_{5} \oplus b_{3} \\
d_{4} &= b_{1} \oplus b_{5} \oplus b_{4} \oplus b_{2} \oplus b_{7}  \\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{3} \oplus b_{1} \oplus b_{6} \oplus b_{7} \\
d_{2} &= b_{0} \oplus b_{2} \oplus b_{6}\\
d_{1} &= b_{1} \oplus b_{5} \oplus b_{7}\\
d_{0} &= b_{5} \oplus b_{0} \oplus b_{6}\\
\end{align}$$
final result:
$$\begin{align}
d_{7} &= b_{4} \oplus b_{5} \oplus b_{6}\\
d_{6} &= b_{3} \oplus b_{7} \oplus b_{5} \oplus b_{4} \\
d_{5} &= b_{2} \oplus b_{6} \oplus b_{4} \oplus b_{3} \\
d_{4} &= b_{1} \oplus b_{5} \oplus b_{3} \oplus b_{7}  \\
d_{3} &= b_{0} \oplus b_{5} \oplus b_{1} \oplus b_{6} \oplus b_{3} \\
d_{2} &= b_{0} \oplus b_{1} \oplus b_{6}\\
d_{1} &= b_{0} \oplus b_{5} \\
d_{0} &= b_{5} \oplus b_{6} \oplus b_{7}\\
\end{align}$$
## problem 5
for the LSB-first multiplication, we will iterate through each bit of the second member $B$, and for each multiplication, shift $A$ to the left by 1, all the while $\mod P(x)$.
$A^{i+1}=x\times A^{i}\mod P(x)$
$A^{i+1}=x\times(a_{3}x^{3}+a_{2}x^{2}+a_{1}x^{1}+a_{0})$
$A^{i+1}=a_{3}x^{4}+a_{2}x^{3}+a_{1}x^{2}+a_{0}x$

Reducing $x^{4}\equiv x+1\mod P(x)$, we get the final coefficients for $A^{i+1}$
$a_{3}'=a_{2}$
$a_{2}'=a_{1}$
$a_{1}'=a_{0}\oplus a_{3}$
$a_{0}'=a_{3}$

so, we only need 1 additional XOR gate in the $x$ module to complete the LSB multiplier. In total, we need $5$ XOR gates and $4$ AND gate.