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
Stores memory, whereas combinational cannot. 