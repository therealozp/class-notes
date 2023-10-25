## Bubble sort demo
for function `swap()`: 
```c
void swap(int* xp, int* yp) {
	int tmp = *x; 
	int *x = *y; 
	int *y = *tmp;
}
```

we can get the following assembly function: 

```asm
swap: 
	lw t0, 0(a0)
	lw t1, 0(a1)
	sw t0, 0(a1)
	sw t1, 0(a0)
	jr ra
```

and for the bubble sort function: 

```c
void bubblesort(int *a, int n) {
	int i, j; 
	bool swappped; 
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&a[j], &a[j + 1]);
				swapped = true
			}
		}
			
		if (!swapped) {
			break;
		}
	}
}
```

Note that the arguments `*a` and `n` are stored in `a0` and `a1` respectively. However, whenwe call the `swap(&a[j], &a[j + 1])` function, we will **still need** to use those two registers, because it is the **base address** and the **comparer** respectively. So, we will store this in `s3` and `s4`.

```
jal ra, func # store returning address PC + 4 to register RA	
	     # jump into func
func: 
jr ra

```
## who saves what?
callee has access to regs t0-t6, and s2-s4
however, regs s0-s11 are the CALLER's resources (also called callee-saved registers, because callee is doing the backup)
in contrast, t registers are saved by callers. so it's called caller-saved registers

**TLDR:** *s0-s11* registers will be saved by the **callee**, and *t0-tx* register will be saved by the **caller.**
[[#Important notes]]

## using the stack pointer
to allocate memory on the stack pointer, for example, s2, s3, and s4: 
 > allocate 4* number of regs = 12 bytes

so we can call: 

```
addi sp, sp, -12 # shifts stack pointer down to 12
sw s2, 0(sp) # stores from 0 to 3
sw s3, 4(sp) # stores from 4 to 7
sw s4, 8(sp) # stores from 8 to 11
```

**NOTE**: if it is a function calling a function, we have to **make extra space for the ra** register. So something like: 

```
sw ra, 12(sp)
```

After function call, restore everything back to original elements, and deallocate space on runtime stack

```
lw s2, 0(sp)
lw s3, 4(sp)
lw s4, 8(sp)
addi sp, sp, 12
```

## Important notes
**ALWAYS BACK UP S REGISTERS NO MATTER WHAT**

When calling the function, **always** back up *any s registers* that we **intend to use**, irrespective of whether it is occupied or not. 

## miscellaneous bullshit
### storing characters
To store a character in a register, do the same thing as C: 

```
addi t0, x0, '0'
addi t1, x0, '9'

addi t2, x0, 'a'
addi t3, x0, 'z'
```

note that ASCII codes are **unsigned**, so using lb and lbu has an equivalent effect. However, just use lbu. 
### negating values
To negate a value, use **XORI** with **negative 1** (which has bytecode 0xFFFFFFFF, or 1111 1111 1111 1111)

```
xori t0, t0, -1
```
### clearing bits / modulo by $2^n$
to clear a set number of bits from the beginning, or do a modulo operation, use **ANDI** with $2^n - 1$.

```
# to mod 16
andi t0, t0, 15
```

