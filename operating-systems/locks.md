the basic idea behind locks is basically making accesses to a critical section **atomic**. so, if there were to be a section that looks like:

```c
lock_t mutex;

lock(&mutex);
balance += 1;
unlock(&mutex);
```

the increment will only ever be ran by one thread at a time, effectively serializing it. to this end, we need support from both the hardware (to make atomic instructions) and the OS (to ensure some sort of fairness).

in general, a lock can be in one of two states:
- **unlocked**: where no thread holds a lock
- **locked**: when a thread is currently in a critical section

due to this mechanism, the `lock()` function will serve only one purpose: **acquire the lock**. how it does it is that:
- attempts to acquire the lock.
- if the lock is being held, waits.
- if the lock is free, acquire it, and enter critical section.

### evaluation
locks will be evaluated in one of three metrics:
- **mutual exclusivity**, aka "does the lock work?" does the lock successfully prevent multiple threads from entering a crit. section at a time?
- **fairness**: does each thread contending for the lock get a fair shot at acquiring it once lock is free?
- **performance**: does the lock add a lot of overhead (in term of time taken or performance)?

### interruption control
one obvious method we can use is to **disable interrupts for critical sections**. immediately, we can already see that this method places *too much trust* in the applications, so any greedy programs can easily monopolize the processor.

furthermore, things like these don't really work on multiprocessors. **also**, code that keeps masking/unmasking the interrupts are executed slowly by the CPU.

### test-and-set
an atomic instruction, that mimics the following:

```c
int TestAndSet(int *ptr, int new) {  
	int old = *ptr; // fetch old value at ptr  
	*ptr = new; // store ‘new’ into ptr  
	return old; // return the old value  
}
```

with this, we are able to construct a fairly simple spin-lock (named spin because it goes into an infinite loop and check):

```c
typedef struct __lock_t {  
	int flag;  
} lock_t;  
  
void init(lock_t *lock) {  
	// 0 indicates that lock is available,  
	// 1 that it is held  
	lock->flag = 0;  
}  

void lock(lock_t *lock) {  
	while (TestAndSet(&lock->flag, 1) == 1); // spin
}  
  
void unlock(lock_t *lock) {  
	lock->flag = 0;  
}
```

**correctness**: the spin lock is correct! it only allows a single thread to enter the critical section.
**fairness**: it isn't really fair, because spin locks don't really provide any fairness guarantees, and a spinning lock and spin forever.
**performance**:
- in a single-core CPU, infinite loops are very bad for performance. 
- if the number of threads running $\approx$ number of CPUs, it works reasonably well.

### compare-and-swap
another atomic instruction, that checks if the value at the specified address `ptr` is the same as `expected`.
- if yes, update with `new`.
- if not, return with the current value.
in both cases, we are returning the old value.

```c
int compareAndSwap(int *ptr, int expected, int new) {
	int actual = *ptr;
	if (actual == expected) {
		*ptr = new;
	}
	return actual;
}
```

so, our spin-lock now looks something like:

```c
void lock(lock_t *lock) {
	// meaning, as long as the current lock status is 1
	while (CompareAndSwap(&lock->flag, 0, 1) == 1); // spin
}  
```

## load-linked and store-conditional
another couple of atomic instructions. essentially, load-link applies a "watcher" to the pointer, just to check if there has been any modifications in between.

```c
int load_linked(int *ptr) {
	// a watcher of some sorts
	return *ptr;
}

int store_conditional(int *ptr, int value) {
	if (nothing has been stored to *ptr since this takes place) {
		*ptr = value;
		return 1;
	} else {
		return 0;
	}
}
```

so, a lock would look something like:

```c
void lock(lock_t *lock) {
	// meaning, as long as the current lock status is 1
	while (load_linked(&lock->flag) ||
		   !store_conditional(&lock->flag, 1)
	); // spin
}  
```

in other words, this constantly loads the value from the pointer. if the lock is currently held, obviously will keep spinning.

otherwise, if the lock is not held, it moves on to check the second condition. this attempts to set the value of the pointer, but **in the (likely) event** that the `ptr` is modified by some other thread later down the line, the store_conditional will break the condition, causing it to re-spin.

### fetch-and-add
atomically increments a value while returning the old value.

```c
int FetchAndAdd(int *ptr) {  
	int old = *ptr;  
	*ptr = old + 1;  
	return old;  
}
```

### ticket locks
this is one of the methods we can use to remedy the unfairness of spin locks. using the fetch-and-add instruction, we can roughly achieve the following implementation:

```c
typedef struct __lock_t {  
	int ticket;  
	int turn;  
} lock_t;  
  
void lock_init(lock_t *lock) {  
	lock->ticket = 0;  
	lock->turn = 0;  
}  
  
void lock(lock_t *lock) {  
	int myturn = FetchAndAdd(&lock->ticket);  
	while (lock->turn != myturn); // spin  
 }  
void unlock(lock_t *lock) {  
	FetchAndAdd(&lock->turn);  
}
```

## avoiding spinning
spinning is simple, and it just works. but, it is inefficient, because the entire time slice is wasted doing nothing but checks. to avoid this, we need **OS support**.

### yielding
if you are going to spin, might as well give up the CPU. in this way, OS issues a syscall to move the caller from *running* to *ready*. however, issues like **context-switching** and **starvation** can still appear.

```c
void lock(lock_t *lock) {  
	while (TestAndSet(&lock->flag, 1) == 1) {
		yield(); // gives up CPU
	};
}  
```
### queueing
use a queue to keep track of which threads are waiting to enter the lock. Solaris provides the `park` API to accomplish this:
- `park()` puts a thread to sleep
- `unpark(threadID)` wakes thread with `threadID` up.

```c
typedef stuct __lock_t {
	int flag; // main lock
	int guard; // queue lock
	queue_t *q; 
} lock_t;

void lock_init(lock_t *m) {
	m->flag = 0; 
	m->guard = 0;
	queue_init(m->q); 
}

void lock(lock_t *m) {
	while (TestAndSet(&m->guard, 1) == 1); // spin-wait for queue
	if (m->flag == 0) {
		m->flag = 1; // acquire the lock
		m->guard = 0; // free the queue lock
	} else {
		queue_add(m->, threadID());
		m->guard = 0;
		park(); // sleep and wait
	}
}

void unlock(lock_t *m) {
	while (TestAndSet(&m->guard, 1) == 1); // spin-wait for queue
	if (queue_empty(m->q)) {
		// let go of the lock because no one is waiting
		m->flag = 0;
	} else {
		unpark(queue_remove(m->q)); // hold the lock for next thread on the queue
	}
	m->guard = 0; // release the queue lock
}
```

there is still an issue with this implementation. consider the case where A is holding the lock, so B executes and waits, and just before it goes to sleep, an interrupt happens. then, A releases the lock, and B continues on to go to sleep, not knowing that the lock has been freed.

to prevent this, Solaris adds another `setpark()` system call, to indicate that a threads is about to `park()`. if an interrupt now occurs and `unpark()` is called anywhere else, the original `park()` will straight up return instead of sleep.

## two-phase locking
this is a hybrid between the two. instead of yielding straight away, the lock will spin for a while, hoping that it can acquire the lock.

if the lock is not acquired in the first stage, we enter the second phase, where the caller sleeps, and only woken up later when the lock is free.
