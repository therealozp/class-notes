the idea behind paging is splitting the address space into different **pages** of fixed size. compare this to segmentation, where logical segments (code, heap, stack) can have variable sizes.

physical is also split into page (frames), where the page table **per process** is needed to map virtual pages to physical frames. this yields two main advantages:
- memory can be managed flexibly. we don't need to know how heap and stack grows, nor do we need to know how it is used.
- memory management is simple, because the *page in address space* and the *page frame* are the **same size**, which makes it easy to allocate and maintain a free list.

a page table entry (PTE) usually consists of the following:
- valid bit: if the translation is valid
- protection bit: indicating rwx (read, write, execute) permissions
- present bit: if page table is in memory or on disk
- dirty bit: if the entry is modified since the time it is brought into memory
- accessed bit: self explanatory due to the name
### address translation
the address in general consists of two components: the page/frame number, and the offset (within the page). the hardware is able to translate the virtual page number (VPN) into a physical frame address.
### where is it stored?
there are many different ways we can store pages. the simplest form it can take is a **linear page table**, or an array. the drawback to this is page tables can grow *very large*. for a system with a 32-bit address space and 4KB pages:
-  $4KB = 2^{2} \times 2^{10}B$, which means 12 bits are reserved for the offset.
-  32 - 12 = 20 bits are reserved for the virtual page number.
- 4MB = $2^{20}$ entries, with 4 bytes per entry

the page table **for each process** is stored on memory. so, to find the location of any given PTE, the OS needs to find the **starting location** of said page table. so, for every memory reference the OS needs to make an extra reference.

## translation look-aside buffer (TLB)
aside from the page table residing in the main memory, we employ a secondary unit of caching, called the TLB. the TLB resides exclusively in cache memory close to the CPU, and is a hardware cache of the popular (frequently accessed) virtual-to-physical address translation.

TLB takes advantage of the spatial and temporal locality to amortize memory access cost. the process is as follows:
- CPU requests the virtual address
- looks up request in TLB
	- if TLB hit, we have the immediate physical translation. 
	- if TLB miss, we access the page table to find our data.

### considerations
#### miss handling
a hardware-managed TLB relies on the MMU to handle misses. 

a software-managed TLB generates an OS trap, which looks up the page table and loads translation into the TLB before resuming execution.
#### context switching
on a process switch, we can either discard the cache and **flush the TLB** (simple but more costly), or tag the data inside the TLB with some sort of process ID to ensure its validity.
#### sharing pages
we use **shared memory pages**, mapped to multiple address spaces. this is especially useful for standard libraries or common shared libraries (`*.dll`, `*.so`) as the OS only needs to manage one instance of it instead of needing to replicate it.
#### replacement policy
optimally, we want to replace the one that will not be used in the near future. however, there are no more oracles, so it is impossible for us to know this.

a second option is using LRU, which is very close to optimal, but has immense overhead.

in these cases, random replacement yields "good-enough" performance for little to no overhead. 

### memory optimizations
linear tables are mostly empty spaces. to reduce this overhead, we have several options:
#### paging + segmentation hybrid
attempts to reduce memory overhead of page tables by adding segmentation to the mix. so, instead of having one big page table for the entire process, each **segment** (e.g. the code, stack, heap) has its own page table.
- so, each process has three page tables for each logical segment.
- the **base** register does not hold the segment, but instead the segment's page table's **physical address**.
- bounds registers can be used to indicate the end of the page table.

this solution works, but for large and sparsely-used heaps, there can still be a lot of resource waste.
#### multi-level page tables
instead of using a linear page table, why not make it a tree? 

the main ideas are:
- split page table into page-sized units
- if entire page of page table entries is invalid, don't allocate it. so, the portions that we allocate can be very dynamic.

so, we can break it down to multiple levels. an abstract way is to make page tables point to one another, but in the page table entry, we can **break the virtual address into multiple parts**. for example, consider a two-level page table. the virtual address in this case would include:
- a **page directory** index: points to a page table
- a **page table index**: points to a page frame in memory
- offset within the page

then, our page directory can hold multiple "pointers" to different page tables, instead of having one massive linear table. 

if a process ever only use a small portion of its virtual address space, this approach ensures that only the necessary page tables are allocated. thus, we save overhead while still making sure that our process has enough space to grow.
## swap memory
another small part on the hard disk, reserved for the OS to swap pages into when the memory eventually hits capacity. this allows the OS to maintain its lies of having infinite virtual memory for multiple concurrently running processes.

when the memory reaches capacity, the OS moves pages to swap to make room for new pages. of course, the OS will not wait until the memory is full to begin swapping, because this can create **deadlocks**. instead, it always keep some small portion of memory free, and does this very proactively.
 
**page fault** occurs when a page is needed, but is not on memory. then, the OS needs to go back into the hard disk, copies the required page to memory, and then copy that page to the TLB.
### replacement policy
similar to the TLB, we also have to consider the page replacement policies of swap, such as LRU and random replacement.

LRU is very expensive, because it needs to keep some sort of timestamp or access history, which is more actions then realistically needed. instead, we use a more practical approach, such as the **clock algorithm**.

the OS keeps some metadata, in the form of **use bit** and the **dirty bit**.
- **use** is set to 1 when page is accessed
- **dirty** is set to 1 when the page is modified. evicting a clean page is free, because we don't have to write it back to the disk, which costs another memory write/hard disk access.

 the **clock algorithm** is an efficient **approximation** using a circular list.
1. arrange pages in a circular list (like a clock)
2. a hand (pointer) moves around the circle, checking pages one by one.
3. if the **use bit** of a page is **0**, evict the page.
4. if the **use bit** is **1**, clear it (set to 0) and move the hand to the next page.
5. repeat until a page with **Use bit = 0** is found and evicted.

### thrashing
in modern PCs, the demands of the set of running processes simply exceeds the available physical memory, which keeps the OS consistently paging. 

instead, we can either limit the number of jobs to run less jobs, or kill memory intensive jobs entirely.