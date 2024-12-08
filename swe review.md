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

3. a process map represents and area of work within software projects. which of the following are an example of process maps?
a. project management
b. system architecture
c. system design
d. system development
e. system testing
f. quality assurance

all of the above.

4. a simple class diagram to model relationship among processes, iterations, and increments?
![[Pasted image 20241207213711.png]]

5. is waterfall SDLC a sequential approach?
yes.

6. waterfall does not factor in inevitable changes in requirements. fact or cap?
**fact.** the life cycle is rigid, easier to manage and report, but is very difficult to provide value.

7. when an OO approach is taken to develop software, iterations and increments are more difficult to integrate. fact or cap?
**cap**. the OO approach makes it easier, due to the modularized and encapsulated nature of OOP.

8. describe iterative and incremental SD processes.
**iterative** enables *repetition* of tasks, so deliverables are produced gradually, encouraging a slow and steady philosophy instead of hurrying to finish.

**incremental** means adding new elements (or diagrams) to an existing deliverable, like adding new packages or developing packages.

9. The only requirement in parallel development is that the ------- between the two packages must be formally defined and developed first.
**interfaces**. not dependency. **interfaces**.

10. given 3 iterations planned at the highest project level, which iteration takes the most time and effort?
always the **second**. it is a detailed iteration that undertakes completion of requirements and apply them in creating a solution.

11. defile CMM (capability maturity model). who developed it? what are the levels?
developed by CMU Software Engineering Institute, the CMM is the most widely accepted benchmark for measuring and improving a software process. 

there are 5 levels to indicate maturity of software processes:
- **initial**: applies processes in ad-hoc manner.
- **repeatable**: process elements and maps are repeatable.
- **defined**: every element in process (what, how, who, and supporting guidelines of when) is properly defined.
- **measured**: process at level 3 can be measured in terms of quality and contribution to process.
- **optimized**: once it is measurable, it is improvable. this is full maturity.

12. Agile is closer to "engineering" than "art". fact or cap?
**cap**. it is closer to an art. source: p. 62.

13. the Agile Manifesto?
- individuals and interactions over processes and tools
- working software over comprehensive documentation
- customer collaboration over contract negotiations
- responding to change rather than following plan.

14. one of the Agile key principles regarding the implementation of software project delivery and quality says the most efficient and effective method of information to and within a development is ---- conversation.
**a. face to face**
b. online
c. digital
d. social media

15. what is scrum and sprint?
scrum is a lightweight process that employs iterative and incremental practices, aimed to get the entire project team together to set a shared and achievable goal. the team *sprints* towards the common goal. (iteration?)

16. any Agile method should contain three elements, including artifacts, -----, and ------.
roles, artifacts, and ceremonies.

17. in an Agile project, what is the product owner responsible for? How is this role different from _project manager_?
this is the key business person whose benefit the product is being developed. this person is the business representative, closely involved with prioritizing work.

by contrast, a project manager is not part of an Agile role. they handle outward-facing jobs like addressing budgeting, schedules, and resources. they also handle regulatory, compliance sign-off, and stakeholder management. 

in some smaller Agile projects, Agile coach and PM can be merged.

18. what is Kanban in an Agile project?
a method used to visualize, manage and improve workflows. improves efficiency by limiting work-in-progress.

contains a Kanban board with stages of workflow: todo, in progress, done. at each stage, Kanban sets a limit on number of tasks that can be worked on at each stage at a time.

emphasizes a steady flow of work instead of fixed time-boxed sprints.

19.  three examples of agile methods in SEP:
- scrum: iterative development with time-boxed sprints.
- kanban: iterative development by limiting WIP
- EXTREME PROGRAMMING: focuses on engineering practices and customer satisfaction, features test-driven dev, pair programming, and CI.

20. what is user story? is it same as use cases?
user story documents the functional requirements of a system in project, which are short high-level unit of functionality. they capture **what the users wants to accomplish, and why**.

by contrast, use case documents requirements from a user's perspective, and focuses more on how the user and system interact with each other. they are process-oriented, suitable for non-Agile contexts.

these two can draw inspo from one another, but are entirely different.

## chapter 5 - use cases
use cases document requirements from a user's perspectives, and also helps with modelling business processes.

