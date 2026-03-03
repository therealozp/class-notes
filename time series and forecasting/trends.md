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

