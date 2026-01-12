1. model is linear:
univariate model: 
$$y_{i} = X_{i}\beta + \epsilon_{i}$$
multi-variate model: 
$$y_{i} = X_{1}\beta_{1} + X_{2}\beta_{2} + X_{3}\beta_{3} + \dots + \epsilon_{i}$$
2. expected value of error term is 0 $E[\epsilon_{i} | X] = 0$
3. variance of error term is the std. dev $Var(\epsilon_{i}) = \sigma^2$
4. unrelated error terms $Cov(\epsilon_{i} ,\epsilon_{j} = 0)$
5. $X$ is non-stochastic

given 1-5 is true, the OLS estimator is BLUE (best linear unbiased estimator)

an unbiased estimator $\hat{\beta}$ of $\beta$ means $E(\hat{\beta}) = \beta$

## variance - covariance matrix
$$\begin{bmatrix}
\epsilon_{1}^2 & \epsilon_{2}\epsilon_{1} & \epsilon_{3}\epsilon_{1} & \epsilon_{4}\epsilon_{1} \\
\dots\end{bmatrix}$$

## heteroskedasticity
$$\begin{bmatrix}
\sigma_{1}^{2} & 0 & 0 & 0 \\
0 & \sigma_{2}^{2} & 0 & 0 \\
0 & 0 & \sigma_{3}^{2} & 0 \\
0 & 0 & 0 & \sigma_{4}^{2} \end{bmatrix}$$
where $\sigma_{i} \neq \sigma_{j}$.
## serial correlation
if there is a serial correlation, then all the terms inside the std dev matrix are no longer zero. instead: 
$$\begin{bmatrix}
\sigma_{1}^{2} & \sigma_{21} & \sigma_{31} & \sigma_{41} \\
\sigma_{12} & \sigma_{2}^{2} & \sigma_{32} & \sigma_{42} \\
\sigma_{13} & \sigma_{23} & \sigma_{3}^{2} & \sigma_{43} \\
\sigma_{14} & \sigma_{24} & \sigma_{34} & \sigma_{4}^{2} \end{bmatrix}$$

if **any** of these $\sigma_{ij} \neq 0$, we have a serial correlation. the Durlin-Wattson test checks if $\sigma_{i, i-1}$ is non-zero (does not depend on previous term).

in the one-time data gathering scheme, the order matters. here, the period term $i$ will run from $\{ 1, \dots, T \}$. so:
- $y_{1}$ will be the oldest observation
- $y_{T}$ will be the most recent observation

in a univariate model $y_{i}=X_{i}\beta+\epsilon_{i}$: 
- run the regression and get the estimated $\hat{\beta}$. 
- forecast (or fitted value) $\hat{y}=X_{i}\hat \beta$
- forecast error (or residual) $\hat\epsilon_{i} = y_{i} - \hat{y_{i}}$
- the typical notation for this will be $e_{i}=\epsilon_{i}$

