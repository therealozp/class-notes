per the IEEE-754 standard, a floating number will always have 3 parts (in order): the **sign bit**, the **exponent** bits, and the **fraction**.

for different number sizes (in bits), the amount of bits reserved will differ.
- 8 bits: 1 - 3 - 4
- 16 bits: 1 - 5 - 10
- 32 bits: 1 - 8 - 23

## floating point to decimal
to convert a floating point number to a binary, the following general steps should be followed:
### separating binary
follow the above convention to split the number. from this, we are able to get the sign bit, exponent, and fraction.
### finding mantissa
mantissa is found by adding `1.` to the fraction part. so, **irrespective of the sign bit**, if the fraction is `0110`, the mantissa is `1.0110`.
### find exponent
there are two steps to finding this value. first, we get the value from the exponent bits, the subtract it from the bias. 

the bias is calculated by the formula $2^{k - 1} - 1$, where $k$ is the number of bits in the exponent.

for example, if the exponent is `110`, then bias is $2^{(3 - 1)}-1=3$, and the exponent is `6 - 3 = 3.` if the exponent is `01000`, then bias is still $2^{(5 - 1)}-1=15$, and exponent is `8 - 15 = -7`.
### de-normalize
bit shift. more formally, it is multiplying the **mantissa** by $2^\text{exponent}$. if the exponent is:
- **positive**: shift left `exponent` bits.
- negative: shift right `|exponent|` bits.
### conversion (with the table method)
basically calculate the value normally, how you convert a binary number to a decimal number (binary conversion).
### sign & final value
take the sign bit, find the sign, and add it to the number. also noteworthy is the sign bit will **never be used in any calculation**, except for this step.

## decimal to floating point
the reverse operation also has somewhat of a similar pattern:
### convert to binary
### establish exponent
### normalize
### find mantissa
### find exponent bits
### establish sign bit

