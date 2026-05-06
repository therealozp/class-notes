stands for the Open Systems Interconnection model. consists of 7 layers:
- application layer is split into 3 layers:
	- application
	- presentation: cryptographic properties, compression e.g. TLS
	- session: manages sessions, like checkpointing, restoration, etc
- transport layer
- network layer
- link layer is split into 2:
	- data link: MAC addresses
	- physical: transmitting raw bits through a medium

web applications: client-server software, where client runs in a browser. typically, it would have a 3 or 4 tier (physically separated software architecture component) architecture. 

![[Pasted image 20260406163549.png]]

web-apps can be developed with web-app frameworks, e.g. ASP.NET, Django for Python, Ruby on Rails, Spring on Java, JS/TS.

with multi-tier objects, state handling needs to be secured. in server-client models, the state is **serialized** (marshalling) before sending to the client, who deserializes it later (un-marshalling).