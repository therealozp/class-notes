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

jal ra, func # store returning address PC + 4 to register RA	
	     # jump into func
func: 
jr ra

callee has access to regs t0-t6, and s2-s4
however, regs s0-s11 are the CALLER's resources (also called callee-saved registers, because callee is doing the backup)
in contrast, t registers are saved by callers. so it's called (caller-saved registers)

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
