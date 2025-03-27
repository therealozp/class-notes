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


