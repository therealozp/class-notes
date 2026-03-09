define a lag operator $L$. then, $Ly=y_{t-1}$, and $L^2y_{t}=y_{t-2}$

the first differences can be written in terms of the lag operator as: $$(1-L)y_{t}=y_{t}-y_{t-1}$$so, if we define a polynomial in the lag operator:
$$B(L)=\sum^{n}_{i=1}b_{i}L^{i}=b_{0}+b_{1}L+b_{2}L^{2}+\dots+b_{n}L^n$$
then we can write something like: $B(L)=1+0.6L - 0.3L^{2}+0.2L^{3}$, and $B(L)y_{t}=y_{t}+0.6y_{t-1} - 0.3y_{t-2}+0.2y_{t-3}$
