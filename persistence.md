## hard disks
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
- **write-back**: a write is marked successful when there is confirmation that the requested block is put in data memory.
- **write through**: actually admitting the rate has been completed after we weren't writing them

## disk scheduling
decides on which IO request to do next.

### shortest seek time first (SSTF)
produces the order of IO request by track, and pick whichever is at the nearest track to complete first.

