For a circuit with a current $i = I\cos{\omega t}$, each different R, L, C element will lead to a different circuit quantity: 

![[Pasted image 20231112125728.png]]

For a circuit that has all of the R, L, or C elements, we derive a different formula for that entirely, being: 
$$V_{RLC} = IZ$$
Where $Z$ is the impedance of the circuit. Impedance for an alternating current is similar to what resistance means for a direct current, meaning that current will actively seek for the path of least impedance to travel. We can find $Z$ for a RLC circuit by using: 
$$Z = \sqrt{R^2 + (X_L - X_C)^2} = \sqrt{R^2 + (\omega L-\frac{1}{\omega C})^2}$$
Drawing the phasor diagram for these circuits, we can divide them into two cases where either $L < C$ or $C < L$: 

![[Pasted image 20231112130524.png]]
![[Pasted image 20231112131102.png]]

Then, we can get the angle of the final $V$ with respect to $I$ by taking the tangents: 
$$\tan{\phi}=\frac{\omega L - 1/\omega C}{R}=\frac{Z_L-Z_C}{R}$$
or relating them directly to the impedance: 
$$\cos{\phi}=\frac{R}{Z}$$
In terms of the root-mean-square (rms) values, we can relate voltage to impedance: 
$$V_{rms} = I_{rms} Z$$
## Average power
The average power of an RLC circuit can be calculated by: 
$$P_{av}=V_{rms}\cdot I_{rms}\cdot \cos{\phi}$$
where $\phi$ is the value calculated above.