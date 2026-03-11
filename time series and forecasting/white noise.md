the error terms $\epsilon_{t}$ are white noise if: 
$$\epsilon_{t} \sim N(0, \sigma^2)$$
and
$$E[\epsilon_{t}, \epsilon_{t -\tau}] = 0 \ \forall \tau \neq 0$$

in other words, the errors need to have zero mean, constant variance, be uncorrelated across time, and normally distributed. the statistics version also enforces an identical, independently distributed (iid) constraint to the normal distribution.

an obvious visual test for white noise is that the ACFs and PACFs immediately go to zero, and just stays there:

![[Pasted image 20260303222632.png]]

but sometimes, this is not immediately clear.

## statistical tests
### sample autocorrelations
$$\hat{\rho}(\tau)=\frac{\sum_{t=1+\tau}(y_{t}-\bar{y})(y_{t - \tau}-\bar{y})}{\sum_{t=1}(y_{t}-\bar{y})^2}$$
then, the variance can be calculated with:
$$var(\hat{\rho}(\tau))=\frac{1}{T}\left[ 1+2\sum_{j\neq 1}^{T}\hat{\rho}^2(j) \right]$$
if we have white noise (normal, iid), then the distribution of sample autocorrelations $\hat{\rho}(\tau)\sim N\left( 0, \frac{1}{T} \right)\iff \sqrt{T }\hat{\rho}(T) \sim N(0, 1)$

squaring both sides, we get $T \hat{\rho}(\tau)^{2}\sim \mathcal{X}^2$. 
statistics tell us that if we have $m$ variables $\sim \mathcal{X}_{1}^2$, then their sums $\sim \mathcal{X}_{m}^{2}$ (chi-squared with $m$ d.o.f.)

### Box-Pierce Q statistic
usually only works with really big samples
$$Q_{BP}=T\sum^{m}_{\tau=1}\hat{\rho}(\tau)^{2} \sim \mathcal{X}^{2}_{m}$$
under the null hypothesis of white noise. meaning, if p-value $< 0.05$, we reject that it follows white noise, indicating there is some degree of autocorrelation.
### Ljung-Box Q statistic
$$Q_{LB}=\frac{T\times 2}{T-\tau}Q_{BP} \sim \mathcal{X}^{2}_{m }$$
under the null hypothesis of white noise. meaning, if p-value $< 0.05$, we reject that it follows white noise, indicating there is some degree of autocorrelation.

so, we have to choose the $m$ carefully. 
- $m$ too big $\to$ no longer a good chi-squared approximation
- $m$ too small $\to$ we lose power of the test

in practice, we would typically choose $m=\sqrt{ T }$