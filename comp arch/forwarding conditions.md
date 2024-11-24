rule of thumb: if a resource **goes back in time**, then forwarding would be needed.

when we mention `ID/EX.rs1` means the register number for `rs1` in the `ID/EX` pipeline register, and so on for other stages

all the ALU operand register numbers in the EX stages are `ID/EX.rs1` and `ID/EX.rs2`.
### EX hazards
an EX hazard occur when:
- `EX/MEM.rd` = `ID/EX.rs1` or `ID/EX.rs2`
- `MEM/WB.rd` = `ID/EX.rs1` or `ID/EX.rs2`

or, in simpler words, if the destination register of the instruction in the `EX/MEM` stage is being used as one of the 2 sources in the instruction afterwards (in the `ID/EX` stages).

if and only if the forwarding instruction eventually writes to a register, e.g. `RegWrite` is enabled, and the destination register is not `x0` (aka for jump instructions, etc.)

when an EX hazard occurs, the `ForwardA` or `ForwardB` flag is set to 10.
### double data (MEM) hazards
consider the following set of instructions:

```asm
1: add x1, x1, x2
2: add x1, x1, x3
3: add x1, x1, x4
```

here, the procedure of instruction 1 needs to wait for instruction 2, and instruction 3 has to wait for the value of `x1` from instruction 2, not 1! so, in the case where they are conflicted, the assembler adds in a second check:

```cpp
if (MEM/WB.RegWrite
and (MEM/WB.rd ≠ 0)
and not(EX/MEM.RegWrite and (EX/MEM.rd ≠ 0) and (EX/MEM.rd ≠ ID/EX.rs1))
and (MEM/WB.rd = ID/EX.rs1))
    ForwardA = 01
```

1. `MEM/WB.RegWrite and (MEM/WB.rd != 0)`:
ensures that the instruction in the MEM/WB stage is writing to a non-`x0` register. writing to `x0` has no effect, so forwarding is unnecessary.

2. `not(EX/MEM.RegWrite and (EX/MEM.rd ≠ 0) and (EX/MEM.rd ≠ ID/EX.rs1))`:
checks whether there is a conflicting instruction EX/MEM that also writes to a register, specifically:
- `EX/MEM.RegWrite and (EX/MEM.rd != 0)`: The instruction in the EX/MEM stage is writing to a non-`x0` register.
- `(EX/MEM.rd != ID/EX.rs1)`: `rd` of the instruction in the EX/MEM stage does **not** match the source register `rs1` of the instruction in the ID/EX stage.

if all these conditions are true, the forwarding from the MEM/WB stage is disabled, ensuring the value from the EX/MEM stage is used instead.

3. `(MEM/WB.rd = ID/EX.rs1)`:
if the register being written to in the MEM/WB stage matches the source register `rs1` of the instruction in the ID/EX stage. if true, forwarding from MEM/WB is needed.

on a MEM hazard, the `Forward` flag is set to 01.

### load-use hazard
checked when the instruction is being decoded in the ID stage. the ALU operand register numbers are accessible with `IF/ID.rs1` and `IF/ID.rs2`. 

on detection, the program stalls and a bubble is inserted. then, a load-use hazard occurs when:

```
ID/EX.MemRead and
(ID/EX.rd == IF/ID.rs1) or (ID/EX.rd == IF/ID.rs2)
```

the first line tests if the instruction is a load, **because the only instruction where** `MemRead` **is enabled is a** `load`.

```
beq x1, x2, label
addi x1, x1, -1
label:
addi x1, x1, 2
```

### branch control hazard
as previously stated, a control hazard occurs when the outcome of the branch is determined **after** instructions have been set. 

to mitigate this, we could stall the instructions until the branch outcome is determined, but there is a better way: **optimistically assume branches are not taken**.

if branches are not taken 50% of the time, this optimization improves the stall penalty by half on average.
- if the prediction is correct, pipeline proceeds as usual without penalty.
- if prediction is wrong, incorrectly fetched and decoded instructions are **flushed**, control jumps to the branch target, and we are faced with the **flushing penalty**.

#### flushing
a control is flushed by overwriting their control signals to 0, effectively turning them into no-ops `nop`. these `nop` pass through pipeline stages without further affect.

note that for a branch misprediction, we need to reset control signals of all instructions in the active pipeline stages (including up to IF, ID, and EX) when the branch reaches the MEM stage. compared to a **load-use data hazard** where a 0 is only written in the ID stage, branch penalty is requires much more work.

note that the timing of the flushes are important. a flush effectively writes 0s to all control signals, making up to 3 loaded instructions `nop`'ed **at one clock cycle**. it is not until up to the 7th cycle that the final `nop` is cleared out the pipeline, meaning that the branch misprediction does not write any wrong results.

consider the following timeline:

| **Cycle** | **IF**                  | **ID**            | **EX**            | **MEM**           | **WB**            |
| --------- | ----------------------- | ----------------- | ----------------- | ----------------- | ----------------- |
| 4         | **Fetch correct instr** | `nop` (flush IF)  | `nop` (flush ID)  | `nop` (flush EX)  | Speculative instr |
| 5         | Fetch next instr        | **Correct instr** | `nop`             | `nop`             | `nop`             |
| 6         | Fetch next instr        | Next instr        | **Correct instr** | `nop`             | `nop`             |
| 7         | Fetch next instr        | Next instr        | Next instr        | **Correct instr** | `nop`             |
| 8         | Fetch next instr        | Next instr        | Next instr        | Next instr        | **Correct instr** |
#### reducing branch delays
to mitigate the branch delay, we can move hardware to determine branch target to ID stage, which requires:
- an adder to compute target address (using offset from current instruction instead of explicit address)
- a register comparator
