![[Pasted image 20260114163254.png]]


suppose that our IDS wants to block any host performing malicious reconnaissance, such as port scanning (a remote machine pings the target repeatedly, checking for open ports, such as telnets). in this case, preventing malicious recon is a **high-level** goal, but defining the action "port-scanning" is a **lower level policy**.

![[Pasted image 20260114163653.png]]

in this case, the IDS can do exactly what it is programmed to do, but can be vulnerable to false positives and negatives. 