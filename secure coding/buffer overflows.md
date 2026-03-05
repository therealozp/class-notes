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
		- symbolic execution (white box): program analysis to determine, for all program blocks B, which inputs cause that block to execute. the idea is that symbolic execution will become too complicated as there are more blocks and inputs to cover it.
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
- compiler warnings
- 