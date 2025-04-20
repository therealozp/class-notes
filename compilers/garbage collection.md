consider the following snippet:

```
main {
	nat n;
	Object ob;
	while (n < x) {
		ob = new Object();
		n = n + 1;
	};
}
```

what is the maximum number that x can go to before the system breaks?

to evaluate this, we consider the memory after the last loop iteration, during the loop test fail (where n = x).

![[Pasted image 20250414180514.png]]

**garbage** is heap-allocated memory that isn't reachable from program variables, so no matter what you do, the program can never access this memory ever again. note that this is a strict definition, so as long as there is *one* control path where the program accesses this memory again, **it is not garbage**.

this memory can be released and re-used for other heap objects. 

C and C++ uses **manual** memory management, including manual deallocation (`free`, `delete`). most strongly-typed languages will come with a garbage collector, but C and C++, being a weakly-typed language, does not.

pros: 
- the programmer has complete control over memory, so much better optimization. gc takes non-trivial bursts of time, so we have control over when gc executes.
- program-specific memory deallocation

cons:
- human stupidity. the programmer will make mistakes, like:
	- free too little - memory leaks
	- free too much - double free, or use-after-free
