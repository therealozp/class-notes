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
