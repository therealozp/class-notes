the early OS does not have any interactivity, so it loads only **one process** in memory, resulting in very poor utilization and efficiency.

### multiprogramming & time sharing
a solution to virtualizing memory is loading multiple processes:
- execute each one for a little bit
- switch processes between them in memory

however, this will result in a protection issue, where other processes may wrongly attempt to access the current process of memory.

the OS ensures that there is a chunk of physical memory available for a process, which the process uses from the virtual address space to run. it always creates an **abstraction** of physical memory:
- address space contains all about a running process
- consists of:
	- program code
	- a **heap** for dynamically allocated memory, expands downward.
	- a **stack** for static memory such as return addresses, static variables, local variables, arguments to routines, expands upward.

running processes do **not** know its physical address, only the OS is aware of that.

memory virtualizing takes a similar strategy known as **limited direct execution (LDE)** for control. there is no reasonable way for the OS to keep interrupting execution of a process to limit memory access (syscalls are too slow), so it needs **hardware support** to achieve virtualization.

## address translation
hardware attempts to convert a **virtual address** to a **physical address**, where actual data is stored. to retrieve the correct piece of data, the OS must get involved at key points to set up the hardware and manage memory in general.

take this example in C:

```c
void func() {
	int x;
	x = x + 3; 
}
```

translating this into assembly (and assuming that the **address** of `x` has been placed in the `ebx` register, we get roughly:

```asm
128: mov1   0x0(%ebx), %eax     ; load 0+ebx into eax
132: add1   $0x03, %eax         ; add 3 into the eax register
135: mov1   %eax, 0x0(%ebx)     ; store eax back to mem
```

- the CPU fetches the instruction at address 128
- execute this instruction (loaded from address 15KB)
- fetch instruction at 132
- execute this instruction (no memory reference)
- fetches instruction at 135
- executes this instruction (store to 15KB)
### address space relocation
the OS wants to place the process somewhere else in the physical memory, not at the address 0x0. however, this complicates things for the program/programmer, as they have to take this into account. 

instead, the OS creates an illusion that the program's allocated memory starts at 0, but in fact is actually located at some other place in the physical memory.

### dynamic (hardware base) relocation
when a program starts running, the OS decides the physical location in memory a process should be loaded. it employs two main registers:
- **base** register: denotes where it starts.
- **bound** register: denotes the size of the memory block allocated to the program. depending on the implementation, this can also mark the "end" of the memory block.

```
physical addr = virt. addr + base
```

every virtual address must not be negative, and must not be greater than the bounds.

```
0 <= virt. addr <= bounds (or bounds + base, depending on implementation)
```

to accomplish this, the OS must intervene on three junctures:
- **on startup**: the OS must find space for the address space in physical memory. OS accomplishes this via a **free list**, which is a list of the range of physical memory that is currently not in use. the nodes of the free list indicates the address of said block.
- **on termination**: memory must be reclaimed for use. OS will put this memory back on the free list on termination.
- **on context switch**: the OS must save and store the base-and-bound pairs of registers in the [[processes#data structures of a process|process structure]], or the **process control block** (PCB).

### base and bad
the base and bound approach makes memory fragmented, and big, unallocated chunks of empty space will appear. another downside is that, if the requested virtual memory cannot be accommodated in physical memory, it will also cause problems. 
## segmentation
to solve the problems introduced by base and bound, we have segmentation.

a segment is just a **contiguous portion of the address space** of a particular length. there are also logically different segments, like stack (grows bottom up), heap (grows top down) and code (which just does not grow).

each segment is placed in different parts of the physical memory, and base-and-bound is used under the hood.
### address translation
similar to what we have done above, the OS keeps track of an **offset** variable which indicates where the actual block begins, and obfuscates the true memory location. so, we once again arrive at:

```
physical address = offset + base_addr
```

### segmentation fault
if the program attempts to access an illegal address beyond the end of the heap, the OS throws a segfault and kills the program.

so, if the program's heap starts at 4KB, and is allowed 2KB, the furthest it could go is 6KB. if the program tries to reach 7KB, we reach a segfault.

### stack address translation
the memory allocated to the stack **grows backward**. so, we need extra support from hardware to check which way segment grows. here, 1 indicates the positive direction (down), and 0 indicates up.

| segment | base | size | grow direction |
| ------- | ---- | ---- | -------------- |
| code    | 32K  | 2K   | 1              |
| heap    | 34K  | 2K   | 1              |
| stack   | 28K  | 2K   | 0              |

we can even further divide these by using the first few MSBs of the virtual address, i.e.

| segment | bits |
| ------- | ---- |
| code    | 00   |
| heap    | 01   |
| stack   | 10   |
| -       | 11   |

so, the way it will be referenced is:

```
	+------------+
000 |            |
	|    code    |
001 |            |
	|            |
010 |    heap    |
	|            |
011 |            |
	|            |
100 |    stack   |
	|            |
101 |            |
	|            |
110 |   unalloc  |
	|            |
111 |            |
	|            |
	+-------------+
```

## paging
the idea behind paging is splitting the address space into different **pages** of fixed size. compare this to segmentation, where logical segments (code, heap, stack) can have variable sizes.

physical is also split into page (frames), where the page table **per process** is needed to map virtual pages to physical frames. this yields two main advantages:
- memory can be managed flexibly. we don't need to know how heap and stack grows, nor do we need to know how it is used.
- memory management is simple, because the *page in address space* and the *page frame* are the **same size**, which makes it easy to allocate and maintain a free list.

a page table entry usually consists of the following:
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

the page table **for each process** is stored on memory