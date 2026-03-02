can be measured using the $R^2$ criteria, or the adjusted $\bar R^2$. adjusted $R^{2}$ will always be smaller than $R^2$. for the $R^2$, larger is better (models data better)

### information criteria
alternatively, an **information criteria (IC)** is also used to measure how well the model performs. two main ICs
- Akaike IC
$$\text{AIC} = \frac{\exp\left( \frac{2K}{T} \right)}{T}\sum^T_{i}e_{i}^2$$
- Schwartz (Bayes) IC 
$$SIC=\frac{T^{\frac{K}{T}}}{T}\sum^T_{i}e_{i}^2$$

time series data often has serial correlation with prior error terms. so, testing for first order serial correlation (error terms of today correlates with terms of yesterday)
$$E[e_{i}e_{i - 1}] \neq 0$$
also measured by the Durbon-Watson (DW) statistic:
$$\begin{align}
\frac{\sum_{t=2}^{T}(\epsilon_{t} - \epsilon_{t - 1})^{2}}{\sum^{T}_{t=1}e_{t }^{2}}
\end{align}$$
if there is no serial correlation, the **DW statistic = 2**. after expanding the equation and calculating the expected value.

when running a regression, we can find a formula for errors: $$e_{t} = \phi e_{t -1} + v_{t}$$
if $v_{t}$ is noise, then the coefficient $\phi$ determines if there is serial correlation. if $\phi = 0$, there is no serial correlation.

index is the value today relative to the value at a particular time
$$\text{index} = \frac{\text{value at time }t}{\text{value at base}}\times 100$$
we also need to consider which time periods we need are looking at. growth rate of $x$ from period to period:
$$grx=\frac{{x_{t} - x_{t -1}}}{x_{t - 1}}$$
so, if our dataset is monthly, but we want to calculate annual difference, then:
$$grx=\frac{{x_{t} - x_{t -12}}}{x_{t - 12}}$$
or quarterly:
$$grx=\frac{{x_{t} - x_{t -4}}}{x_{t - 4}}$$
## rule of logs
we can also take the natural log $\ln$ of the values, which approximates growth rate well:
$$\ln(x_{t}) - \ln (x_{t - 1})\approx \frac{{x_{t} - x_{t - 1}}}{x_{t}}$$
another use case:
$$q_{x}=aP_{x}^{b}P_{y}^{c}P_{z}^{c}I^{e} \iff \ln(q_{x}) =\ln a + b\ln P_{x}+c\ln P_{y}+d\ln P_{z}+e\ln I$$
a series that is not covariance stationary can **sometimes** be made stationary by taking the log. this does **not** work with the mean, though!

for constant growth rate series, we can use logs.