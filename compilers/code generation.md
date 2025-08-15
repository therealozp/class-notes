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

for `NEW_EXPR`:
```
1. let n = num fields
2. check HP + n + 1 < MAX_DISM_ADDR
3. let t = type# for C
4. *mov 1 1
5. repeat n times:
	1. *str 5 0 0; allocate a field
	2. *add 5 5 1; HP++
6. *mov 2 t; R2 <- new object type
7. *str 5 0 2; top of heap = type
8. *str 6 0 5; push new object address
9. *add 5 5 1; HP++
10. decSP();
```

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
## layout
1. initialize `fp`, `hp`, `sp` (max of `fp` is 65536, of `hp` is 1)
2. allocate space for main locals
3. call `codeGenExprs(main block)`
4. `⭐ hlt 0; ` normal program termination
5. create landing pad for the method `* #class1method0: mov 0 0`
6. prologue for class 1, method 0: allocate locals, initialize to 0
7. body of class 1, method 0
8. epilogue for class 1, method 0: clean up and pop things off
repeat 5, 6, 7, 8 for any other methods.

**finally:** have an execution lookup table to know what is being called. at this step, we generate the `vtable`.

steps 1 and 2 form the **main block prologue**, step 4 is the **main block epilogue**. essentially, a *prologue* is code that is run before the main block/method body. 
active callers:
- method prologue
- method body
- method epilogue
## method calls
that means we also need a label to mark the prologue/epilogues of each method in each class.

at the function call site, we know the parameter and the return address. so at the return address, we are going to push the return address `ra` and the parameter, and inside the prologue, we will be able to allocate the locals.

just before the method prologue (codegen for method call must make stack like this)

![[Pasted image 20250409175025.png]]

return address is relevant to the callee's frame. 

the dynamic caller object address goes next, so we can always make sure that when `this` is called, it will always be in the position `calleeFrame - 1`.

if you want to add more arguments, the dynamic incoming arguments can come right after, and keep track of how many arguments there are.
### code gen for methods
the caller does this and jumps to the vtable and lets the vtable figure out the rest.
1. make `return_label = label_num++`
2. push `#__retLabel__` on the stack
3. push `this` if `ID(E)` or `codeGenExpr(E)` if we are executing `E.ID(E)`.
4. push static class and static method numbers for method being called
5. do `codeGen(expr_inside_parentheses)`
6. jump to the vtable, to figure out which prologue to execute: `*jmp 0 #VTABLE`. because all **labels are numbers**, the `VTABLE` label will never conflict.
7. `*#__retLabel__: mov 0 0`, return here from method.

vtable will not overwrite anything, but only read them. specifically, it reads the 3 values after `ra` and figures out which prologue to jump to.

## examples
consider the following DJ code:

```java
class C1 extends Object {
	nat f(C1 o) { 
		o.g(3); 
	}
	nat g(nat n) {
		n;
	}
}

class C2 extends C1 {
	nat g(nat n) {
		n + 2;
	}
}

main {
	C1 c;
	while (1) {
		if (readNat() == 0) {
			c = new C1();
		} else {
			c = new C2();
		}
		readNat(c.f(c));
	}
}
```

in the above examples, `c` can be different objects at compile time, depending on which input is being fed into. **statically,** `c` is an instance of `C1`, but dynamically, *we do not know*. so, when we are trying to execute `f` and it eventually calls `g`, **which `g` are we calling?** 

therefore, this necessitates the use of the vtable. a vtable is a virtual method table (aka dynamic dispatch table) that will dynamically figure out which method is being called. 

when trying to the dynamic caller object address, static class #, and static method #, **do not use the frame ptr**. we do not know how big the temporaries are going to be. instead, use `sp` because we know that we only have to count a fixed amount (i.e. +2, 3, and 4). 

> there can only be 1 `vtable` per program. `vtable` should not modify stack values.

```
vtable jumps to correct method prologue
based on values @ M[sp + 2], M[sp + 3], and M[M[sp + 4]] -> for type
```

the `vtable` for the above function would be: 

| static class # | static method # | dynamic caller type | dynamic class # | dynamic method # |
| -------------- | --------------- | ------------------- | --------------- | ---------------- |
| 1              | 0               | 1                   | 1               | 0                |
| 1              | 0               | 2                   | 1               | 0                |
| 1              | 1               | 1                   | 1               | 1                |
| 1              | 1               | 2                   | 2               | 0                |
| 2              | 0               | 2                   | 2               | 0                |

![[Pasted image 20250414172202.png]]
## ID versus ID = E
for operations on the standalone ID, such as `n == 3` or `obj == null`, we care about what the actual value of the ID `n` is. for other sets of instructions, such as assignment `n = 3` or `obj = null`, we don't necessarily have to differentiate at all.

so, for the standalone ID `ID`, we need the `rvalue` of the expression (aka the value). by contrast, for ID = E, we need the `lvalue` (or left value), which is the address. we can easily convert the `lvalue` into an `rvalue`, but impossible to do the reverse.

### code gen for ID

```
if ID is a param/local
	push the rvalue on the stack
else
	ID must be a field of the `this` (calling) object.
	1. get field offset for the ID within the object
	2. using offset + base address (of the this object), compute A = address of selected field
	3. push M[A] onto stack.
```

consider the following:

```java
class C1 extends Object {
	nat m;
}
class C2 extends C1 {
	nat n;
}
class C3 extends C1 {
	nat p;
}
class C4 extends C2 {
	nat q;
}
```

how will these classes be structured in memory? a rule to remember is to **always layout inherited field first.**

no matter what, we want the offset for C1 (no matter its dynamic class) will always be constant. so, we can have the cascade effect that we desire.

![[Pasted image 20250414173948.png]]

for checking `E.ID`, we follow a similar concept, except:
1. ID cannot be param/local. so we can codegen E to get base object address, as well as the select ID field in that object
2. check and halt if E evaluates to null.

for assignment operations such as `ID = E`, we do the same operations for ID, except:
1. we only need to compute lvalue = A for ID
2. also have to codegen the expression to get a result `r`
3. store `r` in memory at address A
4. make `r` be the value on top of stack. since codegen already handles this, we don't need to pop the value at all.

for dot-assignment operations such as `E1.ID = E2`, we do same operations as for ID = E, except:
5. `ID` cannot be a local or parameter, must be a field of `E1`, so we will need to codegen `E1` to get the base address 
6. check and halt if `E1` evaluates to null
7. code gen for `E2` before `E1`
