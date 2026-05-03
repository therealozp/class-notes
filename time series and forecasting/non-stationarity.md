many macro series are non-stationary, such as growing along some trend or in some other way. 

a special type of non-stationary data is a series that has a **unit root**. for an $ARMA(p, q)$ model where $\Phi(L)y_{t}=\Theta(L)\epsilon_{t}$, if one or more of the roots of $\Phi(L)$ is 1, then we have a unit root, meaning a non-stationary process.

if a unit root exists, then
$$\Phi(L)=(1-L)\hat{\Phi}(L)$$
where:
- $\Phi(L)$ is an $n$-degree polynomial, and
- $\hat{\Phi}(L)$ is an $n-1$ degree polynomial. 

for example, consider the ARMA model $y_{t}=0.5y_{t - 1}+0.5y_{t -2}+\epsilon_{t}$.

we can rewrite the equation as $(1-0.5L - 0.5L^{2})y_{t}=\epsilon_{t}$. substituting $x$ for $L$, we get the polynomial $1 - 0.5x-0.5x^{2}$, which can be factorized into $(1-x)(1+0.5x)$.

if it only has one unit root, then the first difference is stationary. meaning if 
$$\begin{align}
& \Phi(L)=(1-L)\hat{\Phi}(L) \\
\implies&(1 - L)\hat{\Phi}(L) y_{t} = \Theta(L) \epsilon_{t} \\
\implies &\hat{\Phi}(L)\Delta y_{t} = \Theta(L) \epsilon_{t}
\end{align}$$
since $\hat{\Phi}(L)$ does not have any unit roots, the first difference $\Delta y_{_{t}}$ is a stationary series. any series that is non-stationary, but becomes stationary with the first difference, is called an integrated series $I(1)$. any $I(d)$ series need $d$ differences to become stationary.

most, if not all, economic time series are either $I(0)$ or $I(1)$. adding the $I(d)$ property to the $ARMA(p, q)$ set, we create an $ARIMA(p, d, q)$ series.

so,
- $ARIMA(p, 1, q)$ needs first differences for stationarity,
- $ARMA(p, q)$ means the levels $I(0)$ are already stationary.

## random walk
the simplest integrated series is the random walk, where:
$$y_{t} = y_{t -1}+\epsilon_{t}$$
where $\epsilon_{t}$ is [[white noise]]. we can easily see that this series has one unit root:
$$(1-L)y_{t} = \epsilon_{t}$$
so it has one unit root = 1.

suppose we started at $y_{0}$, then:
$$y_{t} = y_{0}+\sum_{i = 1}^{t}\epsilon_{i}$$
then, we can get:
- unconditional mean $E(y_{t}) = 0$
- conditional mean $E(y_{t}\mid \Omega_{t}) = y_{0} +\sum_{i = 1}^{t}\epsilon_{i}$
	- $E(y_{t}\mid \Omega_{t - 1}) = y_{t - 1} +E(\epsilon_{i}\mid \Omega_{t - 1}) = y_{t} - 1$
- unconditional variance
$$\begin{align}
Var(y_{t}) & = Var(y_{t-1})+Var(\epsilon_{t}) \\
&=Var(y_{0}) + \sum_{i = 1}^{t}Var(\epsilon_{i}) \\
&= 0+ t\times \sigma^{2} \\
\implies&Var(y_{t}) \to \infty \text{ as } t\to \infty
\end{align}$$

>[!NOTE]
>the autocovariance of a random walk will be 1 for all lags.

## trends
### deterministic trend
$$y_{t} = \alpha+\beta Time_{t}+\epsilon_{t}$$
where, for $\gamma(t)\sim WN(0, \sigma^{2})$:
$$\epsilon_{t}= \frac{\Theta(L)}{\Phi(L)}\gamma(t)$$

