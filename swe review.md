u879888888## chapter 1
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