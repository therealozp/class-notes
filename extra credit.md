1. large processor executes 20% of serial and 80% of perfectly parallelizable code. running code with smaller cores (after parallel) is 4x faster. what is the final speedup?

$$\text{Speedup} = \frac{1}{0.2 + \frac{0.8}{4}} = \frac{1}{0.2 + 0.2} = \frac{1}{0.4} = \boxed{2.5}$$

2. same situation, but now we can either: 
	- replace small cores, so now we get 6x speedup in parallelized parts, but consumes 5x more power than previous smaller cores.
	- replace larger core, so we get 4x speedup in parallelized parts in addition to a 7x speedup over the serial code, but consumes 6x the power.
	in this case, which one to use?

option A: replacing small cores
$$\text{Speedup} = \frac{1}{0.2 + \frac{0.8}{6}} = \frac{1}{0.2 + 0.1333} \approx \frac{1}{0.3333} \approx \boxed{3.0}$$
option B: replacing large core means we get the 6x in additional to the existing 4x speedup.
$$\text{Speedup} = \frac{1}{\frac{0.2}{7} + \frac{0.8}{4}} = \frac{1}{0.0286 + 0.2} = \frac{1}{0.2286} \approx \boxed{4.37}$$
so, factoring power into the computation:

| Option      | Speedup | Power | Perf/Watt = Speedup / Power |
| ----------- | ------- | ----- | --------------------------- |
| Small cores | 3.0     | 5×    | 0.60                        |
| Large core  | 4.37    | 6×    | 0.728                       |
so, we should replace the large core for better performance/power speedup.

2. 2GHz processor, 200ns remote memory, 0.2% instructions involving remote access. with a base CPI of 0.5, what is the actual CPI?
Remote memory delay in **cycles**:
$$\frac{200\text{ ns}}{0.5\text{ ns/cycle}} = 400\text{ cycles}$$

So each remote access adds 400 cycles, and they occur in 0.2% of instructions:

$$\text{Added CPI} = 0.002 \times 400 = 0.8$$
$$\text{Actual CPI} = 0.5 + 0.8 = \boxed{1.3}$$

3. you can either redesign the datapath of the processor to reduce the base CPI by 20% or improve the cache design to reduce the remote access time by 20%, which option would you take and why?

option A: redesign datapath
$$\text{New base CPI} = 0.5 \times 0.8 = 0.4$$
$$\text{total CPI} = 0.4 + 0.002 \times 400 = 0.4 + 0.8 = \boxed{1.2}$$
option B: redesign cache
$$\text{new remote delay} = \frac{160}{0.5} = 320 \text{ cycles}$$
$$\text{total CPI} = 0.5 + 0.002 \times 320 = 0.5 + 0.64 = \boxed{1.14}$$
so, we should go with option B to improve the cache performance, which gives us slightly better performance with lower CPI. 