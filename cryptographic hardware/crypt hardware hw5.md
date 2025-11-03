## problem 1
prove that condition $4a^{3}+27b^{2} \not =0\mod p$ for $y^{2}\equiv x^{3}+2x+2\mod 17$
in this case, $a =2, b = 2, p = 17$

then, $4a^{3}+27b^{2} = 4\times 8 + 27 \times 4=140$.
$140 \equiv 4\mod 17$, which is not 0. so, the condition for smooth curves is satisfied.

## problem 2
curve: $y^{2}\equiv x^{3}+2x+2\mod 17$
point addition: $(13,7)+(6, 3)$.

since $P$ and $Q$ are different, we can determine:
$$\begin{align}
s &=\frac{y_{2}-y_{1}}{x_{2}-x_{1}}\mod 17 \\
&=\frac{3 - 7}{6 - 13} \mod 17 \\
&=4 \times 7^{-1} \mod 17
\end{align}$$

the inverse of 7 in $Z_{17} = 5$, so $s=20 \mod 17=3$
then, the coordinates of the new point is:
- $x_{3}=s^{2}-x_{1}-x_{2}=9-13-6=-10\mod 17=7$
- $y_{3}=s(x_{1}-x_{3})-y_{1}=3(13-7)-7=18 - 7 = 11 \mod 17 = 11$

so, the result of the point addition $(13, 7) + (6, 3)= (7, 11)$

## problem 3
for the elliptic curve  $y^{2}\equiv x^{3}+2x+2\mod 17$, our prime number $p=17$.

Hasse's theorem states that: 
- the lower bound can be obtained by $p+1-2\sqrt{p}=18 - 2\sqrt{ 17 } \approx 9.75$ points.
- the upper bound can be obtained by $p+1-2\sqrt{p}=18 + 2\sqrt{ 17 } \approx 26.24$

so, the number of points on this elliptic curve lies in the range $(9.75, 26.24)$

## problem 4
elliptic curve: $y^{2}\equiv x^{3}+4x+20 \mod 29$.
- $a=4$
- $b=20$
- $p=29$
base point $P=(8, 10)$
multiplying the point $P \times 9$. this means that we are essentially doubling $P$ three times, then add it to itself one time. $9P=2\times (2 \times (2 P))+ P$

### step 1: doubling P
$$\begin{align}
s&=\frac{3x^{2}+a}{2y}=\frac{3\times 8^{2}+4}{20} \\
&=\frac{49}{5} \mod 29\\
&=20\times 5^{-1}\mod 29
\end{align}$$
in $Z_{29}$, the inverse of 5 is 6 ($5\times 6\mod 29=30\mod 29=1$). so, $s=120\mod 29=4$

then, for point $2P$:
- $x=s^{2}-x_{1}-x_{2}=16-8-8=0$
- $y=s(x_{1}-x_{3})-y_{1}=4\times(8- 0)-10=22$

### step 2: doubling $(0, 22)$
$$\begin{align}
s&=\frac{3x^{2}+a}{2y}=\frac{3\times 0^{2}+4}{2 \times 22} \\
&=\frac{4}{44} \mod 29\\
&=\frac{1}{11}\mod 29 \\
&=1\times 11^{-1}\mod 29
\end{align}$$

in $Z_{29}$, the inverse of 11 is 8 ($11\times 8\mod 29=88\mod 29=1$). so, $s=8\mod 29=8$

then, for point $4P$:
- $x=s^{2}-x_{1}-x_{2}=64-0-0=64 \mod 29 = 6$
- $y=s(x_{1}-x_{3})-y_{1}=8\times(0- 6)-22=17$

### step 3: doubling $(6, 17)$
$$\begin{align}
s&=\frac{3x^{2}+a}{2y}=\frac{3\times 6^{2}+4}{2 \times 17} \\
&=\frac{56}{17} \mod 29\\
&=56\times 17^{-1}\mod 29 \\
&=27\times 17^{-1}\mod 29
\end{align}$$
in $Z_{29}$, the inverse of 17 is 12 ($17\times 12\mod 29=204\mod 29=1$). so, $s=27 \times 12\mod 29=5$

then, for point $8P$:
- $x=s^{2}-x_{1}-x_{2}=25-6-6=13 \mod 29 = 13$
- $y=s(x_{1}-x_{3})-y_{1}=5\times(6- 13)-17=4$

### step 4: $(13, 6)+(8, 10)$
$$\begin{align}
s &=\frac{y_{2}-y_{1}}{x_{2}-x_{1}}\mod 29 \\
&=\frac{10-6}{8 - 13} \mod 29\\
&=4 \times (-5)^{-1} \mod 29 \\
&=4 \times 24^{-1} \mod 29
\end{align}$$

in $Z_{29}$, the inverse of 24 is 23. so, $s=4 \times 23\mod 29=5$

then, our final result is:
- $x=s^{2}-x_{1}-x_{2}=25-13-8=4 \mod 29 = 4$
- $y=s(x_{1}-x_{3})-y_{1}=5\times(13- 4)-6=39 \mod 29 =10$

so, the final result of $9P$ is $(4, 10)$.
