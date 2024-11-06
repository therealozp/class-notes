per the IEEE-754 standard, a floating number will always have 3 parts (in order): the **sign bit**, the **exponent** bits, and the **fraction**.
- single precision is **32 bits**, overflow/underflow if $>10^{38}, <-10^{38}, 10^{-38} < x < 10^{38}$
- double precision is **64 bits** $>10^{308}, <-10^{308}, 10^{-308} < x < 10^{308}$
### why use fp?
- represent values between ints
- scaling factor means much greater range of values
- **however**, much slower than int operations, and lose precision in the process.
### precision vs. accuracy
- **precision** is the number of bits used to represent it.
- **accuracy** is the measure of difference between actual value and its computer rep.

*high precision **allows** for high accuracy, but **does not guarantee it.***
## representation
for different number sizes (in bits), the amount of bits reserved for the exponent will differ.
- 8 bits: 1 - 3 - 4
- 16 bits: 1 - 5 - 10
- 32 bits: 1 - 8 - 23
- 64 bits: 1 - 11 - 52
## hardware
much more complex than integer adder. because doing it in one clock cycle would take too long and would penalize all instructions, the CPU will choose to make it **several cycles**, which can then be pipelined.
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

table method needs 4 rows: exponent, place values (decimal representation), bits, value
### sign & final value
take the sign bit, find the sign, and add it to the number. also noteworthy is the sign bit will **never be used in any calculation**, except for this step.

## decimal to floating point
the reverse operation also has somewhat of a similar pattern:
### convert to binary
split the number and the fraction as you would. normally, and convert them into binary representation. do not worry about the sign for the time being.
### establish exponent
write the number as $x \times {2}^0$.
### normalize
find the first 1, and shift it until we have the form $1.\text{something} \times 2^x$ where $x$ is the number of bits
### find mantissa
the mantissa is however many bits after the decimal point you would require
### find exponent bits
find the final exponent by adding it to the bias.
### establish sign bit

