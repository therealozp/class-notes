## what is performance?
- **algorithms**: determines number of operations executed
- **programming languages, compiler, architecture**: determines number machine instructions executed/operation
- **processor and memory system**: determines how fast instructions are executed
- **IO system (including OS)**: determines how fast IO operations are executed.
### response time and throughput
**response time** (or execution time): how long it takes for a computer to **perform a task**, such as disk access, memory access, IO activities, OS overhead, CPU execution time, etc.

**throughput** (or also bandwidth): number of tasks completed per unit time

### relative performance
$$\text{performance} = \frac{1}{\text{execution time}}$$
when we say *X is N times faster than y*, then:
- performance of X is 5 times **better** than Y
- execution time of X is 5 times **shorter** than Y

### million instructions per second
a measurement of program execution speed based on millions of instructions executed. generally **faster computer = bigger MIPS**

however, MIPs does not account for: 
- differences in ISA
- differences in instruction complexity
that is why MIPS is **not the benchmark of performance,** because the complexity of instructions can be very different. instead, use **CPU time (response time)** for comparison of performance.
$$
\text{MIPS} = \frac{\text{instruction count}}{\text{execution time} \times 10^6}
$$
### measuring execution time
**elapsed time**: the **total** response time, all aspects included. determines system performance. 
**CPU time**: 
- time processing a given job (discounts IO time and other job's shares). 
- comprises user CPU time and system CPU time.
- different programs are differently affected by CPU and system performance.

data transfers: fetching and sending data from and to memory
### CPU clocking
referred to as **clock speed**, to measure how quickly CPU can execute instructions
operation of digital hardware governed by a **constant-rate clock**.

$$
\begin{align}
\text{CPU time} & = \text{CPU clock cycles} \times \text{clock cycle time} \\ &= \frac{\text{CPU clock cycles}}{\text{clock rate}}
\end{align}
$$
performance can be improved by: 
- reducing number of clock cycles
- increasing clock rate
- trade off clock rate and cycle count
### instruction count and CPI (cycles per instruction)
> lower is better
$$\text{clock cycles} = \text{instruction count} \times \text{cycles per instruction}$$
$$\begin{equation}\begin{split}
\text{CPU time} & =  \text{instruction count} \times \text{CPI} \times \text{clock cycle time}\\ & =  \frac{\text{instruction count} \times CPI}{\text{clock rate}}
\end{split}\end{equation}$$

the instruction count for a program is determined by **the program, ISA**, and **compiler.**
the average cycles per instruction (CPI) is: 
- the average number of clock cycles per instruction for a program or a fragment
- **the same** for all instructions from **the same ISA**.

## summary
$$\text{CPU time} = \frac{\text{instructions}}{\text{program}}\times \frac{\text{clock cycles}}{\text{instruction}}\times \frac{\text{seconds}}{\text{clock cycle}}$$
performance depends on: 
- algorithm: affects IC, possibly CPI
- programming language: affects IC and CPI
- compiler: affects IC, CPI
- ISA: affects: IC, CPI, $T_{c}$ (completion time)