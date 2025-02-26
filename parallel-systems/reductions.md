a reduction operation **reduces an array of values to one value**. these operations often have a well-defined identity, are associative, and commutative.

for example, take the sum operation. written linearly, it goes like:

```c
float sum = 0;
for (int i = 0; i < N; i++) {
	sum += input[i];
}
```

however, reduction operations are often defined by the existence of two variables: the **accumulator** and the **callback**. so, assuming that `f` is our summation function:

```c
acc = IDENTITY;
for (int i = 0; i < N; i++) {
	acc = f(acc, input[i]);
}
```

in situ computation

thread **anchored** position: a thread is always anchored somewhere in memory. in the following example

stride: for an anchored thread:
- it needs to read some other value
- perform any sort of computation (in register)
- write it to our anchored position
