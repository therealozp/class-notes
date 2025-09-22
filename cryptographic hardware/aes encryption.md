## symmetric key cryptography
both sides (Alice and Bob) have the same key, and only ciphertext is transmitted throughout the insecure channel.
- stream ciphers
- block ciphers

two primitive operations to build strong encryption algorithms:
- **confusion**: relationship between key and ciphertext is obscured
- **diffusion**: one change in plaintext will change many bits in the resulting ciphertext (influence of one plaintext symbol spread over many ciphertext symbols)

the actual data path of the input/output is fixed at 128 bits, but the key could be low security or high security (128, 192, 256).