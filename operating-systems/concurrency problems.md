## the dining philosophers
issue occurs when all 5 philosophers grab their forks at the same time, and none of them will release forks for the other.

there are a few ways to resolve this problem:
- **philosophers pick the lowest-numbered fork first**. this way, the highest-numbered fork will always get picked last, and the symmetry will be broken.
- **limit to to only $n - 1$ philosophers eating at a time**
- **symmetry breaking**: even-numbered philosophers try to pick left first, then right. odd-numbered picks right, then left.

## non-deadlock bugs
make up the majority of concurrency problems.
### atomicity violation
when the desire serializability is failed. for example, MySQL implements the following:

```c
Thread1::
if(thd->proc_info){
	…
	fputs(thd->proc_info , …);
	…
}

Thread2::
thd->proc_info = NULL;
```

2 threads are trying to access this at the same time, which is bad. to solve, wrap a mutex around where they try to access data.

### order violation
when a specific order is not enforced. recall the ordering mechanism in [[semaphores#as condition variables]] where we want the parent to always execute after the child.

to resolve this, let the higher-order function signal a condition variable, and the lower-order function waits on that signal. 

## deadlock bugs
### why do they occur?
oftentimes, this is due to **complex dependency** between components.

another reason is **encapsulation**. because everything is hidden, we mean to make it modular. however, modularity is not good for locking and concurrency.

take the example of the `Vector` class in Java, and the `AddAll()` method.

```java
Vector v1, v2;
v1.addAll(v2);

// another thread
v2.addAll(v1);
```

we need both locks on `v1` and `v2` to have everything execute correctly. however, because the routine acquires these in some arbitrary order, if the other thread also calls `v2.addAll(v1)` at close to same time, we can have a deadlock.

**all four** of the below conditions are **required** for a deadlock to occur:

| condition                           | description                                                                                                        |
| ----------------------------------- | ------------------------------------------------------------------------------------------------------------------ |
| mutual exclusion                    | threads can claim exclusive control of whatever resource they require                                              |
| hold-and-wait                       | threads will hold resources allocated to them until they acquire the rest of their stuff                           |
| no preemption                       | resources cannot be forcibly removed from whatever thread holding them                                             |
| circular wait (cyclic dependencies) | a cyclic dependency situation where each thread holds **at lease one resource** requested by next threads in chain |
### cyclic dependency
one of the main features behind the dining philosophers problem. in this case:
- thread 1 holds lock L1, and waiting for L2 to be released to execute.
- thread 2 holds lock L2, and waits for L1 to be released to execute.

to prevent this, we need to have a **total ordering** on lock acquisition. this means carefully designing the global locking strategies. in this case, always try to acquire L1 before L2 solves the problem.

### hold-and-wait
have another lock, and **atomically acquire all locks at once**.

```c
lock(prevention);
lock(L1);
lock(L2);
…
unlock(prevention);
```

this way, no untimely thread switch can occur in the midst of lock acquisition. however, this means less concurrency, and it requires us to determine which locks to acquire ahead of time.
### no-preemption
when a lock is held, it typically isn't released until the entire sequence of action is completed. so, use `trylock()` and release them:

```c
top:
	lock(L1);
	if (tryLock(L2) == -1) {
		// free resources
		unlock(L1);
		goto top;
	}
```

doing this removes deadlocks, but introduces **livelocks**, where the acquire-release loop happens over and over again where multiple threads compete for it at a time. to resolve this, just introduce a **random delay** before attempting to re-acquire.
### mutual exclusion
the hardest type to prevent. there are a number of solutions:
- **wait-free data structures**: use powerful hardware instructions and build structures that don't require explicit locking.

for example, something like `atomicAdd`

```c
void atomicAdd(int *value, int amount) {
	do {
		int old = *value;
		// repeatedly tries to swap using CAS
	} while (compare_and_swap(value, old, old + amount) == 0);
}
```

however, livelocks are still a possibility.

## avoidance via scheduling
in some scenarios, we would like to not encounter and patch at all if possible. in this case:
- we need to know which locks various threads might grab during their execution
- subsequently schedules them in such a way that deadlocks cannot occur (for example, let functions execute at different times).

however, this scheduling needs more effort to compute, with also the added demerit of reduced concurrency.

## detect and recover
allow deadlocks to occur occasionally, and then take some action to recover later. for example, if an OS freezes, we can reboot it.

many database systems have a deadlock detection system and subsequent recovery.
- a deadlock detector runs periodically
- builds a resource graphs and checks for cycles
- if there is a deadlock, restart the system

