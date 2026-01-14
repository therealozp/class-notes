what does it mean for software, practices, etc. to be secure?

historically, security is often hard-coded. it would be secure for passwords to be changed every set amount of time, or auto logouts.

in reality, there is no one-size-fits-all scheme that can satisfy this. so, secure software adheres to constraints specified by a policy. a policy is some sort of specification of good or bad behavior of a program (what is good/bad, allow/disallow, etc.)

then, a mechanism is (active) a concrete implementation ensuring that software adheres to a policy (passive). when a mechanism $M$ ensures software obeys a policy $P$, we say that **$M$ enforces $P$**. so, all the foundational ideas boil down to a mechanism, a policy, a program, and enforcement.

in the order of desirability: 
1. true negatives: mechanism signals policy **satisfaction** + is **correct**
2. true positives: mechanism signals policy **violation** (raises an alarm) + is **correct**
3. false positives: mechanism signals policy **violation** + is **wrong**
4. false negatives: mechanism signals policy **satisfaction** + is **wrong**

humans will typically be involved in SOCs (security operations centers), acting as a judge of the mechanism.

there exists a many-to-many relationship between a policy and a mechanism
- allows for dynamic updates of policies, or various choices of mechanisms
- 
### type checking
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

type checking is a kind of memory access control policy, as we are trying to control way memory is accessed.

precise enforcers never exhibit false positives/negatives. that means static mechanisms are always **imprecise**, due to the problem of decidability. 