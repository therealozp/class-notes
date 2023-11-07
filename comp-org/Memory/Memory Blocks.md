Consists of two main parts: 
- Block Addresses
- Offset: (location index within the block)

**Format**: [Block Address | Offset]

Example: For a system with a *maximum capacity* of 2GB, with a *block size* of 32B. Assuming that everything is **byte-addressable**:
- The number of addresses is: 
	- 2GB = $2^{31}$B.
	- For a system of $2^n$ bytes, the **number of bits of the address** of the system is $n$. So, this system address has **31B**
	- With the block size of $32 = 2^5$ B, we will need **5 offset bits** for each block.
## Direct Mapping
- **Block**: unit of data transfer between cache and memory
- **Direct Mapped Cache**: 
	- A block can be placed in exactly one location in the cache
	- (Block Address) % (no. of blocks in cache)
	
![[Pasted image 20231106125739.png]]

Each block in the cache memory will have a **tag field** when using the direct mapping strategy, as both block address (0-indexed) 2 and 6 will be mapped to the same cache block for a 4 block cache system. So, the tag field is a **unique identifier for each block address**, based on the **bits that exceed the number of cache blocks**.

For example, in the above system, block 5 will be mapped to **cache block 01**, with a **tag field** of **1**.
## Cache Miss
The operating system will look for the data **inside the cache block**, and then **checks the tag field.** If they are both same as expected, then its a hit. Else, it's a miss.

[11001] -> 
- (tag field) [1]
- (cache block) [10]
- (offset) [01]

## Procedure
- Memory cap $\Rightarrow$ Memory address number of bits
- Cache cap
- Blocks size $\Rightarrow$ Offset

From the last two, we can derive: 
- number of blocks in cache
- number of bits in the block index.

## Cache Hit
