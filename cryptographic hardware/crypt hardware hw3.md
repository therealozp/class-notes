## problem 1
a. the inverse of the entry F3, according to the table, is 34.
b.
the equation representing `F3 = 1111 0011`: $x^{7}+x^{6}+x^{5}+x^{4}+x+1$
the equation representing `34 = 0011 0100`: $x^{5}+x^{4}+x^{2}$

then, to prove that they are multiplicative inverse, we take the multiplication `F3 . 34` over the irreducible polynomial $x^{8}+x^{4}+x^{3}+x+1$:

- reducing $x^{8}\equiv x^{4}+x^{3}+x+1$
- reducing $x^{12}\equiv x^{8}+x^{7}+x^{5}+x^{4}\equiv x^{7}+x^{5}+x^{3}+x+1$
- reducing $x^{9}\equiv x^{5}+x^{4}+x^{2}+x$
$$
\begin{align}
&(x^{7}+x^{6}+x^{5}+x^{4}+x+1)(x^{5}+x^{4}+x^{2}) \\
&= x^{12}+x^{11}+x^{10}+x^{9}+x^{6}+x^{5} +x^{11}+x^{10}+ x^{9}\\
& \ \ \ +x^{8}+x^{5}+x^{4} +x^{9}+x^{8}+x^{7}+x^{6}+x^{3}+x^{2} \\
&= x^{12}+x^{9}+x^{7}+x^{4}+x^{3}+x^{2}\\
&=(x^{7}+x^{5}+x^{3}+x+1) + (x^{5}+x^{4}+x^{2}+1)x^{7}+x^{4}+x^{3}+x^{2} \\
&\equiv 1
\end{align}
$$
## problem 2
the number of seconds taken to crack the 192-bit key:
$$\frac{2^{192}}{3\times 10^{7}\times10^{5}}=1.58\times 10^{45} \text{ seconds} = 5 \times 10^{37} \text{ years}$$
## problem 3
hash subkey $H(x)=x^{27}+x^{25}+x^{20}+x^{4}+x+1$
irreducible polynomial $P(x)=x^{128}+x^{7}+x^{2}+x+1$
input hash $M_{1}=x^{89}+x^{23}+x^{10}$
input hash $M_{2}=x^{93}+x^{24}+x^{10}+x$
$$
\begin{align}
M_{1}H + M_{2}&=(x^{89}+x^{23}+x^{10})(x^{27}+x^{25}+x^{20}+x^{4}+x+1) \\
&= x^{116}+x^{114}+x^{109}+x^{93}+x^{90}+x^{89} \\
&\ \ \ \  +x^{50}+x^{48}+x^{43}+x^{37}+x^{35}+x^{30} \\
&\ \ \ \   +x^{27}+x^{24}+x^{23}+x^{14}+x^{11}+x^{10} \\
&\ \ \ \ +(M_{2}=x^{93}+x^{24}+x^{10}+x) \\
&= x^{116}+x^{114}+x^{109}+x^{90}+x^{89} \\
&\ \ \ \   +x^{50}+x^{48}+x^{43}+x^{37}+x^{35}+x^{30} \\
&\ \ \ \   +x^{27}+x^{23}+x^{14}+x^{11} + x \\
\end{align}
$$
then:
$$
\begin{align}
\beta(x)&=(M_{1}H+M_{2})\times H \\
&= (x^{27}+x^{25}+x^{20}+x^{4}+x+1) \times (x^{116}+x^{114}+x^{109}+x^{90}+x^{89} \\
&\ \ \ \   +x^{50}+x^{48}+x^{43}+x^{37}+x^{35}+x^{30} \\
&\ \ \ \   +x^{27}+x^{23}+x^{14}+x^{11} + x) \\
&=x^{129}+x^{139}+x^{143}+x^{120}+x^{118}+x^{113}+x^{94}+x^{93}+x^{91}+x^{89} \\
&\quad+x^{77}+x^{73}+x^{64}+x^{63}+x^{60}+x^{51}+x^{50}+x^{49}+x^{44}+x^{37}+x^{35} \\
&\quad+x^{31}+x^{30}+x^{26}+x^{24}+x^{23}+x^{21}+x^{14}+x^{12}+x^{11}+x^{5}+x^{2}+x
\end{align}
$$

reducing $x^{129}\equiv x^{8}+x^{3}+x^{2}+x$
reducing $x^{139} \equiv x^{18}+x^{13}+x^{12}+x^{11}$
reducing $x^{143} \equiv x^{22}+x^{17}+x^{16}+x^{15}$

final answer:
$$
\begin{align}
\beta(x)&=
x^{120}+x^{118}+x^{113}+x^{94}+x^{93}+x^{91}+x^{89}+x^{77}+x^{73}+x^{64} \\
&\quad+x^{63}+x^{60}+x^{51}+x^{50}+x^{49}+x^{44}+x^{37}+x^{35}+x^{31} \\
&\quad+x^{30}+x^{26}+x^{24}+x^{23}+x^{22}+x^{21}+x^{17}+x^{16} \\
&\quad+x^{15}+x^{14}+x^{13}+x^{8}+x^{5}+x^{3}
\end{align}
$$