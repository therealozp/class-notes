at boot:
- BIOS finds a storage device and loads the first sector
- **bootloader** loads the kernel from disk to a location in memory and then jump to it
- OS boot initializes services and drivers
- Init: launches an application that waits for input in the input loop
## principle of locality
a program always access a small proportion of its address space at any given time.
### temporal locality
- when a data location is referenced, they tend to be referenced again soon (a program access the same location multiple times)
- frequently-accessed items should go near the CPU (higher in the hierarchy) e.g. instructions occurring in the loop

### spatial locality
- when a location in mem is referenced, nearby addresses tend to be addressed as well.
- basis for preloading data that is close (a block) to other recently-accessed data (sequential instruction access, arrays)

the end goal of working on memory is to have one big chunk of cache, but that is impossible due to price. however, to mitigate this, we can take advantage of the memory hierarchy and locality:
- store everything on a hard disk (HDD/SSD)
- copy recently accessed blocks of items from disk to smaller capacity DRAM (main memory)
- copy **even more recently accessed** blocks of items from DRAM to smaller SRAM (cache memory)
### memory hierarchy
generally, the higher up a memory stage (or the closer it is to the processor), the memory unit will be **smaller, faster, and more expensive**.

if accessed data is present in upper level $\to$ hit (access satisfied)
if accessed data is absent $\to$ miss:
- a block (unit of copying that may contain multiple memory words) will be copied from lower level
- time taken is called the **miss penalty**
- accessed data supplied from the upper level

by replacing the big chunk of cache with this more manageable hierarchy, it gives the illusion that it is still fast while still keeping costs low.
## SRAM
stands for **static random access memory**. 
- these are integrated circuits that are memory arrays, uses 6-8 transistors per bit prevent corruption. 
- usually has a **single-access** port that indicates **read or write**.
- has a fixed access time to any piece of information, but read/write times may differ.
- **does not need to refresh**, so access time is close to clock cycle time.

there used to be separate SRAM chips, but now they are all integrated into the processor.
## DRAM
stands for **dynamic random access memory**.
- uses a **single transistor** to access the charge.
- must be periodically refreshed.

bits inside a DRAM are organized as *rectangular arrays*, so that means:
- DRAM is accessed as an entire row. refreshing operations happen at a row level. **burst mode** supply successive words on a row with low latency.
- double data rate (DDR): twice as much bandwidth based on clock rate and data width
- quad data rate (QDR) takes this even further and has separate DDR for inputs and outputs.

this almost tabular organization has several unique features that increases bandwidth and make memory accesses fast:
- row buffering allows several words to be read and refreshed, all in parallel
- **synchronous DRAM** allows for consecutive accesses in burst, without needing to go over each individual address. 
- **DRAM banking** allows simultaneous access to multiple DRAMs at a time.
## flash memory
NOR flash: a bit cell like a NOR gate. used for random access and instruction memory in embedded system.

NAND flash: bit cell like a NAND gate. these are generally denser, but only allows access a block at a time. much cheaper.

flash bits wear out after thousands of accesses, so it is not suitable for RAM or disk replacement. instead, we can **spread out usage** with *wear levelling*, remapping data to less-used blocks.


block size: number of addresses per block
set size or associativity: number of sets inside cache

in superscalar, can you have less than the required packet size per execution cycle?
no, but stall in-cycle so that both WB end at the same time.
