MA stands for moving average. the $\theta$ variable dictates how much influence **past forecast errors** (random shocks or white noise) have on the current observation.
# $MA(q)$
in a moving average model, think of $y_{t}$ as the deviation from the mean. then:
$$MA(q)=\epsilon_{t}+\theta_{1}\epsilon_{t-1} +\theta_{2}\epsilon_{t-2}+\dots+\theta_{q}\epsilon_{t -q}$$
where $\epsilon\sim WN(0, \sigma^2)$

so, for the class of $MA(1)$ models:
- $y_{t}=\epsilon_{t} + \theta \epsilon_{t - 1}$
- $y_{26}=\epsilon_{26} + \theta \epsilon_{25}$

then, based on the definition of the [[lag operator]] $L$, we can define:
$$MA(1)=y_{t}=(1+\theta L)\epsilon_{t}$$
then, for any arbitrary $q$:
$$MA(q) = y_{t} = \sum^{q}_{i = 0}\theta_{i}L^{i}\epsilon_{t}$$
where $\theta_{0}$ = 1.

if we recall the definition for [[conditional v. unconditional expectations#approximately rational distributed lag|approximately rational distributed lags]], we defined the $\Theta(L)$ operator to be
$$\Theta(L)=\sum^{q}_{i = 0}\theta_{i}L^{i}$$
## $MA(1)$
specifically for $MA(1)$ where $y_{t} = (1 + \theta L)\epsilon_{t}$, we can find the unconditional mean and variance as follows:
$$\begin{align}
E[y_{t}] & = E[\epsilon_{t} + \theta \epsilon_{t - 1}] \\
&= E[\epsilon_{t}] + \theta E[\epsilon_{t -1}] \\
&= 0
\end{align}$$
$$\begin{align}
Var[y_{t}] & = Var[\epsilon_{t} + \theta \epsilon_{t - 1}] \\
&= Var[\epsilon_{t}] + \theta^{2} Var[\epsilon_{t -1}] \\
&= \sigma^{2}+\theta^{2}\sigma^{2} \\
&= (1 + \theta^{2})\sigma^{2}
\end{align}$$

whereas for conditional mean and variance:
$$\begin{align}
E[y_{t}\mid\Omega_{t - 1}] & = E[\epsilon_{t} + \theta \epsilon_{t - 1}\mid\Omega_{t - 1}] \\
&= E[\epsilon_{t}\mid\Omega_{t - 1}] (=0) + \theta E[\epsilon_{t -1}\mid\Omega_{t - 1}] \\
&= \theta \epsilon_{t -1}
\end{align}$$
$$\begin{align}
Var[y_{t}\mid\Omega_{t - 1}] & = E[(y_{t} - \bar{y})^{2}\mid\Omega_{t - 1}] \\
& =\sigma^{2}
\end{align}$$
### autocorrelations
recall the formula for autocorrelations
$$\rho(\tau) = \frac{\gamma(\tau)}{\gamma(0)}$$
where:
- $\gamma(\tau)=Cov(y_{t}, y_{t - \tau})$
- $\gamma(0)=Cov(y_{t}, y_{t})=\text{variance}$

for $MA(1)$ models:
- $\gamma(0)=\text{variance}=(1+\theta^{2})\sigma^{2}$
- $\gamma(\tau) = E[(y_{t} - \mu)(y_{t-\tau}- \mu)]$

but, since our $\mu =0$:
$$\begin{align}
\gamma(\tau) &= E[y_{t} \times y_{t-\tau}] \\
& = E[(\epsilon_{t} +\theta\epsilon_{t -1})(\epsilon_{t - \tau} +\theta\epsilon_{t - \tau - 1})]  \\
\end{align}$$
let $\tau = 1$. then:
$$\begin{align}
\gamma(1) &=  E[(\epsilon_{t} +\theta\epsilon_{t -1})(\epsilon_{t - 1} +\theta\epsilon_{t - 2})]  \\
&=E[\epsilon_{t}\epsilon_{t-1}] + \theta E[\epsilon_{t - 1}^{2}]+ \theta E[\epsilon_{t}\epsilon_{t-2}]+\theta^{2}E[\epsilon_{t-1}\epsilon_{t-2}] \\
&=0+\theta \sigma^{2}+0+0 \\
&=\theta \sigma^{2}
\end{align}$$

then, the first autocorrelation term of $MA(1)$:
$$\rho(1)=\frac{\theta \sigma^{2}}{(1+\theta^{2})\sigma^{2}}=\frac{\theta}{1+\theta^{2}}$$
similarly, for $\gamma(2)$
$$\begin{align}
\gamma(2) &=  E[(\epsilon_{t} +\theta\epsilon_{t -1})(\epsilon_{t - 2} +\theta\epsilon_{t - 3})]  \\
&=E[\epsilon_{t}\epsilon_{t-2}] + \theta E[\epsilon_{t - 1}\epsilon_{t-2}]+ \theta E[\epsilon_{t}\epsilon_{t-3}]+\theta^{2}E[\epsilon_{t-1}\epsilon_{t-3}] \\
&=0+0+0+0 \\
&=0 \\
\implies &\rho(2) = 0
\end{align}$$
applying the same logic, all autocorrelation terms $\rho(\tau) = 0 \ \forall \tau > 1$.
### partials
for $MA(1)$ models, the partial correlations die off toward 0. if $\theta>0$, they alternate signs; if $\theta<0$, they stay on one side. in either case, both converge to 0.

>[!NOTE] conclusion
>all $MA$ models are covariance stationary.

![[Pasted image 20260308163229.png]]
![[Pasted image 20260308163243.png]]

if $\lvert\theta\rvert<1$, $MA(1)$ is **invertible**, meaning
$$y_{t}=(1+\theta L)\epsilon_{t} \iff \epsilon_{t}=\frac{y_{t}}{1+\theta L}$$
# $MA(2)$
$$y_{t}=\epsilon_{t}+\theta_{1}\epsilon_{t - 1}+\epsilon_{2}\epsilon_{t-2}$$
similar to $MA(1)$:
- unconditional mean is $0$
- conditional mean $E[y_{t}\mid \Omega_{t-1}]=\theta_{1} \epsilon_{t-1} +\theta_{2}\epsilon_{t-2}$

the autocorrelations also follow the same trend. $\rho(1) \neq 0$, $\rho(2) \neq 0$, but $\rho(3)=\rho(4)=\dots=\rho() = 0$. therefore:
$$\rho(\tau)= 0 \ \forall \tau > 2$$
![[Pasted image 20260308163333.png]]

we can generalize this for all $MA(q)$. 
$$
\begin{cases} \rho(\tau) \neq 0 & \text{if } \tau \leq q \\ \rho(\tau) = 0 & \text{if } \tau > q \end{cases}
$$
for all $MA(q)$ models, the partial correlations converge to $0$.