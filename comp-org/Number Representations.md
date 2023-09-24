## Signed Numbers
For a normal unsigned number with $n$ bits, the range of **unsigned number** represented is $[0, 2^n-1]$ e.g. with 4 bits,  you can represent from 0 to 15. 

## Sign - Magnitude
Data range: $[-(2^{n - 1} - 1), 2^{n - 1} -1]$.

Procedure: takes the leftmost bit to represent sign, where **0 is positive**, and **1 is negative.** The value of the other bits remain the same. 

### Arithmetic
The sign of your answer should come from the larger number. If signs are **different**, **subtract** with **bigger number on top**. If signs are the **same**, do **addition**. *If the sign changes when adding 2 same-signed values, then it is an **overflow.*** 

Take 5 - 7 as an example, we could say this is equivalent to 5 + (-7). From that point, we keep subtracting, and we end up with 1111 - 0101 = 1010 (which is -2)
## 1's Complement
Data range: $[-(2^{n - 1} - 1), 2^{n - 1} -1]$. Only has addition, no subtraction. 

Procedure: 
1. Take number in binary
2. Bit flip every bit

### Arithmetic

```C
if (carry_out == carry_in) {
	overflow = false
} else {
	overflow = true
}
```

After finishing the operation, the **carry out must be re-added into the final sum.** This is called end-round carry, and is only applicable to 1's complement. 
## 2's Complement
Data range: $[-2^{n - 1}, 2^{n - 1} -1]$. Only has addition, no subtraction.

Procedure: 
1. Take number in binary
2. Bit flip every bit
3. Add 1 to the result
### Arithmetic

```C
if (carry_out == carry_in) {
	overflow = false
} else {
	overflow = true
}
```

After finishing the operation, convert it to positive however you like. Either do subtract one first and bit flip, or bit flip and add one. 
## Negatives in Hex and Oct
The MSB defines the sign, so the procedure will involve switching it back to binary to determine the sign. For example, the number 3ED in binary is 0011 1110 1101, which is a positive number. However, AED in binary is 1010 1110 1101, which is a negative number. 

The procedure for taking the decimal value is similar. E.g. $(A1)_{16}$ is $(1010 \space 0001)_{2}$, which is -95 (for 2's complement).

## Operation
Carry-ins and carry-outs are usually helpful for determining if an addition or a subtraction **results in overflow.** A good rule of thumb to determining overflow is that: *addition of number of opposite signs will **never** result in overflow. Otherwise, overflow occurs if **carry out $\neq$ carry in.*** 

For addition and subtraction, we have our average carry and borrow rules, which is just normal math. So for example 0x5 + 0x6 (0x stands for hexadecimal), we get B (which is 11). Similarly, if we have 21 - B (for hexadecimal), we use the same carry-borrow rule, we first get 17 - B, borrowing 16 from 2, (which gives 6), and substituting it back in and keep subtracting. 

## Sign Extension
- For unsigned (or positive) numbers, extend with 0. For example, 0101 extended to 8 bits is 0000 0101.
- For negative numbers, extend with 1. For example, 1101 extended to 8 bits is 1111 1101. (This is 2's complement)

### Left shift
Conceptually, this is just **binary multiplying** by $2^n$, where n is the number of bits that are being shifted. E.g. 0011 1011 shifted by 2 bits is 1110 1100; or 1101 0011 shifted by 2 bits is 0011 0100 1100.

### Right shift
Conceptually, again, this is just **binary division** by $2^n$. This is also how C integer division works (apparently). E.g. 0011 (3) being right shifted by 1 bit (divided by 2) is 0001 (1). 

