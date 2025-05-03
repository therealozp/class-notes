knowing that **time sharing** is not an effective method to virtualize the CPU with control, we need to find a way to implement virtualization such that:
- it does not add excessive overhead to the system
- it runs processes efficiently while retaining CPU control

## candidate 1: direct execution
obviously, we could just run the program **directly** on the physical CPU. thus, the timestamps for a process would look something like:

| time | OS                                   | program                                       |
| ---- | ------------------------------------ | --------------------------------------------- |
| 1    | create entry for process list        |                                               |
| 2    | allocate memory for program          |                                               |
| 3    | load program into memory             |                                               |
| 4    | set up the stack with `argc`/ `argv` |                                               |
| 5    | clear registers                      |                                               |
| 6    | executes the `main()` call           |                                               |
| 7    |                                      | run the `main()` program                      |
| 8    |                                      | executes the `return` statement from `main()` |
| 9    | free process memory                  |                                               |
| 10   | remove process from process list     |                                               |
|      |                                      |                                               |
one immediate issue with this is that the OS relinquishes control of the program immediately, and shifts all control capabilities to the program. without these **limits**, the OS is not in control of anything, and would just be a simple library.

### problem 1: restricted operation
during process execution, the process might need to perform some restricted operations, such as
- I/O request to disk
- gain access to more system resource such as CPU or memory

in user mode, the application does not have full access to hardware resources. this is only available in **kernel mode**. thus, we use **system calls** to enable *protected control transfer*.
### system calls (syscalls)
allows a user to tell an OS what to do:
- the OS provides some interfaces (API, `stdlib`)
- a typical OS exports a few hundred system calls (run programs, access memory, access devices, etc.)

using this allows the kernel to carefully expose certain **key pieces of functionality** to the user program, such as: 
- accessing file system
- creating/destroying processes
- communication with other processes
- allocating more memory

the most crucial part to achieving *protected control transfer* is by means of the `trap` and the `return-from-trap` instruction.

on a `trap` system call:
- the process jumps into the kernel
- privilege level of process is raised to kernel mode

on a `return-from-trap` system call:
- return into the calling user program
- reduce privilege level back to user mode

so, with these 2 system calls, we can add on to our timestamps as follows:

| time                  | OS                                    | hardware                                     | program (user mode)                              |
| --------------------- | ------------------------------------- | -------------------------------------------- | ------------------------------------------------ |
| at boot (kernel mode) |                                       |                                              |                                                  |
| 1                     | initializes **trap table**            |                                              |                                                  |
| 2                     |                                       | remembers the address of the syscall handler |                                                  |
| at run                | (kernel mode)                         |                                              |                                                  |
| 3                     | creates entry for process list        |                                              |                                                  |
| 4                     | allocates memory for the program      |                                              |                                                  |
| 5                     | loads program into memory             |                                              |                                                  |
| 6                     | setup user stack with `argv`          |                                              |                                                  |
| 7                     | fill kernel stack with registers / PC |                                              |                                                  |
| 8                     | **`return from trap`**                |                                              |                                                  |
|                       |                                       | restore registers from kernel stack          |                                                  |
| 10                    |                                       | move to user mode                            |                                                  |
| 11                    |                                       | jumps to the `main()` call                   |                                                  |
| 12                    |                                       |                                              | runs `main()`                                    |
| 13                    |                                       |                                              | ...executes programs...                          |
| 14                    |                                       |                                              | calls system **`trap()`** to shift control to OS |
| 15                    |                                       | save registers to kernel stack               |                                                  |
| 16                    |                                       | move to kernel mode                          |                                                  |
| 17                    |                                       | jumps to the trap handler                    |                                                  |
| 18                    | handles the trap                      |                                              |                                                  |
| 19                    | do work of the requested syscall      |                                              |                                                  |
| 20                    | **`return from trap`**                |                                              |                                                  |
| 21                    |                                       | restore registers from kernel stack          |                                                  |
| 22                    |                                       | move to the user mode                        |                                                  |
| 23                    |                                       | jumps to PC after trap                       |                                                  |
| 24                    |                                       |                                              | ...executes programs...                          |
| 25                    |                                       |                                              | return from `main()`                             |
| 26                    |                                       |                                              | `trap()` via the `exit()` call                   |
| 27                    | free process memory                   |                                              |                                                  |
| 28                    | remove from process list              |                                              |                                                  |
### problem 2: switching between processes
context switching defines the flow that is involved when we want to switch between different processes.

there are a number of ways where the OS can regain control of the CPU:
- cooperative approach: wait for system calls
- non-cooperative approach: OS takes control
#### cooperative
processes will periodically give up the CPU through system calls such as `yield`. at this point, the OS can choose to run some other task at its discretion.

applications will also automatically return control to the OS when it attempts to do something illegal, like division by 0, or accessing non-allowed memory regions. 

however, if the OS decides to wait, in the case that a process gets stuck in an infinite loop, **it will never yield**. so, we will have to reboot the machine.

#### non-cooperative
we enforce the CPU control by means of a **timer interrupt**. this gives the OS the ability to run again on the CPU, no questions asked.

1. during boot sequence, OS starts a timer. 
2. this timer raises an interrupt every few milliseconds.
3. when the interrupt is raised:
	- currently running process is halted
	- save sufficient amount of program state
	- pre-configured interrupt handler, baked into the OS, runs.

### saving and restoring context
the [[scheduler]] makes an important decision: do we continue running the current process, or switch to a different one? 

if we decide to switch, a **context switch** is executed. context switch is a low-level piece of assembly that:
- saves a few register values for the current process (general purpose regs, PC, kernel stack pointer) into its kernel stack
- restores a few for the soon-to-be executing process from the kernels tack
- switches to the kernel stack for the soon-to-be executing process

to aid with concurrency, during interrupts or trap handlings, if *another* interrupt should occur:
- the OS disables interrupts during interrupt processing
- uses a number of sophisticated **locking schemes** to protect concurrent access to internal data structures.

with the timer interrupt, we can do even better:

| time                  | OS                                            | hardware                                     | program (user mode)     |
| --------------------- | --------------------------------------------- | -------------------------------------------- | ----------------------- |
| at boot (kernel mode) |                                               |                                              |                         |
| 1                     | initializes **trap table**                    |                                              |                         |
| 2                     |                                               | remembers the address of the syscall handler |                         |
| 3                     | **starts interrupt timer**                    |                                              |                         |
| 3                     |                                               | start timer                                  |                         |
| 4                     |                                               | interrupt CPU in X ms                        |                         |
| 5                     |                                               |                                              | run process A           |
| 6                     |                                               |                                              | ...execute processes... |
| 7                     |                                               | **timer interrupt**                          |                         |
| 8                     |                                               | save registers of A to kernel stack A        |                         |
|                       |                                               | moves to kernel mode                         |                         |
| 10                    |                                               | jumps to the **trap handler**                |                         |
| 11                    | handles the trap call                         |                                              |                         |
| 12                    | calls the `switch()` routine                  |                                              |                         |
| 13                    | save registers(A) into process structure A    |                                              |                         |
| 14                    | restore registers(B) from process structure B |                                              |                         |
| 15                    | switch to kernel stack B                      |                                              |                         |
| 16                    | **`return from trap`** into B                 |                                              |                         |
| 17                    |                                               | restores registers B from kernel stack B     |                         |
| 18                    |                                               | move to user mode                            |                         |
| 19                    |                                               | jump to B's program counter                  |                         |
| 20                    |                                               |                                              | run process B           |
| 21                    |                                               |                                              | ...execute processes... |
