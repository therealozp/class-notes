smoothing is mechanical. it does not require any deep modelling or statistical techniques, and doesn't produce the theoretically optimal forecast either.

the theoretic optimal is not always the model that forecast the best.

smoothing allows us to draw a smooth curve through the data, and use the curve to forecast. it usually work with small samples (large samples won't even improve the forecasts). 
$$\begin{align}
\{ y_{t} \}^{T}_{1} &\text{ : original series} \\
\{ \bar{y}_{t} \}^{T}_{t}&\text{ : smoothed series}
\end{align}$$
1. one-sided moving average:
$$\bar{y}_{t}=\frac{1}{m+1}\sum_{i = 0}^{m}y_{t - i}$$
for example, if $m=2$, then the value $y_{t}$ would be the average of the values $y_{t} +  y_{t - 1}+y_{t -2}$. 

2. two-sided moving average
$$\bar{y}_{t}=\frac{1}{2m+1}\sum_{i = 0}^{m}y_{t - i} + y_{t + i}$$
so, if $m = 3$, then we would sum everything from $y_{t-3}$ to $y_{t+3}$, and divide everything by 7.

3. weighted moving average
a WMA is almost always one-sided. the sums of all the weights need to be equal to 1.
$$\bar{y}_{t}=\sum_{i = 0}^{m}w_{i}y_{t - i}$$
4. exponential smoothing
then, setting $\bar{y}_{1}$, we then update to get future values of the series with the formula:
$$\bar{y}_{2} = \alpha y_{2}+(1-\alpha)\bar{y}_{1}$$
where the value of $\alpha \in (0, 1)$. this is called exponential smoothing because the effects of an outlier die out by $(1-\alpha)^{n}$ as we go $n$ periods ahead into the future.

as mentioned before, smoothing of any kind will not give the statistically theoretical optimal forecast, but there is an exception. if there exists a series such that:
$$C_{0,t} = C_{0, t-1} + \eta_{t},\quad \eta_{t}\sim WN(0, \sigma_{\eta}^2)$$
and you observe that $y_{t}=C_{0, t}+\epsilon_{t}$, where $\epsilon_{t}\sim WN(0, \sigma^{2})$, and the covariance of $\eta_{t}, \epsilon_{t} = 0$, and the errors are not correlated over time, then the exponential smoothing model produces the optimal forecast.

when forecasting with the exponential smoothing model, the forecast for $y_{T+h}$, for any period of $h$, is $\bar{y_{T}}$.

