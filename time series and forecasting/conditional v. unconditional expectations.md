an [[information set]] $\Omega_{T -1}$ indicates what you know at the end of the period $T-1$, or at the start of period $T$.

$$\Omega_{T-1}=\{ y_{T-1}, y_{T-2}, \dots y_{1}; X_{T - 1}, X_{T-2}, \dots X_{1} \}$$
the conditional expectation of $y_{t}$ is denoted as $E[y_{t}\mid\Omega _{T -1}]$, while the unconditional expectation is denoted $E[y_{t}]$

for white noise, this should be independent, meaning:
- $E(\epsilon_{t}) = E(\epsilon_{t} \mid \Omega_{T-1}) = 0$
- $E[(\epsilon_{t}-\mu)^{2}] = E[(\epsilon_{t}-\mu)^{2}\mid \Omega_{T-1}] = \sigma^{2}$
## distributed log
$(1-L)^{2}=1-2L+L^{2}$, so we can run an infinite order distributed log:
$$\sum^\infty_{i = 0}b_{i}L^{i}$$
### Wold's theorem
let $y_{t}$ be a zero mean, covariance stationary process. $y_{t}$ can be constructed as:
$$y_{t}=B(L)\epsilon_{t}=\sum^{\infty}_{i=0}b_{i}L^{i}\epsilon_{t}$$
where $\epsilon_{t}$ is white noise
### infinite order moving average
conditional and unconditional means and variances of this process:
- unconditional mean is constant:
$$E(y_{t}) = E\left(\sum^{\infty}_{i=0}b_{i}L^{i}\epsilon_{t}\right) = \sum^{\infty}_{i=0}b_{i}L^{i}E(\epsilon_{t}) = 0$$
- conditional mean varies:
$$\begin{align}
E[y_{t} \mid \Omega_{t-1}] &= E\left(   \sum^{\infty}_{i=0}b_{i}L^{i}\epsilon_{t}\mid \Omega _{T-1}\right) \\
& =\sum^{\infty}_{i=0}b_{i}\epsilon_{t}
\end{align}$$

- unconditional variance varies:
$$var(y_{t}) = var\left[ \sum^\infty_{i=0}b_{i}L^i \epsilon_{i}\right]=\sum^\infty_{i=0}b_{i}^{2}\sigma^{2}$$
- conditional variance is constant:
$$var(y_{t}\mid \Omega _{t-1}) = E[(y_{t}-E(y_{t})^{2)}\mid \Omega_{t-1}]=\sigma ^{2}$$
>[!NOTE]
>in practice, a stationary series with cycles can be modeled as a high-order moving average (but it needs a lot of data)

### rational finite distributed logs
$$B(L)=\frac{\Theta(L)}{\Phi(L)}$$
where:
$$\begin{align}
\Theta=\sum^q_{i=0}\theta_{i}L^{i} \\
\Phi=\sum^{p}_{i =0}\phi_{i}L^{i}
\end{align}$$
### approximately rational distributed log
$$B(L)\approx\frac{\Theta(L)}{\Phi(L)}$$
but $p$ and $q$ are small. this is the family of $ARMA(p, q)$ models. an $ARMA(p, q)$ process looks like:
$$y_{t}=B(L)\epsilon_{t}$$
and $$\Phi(L)y_{t}=\Theta(L)\epsilon_{t}$$

