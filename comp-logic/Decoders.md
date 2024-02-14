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

take the following decoder as an example: 

![[Pasted image 20240214101627.png]]

the enable line $G_{1}, \overline{G_{2A}}, \overline{G_{2B}}$. Let us define that $\overline G_{2} = \overline G_{2A} + \overline G_{2B}$. From there, we notice that both inputs of $G_{2}$ needs to be low (meaning their OR of them must be 0), while $G_{1}$ needs to be high. 

## Encoders
A combinational logic module that assigns a unique output code for each input signal applied to the device. Essentially an opposite decoder. 

From the given truth table, we use K-maps to get the boolean function of each individual output line of the encoder based on the different inputs. From then, logic implementation using requisite gates do not differ by much.1
### Priority encoders
Allows multiple input lines to be active simultaneously, encoding the binary value of the subscript of the input line with highest priority. Particularly useful to implement prioritized interrupts in interfacing of CPUs to peripheral devices.

To simplify the design, the highest priority is assigned to the highest subscript, next highest to second highest, and so on.