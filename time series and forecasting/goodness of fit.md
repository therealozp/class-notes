### adjusted R squared
can be measured using the $R^2$ criteria, or the adjusted $\bar R^2$. adjusted $R^{2}$ will always be smaller than $R^2$. for the $R^2$, larger is better (models data better)
$$R^{2}=1 - \frac{MSE}{\sigma^{2}}$$
adjusted $R^2$ has no asymptotic properties.
### information criteria
alternatively, an **information criteria (IC)** is also used to measure how well the model performs. information criteria adjusts the sum of squared residuals by the sample size and the degrees of freedom lost (or the number of things we are estimating). the two main ICs we typically use:

- Akaike IC
$$\text{AIC} = \frac{\exp\left( \frac{2K}{T} \right)}{T}\sum^T_{i}e_{i}^2=e^{\frac{2K}{T}}\times MSE$$
- Schwartz (Bayes) IC 
$$SIC=\frac{T^{\frac{K}{T}}}{T}\sum^T_{i}e_{i}^2=T^{\frac{K}{T}}\times MSE$$
## consistency
a model selection criterion $IC$ is consistent if and only if:
- when the correct model (also called the *data generating process*, or dgp) is among the models we are comparing, the chance that $IC$ chooses the correct model approaches $100\%$ as $T$ (number of timestamps) gets larger
- when the true dgp is **not** among the models we are estimating, the possibility of choosing the **best estimation** $100\%$ as $T$ gets larger

SBC is consistent.
## asymptotic efficiency
as our model becomes more complicated, the variance of the error terms **goes down**. an IC-based selection process is efficient if this variance shrinks the fastest.

AIC is asymptotically efficient.

>[!NOTE]
when there is a split decision, the class default is SIC. AIC may be used, but the justification should be because it is asymptotically efficient.