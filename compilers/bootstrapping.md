realistically, DJ has very limited IO functionality. so, having a DJ to DISM compiler in DJ would be difficult.

**pros**: 
- compiler executable on a new target platform
- (specific DJ) compiler is implemented in a type-safe language, which removes a lot of memory bugs (once gc is implemented)
- non-trivial, large program (a compiler itself) added to the test suite.
- incremental feature adding 

a big part of implementing compilers is having a complete test suite. 

### DJ+for to DISM in DJ
adding the `for` keyword support in the language. 

our first DJ compiler fundamentally does not support `for` loops. suppose that we implemented the feature as another program, using DJ. 

using the `DJ to DISM in DISM` compiler to compile said program, we get the next version of DJ+for to DISM in DISM.

you can then re-use the DJ+for to DISM in DISM to compile an actual DJ+for (season 2) that uses for loops innately, instead of using the `while` loop in version 1.

## reflections of trusting trust
Ken describes a C compiler, written in C, that generated target code as usual, but also contained an extra procedure $P$:
1. if the source code seems to be implementing a login command, then (in addition to target code), inserts a back door to allow Ken's password to always log in
2. if source code seems to be implementing a C compiler (bootstrapping), let's make sure to insert the entire process $P$.

now, since the compiler machine code has been contaminated (embedded in the executable), even if we try to "clean" the C program, the compiler will keep on producing these backdoors in the new compiler.[]()