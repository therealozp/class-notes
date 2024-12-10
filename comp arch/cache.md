- **block** or line: the minimum unit of information that can be present or absent. also understood as a group of addresses.
- **hit rate**: percentage of memory accesses found in a level in a hierarchy.
- **miss rate**: percentage of access **NOT** found.
- **hit time**: time taken to access a level of memory hierarchy, including time needed to determine whether access is hit or miss
- **miss penalty:** time required to
	- fetch a block from the a lower level
	- access the block
	- transmit from one level to another
	- inserting it in upper level
	- passing block to requestor

so, **cache memory** is the level in hierarchy **closest to the CPU**.
### direct-mapped cache
a structure where **each memory location is mapped to exactly one location in cache**.

this is naturally dependent on the cache capacity and number of bits used to address memory blocks and index cache blocks. number of blocks are usually placed as power of 2 for easy binary addresses.

the location is determined by address of the current location, and determined by: $$\text{block address} \mod \text{num blocks in cache}$$
in binary, we take the lower $n$ number of bits of the block address, where $n$ is the number of bits required to index cache.

**valid bit**: a field in the table of a memory hierarchy that indicates that the associated block contains valid data.

**tag**: a field in the table that **contains the address information** required to identify whether the associated block corresponds to a requested word. used to *identify the cache*.

so, when is cache hit?
- store block address and data
- actually, we only need the **higher-order bits** of the block address, called the **tag index**.
what if no data?
- valid bit: 1 = present, 0 = not present
- initially 0

the tag is compared against the **upper portion of the address** to determine if the entry loaded in the cache is actually the address we are looking for.

suppose that:
- $N$ bits are used for the virtual address
- $K$ bits are reserved for tag field.
- $M$ bits for the block index inside cache

for example, if the cache size is 1024B, and a physical address length of 32 bits:
- 10 bits are used for the indexing ($M = 10$ )
- suppose that 2 bits are used as the offset bit
 
 the number of bits inside tag $K$ will be $32 - 10 - 2 = 20$.

so, if the tag bit inside the cache and the upper 20 bits of the block address are the same (and of course valid bit on), then it is a cache hit.

## block size
- due to spatial locality, **larger blocks reduce miss rates**.
- however, in a fixed-sized cache:
	- making blocks larger means fewer blocks. fewer blocks means more competition for into blocks. more competition means increased miss rates.
	- larger blocks lead to more pollution
- larger block sizes also lead to larger miss penalties.
	- overrides the benefit of reduced miss rates
	- early restart and critical-word-first can help (LRU)

as mentioned before, a cache miss means that the requested data is not present in the cache. so:
- on a cache hit: the CPU proceeds normally
- on cache miss:
	- stall the CPU pipeline
	- fetch block from lower hierarchy level
	- if it is **instruction cache miss**: restart instruction fetch
	- if it is **data cache miss**: complete the data access.

## writing
occurs when we need to update memory blocks (e.g. writing to a word doc)
### write through
updates both upper and lower levels at the same time. simplifies replacement, but might need a write buffer.

on a **data-write hit**, we *could* just update the block inside cache, but:
- cache and memory becomes inconsistent
- write takes longer

so, a solution would be to hold another temporary variable called a write buffer, which: 
- holds data waiting to be written to memory
- after writing to buffer, CPU continues immediately without stall. we will only stall on write if the buffer is full.

on a **data-write miss**, there are two options we can go:
- allocate on miss: fetch the block
- write-around: don't fetch the block; since programs often writes a whole block before even reading it (e.g. on initialization)
### write-back
instead of keeping track of which is which, we keep a note of whether each block inside the cache is "dirty" (affected by write operation.)

when a dirty block is then replaced (for example, by a cache capacity exceed):
- we write that dirty block from memory
- we can also use a write buffer to allow the incoming replacement to be read first.

on a write miss: we just fetch the block to memory and write it back.

## associative caches
### fully associative
basically a hashmap (set) of block addresses. this means a block can be placed **anywhere** without limitation.

one downside to fully associative is the overhead. because we need to look through every 
## set associative
combines the speed of fully associative and mapping effectiveness of direct-mapped.

spectrum of associativity:
- for an $n$-way set associative cache, there are $n$ blocks per set.
- a fully associative cache has 1 set.
- a direct-mapped cache is a 1-way set associative with 1 block per set and $n$ sets, where $n$ is the number of blocks.

the spectrum of associativity states that:
- the total size of cache (in terms of blocks) = number of sets $\times$ associativity (associativity meaning $n$-way)
- so, for a fixed cache size, increasing the associativity **decreases** number of sets; while **increasing number of elements per set**.

## cache organization
to determine a matching, the cache organization has **comparators** to determine which elements **inside of a set** matches the tag.

the output of comparators is used to select data from one of the blocks inside a set, using a multiplexor with a decode select signal.

alternatively, instead of a MUX, in some implementations, we also have **output enable signals** on the data portions of cache RAMs; which can be used to select the cache entry inside set that drives the output.

output enables signals come from the comparators, causing element that matches to drive the data outputs. 

## block placement
determined entirely by associativity. 
- in a DMC (1-way associative): exactly one choice for placement
- $n$-way set associative: $n$ choices (for each block) within set
- fully associative: any location
high associativity reduces miss rate, but also increases complexity and cost (because of the higher need for comparators) and access time (due to having to search)
### finding the block

| associativity           | location method                           | tag comparisons   |
| ----------------------- | ----------------------------------------- | ----------------- |
| direct mapped           | index                                     | 1                 |
| $n$-way set associative | set index, then search entries within set | $n$               |
| fully associative       | search all entries                        | number of entries |
|                         | lookup table                              | 0                 |

## trade-offs

| design change          | effect on miss rate        | negative impact on performance                                                                                          |
| ---------------------- | -------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| increasing cache size  | decrease capacity misses   | increase access time                                                                                                    |
| increase associativity | decrease conflict misses   | may increase access time                                                                                                |
| increase block size    | decrease compulsory misses | increases the miss penalty. for caches with a very large block size, this may also increase miss rate due to pollution  |
- **compulsory miss**: aka cold-start miss, occurs when the first time block is accessed. since the block size is larger, it allows a bigger range of information to be selected.
- **capacity miss**: the replaced block is later accessed again; occurs due to a finite cache size
- **conflict miss**: when a bunch of different blocks compete for an entry inside a set. this doesn't occur in a fully associative cache with the same capacity because it is one big set.