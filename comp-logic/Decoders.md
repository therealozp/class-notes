$n$ inputs, $2^n$ outputs. Each output represents a minterm. 
## Active-high decoders
Voltage high (1) is true, voltage low (0) is false. each output corresponds to a **minterm**. 

For example, suppose a function has $\Sigma m(0, 2, 4)$. Then, for an active high decoder, outputs of 0, 2, 4 should be added with an OR gate to represent the function. 

Alternatively, to represent it in POS form, we take the product of **maxterms** $M_{1}\cdot M_{3}\cdot M_{5} \cdot M_{6} \cdot M_{7}$, which are equivalent to $\overline m_{1}\cdot \overline m_{3}\cdot \overline m_{5} \cdot \overline m_{6} \cdot \overline m_{7}$. Then, we take outputs 1, 3, 5, 6, 7 and wire them together with a NOR gate. 

## Active-low decoders
Voltage low (0) is true, voltage (high) is false. each output corresponds to a **maxterm.**

To represent the above function, we take outputs 1, 3, 5, 6, 7 and wire them together with an AND gate. Alternatively, wire outputs 0, 2, 4 together with a NAND gate.

## Decoder Expansion
The enable input $E$ effectively turns the decoder "on/off." For example, in an active-high decoder, $E = 0$ means all inputs will becomes 0, and $E = 1$ means the decoder will work normally. 

Then, to group up a bunch of smaller decoders into one big decoder, we use decoder expansion. A 2-to-4 to a 3-to-8 means chaining the extra output to the enable inputs of each decoder. At that point, the general boolean function becomes $I_{2}I_{1}I_{0}$. (see slides)