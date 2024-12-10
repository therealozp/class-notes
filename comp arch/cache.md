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
