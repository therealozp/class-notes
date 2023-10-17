## Current Model
An isolated conductor (when $E$ is zero): 
- Electrons drift randomly
- Metal atoms remain fixed
- Each atom contributes one shared electron

Electron flowing through a filament (bulb): 
- The potential will drop across a certain conductor, but it will not drop across the wire

## Current
For a charge $\Delta q$ moving through a wire segment in a time $\Delta t$, the current (rate of flow of charge) is simply: 
$$ I = \frac{\Delta q}{\Delta t}$$
The SI unit of current is the Ampere (A or C/s).

We can also define current in terms of potential difference and resistance. Resistance is defined as "the degree to which a substance or device opposes the flow of current." All materials which **conduct electricity** have some degree of resistance. 

For a conductor made with a specific material, the equation for resistance is: 
$$R = \frac{\rho l}{A}$$ Where $\rho$ is the resistivity of the material, A is the cross-sectional area, and $l$ is the length of the conductor. 

### The conduction model
In the conduction model, we take the direction of the electric field as the direction of the current. The drift speed in the electron can be calculated with the formula:
$$v_d = \frac{I}{nqA}$$
And the number of electrons can be calculated with: 
$$n = \frac{N_q}{volume}=\frac{N_q}{Av_ddt}$$
### Current density
Current per unit area.
![[Pasted image 20231002181555.png]]
$$I = \int\int\vec J \cdot d \vec A$$
$$|{J}| = \frac{I}{A} = n|q|v_d$$
Where $n$ is the **concentration of moving charges**, $q$ is the charge per particle, and $v_d$ is the drift speed. 

![[Pasted image 20231002181832.png|500]]
$$\vec J = \sigma \vec E$$
where $\sigma$ is the inverse of $\rho$, and the electric field can be defined as: 
$$E = \rho J$$
### Current model
As resistance increases, current decreases, so the current is **inversely proportional** to resistance. 

Potential difference is defined as the work per unit test charge, namely: 
$$\Delta V = \frac{W}{q_0}$$
One source of potential energy is a battery, and for most purposes, we will consider an ideal battery, where there is negligible internal resistance. Then, the **electromotive force** $\epsilon$ rating of the battery is defined as:
$$\epsilon = \frac{W_{batt}}{q_0}$$
It is this EMF that provides the energy to the charges; so the higher $\epsilon$ is, the **higher potential energy** we raise the test charges, which **increases kinetic energy** acquired by the charges, thus **increasing the current**.

## Ohm's law
Applying a potential difference $\Delta V$ across a conductor with resistance R, we get a current I: 
$$I = \frac{\Delta V}{R}$$
So Ohm's law is the **linear relationship** between current and voltage before a good conductor, and those which produce these results are called Ohmic.

## Circuit design
A simple circuit can be thought of as a single battery and a resistor connected in a closed loop. The current will flow from **positive to negative** (see conventional model):

![[Pasted image 20231002182906.png]]
The ammeter is placed in **series** with the resistor to measure the current in the loop. We assume that the resistance of the ammeter is significantly smaller than the resistance: $R_M << R$

The voltmeter is placed in **parallel** with the resistor to measure the voltage drop across the resistor. So, to not draw any current from the circuit, $R_M > R$.

So, for a simple circuit with resistance R and potential difference $\epsilon$, Ohm's law states that $\epsilon = IR$.
## Power
Average power (the rate of transfer) is defined as: 
$$P = \frac{\Delta E}{\Delta t}=\frac{\Delta PE}{\Delta t}$$
We can express this in terms of voltage, noting that voltage raises the potential energy of a charge element $\Delta q$:
$$P = \frac{\Delta E}{\Delta t}=\frac{\Delta q \epsilon}{\Delta t} = I \epsilon$$
So, by applying Ohm's law:
$$P = I^2 R$$
*The rate of energy transfer in the circuit is equal to the rate of dissipation in the resistor.*

When asked about: 
- Rate of energy conversion from **chemical to electrical** in the battery: $P_{chemical}$ is the **total** $P$ power output. 
- Rate of energy dissipation **in the battery**, means the power dissipated by the *internal resistance* of the battery, usually $P_{batt} = I^2r$. 
- The **net output** of the battery: means the useful energy being dissipated at the target resistor(s). Usually $P_{out} = I^2R$. 

For questions concerning the "potential difference across the terminals of the battery", this usually means: 
$$V_{term}=\frac{\epsilon}{r+R}\cdot R $$

[[Advanced Circuits]]