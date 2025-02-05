the early OS does not have any interactivity, so it loads only **one process** in memory, resulting in very poor utilization and efficiency.

### multiprogramming & time sharing
a solution to virtualizing memory is loading multiple processes:
- execute each one for a little bit
- switch processes between them in memory

however, this will result in a protection issue, where other processes may wrongly attempt to access the current process of mpemory.

the OS ensures that there is a chunk of physical memory available for a process, which the process uses from the virtual address space to run. it always creates an **abstraction** of physical memory:
- address space contains all about a running process
- consists of:
	- program code
	- a **heap** for dynamically allocated memory, expands downward.
	- a **stack** for static memory such as return addresses, static variables, local variables, arguments to routines, expands upward.

running processes do **not** know its physical address, only the OS is aware of that.

memory virtualizing takes a similar strategy known as **limited direct execution (LDE)** for control. there is no reasonable way for the OS to keep interrupting execution of a process to limit memory access (syscalls are too slow), so it needs **hardware support** to achieve virtualization.

## address translation
hardware attempts to convert a virtual address to a physical address, where actual data is stored. 