when deterministic, the series always revert back to the trend, so we usually get really good forecasts with these.
### stochastic trend
also called a random walk with drift.
$$y_{t} = \delta+y_{t -1}+\epsilon_{t}$$
meaning for some data at position $n$, we are essentially getting
$$y_{n} = n \delta+y_{0}+\sum_{i = 1}^{n}\epsilon_{t}$$
for a stochastic trend:
- unconditional mean $E(y_{t}) = y_{0} +\delta$
- conditional mean $E(y_{t}\mid \Omega_{n}) = y_{0} +t \delta+\sum \epsilon_{i}$
- variance $Var(y_{t})=t \sigma^{2}$, approaching $\infty$ as $t$ increases. 

## ARIMA models
for an $ARIMA(1, 1, 1)$:
$$\Delta y_{t} = \phi \Delta y_{t -1}+\epsilon_{t}+\theta \epsilon_{t-1}$$
with a zero mean, an $ARIMA(p, d, q)$ model follows:
$$(1-L)^{d}y_{t}=\frac{\Theta(L)}{\Phi(L)}\epsilon_{t}$$
with a mean $c$, the model becomes
$$(1-L)^{d}\Phi(L)y_{t} = c + \Theta(L) \epsilon_{t}$$
or 
$$(1-L)^{d}y_{t}=\frac{c}{\Phi(1)} + \frac{\Theta(L)}{\Phi(L)}\epsilon_{t}$$
for economic purposes, $d$ is often 0 or 1. an $I(1)$ series:
- is non stationary, but its first difference is stationary
- any shock is permanent
- variance grows unbounded

an $AR(1)$ model with zero mean has the equation:
$$y_{t}= \phi y_{t-1}+\epsilon_{t}$$
if $\phi< 1: y_{T+h, T}=\phi^{h}y_{t}$ 
if $\phi= 1: y_{T+h, T}=y_{t}$ 

suppose we run ordinary least squares (OLS) on this equation. if $\phi = 1$, the OLS estimate has 2 properties:
1. it becomes **super consistent**.
a model is consistent when the estimation $\hat{\beta}$ approaches the true value of $\beta$ as the number of observation increases.
$$\frac{\phi - \hat{\phi}}{\sqrt{ T }}\to 0 \text{ as }T\to \infty$$
usually, the rate that it approaches is proportional to $\sqrt{n}$. **super consistency** means the rate of approach is even *higher* than $\sqrt{ n }$, so in our model's case:
$$\frac{\phi - \hat{\phi}}{ T}\to 0 \text{ as }T\to \infty$$
2. but the estimator is biased downwards:
$$E[\hat{\phi _{OLS}}] < \phi ^{*}= 1$$
this mean that the statistic $\frac{\hat{\phi}_{OLS} - 1}{\sigma}$ is **not** t-distributed. so, to test the unit root, we have to rely on a different distribution to see if $\phi<1$ significantly. 

this distribution is put together by 2 statisticians, Dickey and Fuller, so the tests for this is usually called Dickey-Fuller tests.

consider an $ARMA(3,2)$ model, where:
$$(1 - \phi_{1}L-\phi_{2}L^{2}-\phi_{3}L^{3})y_{t}=\epsilon_{t}+\theta_{1}\epsilon_{t -1}+\theta_{2}\epsilon_{t - 2}$$
a unit root exists when L=1 is a root of $\Phi$. if the individual $\phi$'s sum to 1, you also have a unit root. if you have a unit root, you can divide $\Phi(L)$ by $1-L$ and get no remainder. 

so, if the $ARMA(3, 2)$ process above happen to have a unit root, we can extract $1-L$ away from it to create a new series:
$$(1-L)y_{t}(1 - \hat{\phi}_{1}L - \hat{\phi}_{2}L^{2})=\epsilon_{t}+\theta_{1}\epsilon_{t - 1}+\theta_{2}\epsilon_{t-2}$$
which becomes an $ARIMA(2, 1, 2)$ series. 

## unit root tests
the simplest variant is testing the $y_{t}=\phi y_{t -1}+\epsilon_{t}$, and testing to see if $\phi$ is too close to 1 (because we are statistically unable to show it is less than 1). the $\hat{T}$ should follow a standard D-F distribution.

