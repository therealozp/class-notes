AR models are autoregressive. $AR(p)$ models takes the formula
$$y_{t}=\phi_{1} y_{t-1}+\phi_{2}y_{t-2}+\dots+\phi_{p}y_{t-p}+\epsilon _{t}$$
since this is autoregressive, the $\phi$ coefficients show how much influence past observations (historical values) have on the current observation
## $AR(1)$
$$y_{t}=\phi y_{t-1}+\epsilon_{t}$$
expressed in terms of lag operators:
$$\epsilon_{t}=(1-\phi_{1} L)y_{t}$$
![[Pasted image 20260308164521.png]]
![[Pasted image 20260308164531.png]]
## $AR(2)$
similarly, we can define an $AR(2)$ model as:
$$y_{t}=\phi_{1}y_{t - 1} + \phi_{2}y_{t -2} + \epsilon_{t}$$
then, swapping sides and expressing it in terms of the errors:
$$\begin{align}
\epsilon_{t} &=y_{t} - \phi_{1}y_{t - 1} -\phi_{2}y_{t -2} \\
&=(1-\phi_{1}L^1-\phi_{2}L^2)y
\end{align}$$
![[Pasted image 20260308164544.png]]
