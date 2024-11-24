## processor
consists of three main components:
- **processor**: active component that does all decision making
- **datapath**: the hardware necessary to perform operations
- **control**: hardware portion that tells datapath what needs to be done.

every execution of the instruction generally includes 3 different parts: 
1. the PC gives out an address of instruction, goes into that address and fetches instruction
2. go into register file to read registers based on the instruction
3. depending on the instruction:
	- use the ALU to perform arithmetic, calculate addresses for `load/store`, branch comparisons, etc.
	- accesses memory for `load/store`
	- advance program counter
## datapath
if we wait for an instruction to go through all of the above mentioned processes before executing another one, it would be too slow. so, we break it up into 5 different stages, and connect them together.

**stage 1**: instruction fetch (IF)
**stage 2**: instruction decode (ID)
**stage 3**: execute (EX) - go to arithmetic logic unit (ALU)
**stage 4**: memory access (MEM)
**stage 5**: write back to register (WB)

overall, smaller stages are generally easier to design and optimize individually (modularity).

some type of instructions will reach all the way to stage 5, others will stop at stage 3, for example: 

branch: 1-2-3
add: 1-2-3-5
store: 1-2-3-4
load: 1-2-3-4-5

### main components
the first-cut datapath does instruction in one clock cycle. so, each element **can only do one function at a time**, and separation of data mem. versus instruction mem. is needed.
### registers and ALU
the register file stores **32-bit** values. each register is 5 bits long, and 2 registers can be read at a time. 

**the RegWrite control signal is high (1) if a register should be written**.

the ALU has 5 basic operations, selected by a 3-bit control signal called **ALUOp**

| ALUOp | function |     |
| ----- | -------- | --- |
| 000   | and      |     |
| 001   | or       |     |
| 010   | add      |     |
| 110   | subtract |     |
| 111   | slt      |     |
another 4 bits is used for the ALUControl, which maps the intended function to its corresponding function inside the ALU:

| desired operation   | function              |
| ------------------- | --------------------- |
| load/store          | add                   |
| branch              | subtract              |
| r-type instructions | depends on the opcode |
### memories
to fetch instructions or read/write words, the memories need to be 32-bits wide. the control signals are highlighted in blue. note that:
- **MemRead** is set to 1 if **data memory** (not instruction memory!) is to be read
- **MemWrite** is set to 1 if **data memory** is to be written to.
### control
sends out the necessary control lines inside the datapath indicating which components to fire on different types of instructions.
## instruction fetch (IF)
the CPU runs in an infinite loop, fetching instructions from memory and executing them. the PC register holds the address of the current instruction, and is continuously incremented by 4 to move next.

the value written to the PC is determined by one of two adders. in the case of branching or jumping, the target changes. to select between the two (+4 or new address), another **multiplexor** is responsible for handling these signals. 

