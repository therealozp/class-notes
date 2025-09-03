the means by which the OS creates infinite amounts of resources from limited hardware. currently, there is CPU and memory virtualization, which helps abstract away from the hardware and exposes APIs for [[processes]] to use.

## CPU virtualization
what the OS is attempting to do at this stage is **creating an illusion** that, despite the limited number of cores allocated to the CPU, there are infinite **virtual** CPU cores.

### time sharing
this concept describes running one process, stopping it, and running another. this is one way the CPU can be virtualized, but **it costs performance.**

