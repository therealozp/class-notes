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

## activity diagram and IOD
good for MOPS (business analyst).

the user flows documented by a use case diagram will be visualized by an activity diagram. characteristics: uses "swimlanes" or "partitions" to denote which activity belongs to which. helpful notation: 

![[Pasted image 20241201200123.png]]

for example, a PaysBill activity diagram:

![[Pasted image 20241201200211.png]]
![[Pasted image 20241201200238.png]]

the IOD is basically an activity diagram of references of activity diagrams. in contrast to the activity diagram, every element in an activity diagram are references, and no swimlanes occur.

![[Pasted image 20241201200449.png]]
![[Pasted image 20241201200505.png]]

## class diagrams
used for class modelling and system design. in short, classes are abstract models of business entities/elements, tangible or conceptual. both are needed for the problem space of a software system.

a class is represented as follows:
![[Pasted image 20241201201030.png]]

and a concrete implementation:
![[Pasted image 20241201201100.png]]

classes in **problem space** are classes to represent business entities/domain concepts. classes in **solution space** are designed and refined to code/test.

to identify MOPS classes, analyze **use cases**. 
- **generalization** is searching for commonalities in different classes and placing them in a **common or generic class**
- **specialization** is deriving classes based on existing classes into ones that are more niche and specialized.

some helpful notation for MOPS class diagrams:
![[Pasted image 20241201201246.png]]

- the *inheritance* arrows indicate *something inherits something else*. direction is very important: the pointy end is the parent class (superclass).
- the *aggregation* arrows show that *something has something else*. in this case, the diamond end shows the "whole", or "a bunch of Xs aggregate to become Y."
- multiplicities are stupid. basically, we have to read it according to direction of classes. number $a$ on class `X` and number $b$ on class `Y` mean that, $a$ `X`'s uses $b$ `Y`'s each.
- also note stereotypes: 
	- `<<entity>>` indicates an object ("core business object")
	- `<<boundary>>` is anything with UI (GUI or not GUI), 
	- `<<table>>` is for databases
	- `<<control>>` for business logic to co-ordinate between `<<entity>>` and `<<boundary>>`.


![[Pasted image 20241201201534.png]]
in this diagram:
- Surgery, Consulting, and Dentistry all *inherit* from Department
- multiple Departments *aggregate* to become a Hospital
- a Department *uses* doctors. not aggregates.
- each department uses 1 or more doctors, and each doctor belongs to from 1 to 4 departments.

in the solution space, we have even more notation:
![[Pasted image 20241201204834.png]]
note that: 
- *inheritance* requires a parent-child. triangular end points to the superclass.
- *association* is just a 'uses' relationship. in MOSS, this means that at runtime, a link is established between the two classes.
	- also *directional association*, which means that whatever at the flat end knows of the existence of the other, but the class at pointed end does not know of the flatter.
	- these relationships use references.
- *aggregation* applies a "has" relationship. diamond end is the "whole". an aggregation is when the "part" can exist independently of the "whole", and is sharable within system.
- *composition* also implies the same as aggregation, but in this case, the "part" cannot exist without the "whole".


on more detail of what how each of the relationship looks like in code:

![[Pasted image 20241201205145.png]]
### the interfacing fanangle
- *interfacing* is a classifier/contract that lists a set of public features or methods. any classes that wants to realize it must adhere to the specs of the interface.
- *realization* only applies to classes that have an interface. there are two ways to represent it, either:
	- make a separate *Interface* class and use dashed close hollow arrow
	- use the lollipop notation

![[Pasted image 20241201211330.png]]

![[Pasted image 20241201211346.png]]

in other words, for very complex classes where there are numerous attrs and ops, we can reduce the complexity of interaction by providing an *interface*, or a **subset of class's functionality**.

note that the interface is more like the front-end, which contains only the list of attributes without any underlying implementation. 

![[Pasted image 20241201212229.png]]

