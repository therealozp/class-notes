## package diagram
good in the MOAS (architect)

| category      | UML component diagram                                 | package diagram                                         |
| ------------- | ----------------------------------------------------- | ------------------------------------------------------- |
| purpose       | shows physical aspect of system                       | show how system's parts are grouped + interact          |
| elements      | show private model elements                           | shows public items                                      |
| structure     | how to distribute system into parts                   | shows how to group related elements together            |
| usage         | used in **design phase** to show system architecutre  | used to structure high-level system elements            |
| visualization | shows relationships between components and interfaces | shows how parts of the system interact with each other. |
|               |                                                       |                                                         |
the arrow direction indicates "depends on".
![[Pasted image 20241201183013.png]]

payment depends on order management, and order management depends on customer. in other words:

```cpp
// customer.h
namespace Customer {
	class Customer
}

// ordermgmt.h
#include "Customer.h"
namespace OrderMgmt {
	class Order;
}

// payment
#include "OrderMgmt.h"
namespace Payment {
	class Payment;
}
```

there are generally 3 layers to the package diagram: presentation (GUI, business layer for logic, user classes, object classes; and data layer, for database and sysadmin)

![[Pasted image 20241201183320.png]]

## use case diagram
good for MOPS (business analyst + user)
- actors: finding good actors is the most important first step. is a role played by typical users, or actors **interacts and uses** the system. does not have to be a person, just have to be something that exists externally to the system.
- use case (not user story): documents a series of interactions with system, meant to generate observable and valuable results.

*uses* is straight line. *include* and *extend* are dashed, with notation. *inherit* is closed hollow arrow. direction of arrow shows the relationship, e.g. if 1 is pointing to 2 with an inherit arrow, then 1 inherits from 2.

![[Pasted image 20241201183718.png]]
![[Pasted image 20241201183801.png]]