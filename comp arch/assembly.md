## registers
a small bit of memory used in the CPU. ultra fast, very limited capacity, and only available on very specialized locations. these are used in assembly to perform different instructions, and **operations can only be performed on these.**

risc-v has a 32 x 64-bit register file. where:
- 64-bit is doubleword `dw`
- 32-bit is word `w`
- 16-bit is half `h`
- 8-bit is a byte
- 4, 2, and 1 is nibble, crumb, and bit, respectively.

these registers are much faster to access, and operating on memory requires loads and stores -> more instructions to execute
## memory operands
main memory are used for composite data, such as arrays or any form of dynamic data. if the amount of registers needed are too many, then we store in memory.

the flow for arithmetic operations:
- load values from memory into registers
- perform operations
- store them back to memory (if needed)

addresses are little-endian, and is byte-addresible.
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
#### good design demands good compromises
different formats makes decoding difficult, but they allow uniform 32-bit instructions. the design of risc-v aims to make formats as similar as possible.
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

`func6` - 6b | `immediate` - 6b | `rs1` - 5b | `func3` - 3b | `rd` - 5b | `opcode` - 7b

- the `immediate` indicates how many bits to shift.
- `slli` shifts left logical, filling empty space with 0s, meaning multiplication with $2^{i}$
- `srli` shifts right, filling with 0s, meaning dividing with $2^{i}$

### b-type: conditional operations
branch to a labeled instruction if a condition is true. otherwise, continue sequentially. branch instructions **is the most complicated instruction** the CPU will have to deal with, with second-most being the `load` operation.

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

## basic blocks 
a basic block is a sequence of instructions that has:
- no embedded branches (except at the end)
- no branch targets (except at the beginning)
the compiler will identify basic blocks to perform optimization, and this process can be further accelerated by an advanced processor.

## procedure calling (function calls)
generally, when calling a procedure, we have to go through 7 steps:
1. place parameters in registers `x10 - x17` or `a0 - a7`
2. transfer control to procedure
3. acquire storage for procedure (allocate memory)
4. perform procedure operations
5. place result in register for caller
6. return to place where procedure is originally called (stored in `x1`)

### call function: jump and link
`jal x1, procedureLabel`: 
- address of following instruction (the next line) is stored in `x1`
- jumps to the target address

uses a 20-bit immediate for larger range.

`imm[20]` 1b | `imm[10:1]` 10b | `imm[11]` 1b | `im[19-12]` 8b | `rd` 5b | `opcode` 7b

for a larger jump, for example, to 32bit addresses: 
- `lui` to load the first `[31:12]` to a temp register
- `jalr x0, imm[11:0](temp)` to jump to address
### return from function: jump and link register
`jalr x0, 0(x1)`
- similar to `jal`, but jumps to the address `(0 + x1)`
- uses `x0` as `rd` (`x0` cannot be changed)
- can also be used for **computed jumps** (for, switch/case statements)

## leaf vs. non-leaf procedures
leaf procedures don't call other procedures, non-leaf is the inverse.

an example:
```asm
leaf:
	addi    sp, sp, -24
	sd      x5, 16(sp)
	sd      x6, 8(sp)
	sd      x20, 0(sp)
	add     x5, x10, x11
	add     x6, x12, x1
	sub     x20, x12, x1
	etc...
```

when we use **non-leaf** procedures:
- save **return address**, **arguments and temporaries** needed after the call (callee saves `s`, caller saves `t`) inside the stack pointer. stack pointer always decrement in steps of -4 or -8, depending on the size.
- offset starts with 0, and grows **DOWNWARDS**.

storing 3 doublewords (8 + 8 + 8 = 24-bits):
```asm
addi    sp, sp, -24
sd      x5, 16(sp)
sd      x6, 8(sp)
sd      x20, 0(sp)
```

storing 3 words, 1 doubleword (4 + 4 + 4 + 8 = 20-bits):
```asm
addi    sp, sp, -20
sd      x5, 0(sp)
sw      x6, 8(sp)
sw      x7, 12(sp)
sw      x8, 16(sp)
```

then, it can be restored by:
```
lw      x8, 16(sp)
lw      x7, 12(sp)
lw      x6, 8(sp)
ld      x5, 0(sp)
addi    sp, sp, 20
```