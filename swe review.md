## chapter 1
1. science v. engineering
- scientists is to **answer questions** and **discover information**, while engineers **creates products or processes to solve these problems.**

2. definition of engineering by NAE
- the application of science, because engineers take abstract ideas to build tangible products
- design under constraints, because engineering means constructing a product to do exactly what we want to, without any expected consequences

3. why is swe left and right brained?
balances the logical and analytical, but also needs to find creative solutions to problems.

4. how does civil and mech affect swe?
SDLC is inspired by processes from civil engineering, and mech e provides backbone to standardize software components

6. the four processes to apply SWE:
- object-oriented fundamentals
- modelling (UML)
- experience (case studies)
- processes (SDLC, agile)

7. importance of modelling:
- serves as a foundation by help understanding business objectives before designing and coding the solution
- a bridge between analysis and implementation
- better communication because of requirements, identify gaps, and improves efficiency

8. databases and business workflows are very well-supported by OO fundamentals. fact or cap?
**fact**. OO fundamentals result in services that are versatile, changable, and reusable. source: pg. 5, software engineering fundamentals.

9. four basic terms in SE
- programs: structured code specific to a language
- classes: styles of software programs that encapsulate data and methods
- data: instance-level representation of business reality encoded and stored in databases
- objects: instances of classes that comprise data and behavior

10. six OOP basics
- classification
- abstraction: reuse a class without knowing how a method is implemented
- encapsulation: easier debugging + reuse a class without knowing how a method works
- association
- inheritance: extensibility of design + code reuse
- polymorphism

11. ___ in design makes polymorphism at runtime possible.
**inheritance**

12. SE started evolving in 1970s, fact or cap?
**cap**. SE started evolving in 1960s when Simula67 was brought to life. source: p.12 textbook

13. SSADM is a newer method for Agile-based product development. fact or cap?
cap. Agile was born in 2000s, SSADM is born in 1980s. source: p. 14-15

14. UML purposes
visualizing, specifying, constructing, documenting, maintaining. mnemonic: vscodeduma

15. UML is not only modelling standard, but also specifies sequence in which models are to be developed. fact or cap?
cap. first verse is correct, second is wrong. source: p. 16

## chapter 2
1. use case diagrams, class diagrams, and activity diagrams strongly exhibit static characteristics nature. fact or cap? why?
**use case diagram**: **behavioral-static in nature** because they help organize and evaluate requirements of a system.
**activity diagram**: **behavioral-static** in nature, because they show activities and sequence in which they occur, *but not exactly when*.
**class diagram**: **structural-static** in nature, because it does not show any behavioral content. there are no dependencies and no concept of "time".

2. UCs in a UCD cannot be decomposed into layers or levels, i.e., they are all at the same level within the entire requirements model. fact or cap?
**fact**. they cannot be decomposed in the way that data-flow diagrams (DFDs) are decomposed.

3. UCs can be structured and related to represent a process flow, so they are behavioral instead of structural. how to correct?
UCDs being behavioral is correct, but the *behavioral aspect is not visible* in the use case diagram. instead, a more "correct" version would be:

UCDs are behavioral because they represent interactions between actors and UCs, and UCs with each other to capture the flow of a process.

4. documentation of UCs is a rich source to identify business entities that eventually result in classes. fact or cap?
**fact**. p.23

5. lines are used to connect actors to UCs to indicate dependency or flow of info. fact or cap?
**cap**. p. 23: lines only indicate association or communication.

6. activity diagrams can document internal behavior within UCs, between UCs, or the overall business. fact or cap?
**fact**. p. 24

7. lines in activity diagram show dependencies or flow of information. fact or cap?
2 things wrong: 
- activity diagrams use arrows instead of lines, and indicates control flow and data flow. 
- this is not the same as UCDs, because UCDs use it to model interactions.

8. how are multithreading visualized in ADs to model business processes? 
by using forks and joins. 

9. can ADs map their activities to corresponding actors within a system? **UNSURE**
yes, by using swimlanes or partitions.

10. explain why ADs are static, not dynamic.
although the AD does indeed show the activities and the sequences, they do not specifically show **WHEN**. this makes them generic and behavioral, not dynamic.

