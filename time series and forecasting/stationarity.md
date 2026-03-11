we have some requirements on realization (data series) that must be met to work with cycles, primarily that **data must be stable.** in this case, stability means covariance stationary, or second-order stationarity.

1. mean must be stable over time (1st order)
$$E(y_{t})=\mu \ \forall t$$
the mean must be constant, we cannot have $E(y_{t})=\mu_{t}$ where $\mu_{t}\neq \mu_{t-h}$

2. variance/covariance structure has to be stable over time
	- first part of this assumption being true is $\sigma^{2}<\infty$
	- second part involves **autocorrelations**
## autocorrelation
let $\tau$ be displacement (how many periods apart. then, the autocovariance function is:
$$\begin{align}
\gamma(t, \tau) & = cov(y_{t}, y_{t-\tau}) \\
& =E[(y_{t}-\mu_{t})(y_{t-\tau}-\mu_{t-\tau})]
\end{align}$$
with first order stationarity $\mu_{t}=\mu_{t-\tau}=\mu$, 
$$\begin{align}
\gamma(t, \tau) =E[(y_{t}-\mu)(y_{t-\tau}-\mu))]
\end{align}$$
to be covariance stationary, $\gamma(t, \tau)$ depends only on $\tau$, not on $t$. so, for a covariance stationary series:
$$\gamma(t=6, 3)=\gamma(t=20, 3)=\gamma(t=150, 3)$$
but, 
$$\gamma(t=6, 3)\neq\gamma(t=6, 4)$$

if $\gamma(\tau)$ denotes autocovariance between $y_{t}$ and $y_{t-\tau}$, then $\gamma(0)= E[(y_{t}-y)(y_{t}-y)] = \sigma^{2} <\infty$

then, the autocorrelation $\rho$ is defined as:
$$\rho(\tau)=\frac{\gamma(\tau)}{\gamma(0)}\iff \rho(0)=\frac{\gamma(0)}{\gamma(0)}= 1$$
the partial autocorrelations $P(\tau)$ is obtained by regressing $y_{t}$ on its previous terms:
$$y_{t}= \beta_{1}y_{t-1}+\beta_{2}y_{t-2}+\dots+\beta_{\tau}y_{t-\tau}$$
so, $P(1)=\beta_{1}$ with the regression $y_{t}=\beta_{1}y_{t-1}$, and $P(2)=\beta_{2}$ with the regression $y_{t}=\beta_{1}y_{t-1} + \beta_{2}y_{t-2}$,

at lag point 1 (i.e. $t-1$), the autocorrelation and partial autocorrelations are the same $P(1)=\rho(1)$.

>[!NOTE] note
>if a series is covariance stationary, then the autocorrelations and partials should approach 0 as $\tau$ gets large.

## growing series
growing series are not covariance stationary:

![[Pasted image 20260303214053.png]]

we can take the logarithm to get the percentage change, which **sometimes** will work, but not always:

![[Pasted image 20260303214151.png]]

we could even try to detrend the series by running the regression to the time variable, and taking the residuals:

![[Pasted image 20260303214331.png]]

that doesn't seem to work well. however, if we take the first differences, we can see that we have transformed this to a stationary series:

![[Pasted image 20260303214228.png]]
## seasonal series
series with [[seasonality]] will usually not be covariance stationary, as seen by this ACF/PACF plot:

![[Pasted image 20260303213957.png]]

one way to detrending this is to remove seasonality, which is done by running a regression and taking the residuals: 

![[Pasted image 20260303214301.png]]

but this does seem that there some kind of trend going on still, so if we run an additional regression with regards to both season and time, we can see that this becomes a stationary series:

![[Pasted image 20260303214433.png]]

>[!NOTE] note
>so, if there is seasonality, we can remove the seasonal effects; if there is a trend, then we can detrend the data. otherwise, the first difference will often work as well.

