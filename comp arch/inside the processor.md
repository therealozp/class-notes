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
## data path
the first-cut data path does instruction in one clock cycle. so, each element **can only do one function at a time**, and separation of data mem. versus instruction mem. is needed.
### registers and ALU
the register file stores **32-bit** values. each register is 5 bits long, and 2 registers can be read at a time. 

another 4 bits is used for the ALUControl, which maps the intended function to its corresponding function inside the ALU. note that the opcode only ever really matters to in determining what the ALU should execute. most other instructions depend on the ALUOp as the driver.

| opcode              | ALUOp | operation        | opcode field | ALU function | ALU control |
| ------------------- | ----- | ---------------- | ------------ | ------------ | ----------- |
| load                | 00    | load to register | XXXXXXXX     | add          | 0010        |
| store               | 00    | store register   | XXXXXXXX     | add          | 0010        |
| beq                 | 01    | branch           | XXXXXXXX     | subtract     | 0110        |
| r-type instructions | 10    | add              | 100000       | add          | 0010        |
|                     |       | subtract         | 100010       | subtract     | 0110        |
|                     |       | and              | 100100       | and          | 0000        |
|                     |       | or               | 100101       | or           | 0001        |
### memories
to fetch instructions or read/write words, the memories need to be 32-bits wide.
### control
sends out the necessary control signals inside the datapath indicating which components to fire on different types of instructions. 

a signal is **asserted** when its logical state is true, and **de-asserted** when it is false/unknown.

behavior with the 1-bit control MUX:
- when the selection bit is set (1), the MUX selects the input corresponding to 1.
- otherwise, it will select the data line coming into 0.

- **`Branch`**: determines whether a branch is to be taken.
- **`RegWrite`**: enable writing to a register file.
- **`MemToReg`**: controls whether data is written back **to the register file**.
- **`MemWrite`**: enables writing to the data memory.
- **`ALUSrc`**: when `0`, the second operand is provided inside the register `rs2`. when `1`, the second operand comes from the immediate itself.
- **`ALUOp`**: specifies the operation the ALU should perform.

| instruction / control lines active | Branch | MemRead | MemToReg   | ALUOp | MemWrite | ALUSrc | RegWrite |
| ---------------------------------- | ------ | ------- | ---------- | ----- | -------- | ------ | -------- |
| r-type instructions                | 0      | 0       | 0          | 10    | 0        | 0      | 1        |
| load                               | 0      | 1       | 1          | 00    | 0        | 1      | 1        |
| store                              | 0      | 1       | irrelevant | 00    | 1        | 1      | 0        |
| branch                             | 1      | 0       | 0          | 01    | 0        | 1      | 0        |
### r-type
- reads two register operands
- performs an arithmetic or a logical operation
- writes result to a register
### load/store
- read register operands
- calculate address using the 12-bit offset. however, since ALU arithmetic requires all number to be a nice 32-bit size, the ImmGen component sign-extends it.
	- `load`: read data memory and update register
	- `store`: writes register value to memory
### branch 
- read register operands
- compare operands by using the ALU **subtraction**, and check for zero output.
- calculates the target address: 
	- sign-extend the **displacement**, or how far an instruction is from the target instruction.
	- shifts left 1 place to account for halfword displacement
	- adds to the PC value

the `PCSrc` signal is the one that determines whether the control flow branches or not. this signal is controlled by an AND gate, and:
- will only be set if the `Branch` signal and the `ALUZero` are both set (e.g. the condition satisfies). otherwise, it is zero.
- control sets `Branch` only during a `beq`, otherwise, `PCSrc` is 0.