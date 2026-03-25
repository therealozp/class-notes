```c
// variatic functions - variable no. args
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