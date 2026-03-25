access control (AC) mechanisms will try to enforce AC policies.
- authentication: determines subjects identities
- authorization: determines whether/how an identified subject may access an object
### authentication
3 main authentication factors:
1. what you know: usernames, passwords, PINs
2. what you have: physical keys, credit cards, phones
3. what you are: biometrics, locations

for something to be MFA, there needs to be multiple factors. PWs and PINs combo cannot be considered a 2FA. PWs and email depends on the email service: 
- if an email relies on strictly password only, then it's still 1FA
- if the email requires a phone access, fingerprint, etc. then it can be MFA
### authorization
- access-control list: data structure that stores list of permissions **stored with each object**. for example, for a file, we can have `(root: rwx, user5: r--, others: ---)`
- capability list: list of permissions **stored with each subject**. `(file 1: R, file 2: X, file 3: -)`
- access-control matrix: combines both of the above. probably not used in practice where machines are big, but useful because of constant-time access

|        | file 1 | file 2 | etc. |
| ------ | ------ | ------ | ---- |
| root   | rwx    | rwx    | ...  |
| user 5 | r      | x      |      |
| ...    |        |        |      |
- RBAC - role based access control, where roles determines permissions

### mandatory access control (MAC)
system determines authorizations, not users. in other words, users cannot determine authorization decisions (hard-coded).

traditionally used with multi-level security (MLS, top secret -> secret -> public/unclassified). in general, it can be classified into lattices.

- Bell - La Padula model: no read-ups, no write-downs. this is a conjunction of two safety properties, so it is also [[safety properties|safety]]. enforces confidentiality in [[properties#categorization|the CIA triad]].
	- no subject can read anything at a higher level than where they are at
	- no subject at a higher level (i.e. top secret) should write down to a lower level of authorization
- Biba Integrity model: no read downs, no write ups. enforces integrity instead
in reality, we use both. also in reality, we also have exceptions. so we have mechanisms to enforce exceptions.
### discretionary access control
users can affect authorization decisions. ****