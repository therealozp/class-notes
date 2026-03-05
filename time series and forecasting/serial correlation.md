time series data often has serial correlation with prior error terms. so, testing for first order serial correlation (error terms of today correlates with terms of yesterday)
$$E[e_{i}e_{i - 1}] \neq 0$$
also measured by the Durbon-Watson (DW) statistic:
$$\begin{align}
\frac{\sum_{t=2}^{T}(\epsilon_{t} - \epsilon_{t - 1})^{2}}{\sum^{T}_{t=1}e_{t }^{2}}
\end{align}$$
if there is no serial correlation, the **DW statistic = 2**. after expanding the equation and calculating the expected value.

when running a regression, we can find a formula for errors: $$e_{t} = \phi e_{t -1} + v_{t}$$if $v_{t}$ is noise, then the coefficient $\phi$ determines if there is serial correlation. if $\phi = 0$, there is no serial correlation.