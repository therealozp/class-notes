sometimes, data follows a seasonal pattern, it could be holidays, weather, or maybe some event-specific thing like spring break, workday/weekends

to check for seasonality, we essentially set a bunch of seasonal variables for each "season." so, for a monthly cycle, perhaps a regression could look like:
$$\begin{align}
y_{t}=\beta_{1}\text{Jan} + \beta_{2}\text{Feb} + \beta_{3}\text{Mar} +\dots+\beta_{12}\text{Dec} + \epsilon_{t}
\end{align}$$

for models with seasonal data, the $R^{2}$ is useful. the centered and uncentered $R^2$ are two viable metrics:

$$\text{uncentered }R^{2}=1 - \frac{\sum^{T}_{i = 1}e_{i}^{2}}{\sum^{T}_{i = 1}(y_{i} - \bar{y})^2}$$
$$\text{centered }R^{2}=1 - \frac{\sum^{T}_{i = 1}e_{i}^{2}}{\sum^{T}_{i = 1}y_{i}^2}$$
note that if the sample mean $\bar{y}=0$, centered and uncentered $R^2$ are equal. the rule of thumb is:
- $R^{2}< 0.1$: no real evidence of seasonality
- $0.1\leq R^{2}< 0.25$: there's no seasonal effects, in the sense that fluctuations happening every period. but, you might have one or two cases where they are different - in that case, look at the coefficients
- $0.25\leq R^{2}< 0.5$: reasonable evidence of seasonality, take a closer look
- $0.5\leq R^{2} < 0.75$: probably worth modelling seasonality
- $0.75 \leq R^{2}$: almost guaranteed to have seasonality

if only the seasonal regression is ran, the forecasts are simply the coefficients. for example, in the case of yearly data, this year's forecast is equal to next year's forecast, and the next next year, etc.

however, if there is also a trend, then the forecast will be coefficient + effect of the trend. for example, in a dataset where:
- Dec 2016 is 204th datapoint $\implies$ May 2017 is 209th
- $\hat\beta_{time}=-149.54$
- 112,259 is the May coefficient

then, the forecast would be: $$\hat{y}_{2017:05}=112,259-149.54 \times 209 = 81,005$$