for a long time, people have tried to define some kind of metric to measure security. for example, comparing multiple vulnerabilities that range from minor annoyances (pop ups), to catastrophes such as data wipes. so, to tackle this, we define attack surfaces as a metric.

>[!note] definition
**attack surfaces**: a measurement of how much/many untrusted inputs a program takes.

ransomware may encrypt/scramble data, or even more dangerous, exfiltrate data. institutions such as PII (personal identifiable data) like hospitals or financial institutions are most vulnerable. so, there maybe some payment involved in a form of hush money.

the issue with cyber-insurance: 
- if multiple companies are affected by the same attack, one insurance company will need to pay ALL at once. 
- difficult to even quantify metrics to define payout
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
			- when machine is attacked, shut down the attacked machine and use replicas
		- recover: reverting to a backup
4. adhere to the principle of least privilege (need-to-know basis)
5. avoid "security by obscurity"
	- encapsulate any secrets being relied on into cryptographic keys
6. be careful about when + how keys are stored. 
	- we want to isolate these secrets
	- use special-purpose hardware to store keys securely (Windows TPM)
	- actively delete stuff that aren't used (**actively overwritten**, not garbage collected, because they can still remain in memory remnants). hard-coded secrets are very hard to get rid off, i.e. via version history
	- use a CSPRNG to generate random keys for encryption
7. simplicity
	- simpler the stuff, easier it is to analyze (both design and implementation)
	- user involvement and default settings (i.e. shipping products with default easy passwords, and expecting users to change that password)
8. secure the weakest link
	- password strengths check
	- insider attacks/social engineering
9. understand limits of security mechanisms
	- adding HTTPS mitigates **none** of the attacks on the simple web server example
10. make judicious use of code you did not write yourself
	- libraries
	- code posted online somewhere
	- AI-generated code
11. TOCTOU - time of check to time of use
	- in between the time of permission checks and of actual usage, the security state might change 
	- a user might have permissions to open at first, but if gap is big, then permissions could change
	- don't do context switching during secure operations/do this atomically (via locks, mutexes, etc.)
	- time-based OTPs
	- complete mediation - dynamic mechanisms should do **all** (ergo, *complete*) security checks before sensitive operations