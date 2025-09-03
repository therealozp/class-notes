there are a few stats that give developers some insight into a processor's performance, such as:
- **FLOPS**: floating point operations per second, dictating how much computation a processor's core does per unit time
- **bandwidth**: bytes per second, meaning how much data the memory is moving per unit time

historically, the GPU's performance has always been bottlenecked by the memory bandwidth. i.e. we always have a lot of computing power, but the data that the device is able to move has always been weak.

an application can be:
- **compute-bound**: performance is limited by the FLOPS rate (cores are always fully utilized)
- **memory-bound**: performance limited by memory bandwidth. cores are idling frequently, because memory does not supply data fast enough.

