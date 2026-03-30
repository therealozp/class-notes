`printf()` is a variadic function, which accepts a variable number of arguments.

```c
printf("%s %d %x %o %%\n", "x", 91, 91, 91);
// > x 91 5B 133 %

// %s prints a string
// %d prints decimal number
// %s prints hexadecimal
// %o prints octal
```

the format strings are complex, and can usually take the form of `%[flags][width][.precision][length][specifier]`
- `flags` specifies formatting, such as whether to include `0x` at the start of hex print
- `width` defines the minimum number characters to print
- `.precision` specifies how many decimals 

vulnerable code: `sprintf(buffer, "Warning: %10s -- %8s", msg, uname)`. assume that buffer is 32 bytes. because we print minimum 10 for message and 8 for username, as long as the username is > 8 characters, the buffer will be overflown.

```c
printf("Username is");
if (is UNdef) printf(uname);
else prinf("<none>");
```

in this case, if the username is typed in as `%s`, the machine code will instead look for the next immediate value **on the stack**, and interpret it as a `char *`, and leaking values. to mitigate, a common rule is to never use untrusted input as a format string. 

```c
#include <stdio.h>

void f(char * u) {
	char s[512];
	snprintf(s, sizeof(s), u);
	s[sizeof(s) - 1] = 0;
	printf("%s", s);
	...
}
```

consider the case where `u = "%s"`. then, at the call to `snprintf`:
![[Pasted image 20260325155211.png]]

`snprintf` will print the contents of `u` into s. because no further arguments are provided, it marches up the stack and finds the return address. since the `snprintf` call is made on `%s`, the RA is treated as a `char *`. since the RA is pointed to code memory, this code will print up to 511 characters to where it is pointed.

consider `u = "%x%x"`.
instead of treating the information as `char *`, `snprintf()` will directly print the return address, and the old FP that belong to `f()`. this already defeats ASLR, because the return address that points to code memory is leaked (offset can be found to compute base address of code); as well as the old FP (to compute base address of stack).

consider `u = "%p%p"`. pretty much the same effect as `%x%x`, but sometimes the pointer values are printed in system-specific formats.

sometimes, compilers can inline some system calls to avoid all the overhead of pushing/popping values on the stack. so, instead of making a new frame for `snprintf`, it will be made inline:

![[Pasted image 20260325160648.png]]

if the variable `u` becomes `%s` now, the old FP becomes the string pointer, which points to the frame before `f()`'s frame. so then, the stack memory contents in the frame are printed, which can leak return addresses, canaries, pointers to the heap, another old FP, potentially defeating ASLR entirely.

consider `u = "abcd%d %n"`, and assume an address (an integer) is 4 bytes long.
the `%n` specifier doesn't actually print anything, but instead writes the number of printed bytes (a count) to whatever pointer is pointed to a stack. in other words, the next item on the stack is treated as an `int *`, then writes number of bytes printed so far into that location. 

`printf("ab%n", &i)` will print out `ab`, and set `i` to 2.

so, printing with this `u`:
- `s[0]` is set to `a`
- `s[1-3]` is set to `bcd`
- `s[4-7]` is set to the old frame pointer
- right now, 8 bytes of data has been "printed", and `%n` says "just take the next thing on the stack and write 8 that location"
- so, `M[abcd] = 8`.

in reality, the `%d` specifier isn't even used - only for illustrative purposes at this point. the attacker could specify any arbitrary access, and can write whatever they want by controlling the length of the string. the attacker gains arbitrary write access (overwriting return addresses, secrets, and without write protections in code memory can overwrite code).

## mitigation
one of those things where it is undecidable to catch all of these errors to catch them statically. with some level of compiler warnings, we are able to identify some, but cannot be all.

- use type-safe programming languages (no issue of leakage here)
- avoid using untrusted inputs as format strings. if you have to, have to sanitize it carefully.