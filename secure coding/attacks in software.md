>[!note] definition
>**attack vectors**: how the attack occurs. there is exactly one high-level attack vector: subverting (undermining) trust that software places in something. 

overall, there are 4 different things that software trusts (make assumptions about) that lets attackers mount attacks:
### user input
- attacker may provide unexpected input $\implies$ can be mitigated by **validating (or sanitizing** inputs.
	- buffer overflows, SQL injections, XSS, etc.
	- confused deputy attack: input causes software to misuse its privileges (permissions) on behalf of the less-privileged attacker. (also a kind of privilege escalation attack)
		- think about a situation where a compiler compiles a source file, and an attacker specifies the name of the target program as some system file (such as a `passwords` file)
		- then, once `passwords` is overwritten, no one else could log onto the server, and the machine is effectively brought down.
### users to behave certain ways.
- attacker is a privileged user who doesn't behave correctly. aka insider attack, this is usually the most difficult type of attack to prevent because the user needs all of their privileges. 
	- examined after-the-fact with auditing/logging
	- Principle of Least Privilege
	- require multiple insiders to authorize the sensitive actions.
- attacker convince users to behave otherwise 
	- social engineering: attacker psychologically convinces user to perform insecure action
		- phishing: social engineering by pretending to be a trustworthy entity in electronic communication
		- smishing: phishing, but through SMS
		- spear phishing: hyper-specific phishing, targeting only 1 victim.
### attackers/users to have limited resources
attackers may use more-than-expected resources, in the case of Denial of Service (DoS), or distributed DoS (DDoS) (e.g. with a botnet)

### the environment in which it executes (hardware or software) 
the operating system or the chip that software is executed on can sometimes be compromised.

## tradeoffs
overall, more security means: 
- lower usability (passwords, security pop-ups, pop-up fatigue)
- lower performance or running time (permission checks on the OS, resource monitors that all consume resources)
- lower bandwidth (no firewalls = faster network ops)
- higher code and data size (to use on security data structures and mechanisms)
- more energy consumed to keep it running
- more personnel (human resources and developer time to maintain, to monitor, etc.)

## attacks
- memory corruption attacks:
	- out of bounds writes
		- buffer overflows (including stack based/heap based)
	- format string attacks
	- integer overflows
- null pointer dereferences (segfaults) may cause crash and DOS or enter an error state
- use-after-frees
	- p1 points to struct of type `s`, p2 points to same object, and free p1, try to use s2
- broken type safety (type confusion)
	- p1 is an object of type `S`
	- p2 points to same as p1, but cast as type `T`
	- access fields in p2 (type `T`), that doesn't exist in `S`.
- double-free vulnerabilities: free some block of memory twice, which screws up the heap manager. this may corrupt the data structure used for managing the heap memory (also called the free list)

```c
free(p); // the free list indicates this slot is available
...
... // malloc(p') occurs somewhere here
... // malloc'ed into the slot that was just freed
free(p); // slot is freed again 
use p`; // use-after-free
```

