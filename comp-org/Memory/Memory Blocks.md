Consists of two main parts: 
- Block Addresses
- Offset: (location index within the block)

**Format**: [Block Address | Offset]

Example: For a system with a *maximum capacity* of 2GB, with a *block size* of 32B. Assuming that everything is **byte-addressable**:
- The number of addresses is: 
	- 2GB = $2^{31}$B.
	- For a system of $2^n$ bytes, the **number of bits of the address** of the system is $n$. So, this system address has **31 bits**
	- With the block size of $32 = 2^5$ B, we will need **5 offset bits** for each block.

To determine the: 
- **number of cache blocks**: get the (cache capacity / block size)
