there exists 2 common layered models for computer communications.

## TCP/IP model
also known as Internet Protocol Suite. 

![[Pasted image 20260330162114.png]]

consists of:
- application layer: application/process specific data transmission
	- web browsers/clients and web servers, email clients and emails servers, FTPs, SFTP, etc.
	- client-server model: workloads partitioned between the producer/provider and a consumer/requestor
	- peer-to-peer (P2P) model: all hosts are partitioned between equally privileged/powerful peers (file sharing, etc.)
- transport layer: sends packets between applications
	- each application has a transport-layer address, denoted a port number
		- 16-bit TCP/UDP port number
		- 80 for HTTP
		- 443 for HTTPS
	- two things handled at this layer:
		- application addressing
		- reliability (e.g. with TCP): ensure that data arrives; in proper order; without errors; without duplicates. lost data gets re-sent.
- internet layer: sends packets between hosts on possibly different networks (i.e. networks not on the same physical link) so multiple hops may be necessary
	- each **host** has an internet-layer address:
		- IPv4: 32 bits
		- IPv6: 128 bits
	- two things are handled at this layer:
		- packet (also called datagrams) routing
		- host addressing
- link layer: transmits data (grouped into packets/frames) between devices on the same physical link (i.e. on the same network)
	- each network device has a link-layer address, e.g. a MAC (media access control) Ethernet + Wi-Fi networks use a 48-bit MAC address (defined in IEEE 802)


![[Pasted image 20260401154333.png]]

## protocols
system of rules for communicating (who, what, when, how)
- link layer: IEEE 802.11 defines the standards for wireless communications
- internet layer: 
	- IP (internet protocols), main purpose is for relaying datagrams and host addressing
	- IPSec: IP plus some cryptographic protections, to ensure authenticity
- transport layer: 
	- TCP (transmission control protocol)
		- provide **reliable** (the receiver acks having received data), stable stream of **ordered** and **error-checked** data, re-transmits lost data using timeouts, etc. also contains checksums and port #'s.
		- TCP is connection-oriented. TCP is stateful, meaning each packet is interpreted in context of a "connection" - a stream of packets
	- UDP (user datagram protocol): 
		- provides **unreliable** steam of data, possibly misordered, non-error-checked. UDP still adds checksums and port #'s.
		- UDP is connectionless, so it is stateless. each packet is interpreted in isolation.
	- QUIC: Quick UDP Internet Connections
		- based on UDP, but only adds reliability when needed. in reality, UDP does fail, but do so very rarely. so, instead of checking every time like TCP, we can just detect when an error happens and then fix it.
			- performance is comparable to UDP
			- reliability when needed
			- uses a checksum + parity bit
- application layer: 
	- TLS (transport layer security) or SSL (secure socket layer). SSL is deprecated, TLS is better. kind of like IPsec for the application layer
	- HTTP/HTTPS (HyperText Transfer Protocol). has methods like GET/PUT to fetch/update a resource. HTTPS runs HTTP over TLS.
	- POP for email (pop-over-punch), SMTP
	- FTP/SFTP for file transfers
### three-way handshake
![[Pasted image 20260406154743.png|500]]
## SYN flooding
host is vulnerable during half-open connections, where DDoS attacks can happen. at this stage, a botnet can send a bunch of SYN connection requests, and the victim needs to remember all those requests (for the sequence numbers, addresses, sizes of packets, maximum transmission size, etc.) that they **cannot** remove. this can potentially exhaust all memory on the server.

sometimes, the attacker can also spoof the source IP addresses to subvert the firewall.
### mitigation 
- firewalls (sometimes helps), 
- SYN cookies: instead of remembering state, we can encode the state in the sequence number.
	- cookies refer to the encapsulation of data so you don't have to remember anything. 
	- B's SYN sequence number is chosen to encode current state, and A can reconstruct later. a CSPRNG is commonly used for this purpose.
## bandwidth amplification attacks
denial of service (DoS) attacks are a battle between whoever has more computing power. an attacker uses another third party with more computing power to attack the victim, on behalf of an attacker. analogous to a confused deputy attack.

![[Pasted image 20260406155023.png]]

spoofed address can be a number of things, but there has to be the IP address for sure.

### mitigation
- firewalls and IDSes (or IPses)
	- compare: can monitor both inflow and outflow of packets
		- monitor outflow to see if any confidential information is leaked
	- contrast:
		- IDSes detect **anomalies**. they use ML models/some classifiers to detect anomalous packets. a bit more complicated than firewalls
		- firewalls just do simple pattern-match to decide which one to decide what to do with the packet (drop/allow)

firewall packets (using dotted octet notation, meaning asterisks). rule matching/disambiguation is first-rule-apply basis.

| source IP     | source port | destination IP | destination port | ... | action                            |
| ------------- | ----------- | -------------- | ---------------- | --- | --------------------------------- |
| `131.247.*.*` | `*`         | `131.247.*.5`  | 80               |     | drop/allow/log/run some function  |

## OSI model
stands for the Open Systems Interconnection model. consists of 7 layers:
- application layer is split into 3 layers:
	- application
	- presentation: cryptographic properties, compression e.g. TLS
	- session: manages sessions, like checkpointing, restoration, etc.
- transport layer
- network layer
- link layer is split into 2:
	- data link: MAC addresses
	- physical: transmitting raw bits through a medium

web applications: client-server software, where client runs in a browser. typically, it would have a 3 or 4 tier (physically separated software architecture component) architecture. 

![[Pasted image 20260406163549.png]]

web-apps can be developed with web-app frameworks, e.g. ASP.NET, Django for Python, Ruby on Rails, Spring on Java, JS/TS.

with multi-tier objects, state handling needs to be secured. in server-client models, the state is **serialized** (marshalling) before sending to the client, who deserializes it later (un-marshalling).