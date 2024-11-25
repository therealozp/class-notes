both these terms are used to describe "unexpected" events, requiring a change in control flow. dealing with these without sacrificing performance is hard.

an **exception** arises within the CPU, and an unscheduled event to disrupt program execution used to detect overflow.

an **interrupt** is an exception that comes from **outside** of the professor.

| event                               | from where ? | terminology         |
| ----------------------------------- | ------------ | ------------------- |
| I/O device request                  | external     | interrupt           |
| invoking the OS from a user program | internal     | exception           |
| arithmetic overflow                 | internal     | exception           |
| using an undefined instruction      | internal     | exception           |
| hardware malfunctions               | either       | exception/interrupt |
## handling exceptions
there are usually two main types of exceptions:
- undefined instruction
- arithmetic overflow

in every exception, the control flow that the processor must assume is to **save address of the offending instruction** in the supervisor exception program counter (SEPC), then transfer control to the OS at some predefined address.
- **SEPC**: 64-bit register that holds the **address** of the offending instruction
- **SCause**: 64-bit register that records the reason of the exception.

to aid with exception handling, we have **vector interrupts**, which are addresses which control is transferred to based on cause of exception. 
- the addresses are separated by 32 bytes (8 instructions worth)
- OS must record the reason
- before that, some limited processing in the sequence may be done.

the predefined address for the control transfer is `0x0000 0000 1C09 0000`, which is fed directly into the MUX that goes into the PC. the ALU overflow signal is an input to the control unit that detects this.

### multiple exceptions
since our pipeline processes instructions by the multiple, we could encounter multiple exceptions at once.
- simplest: deal with exception from earliest
- multiple instructions per cycle + out-of-order completion -> very difficult to maintain precise exceptions

**precise interrupt/exception**: an I/E that is always associated with the correct instruction in pipelined computers

**imprecise interrupts**: interrupts that are not always traced back to the original root cause.

## multiple issue
a multiple issue is a scheme where multiple instructions are launched (or issued) in one clock cycle.
- **static**: many decisions are made by compiler before execution:
	- compiler groups instructions to be issued together
	- package them into "issue slots" - instructions issued in a given CC
	- compiler detects and avoids hazards
- **dynamic**: decisions are made **during execution by the processor**.
	- CPU examines the instruction stream and chooses instructions to issue
	- compiler helps by reordering instructions
	- CPU resolves hazards **at runtime**
	- 
## speculation
compiler or processor guessing the outcome to remove it as a dependency in executing other instructions. very common in multiple-issue processors.

"guess" what to do with an instruction:
- start operations ASAP
- check if guess was correct: if yes, continue; if no, roll-back and adjust

examples:
- speculate the branch outcome, and rollback if path taken is different
- speculate on load, and roll back if location is updated

the compiler may also reorder instructions:
- e.g. move loads before branch
- include fix-up instructions to recover from incorrect guess

hardware can still look-ahead for instructions to execute, and buffers the results until they are actually needed; or flushes the buffers on an incorrect speculation.