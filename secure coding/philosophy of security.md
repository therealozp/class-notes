what does it mean for software, practices, etc. to be secure?

historically, security is often hard-coded. it would be secure for passwords to be changed every set amount of time, or auto logouts.

in reality, there is no one-size-fits-all scheme that can satisfy this. so, secure software adheres to constraints specified by a policy. a policy is some sort of specification of good or bad behavior of a program (what is good/bad, allow/disallow, etc.)

then, a mechanism is (active) a concrete implementation ensuring that software adheres to a policy (passive). when a mechanism $M$ ensures software obeys a policy $P$, we say that **$M$ enforces $P$**. so, all the foundational ideas boil down to a mechanism, a policy, a program, and enforcement.

in the order of desirability: 
1. true negatives: mechanism signals policy **satisfaction** + is **correct**
2. true positives: mechanism signals policy **violation** (raises an alarm) + is **correct**
3. false positives: mechanism signals policy **violation** + is **wrong** (type I error)
4. false negatives: mechanism signals policy **satisfaction** + is **wrong** (type II error)

humans will typically be involved in SOCs (security operations centers), acting as a judge of the mechanism.

there exists a many-to-many relationship between a policy and a mechanism
- allows for dynamic updates of policies, or various choices of mechanisms
- 
## imprecise mechanism
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
## precise systems
precise enforcers never exhibit false positives/negatives. that means static mechanisms are always **imprecise**, due to the problem of decidability. an example of a precise enforcement systems would be an intrusion detection system.

![[Pasted image 20260114163254.png]]

suppose that our IDS wants to block any host performing malicious reconnaissance, such as port scanning (a remote machine pings the target repeatedly, checking for open ports, such as telnets). in this case, preventing malicious recon is a **high-level** goal, but defining the action "port-scanning" is a **lower level policy**.

![[Pasted image 20260114163653.png]]

in this case, the IDS can do exactly what it is programmed to do, but can be vulnerable to false positives and negatives. 

- **sound enforcers:** never exhibits false negatives, but may exhibit false positives. an "easy" way to sound enforce is just disallowing everything. overly strict.
- **complete enforcers**: never exhibits false positives, but may exhibit false negatives. complete enforcement looks like allowing everything. overly lenient.

policy $\subset$ properties $\subset$ safety and liveness
![[Pasted image 20260126153251.png]]
## trace
a **trace** (or **run**, or **execution**) is a sequence of actions of security relevant actions (or **events**). 

consider the program `echo`,  where our traces are (separated by semicolons). traces may be **converging** (terminating) or **diverging** (non-terminating).

```
input('a');output('a') // if the program waits for inputs and hangs
in('a'); out('a'); in(Ctrl + C); exit
ε // for an empty trace
in(a);out(a);in(a);out(a);... // infinite length trace
```

let's denote a program as $\mathcal{p}$. then, $\mathcal{p}_{\text{echo}}=\{ \text{all of the above choices},\dots \}$. there are uncountably infinite traces of $\mathcal{p}_{\text{echo}}$. 

then, a program is just a set of traces. and a policy is a set of programs (of all *good*/*secure*/*valid* programs). so that means a policy is a **set of sets of traces**.

a policy $P=\{\mathcal{p_{1}}, \mathcal{p_{2}},\dots\}$
a policy $P=\{\{ t_{1}^{1};t_{2}^{1};t_{3}^{1},\dots \}, \{ t_{1}^{2};t_{2}^{2};t_{3}^{2},\dots \},\dots\}$
a policy $P$ where there are no null dereferencing: $P_{1}=\{ \{ t_{1}, t_{2},\dots \}\ |\ \forall i: \text{read(0)}\not\in t_{i}\}$
