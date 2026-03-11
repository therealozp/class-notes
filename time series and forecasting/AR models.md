AR models are autoregressive. $AR(p)$ models takes the formula
$$y_{t}=\phi_{1} y_{t-1}+\phi_{2}y_{t-2}+\dots+\phi_{p}y_{t-p}+\epsilon _{t}$$
since this is autoregressive, the $\phi$ coefficients show how much influence past observations (historical values) have on the current observation.

an $AR(p)$ model has a **necessary condition** for covariance stationarity:
$$
\sum_{i = 0}^{p}\phi_{i} < 1
$$
meaning, if this condition is satisfied, the process may or may not be covariance stationary; but if it is not, then the model is absolutely NOT covariance stationary.
## $AR(1)$
$$y_{t}=\phi y_{t-1}+\epsilon_{t}$$
expressed in terms of lag operators:
$$\epsilon_{t}=(1-\phi_{1} L)y_{t}$$

when we further decompose $y_{t-1}=\phi y_{t-2}+ \epsilon_{t-1}$, we can plug this back in to our original equation:
$$
\begin{align}
y_{t} &=\phi y_{t-1}+\epsilon_{t} \\
&=\phi(\phi y_{t-2}+\epsilon_{t-1})+e_{t} \\
&=e_{t}+\phi e_{t-1}+\phi^2y_{t-2}  \\
&=e_{t}+\phi e_{t-1}+\phi^2e_{t-2}+\phi^{3}e_{t-3}+\dots
\end{align}
$$
taking the expected value of $y_{t}$, we get the expected value of the noises:
$$E(y_{t})=E(e_{t}+\phi e_{t-1}+\phi^{2}e_{t-2}+\dots)=0$$
and the variance:
$$\begin{align}
Var(y_{t})&=Var(e_{t}+\phi e_{t-1}+\phi^{2}e_{t-2}+\dots) \\
&=Var(e_{t})+\phi^2Var(e_{t-1})+\phi^{4}Var(e_{t-2})+\dots \\
&=\sum^{\infty}_{i=0}\phi^{2i}\sigma^{2} \\
&=\frac{\sigma^{2}}{1-\phi^{2}} = \gamma(0)
\end{align}$$
### autocovariance
so then, the autocovariance of an $AR(1)$ model is:
$$\begin{align}
\gamma(\tau)&=E[(y_{t}-\mu)(y_{t-\tau}-\mu)] \\
&=E(\phi y_{t-1}y_{t-\tau}+\epsilon_{t}y_{t-\tau}) \\
&=\phi \gamma(\tau-1)
\end{align}$$
we have shown before that $\gamma(0)=\frac{\sigma^{2}}{1-\phi^{2}}$, and:
$$\begin{align}
\gamma(0)& = \frac{\sigma^{2}}{1-\phi^{2}} \\
\gamma(1) &= \frac{\phi\sigma^{2}}{1-\phi^{2}} \\
\gamma(2) &= \frac{\phi^{2}\sigma^{2}}{1-\phi^{2}} \\
&\dots \\
\gamma(\tau) &= \frac{\phi^\tau\sigma^{2}}{1-\phi^{2}}
\end{align}$$
so then, the autocorrelation function for $AR(1)$ models is:
$$\rho(\tau)=\frac{\gamma(\tau)}{\gamma(0)}=\phi^{\tau}$$
for any $\lvert \phi \rvert < 1$, the ACF dies off to 0.

### partials
the partial autocorrelations are the main identifier of an $AR$ model. 
$$
\forall AR(p): \begin{cases} P(\tau) \neq 0 & \text{if } \tau \leq p \\ P(\tau) = 0 & \text{if } \tau > p \end{cases}
$$
so, for $AR(1)$, the only non-zero PACF is the first. 

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
