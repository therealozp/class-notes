hard disks have been the main form of persistence for decades.
- the drive consists of a large number of sectors (512-byte blocks)
- we can view the disk with $n$ sectors as an **array of sectors**, indexed from 0 to $n - 1$

due to how sectors are structured, the only guarantee when writing data to disk is that **a single 512B write is atomic.** multi-sector operations are possible:
- many filesystems will read/write at 4KB at a time.
- because of this atomicity, if there is power loss, only a portion of a larger write may be complete.

**contiguous access** is the fastest. this means everything is sequential, and it is much faster than any random access pattern.

### geometry
hard disks consists of a bunch of **platters**, aluminum disks with a thin magnetic layer. each side of the platter is called a surface. data is stored persistently by inducing magnetic charges wherever relevant.

the **spindle** is connected to a motor that spins the entire set of platters around. the **tracks** are the concentric **circles of sectors** on the surface, containing up to thousands of tracks.

to read and write, the **disk head** is used. it is attached to an arm that glides across the surface. 

measuring the time taken to read/write involves computing some sort of delay, so the **rotational delay** measures time for the desired sector to be reached. note that the disk can only ever spin one way, so on the other side of the head, it would take $R - 1$ timesteps to reach a "previous" sector. 
### multiple tracks
for multiple tracks, the head usually will have to seek, while the disks spin to reach the correct location. 

**seeking** means moving the arm to the correct track, and is one of the costliest disk operations. seeking is broken into 4 phases:
- **acceleration**: the disk arm gets moving
- **coasting**: disk arm moves at full speed
- **deceleration**: arm slows down
- **settling**: head is *carefully positioned* over the correct track. usually the slowest part, settling time is quite significant (0.5 to 2ms)

**transfer** is the last phase in IO, where data is read from or written to the surface. then, the complete IO time consists of:
- seeking
- waiting for rotational delays
- tranfer

### track skew
supposing that we have a disk where the different sectors all line up with each other. in this case, if all of the tracks have sectors immediately "next" to each other on different tracks. moving the arm can risk overshooting or undershooting the actual sector.

so, this makes sure that sequential reads can be done properly even when crossing track boundaries.

### track buffer (cache)
holds data read from or written to the disk. allows the drive to quickly respond, and only borrow a very little set of memory (8-16MB)

two main ways to update the cache:
- **write-back**: a write is marked successful when there is confirmation that the requested block is put in data memory. this is faster, but dangerous because of data loss
- **write through**: actually admitting the write has been completed after the write has actually been written to disk.

## IO time
$$T_{\text{I/O}} = T_{\text{seek}}+T_{\text{rotation}} + T_{\text{transfer}}$$
and IO rate:
$$R_{\text{I/O}} = \frac{\text{Size}_{transfer}}{T_{\text{I/O}}}$$
because of the contiguous nature of sectors on disks, the random workloads are far slower than the sequential workloads.
## disk scheduling
decides on which IO request to do next.

### shortest seek time first (SSTF)
produces the order of IO request by track, and pick whichever is at the nearest track to complete first.

because the disk only ever rotates one way, we can consider this situation where a request is issued for sector 16 and sector 8:

![[Pasted image 20250502102613.png]]

note that 16 is already well past 30, and it would need a full rotation to access 16. however, if rotation is faster than seek, then we would sacrifice that rotation and just go the full way, while the arm is still seeking to the second track.

if seek is much faster than rotation, we should schedule 8 to be access first, because we can hop 2 tracks while the disk is still rotation to put where 8 is.

## RAID
stands for Redundant Array of Inexpensive Disks, which uses **multiple disks** to build a bigger, faster, and more reliable disk system. to the OS, RAID just looks like one big disk.

due to using multiple disks, we get the added benefit of:
- **performance**: because we are accessing/writing stuff in parallel
- **capacity**: for obvious reasons
- **reliability**: RAID can tolerate loss of disks.

### interface
when RAID receives an IO request, a few things must be done:
1. calculates which disk to actually access
2. issues one or more physical IOs to do so

for example, in a mirrored RAID system where two copies of each block are kept on separate disks, RAID needs to perform **two physical IOs** for every one logical IO issued.

