software threats
attack vectors: how the attack occurs. we could view that there is exactly one high-level attach vector: subverting (undermining) trust that software places in something.

attackers will exploit vulnerabilities (or bugs)

1. software trusts (makes assumptions about) user input
	- attacker may provide unexpected input $\implies$ can be mitigated by **validating (or sanitizing** inputs.
		- buffer overflows, SQL injections, XSS, etc.
		- confused deputy attack: input causes software to misuse its privileges (permissions) on behalf of the less-privileged attacker. (also a kind of privilege escalation attack)
			- think about a situation where a compiler compiles a source file, and an attacker specifies the name of the target program as some system file (such as a `passwords` file)
			- then, once `passwords` is overwritten, no one else could log onto the server, and the machine is effectively brought down.
2. software trusts users to behave certain ways.
	- attacker is a privileged user who doesn't behave correctly. aka insider attack, this is usually the most difficult type of attack to prevent because the user needs all of their privileges. 
		- examined after-the-fact with auditing/logging
		- Principle of Least Privilege
		- require multiple insiders to authorize the sensitive actions.
	- attacker convince users to behave otherwise 
		- social engineering: attacker psychologically convinces user to perform insecure action
			- phishing: social engineering by pretending to be a trustworthy entity in electronic communication
			- smishing: phishing, but through SMS
			- spear phishing: hyper-specific phishing, targeting only 1 victim.
3. software trusts that attackers/users to have limited resources
	- attackers may use more-than-expected resources, in the case of Denial of Service (DoS), or distributed DoS (DDoS) (e.g. with a botnet)
	- 
