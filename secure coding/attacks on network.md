## SYN flooding
host is vulnerable during [[TCPIP model#three-way handshake|half-open connections]], where DDoS attacks can happen. at this stage, a botnet can send a bunch of SYN connection requests, and the victim needs to remember all those requests (for the sequence numbers, addresses, sizes of packets, maximum transmission size, etc.) that they **cannot** remove. this can potentially exhaust all memory on the server.

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

an example of a firewall table

| source IP     | source port | destination IP | destination port | ... | action                           |
| ------------- | ----------- | -------------- | ---------------- | --- | -------------------------------- |
| `131.247.*.*` | `*`         | `131.247.*.5`  | 80               |     | drop/allow/log/run some function |
|               |             |                |                  |     |                                  |

## client-state manipulation
attacker modifies state stored on client and returned to server.

refer to pizza model. suppose that instead of the value of the HTML saying "Pay 5.50", the client can modify the HTML to say 0.01 instead. then, the payment API call will only issue a charge for 0.01 instead of 5.50.
### mitigation
1. keep state on server, but send client a session ID/key (SID)
	- application generates a random number, the SID, and use a [[databases|database]] to map back to state
	- using a CSPRNG. not truly random, just sort of random, but it should be unpredictable. if the attacker manages to crack a portion of the number, it should not help them decode the ones before.
	- `hash(sid + client details)` like IP addresses to session state,
	- app sends client the session ID, e.g. in a hidden value,
	- when client returns the SID (e.g. GET/sid....), the server can look up the session state.
	$\to$ might block hosts sending several invalid (sid + client details) combo.
	
2. send client state but use cryptography to enforce integrity.
	- application creates and sends a MAC (message authentication code) or digital signature with the state send to client
	- client returns state + MAC/signature to the server
	- server checks that MAC/signature is valid for the returned state
	- preferred if there is minimal state, because server can remain stateless. otherwise, #1 is preferred because there is less information to manage.

## attacks with SID
if we have session ID embedded into the URL, there might be some problems:
- session hijacking: when someone sends a URL containing an SID to others, they may tamper with session
	- especially through the HTTP `referrer` field, showing which URL the user came from. a sysadmin would have access to these SIDs, opening them up to hijacking
- session fixation: attacker sends victim a URL with known SID
	- attacker has access to all actions of the victim
### mitigation
1. don't put SIDs in URLs. instead, use POST variables. in the same pizza example, the requests might be changed into the following. note that the data is still visible in the packet, but it is not encoded in the URL.

```
POST /submit_order HTTP/1.0
...
sid%...
pay%yes
...
```

2. exchange and expire SIDs frequently (especially when there are sensitive operations)
3. hash both the SID and client info
4. use cookies. the HTTP request would still be a GET request. a HTTP header **from server**: 

```
HTTP/1.0 200 OK
set_cookie:sid=...;secure
<html>...
```

the `secure` flag tells the browser and server that these cookies should **only** be sent over TLS. so in this case, the cookie is automatically sent with every communication between the browser and the server. when the user clicks "yes" to payment, the browser sends:

```
GET /submit_order?pay=yes HTTP/1.0
...
cookie:sid=...
```

## CSRF or XSRF
stands for **cross-site request forgery**. attack in which a privileged client (the victim's browser, because it has an SID cookie) sends and fulfills web-app request on behalf of of a less-privileged 3rd party attacker, using the victim's SID. most of this generally is to fulfill a money transfer request. 

the URLs can be of embedded content (images/videos) that the browser goes to fetch automatically, and this URL could be poisoned. 

### mitigation
- everything about refreshing and expiring the session still applies
- generate a CSRF token
	- just a randomly generated number from a CSPRNG
	- server embeds the hidden token in HTML forms and only satisfies requests with the proper tokens. the URLs sent by the attacker won't have these CSRF tokens.
	- hash tokens and client details, store them in a database for validity checks
- and don't trust scripts (JS) from the client.