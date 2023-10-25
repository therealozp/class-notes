Selects one data line from two or more input line, and combine with the selection bit to route the selected data through the output. 

![[Pasted image 20231002124649.png]]

In this case, a selection of (0, 0) for $(S_0, S_1)$ routes to $D_1$, because 0, 0 becomes the **first minterm**.

## From MUXs to Function
Read the Boolean function, expand it to CSOP form, and group selection bits together and determine the value for data lines.

## Bit shifting
Moves the bits of a word left one bit if S is low, and right one bit when S is high. 
![[Pasted image 20231002130321.png|500]]

## Deriving Multiplexors
For a multiplexor with selection bits B, C and a data line of A as such:

![[Multiplexors 2023-10-25 11.18.00.excalidraw | 800]]

If we decide to chain in another MUX, we take the output and **multiply** it by the selection bit of choice. **NOTE**: by selection bit being 0 or 1, it means it is being **selected** (1) or **not selected** (0). Hence, we don't derive it straight, but rather have an X' for 0 and X for 1, for every X as a selection bit. 