## number representations
for n bits, we can represent:
- 0 to $2^{n}- 1$ unsigned integers
- $-2^{n-1}$ to $2^{n-1}-1$ signed integers under 2's complement

when computing numbers, there will be some cases where the operation will overflow.
the overflow is kept as **a single bit** in the system status to indicate when an operation will result in an overflow.

| operand 1 | operand 2 | operation | result         | overflows?                           |
| --------- | --------- | --------- | -------------- | ------------------------------------ |
| +         | -         | +         | doesn't matter | never                                |
| +         | +         | +         | -              | yes                                  |
| -         | -         | +         | +              | yes                                  |
| +         | +         | -         | doesn't matter | never                                |
| -         | -         | -         | doesn't matter | never                                |
| -         | +         | -         | +              | yes (negative - positive = positive) |
| +         | -         | -         | -              | yes (positive - negative = negative) |
|           |           |           |                |                                      |
## multiplication
because of the number of bits stored in the register (32), a multiplication will result in a maximum of 32 + 32 = 64 bits. so, by default, the hardware will process 64 times, and will return the answer on the 65th no matter what.

the naive implementation for the multiplier can be expressed as:
- the initial numbers are the **multiplicand** and the **multiplier**
- loop: check the **multiplier's LSB** = 0
	- if = 1: add multiplicand to **result**, put it in the product register
	- if = 0: skip this step
	- end of the loop: 
		- multiplicand <<= 1 
		- multiplier >>= 1

instead, a more optimized approach can be attained as we shift the result continuously. this way, instead of using a 128-bit ALU, we will only need to use 64.
- keep a running **partial product**
- check LSB of multiplier:
	- if = 1: add the multiplicand to partial
	- if = 0: skip
	- end of loop:
		- partial product <<= 1
		- multiplier >>= 1

an even **faster multiplier** can be attained when we run multiple adders in parallel. this process allows for **pipelining**, which makes processes much faster.
### in assembly
- `mul`: multiply, gives the lower 64 bits of product
- `mulh`: multiply high, gives upper 64 bits of product of **2 signed numbers**. can also be used to *check for 64 bit overflow.*
- `mulhu`: multiply high, gives upper 64 bits of product of **2 unsigned numbers**
- `mulhsu`: multiply high, gives upper 64 bits of product of **a signed and unsigned number**
## division
the process is very similar to long division. in an operation 6 / 2 = 3, 6 is the dividend, 2 is the divisor, 3 is the quotient.
- first, check for 0 divisor
- num bits in dividend >= divisor?:
	- push 1 bit at the end of quotient, subtract to get remainder
	- 0 bit in quotient, bring down the next dividend bit
- do subtraction, if remainder ever goes < 0, add back the divisor

for **signed division**, do everything normally and worry about the sign bit later.

in hardware, it will look different. the process will look like the following:
- the divisor is originally in the upper left half
- the remainder is originally the dividend
- loop:
	- remainder -= divisor
	- if remainder >= 0:
		- quotient <<= 1
		- rightmost bit of quotient = 1
	- if remainder < 0:
		- quotient <<= 1
		- rightmost bit of quotient = 0
		- remainder += divisor
	- divisor >>= 1
	- 65th rep? break

an **optimized divisor** also uses the "partial" remainder trick similar to the multiplier operation. that's why the multiplier and divider hardware looks very similar.
### in assembly
- `div, rem`: signed divide, remainder
- `divu, remu`: unsigned divide, remainder

**overflow and div 0 do not produce errors.** instead, they return defined result, because it is much faster for the common case of no error.