RAID consists of:
- a microcontroller to run firmware to direct RAID operations
- volatile memory (DRAM) for buffering data blocks
- non-volatile memory for safe writes (disks)
- specialized logic to perform parity calculation

RAIDs are designed to detect and recover from certain kinds of disks faults with the **fail-stop** model.
- a disk can be in a *working* or a *failed* state.
	- working means all blocks can be read from or written to
	- failed means a disk is **permanently** lost.
all of the housekeeping is done by the RAID controller, which immediately knows when a disk has failed. 
### considerations
to evaluate a RAID system, we evaluate it on three things: capacity, reliability, and performance.

we also take into consider some performance metrics:
- single request latency: time taken to complete a single IO operation, which is important for interactive systems.
- steady-state throughput: how much data the system can handle under sustained workloads. measures ability to handle high-bandwidth tasks like backup, video streaming, or database systems.

workloads can either be **sequential**, or **random**. for the sake of argument, let's assume that a disk can transfer data at $S$ MB/s under sequential load, and $R$ MB/s under random load.

take the following example:
- 10MB average transfer load
- 10KB average random load
- seek time: 7ms
- rotational delay: 3ms
- disk transfer rate: 50MB/s

then, the time to access a sequential load is: $\frac{10}{50}\times 1000 + 7 + 3 = 210ms$
time to access a random load is: $\frac{10}{50} + 7 + 3 = 10.2ms$

then, $S=\frac{10MB}{210ms} = 47.62MB/s$
$R=\frac{10KB}{10.2ms} = 0.981MB/s$

so, we could clearly see why random loads are much, much slower.

#### RAID 0: striping
RAID 0 is the simplest form of RAID, where all blocks are just **striped**, meaning that blocks are spread across disks in a **round-robin** fasion.

due to this, there is no redundancy in RAID 0, but excellent performance and capacity.

![[Pasted image 20250502104558.png]]

each stripe make up a "contiguous" set of blocks. so, if each **chunk** (one unit in the RAID system) consists of 2 blocks, a stripe can consist of 4 chunks of 8 blocks.

the chunk size is the biggest factor to the array performance.
- if **smaller chunks**: better parallelism, because blocks are more spread out. however, this comes at a cost of positioning time across all disks to access blocks.
- if **bigger chunks**: intra-file parallelism is reduced, but it also reduces the positioning time. 

in terms of:
- **capacity**: RAID 0 is perfect, because all N disks are usable (useful capacity)
- **performance**: RAID 0 is excellent because of perfect striping, so all disks are utilized in parallel.
- **reliability**: RAID 0 is bad, because any disk failure will lead to data loss.
- **single request latency**: identical to that of a single disk
- **steady-state throughput**:
	- sequential workload: $N\cdot S\ \text{MB/s}$
	- random workload: $N\cdot R\ \text{MB/s}$

#### RAID 1: mirroring
simply copies whatever writes made to one disk, to other disks. RAID 1 tolerates disk failures extremely well.
- copy more than one of each block in the system
- copies placed on separate disks

in terms of:
- **capacity**: comparing to RAID 0, RAID 1 is very expensive, because only $\frac{N}{2}$ disks are useful.
- **reliability**: however, in an $N$-disk system, RAID 1 can tolerate failures of any one disk (and up to $\frac{N}{2}$ disks depending on which fails)
- **performance**:
for each logical write, it takes **two physical** writes to complete, and suffers the **worst-case delay** for seek and rotation for both requests.

steady-state throughput:
- sequential write: $\frac{N}{2}\cdot S\text{ MB/s}$. each logical write needs 2 physical writes
- sequential read: $\frac{N}{2}\cdot S\text{ MB/s}$. we only read from $\frac{N}{2}$ disks to keep reads contiguous, so we end up only getting that much bandwidth.
- random write: $\frac{N}{2}\cdot R\text{ MB/s}$
- random read: $N\cdot R\text{ MB/s}$. now, we can use the power of all the disks to distribute reads.
#### RAID 10 vs. RAID 01
10 means stripes of pairs, and 01 means pairs of stripes.

![[Pasted image 20250502122215.png]]

#### RAID 4: parity disk

![[Pasted image 20250503011700.png]]

