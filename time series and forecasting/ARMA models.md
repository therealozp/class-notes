simple models such as linear, quadratic, growth rates, etc. usually have residuals (error terms) that contain cycles. most of what we have covered don't have white-noise residuals.

now, we try to approach modelling the cycles. one of the biggest things is using the Box-Jenkins model approach to univariate (single variable) time series.
## $ARMA(p, q)$ models
the $AR(p)$ component is **autoregressive** (see [[AR models]]), and $MA(q)$ stands for moving average (see [[MA models]]). 

the $ARMA(p, q)$ uses both components to make the prediction, so take an $ARMA(2, 2)$ for example:
$$\begin{align}
y_{t}=\phi_{1}y_{t - 1} + \phi_{2}y_{t - 2} + \epsilon_{t} + \theta_{1}\epsilon_{t - 1} + \theta_{2}\epsilon_{t - 2}
\end{align}$$
so, shuffling the terms around, we can get:
$$\begin{align}
& y_{t} - \phi_{1}y_{t - 1} -  \phi_{2}y_{t - 2 }=\epsilon_{t} + \theta_{1}\epsilon_{t - 1} + \theta_{2}\epsilon_{t - 2} \\
\implies &(1 - \phi_{1}L - \phi_{2}L^{2})y_{t} = (1 + \theta_{1}L + \theta_{2}L^{2})\epsilon_{t} \\
\implies &y_{t} = \frac{1 + \theta_{1}L + \theta_{2}L^{2}}{1 - \phi_{1}L - \phi_{2}L^{2}}\epsilon_{t}
\end{align}$$ 
## mixed models
let's assume that our model consists of a trend and seasonality. so:
$$y_{t} = \sum_{i = 1}^{12}\sigma_{i}\text{month}_{i} + \beta_{1}\text{time}_{t} + \beta_{2}\text{time}_{t}^{2} + \epsilon_{t}$$
now, suppose that even after running the regression, we still notice trends in the residuals $\epsilon_{T}$. so, let's continue modelling that with an $ARMA(3, 3)$ model:
$$\epsilon_{t} = \frac{1 + \theta_{1}L + \theta_{2}L^{2}+\theta_{3}L^{3}}{1 - \phi_{1}L - \phi_{2}L^{2} - \phi_{3}L^{3}}\gamma_{t}$$
## forecasting
when forecasting with regression models, there could be the classic regression forecast, and the conditional forecast:
$$y_{t + h}\mid X^{*}_{T+h} = \hat{\beta}_{0} + \hat{\beta}_{1}X^{*}_{T+h}$$
where $X^{*}_{T+h}$ is the assumed value of $X$ at the time $T+h$

generally, there are 4 sources of forecast errors:
- specification uncertainty (model might not be correctly specified)
- innovative uncertainty (the error term)
- parameter uncertainty (did not get the params $\beta$'s correct), which goes away as $T$ get's bigger
- $X^{*}_{T+h} \neq X_{T + h}$, meaning the assumption about the values was wrong. this wasn't a problem in the trend and regression models, because we are able to compute the conditional mean.
### if our assumption is correct
consider the error $y_{T+h}- \hat{y}_{T+h}$, where the forecast does not have a constant. then assuming the assumed value for $X$ is correct:
$$\begin{align}
\hat{e}_{T+h} &= \beta_{1}X_{T+h}+ \epsilon_{T+h} - \hat{\beta_{1}}X^{*}_{T+h} \\
&= (\beta-\hat{\beta})X^{*}_{T+h} + \epsilon_{T+h}
\end{align}$$
then, the variance of the residuals are:
$$\begin{align}
var(\hat{e}_{T+h}) = var(\hat{\beta})X^{*}_{T+h} + var(\epsilon_{T+h})
\end{align}$$
the variance of $\hat{\beta}$ approaches 0 as T gets bigger, but while T does not reach that point:
$$\text{var}(\hat{e}_{T+h}) = \underbrace{\frac{\sigma^2 X_{T+h}^{*2}}{\sum_{i=1}^{T} X_i^2}}_{\text{parameter uncertainty}} + \underbrace{\sigma^2}_{\text{innovative uncertainty}}$$
### if we just don't know
if we don't know the value of $X^{*}_{T+h}$, a possible option is to replace it with a forecast. suppose we are trying to forecast the next period, then:
$$y_{T + 1}= \beta X_{T + 1} + \epsilon_{T + 1}$$
then, one possible forecast of $X_{T+ 1}$ can be $X_{T}$. in this case, our dependent variable will be lagged by 1:
$$y_{t}= \beta X_{t - 1} + \epsilon_{t}\iff y_{T + 1}\mid \Omega_{T} = \hat{\beta}X_{T}$$
if instead of only 1 lag value, we throw in a bunch of different X's and the constant $\beta_{0}$ back in the mix, we can estimate $y_{t}$:
$$y_{t} = \beta_{0} + \sum_{i = 1}^{Nx}\sigma_{i}X_{t - i}+\epsilon_{t}$$
known as a [[lag operator#distributed lag|distributed lag]]. the $\sigma_{i}$ variables are the lag weights, and the pattern of the $\sigma_{i}$'s are referred to as their distribution. each lagged X will cost a degree of freedom.

for a rational distributed lag:
$$y_{t}=\frac{A(L)}{B(L)}X_{t}+\epsilon_{t}$$
then, this would be a distributed lag with both lagged dependent and an independent variables.

take an example where we have 1 lagged variable, and the prior term is $AR(1)$. assuming $\epsilon_{t}$ is not white noise, then we can model $\epsilon_{t}=\phi \epsilon_{t-1}+\gamma_{t}$ where $\gamma_{t}$ is white noise. then, we can write:
$$\begin{align}
&y_{t} = \sigma X_{t - 1}+\frac{\gamma_{t}}{1- \phi L} \\
\implies &(1- \phi L)y_{t}= \sigma(1 - \phi L)X_{t - 1} + \gamma_{t} \\
\implies &y_{t} = \phi y_{t - 1}+ \sigma X_{t - 1}+ \sigma X_{t - 2} + \gamma_{t}
\end{align}$$

