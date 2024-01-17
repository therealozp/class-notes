## Magnetic Flux
Through a conducting loop, magnetic flux through a conducting loop is: 
$$\Phi = BA$$
![[Pasted image 20231105202955 1.png]]

## Faraday's Law

![[Pasted image 20231105203333 1.png]]

- A current (thus voltage) was measured when the magnet was either moving towards or away from the loop. 
- The polarity is different if the magnet was moving towards or away from the loop
- There is no current when the magnet remains static.

Due to the change in flux through a loop, an emf is induced such that the loop now has a current through it.
$$\epsilon=-\frac{\Delta\Phi}{\Delta t}$$
According to the first point in the summary, the "induced" emf is not merely due to a change in flux, but due to a **rate of change** in flux. For a system of $N$ windings, the emf is as follows; 
$$\epsilon=N\frac{\Delta\Phi}{\Delta t}$$
## Lenz's Law
The **induced emf** due to the change in flux through a closed loop is **an opposition emf** set up to oppose **the change of flux**, and thus the mechanism for which caused the change in flux.

So, when the bar magnet approached the loop, we read a current with an opposite polarity as when the magnet was retracted. In other words, it **opposed** the *increase* in flux with one polarity, thus reversed polarity when the **induced emf** was set up to oppose the *decrease* in flux.

## Transformers

![[Pasted image 20231105205315 1.png]]

When there is an alternating current $V_P = V_o \cdot \cos{\omega t}$: 
- the oscillating electric field will generate **a change in flux** through the primary coil
- the flux is transported through the iron core to the secondary
- **an induced emf** is now generated across the secondary coil (blue)

According to [[#Faraday's Law]]: 
$$\begin{split}
V_P&=N_P\frac{\Delta\Phi_P}{\Delta t} \\
V_S&=N_S\frac{\Delta\Phi_S}{\Delta t} \\\\
\frac{\Delta\Phi_P}{\Delta t} &=\frac{\Delta\Phi_S}{\Delta t} \ (conserved \ flux \ lines)
\end{split}
$$
For an ideal transformer: 
1. Flux lines are preserved
2. Power is preserved.

Since the flux is the same, we can rearrange the equation we can get: 
$$\frac{V_P}{V_S} = \frac{N_P}{N_S}$$
If $N_S > N_P$, then it is a step-up transformer. Else, it's a step down transformer.

From law number 2 stating the equivalence in power, we can also get the equation: 
$$I_P V_P = I_SV_S$$