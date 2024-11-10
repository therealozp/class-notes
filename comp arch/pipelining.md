## datapath
consists of 5 main stages. some instructions will reach all the way to stage 5, others will stop at stage 3.

branch: 1-2-3
add: 1-2-3-5
store: 1-2-3-4
load: 1-2-3-4-5

**stage 1**: instruction fetch (IF)
**stage 2**: instruction decode (ID)
**stage 3**: execute (EX) - go to arithmetic logic unit (ALU)
**stage 4**: memory access (MEM)
**stage 5**: write back to register (WB)

## implementation
- send the **program counter (PC)** to memory that contains the code and fetch instruction from memory
- **read 1 or 2 registers**, depending on instruction. `load` required only 1, but most others require 2.
## instruction fetch
the CPU runs in an infinite loop, fetching instructions from memory and executing them. the PC register holds the address of the current instruction, and is continuously incremented by 4 to move to the next instruction.