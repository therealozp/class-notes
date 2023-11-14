## Procedure
Data will be on the virtual memory initially, but **CPU does not read from anywhere else other than cache**. And cache does not read anywhere else other than the main memory. Therefore: 

- On a cache hit, the data is already available on the cache. 
- On cache miss, there is one of two things that can happen: 
	- A page fault occurs: **page fault** happens when requested block of data is **not present** on the main memory, but is available on the **virtual memory**. Therefore, that block of data must be copied from the virtual memory into main. 
	- A page fault does not occur: meaning data **is available** on the main memory, and does not need an extra step of querying.
## The page table
Maintaining information on the location of each page, whether on disk or memory. The **page size** defines the number of bits in the **offset**, and the **number of page** determines the number of bits for the **page number**. 

So, a 8-page table with a 2KB page size will have 3 + 11 = 14 bits for indexing.

## Effective access time
Computes the average access time when there is a percent rate of page fault. So: 

 > EAT = (1 - page fault rate) x 2 x main memory access time + page fault rate x page fault penalty
 
Even if there is not page faults, the EAT would still need to read the memory twice: first to read the access the page table, and second to access the page from memory. 

 
 