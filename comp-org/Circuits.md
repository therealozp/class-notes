Digital logic circuits can be categorized as 
- Combinational circuits
- Sequential circuits

## Combinational
Combination circuits uses boolean operators to determine output from a set of inputs. The key to recognizing combinational circuits is that **the output is entirely dependent on inputs.**

Procedure: truth table -> CSOP -> optimized -> circuit
### Half-Adder
A typical combinational circuit used to add two binary digits together. Constructing a truth table reveals that: 
- sum is an **XOR** gate
- carry is an **AND** gate

| x   | y   | sum | carry |
| --- | --- | --- | ----- |
| 0   | 0   | 0   | 0     |
| 0   | 1   | 1   | 0     |
| 1   | 0   | 1   | 0     |
| 1   | 1   | 0   | 1      |

So, it looks something like: 
![[Pasted image 20230927124548.png|500]]

### Majority Circuit
Outputs whichever value is more prevalent. For example, a 3-majority circuit: 

| x   | y   | z   | f   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 0   |
| 0   | 1   | 0   | 0   |
| 0   | 1   | 1   | 1   |
| 1   | 0   | 0   | 0   |
| 1   | 0   | 1   | 1   |
| 1   | 1   | 0   | 1   |
| 1   | 1   | 1   | 1    |
## Sequential 
- Stores memory, whereas combinational cannot. 
- Consist of a combinational circuits to which elements are connected from a **feedback path**. 
	- A function of both the current inputs, and states of current element.
- Only stores binary information
- Memory elements determine the state of the circuit
- Next state is a function of input and current state, outputting output and next state.

![[Pasted image 20231002131553.png]]
### Clocks
- SLCs require a means by which events can be sequenced.
- State changes are controlled by **clocks.**
	- A clock is a special circuit that sends a series of pulses with a precise pulse width and a precise interval between consecutive pulses.
	- The interval between consecutive pulses is called the **clock cycle time**
	- Speed is measured in MHz or GHz
### The SR Flip Flop
The most basic component of sequential logic components, stands for "set/reset"

![[Pasted image 20231002131759.png]]

Here, we see that the output is fed back into the OR gate. Hence: 
$$\begin{split}
& Q(t+1)' = \overline{S + Q(t)} \\
& Q(t+1) = \overline{R + \overline{Q(t)}}
\end{split}$$
![[Pasted image 20231002132339.png|300]]
We see that for S = 1 and R = 1, we get **undefined** values. So now, we have a JK flip flop.

### JK flip flop
We add another set of J and K inputs threaded through the SR Flip Flop. Hence, we get: 
![[Pasted image 20231002132642.png|500|center]]
In this case, S and R will become:
$$\begin{split}
& S = J\cdot\overline{Q(t)} \\
& R = K\cdot Q(t)
\end{split}$$
After completing the truth table (as an exercise for the reader) we get: 
![[Pasted image 20231002133336.png]]
### D Flip Flops
- D(ata) flip flop is a true representation of physical computer memory. This sequential circuit stores **one bit of information.**
- The output of the flip flop remains the same during subsequent clock pulses. 
- Output only changes only when the value of D changes.
![[Pasted image 20231002133613.png|500]]
![[Pasted image 20231002133632.png|200]]

