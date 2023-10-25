The **synchronous** sequential circuits are also called FSMs, which have a finite number of distinct states and transitions, hence the name. A sequential circuit with $p$ flip flops: 
	- Can have $2^p$ distinct states.
	- Can have $2^p \times 2^p = 2^{2p}$ transitions
## Moore and Mealy
Two types of FSMs:
- *Mealy Machine*: depends on external input and current states, so input changes can cause output changes (**asynchronous**)
- *Moore Machine*: depends entirely on memory elements (current states)

Distinguishing between the two: 

![[Pasted image 20231025103301.png]]

Note that the DFF will change state immediately when the input changes (as in, until the next clock cycle). By definition, the Mealy machine will depend directly on the inputs (e.g. it is passed through one DFF), while the Moore machine applies an extra delay with another set of DFFs. 

So, in the Moore machine, it is **completely dependent** on states of DFFs, while for Mealy, it is still dependent on the input. 