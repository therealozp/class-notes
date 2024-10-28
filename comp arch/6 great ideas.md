## abstractions (layers of representation/interpretation)
helps us deal with complexity by abstracting away lower-level details. 
#### instruction set architecture
- the hardware/software interface. 
- includes critical components for a machine to work correctly, such as **instructions** and **IO devices**.
#### implementation
- the details and underlying interface
- hardware that obeys the architecture abstraction

high level language -> assembly -> machine language -> hardware architecture -> architecture implementation
## Moore's law
the power of computer chips double every year.
## principle of **locality**/memory hierarchy
- processor register - super fast, tiny capacity
- L1, L2, L3 cache
- RAM memory
- non-volatile, flash-based memory (SSD)
- virtual memory in hard disks (HDD) - slowest, highest capacity
## parallelism
ability to execute multiple instructions at the same time. includes operations such as `fork()` to divide threads, and `join()` to merge them and post-process.
## performance measurement and improvement
matches application to underlying hardware to exploit **locality, parallelism**, and **special hardware features** such as using the GPU for matrix multiplications.

one big issue is **latency**:
- how long it takes to set the problem up
- how much faster it executes
- *it is all about time to finish.*
## dependability via redundancy
backup of backup of backup.

redundant datacenters, disks (RAID), memory bits (ECC memory). **increasing transistor density reduces cost of redundancy.**