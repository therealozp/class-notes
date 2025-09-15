6. suppose that the original plaintexts are $x_{1}$ and $x_{2}$, and ciphertexts being $y_{1}$ and $y_{2}$ respectively. also suppose that the key is $k$. then, using XOR to create ciphertexts, we get:
$$x_{1} \oplus k = y_{1}$$$$x_{1} \oplus k = y_{2}$$
if the same key $k$ is being used across the encryption of multiple plaintexts, then we can take the XOR between two ciphertexts, and cancel out the key $k$:
$$
y_{1} \oplus y_{2} = (x_{1} \oplus k) \oplus (x_{2} \oplus k) = x_{1} \oplus x_{2}
$$
now that we have the XOR between two plaintexts, we can test one plaintext and test whether it will produce meaningful output in the other plaintext. 

moreover, this can also be validated by using the techniques to break substitution ciphers, by statistical analysis of the original plaintext for common words and letters.


