![[Pasted image 20250501172808.png]]

the CPU is attached to memory via a memory bus. other devices are connected to the system via general IO buses like PCIe lanes, or a peripheral IO bus like SCSI, SATA, etc.

buses are **data paths** provided to enable information between CPU(s), RAM, and IO devices. within these, the IO buses connect CPU to an IO device, by using **three hardware components**: IO ports, interfaces, and device controllers.

## canonical device
has two important components:
- **hardware interface** to allow system software to control operation
	- status register sees the current device status.
	- command register provides instructions.
	- data registers lets CPU pass data to (or get data from) a device.
- **internals**, which are implementation specific.

![[Pasted image 20250501173127.png]]

a typical hardware interaction can be:

```c
while (STATUS == BUSY)
	; // wait until not busy
write data to data register
write data to command register
while (STATUS == BUSY)
	; // until device is done with request
```

the OS repeatedly polls the status register to check for status. it's simple, and it works; but **it wastes CPU time** waiting for the device. so, we can switch to another *ready* process while the OS polls.

**interrupts**, on the other hand, puts the process requesting IO to sleep, and switches context to another. when the device is ready, it wakes up said process via an interrupt. this way, both the CPU and disk are efficiently utilized.

however, polling and interrupts depend on the device, and isn't always the best solution.
- if the device is fast, interrupts slow things down because context switching is expensive. so, fast device -> polling.
- otherwise, if the device is slow, might as well use interrupts for better utilization.

## data movement
the CPU wastes a lot of time copying large chunks of data from memory to device. slow, and wastes a lot of CPU cycles.

by contrast, using a direct-memory-access (DMA) controller, we offload this task to the DMA and free up the CPU to do other things. we copy data by telling the DMA controller "where the data lives in memory" and "how much data to copy". then, when completed, it just raises and interrupt and let IO begin on disk.

## device interaction
we've covered interaction with disk and memory, but what about to devices?

similar to above, we can use:
- IO instructions: lets OS send data to specific device registers (e.g. `in` and `out` in x86)
- memory-mapped IO: make device registers available as if they are memory locations. then, we can use `load` or `store` to interact with device instead of main memory.

to interact with **specific** interfaces (such as SCSI, IDE disks, etc.), we need the help of abstraction.
## abstraction
these are the file system specifics of which disk class it is using. for example, it issues block rw requests to the generic block layer.

![[Pasted image 20250501180028.png]]

however, there is a big problem: abstraction means that many of the devices' special functionality will go unused (in this generic interface layer). thus, we introduce a secondary layer: **device drivers**.
### device drivers
over 70% of OS code are device drivers. any device drivers are needed because you might plug it into the system. they are also the primary contributor to kernel crashes, making even more bugs.

#### IDE disk driver
has 4 types of registers (control, command, status, and error) with `in` and `out` IO instructions.
