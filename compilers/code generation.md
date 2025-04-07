memory consists of 4 segments: code (also called text, because the hard-coded string literals are part of the code segment), stack, heap, and global variables (split into initialized and uninitialized).

addresses: 65535 ($2^{16}$ bytes) check 1: we have enough space in memory to store addresses (16 bits for now), while each DISM memory is stored as an `unsigned int`, which is 4 bytes.

the program stack is a **stack of frames**, aka **activation records**, that collect all data locally related to a method or a main block.

the program heap stores all the dynamically allocated data.

![[Pasted image 20250326181316.png]]

at program begin execution: 

the frame pointer points to the current stack frame. at any given point in time, there can **only be 1 frame pointer**.

the stack pointer points to the next available space for the stack to use. similarly, the heap pointer `hp` will point to the next spot available for heap use. stack will grow upwards, heap grows downward. 

**in DJ, the heap pointer only grows**, because we do not have a garbage collector.

DISM, by default, has 8 registers. using 3 of the 8 for `fp`, `hp`, and `sp`, we are down to 5. reserve another one for the hardwired 0, we now have 4 registers left to play with.

the "canonical" definition:
- R7 always contains the frame pointer
- R6 always contains the stack pointer
- R5 always contains the heap pointer
- R0 always contains 0

assigning the registers like this, we can quickly check memory correctness by R7 > R6 > R5. the top frame from the stack will always be from main. every DJ expression gets translated to DISM code that, when finished running, leaves the expressions's result on top of the program stack.

