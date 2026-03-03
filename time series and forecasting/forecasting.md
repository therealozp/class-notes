to see which model predicts best, we can look at the forecast errors:
- $\hat{y_{t+h}}$: forecast of $h$ periods ahead
- $y_{t+h}$: actual value of $h$ periods ahead
- $e_{t +h}=y_{t+h}-\hat{y_{t+h}}$

suppose 3 different models $a, b, c$ are ran:
$$e_{t+h}^{a}=y_{t+h}-\hat{y}_{t+h}^{a}$$$$e_{t+h}^{b}=y_{t+h}-\hat{y}_{t+h}^{b}$$$$e_{t+h}^{c}=y_{t+h}-\hat{y}_{t+h}^{c}$$

| model | $e_{1}$ | $e_{2}$ | $e_{3}$ | $\sum e$ | $\sum \frac{e^{2}}{3}$ | $\sum \frac{\lvert e \rvert}{3}$ |
| ----- | ------- | ------- | ------- | -------- | ---------------------- | -------------------------------- |
| a     | 50      | -70     | 20      | 0        | 2600                   | 46.6                             |
| b     | 5       | 35      | -40     | 0        | 950                    | 26.6                             |
| c     | 12      | -9      | 10      | 14       | 102.6                  | 10                               |

$c$ generally performs the best, across the MSE and MAE metrics, so any selection criterion has to choose model $c$. not all model that has smallest MSE will also have smallest MAE.

## in-sample forecasting
cut off data at a certain point (truncation), and use the remaining data to fit a model. then, we can use that fitted model to forecast the observation of the dependent variable that we cut off