type-safe/strongly-typed languages provide type safety: **all** language-level values will only be used in appropriate ways (for example, no adding 2 functions together). 

type-safe languages: Java, Python, Ruby, most scripting languages. if your language is dynamically typed, might as well add type safety. values are usually stored in 
`[type tag | data]` formats.

weakly-type languages: **some** language-level values will only be used in appropriate ways e.g. C and C++. these languages are usually lower level, so it comes with more performance benefits.

untyped languages: no types. i.e. assembly, machine code, etc.

consider the following C function:

```c
void get_input() {
	char buf[1024];
	gets(buf); 
	// function def is char * gets(char *), from <stdio.h>
	// reads a line from stdin
	// stops at \n or EOF
	// null terminates the string
}

void main(int argc, char *argv[]) {
	get_input();
}
```

if there is a `gets` call on the exam, 9 times out of 10 it will be a buffer overflow attack.

while `get_input()` runs:
![[Pasted image 20260302161233.png]]

one strategy can be when the attacker inputs more than 1024 characters, the null-termination can overwrite whatever is on the main frame. typically, for a 64-bit architecture, one address is 64 bits = 8 bytes. 1 character is 1 byte. for this to work, the attacker would only have to write an extra 8 characters (to cover address 1024-1031), which causes `argv` to be replaced with the null termination.

![[Pasted image 20260302161756.png]]

another can be manipulating the stack such that `buf[0] - buf[1023]` will write some sort of malware, and the RA gets pointed to `buf[0]`. then, after the execution finishes, the PC points to the start of malware.

![[Pasted image 20260302161942.png]]

also called the stack-smashing attack.
### no-op sled/slide
in the case that the attacker cannot exactly pin-point the return address to point the malware to, a clever trick would just be inserting a bunch of no-ops so the RA is a better "landing" as the PC moves down to the malware.

![[Pasted image 20260302162551.png]]

## protection
the biggest protection that modern computers have taken is implementing an access-control mechanism that **disallows stack execution**. 

one implementation is the no-execute bit (NX bit), to mark which segments that are not executable. this is a hardware mechanism, and marked by the OS to see which segments can't be executed. ideally, all segments apart from code should be marked NX.

the OS uses NX bits to implement execution space protection. Windows call them DEP (data execution protection). openBSD calls it W^X (write xor execute), meaning you can ONLY do one or the other.

