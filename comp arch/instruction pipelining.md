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
5. **WB**: writes the result back to the **register file**

some type of instructions will reach all the way to stage 5, others will stop at stage 3, for example: 

branch: 1-2-3
add: 1-2-3-5
store: 1-2-3-4
load: 1-2-3-4-5
## hazards
inconveniences that slow the processor down, because of interdependency of results.
### structural hazards
when a required resource is busy, and will be needed in multiple different stages. in a pipeline with a single memory: 
- `load/store` instructions require access to data memory
- **IF stalls** for that cycle, causing a *bubble*. these are `nop` instructions that delays the pipeline until the dependencies are no longer problematic.

this happens when two or more instructions in the pipeline active compete for access for a **single physical resources**, which can be resolved in one of two ways:
- **wait**: instructions will take turns, meaning stalling is unavoidable
- **cheat**: adding more hardware. a structural hazard can always be solved with more hardware.

### data hazards
data dependency when an instruction needs to wait for the previous instruction to complete its data read/write operation. 

to address this, we do **forwarding (or bypassing)**, which fetches the data directly from the internal buffers instead of waiting for a register.

first, we need to establish some common conventions on how processes are represented:
- shading on the **right half** of the register file or the memory means that the data is **successfully read** in that phase.
- on the other hand, shading on the **left half** means that the **writing** operation is conducted.
- if neither is conducted in the operation (such as the MEM stage during the `add` instruction), the background is **blank**.

> **right read left write**
### forwarding/bypassing
consider the following instructions:

```
add x1, x2, x3
sub x4, x1, x5
```

here, `x1` is used immediately as a source reg. after the `add` instruction. this means `x1` takes the full cycle (until WB) to load data. instead of letting `sub` waiting, we **immediately use the result as soon as it is computed** (after EX finishes).
- does not wait until register file is written
- extra connections in the datapath is required

more forwarding conditions [here](forwarding%20conditions)
#### load-use data hazards
the `load` instruction takes the full 5 stages to finish. however, unlike other r-type instructions where results are available immediately after the EX stage, **load has to wait until MEM is accessed**. 

so, we cannot directly forward the result from EX to the ID stage of the next instruction. instead, we have to squeeze in another `nop` instructions to shift it forward one cycle, in order to save time down the line.

```
ld x1, 0(x2)
sub x4, x1, x5
```

becomes 

```asm
ld x1, 0(x2)
nop
sub x5, x1, x5
```

### control hazards
deciding on the control action depends on the previous instruction. the branch completely determines the control flow. 
- fetching next instruction depends on the branch outcome
- however, due to the immediate queueing, the pipeline doesn't always fetch the correct next instruction, because the next instruction is in IF when branch is in ID.

in the risc-v pipeline, need to compare registers to compute the **branch target early**. so, *hardware is added to do it immediately in the ID stage*.

Q: in a branch instruction, why are we not fetching the next instruction during the decode phase, but instead during the execute phase?

A: note that, when an instruction is queued but not used, **it needs to be flushed**, which costs a clock cycle. so, **we do not want to over-fetch**, as it comes at a higher cost of flushing more out if the control branches successfully. to accomplish this, we **stall after branch**.

[IMAGE NEEDED]

### branch prediction
longer pipelines do not have this privilege of early determination of branch outcome, making the **stall penalty unacceptable**. 

instead, we opt for **branch prediction**, and only stalls if the prediction turns out to be wrong. in the pipeline, we are able to predict untaken branches, and fetch the instruction immediately after branch without any stalls.

**static branch prediction**:
- based on typical branch behavior. for example, in loops and `if` statements, the backwards branch predicted to be taken, and forward to not be taken.

**dynamic branch prediction**:
- hardware records actual branch behavior or history
- assume that the future behavior continues the trend. if we are wrong, stall while re-fetch, and update history.

## pipeline registers
pipelining improves efficiency by: 
- regularizing instruction format
- divide instructions in to fixed number of steps, implement them as segments

that means, when designing the pipeline, we need to:
- ensure each segments take the same amount of time
- keep it full, so throughput and utilization is maximized while minimizing the set up time

to this end, we have **pipeline registers** in-between different stages of execution to hold information produced from the previous cycle, namely:
- `IF/ID`: this in particular needs to be 64 bits wide, to hold the 32-bit instruction fetched from memory and the 32-bit address of the next instruction for the PC.
- `ID/EX`
- `EX/MEM`
- `MEM/WB`

### `load` pipeline
#### instruction fetch IF
1. the PC sends the address of instruction to be fetched from memory
2. instruction is fetched and placed inside the `IF/ID` pipeline reg. 
3. PC is incremented by 4 and written back to PC for next clock cycle
4. new address also saved in the `IF/ID` register, in case needed later

the computer does not know what instruction is being fetched, so it goes for a catch-all by passing all potentially useful info down the pipeline
#### instruction decode ID
1. the ``IF/ID`` register supplies the 16-bit immediate field, which is sign-extended to 32 bits with the ImmGen module
2. **register numbers** of the dest. and source also provided to be read
3. all three values stored in `ID/EX`, along with the new incremented address

$\to$ all info needed still saved
#### execute EX
the EX stage either executes an address, or uses the ALU to calculate a certain address. in this case:
- the `load` instruction reads the content inside `rs1`, and the sign-extended `imm` from `ID/EX`, and adds them with the ALU
- the resultant sum is placed in `EX/MEM`.
#### memory operations MEM
the load instruction reads the **data memory** with address placed inside the `EX/MEM`. it then loads the data into the `MEM/WB` pipeline register
#### register write WB
the final step involves reading data from `MEM/WB` and writing it back to the **register file**. the write register number comes from the `MEM/WB` alongside data, passed from the ID stage until the `MEM/WB` register.

### `store`
the first three stages of `store` is similar to `load`, up until the calculate target address to load the data from.
#### mem ops MEM
the data is being written to memory, and the register containing the data read is stored inside `ID/EX`.

the only way where we can access this data during MEM, is by storing it inside the `EX/MEM` at the EX stage, much like how we stored the address.
#### register write WB
for `store`, no register is written to. since every instruction behind `store` already happened, we cannot accelerate them.

so, an instruction passes through a stage regardless, because all later instructions are already optimally queued.

## pipeline control
the datapath borrows the control logic for PC source, `rd` number, and ALU control. **we always need the 6-bit function field of the instruction in the EX stage as input to the ALU control**, so these 6 bits need to be included inside the `ID/EX` pipeline reg.

these 6 bits are also the 6 LSBs in the immediate field, so `ID/EX` can supply them directly from the immediate field as sign extension does not impact the LSB.

[IMAGE NEEDED]

### which stages determine which signals?
1. **instruction fetch IF**: the control signals for the PC is always asserted, so nothing special is determined here.
2. **instruction decode and read register file ID**: the same thing with IF, nothing particular set here.
3. **execution EX**: the control sets `RegDst`, `ALUOP`, and `ALUSrc`. the signal selects the destination, which operation to perform, and evaluates if the second piece of data comes from a register (`ALUSrc` = 0) or directly from the ALU (`ALUSrc` = 1).
4. **memory MEM**: control lines set are `Branch`, `MemRead`, and `MemWrite`, set by `beq`, `load`, and `store` respectively. `PCSrc` sets next sequential address, unless control asserts branch.
5. **write-back WB**: control lines `MemToReg`, which decides between sending the result from ALU or from memory to register file, and `RegWrite`, which decides chosen value.