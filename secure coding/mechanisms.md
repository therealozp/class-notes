a mechanism is (active) a concrete implementation ensuring that software adheres to a policy (passive). when a mechanism $M$ ensures software obeys a policy $P$, we say that **$M$ enforces $P$**. so, all the foundational ideas boil down to a mechanism, a policy, a program, and enforcement.

for information on true/false positives/negatives, refer to [[philosophy of security]].
## imprecise mechanisms
take the example program getting type-checked, using the following policy:

| types                 | operations                                      |
| --------------------- | ----------------------------------------------- |
| int                   | +, -, *                                         |
| bool                  | use in conditionals                             |
| char *                |                                                 |
| int -> int (function) | invoke on an integer, result returns as integer |
 
```
main {
	if alwaysTrue() then exit();
	else f();
}

void f() {
	5(); // type error
	f + f; // type error again
}

bool alwaysTrue() {
	return true;
}
```

in this case, the type checker would raise type errors on function `f()`, but in reality, it would never run. then, static type checkers may raise **false positives**, because it is (mostly) impossible for a static type checker to know what a dynamic program does. or in the halting problem terms, it is undecidable for a computer/algorithm to figure out what an input program will do at runtime. 

type checking is a kind of memory [[access control mechanisms|access control]] policy, as we are trying to control way memory is accessed.
## precise mechanisms
precise enforcers never exhibit false positives/negatives. that means static mechanisms are always **imprecise**, due to the problem of decidability. an example of a precise enforcement systems would be an intrusion detection system.

![[Pasted image 20260114163254.png]]

suppose that our IDS wants to block any host performing malicious reconnaissance, such as port scanning (a remote machine pings the target repeatedly, checking for open ports, such as telnets). in this case, preventing malicious recon is a **high-level** goal, but defining the action "port-scanning" is a **lower level policy**.

![[Pasted image 20260114163653.png]]

in this case, the IDS can do exactly what it is programmed to do, but can be vulnerable to false positives and negatives. 

- **sound enforcers:** never exhibits false negatives, but may exhibit false positives. an "easy" way to sound enforce is just disallowing everything. overly strict.
- **complete enforcers**: never exhibits false positives, but may exhibit false negatives. complete enforcement looks like allowing everything. overly lenient.

policy $\subset$ [[properties]] $\subset$ safety and liveness
![[Pasted image 20260126153251.png|500]]
