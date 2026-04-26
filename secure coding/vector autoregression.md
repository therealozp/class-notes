another special, but quite often used case is the vector autoregression $VAR(n, p)$, where $n$ is the number of variables and $p$ is the number of lags. if only one parameter is specified, then it is just $VAR(p)$.

for a 2-variable $VAR(1)$ model, we can assume $y_{1}$ and $y_{2}$ are variables. then:
$$
\begin{align}
y_{1t}=\alpha_{1}+\phi_{11}y_{1, t - 1} + \phi_{12}y_{2, t-1} + \epsilon_{1, t}\\
y_{2t}=\alpha_{2}+\phi_{21}y_{1, t - 1} + \phi_{22}y_{2, t-1} + \epsilon_{2, t}
\end{align}
$$
in this case, we may or may not want a constant. sometimes it helps, sometimes it doesn't.

vector autoregressions forecasts really well when the variables are correlated with each other and themselves across time. to tell, we usually look at the cross-correlations:
$$\frac{cov(x_{t}, y_{t - i})}{cov(x_{t}, y_{t})} \quad\text{where } i\geq 1$$
so, when the cross-correlations are different from 0, $VAR$ is a good option.

## causality
when X provides useful information when forecasting Y, when we can say that X has predictive causality for Y. in terms of the $VAR$ models, we say that at least one of the $\phi^{i}_{xy} \neq 0$ significantly.

we can also use the F-test of $\phi^{1}_{xy} = \phi^{2}_{xy} = \dots = 0$, which really tests this.

### Granger causality
$X$ is said to "Granger cause" $y$ if $X$ has predictive causality for $y$, **but not vice-versa**. if the reverse also happens to be true, then this is also referred to as Granger "feedback". feedback is very common to see.

## impulse response functions
an advantage of VAR allows the calculation of impulse response functions (IRFs), which show the effect of a one-standard-deviation shock today on the variable and related variable in the future.

### univariate case
we can only apply this if the data is covariance stationary.

if $y_{t}$ is covariance stationary, then by Wold, we can express $y_{t}$ as an infinite order moving average:
$$y_{t} = b_{0}\epsilon_{0} + b_{1}\epsilon_{1}+\dots$$
in the prior [[lag operator#Wold's theorem|Wold's decomposition]], we normalized $b_{0} = 1$, but we don't do that here. then, our error terms will be white noise: $\epsilon_{t} \sim WN(0, \sigma^{2})$.

then, with a little bit of math, we can express these terms as:
$$y_{t} = b_{0}m\left( \frac{\epsilon_{0}}{m} \right) + b_{1}m(\frac{\epsilon_{1}}{m})+\dots$$
then, $y_{t}=b_{0}'\epsilon_{t}'$, where $b_{i}'= b_{i}m$ and $\epsilon_{t}' = \frac{\epsilon_{t}}{m}$, and $\epsilon_{t}'\sim WN\left( 0, \frac{\sigma^{2}}{m^{2}} \right)$. if we set $m = \sigma$, then $\epsilon_{t}' \sim WN(0, 1)$. in this case, the estimated $b_{i}'$ shows the effect of the 1-standard deviation shock, and the $\{ b_{0}', b_{1}',\dots , b'_{n} \}$ is the impulse response function.

## forecasting
similar to all models, we can look at the forecast errors to estimate the forecast. there are 4 properties  you want for $e_{T+h, T}$:
1. $E(e_{T+h, T})=0$ (unbiased)
2. one period ahead forecast error to be white noise
3. 2-period ahead forecast should either be $MA(1)$ or white noise. by extension, $h$-period ahead forecast should either be $MA(h - 1)$ or white noise.
4. optimal forecasts have forecasts errors whose variances grow in $h$, and converges to the variance of the process.

often times, multiple forecast models will satisfy these 4 conditions. how then, do we determine the optimal? then, we can look at the mean squared error (MSE) or RMSE, mean absolute error (MAE), or percent forecast error (PFE) and MSPFE.

suppose that we have 2 models, $a$ and $b$, and their respective forecasts $\hat{y}^{a}_{T+h, T}$ and $\hat{y}^{b}_{T+h, T}$. then, we can obtain the forecasts by combining the two:
$$y_{T+h} = \beta_{a}\hat{y}^{a}_{T+h, T} + \beta_{b}\hat{y}^{b}_{T+h, T} + \epsilon_{T+h}$$
if $a$ encompasses $b$, then $\beta_{a}= 1$ and $\beta_{b} = 0$. if $b$ encompasses $a$, then $\beta_{b} = 1$ and $\beta_{a} = 0$. 

if neither one encompasses the other, we can assign weights to combine them:
$$y_{T+h} = w\hat{y}^{a}_{T+h, T} + (1 - w)\hat{y}^{b}_{T+h, T}$$
there does exist a theoretically optimal $w$, but typically, we can run a regression
$$y_{T+h} = \beta_{0}+ \beta_{1}\hat{y}^{a}_{T+h, T} + \beta_{2}\hat{y}^{b}_{T+h, T} + \epsilon_{T+h}$$
and hope that $\beta_{0}=0$ and $\beta_{1}+\beta_{2} = 1$.