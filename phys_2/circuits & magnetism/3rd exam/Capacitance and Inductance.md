## Inductance
The emf inducted in a circuit usually follows the formula: 
$$\epsilon = -L\frac{di}{dt}$$
The self-inductance of a solenoid is calculated by the formula: 
$$L = \frac{N\phi_B}{i} = \frac{NBA}{i}$$
where $\phi_B$ is the magnetic flux caused by the current in each turn of the coil. In a solenoid, the magnetic field is calculated using the formula in [[Magnetic Field# In a solenoid]].
### Stored Energy and Energy Density
For an inductor with inductance $L$ with **a stable** current $I$ running through it, we can get the formula for total stored energy: 
$$U=L\int^I_0idi=\frac{1}{2}LI^2$$
and the energy density of a magnetic field B: 
$$u=\frac{B^2}{2\mu_0}\ \ (in \ a \ vacuum)$$
for any other environment with magnetic permeability of $\mu$, substitute $\mu_0$ for that instead.

## The LR Circuit

In a circuit containing a resistor $R$, an inductor $L$, and a source of emf, the growth and decay of current are exponential, by a time constant $\tau$. This is to say that when a switch is open and closed, current will not rush to become it's maximum value, but grow with time. 

![[Pasted image 20231109234501.png]]

To calculate the **current** after a certain amount of time $t$ after a switch is closed, we can use the formula: 
$$i=\frac{\epsilon}{R}(1-e^{(-R/L)t})$$
