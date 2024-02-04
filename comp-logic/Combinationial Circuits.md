## Parity checker
In a bit system from $d_{1}$ to $d_7$, we can check to see if there has been a mismatch between the data sent and the data received. We can do this by adding another bit to the system to check if the number of 1's and 0's are consistent. 

## Programmable NOT
We can use a two-input XOR gate to simulate a NOT gate, depending on the programmable input being 1 or 0. In the case of the full adder $FA(a, b, c_{in})$, we can add an XOR before the $b$ input to simulate NOT. 

![[Pasted image 20240131100120.png]]

The use of this NOT is to implement **subtraction** inside a full adder, by bit flipping one of the inputs to simulate its two's-complement. Then, the **carry-in** has to be 1, to account for the missing bit added to the complementing operation.

1001 $-$bit flip$\rightarrow$ 0110 $-$add carry in of 1$\rightarrow$ 0111. 

## Analysis
Used to: 
- simplify a boolean function implemented by a circuit
- 