memory consists of 4 segments: code (also called text, because the hard-coded string literals are part of the code segment), stack, heap, and global variables (split into initialized and uninitialized).

addresses: 65535 ($2^{16}$ bytes) check 1: we have enough space in memory to store addresses (16 bits for now), while each DISM memory is stored as an `unsigned int`, which is 4 bytes.

the program stack is a **stack of frames**, aka **activation records**, that collect all data locally related to a method or a main block.

the program heap stores all the dynamically allocated data.

![[Pasted image 20250326181316.png]]

at program begin execution: 