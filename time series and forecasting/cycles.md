we have seen these before with sine waves, musical notes, etc. but we are looking for something different. seasonality is an example, and we can say that **seasonal data displays cycles**.

think of cycles as some dynamic that is not captured by [[seasonality]]. **cycles require persistence**, i.e. the present is related to the past (and thus the future is related to the present)

$\implies$ cycles are ordered sets of observations, in this class, it's time. it can also be spatial, ordered by distance.

the phrase "sample path" might sometimes be used. the data generating process (DGP) is the underlying model driving the realizations. when working with cycles, there is a 3-step process:
1. methods of characterizing cycles (identification processes)
2. modelling cycles (build a model + estimate it)
3. forecast of cycles (use the fitted model to make forecasts)

### forecasting
forecasting cycles will rely on the [[information set]]. the goal is to find the optimal forecast, conditional on what we know.

as per [[loss functions]], the best forecast was the one that minimized expected loss. for most commonly used losses, the **conditional mean** minimizes expected loss. for a linear mode, the conditional mean is a linear combination of things in our information set $\Omega_{T}$.

for a $MA(2)$ model, $$y_{T} = \epsilon_{T} + \theta_{1}\epsilon_{1}+\theta_{2}\epsilon_{2}$$
the prediction of $y_{T+1}$ based on this is:
$$
\begin{align}
P(y_{T+1}\mid \Omega_{T})&=E(y_{T+1}\mid \Omega_{T}) \\
&=E(\epsilon_{T+1}\mid\Omega_{T}) + \theta_{1}E(\epsilon_{T}\mid\Omega_{T}) + \theta_{2}E(\epsilon_{T - 1}\mid\Omega_{T}) \\
&=0 + \theta_{1}\epsilon_{T} + \theta_{2}\epsilon_{T - 1}
\end{align}
$$
