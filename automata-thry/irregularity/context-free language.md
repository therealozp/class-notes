a [[grammar]] G is context-free if all production rules are of the form: 
$A\rightarrow x,$ where $A \in V \text{ and } x \in \set{V\cup T}^{*}$
or in English, if the LHS of the transition function is only **one** variable, then it is a context-free language.

by contrast, context-sensitive grammar is when the context of the variables matter. for example: 

$S\rightarrow aSBc \mid abc$
$cB\rightarrow Bc$
$bB\rightarrow bb$

here, for example, if a $c$ precedes the variable $B$, then it can be converted to $Bc$, and so on. then, there is a context that the grammar is to obey so that the transition function can be executed.

## linear grammar
the a grammar is linear if it is **context-free** and all of its RHS have **at most** one non-terminal symbol (variable).

so, the language below is linear: 
$S\rightarrow aSb$
$S\rightarrow \lambda$

but this language is not: 
$S\rightarrow aSb$
$S\rightarrow SS$

## ambiguous grammar
meaning that there is more than one way to derive strings. take the string $aabb$ and the below grammar for example: 

$S\rightarrow aSb \mid \lambda$
$S\rightarrow SS$

then, the string can be derived as: 
- $S\rightarrow aSb \rightarrow aaSbb \rightarrow aabb$
- $S\rightarrow SS\rightarrow aSb\lambda \rightarrow aaSbb\rightarrow aabb$
there is more than one way where the string $aabb$ can be derived, hence, it is ambiguous.

> if a grammar is linear, then it also **must** be non-ambiguous.