11. what is another name for "partitions"? 
**swimlanes**.

12. what's the purpose of "partitions" in activity diagrams?
to clarify responsibilities and have some degree of separation between actors, as it represents a distinct unit involved in the workflow. (more ideas: improves readability, showing collaboration between elements)

13. class diagrams are behavioral-static. fact or cap?
**cap**. it is absolutely not behavioral, because it only represent the key entities and show relationship and description of classes. it is static, because the relationships between classes are static.

14. class diagrams represent key entities within business and technical domain. fact or cap?
**fact**. source: p.25 in book.

15. which diagrams are also scenario diagrams?
sequence diagrams.

16. sequence diagram can document behavior within use cases, particularly, messages between actors/systems/collaborating objects within a given time block. fact or cap?
**fact**. 

17. preconditions and postconditions can be shown in SDs. fact or cap?
**fact**. pre/post conditions can be shown in SDs. however, if-then-else interactions are NOT.

19. while activity diagrams are static, sequence diagrams exhibit dynamic characteristics. fact or cap?
**fact**. SDs are **behavioral-dynamic** in nature. because these events are very time based, we are able to determine what happens between two messages and ascertain them as time progresses.

20. if-then-else interactions can appear in interaction overview diagrams (IODs). fact or cap?
**fact.**

21. IODs are behavioral-static. why?
IODs provide a high-level overview of how other diagrams—such as sequence diagrams or even use cases are related to each other, IODs are much closer to activity diagrams than they are SDs. so, the relationships are static, but it is still modelling flow (behavioral).

22. use cases or sequence diagrams in interaction overview diagrams, each must be represented by using a special symbol or icon, which is?
the "ref" keyword in the little tag field on the top-left.

23. which UML diagram maybe considered a tool to show all messages sent and received by an object?
communication diagrams.

24. state machine diagram to model various states in which a UC or entire system can be in. fact or cap?
**fact**. p. 28 

25. are SMDs optimal to model real-time systems?
yes. state machines are able to represent time precisely and in a real-time fashion.

26. SMDs are is to show all possible states (entire behavior or life cycle of object). fact or cap?
fact. they have to be able to depict all behaviors or all the steps the object undergoes. 

27. what UML diagrams can be used as pictorial representation of final executables and linked libraries that contain the code of the system?
component diagrams. source: p. 31

28. dependencies in package diagram are mandatory. fact or cap?
**cap**. they are not mandatory, because they are not as important as the packages themselves.

29. timing diagrams can show multiple objects and corresponding states at the same time. fact or cap?
**fact**. timing diagrams depict states of objects and state changes at precise points in time, and shows them for multiple objects *at the same time*.

30. both SMDs and timing diagrams can show exact point which state change occurs and how long object remains there before changing. fact or cap?
**fact**. they are both able to show this, but timing diagrams can also show it for multiple objects.

31. the only **hardware diagrams** in UML?
deployment diagrams.

32. which diagram can be used to enable discission of operational requirements (ability to handle speed and volume, location and security of nodes, and manner in which they are **deployed**)? 
deployment diagrams. 

33. static-structural UML diagram and dynamic-behavioral
static-structural: class diagrams
dynamic-behavioral: sequence diagrams, state machine diagrams, timing diagrams

## chapter 3
1. UML can be used in which of the following?
a. capturing requirements
b. developing architecture
c. creating designs of software solutions
d. modelling process flows

all of the above.

2. cloud-based services are a very new type of projects introduced many years after UML. therefore, it is not appropriate to use UML for this type of project development and deployment. fact or cap?
**cap**. you can absolutely use UML for emerging technologies, including cloud-based projects. p. 355

3. small projects mainly use the UML in the solution space while large projects use UML for modeling in the problem, solution, and architectural spaces. fact or cap?
**fact**. 
- small projects use UML in solution space, using class, sequence, and SMDs. 
- medium projects need more formality, and creates more sophisticated models with UCDs and activity diagrams.
- large projects have a regulatory need to use UML to model, used extensively in problem and solution space.

