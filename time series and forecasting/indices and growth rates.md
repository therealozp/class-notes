## indices and growth rates
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
a series that is not [[stationarity|covariance stationary]] can **sometimes** be made stationary by taking the log. this does **not** work with the mean, though!

for constant growth rate series, we can use logs.