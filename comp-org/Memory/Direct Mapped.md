#memory 

- **Block**: unit of data transfer between cache and memory
- **Direct Mapped Cache**: 
	- A block can be placed in exactly one location in the cache
	- (Block Address) % (no. of blocks in cache)
	- For each memory block, th[]()ere is only **one** location in cache where it can map to.
	- Will also need a **valid bit**

![[Pasted image 20231106125739.png]]

Each block in the cache memory will have a **tag field** when using the direct mapping strategy, as both block address (0-indexed) 2 and 6 will be mapped to the same cache block for a 4 block cache system. So, the tag field is a **unique identifier for each block address**, based on the **bits that exceed the number of cache blocks**.

For example, in the above system, block 5 will be mapped to **cache block 01**, with a **tag field** of **1**.

**Example:** 
32 B ($2^5$) of main memory, 4B ($2^2$) of cache memory. 
So, the number of bits indexing for **cache is 2 bits**, and for main memory, it uses **5 bits of indexing**. Then, there will be 3 bits in the tag field, and the offset will be 5. 
## Cache Miss
The operating system will look for the data **inside the cache block**, and then **checks the tag field.** If they are both same as expected, then its a hit. Else, it's a miss.

[11001] -> 
- (tag field) [1]
- (cache block) [10]
- (offset) [01]
## Cache Hit
Will always miss on the first run, but for subsequent runs, check for: 
- Same cache block
- Same tag field
## Procedure
- Memory cap $\Rightarrow$ Memory address number of bits
- Cache cap
- Blocks size $\Rightarrow$ Offset

From the last two, we can derive: 
- number of blocks in cache
- number of bits in the block index.
### Comparator
For each block of cache memory, we only need 1 single comparator to determine if it's a cache hit or a cache miss. Due to the lookup nature of direct mapping, we only need to check if it's the same offset, tag index, and valid bit.
