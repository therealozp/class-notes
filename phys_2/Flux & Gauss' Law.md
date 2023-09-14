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

### With a linear line of charge
Electric charge is distributed uniformly along an infinitely long, thin wire. The charge per unit length is $\lambda$ (assumed positive). Using Gauss' law, we can find the electric field: 
$$E = \frac{1}{2\pi\epsilon_0}\frac{\lambda}{r}$$
![[Pasted image 20230904143720.png]]

## Electrostatic shielding
A conducting box is immersed in a uniform electric field.
The field of the induced charges on the box combines with the uniform field to give **zero total field** inside the box.

![[Pasted image 20230904143830.png]]

