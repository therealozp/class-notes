### The loop rule
The sum of all potential differences around a closed loop is zero. 
$$\sum \Delta V = 0$$
So, for example, in the above circuit with the resistor, the voltage **must drop** somewhere. And seeing that A is a higher potential and B is a lower, we determine that the drop occurs at the resistor $R$. 

Sign convention: 
- If current travels from - to +, then $\Delta V > 0$
- If current travels from + to -, then $\Delta V < 0$

![[Pasted image 20231002184335.png]]

So, when we start at B and return to B: 
$$\sum \Delta V=\epsilon  -IR = 0$$
### The junction rule
Consider the following scenario: 

![[Pasted image 20231002184615.png]]

Then, the current would flow through the battery, and split at A into two parts travelling through 2 junctions. 

![[Pasted image 20231002184549.png]]

Recall the concepts of voltage: $V_a = V_b$, and $V_c = V_d$, we understand that $V_a - V_d = V_b - V_c$. So, at the junction, we have the rule $I = I_2 + I_3$. 

## Series circuit
When we refer to resistors being in series, we mean having the same current and being part of the same current loop. Therefore, we say the total resistance of the circuit being: 
$$\sum R = R_1 + R_2 +...$$
Therefore, solving for the current: 
$$I = \frac{\Delta V}{\sum R}$$
## Parallel circuits
When we refer to them being in parallel, then they have the **same potential** at both ends. So, by the junction rule: $I = I_1 + I_2 + I_3= \sum I$ . Thus,
$$\frac{1}{R_t} = \frac{1}{R_1} + \frac{1}{R_2} +... + \sum \frac{1}{R_i}$$
So, for a parallel configuration, the resistance **diminishes.** The more conduction channels, the greater the current, and the less total resistance. 

## Dual battery (opposing polarities)
When there are two batteries facing each other, we make sure that the loop still holds (travelling from a high potential to a lower potential). Consider the following example: 

![[Pasted image 20231002192639.png]]

Then, we will have: 
$$\sum \Delta V_i = 12V - I\cdot 10 \Omega - 9V - I\cdot20\Omega$$
## RC circuit
The capacitor is initially charged to $\Delta V_0$. When the switch is closed, the capacitor discharges, and thus a current exists in the circuit.

![[Pasted image 20231002192931.png]]

The current will originally be at its maximum value $I_0$ as the capacitor is discharging. With time, however, the amount of charge on the plates decays with time, meaning that the **voltage also decreases**. Therefore, we have $\Delta V_C < \Delta V_0$ for $t>0$. 

![[Pasted image 20231002193059.png]]

The amount of time it takes to lose 0.63 of the maximum voltage is equal to one time constant $\tau = RC$. Since the current is **proportional** to the potential difference, it will also so **decay with time**.

### Charging
When the circuit is hooked up to a battery, the capacitor will be charged with time, as charge accumulates on the plates. The voltage in this case will **asymptotically** approach the max $\epsilon$. 

![[Pasted image 20231002193413.png]]

However, note that when the capacitor charges, there will be an **opposite** potential difference against the battery, effectively cutting the current with time. Hence, we note that the current will eventually decay.

## AC / DC
An alternating circuit (AC) is one for which the supplied voltage changes with time. For example, let the voltage oscillate sinusoidally, driving the current back and forth across the resistor. In a non-L-C circuit, the current and the voltage are in phase. 

![[Pasted image 20231002193641.png]] 

Because the voltage and current have this behavior, the rate of energy dissipation will also differ. 

![[Pasted image 20231002193951.png]]

Averaging the power function, we get: 
$$\overline P =\frac{1}{2}I^2_0R = I_{rms}^2R.$$
Therefore: 
$$\begin{split}
& I_{rms} = \frac{I_0}{\sqrt{2}} \\
& V_{rms} = \frac{V_0}{\sqrt{2}}
\end{split}$$
