a **translator** is a program that takes in a program (source code) written in some source language $S$, and compiles it to another program (object code) written some target language $T$, that is **functionally (or behaviorally) equivalent**.

a **compiler**, is a translator where $T$ needs to be a (possibly virtual) machine language. 

```
        +----------+
src --> |          | --> target
dj  --> | compiler | --> DISM
C   --> |          | --> x86, ARM
        +----------+
```
