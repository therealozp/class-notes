a **translator** is a program that takes in a program (source code) written in some source language $S$, and compiles it to another program (object code) written some target language $T$, that is **functionally (or behaviorally) equivalent**.

a **compiler**, is a translator where $T$ needs to be a (possibly virtual) machine language. 

in contrast, an **interpreter** translates the code to a lower-level language **just-in-time**, so it does it as the program runs. the compiler translates everything into another target language before execution.

```
        +----------+
src --> |          | --> target
dj  --> | compiler | --> DISM
C   --> |          | --> x86, ARM
        +----------+
```

a job of a compiler is not only to compile valid programs, but also have an option to **reject invalid programs**.
## phases of compilation
**source program** *--lexical analyzer (lexer, tokenizer, scanner)-->* **token stream** *--parser-->* **tokens organized into categories** *--parser actions-->* **abstract syntax trees (ASTs)** *--semantic analysis (type checking)-->* **valid (well-typed) ASTs + symbol table** *--code generation-->* **machine code**

- a **token** is a program characters that are grouped into their smallest logical meaning.
- the abstract syntax tree moves from a 1-D token stream to a 2-D data structure, which helps eliminates a lot of unrelated characters. delimeters (such as the ";") and parentheses are candidates to this removal.
- a symbol table maps variables to their corresponding types. for example:

```
	PLUS -> maps to int
    /  \
int(3)  int(4)  
```

everything before (not including) building the well-typed AST and symbol table is **front-end analysis**, everything after (not including) it is **back-end synthesis**. in this case, the symbol table is an **intermediate representation** (IR), written in an **intermediate language** (IL).

in the real world, the backend is much much more complicated than the frontend, where code generation is much more complex, and can also get broken up into multiple different stages as well.