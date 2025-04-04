1. calculate total number of cycles needed to run the query
the cache size is 8MB, which is $2^{3}\times 2^{20} = 2^{23}$ bytes. so, we will need 23 bits of indexing for the block index and the offset field. the memory address format looks to be 32 bits, so we reserve the first 9 bits for the tag field.

however, if we look at the base addresses of:
- `country`: `0x05000000`
- `language`: `0x06000000`
- `position_hometown`: `0x07000000`

the last 23 bits of these arrays are all `000 0000 0000 0000 0000 0000`, which means they will be mapped to the same cache block. the number of entries loaded into the cache per array fetch is:
$$\frac{64\text{ bytes}}{4 \text{ bytes per entry}} = 16 \text{ total entries }$$
but, because they all get mapped to the same cache block, every time the code tries to access each of the `country`, `language`, or `position_hometown` arrays, it invariably results in a **miss**. so, each iteration incurs 3 misses in total.

for example, in iteration 1:
- first ever memory access to the `country` variable, so we fetch the first 16 entries and store them to the cache.
- after the first comparison, we continue to access the `language` array. CPU attempts to look inside the cache, sees that the desired block is currently populated, but **with the wrong data**. so, it evicts the entry, and decides to fetch its `language` array.
- after it determines the branch, it now attempts to modify the `position_hometown` array. it also looks inside the cache, sees the same block populated with the wrong data. it then evicts the entry to fetch the `position_hometown` array.  

this will cost $3 \times 100 = 300$ cycles per iteration. for 32768 entries, the total number of cycles required is: $300 \times 32768 = 9,830,400 \text{ cycles}$.

2. filling out AMBIT code
since AMBIT processes data in batches (rows of DRAM at a time), we can calculate the number of batches we need:
$$\frac{2^{15} \times 4}{8 \times 2^{10}}=\frac{2^{17}}{2^{13}}=16 
\text{ batches}$$

to compare if the two results are the same, we can use the XOR to check if, at any point the result is not 0, this means the values are different. if the results is 0, the two values are equal.

finally, to store data back, we use De Morgan's law:

```c
student.country[i] == "Switzerland" && student.language[i] == "German"
```

is the same as 

```c
not (student.country[i] != "Switzerland" || student.language[i] != "German")
```

so, the logical choice here would be to use the `bbop_or` command, as we essentially are writing to the final input array `false` if both of them are equal, or `true` if either of them are not equal. since AMBIT usually works with DRAM cells that has a dual contact capacitor, it can store both the value and its complement at the same time. so, we just take the complemented value, and we get the correct result.

final code:

```c
for ( int i = 0; i < 16; i ++){
	// offset the array by the base addr
	bbop_xor 0x08000000, 0x05000000 + i*8192, 0x0A000000 ;
	bbop_xor 0x09000000, 0x06000000 + i*8192, 0x0B000000 ;
	bbop_or  0x07000000, 0x08000000, 0x09000000 ;
}
```

3. final speedup
each `bbop_xor` command takes 25 ACTIVATE commands, and 11 PRECHARGE command, for a sum total of $25\times 50 + 11 \times 20 = 1470 \text{ cycles}$.

each `bbop_or` command takes 11 ACTIVATE commands, and 5 PRECHARGE commands, for a sum total of $11 \times 50 + 20 \times 5 = 650 \text{ cycles}$.

so, the total cycle cost is:
$16\times(1470 \times 2 + 650) = 57,440 \text{ cycles}$

for a speed up of $171.142$ times.

## Part 2
1. determine $K$ and $M$.
the calculation is determined as: 
$$t_{c p u } = K\times \text{num\_operations} + \frac{\text{num\_bytes}}{M}$$
4-bit elements is 0.5 bytes. in the first case, we need to iterate through 65536 elements, consisting of 1 arithmetic, 2 data reads, and 1 data write. so, in total we are doing $65536\times 3\times 0.5 = 98304$ bytes, which gives us our first equation:  
$$100 \times 10^{-6} = K\times65536 + \frac{98304}{M}$$
in our second case, we are only moving data, so there are no arithmetic operations to be done. so, we are only moving data, 102,400 elements of 4 bits. there is one read from the first array, and write to another array, which makes for the equation:
$$10\times 10^{-6}=\frac{102400\times 0.5\times 2}{M}$$
so, $M=1.024\times 10^{10}$, or 10.24 GB/s for short.

substituting this into our first equation, we also yield K to be:
$$K=-\frac{\frac{98304}{1.024\times 10^{10}} - 100\times 10^{-6}}{65536}$$
so, $K = 1.38\times 10^{-9}$, which is about 1.38ns per operation.

2. AMBIT code

```c
for (int i = 0; i < ; i++) {
	// let 0x00900000 store the C_in values
	// calculate the sum first
	bbop_xor    0x00700000, 0x00A00000 + i * 8192, 0x00B00000 + i * 8192;
	// XOR the temp result with carry values to get sum
	bbop_xor    0x00C00000 + i * 8192, 0x00700000, 0x00900000;
	
	// calculate the xor(a, b) AND c_in 
	bbop_and    0x00700000, 0x00700000, 0x00900000;
	bbop_and    0x00800000, 0x00A00000 + i * 8192, 0x00B00000 + i * 8192;
	
	// calculate the C_out for the next iteration
	bbop_or     0x00900000, 0x00700000, 0x00800000;
}
```

3. theoretical operations per second
to calculate this, there is a few things we need to consider. because the DRAM rows are 8KB long, we are able to operate on $2^{13}\times 2^{3} \times 2^{3}$ bits at the same time.

as discussed above, we are also able to calculate the time it takes to run 1 iteration:
- each `bbop_xor` command takes 25 ACTIVATE commands, and 11 PRECHARGE command, for a sum total of $25\times 20 + 11 \times 10 = 610 \text{ ns}$.
- each `bbop_and` and `bbop_or` command takes 11 ACTIVATE commands, and 5 PRECHARGE commands, for a sum total of $11 \times 20 + 5 \times 10 = 270 \text{ ns}$.
- in total, we have 2 XORs, 2 ANDs, and 2 ORs, which is $610 \times 3 + 270 \times 2 = 2370 \text{ ns}$/iter

so, for each bit, we can run $\frac{1}{2030 \times 10^{-9}}$ operations per second. with $2^{16}$ bits, we are able to run:
$$\frac{65536}{2370 \times 10^{-9}} = 2.765 \times 10^{10}\text{ OPS}$$

