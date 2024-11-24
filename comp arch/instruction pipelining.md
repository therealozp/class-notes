**pipelining** means organizing instructions such that multiple instructions are overlapped and have all of them executed in parallel to one another, like an assembly line.

in pipelining, there are different stages that operates on different instructions. it improves performance by **increasing instruction throughput**, meaning that:
- it executes instructions in parallel,
- but still does not do anything for latency (time from start to finish) per instruction
- the potential speedup is the number of stages

however, due to the characteristics of instruction pipelining:
- the unbalanced lengths of pipe stages reduces speedup
- "filling" the pipeline and "draining" it (such as, on branch instructions) also reduces speedup
- sometimes, "stalling" is required to handle dependencies.

smaller stages are generally easier to design and optimize modularly. the entire process takes 5 stages:

overall, the process involves 5 different stages:
1. **IF**: fetch instruction from memory
2. **ID**: decode instruction and register read
3. **EX**: executes the operation and/or calculates the target address
4. **MEM**: accesses the memory operand
5. **WB**: writes the result back to register.

some type of instructions will reach all the way to stage 5, others will stop at stage 3, for example: 

branch: 1-2-3
add: 1-2-3-5
store: 1-2-3-4
load: 1-2-3-4-5
## hazards
pipelining is also very much subject to hazards.
### structural hazards
when a required resource is busy, and will be needed in multiple different stages. in a pipeline with a single memory: 
- `load/store` instructions require access to data memory
- **IF stalls** for that cycle, causing a *bubble*. these are `nop` instructions that delays the pipeline until the dependencies are no longer problematic.

this happens when two or more instructions in the pipeline active compete for access for a **single physical resources**, which can be resolved in one of two ways:
- **wait**: instructions will take turns, meaning stalling is unavoidable
- **cheat**: adding more hardware. a structural hazard can always be solved with more hardware.

### data hazards.
- **data** hazards: data dependency when an instruction needs to wait for the previous instruction to complete its data read/write operation. to address this, we do **forwarding (or bypassing)**, which fetches the data directly from the internal buffers instead of waiting for a register.
- control hazards: deciding on the control action depends on the previous instruction.
 

## instruction fetch (IF)
the CPU runs in an infinite loop, fetching instructions from memory and executing them. the PC register holds the address of the current instruction, and is continuously incremented by 4 to move next.

the value written to the PC is determined by one of two adders. in the case of branching or jumping, the target changes. to select between the two (+4 or new address), another **multiplexor** is responsible for handling these signals. 

in a branch instruction, why are we not fetching the next instruction during the decode phase, but instead during the execute phase?

- to avoid flushing out extra instructions. if we fetch next during decode, then by the time we reach execute, we will have already fetched another one. 
- if we fetch during execute, if the branch fails, we will only have to flush out one instruction.