for an $AR(1)$ model with a constant:
$$y_{t} = \mu +\phi y_{t - 1} + \epsilon_{t}$$
we can run a regression on deviation from the mean:
$$\begin{align}
&y_{t} - \mu =\phi(y_{t -1}-\mu) + \epsilon_{t} \\
\end{align}$$
setting $\alpha=1-\phi$, we can rewrite the equation as $$y_{t}=\alpha + \phi y_{t-1}+\epsilon_{t}$$if $\phi=1$, then $y_{t}=\phi y_{t-1}+\epsilon_{t}$, meaning the series is a random walk. 

if we have a linear time trend in our $AR$ process, we want to make sure that it is not a random walk with drift:
$$y_{t}=a+bTime_{t}+\epsilon_{t}$$
taking out the trend, we can obtain the new $AR(1)$ model
$$y_{t}-a-bTime_{t} = \phi(y_{t} - a-b Time_{t}) + \epsilon_{t}$$
then, reorganizing the terms
$$\begin{align}
 y_{T} &=\phi y_{T-1}+a(1 - \phi) + b Time_{T} - b\phi Time_{T - 1} + \epsilon_{t} \\
 &=\phi y_{T - 1} + a(1 - \phi) + b(T) - b \phi(T)+b\phi(1) + \epsilon_{t} \\
 &=\phi y_{T - 1}+a(1 - \phi) + b\phi+b(1 - \phi)Time + \epsilon_{t}
\end{align}$$
in which case, if $\phi=1$, this becomes $y_{T}=y_{T -1}+b + \epsilon$, which is a random walk plus drift.

so, if our process becomes $AR(3)$:
$$\begin{align}
y_t &= \phi_1 y_{t-1} + \phi_2 y_{t-2} + \phi_3 y_{t-3} + \epsilon_t \\
\end{align}$$
we strategically add terms that cancel out to find the differences:
$$\begin{align}
y_t &= \phi_1 y_{t-1} {\color{aqua} + \phi_2 y_{t-1} - \phi_2 y_{t-1}} + \phi_2 y_{t-2} + \phi_3 y_{t-3} \\
&= (\phi_1 + \phi_2)y_{t-1} - \phi_2(y_{t-1} - y_{t-2}) + \phi_3 y_{t-3} \\

\end{align}$$
repeating the same thing, we can get:
$$\begin{align}
y_t &= (\phi_1 + \phi_2)y_{t-1} - \phi_2 \Delta y_{t-1} + \phi_3 y_{t-3} {\color{aqua} + \phi_3 y_{t-1} - \phi_3 y_{t-1}} {\color{orange} + \phi_3 y_{t-2} - \phi_3 y_{t-2}} \\
&= (\phi_1 + \phi_2 + \phi_3)y_{t-1} - (\phi_3 + \phi_2)(y_{t-1} - y_{t-2}) - \phi_3(y_{t-2} - y_{t-3}) \\
&= (\phi_1 + \phi_2 + \phi_3)y_{t-1} - (\phi_3 + \phi_2)\Delta y_{t-1} - \phi_3 \Delta y_{t-2} \\
\end{align}$$
lastly, by subtracting $y_{t-1}$ from both sides, we obtain our final equation:
$$
\begin{align}

y_t - y_{t-1} &= (\phi_1 + \phi_2 + \phi_3 - 1)y_{t-1} - (\phi_3 + \phi_2)\Delta y_{t-1} - \phi_3 \Delta y_{t-2} \\

\Delta y_t &= (\phi_1 + \phi_2 + \phi_3 - 1)y_{t-1} - (\phi_3 + \phi_2)\Delta y_{t-1} - \phi_3 \Delta y_{t-2}
\end{align}
$$
for this, we can use an augmented Dickey-Fuller (ADF) test, where we need to decide the number of lagged differences to include.
- if it is a pure $AR(p)$ model, we can just augment it with $p$ lags.
- otherwise, if it is $ARMA$, we have to search for which lag value to use.
	- use the auto fit, and set the max value of $p$ to something (like 8) and $q$ to 0
	- once we obtain the optimal $p$, run the ADF test with that many augmentations
