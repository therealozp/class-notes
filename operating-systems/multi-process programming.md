## `fork()` system call
creates a new process, which has its own copy of the address space, registers, and program counter. returns an integer indicating the status.

## `wait()` system call
when a parent process calls `fork()` to create a child process, both processes will be executed in parallel. thus, to merge the results and wait for the program to deterministically continue, we must use a `wait()` call in the parent branch.

## `exec()` system call
executes the specified program in `argv[0]`, and accepts `char *argv[]` as a second argument. runs the specified command with all the specified flags.


