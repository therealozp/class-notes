#memory

A 1-to-$n$ scheme of cache mapping, where every block can be mapped to **every other cache** without limitation. Unlike direct mapping, the tag field of the cache memory **does not** have an impact on the memory, so if there is 4 blocks of cache memory and 32 B of main memory: 
- Each block of cache memory can store **every value** of blocks from 0 to 31
- Tag field in this case will be 5

Also unlike direct mapping, we have to check **all cache blocks** to determine a hit or miss, because now each cache block stores all possible values, so we **do not** know where the information goes. [[Direct Mapped# Comparator]]