4. how and where does organization of software start?
by **identifying business objectives**. first that, then break down the "what, why, how" of the system for prioritization.

5. the decomposition of the primary ---A----  represents the key areas (i.e., subsystems) of the system to be developed, which (most, if not all) are better modeled as ---B--- in the UML.

the complete sentence:
This decomposition of the objective reveals the key areas of the system, which are 
represented as **packages** in UML.

6. by whom should the prioritization process of lower-level business objectives be typically undertaken? 
a. project manager
b. domain experts
c. system users 
d. business analysts.

carried out by **project managers** in a workshop environment with domain experts and business stakeholders.

7. once decomposed, low-level objectives should be modelled by:
a. class diagrams
b. object diagrams
c. use case diagrams
d. IODs
e. communication diagrams

**c. use case diagrams**. alternatively, in large systems, they become lower-level packages.

8. if UML is used, user requirements within each package which represents a low-level business objective should be modelled by: 
a. use case diagrams
b. activity diagrams
c. SMDs
d. class diagrams
e. sequence diagrams

user requirements are modelled with **use case** and **activity** diagrams.

9. UML models in the **architectural** space play a major role in: small medium, large, or collaborative, outsourced projects. which one?
in **large** (50+ people, >1 year, >$10mil) collaborative projects.

10. three main modelling spaces of SWE: distinguish and describe each of them. which of these should use design-level class diagrams to specify lowermost detail of classes? which one uses more UCDs and ADs than the other two?

**problem space**: to understand what the business problem of the user is. these usually explains the problem without going into the specifics. 
**solution space**: contains the design of the system, describing "how" the solution can be implemented. MOSS contains solution-level designs expressed by technical or lower-level class diagrams.
**architectural space**: deals with architecture and management, shows another dimension to SWE. models in this space require a large amount of technical background that must consider key issues of architecture, existing architecture, technical env, and operational requirements.

among these 3:
- **solution space** uses design level class diagrams to specify lowermost details.
- **problem space** uses more UCDs and ADs than the other two.

11. if UML is used to create design spec for analyzed user requirements, what diagrams are typically used?
a. use case 
b. activity
c. SMDs
d. class
e. sequence

idk

12. the package in a package diagram can contain classes, components, UCs, and all other related constructs belonging to a particular subsystem. fact or cap?
**fact**. a package can contain all of the above, but is not necessarily treated as a executable entity, but rather an organizational element in a subsystem.

13. how to represent a subsystem in a UML package diagram?
with packages (?)

14. strengths and weaknesses of package diagrams
**strengths**: 
- excellent organizational unit, as it groups requirements and subsequent work into smaller chunks
- provides a container for all UML elements and diagrams. so, it provides a unique namespace.
- enables layering, since it is possible have package in packages. so, sysdev is much better divivded.
- used to organize work around multiple teams and people, so it can be specifically assigned to a modelling/development team.
- enables robust info architecture, by grouping business models and understanding dependencies.
- provides a good high-level view, if stereotyped appropriately.
- show dependencies between major areas, helping domain experts indicate criticality and providing input to prioritization.

**weaknesses**: 
- unable to show technical details, so not easy to use in a technical sense,
- not object-oriented in nature.
- tends to get confused with classes
- dependencies can become circular.

## chapter 4
1. one of the most confusing confusions in discussing UML-based analysis and design work is to assume UML is a process. why?
**UML is not a process**, it is just a set of standardized notations and diagrams. processes define **activities and roles** that produce the deliverables, while UML only produces the content.

2. one of descriptors of a software development process that defines the level or depth to which a process needs to be performed is called ___ 
**ceremony**. the descriptors are:
- **identifier** - unique name or number for the process, including its revision history.
- **purpose** - goal of the process, such as software production, integration, or maintenance.
- **owner** 
- **user** - roles or people in a project who use the process to create deliverables.
- **beneficiary** - people who benefit from the process outcomes, like managers or business stakeholders.
- **artifacts/deliverables** - outputs or results produced by the process.
- **activities and tasks** - steps taken to produce artifacts, often grouped by user roles.
- **ceremony** - the level (or depth) required in executing the process.
- **metrics and measurements**
- **related processes**

3. 