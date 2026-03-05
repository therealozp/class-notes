in time series analysis, the underlying assumption is that there is some steady relationship between the variable and time.

so, if we create a variable, call it $time_{t}$ with a value of 1 during the initial observation period (the start of the dataset) and a value of $T$ at the end:

## linear trend
$$y_{t}=\alpha + \beta \text{ Time}_{t} + \epsilon_{t}$$
then, the estimate $\hat{\beta}$ is the **average** change in $y$ from period to period.

## n-degree
for a second-degree model
$$y_{t}=\alpha + \beta_{1} \text{ Time}_{t} + beta_{2} \text{ Time}_{t}^{2} + \epsilon_{t}$$
> in this class, we will eliminate the lower-order terms. so, the equation should boil down to:
$$y_{t}=\alpha + beta_{2} \text{ Time}_{t}^{2} + \epsilon_{t}$$
same applies for cubic models as well, only containing the 3rd degree variable.

higher-order models tend to model data better, but forecasts will generally be less accurate the longer the series is. consider these results from a fitted model:

| models     | AIC    | SBC    | $\bar{R}^2$ | forecast |     |
| ---------- | ------ | ------ | ----------- | -------- | --- |
| linear     | 21.464 | 21.512 | .888        | 387.625  |     |
| 2nd degree | 21.244 | 21.310 | .901        | 399.260  |     |
| 3rd degee  | 20.670 | 20.743 | .949        | 417.731  |     |
## constant growth rate
a typical way of adjusting data is using [[indices and growth rates]]. for example, taking the natural log with give us growth rate:
$$\ln(y_{t})=\alpha+\beta_{1} \text{ Time} + \beta_{2}\text{ Shutdown} +\epsilon_{t}$$
the forecast values on the left will be the growth rate. to get the actual forecast (levels), we need to go through another exponentiation.

note that, this model's information criteria (and $R^{2}$, for that matter) **cannot** necessarily be compared to the ones where the left hand side variable is the levels themselves. so, even with this updated results, we can't say the growth rate models data better than the linear:

| models               | AIC    | SBC    | $\bar{R}^2$ | forecast |     |
| -------------------- | ------ | ------ | ----------- | -------- | --- |
| linear               | 21.464 | 21.512 | .888        | 387.625  |     |
| 2nd degree           | 21.244 | 21.310 | .901        | 399.260  |     |
| 3rd degee            | 20.670 | 20.743 | .949        | 417.731  |     |
| constant growth rate |        |        | .894        | 390.143  |     |
