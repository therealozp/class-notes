### dining philosophers
5 philosophers sitting around the round table, with 1 fork between each of them. each philosopher needs 2 to eat. solve the deadlock.
- option 1: instead of a deadlock, whenever some timeout is reached, make all philosophers drop the fork. this introduces a livelock, so technically it is solved, but not really.
- option 2: use a lock on the function `getforks()`. it works, because now a philosopher is able to get both forks. but, it reduces concurrency because not all philosophers can eat.
- option 3: use a 4-semaphore to limit the number of forks taken per turn to 4. so, one philosopher will starve, but it will never cause a deadlock.

use some sort of order to solve the locks.