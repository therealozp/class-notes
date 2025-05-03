to implement a file system, there are two considerations we should think about:
- **data structures**: what type of on-disk structures does the file system uses to organize data and metadata?
- **access methods**: how does the fs map the syscalls made by a process, such as `open`, `read`, `write`, etc, and which structures are read during the execution of said syscalls?

## organization
suppose that we have a filesystem of 64 blocks, each 4KB each. 

![[Pasted image 20250502202720.png]]

we can reserve the blocks 8 to 63 to store data, dubbed the **data region**: 

![[Pasted image 20250502202951.png]]

then, the file system needs to track which data blocks comprise a file, then the size of the file, which inode it belongs to, etc.

to store this, let's reserve some more space in the first block set and map out the inode table. 
- this holds an array of on-disk inodes
- each inode has size 256 bytes, so 4KB can hold 16 inodes. leaving some space for the **data bitmap** and the **inode bitmap**, we are left with 5 blocks for inodes, and a total of 80 inodes:

![[Pasted image 20250502203430.png]]

as mentioned, we need allocation structures to track whether inodes or data blocks are free or allocated. so, for each of the data and inode bitmap, each bit indicates free (0) or in use (1).

then, the first block (block 0) will be the **superblock**, which contains information for this particular filesystem. info such as number of inodes, start location of the inode table, etc. are included. when a filesys is mounted, the OS will read the superblock first, to initialize information.

## inodes
each inode is referred to by its own inode number. with that, the filesystem can calculate where the inode is on the disk. 

for example, to access inode 32 in our fictitious filesystem, we would get:
- inode offset in the inode region: $32\times 256 = 8192$
- final offset by adding the inode table start: $12KB + 8KB = 20KB$

one major thing to notice is: the disk is **not byte-addressable**, it is **sector** addressable. the disk consists of a large number of addressable sectors of size 512B.

then, the calculations can be obtained by:
- we have the sector address, `iaddr`, of the inode block
- `block_number` = `inode_number` $\times 256$ / `block_size`
- `sector` = (`block_number * block_size` + `iaddr` )  / `sector_size`


the inode has all of the information needed about a file: 
- file type: if it is a normal file, a directory, etc.
- size and number of data blocks allocated to it
- protection information (owner, who can access, etc.)
- time information
- and others!

### multi-level index
each inode has a fixed number of direct pointers, which are pointers to the data blocks. each pointer are usually 32 bits (4 bytes), so each block is able to hold $\frac{4KB}{4B} = 1024$ pointers.

each inode can contain: 
- 12 direct pointers, that point directly to the 12 data blocks
- 1 single indirect pointer, which points to 1 block of 1024 pointers
- 1 double indirect pointer, which points to a block of 1024 single-indirects, each of which points to a block of 1024 directs.
- 1 triple indirect pointer, and you get the point.

direct pointers can point to a single 4KB block, so with 12 direct pointers, an inode can directly point to $12\times 4KB=48KB$.

if we need an even bigger file, we can use one indirect block that holds 1024 pointers. with this addition, we gain an additional $1024\times 4KB = 4MB$, making our total $4MB + 4KB$.

if an even bigger file is needed, the double indirect pointer helps, and adding $1024\times 1024\times 4KB = 4GB$ to what we currently have.

the rationale behind this kind of design is because:
- most files are small (2KB), and so direct pointer are very good
- the average file size is growing to 200KB
- most bytes are stores in a few big files that use most of the space, so the organization helps.
- the fs has a lot (~100K) of files, and even if the disk grows, the file system remains roughly 50% full, always.
- the directories are typically small, most have 20 or fewer entries.

### directories
a directory contains a list of (entry name, inode number) pairs. each directory has another two extra files `.` and `..` representing current and parent directory, respectively.

## access paths
