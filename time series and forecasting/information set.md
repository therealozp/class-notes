an information set $\Omega_{T}$ is the things you know at time $T$, including what is happening right now + what has happened in the past. it can also include **some future things** you know now (like how many weekend days there are in a future month)
$$\Omega_{T}=\{ y_{T}, y_{T-1}, \dots y_{1}; X_{T}, X_{T-1}, \dots X_{1} \}$$
since we have $y$ and $X$, we can also find the error terms $e_{t}$:
$$\Omega_{T}=\{e_{T}, e_{T-1}, \dots, e_{1}\}$$
we can have future $X$'s in $\Omega_{T}$, but **never** $y$'s and $e$'s.

## cycles
we've seen these before with sine waves, musical notes, etc. but we are looking for something different. seasonality is an example, and we can say that **seasonal data displays cycles**.

think of cycles as some dynamic that is not captured by [[seasonality]]. **cycles require persistence**, i.e. the present is related to the past (and thus the future is related to the present)

$\implies$ cycles are ordered sets of observations, in this class, it's time. it can also be spatial, ordered by distance.

the phrase "sample path" might sometimes be used. the data generating process (DGP) is the underlying model driving the realizations. when working with cycles, there is a 3-step process:
1. methods of characterizing cycles (identification processes)
2. modelling cycles (build a model + estimate it)
3. forecast of cycles (use the fitted model to make forecasts)

we have some requirements on realization (data series) that must be met to work with cycles, primarily that **data must be stable**
stability in this case is covariance stationary, or second-order stationary
1. mean must be stable over time (1st order)
$$E(y_{t})=\mu \ \forall t$$
the mean must be constant, we cannot have $E(y_{t})=\mu_{t}$ where $\mu_{t}\neq \mu_{t-h}$

2. variance/covariance structure has to be stable over time
	- first part of this assumption being true is $\sigma^{2}<\infty$
	- second part involves **autocorrelations**