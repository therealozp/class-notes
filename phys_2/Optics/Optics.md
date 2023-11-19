A wave is normally defined by the following parameters: 
- Amplitude $A$
- Wavelength $\lambda$
- Frequency $f$ and period $T$
- Wave velocity $v = \lambda f$ 
- **Wave energy** transported by the wave is **proportional** to the **amplitude squared**


![[Pasted image 20231106232339.png]]

## Diffraction
When a **plane wave** approaches an opening with a width of $D$, diffraction will occur. This slit might also be referred to as the **aperture**; where $\lambda > D$.

## Models of light
Two models that describe light: 
1. Wave-like (as with sound and water)
2. Particle-like

If there is wave like behavior, there could exist some interference as such: 
![[Pasted image 20231106234114.png]]

We can also conclude that light is not a simple particle due to Young's double-slit experiment.

## Snell's law
In the Universe, light travels at $2.99 \times 10^8 \ m/s$ in a vacuum. But what about light and water? 

In different environments, we can calculate the wavelength of light using the formula: 
$$\lambda_n = \frac{\lambda_0}{n}$$
Where $\lambda_0$ is the wavelength of light in the vacuum, and $\lambda_n$ is the wavelength of light in the medium. Note that, however, that the **frequency does not change**: $f_n = f_0$. 

$n$ is the **index of refraction** of the medium, is always $\geq 1$ and is given by:
$$n = \frac{c}{v_n}$$
For light incident perpendicularly at the material, we can get: 
![[Pasted image 20231106235129.png]]

But what if it is done at an angle? Consider the following photo: 

![[Pasted image 20231106235232.png]]

Then, we can derive the sides: 
$$\begin{split}
AC = BC \sin{\theta_1} = 2\lambda_1 \\
BD = BC \sin{\theta_2} = 2\lambda_2
\end{split}$$
Therefore, we can get the equation: 
$$\frac{\lambda_1}{\lambda_2} = \frac{\sin{\theta_1}}{\sin{\theta_2}}$$
But, the frequency are the same for both sides of the boundary, so we can finally derive the final equation of Snell's law: 
$$n_1\sin{\theta_1}=n_2\sin{\theta_2}$$
## Refraction

![[Pasted image 20231106235750.png]]

To calculate that $d$, we can apply Snell's law:

![[Pasted image 20231106235832.png]]

### Total internal reflection
Occurs when $n_1 > n_2$, and the critical angle $\theta_c$ can be calculate using: 
$$\sin{\theta_d} = \frac{n_2}{n_1}$$
If the angle is greater than the critical anger, we get **total internal reflection.**

![[Pasted image 20231107000246.png]]

This has implications for fiber optics, which makes extensive use of the TIR principle.

## Dispersion
When refraction occurs for light of different wavelengths, we get dispersions:

![[Pasted image 20231107001439.png]]

## Apparent depth

![[Pasted image 20231107001542.png]]

Procedure: 
1. Find $\theta_1$ by using [[#Snell's law]]
2. Calculate the value of $x$, and use $x$ for subsequent calculations involving the tangents $\tan{\theta_1}$ and $\tan{\theta_2}$.

## Prisms and refraction
TODO

## Fiber Optic cable's incident angle
We have the $d$ which stands for the width of the cable. So, the strategy would be to find the **critical angle** and re-calculate the incident angle $\theta_1$. In summary:

![[Optics 2023-11-16 10.43.11.excalidraw|1000]]
$$n_1\sin{\theta_1} = n_2\sin{\theta_2}$$
$$\sin{\theta_{crit}} = \frac{n_{core}}{n_{cladding}}$$
$$\theta_2 = 90\degree - \theta_{crit}$$
