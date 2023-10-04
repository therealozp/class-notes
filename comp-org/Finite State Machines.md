The **synchronous** sequential circuits are also called FSMs, which have a finite number of distinct states and transitions, hence the name. A sequential circuit with $p$ flip flops: 
	- Can have $2^p$ distinct states.
	- Can have $2^p \times 2^p = 2^{2p}$ transitions
## Moore and Mealy
Two types of FSMs:
- *Mealy Machine*: depends on external input and current states, so input changes can cause output changes (**asynchronous**)
- *Moore Machine*: depends entirely on memory elements (current states)

