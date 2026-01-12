## mean
**mean** (also called expected value):
- $\mu=E[X]$
- sample mean $\frac{1}{N}\sum_{i=1}^{N} X_{i}$

## variance
- $\sigma^2=E[(X-\mu)^2]$ 
- sample variance $\sigma^{2}=\frac{1}{T}\sum_{i=1}^{T} (x_{i}-\bar{x})$. we don't typically use this formulation, because it is already biased (we already estimated this)
the **unbiased** sample variance are usually obtained by:
- $S^{2}= \frac{1}{T -1}\sum_{i=1}^{T} (x_{i}-\bar{x})$
and we use the standard deviation:
- $\hat{\sigma}=\sqrt{ \hat{\sigma}^2}$
- $\hat{S}=\sqrt{ \hat{S}^2}$

## skewness
the third moment, standardized (divided by the std.dev)
$$\mathcal{S}= \frac{E[(X-\mu)^3]}{\sigma}$$

- in a symmetric distribution, the skewness is 0. 
- in a right-hand skewed distribution, skewness $\mathcal{S} > 0$
- in a left-hand skewed distribution, skewness $\mathcal{S} < 0$

the estimate is calculated by:
$$\mathcal{S} = \frac{1}{T}\sum_{i=1}^{T} \frac{(x_{i}-\bar{x})^3}{\sigma}$$
## kurtosis
$$K=\frac{E[(X-\mu)^4]}{\sigma^4}$$
for all norm dists, $K=3$

## tests for normality
Jarque-Bera test
$$JB = \frac{T}{6}\left( \hat{\mathcal{S}} + \frac{1}{4}(\hat{K}-3)^2 \right)\approx\mathcal{X}^2$$
