#computer_orgnization
## 1. Organization vs architecture
- Organization: all **physical aspects** of systems (e.g. circuits, signals, memory types, etc. )
- Architecture: **logical, abstract system** implementation as seen by a programmer (e.g. instruction sets, formats, dtypes, mem access methos, I/O, etc.) 
In reality, there is no clear distinction between problems of the two:

> **any task done by software can be accomplished by hardware (and vice versa)**
#### a. Components
At the most basic level, a computer consists of three pieces: 
- **Processor** to interpret and process programs. After compiling the program, an **executable** is returned. The CPU **interprets/decodes** the abstraction to run the program. Has a control unit, arithmetic logic unit (ALU), and registers (small storage areas).
- **Memory** to store data & programs. An **array of addresses** (accessible by *`MEM[index]`*, where the hardware communicates through an OS to allocate memory. 
- A mechanism for **I/O**

#### b. Moore's Law
Number of transistors double every year, **capacity up**.

#### c. Rock's Law
Price cut by half (???) each year

#### d. Units of:
- **Capacity**: KB, MB, GB, TB,... KiB, MiB, GiB, TiB
- **Processor Speeds**: KHz, MHz, GHz
- **Time & Space**: $\mu$s, ns, ms.

Hertz = **clock cycles/s** (frequency). For example, a bus operating at 133MHz has a cycle time of 7.52ns, as $133 \cdot 10^6 cycles/s = \frac{1}{133 \cdot 10^6} = 7.52 ns/cycle$

**The writing operation** (e.g. adding 2 32-bit numbers a and b):
a + b --ADDER--> 32-bit register, written simultaneously to a DFF (D Flip Flops ??)

## 2. The Computer Level hierarchy
The machines at each level call a subsequent layer below it to perform tasks, which is **ultimately performed by the computer circuits.**

 > **Top level:** User Programs (.exe)
 > High level languages (C++, Java, Fortran, etc.) -> requires compilation
 > Assembly
 > System Software (OS, Library Code)
 > Machine Code (Instruction Set Architecture - ISA)
 > Control (Microcode / Hardwired)
 > **Lv. 0:** Digital Logic (Circuits, gates, etc.)

## 3. The von Neumann Model
The basic structure of the computers is known as the von Neumann Model:
- **memory**, containing instructions & data
- **processing unit**, performing arithmetic and logical operations
- **control unit**, for interpreting instructions

Today's stored-program machine architecture: [[#a. Components]]
- Has capacity for sequential instruction processing
- A single data path between CPU and main memory, called the **von Neumann bottleneck**

![[vonneumann.excalidraw]]


Employs a **fetch-decode-execute cycle** to run programs.

Today's von Neumann model: 
- Programs and data are: 
	- stored in a slow to access storage medium, such as a hard disk. 
	- copied to a fast-access, volatile storage medium such as RAM prior to execution.
There are 2 kinds of RAM: *SRAM* (for cache memory, holds **static** data as long as power is provided) and *DRAM* (continuously refreshed, **dynamic**)

## 4. Non von-Neumann models
#### a. Multi-core
- Multi cores / chips, but single PU
- Independent L1 cache and shared L2 cache

#### b. Multiprocessor
- Single or Multiple cores/chips, and multiple PUs
- Independent L1 and L2 cache
- Runs through the system bus to memory