1. what and where do use case modelling begins with?
**identification and documentation of users, or actors**. actors also indicate how a system will be used, and provides the core starting point for the rest of modelling.

2. which of the following can be an actor? 
an actor is a role played by a person or thing *external* to the software system, and interacts with system to achieve business goals.

(a) an external system (is not, because no interaction is specified) 
**(b) time** is considered an actor (time triggered events initiate an interaction or process within a system).
**(c) An external entity or system that sends or receives a message from the system** is an actor, because it interacts with a system.
(d) A class that is used to implement the system 
**(e) A role that initiates an interaction with the system**: literally definition

3. an actor may serve as starting point for interface modelling. fact or cap?
**cap**. they provide the core starting point, as they indicate how the system is used. they represent the interface of the system, and may serve as the basis for good classes.

4. actors are not classes, but may serve as basis for good classes. **fact or cap**? 
**fact**.

5. how to distinguish primary from secondary actors?
- primary actors are those for whom the **system exists**. that means, for a hospital management system, the primary actors are patients, doctors, or nurses.
- secondary actors are roles of **indirect relevance**. for example, if an assistant is involved in processing a sample but is actually not involved in any execution of the use cases.

take for contrast, if a user does not directly interact with the computer screen at the bank. they are still considered a primary, because it is for them that the system exists.

6. what does indirect actor mean?
- a **direct actor** are those who actually *use* the system. for example, and admin entering patient details is a direct actor.
- an **indirect actor** are those who never get to use it directly. for example, a customer will never use the HMS directly, if they just stand and provide info instead of interacting with the system.

7. abstract actors and how they are represented
these are more important than the previous two, and can be shown in UCDs. *abstract actors* are **parents of concrete actors**. they are more generalized, and from where specialized actors can be derived.

"Abstract actors can model the common behavior of a system, such as staff logging into the system. Concrete actors model the specific behavior of the system, such as a doctor checking a consultation schedule on the calendar. Since a doctor inherits from staff, there is no need to separately model the log-in procedure for doctors if it has already been modeled for staff."

8. in actor documentations, what should actor relationships describe?
- other relevant actors or use cases in the system with whom this actor is interacting. 
- if there is an inheritance hierarchy, also generalized/specialized actors

9. A use case documents a series of interactions of an actor with a system. It not only describes **what** a system does, but also **how** the system does it. fact or cap?
**fact**. 

10. we can categorize use cases to be business or system level, and also abstract or concrete. fact or cap?
**fact**. both are true.

11. what are pre and post conditions of use cases?
- preconditions are conditions that need to be satisfied before executions can commence.
- postcons are conditions that must be met at the end of exec.

12. in UC documentations, what is the difference between alt flows and exceptions?
**alt flows** represent different path that user can take, maybe not the main "happy" path but is still valid and expected.

**exceptions** handle error conditions or situations when something goes wrong.

13. UCs capture both functional and non-functional aspects. fact or cap?
**cap**. they only capture functional aspects, specifically the business process carried out by the system.

14. because UCs facilitate requirement tracing, they are helpful in creating and executing acceptance cases. fact or cap?
**fact**.

15. use case documentation provides a means for creating activity diagrams, class diagrams, sequence diagrams, and developing test cases in a later stage. It also provides a good basis for coding. is there anything wrong in this statement?
although the first clause is correct, **use case diagrams do not provide a good basis for coding**. it provides good foundation for modelling, but not code generation.

16. use case docs are well standardized in UML. fact or cap?
**cap.** it is anything but well standardized lol

## chapter 6
1. how are UCDs related to MOPS, MOSS, MOAS?
2. there are three specific relationships in between two use cases in a diagram. what are they? if you were to add functionality to an existing use case, which relationship to use, and how to draw?
- **includes**: when part of a behavior is likely to be reused, we can factor out that common behavior as an independent use case.
- **extends**: specializes the behavior of another use case, **used to functionality on an existing use case**. can also be thought as representing an option.
- **inherits**: also known as **generalization**, where a use case implements the behavior described by another higher-level abstract UC.

3. UCDs provide a high-level picture of the system. they present good features to represent flow (sequence of actions), but also dependencies in system, 