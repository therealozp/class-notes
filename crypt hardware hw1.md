### problem 1
the amount of ASICs we can run in parallel with the budget is: $\frac{10^{6}}{100} = 10^{4}$ different ASICs.

then, to compute the time of an average key search, we can obtain this number with relation to the Age of the Universe by:
$$\frac{2^{128}}{5\times 10^{8} \times 10^{4}\times 10^{10} } = 6.805\times 10^{15} \text{ age of the universe}$$
### problem 2
the multiplicative inverse of 5:
- in $Z_{11}: 5^{-1}\equiv 9 \mod 11$
- in $Z_{12}: 5^{-1}\equiv 5 \mod12$
- in $Z_{13}: 5^{-1}\equiv 8 \mod 13$
### problem 3
#### pt1
$3^{10} \mod 13$: we can see that $1\equiv 3^{3}\mod 13$, so decompose $3^{10}$ into $3^{3}\times 3^{3}\times 3^{3}\times 3$. then, our final result is:
$$3\equiv 3 \times 1\times 1\times 1 \mod 13$$
#### pt2
$7^{10} \mod 13$: we can see that $10\equiv 7^{2}\mod 13$, so we can decompose into: $10\times10\times10\times10\times10\mod 13$.

then, knowing that $9\equiv10^{2} \mod 13$, we can further decompose: $9\times 9 \times 10 \mod 13$

then, given that $3\equiv 9^{2} \mod 13$, we get $x\equiv 3 \times 10 \mod 13$, so $x =4$.

#### pt3
$2 \equiv 3^{3}\mod 5$. 
also, knowing that $1\equiv 3^{4} \mod 5$, we also know that $x$ can take any value in the set of $\{3, 7, 11, \cdots, 3\times 4n \}$

### problem 4
$\Phi(4) = \{ 1, 3 \}$
$\Phi(5) = \{ 1, 2, 3,4 \}$
$\Phi(9) = \{ 1, 2, 4, 5, 7, 8 \}$
$\Phi(26) = \{ 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 22, 25 \}$
### problem 5
$y_{1}=ax_{1}+b \mod m$
$y_{2}=ax_{2}+b \mod m$

$\implies(y_{2} -y_{1})=a(x_{2}-x_{1}) \mod m$
$\implies a=(y_{2} -y_{1})(x_{2}-x_{1})^{-1} \mod m$

so, to be able to derive the multiplicative inverse of $x_{2}-x_{1}$, we need to choose the plaintext such that $gcd(x_{2}-x_{1}, m) = 1$.
### problem 6
we can XOR the plaintext with the ciphertext to get a sequence of keys. then, since we are using the same key (supposing that key length is 128 bits in length), we can inspect the sequence for repeating chains of 128. that same chain of 128 is the key that we need to decrypt all other ciphertext.
### problem 7
since we know that the period of the LFSR is 200 bits, we only need to examine 200 consecutive bits of the plaintext and the ciphertext to get a **possibly shifted** version of the key. from there, we are able to apply the key over 200 different possible periods, and see if the decrypted ciphertext makes sense (or matches with the original plaintext.)

### problem 8
tapping the channel to get the plaintext and the ciphertext, we can XOR them with each other and investigate the key:

```
     1001 0010 0110 1101 1001 0010 0110
xor  1011 1100 0011 0001 0010 1011 0001
------------------------------------------
     0010 1110 0101 1100 1011 1001 0111
```

investigating the key, we can break it up into 4 identical segments of length 7:
$$0010111\ 0010111\ 0010111\ 0010111$$
so, we know that the stream cipher has a length of 7, and since it is a maximum length LFSR, we know that the degree of the LFSR is 3. 