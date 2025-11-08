to resolve issues with setup time violations, reduce the frequency of the circuit
for hold time violations, add a buffer in between (to add more delay)

domain parameters: publicly published params that are available to anyone. attackers, even with access to these parameters, cannot attack your scheme.

$$
\begin{equation} \tag{12}
\left\{
\begin{aligned}
S'_{0,c} = & (\{02\}_{16}(S_{0,c} + S_{1,c}) + (S_{2,c} + S_{3,c}) + S_{1,c}) \\
         & + (\{02\}_{16}(\{04\}_{16}(S_{0,c} + S_{2,c}) \\
         &+ \{04\}_{16}(S_{1,c} + S_{3,c})) + \{04\}_{16}(S_{0,c} + S_{2,c})) \\
S'_{1,c} = & (\{02\}_{16}(S_{1,c} + S_{2,c}) + (S_{3,c} + S_{0,c}) + S_{2,c}) \\
         & + (\{02\}_{16}(\{04\}_{16}(S_{0,c} + S_{2,c}) \\
         & + \{04\}_{16}(S_{1,c} + S_{3,c})) + \{04\}_{16}(S_{1,c} + S_{3,c})) \\
S'_{2,c} = & (\{02\}_{16}(S_{2,c} + S_{3,c}) + (S_{0,c} + S_{1,c}) + S_{3,c}) \\
         & + (\{02\}_{16}(\{04\}_{16}(S_{0,c} + S_{2,c}) \\
         & + \{04\}_{16}(S_{1,c} + S_{3,c})) + \{04\}_{16}(S_{0,c} + S_{2,c})) \\
S'_{3,c} = & (\{02\}_{16}(S_{3,c} + S_{0,c}) + (S_{1,c} + S_{2,c}) + S_{0,c}) \\
         & + (\{02\}_{16}(\{04\}_{16}(S_{0,c} + S_{2,c}) \\
         & + \{04\}_{16}(S_{1,c} + S_{3,c})) + \{04\}_{16}(S_{1,c} + S_{3,c}))
\end{aligned}
\right.
\end{equation}
$$