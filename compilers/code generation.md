memory consists of 4 segments: code (also called text, because the hard-coded string literals are part of the code segment), stack, heap, and global variables (split into initialized and uninitialized).

addresses: 65535 ($2^{16}$ bytes) check 1: we have enough space in memory to store addresses (16 bits for now), while each DISM memory is stored as an `unsigned int`, which is 4 bytes.

the program stack is a **stack of frames**, aka **activation records**, that collect all data locally related to a method or a main block.

the program heap stores all the dynamically allocated data.

![[Pasted image 20250326181316.png]]

at program begin execution: 
![[Pasted image 20250407172043.png]]

the frame pointer points to the current stack frame. at any given point in time, there can **only be 1 frame pointer**.

the stack pointer points to the next available space for the stack to use. similarly, the heap pointer `hp` will point to the next spot available for heap use. stack will grow upwards, heap grows downward. 

**in DJ, the heap pointer only grows**, because we do not have a garbage collector.

DISM, by default, has 8 registers. using 3 of the 8 for `fp`, `hp`, and `sp`, we are down to 5. reserve another one for the hardwired 0, we now have 4 registers left to play with.

DJ has some control flow commands that evaluates and jumps when condition is set to 0, which can come in handy for systems that have a 0 register.
## invariants
- R7 always contains the frame pointer
- R6 always contains the stack pointer
- R5 always contains the heap pointer
- R0 always contains 0

assigning the registers like this, we can quickly check memory correctness by R7 > R6 > R5. the top frame from the stack will always be from main. 

every DJ expression gets translated to DISM code that, when finished running, leaves the expressions's result on top of the program stack. each such intermediate result is an **immediate** or **temporary.** this way, DISM is a stack machine.

no-op instruction: `mov 0 0; comment` used for comments. code gen needs 1 instruction per line.
## implementation
`codegen.c` will contain two main functions similar to type-check: `codegenExpr` and `codegenExprs`.

the process for pushing the a `NATLITERAL` onto the stack looks like:

![[Pasted image 20250407172309.png]]

for `printNat`:

![[Pasted image 20250407175829.png]]

for `PLUS_EXPR`:

![[Pasted image 20250407180049.png]]

> exam notes: use a 5-winged star (⭐) to define the action of outputting to a file.
> exam notes: underlining text indicates something that needs to be filled in.

```c
int codeGenExpr(ASTree * t, [context info]) {
	// MUST HAVE: initial checks
	if (t->typ == NAT_LITERAL_EXPR) {
		// fout is a global variable of type FILE *
		fprintf(fout, "    mov 1 %d\n", t->natVal);
		// after setting, also move it to the stack
		// DISM uses RTN (register transfer notation)
		// to make sense of what we are working on
		fprintf(fout, "    str 6 0 1; M[SP] <- R1 (a natliteral) \n");
		decSP(); // decrement stack pointer
	} else if (t->typ == NULL) {
		fprintf(fout, "    str 6 0 0; M[SP] <- 0 (a null) \n");
		decSP(); // decrement stack pointer
	} else if (t->typ == printNat(E)) {
		codeGenExpr(E, [same context info]);
		
		⭐lod 1 6 1; load M[sp + 1] for printing // stack read is going up
		⭐ptn 1; 
	} else if (PLUS_EXPR) {
		codeGenExpr(e1, [same ctx]);
		codeGenExpr(e1, [same ctx]);
		
		⭐lod 1 6 2; r1 <- 1st operand
		⭐lod 2 6 1; r1 <- second operand
		⭐add 1 1 2; r1 <- r1 + r2
		⭐str 6 2 1; store result of addition
		// pop one thing off the stack
		incSp();
	} else if (IF_THEN_ELSE) {
		// if (e0) {el1} else {el2}
		// for example
		int elselabel = labelNum++;
		int endLabel = labelNum++;
		
		codeGenExpr(e1, [same ctx]);
		⭐lod 1 6 1; load the test result into r1
		⭐beq 0 1 #___elselabel___
		incSp();
		// basically, check if e0 condition = 0, if yes, skip el1 and do el2
		codeGenExprs(el1, [same ctx]);
		⭐jmp 0 #___end_label___; // jump around the else statement
		
		⭐#___elselabel___: mov 0 0;
		incSp(); // safe increment
		codeGenExprs(el2, [same ctx]);
		⭐#___endlabel___: mov 0 0 ;
	}
}
```

```c
codeGenExprs(e1, e2, ...en) {
	codeGenExpr(e1, [same ctx]);
	incSP(); 
	codeGenExpr(e2, [same ctx]);
	incSP();
	...
	codeGenExpr(en, [same ctx]);
}
```

the reason why decrementing the stack pointer requires another function is because there are a few more nuances, namely, we need to make sure that `sp` doesn't collide with `hp`.

```c
void decSP() {
	⭐mov 1 1;
	⭐sub 6 6 1; // sp--
	// check if hp is still < sp
	//  labelNum is a global num init to 0
	⭐blt 5 6 #___labelNum___; // continuation branch,
	⭐mov 1 77 // out of stack mem error
	⭐hlt 1; out of stack mem
	⭐#___labelNum___: mov 0 0; // no op
	
	labelNum++; // note this does not have a star!
}
```

for branch names, if we keep reusing them, we will run into branch name duplicates. theoretically, we would require an infinite bank of names to pull from. to resolve this, we keep a global `labelNum` variable and keep incrementing it to generate infinite names.
