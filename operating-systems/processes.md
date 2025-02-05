a process is a running program. a process consists of:
- memory (address space), contains instructions and data
- something else

each process has its own virtual memory space, unless explicitly specified. in modern OSes, there are shared libraries (`.dll` or `.so`), which also execute their own processes.
## process creation
the OS exposes several APIs to the OS, including:
- **create**: creates a process
- **halt**: to stop a runaway process
- **wait**: wait for a process to stop running
- **miscellaneous control**: to pause/resume a process
- **status**: gets status info

to actually create a process:
1.  loads program code (initially packaged in an **executable**) to main memory (RAM, the address space of process). 

**note**: the modern OS loads programs **lazily** (contrast with **eager** loading in earlier OSes), meaning only necessary parts are loaded during execution.

2. allocates memory for **runtime stack** (static data, variables, etc.)
3. allocates program **heap**, used for explicitly requested dynamic data. `free(), malloc()`
4. other initialization tasks on setup. a program has three open file descriptors (`stdin, stdout, stderr`)
5. **start program** at entry point, `main()`. at this point, the OS transfers control of CPU to the new process.
## process states
a process can be in one of 3 states:
- **running**: already running on the processor
- **ready**: ready to run, but the OS hasn't ran it yet for whatever reason.
- **blocked**: the process has performed some kind of operation. when it initiates I/O request, it becomes *blocked*, and frees up the processor for other processes.

the transition between processes can be described with a FSM as follows:

![[state-switches.png]]
## data structures of a process
to keep track of the state of each process, the OS will likely keep some sort of **process list** for:
- all ready processes
- currently running processes
- in some way, blocked processes, so that when some I/O event finishes, it wakes the correct process to run it again.

another data structure the OS employs is the **register context**, which holds all the content currently in registers of a stopped process. 

when said process is stopped, its registers will be saved to this memory location. when it is time to unfreeze, the OS re-loads this stored data to resume the process.