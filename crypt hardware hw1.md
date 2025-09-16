6. we can XOR the plaintext with the ciphertext to get a sequence of keys. then, since we are using the same key (supposing that key length is 128 bits in length), we can inspect the sequence for repeating chains of 128. that same chain of 128 is the key that we need to decrypt all other ciphertext.

7. since we know that the period of the LFSR is 200 bits, we only need to examine 200 consecutive bits of the plaintext and the ciphertext

8. tapping the channel to get the plaintext and the ciphertext, we can XOR them with each other and investigate the key:

```
     1001 0010 0110 1101 1001 0010 0110
xor  1011 1100 0011 0001 0010 1011 0001
------------------------------------------
     0010 1110 0101 1100 1011 1001 0111
```

investigating the key, we can break it up into 4 identical segments of length 7:
$$0010111\ 0010111\ 0010111\ 0010111$$
so, we know that the stream cipher has a length of 7, and since it is a maximum length LFSR, we know that the degree of the LFSR is 3. 