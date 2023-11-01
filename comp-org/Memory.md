## Hierarchical Memory Organization
- Registers
	- Typical size < 1KB
	- Access time < 0.5ns
- Cache (faster memory than main). Cares about **access speed** and **capacity**
	- **L1 Cache** (8-64KB): 1ns access time
	- **L2 Cache** (512KB - 8MB): 3-10ns access time
- Main memory: 
	- 50-100ns access time
- Hard drive (**slowest**), can go up to **10ms** access time.

![[Pasted image 20231101132623.png]]


Virtual Memory: takes hard drive space and allocates as RAM
## Read-only-memory (ROM)
- Does not need to be refreshed
- Used to store permanent / semi-permanent data that persists even when the system is turned off.
## Random-access-memory (RAM)
Also has two big types.
- Has large array of storage cells, but is **volatile** (only holds data as long it has power)
- Random access: access time is practically the same to any data on a RAM chip. 
- **Output** Enable $\rightarrow$ **read**, **Input** enable $\rightarrow$ **write.**

$2^n \times m$ RAM chip: stores $n$ bit addresses and $m$-bit data.
#### Static RAM: 
- SRAM is very fast and does not need to be refreshed like DRAM. Used to build **cache** memory.
- Fast access time, but also very expensive.
- 6-8 transistors per bit.
- Uses a CMOS structure.
#### DRAM (main memory)
- Slow, cheap, and dense memory. 
- One transistor + capacitor per bit. Bit is stored as a **charge.**
- Must be **rewritten** after being read and must be **periodically refreshed.**
- Typical choice for main memory. 

DRAM has a refresh cycles of *tens of milliseconds*, and done for the **entire memory.**

![[Pasted image 20231101124856.png]]

When accessing memory, we used in RISC-V:

```
lw t1, 0(a0)
OR 
sw t1, 0(a0)
```

which, for the `word` datatype, has 4 bytes = 32 bits of memory. This means that the data bus will hold **32 data lines.**

## Cache Memory
- The **speed gap** between CPU and main memory. 
	- Processor operation: 1ns
	- Memory access takes more than 50ns.
- Each instruction involves at least one memory access: 
	- One memory access to fetch the instruction
	- A second memory access for load and store instructions
- Memory bandwidth limits instruction execution rate

$\Rightarrow$ *Cache memory can bridge this gap.*

### Principle of Locality of Reference
- Programs access **small portion** of their address space.

- **Temporal locality**: 
	- If an item is accessed, it will *probably* be accessed again soon
	- Same loop insts. are fetched each iteration
	- Same procedures may be called and executed many times. 

- **Spatial locality**:
	- Tendency to access contiguous instructions/data in memory
	- Sequential execution of instructions
	- Traversing array element by element

## The Miss Penalty
On average, when a **cache miss** occurs, memory from RAM will be accessed and copy into cache. So, in this case, the **miss penalty** will be that reading time + cache accessing time. So about 50ns + 2s. 