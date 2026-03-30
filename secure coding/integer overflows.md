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

which is $2^{30}+2$. when computing the actual length of the malloc, there isn't enough space within the integer to hold the result, and after the shift operation, we get 
