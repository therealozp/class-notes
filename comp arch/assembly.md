## assembly language
the basic job of a CPU is to run **a lot of instructions**, which are *primitive operations* that the CPU may execute. different CPUs implement different set of instructions, called the **instruction set architecture** (ISA).
### design principles
in designing an assembly language, there are some principles that they all follow: 
	#### simplicity favors regularity
- regularity makes implementation easier.
- simplicity enables higher performance at lower cost.
#### smaller is faster
- c.f. main memory: millions of locations
#### make the common case fast
- small constants are very common, so the immediate operands avoid executing another load instructions.

## instructions
for every instruction, the opcode of the instruction will be used for the control unit, which determines which instruction to run.

### r-type: arithmetic instructions

`func7` - 7b | `rs2` - 5b | `rs1` - 5b | `func3` - 3b | `rd` - 5b | `opcode` - 7b

- `opcode`: operation code  
- `rd`: destination register number  
- `funct3`: 3-bit function code (additional opcode)  
- `rs1`: the first source register number  
- `rs2`: the second source register number  
- `funct7`: 7-bit function code (additional opcode)

for example, if an instruction `add x9, x20, x21` is executed, then:
- the `opcode` will be 51 (or 0110011)
- `rd` will be 9 (because x9)
- `rs1` will be 20
- `rs2` will be 21
### i-type: immediate arithmetic and load instructions

`immediate` - 12b | `rs1` - 5b | `func3` - 3b | `rd` - 5b | `opcode` - 7b

- `opcode`: specifies instruction
- `rs1`: source or base address
- `rd`: destination register
- `immediate`: constant operand, or offset added to base address. this number will be sign-extended to 32b before any arithmetic operations
### s-type: store instructions

`imm[11:5]` - 7b | `rs2` - 5b | `rs1` - 5b | `func3` - 3b | `imm[4:0]` - 5b | `opcode` - 7b

different immediate formats for store instructions:
- `rs1`: base address register number
- `rs2`: source operand register number
- `imm`: offset to base address. the immediate is split into 7 and 5 bits to ensure `rs1` and `rs2` lies in place.

### shift instructions

func6 - 6b | `immediate` - 6b | `rs1` - 5b | `func3` - 3b | `rd` - 5b | `opcode` - 7b

- the `immediate` indicates how many bits to shift.
- `slli` shifts left logical, filling empty space with 0s, meaning multiplication with $2^{i}$
- `srli` shifts right, filling with 0s, meaning dividing with $2^{i}$

### conditional operations
branch to a labeled instruction if a condition is true. otherwise, continue sequentially. branch instructions **is the most complicated instruction** the CPU will have to deal with, with second-most being the `log` operation.

works by interrupting the flow of the program, calculates the address of the target branch, and push the address to the program counter to run.
### loop operations
`while (save[i] == k) i += 1;` is compiled to:

```risc
loop:
	slli    x10, x22, 3
	add     x10, x10, x25
	ld      x9, 0(x10)
	bne     x9, x24, exit
	addi    x22, x22, 1
	beq     x0, x0, loop
exit:
```

