Consider a flat area perpendicular to a uniform electric field. Increasing the area means more **electric field lines** pass through the area, increasing the **flux**. 
A **stronger field** = **more closely spaced** field lines, increasing flux.

![[Flux 2023-09-04 14.09.39.excalidraw|1024]]

Suppose with the same surface, we pivot the surface an angle $\phi$. If the area is not perpendicular to the field, fewer field lines pass through it. 
In this case, the area is only counted by the **silhouette** (the projection) of the rotated surface, and the flux is decreasing by a factor of **$\cos(\theta)$

In general, the flux through a surface must be computed using a surface integral over the area: 
$$\Phi_E = \int{\vec E \cdot d\vec A} $$
Depending the sign of the charge, the flux through a **closed surface** is either *outward (positive)* or *inward (negative)*. Special cases include: 
- If there is no charge inside the box, there is no electric field. 
- If the **net charge** inside the box is **zero**, then **electric field flows in on one half but out on the other half**, which results in a **net zero** electric flux.
- If charge is near the box, but not **inside it**: on one end, flux points into the box; on the other, it flows out; on the sides, field is **parallel** to the surface -> **net zero flux.**

![[Pasted image 20230904142817.png]]

## Gauss' Law
Let $Q_{encl}$ be the total charge **enclosed** by a surface. Gauss' law states that the **total electric flux** through an enclosed surface is equal to the **net charge** inside the surface divided by $\epsilon_{0}$
$$\Phi_E = \int{\vec E \cdot d\vec A} = \frac{Q_{encl}}{\epsilon_0}$$
Note that **flux** is the same irrespective of the radius of the sphere of charge we are considering.

### With an enclosing sphere
![[Pasted image 20230918232636.png|600]]

### With a linear line of charge
Electric charge is distributed uniformly along an infinitely long, thin wire. The charge per unit length is $\lambda$ (assumed positive). Using Gauss' law, we can find the electric field: 
$$E = \frac{1}{2\pi\epsilon_0}\frac{\lambda}{r}$$
![[Pasted image 20230904143720.png]]

### On a Planar Charge
Imagine a cylinder sliced by the plane. We note that the electric field in this case will come **out** from both ends of the cylinder, pointing it outward. The flux through the end of that surface is $+EA$, so the flux through both ends is $+2EA$. Also note that there is proof by integration [here.](https://mediaplayer.pearsoncmg.com/assets/Anderson_Video_E_Field_of_a_Planar_Charge)

![[Pasted image 20230919010315.png|600]]

In this case, the vector $\vec E$ is:
$$
\begin{equation*}
\vec E = \left\{
        \begin{array}{ll}
            +\frac{\sigma}{2\epsilon_0} \hat z & \quad z > 0 \\
            -\frac{\sigma}{2\epsilon_0} \hat z& \quad z < 0
        \end{array}
    \right.
\end{equation*}
$$
## Electrostatic shielding
A conducting box is immersed in a uniform electric field.
The field of the induced charges on the box combines with the uniform field to give **zero total field** inside the box.

![[Pasted image 20230904143830.png]]

For any cases where the cylinder or sphere of charge has a significant radius (i.e. we are forced to compute an area of charge $r$ for $r < R$), the final result is often **the original result where r = R**. but **scaled by a factor of r/R.**

Proof: 
### For a charged cylinder: 
Yes, you're on the right track.

Given the symmetry and uniform charge distribution, when you're inside the charged cylinder (i.e.,$r < R$), the electric field due to the charge inside your Gaussian cylinder of radius $r$ will behave as if you're dealing with a line of charge with a linear charge density proportional to $r$. 

The reason for this is that the charge enclosed within a radius $r$ scales with $r^2$ (because of the area factor $\pi r^2$), while the area of the Gaussian surface scales with $r$ (because of the circumference factor $2\pi r$). Therefore, the electric field $E$ scales with $r$.

When you set up the equation using Gauss's law:
$$E \times (2\pi r L) = \frac{\lambda \times \pi r^2 L}{\epsilon_0}$$
And solve for $E$:
$$E = \frac{\lambda r}{2 \epsilon_0 R^2}$$
Notice the factor of $r$ in the numerator. If you normalize this by the electric field at $r = R$, which is $E_{R} = \frac{\lambda R}{2 \epsilon_0 R^2} = \frac{\lambda}{2 \epsilon_0 R}$, you'll get:
$$ \frac{E}{E_{R}} = \frac{r}{R}$$
Which shows that the electric field magnitude scales with the factor $r/R$ when $r < R$.

### For a charged sphere
Certainly! Let's determine the electric field $E$ due to a uniformly charged sphere of radius $R$ and total charge $Q$ at a distance $r < R$ from its center.

1. **Charge Density**: Given that the sphere has a uniform volume charge density, we have$$ \rho = \frac{Q}{\frac{4}{3} \pi R^3}$$
2. **Gaussian Surface**: Choose a spherical Gaussian surface with radius $r$ inside the charged sphere.

3. **Symmetry**: Due to spherical symmetry, the electric field $E$ at every point on the Gaussian surface is radially outward and has the same magnitude. 

4. **Charge Enclosed**: The volume of the portion of the charged sphere enclosed by the Gaussian surface is $\frac{4}{3} \pi r^3$. The charge $Q_{\text{enc}}$ enclosed by this Gaussian surface is given by
$$Q_{\text{enc}} = \rho \times \frac{4}{3} \pi r^3 = \frac{Q r^3}{R^3}$$
where we substituted the value for $\rho$ from the first step.

5. **Gauss's Law**: Applying Gauss's law, the electric flux through the Gaussian surface is equal to $Q_{\text{enc}}/\epsilon_0$. We get
$$E \times 4\pi r^2 = \frac{Q r^3}{\epsilon_0 R^3}$$
Here, $4\pi r^2$ is the area of the Gaussian surface.

6. **Solving for $E$**: 
$$E = \frac{Q r}{4\pi \epsilon_0 R^3}$$

So, for $r < R$, the electric field inside a uniformly charged sphere is given by:
$$E = \frac{Q r}{4\pi \epsilon_0 R^3}$$
This electric field grows linearly with $r$ when inside the sphere, similar to the cylindrical case.