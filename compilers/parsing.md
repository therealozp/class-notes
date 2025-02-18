the categorizing **process of sequences** of tokens based on orderings.

a language's syntax are the parsing rules to categorize sequences of tokens. **syntactic analysis** is the parsing phase of the compiler.

```
tokens stream --(parser)--> tokens in categories --(parser actions)--> AST
```

anywhere in the parsing process, a **stack** will be involved.

a parse tree (or a syntax tree) of a program, is a tree representing a program's syntactic structure. 
- a **concrete** syntax tree is a tree where a program can be read by reading the leaves of the tree.

parsers operate as a [[non-deterministic push-down automata|push down automata]], which is just an NFA with a stack. generally, PDAs are more powerful than NFAs. the equivalent to PDAs are context-free grammars (CFGs), which are **rules of syntax** for a PL.
- rules define which orderings of tokens constitute valid programs
- contain categories of token sequences (also called **syntactic categories** or **nonterminals**)
- contain possibly recursive rules (grammar rules or productions) defining which token sequences belong to which **categories**.

```
expr_list   ::= expr SC expr_list | $\epsilon$
expr        ::= NAT | expr PLUS expr | expr TIMES expr 
```

in the above example, `expr_list` and `expr` are categories (non-terminals), while terminals are expanded from tokens. 

a symbol is a non-terminal or a terminal $\to$ $\epsilon$ is **NOT** a symbol.

rules are written in Backus-Naur form (BNF), which looks like:
- $N ::=\Sigma$ | $N::=\sigma_{1}, \sigma_{2}, \dots, \sigma_{n}$
- $N ::= \Sigma_{1} \mid \Sigma_{2}$
- ...

a language is called **right-recursive** if the non-terminal on the LHS in same as the **rightmost symbol** on the RHS of the production rule. similarly, a **left-recursive** language if the non-terminal on the LHS is **same as the leftmost symbol** of the RHS. 

**ambiguous** CFGs means that, for the same language, there can be multiple ways to compile (> 1 parse trees) for the same program.

to resolve this problem, we can turn our ambiguous language into a left/right recursive language. consider the following:

```
e -> N | e + e | e * e
```

we want to make the `*` operator bind more tightly than the `+` operator, and make both of these left-associative (hint: use left-recursion). whichever way-associative you want, pick the way-recursion grammar.

let `t` define the term, and `f` define a factor. we say that the levels matter, meaning that whichever is placed on top is evaluated first.

```
e -> e + t | t
t -> t * f | f
f -> N
```

### shift-reduce parsing
at every step, either:
- shift (push) an input symbol (token) onto the stack, and consume from the input, **or**
- reduce the stack from `[o1, o2, o3, ..., oN]` using the rule $N\to \sigma_{1}, \sigma{2}, \dots, \sigma_{N}$ to make the stack.

also called **bottom-up** parsing and **LR parsing** (process input **left-to-right**, builds **rightmost derivation**, or always choosing to process the *rightmost non-terminal* in a grammar).

balanced parentheses grammar:

```R
S' -> S$
S  -> (S)S | epsilon
```

for a grammar:

```R
pgm -> expr$ # ($ indicates EOF)
expr -> f(expr) | 0
```

for a grammar defined by:

```
S' -> S$
S  -> (S)S | epsilon
```

| stack  | input | action                     |
| ------ | ----- | -------------------------- |
| ` `    | `()$` | shift                      |
| `(`    | `)$`  | reduce by $S \to \epsilon$ |
| `(S`   | `)$`  | shift                      |
| `(S)`  | `$`   | reduce by $S\to \epsilon$  |
| `(S)S` | `$`   | reduce by $S \to S(S)$     |
| `S`    | `$`   | shift                      |
| `S$`   | ` `   | reduce by $S' \to S$       |
| `S'`   | ` `   | accept                     |
|        |       |                            |
## LR(0)
again, the LR class of parser belongs to the shift-reduce/bottom-up class of parsers. LR(0) is a simple version of what production-environment parsers are. the '0' means that the parser has no lookahead (LA) symbols.

