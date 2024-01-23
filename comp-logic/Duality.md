In a boolean equation system, we can get the duality of whatever the current Boolean equation is by changing all + to $\cdot$ , all 0's to 1's, and keep the variables intact. For example, the duality of the boolean equation $a(b + c)$ will be $a + bc$. Similar to DeMorgan's, without the negation.

The principle of duality states that if a statement $F_{1}= F_{2}$, then the dual of both statements $D$ will also be true $D(F_{1)} = D(F_{2})$.
### Proving the consensus theorem
For proving 

description: 
First, we set up the 3 ICs in the gaps so that the bridge can prevent wrong electronic signals. We designated input A to be yellow, B to be green, and C to be blue. We then moved on to wiring the ICs to their respective GCCs and Grounds. 

We first connected the B and A inputs to the AND IC, and wire the resulting output to the OR gate. Next, we had to wire the A input to an inverter, and wire that output and C to the same AND IC but at a different gate. From that output, we yield A'C. 

After we wired both AB and A'C into the OR, we connected the output to the positive end of the LED, wired a resistor to the negative end, and grounded it. After testing for all cases, the output of our circuit matched what we expected.