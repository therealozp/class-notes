>[!note] definition
>**attack vectors**: how the attack occurs. 

we could view that there is exactly one high-level attack vector: subverting (undermining) trust that software places in something. 

for a long time, people have tried to define some kind of metric to measure security. for example, comparing multiple vulnerabilities that range from minor annoyances (pop ups), to catastrophes such as data wipes. so, to tackle this, we define attack surfaces as a metric.

>[!note] definition
**attack surfaces**: a measurement of how much/many untrusted inputs a program takes.

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
4. software trusts the environment in which it executes (hardware or software) 

## tradeoffs
more security = lower usability (passwords, security pop-ups)
more security = lower performance or running time (permission checks on the OS, resource monitors that all consume resources)
more security = lower bandwidth (no firewalls = faster network ops)
more security = higher code and data size (to use on security data structures and mechanisms)
more security = more energy consumed to keep it running
more security = more personnel (human resources and developer time to maintain, to monitor, etc.)

ransomware may encrypt/scramble data, or even more dangerous, exfiltrate data. institutions such as PII (personal identifiable data) like hospitals or financial institutions are most vulnerable. so, there maybe some payment involved in a form of hush money.
## design principles
1. validate/sanitize inputs. really needs to be creative on how user provides inputs, because there are a number of ways attackers can provide input to attack a machine.
2. try to handle errors securely.
	- no leakage of confidential info via error messages, etc.
	- when the program fails, enter a secure state. don't enter an insecure state. 
3. use layers of heterogeneous mechanisms
	- defense in depth. have mechanisms to prevent, detect, contain, and recover.
		- prevention: firewalls, passwords, access controls, etc. the only mechanism to operate before attacks occur.
		- detection: auditing, antiviruses.
			- malicious software (malware) are polymorphic. you can always slightly modify malware to make it ever so slightly different, but retain the observable behavior to bypass antiviruses (for example, add no-ops)
		- contain: via replication
			- when machine is attacked, shut down the attacked machine and use replicase
		- recover: reverting to a backup
4. adhere to the principle of least privilege (need-to-know basis)
5. avoid "security by obscurity"
	- encapsulate any secretes being relied on into cryptographic keys
6. be careful about when + how keys are stored. 
	- we want to isolate these secrets
	- use special-purpose hardware to store keys securely (Windows TPM)
	- actively delete stuff that aren't used (**actively overwritten**, not garbage collected)
- 