## power trends
**Moore's Law** and **Dennard Scaling** (reduces supply voltage of new computers to have more power with the same supply of energy): faster, cheaper, lower-power general-purpose computers each year. 

clock rate and power has both been increasing, but we have been working to limit power consumption. these two metrics are **correlated**, so they scale together

power leakage became a major issue, and we reached the practical limit for cooling.
## reducing power
suppose that a new CPU has the below specs. what is the impact on dynamic power?
- 85% capacitive load of old CPU
- 15% voltage and 15% frequency reduction

use $P = C \times V^{2}\times F$
- $C$ is capacitive load
- $V$ is voltage
- $F$ is frequency

## Amdahl's law
states that potential potential performance improvement from a given enhancement is limited by the extent to which the improved feature is utilized. (law of diminishing returns)
$$T_{improved}=\frac{T_{affected}}{\text{improvement factor}} + T_{\text{{unaffected}}}$$
in summary, it is a good way to find the max improvement possible by **improving a particular part of a system**

