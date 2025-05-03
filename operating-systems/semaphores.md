by and large, semaphores are objects with **integer values**, and has two main interactions: `sem_wait()` and `sem_post()`

semaphore initialization usually looks like:

```c
#include <semaphore.h>

sem_t s;
sem_init(&s, 0, 1); // 1 indicats initial semaphore value
```

on calling `sem_wait()`:
- if the current semaphore value is > 0 (meaning that there are available slots), `sem_wait()` returns immediately, and decrements the value by 1. this lets one of the threads proceed into a critical section. 
- if the semaphore value is < 0, in this case, $-n$, then there are $n$ waiting threads. this just suspends execution waiting for a post.

on calling `sem_post()`:
- the value of the semaphores are incremented by 1
- wakes up one of the waiting threads

## semaphores as locks
since a lock is essentially letting only 1 thread through, we can see how this can be achieved with a 1-semaphore.

```c
sem_t m;
sem_init(&m, 0, 1);
sem_wait(&m);
//critical section here
sem_post(&m);
```

## as condition variables
to make a condition variable, we need to mimic signaling. consider the following example:

```c
sem_t s;

void *child(void *arg) {
    printf("child\n");
    sem_post(&s);  // signal parent
    return NULL;
}

int main(void) {
    sem_init(&s, 0, 0);   // initial count = 0
    printf("parent: begin\n");
	
    pthread_t c;
    pthread_create(&c, NULL, child, NULL);
	
    sem_wait(&s);         // wait until child posts
    printf("parent: end\n");
	
    sem_destroy(&s);
    return 0;
}
```

the semaphore is initialized to 0 because we essentially want the parent to be blocked, and sit on wait until the child posts (thus incrementing the semaphore value and letting the parent through).

consider the classic problem of the producer-consumer solution. instead of having a bunch of different condition variables and mutexes, semaphores are much more elegant:

```c
sem_t empty;
sem_t full;

void *producer(void *arg) {
	int i;
	for (i = 0; i < loops; i++) {
		sem_wait(&empty); // line P1
		put(i); // line P2
		sem_post(&full); // line P3
	}
}

void *consumer(void *arg) {
int i, tmp = 0;
	while (tmp != -1) {
		sem_wait(&full); // line C1
		tmp = get(); // line C2
		sem_post(&empty); // line C3
		printf("%d\n", tmp);
	}
}

int main(int argc, char *argv[]) {
	// …
	sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with…
	sem_init(&full, 0, 0); // … and 0 are full
	// …
}
```

essentially, we are letting `MAX` threads (of producers and consumers combined) go at the same time. because producers wait on `empty`, and consumers wait on `full`, they both need elements already consumed and produced respectively (hence **positive** semaphore values), to keep doing their job.

however, doing this will cause a race condition when we `get()` and `put()`. because the threads that DO pass through can access it without restriction, it can overwrite each-other's data.

so, the second attempt of the producer is as follows: 

```c
void *producer(void *arg) {
	int i;
	for (i = 0; i < loops; i++) {
		sem_wait(&mutex); // line p0 (NEW LINE)
		sem_wait(&empty); // line p1
		put(i); // line p2
		sem_post(&full); // line p3
		sem_post(&mutex); // line p4 (NEW LINE)
	}
}
```

looks better, but it is still bad!

imagine that the thread acquires the mutex, and then goes in to wait on `empty`. if the semaphore fails and we end up having to wait at `empty`, the mutex will never be released! this is because we are wrapping a multi-value semaphore inside of a binary semaphore.

by contrast, a better implementation would be:

```c
void *producer(void *arg) {
	int i;
	for (i = 0; i < loops; i++) {
		sem_wait(&empty); // line p1
		sem_wait(&mutex); // move mutex inside
		put(i); // line p2
		sem_post(&mutex); // move mutex inside
		sem_post(&full); // line p3
	}
}
```

now, when we have to sleep on `empty`, other threads can still access data.

## reader-writer locks
picture that a number of **insert** and **lookup** operations are being done on a list.
- **insertion** changes list state. *critical section* makes sense here.
- **lookup** merely reads it. so, as long as there are no ongoing inserts, we can allow a bunch of readers to go concurrently.

essentially, we can have two locks, a `readlock` and a `writelock`. we want `read` and `write` operations to happen independently of each other.
- let the first reader acquire the `writelock` and let no writer threads pass.
- as many readers as we defined can read at the same time.
- when the last reader leaves, release the `writelock`.

however, this has a big fairness problem: **writers will be starved.** this problem can be remedied by doing a similar setup for writers, i.e. first writer will block the `readLock` and will only release it when the last writer leaves.

