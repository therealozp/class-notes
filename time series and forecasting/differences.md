differences, or also called "lags", just means taking the difference of value from current timestamp versus $x$ number of timestamps ago. for example, first difference:
$$dy_{t}=y_{t}-y_{t-1}$$
if the *dataset period is monthly*, then the monthly difference will be:
$$dy_{t}=y_{t}-y_{t-1}$$
and quarterly:
$$dy_{t}=y_{t}-y_{t-4}$$
and annually (also called the annual difference or seasonal differences):
$$dy_{t}=y_{t}-y_{t-12}$$
>[!ERROR] note
>when we annually difference the dependent variables, we also have to **difference the dummy variables** as well (except for time variables, or seasonal variables)
## forecasting
in the differences model, we are forecasting the differences., so, essentially, we are forecasting $\hat{dy}_{t+h}$. to convert them into actual values, we have to add them to whatever real value we had before. or, in formulaic form:
$$\hat{y}_{t+h}=ad \hat{y}_{t+h}+y_{t+h-12}$$
the number 12 is not fixed - we are taking the annual difference in this case.
