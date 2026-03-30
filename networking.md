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

