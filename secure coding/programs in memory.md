it is important for us to understand how program data is often stored and executed in memory. generally, it is divided into 4 big chunks
- heap: stores dynamically allocated data (i.e. from `malloc`, `new`, etc.)
- stack: stack of frames/activation records. each frame keeps track of data that is locally relevant to that function/method/procedure.
- globals/statics: contains all the global-scoped variables related to the program
- code (or "text"): contains all the code. sometimes also referred to as "text" because of all the string literals.

![[Pasted image 20260225160507.png]]

## during execution
consider the program code:

```c
void f() {
	... (1)
	g(args); (2)
	...
}
```

### before `g()` call
at point `(1)`
![[Pasted image 20260225161718.png]]
### stack preparation
at invocation point of `g(args)`, `f` knows at least 2 major things that `g` doesn't know:
- the arguments
- when `g()` finishes executing, where does it return to? (return addr)

so, before changing updating the frame pointer, `f()` would push the return address to the stack, as well as all the arguments related to calling `g()`.

![[Pasted image 20260225162458.png]]

### `g()`'s method prologue
then, we jump to code for `g()` or, `g()`'s prologue. at this step, the frame pointer gets updated, and `g()`'s locals is pushed on the stack. then, the old frame pointer gets pushed on as well, so that it can be updated later.

![[Pasted image 20260225163650.png]]
- note, that the frame pointer in x86 is called `ebp`, or "extended base pointer", as it is the base of the current frame
- the stack pointer is called `esp`, or "extended stack pointer"

### post-execution
then, after `g()`'s execution, we will have to "pop" g's frame off:
![[Pasted image 20260225164430.png]]

in words, during the call to jump to return address (which is where FP is already pointing to): 
- pop the return value off (if available) and stores it into a register to be pushed onto the stack later,
- the old frame pointer is determined to be a fixed length away from the current FP. we now update the FP back to where we intended,
- all of the related values for `g()` is popped off the stack,
- the return value (if available) is pushed.