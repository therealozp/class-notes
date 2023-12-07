
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

## Block placement & identification
Three main schemes of placement and identification:
### [[Direct Mapped]]

### [[Fully Associative]]

### [[Set Associative]]

## Memory Write
### Write through
- Updates cache AND lower-level memory
- Cache-control bit: only 1 valid bit needed. 
- Memory always have **latest-data**.
- Can always discard cached data when cache is replaced
- Can be improved with a buffer
### Write-back
- Write updates **into cache only**
- Cache control: **valid** bit and **modified** bit
- **Modified** cache will be rewritten to memory when replaced
- **Multiple writes** to the **same** cache block will only need to be written **once** to memory
- Uses less memory bandwidth $\rightarrow$ less power