but, even with properly-implemented NX bits, attackers can still:
- change RA to valid code (**not** confused deputy attack)
	1. point to privileged function, right after the security checks to bypass checks.
	2. begin `exec` system call (for example, via `cmd.exe` or `/bin/sh`, which executes arbitrary scripts given as an argument, and passes the script on the stack. (called a **return-to-libc** attack)
	3. return-oriented programming: find an expressive set of "gadgets" and chain them together (a ROP chain) to form malware
		- "gadgets" are short sequences of instructions in code mem
		- they usually end with `ret` ("return" instruction)
		- there are a Turing-complete set of gadgets on any machine running the C library. so, an attacker can basically put together ANY algorithm.
- the attacker can overwrite basically anything, from locals, old frame pointers, intermediates, etc.
	- if the locals are important (loop variables, secret keys, etc.), they can all be read or overwritten. 
	- there is also the class of heap-based buffer overflows, where they could overwrite stuff on the heap as well.
		- if the stack-heap boundary floats around (like it does in a lot of architectures), it could overwrite stuff on the stack as well
	- return addresses are a big problem, but things like these can cause trouble too.

## finding buffer overflows
1. the ideal case is attackers have access to source code. so, examine source, if available.
2. otherwise, they can decompile the executable, or reverse-engineer it.
3. fuzz-testing the program
	- fuzzing: use software to give the program a bunch of corner cases (very long/short inputs) and **monitor unexpected behaviors**. does it crash? does it do any handling?
	- checking memory usage like memory leaks (if the memory consumption keeps growing)
	- you can fuzz with source code (white box) and without (black box).
		- symbolic execution (white box): program analysis to determine, for all program blocks B, which inputs cause that block to execute. however, SE will become too complicated as code grows, because there are far more blocks and inputs to cover it.
		- concolic execution (concrete symbolic execution): analysis can be guided by concrete input. this is combining symbolic execution with with choosing specific inputs. 

```
x = 2
x += y

  v this is a guard
if x > 4 {something}
             ^ this is a block
```

## Morris worm
the most widespread buffer overflow attack. exploits the `fingerd` daemon (background processes), which displays information about users.

"worm" is kind of similar to a virus (self-replicating malware), but "worms" specifically target networks. launched by Robert Morris in 1988, while he was a student.

stack-smashed with more characters 

## prevention
- use extreme caution (or avoid entirely) the functions `gets`, `scanf` (`gets(buffer)` is equivalent to `scanf("%s", buf)`), `strcpy`, `strcat`, `sprintf`, `sscanf`, `fscanf`, etc.
- instead, use n-ary versions of unsafe functions. still not exactly safe, because it also now depends on the programmer as well.
	- these *might* differ on how they handle corner cases, i.e. null terminators, so still needs a manual analysis instead of straight replace
	- `char * fgets(char * str, int num)` which lets you define limit from the start. 
	- `char * gets_s(char * str, rsize_t n)`, available since C11
	- `strncopy`

```
[||||||||] dest buf <- overflowing this one
[||||||||||||||||||||] src buf
```

- find and use safer string libraries
- check boundaries on array operations
- use type-safe programming languages

there are additional protections provided by the modern OS, for example:
- compiler warnings/errors. some functions don't generate warnings despite being unsafe (`scanf`, `strcmp`, etc.)
- stack canaries/speed bumps - StackGuard
- address space layout randomization - ASLR
- control flow integrity (CFI)
### StackGuard
inserts a canary in between the return address and other information. the idea is the canary is a secret value that the attacker doesn't know about, and before we jump to the address defined by RA, we check that the canary has not been modified.

canaries may be reused.

1. put a "random" (crypt-secure) and/or a null byte right before the RA
2. check canary hasn't been verified before jumping to the RA.

the "random" can sometime be a null byte. although it offers less protection, it ensures that all string reads end right there without infringing on the return address.

limitations: 
- attacker might guess or brute force canary
- attacker might exploit other vulnerabilities to read the canary off the stack (i.e. through format-string vulns.)
- only mitigates RA-overwriting attacks

this only exhibit false negatives, never false positives. there's never any reason why the canary should ever be modified, so there will never be a false positive. false negatives is when the return address is modified with the same value, or with a zero-overwrite.

### ASLR
idea is to make it harder for attackers to figure out pointer values by randomizing the base address locations of each of the segments in memory (stack, heap, globals, code/"text"); so that the pointer values are different from machine to machine.

ASLR tries to protect pointers essentially by shuffling everything.

limitations:
- attacker may still exploit other values (e.g. format string vulns) to learn the base addresses
- attacker can guess/brute force the base addresses
	- finding essentially one pointer into the segment will essentially give the offset and the base address of the segment. so, even though the base addr is different, the offset remains the same.
- only tries to protect pointers (including return addresses)

### control flow integrity
assumptions:
1. no-write-code is active
2. NX bits are in place
3. special codes are only used for this purpose. nothing else.

a big problem in C/C++ vulnerabilities is that there is usually a lot of jumps/branches taken that we really should **never** be able to.

so, we can rely on the control flow graph (as a directed graph) of the program to check if this destination is allowed from X source.
- treat each instruction as a node/vertex
- there exists and edge (from $i \to j$) when an instruction $j$ can immediately follow $i$.

before any computed jump instruction, check that the destination is valid. 
- embed at every valid destination a special code (doesn't need to be secret, but needs unique in the fact that it serves no other purpose)
- check before jumping for the correct code

```
-> check for the correct code here
beq zero, R5, #1
// passes through here if not zero
...

#1: nop **code** instruction
```

even with the simplest implementation with the same code for every single valid jump destination, we get the benefit of guarding privileged function execs. so, consider the old example of the file reading before security checks, the attacker can only jump to the beginning of the file open - meaning no security checks can be bypassed.

limitations:
- "mimicry" attacks: sometimes, CFGs are imprecise. the attacker can follow the valid path inside the graph to jump to disallowed instructions (as long as it stays on the valid control flow path).