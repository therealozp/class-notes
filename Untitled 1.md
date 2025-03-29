- launch a thread for each hashing algorithm -> load data for the next 4 with the another thread -> 3.5x
- 4 threads for each hashing algorithm -> 3.2x
- 2 threads, each thread calls 4 each for each hashing algorithm -> 3.2x
- changed the hex-hash printing algorithm (general optimization)
- ran in batches of 50, 6 threads and 8 threads: 1.1x - 1.2x speedup
- 8 threads free for all: 1.6x
- producer-consumer straight up timed out
- 8 threads divide into chunks and split -> 2.95x
	- changed hex digits printing to using static variables and bit manipulation; changed compare function: 3.57x
	- dynamic resizing of the input array: 4.46x
	- binary searching the hash instead of linear searching: 4.46x
	- hash-map: chaining: 4.31x
	- hash-map: chaining and locking: 4.48x
	- hashmap: FNV hashing algorithm: 4.69x
	- hashmap: open-addressing, linear scan: 4.42
	- open-addressing, quadratic scan: 4.05x
	- conditional binary search with file IO optimizations: 5.27x



