lingo: 
- cryptology: the study (science of) secrets
- cryptanalysis: analyzing and breaking secrets
- cryptography: writing secrets
- crypto: catch-all for the first three

## symmetric-key cryptography
one of the biggest revolutions in computer science is what comes after this, which is asymmetric. 

![[Pasted image 20260429154316.png]]

common key length varies, standard is around 56-64 bits to 128 bits, and more advanced ones are even 256 bits. 
### one-time-pad
Claude Shannon showed that there is a provably secure bit length, which is as many as your plaintext requires. if plaintext is $n$ bits, then the provably secure key length is also $n$. then, the ciphertext is the XOR of the plaintext and the ciphertext, also $n$ bits.

there are generally two forms of symmetric ciphers:
1. block cipher: encodes and decodes and fixed number of symbols (bits) at a time. includes 2 popular "modes":
	- ECB (electronic code book), involving a lot of bit level manipulation, rotations, swaps, swaps, and does multiple rounds for each block of plaintext. much faster, but much less secure. also vulnerable to replay attacks, where the attacker just sits and re-sends the same ciphertext, because the algorithm is deterministic.
	- CBC (cipher block chaining): use the previous ciphertext to encrypt the next plaintext. much slower, but much more secure. 

 ![[Pasted image 20260429160409.png|400]]
 
2. stream cipher: encrypt/decrypt one symbol at a time.
## asymmetric cryptography
typically much slower than symmetric, involving a lot of math. typically, we use a hybrid approach by using asymmetric to share keys, and using the symmetric to encrypt-decrypt with said shared key (see HTTPS and TLS).
### Diffie-Hellman key exchange
public-private-key cryptography. also called Diffie-Hellman-Merkle, discovered in 1977. 

Alice creates a secret $a$ (with a CSPRNG), a prime number $p$, and the generator $g$. a generator is a number such that its powers will give every single number $\mod p$. based on the discrete logarithm problem (DLP), seems to require exponential time. the discrete log problem is based on finding a number $a$, given $g$, $p$, and $g^{a}\mod p$.

![[Pasted image 20260429161616.png]]

a passive attacker wouldn't be able to break this (given that the DLP problem is harder to solve), but an active attacker (malary) can do a man-in-the-middle attack to break DHKE. what the MITM attack does is sit in the middle, and to Bob, pretend to be Alice (and forward Alice's key); and to Alice, pretend to be Bob.

### RSA
found in 1977 by Rivest, Shamir, Adleman

1. Alice and Bob computes public and private keys
	1. let $m = pq$, where $p$ and $q$ are primes are very large (upwards of 3042 bits)
	2. let $n$ be the Least Common Multiple (LCM) of $(p -1, q  -1)$
	3. let $e\in \mathbb{N}$ such that $e$ and $n$ are relatively prime (have a GCD of 1)
	4. let $d\in \mathbb{N}$ such that $d\times e\equiv 1\mod n$.
	$\to$ public key is $(m, e)$, private key is $d$. $p, q, n$ should all be kept secret
2. to encrypt
	1. Bob sends his public key to Alice.
	2. Alice encrypts plaintext $p$ as ciphertext $C\equiv p^{e_{B}}\mod m_{B}$
3. to decrypt, Bob computes $p \equiv C^{d_{B}}\mod m_{B}$
#### digital signatures
supports 3 things:
- message integrity
- authenticity, because no one else should have Alice's private key
- non-repudiation: Alice cannot plausibly deny that she signed the message

![[Pasted image 20260429163806.png]]

however, these are still vulnerable to a replay attack. to solve this, we have timestamps, expiry etc. so that replay is impossible.

## cryptographic hash functions
also called one-way or trapdoor functions, easy to compute, but hard to inverse. see the SHA family of algorithms. has 5 big properties:
- easy to compute hashes,
- should be computationally difficult to perform the converse operation,
- deterministic,
- difficult to find 2 messages with the same hash (collision attacks),
- difficult to modify a message without also modifying its hash (or also called *digest*).

MACs provide integrity and authenticity the same way RSA does, but they don't provide non-repudiation. a typical MAC can go:
- pass message and shared key into SHA to produce a MAC
- MAC is sent to Bob
- Bob repeats the same process and passes that through the SHA
- check if they are the same, if they are, then the message is authentic