- **Patient** is a complex class with many operations.
- **PatientForm** only needs a subset of these operations for patient registration.
- **Solution**: `Patient` provides an interface, e.g., `PatientRegistrationInterface`, which `PatientForm` uses.

### dependency
involves a client and a supplier class, where the client **depends on** the supplier. **class at the pointy end is the supplier.**

the best analogy for this relationship is between a schedule and a doctor. 
- if the doctor's availability changes, he is fired for whatever reason, or the name is changed, it impacts the schedule directly.
- if the schedule changes (due to a rework, appointment reschedule, etc.) the doctor class remains unchanged.

1. client objects change their state as a result of stage changes in supplier objects.

```python
class Doctor:
    def __init__(self, name):
        self.name = name
        self.available_dates = []

    def update_availability(self, new_dates):
        self.available_dates = new_dates

class Schedule:
    def __init__(self, doctor):
        self.doctor = doctor
        self.appointments = {}

    def update_schedule(self):
        # Changes in Doctor's availability affect the Schedule's appointments
        available = self.doctor.available_dates
        self.appointments = {date: f"Appointment with {self.doctor.name}" for date in available}

# Example usage
doctor = Doctor("Dr. Smith")
schedule = Schedule(doctor)

doctor.update_availability(["2024-12-05", "2024-12-10"])
schedule.update_schedule()
print(schedule.appointments)  # Updated schedule based on doctor's availability

```

2. operations in client objects **create instances of** the supplier class (not just use as a reference!) e.g. a doctor is hired and a class is created.

```python
class Doctor:
    def __init__(self, name, specialty):
        self.name = name
        self.specialty = specialty

class Hospital:
    def __init__(self):
        self.doctors = []

    def hire_doctor(self, name, specialty):
        new_doctor = Doctor(name, specialty)  # Client class creates supplier objects
        self.doctors.append(new_doctor)

# Example usage
hospital = Hospital()
hospital.hire_doctor("Dr. Smith", "Cardiology")
print([doctor.name for doctor in hospital.doctors])  # ['Dr. Smith']

```

3. operations of client classes have signatures (return type or function arguments) with the supplier.

```python
class Doctor:
    def __init__(self, name):
        self.name = name

class Schedule:
    def __init__(self):
        self.appointments = {}

    def assign_doctor(self, date, doctor):
        self.appointments[date] = doctor  # Method accepts a Doctor as an argument

    def get_assigned_doctor(self, date):
        return self.appointments.get(date)  # Method returns a Doctor

# Example usage
doctor = Doctor("Dr. Smith")
schedule = Schedule()

schedule.assign_doctor("2024-12-05", doctor)
assigned_doctor = schedule.get_assigned_doctor("2024-12-05")
print(assigned_doctor.name)  # 'Dr. Smith'
```

## sequence diagrams
specify **interactions** between objects in the sequential order that they occur.

![[Pasted image 20241201220547.png]]

notation: 
![[Pasted image 20241201220613.png]]

some notes: 
- messages are often shown going from left to right. sometimes, when an object feels the need to update itself, it will also send a self-message, indicated by a loop back to the control stage.
- an asynchronous message means that we do not have to wait on the response, meaning that everything else can execute independent of the result of this one.

- **destroying an object only removes it from execution memory, not complete and total erasure of the object**.
- **creation of an object** is indicated at pointing directly during execution.
![[Pasted image 20241201224053.png]]
![[Pasted image 20241201224312.png]]
![[Pasted image 20241201224345.png]]

- *focus of control* under an object, let's say A means that, for those sequences, that A **is in control** of the interactions.
	- the system will wait until A completes its sequences of messages and relinquishes control.
	- when an foc is on the timeline, it implies that focus will remain until a meaningful return value has been established.
![[Pasted image 20241201224036.png]]


![[Pasted image 20241201224228.png]]
![[Pasted image 20241201224236.png]]
![[Pasted image 20241201224247.png]]![[Pasted image 20241201224402.png]]
![[Pasted image 20241201224416.png]]
![[Pasted image 20241201224424.png]]


![[Pasted image 20241202003112.png]]