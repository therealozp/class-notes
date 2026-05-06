also known as Internet Protocol Suite. later improved upon by the [[OSI model]].

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
