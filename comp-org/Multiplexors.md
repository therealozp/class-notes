Selects one data line from two or more input line, and combine with the selection bit to route the selected data through the output. 

![[Pasted image 20231002124649.png]]

In this case, a selection of (0, 0) for $(S_0, S_1)$ routes to $D_1$, because 0, 0 becomes the **first minterm**.

## From MUXs to Function
Read the Boolean function, expand it to CSOP form, and group selection bits together and determine the value for data lines.

## Bit shifting
Moves the bits of a word left one bit if S is low, and right one bit when S is high. 
![[Pasted image 20231002130321.png|500]]

