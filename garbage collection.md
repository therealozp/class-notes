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

garbage collection means target code automatically deallocates garbage, usually in a separate module, the **runtime environment**. the RE is:
- constant for all source programs
- handles memory alloc + dealloc
- may be part of a VM/interpreter

C and C++ uses **manual** memory management, including manual deallocation (`free`, `delete`). most strongly-typed languages will come with a garbage collector, but C and C++, being a weakly-typed language, does not.

pros: 
- the programmer has complete control over memory, so much better optimization. gc takes non-trivial bursts of time, so we have control over when gc executes.
- program-specific memory deallocation

cons:
- human stupidity. the programmer will make mistakes, like:
	- free too little - **memory leaks** (garbage never gets collected)
	- free too much - **double free** (may corrupt the free list), or **use-after-free** (may create dangling pointer errors, where program access deallocated data)

## reference counting

```
class C extends Object {
	Object f;
	nat foo(nat n) {
		C o1;
		C o2;
		C o3;
		C o4;
		
		o1 = new C();
		o2 = new C();
		o3 = new C();
		o4 = new C();
		
		o1.f = o2;
		o2.f = o3;
		o3.f = o4;
		⭐1
	}
}

main {
	C obj;
	obj = new C();
	obj.foo(8);
	⭐2
}
```

at ⭐1, memory should look like:

![[Pasted image 20250416175531.png]]

at ⭐2, memory should look like:

![[Pasted image 20250416175930.png]]

note that now that `o1` and `o3` has 0 references, they are for sure garbage, so we collect them. while collecting them, their `f` fields and whatever they reference will have **their reference count decremented**.

now that `o2` also has a 0 reference, we can collect them as well. however, note that `o4` still has the reference from itself, so the collector doesn't count it!

**pros**:
- pretty simple (can be implemented for DJ)
- collection is performed incremental. it only ever gets really slow for large graphs with a lot of references.
- garbage is collected immediately as soon as reference goes to 0.

**cons**:
- major: cycles of garbage (such as `o4`) is not collected, so there will be memory leaks. solution: blame the programmer.
- major: typically high running-time overhead
- minor (common across all garbage collectors): object size will generally be bloated (by at least a bloat)
- medium: fragmentation. on its own, it doesn't really do anything to defragment memory.
## tracing
these are called tracing because it "traces" through the heap to find which is garbage. the real, industrial strength garbage collectors.
### mark and sweep
a lazy approach, does not execute until we run out of heap memory. as soon as an allocation fails due to insufficient heap space:
- **mark** (i.e. flag): treats the heap like a graph, marks all object we can reach from program variables (stack and globals). uses BFS/DFS to traverse and set flag in reachable objects.
- **sweep**: for all objects in the heap:
	- if object is marked, unmark it.
	- else, add to free list.

**pros**:
- all garbage gets collected (even cycles)
- no overhead until we need to collect (pay as you go principle)
**cons**:
- bloating
- does not handle fragmentation from collected objects
- may be a long pause when GC initiates
### mark and compact
similar to mark and sweep, except:
- compact the garbage
	- copy garbage in non-contiguous garbage, so compress it down to the bottom. going from addr 1 to `hp`, assign each object a (possibly) new address in the contiguous heap mem starting at addr 1.
	- update all object-type program variables including temporaries and fields to use the new addresses
	- going from 1 to `hp`, move each **marked** object to its new address.

**pros**:
- we don't even need a free list. all things that needs to be dealloc'ed will be at the heap pointer.
- solves fragmentation.
**cons**: 
- more overhead, even longer pauses.