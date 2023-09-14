The electric field inside a conductor in static equilibrium is **zero**, and all **excess charges** lie on **the surface.**
Since the electric field can drive charges, the field **can do work**. For example: 

![[Electric Potential 2023-09-10 23.43.25.excalidraw]]

In this example, the (test) charges accelerates toward the negative plate in the presence of the field. Since the only thing between the plates that *can* affect the charge is the field, $\vec E$ is **doing work to increase KE** of the test charge.

Plugging in the electric force into the formula for a uniform force-field: 
$$W_{net,x} = F_x \cdot \Delta x = \vec E \cdot q_0 \cdot \Delta x$$
However, since the electric field **is a conservative force**, we get $\Delta KE = -\Delta PE$. Thus, the potential energy gained by the system when pushing the test charge (positive) **against** the displacement $\Delta x$ is simply: 
$$\Delta PE = q_0 E_x \cdot \Delta x$$
The scalar product $E_x \cdot \Delta x$ associated with the source charges is called the **potential difference**.
$$\Delta V = E_x \cdot \Delta x$$
Or, in terms of the change in potential energy: $$\Delta V = \frac{\Delta PE}{q_0}$$
> In short, if we are raising the potential energy of the system, we are simply moving the positive charge to a higher potential. 

Now, we have a scalar quantity that gives us useful info about the source charges, as well as how they interact with **test charges.** From the above formula, we can deduce that $$\Delta KE = -q_0 \Delta V$$
So for cases (1) where $q_0 > 0, \Delta V < 0$ and (2) where $q_0 > 0, \Delta V > 0$, we yield $\Delta KE > 0$ for (1), and  $\Delta KE < 0$ for (2). So, a **positive charge's KE increases** when accelerating through a **decreasing potential.**

## Equipotential surface

With a uniform field, the potential varies with $x$. That is plotting the potential of this source charge distribution yields a **straight line** whose slope is $E_x$. However for each **equipotential surfaces** (the dashed lines), the potential **is the same.**

![[Electric Potential 2023-09-11 00.00.32.excalidraw]]

- An **equipotential surface** is a surface on which the electric potential is the same at every point. 
- At each ES, there exists a different **electric potential.** The **closer** to the charge, the **higher** $V$ becomes. 
- Field lines and ES are always mutually perpendicular.

## Electric potential of a point charge
For a point charge, the electric field is non uniform. As in $$\vec E_{q} = \frac{\vec F_{Q, q_0}}{q_0} = \frac{kQ}{r^2}$$
Since the potential is a source charge quantity, it is also uniform. So recall that for the electric potential, $\Delta PE$ is a function of $r$. 
--> So, as **r decreases**, **PE increases.**
To get the potential energy function, we must integrate the force equation from infinity to some point r from the source (point) charge. The result is: $$PE(r) = \frac{kqq_0}{r}$$
Applying the potential difference equation from above, we get: 
$$V(r) = \frac{PE(r)}{q_0} = \frac{kq}{r}$$
For more than one source charge, use superposition. $$V = \sum V_i = k\sum \frac{q_i}{r_i} $$
The potential difference $V_a - V_b$ equals work done per unit charge by this external force for moving it from **b to a:** $$V_a - V_b = -\int_a^b \vec E \cdot d \vec l$$
Therefore, the electric potential energy of two point charges will be defined as $$U = \frac{1}{4\pi \epsilon_0}\frac{qq_0}{r}$$


So, in summary, for a **positive test charge** (just reverse the following if negative): 

> Moving with the direction of the electric field means moving in the direction of decreasing V, and vice versa.
> Moving a unit charge slowly against $\vec E$ requires applying an external force per unit charge equal and opposite to $\vec E$.

## Components of E
The components of the electric field can be found by taking partial derivatives of the electric potential: $$E_x = -\frac{\delta V_x}{\delta x}, E_y = -\frac{\delta V_y}{\delta y}, E_z = -\frac{\delta V_z}{\delta z}$$
The electric field is the negative gradient of the potential. 
- A solid conducting sphere of radius $R$ has a total charge of $q$
- The electric field **inside** the sphere is **zero** everywhere. 
- The potential is** the same** at every point inside the sphere and is **equal** to its **value at the surface**.

![[Pasted image 20230911005707.png]]

## The electron volt
We already have the unit of kinetic energy as Joules, but some times, the electron volt (eV) is more appropriate. 1eV is the amount of KE gained by an electron (or proton) accelerated through a V of 1 Volts.
1 eV = $1.6 \cdot 10^-19$ J

## The capacitor
A simple capacitor is two parallel surfaces with opposite charges, and its main function is to **store energy.** We introduce C (the capacitance), and after some boring math equations, we get: $$Q = C\Delta V$$
When charging the capacitor, electrons are drawn of the left (positive) plates, leaving behind a net positive charge. The amount of energy stored is equivalent to how much work it took to charge up the capacitor: $$PE_c = \frac{1}{2}C(\Delta V)^2$$
The energy is stored in the **electric field** (the only thing that exists between the plates), in a volume of $A \cdot d$. The **energy density** (energy/ unit volume) is therefore: $$u_e = \frac{PE_c}{A\cdot d} = \frac{1}{2} \epsilon_0 E^2$$
