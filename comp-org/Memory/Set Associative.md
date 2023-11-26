w> Aims to combine direct mapping and fully associative cache schemes.

A **set** is a group of blocks that can be indexed. For a number of $2^n$ sets, we will need $n$ bits for **set indexing**. In an *$n$-way set associative* scheme, there will be $n$ **blocks per set**

1. Implements direct mapping scheme to map a **block** of memory, and chooses a set to go in.
	- get the **number of sets in cache** = number of blocks in the cache % $n$ (the number of blocks per set)
	- get the **set index** = block address % no. of sets in cache
	- for a set index of $2^n$, $n$ bits will be used for the set index. 
2. After a set is chosen, implements fully associative mapping to pick **any** block in the set to put in.
	- each block will have a **tag** and a **valid bit**, used to identify the **block**, and *NOT the set.*
	- within each set, the lookup scheme is completely fully associative.
### Comparator
Since the set index is **extracted directly from the main memory address**, we do not need to compare this with the set index again. Therefore, the number of comparisons we have to make is $n$, for **every block in the set** (aka the fully associative scheme)