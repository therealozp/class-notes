## semicon manufacturing
- **die/chip**: an individual rectangular sections cut from wafers
- **yield**: the *percentage of good dies* from **total number of dies on wafer**
- **wafer**: slice from the silicon ingot
- **semiconductor**: substance that doesn't conduct electricity well.
- **transistor**: on/off switch controlled by electrical signal
- **bonding**: process where good dies are connected to IO pins of package.

silicon ingots -> blank wafers -> patterned wafers -> tested wafers -> dies -> bonding to package 
## multiprocessors
could be **multicore multiprocessors**: more than one processor per chip
requires explicitly parallel programming
- compare with instruction level parallelism: hardware executes multiple instructions at once (hidden from programmer)
- however, it is **hard to do**:
	- performance
	- load balancing
	- optimizing communication & synchronization

although circular silicon ingot causes several wasted dice, it allows for **uniform thickness**, less wasted material, and makes it much easier to cut and stack.
## integrated circuit cost
$$\text{cost per die} = \frac{\text{cost per wafer}}{\text{dies per wafer} \times\text{yield}}$$
$$
\text{dies per wafer} = \frac{\text{wafer area}}{\text{die area}}
$$
$$\text{yield} = \frac{1}{(1+\text{defects per area} \times \text{die area} /{2})^{2}}$$
yield is a ratio of good dies versus dies on the wafer
a non-linear relation to area and defect rate
- wafer cost and area are fixed
- defect rate determined by manufacturing process
- die area determined by architecture and circuit design