in C/C++, everything is an integer (i.e. integer is a primitive).

assuming a 32-bit architecture:
```c
void f(unsigned int len) {
	float * fa = (float *)malloc(len * sizeof(float));
	// the arguments to malloc is a size_t, an alias for unsigned int
	fa[len - 1] = 3.14;
}
```

suppose that the attacker enters a length of a 32 bit number as:

```
31 30 29 28 17 ... 2 1 0
0  1  0  0  0      0 1 0
```

which is $2^{30}+2$. when computing the actual length of the malloc, there isn't enough space within the integer to hold the result, and after the shift operation, the MSB drops off, leaving us with only 16 as the `malloc` size. 

so, even though only 16 bytes is allocated, the `fa[len - 1] = 3.14` still overwrites the same `01......01` addresses away.

## mitigation
- check overflow/underflow when type casting
- type safe languages MIGHT help, but some static analyzers can help as well. the previous example is an int overflow **and** an out-of-bounds write, and type-safe languages like Java would still prevent this OOB write, but the int overflow **still happens**.
- use safer numeric libraries