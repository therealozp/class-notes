we have seen these before with sine waves, musical notes, etc. but we are looking for something different. seasonality is an example, and we can say that **seasonal data displays cycles**.

think of cycles as some dynamic that is not captured by [[seasonality]]. **cycles require persistence**, i.e. the present is related to the past (and thus the future is related to the present)

$\implies$ cycles are ordered sets of observations, in this class, it's time. it can also be spatial, ordered by distance.

the phrase "sample path" might sometimes be used. the data generating process (DGP) is the underlying model driving the realizations. when working with cycles, there is a 3-step process:
1. methods of characterizing cycles (identification processes)
2. modelling cycles (build a model + estimate it)
3. forecast of cycles (use the fitted model to make forecasts)