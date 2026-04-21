an [[information set]] $\Omega_{T -1}$ indicates what you know at the end of the period $T-1$, or at the start of period $T$.

$$\Omega_{T-1}=\{ y_{T-1}, y_{T-2}, \dots y_{1}; X_{T - 1}, X_{T-2}, \dots X_{1} \}$$
the conditional expectation of $y_{t}$ is denoted as $E[y_{t}\mid\Omega _{T -1}]$, while the unconditional expectation is denoted $E[y_{t}]$

for white noise, this should be independent, meaning:
- $E(\epsilon_{t}) = E(\epsilon_{t} \mid \Omega_{T-1}) = 0$
- $E[(\epsilon_{t}-\mu)^{2}] = E[(\epsilon_{t}-\mu)^{2}\mid \Omega_{T-1}] = \sigma^{2}$