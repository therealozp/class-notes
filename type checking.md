a programming language accepts valid strings that tells a machine what to do. however, this should also mean that the compiler should be able to filter out **invalid strings**. these invalid strings can cause security vulnerabilities.

writing a compiler is also very akin to implementing a language. so, type checking strikes as an extremely important component, as it ensures that programs are valid.

reserve memory bank 0 for the null pointer. because of inheritance and polymorphism, the compiler doesn't really know which method to execute inside of a class. we constantly need to determine the type of every object to know which one is being accessed.

when assigning types to classes, we can give the base class the number 0; and for every subsequent user-defined class, we just increment it by 1.

fields and methods are members of objects (or classes).

dot operators are a more convenient way to do pointer arithmetic. suppose that a member is accessed and assigned:

```
nl.data = n2
```

its equivalent when referencing memory would be 

```
MEM[nl - data] = n2
```

where data is the offset defined in memory. suppose that we have a snippet: 

```
nat n1;
n1 = readNat();
n1 = new natList();
n1.data = n2;
```

without any type checking, the type `natList` is assignable to the variable of type `nat`. if the `data` field is accessed without intervention, it may intrude in a memory section defined by another block, thus granting arbitrary memory occupation.

type-safe (aka strongly-typed) programming languages ensure that all language-level values only get used in allowed ways. 

by contrast, weakly-typed languages only ensure that **some (but not all!)** language-level values gets used in allowed ways. (like C or C++).

increasing security comes at the cost of decreasing performance. 

lambda calculus is created to model general computation, even pre-dating turing machines. it is naturally untyped.

a lot of programming language is typing. 

a type checker is a proof checker, trying to prove that our program will only behave as expected. one big challenge for the type checker is that it does not have any access to the semantics in general, so it has no way to check!

a type checker couldn't be integrated in the parsing stage, because it is **context-sensitive**. so, consider the following statement:

```
printNat(x + 6); 
```

is this valid? probably. probably not! depends on what the value of `x` is. so, we need the context of what `x` is to be able to see if it is valid. 
## symbol tables
a data structure that maps variables to their types. we should have 2 global symbol tables - get/set in `setupSymbolTables(ASTree *x)` -> at this point, there is no type checking.

1. `VarDecl* mainBlockST`
	- an array of `VarDecl`s for the the main block. size = numMainBlockLocals.
	- type definition for the var decls structure:

```c
typedef struct vdecls {
	char * varName; // 1
	int varNameLineNo; // 2
	
	int type; // 3
	int typeNameLineNo; // 4
}
```



