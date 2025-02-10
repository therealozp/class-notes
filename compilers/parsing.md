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

also called **bottom-up** parsing and LR (process input **left-to-right**, builds **rightmost derivation**, or always choosing to process the *rightmost non-terminal* in a grammar).



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
a simple version of what real parsers are. the '0' means that the parser has no lookahead (LA) symbols

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

we get the trace for $N\to \sum_{1}\sigma \sum_{2}$, where:
- $\sum$ indicates a **possibly empty** sequence of tokens
- $\sigma$ is a symbol
- and $N$ is a non-terminal

