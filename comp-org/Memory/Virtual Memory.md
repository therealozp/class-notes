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

## TLB: The buffer
Will store a portion of the page table in the cache for speed-up of memory access time. Will have **near immediate** look-up time for the page table, and then move to the **page table** (in main memory) to continue looking. 

Data stored in the TLB will have the format: [ Frame Number | Page Number ]

When determining data availability in the TLB, we only look for the **page number** component, and from there we can read the **frame** of the memory stored inside the cache. 

Then, we can divide further into the above cases in [[#Procedure]]. 

![[Pasted image 20231115132115.png]]

Case 1: TLB hit and Cache hit: 4ns (for reading TLB and read data from cache)

Case 2: TLB hit and Cache miss: 54ns for **non-overlapping** (no parallel reading), and 52ns for *overlapping (parallel reading)*
- 2ns from TLB hit
- Uses the **miss penalty** to determine the time: 
	- 50ns to **copy** from main memory (or 50ns to *read* from main memory in a **non-overlapping** system)
	- 2ns to read from cache again

Case 3: TLB Miss + Page Fault does not occur + Cache hit: 52ns
- TLB Miss: assuming 0 time
- Reading from page table: 50ns
- Cache hit: 2ns

Case 4: TLB Miss + Page fault does not occur + Cache Miss: 102ns
- TLB Miss: assuming 0 time
- Reading from page table: 50ns
- Cache miss, so have to copy from main memory to cache: 50ns
- Read data from cache: 2ns

Case 5: TLB Miss + Page Fault occurs: 10ms
- TLB Miss: assuming 0 time
- Page Table reading: 50ns
- Missing, so copy from hard drive: 10ms
- Copy back from main memory: 50ns
- Read data from cache: 2ns