defined as an NFA controlling a stack. the NFA states are items, for example

```
S -> E$
E -> T + E | T
T -> x
```

to derive the items of the NFA, we can insert a dot into each of the possible position of every production rule:

```
S -> .E$
S -> E.$     # this indicates stop @EOF

E -> .T + E
E -> T. + E
E -> T +. E
E -> T + E.

E -> .T
E -> T.

T -> .x
T -> x.
```

> **NOTE**: never write the $\epsilon$ transition state. $A\to\epsilon$ **does NOT** constitute a valid state $A\to.\epsilon$, because it creates epsilon transitions.

we get the trace for $N\to \sum_{1}\sigma \sum_{2}$, where:
- $\sum$ indicates a **possibly empty** sequence of tokens
- $\sigma$ is a symbol
- and $N$ is a non-terminal

**rules**: 
- anytime we encounter the transition: $N \to \Sigma_{1}\cdot\sigma\Sigma_{2}$, we can consume the $\sigma$ to move to the state $N \to \Sigma_{1}\sigma\cdot\Sigma_{2}$
- anytime we encounter a non-terminal $N$: $N \to \Sigma_{1}\cdot N'\Sigma_{2}$, we can use a $\epsilon$ transition to switch non-terminals $N'\to \cdot\Sigma_{3}$.

parse stack for LR parsers contain the state numbers. show the symbols on the stack in the exam!

- push the state $q$ on the stack which has the item $S\to .N$
- repeat until error/accept:
	- let $s$ be the state on the top of the stack.
	- if $N\to\Sigma_{1}.T\Sigma_{2}$ is an item in $s$, and $T$ is next input, then **shift**.
		1. push the $T$ onto the stack
		2. push $s'$, where $s \to^{T}s'$
		3. consuming $T$ from input
	- if $N\to\Sigma.$ is an item in $s$, **reduce**.
		1. popping $\Sigma$ and its corresponding states. now, $s'$ is on top of the stack (and has the item $N'\to \Sigma_{1} N\Sigma_{2}$)
		2. pushing N
		3. pushing $s'$, where $s'\to^{N}s''$
	- if $S\to N.end$ is an item in $s$, and $end$ is the next input, **accept**.
	- if 0 (parse error, external) or more than 1 (parse conflict, internal) of the above rules apply, **error**.

a parse table indicates which state we can go to after we reduce (aka when we reduce, we move on to the next state)

suppose that we are operating on the following language:

```
S -> E$
E -> T + E
E -> T
T -> x
```

we start by filling out all the shift operations. $sN$ means "shift the input and move to state $N$.

| state | x   | +   | $      | E   | T   |
| ----- | --- | --- | ------ | --- | --- |
| 0     | s2  |     |        |     |     |
| 1     |     |     | accept |     |     |
| 2     |     |     |        |     |     |
| 3     |     | s4  |        |     |     |
| 4     | s2  |     |        |     |     |
| 5     |     |     |        |     |     |
then, we can add in the `goto` operations, which consumes a non-terminal. $gN$ moves to state $N$.

| state | x   | +   | $      | E   | T   |
| ----- | --- | --- | ------ | --- | --- |
| 0     | s2  |     |        | g1  | g3  |
| 1     |     |     | accept |     |     |
| 2     |     |     |        |     |     |
| 3     |     | s4  |        |     |     |
| 4     | s2  |     |        | g5  | g3  |
| 5     |     |     |        |     |     |
finally, add in the `reduce` operations, which pops the state and the current token on stack, before moving to another state. unlike the above two, $rN$ reduces **by the rule $N$**.  however, the reduce operations **fill out the entire row!**

