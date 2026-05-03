suppose we process the regression 
$$y_{t} = \alpha+\beta X_{t} + \epsilon_{t}$$
for this to make sense under the traditional regression assumptions, both $X$ and $y$ will have to be stationary.

in 1974, Granger and Newbold generated two random walks $y_{t}=y_{t-1}+\epsilon_{yt}$ and $x_{t} = x_{t - 1} + \epsilon_{xt}$, where both $\epsilon_{t}$'s are white noise and uncorrelated.

after estimating the regression a bunch of times, nearly 75% of the time, the null hypothesis $\beta=0$ is rejected, and often the $R^2$ score is high.

this is usually referred to as a **spurious regression** that shows a relationship that does not exist. 

OLS regression results usually falls into one of 4 possibilities:
1. both $X_{t}$ and $y_{t}$ are stationary, regular results hold, and ordinary interpretation is correct.
2. if they are integrated at different orders $I(1)$ and $I(0)$, results won't mean anything.
3. if both are $I(1)$ (or any $I(d)$ for that matter), and the residuals of the regression also follow an $I(d)$ integrated series, these results are meaningless. this is a **spurious regression**.
4. both are integrated at the same order (almost always $I(1)$) and the residuals from the regression are $I(0)$ stationary, we have what Engle and Granger calls **cointegration**.

to illustrate, we can use the consumption-smoothing (permanent income hypothesis) as an example:
- $C_{t}$ is the current consumption
- $y_{t}^{p}$ is the permanent income
- $C_{t}'$ is the current transitory consumption

$C_{t}$ and $y_{t}^{p}$ are $I(1)$, so not stationary. $C_{t}'$ is stationary. the formula for the permanent income hypothesis says that $C_{t} = \beta y_{t}^{p} + C_{t}'$. even though both the independent variables are $I(1)$, the dependent variable is stationary $I(0)$. so, we conclude that both $C_{t}$ and $y_{t}^{p}$ is cointegrated.

## cointegration
when two variables are cointegrated, the OLS estimator is **super consistent**, and the estimate $\beta$ can be interpreted in the standard way.

to test for cointegration:
1. test both $X_{t}$ and $y_{t}$ to see if they are both $I(1)$. use the correct unit root test for this (Dickey-Fuller test)
2. if both are $I(1)$, run the regression. save the residuals of the regression
3. if the error terms are $I(0)$, variables are cointegrated. otherwise, it is a spurious regression.

if we find cointegration, we need to represent their relationship in an **error correction model (ECM)**.
$$
\Delta y_{t} = \underbrace{a + b_{1} \Delta x_{t}}_{\text{short term}} + \underbrace{b_{2} (e_{t-1})}_{\substack{\text{error} \\ \text{correction} \\ \text{term}}} + \nu_{t}
$$
where $\nu_{t}\sim WN(\dots)$.
