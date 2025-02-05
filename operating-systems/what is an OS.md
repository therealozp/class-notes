## virtualization
takes a physical resource (processor, memory, disk, etc.) and makes it into a **virtual form** of itself.

the virtual form is more **general, powerful, and easy to use**. the OS is also referred to as a virtual machine.
## as a resource manager
the OS:
- makes it easy to run programs -> **sharing CPU**
- allowing them to **share memory**
- enable programs to interact with devices -> **sharing disks**

to have multiple programs running at the same time, the OS virtualizes one CPU into a seemingly infinite number of CPUs.

to virtualize memory, the OS makes use of the virtual memory, to simulate the "infinite memory access" that each program has access to. the physical memory is only arrays of bytes, and a program keeps all of those data structures in memory.
- on a read, it **specifies and address** to be read from
- on a write, it specifies the data written to be written to the address

physical memory can only be accessed by the OS. uses virtual addresses to communicate, and maps down to physical memory on execution.

## concurrency
the OS is juggling multiple things at once, and multi-threaded processes also exhibit the concurrency problem. 
