## abstractions (layers of representation/interpretation)
helps us deal with complexity by abstracting away lower details. 

### instruction set architecture
this is the hardware/software interface. includes everything programmers need to know about making a machine work correctly, such as **instructions** and **IO**.

## Moore's law
the power of computer chips double every year.

## principle of **locality**/memory hierarchy
- processor register - super fast, tiny capacity
- L1, L2, L3 cache
- RAM memory
- virtual memory - slowest, highest capacity

## parallelism
ability to execute multiple instructions at the same time

## performance measurement and improvement
matching application to hardware to exploit locality, parallelism, specialized hardware (GPUs for matrix operations)

## dependability via redundancy
backup of backup of backup.

redundant datacenters, disks (RAID), memory bits (ECC memory)