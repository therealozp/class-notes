simple models such as linear, quadratic, growth rates, etc. usually have residuals (error terms) that contain cycles. most of what we have covered don't have white-noise residuals.

now, we try to approach modelling the cycles. one of the biggest things is using the Box-Jenkins model approach to univariate (single variable) time series.

## $ARMA(p, q)$ models
the $AR(p)$ component is **autoregressive**, and $MA(q)$ stands for moving average.

### $MA(q)$
in a moving average model, think of $y_{t}$ as the deviation from the mean. then:
$$MA(q)=\epsilon_{t}+\theta_{1}\epsilon_{t-1} +\theta_{2}\epsilon_{t-2}+\dots+\theta_{q}\epsilon_{t -q}$$
where $\epsilon\sim WN(0, \sigma^2)$

so, for the class of $MA(1)$ models:
- $y_{t}=\epsilon_{t} + \theta \epsilon_{t - 1}$
- $y_{26}=\epsilon_{26} + \theta \epsilon_{25}$

then, based on the definition of the lag operator $L$, we can define:
$$MA(1)=y_{t}=(1+\theta L)\epsilon_{t}$$
then, for any arbitrary $q$:
$$MA(q) = y_{t} = \sum^{q}_{i = 0}\theta_{i}L^{i}\epsilon_{t}$$
where $\theta_{0}$ = 1.

if we recall [[conditional v. unconditional expectations#approximately rational distributed log]], we defined the $\Theta(L)$ operator to be
$$\Theta(L)=\sum^{q}_{i = 0}\theta_{i}L^{i}$$
#### $MA(1)$ models
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
##### autocorrelations
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



