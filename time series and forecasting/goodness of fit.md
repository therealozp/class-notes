can be measured using the $R^2$ criteria, or the adjusted $\bar R^2$. adjusted $R^{2}$ will always be smaller than $R^2$. for the $R^2$, larger is better (models data better)

### information criteria
alternatively, an **information criteria (IC)** is also used to measure how well the model performs. two main ICs
- Akaike IC
$$\text{AIC} = \frac{\exp\left( \frac{2K}{T} \right)}{T}\sum^T_{i}e_{i}^2$$
- Schwartz (Bayes) IC 
$$SIC=\frac{T^{\frac{K}{T}}}{T}\sum^T_{i}e_{i}^2$$

RATS command: `@regcrits`

time series data often has serial correlation with prior error terms. so, testing for first order serial correlation (error terms of today correlates with terms of yesterday)
$$E[e_{i}e_{i - 1}] \neq 0$$
also measured by the Durbon-Watson (DW) statistic

index is the value today relative to the value at a particular time
$$\text{index} = \frac{\text{value at time }t}{\text{value at base}}\times 100$$
