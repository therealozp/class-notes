a programming language accepts valid strings that tells a machine what to do. however, this should also mean that the compiler should be able to filter out **invalid strings**. these invalid strings can cause security vulnerabilities.

writing a compiler is also very akin to implementing a language. so, type checking strikes as an extremely important component, as it ensures that programs are valid.

reserve memory bank 0 for the null pointer. because of inheritance and polymorphism, the compiler doesn't really know which method to execute inside of a class. we constantly need to determine the type of every object to know which one is being accessed.

when assigning types to classes, we can give the base class the number 0; and for every subsequent user-defined class, we just increment it by 1.

fields and methods are members of objects (or classes).
## security concerns
dot operators are a more convenient way to do pointer arithmetic. suppose that a member is accessed and assigned:

```
nl.data = n2
```

its equivalent when referencing memory would be :

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

## strong vs. weakly typed languages
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

### main block symbol table
- an array of `VarDecl`s for the the main block. size = `numMainBlockLocals`.
- type definition for the `VarDecls` structure:

```c
typedef struct vdecls {
	char * varName; // 1
	int varNameLineNo; // 2
	
	int type; // 3
	int typeNameLineNo; // 4
} VarDecl
```

let $i$ be the type number. it could fall in between one of the following: 
- the $i^{t h}$ class declared ($i > 0$)
- the overarching base class `Object` (where $i = 0$)
- the `nat` type ($i = -1$)
- the "any object" (mostly `null`) object: it needs to be its own object, that could stand in for any other object type. in this case, $i = -2$
- DJ defines all classes to have a super-class. so, in the symbol table, it necessitates the existence of `Object`'s super-class as well. to represent this, we can use the "no-object" type, where $i = -3$
- undefined, or has no type ($i - 4$)

so, we can build the symbol table for the following snippet:

```java
class C extends Obj {...}
main {nat n; C c; Object o; 0;}
```

then, the symbol table for the following would be:

```txt
mainBlockST[0].varName = n
mainBlockST[0].type = -1
mainBlockST[1].varName = C
mainBlockST[1].type = 1
mainBlockST[2].varName = o
mainBlockST[2].type = 0

numMainBlockLocals = 3
```

### class declarations sym table

a valid class tree will always have the `Object` class as the root.

```c
ClassDecl *classesST // an array of size numClasses
		   classesSt[0] // class ST for object
		   classesSt[1] // 1st class defined by program
```

a `ClassDecl` object is a `struct` with the following fields:

```java
typedef struct {} VarDecl;

typedef struct {
	char * className;
	int classNameLineNumber;
	int superclass; // helps access parent classes by reusing symtable
	int superclassLineNo;
	int isFinal;
	
	// luckily, we have the perfect data structure to store the fields
	VarDecl* fields;
	int numVars; // how many fields do we have
	
	MethodDecl* methodList
	int numMethods;
}
```

so, for example, if we want to access the type of the **third** field of the **second** user-defined class, we can access it with something like:

```c
classesST[2].varList[2].type // the first variable declaration is in 0
```

### method declarations

```java
typedef struct {
	int isFinal;
	
	char* methodName;
	char* paramName;
	
	int returnType;
	int paramType;
	
	int methodNameLineNo;
	int paramNameLineNo;
	int returnTypeLineNo;
	
	VarDecl* localST;
	int numLocals;
	
	ASTree* bodyExprs;
} MethodDecl
```

if we have another pointer to the expression list body within the method declaration, that would make our lives much easier by enabling us array-like access to the method body.

take the following snippet:

```java
class C extends Object {
	nat foo(nat bar) {C x; 0;};
}
main {0;}
```

if we want to access and initialize `C x`, we have something like:

```js
classesST[1].methodList[0].localST[0].varName = x
classesST[1].methodList[0].localST[0].type = 1
```

1. understand ASTs very well. to construct symbol tables, there is a lot of AST traversals.
2. use `calloc()` (in stdlib) to initialize arrays. 

```c
classesST = calloc(numClasses, sizeof(classDecl);
if (classesST == NULL) {
	internalSTerror("Error in calloc")
}
``` 

3. some good helper functions

```c
int typeNameToNumber(char *typeName) {
	// initial checks to ensure that the AST is valid
	if (strcmp(typeName, "Object") == 0) {
		return 0;
	}
}
```