| state | x   | +         | $      | E   | T   |
| ----- | --- | --------- | ------ | --- | --- |
| 0     | s2  |           |        | g1  | g3  |
| 1     |     |           | accept |     |     |
| 2     | r3  | r3        | r3     |     |     |
| 3     | r2  | **s4/r2** | r2     |     |     |
| 4     | s2  |           |        | g5  | g3  |
| 5     | r1  | r1        | r1     |     |     |
in state 2, on the "+" input, we see that there is two possible actions the parser could take. since these two actions are shift/reduce, we call this a **shift-reduce conflict**. another possible type is the **reduce-reduce conflict**, but *never* a shift-shift conflict.

this is illegal, and we say that this language is **cannot** be parsed by the $LR(0)$ algorithm, or $G \not\in LR(0)$.
### parse trace
we can use a parse trace table to keep track of where the parser is at any given input. assuming the same language $G$ as above, we attempt to parse `x$`:

| stack | input | action |
| ----- | ----- | ------ |
| 0     | x$    | s2     |
| 0x2   | $     | r3     |
| 0T3   | $     | r2     |
| 0E1   | $     | accept |

## SLR parser
stands for simple LR, and has a lookahead length of 1. here, $follows(N)$ indicate a set of tokens that can follow a token $N$.

so, using the language $G$ above has:
- $follows(E) = \{ \$ \}$
- $follows(T) = \{+, \$ \}$

1. draw the LR(0) finite state machine
2. compute all the follows (lookahead length of 1)
3. reduce only if the input matches one of the follows and correct state. for example:
	- if the stack currently has the token $T$, and the next input is $+$
	- instead of reducing $E \to T$, the parser sees that $+\not\in follows(E)$, so it will **not reduce**
	- instead, the token $+$ is shifted in, and parsing continues as usual.

bottleneck: the LR parsers can chain tokens, maxing out the stack, before popping each token. this is an extremely inefficient use of space.

### more sets
- $follows(N)$ indicates all **tokens** that immediately follows a substring derived from $N$
- $nullable(\Sigma)$ is true if and only if $\Sigma$ can expand into $\epsilon$
- $first(\Sigma)$ indicates all **tokens** that can begin an expansion of $\Sigma$

consider the language:

```
S -> Z$
Z -> XYZ | d
X -> Y | a
Y -> ep | c
```

| token | null | first   | follows |     |
| ----- | ---- | ------- | ------- | --- |
| S     | F    | a, c, d |         |     |
| Z     | F    | a, c, d | $       |     |
| X     | T    | a, c    | a, c, d |     |
| Y     | T    | c       | a, c, d |     |
## LR(1)
LR(1), aka the **canonical LR parser** has massive parse tables, too many DFA states, making parsing too complicated. one of the two choices of building production-level parsers, but normally we use the LALR parser.

we call this canonical LR, because any LR parser $LR(k)$, for any constant $k$, can be reducible to some form of $LR(1)$. $LR(1)$ has all the computation possible for any standard programming language.

LR(1) is similar in concept to LR(0), except items have lookaheads.  takes the form:
$$N\to\Sigma_{1}.\Sigma_{2}.\ \ \ \ \ T$$
where $T$ is the lookahead character, to tell the parser **when to reduce**.
### transitions
- on $N\to\Sigma_{1}.\sigma\Sigma_{2}\ \ \ \ \ T$, consume a $\sigma$ to go to $N\to\Sigma_{1}\sigma.\Sigma_{2}\ \ \ \ \ T$
- on $N\to\Sigma_{1}.N'\Sigma_{2}\ \ \ \ \ T$, consume $\epsilon$ and go to $N' \to .\Sigma_{3}\ \ \ \ \ T'$, where $N'\to \Sigma_{3}$ is a valid rule and $T'\in first(\Sigma_{2}T)$ 

consider the example language

```
S -> A$
A -> (A) | a
```

to parse with an LR(1):
- first, write the starting state. in this case, `S -> .A$`
- we see there is a dot in front of the token `A`, we chase down all possible states that starts with `A`
- now, we need to compute the lookahead. meaning that, whichever state that we originated from, we find the first character **AFTER THE DOT MOVED**, in this case, for state 0, is \$.
## LALR
to derive an LALR parser, we go from LR(1) and merge its DFA states where **states only differ in the lookaheads.**

