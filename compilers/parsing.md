the **categorizing process of sequences** of tokens based on orderings.

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

a language is called **right-recursive** if the non-terminal on the LHS in same as the **rightmost symbol** on the RHS of the production rule. 

```
E -> T + E
T -> epsilon
```

similarly, a **left-recursive** language if the non-terminal on the LHS is **same as the leftmost symbol** of the RHS.

```
E -> E + T
T -> epsilon
```

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

yacc: yet another compiler compiler.
## LL vs LR
### LL parsing
LL parsing tends to need a lot of rewriting the grammar to eliminate left-recursion. so, it is very time-consuming.

on the contrary, predictive parsers are **faster**. however, only applies when you actually hand-write the parser. once you have introduced another third-party tool into the mix, you lose all performance benefits.

possible tools are ANTLR (another tool for language recognition), which generates an $L L (*)$ language. this also makes it quadratic time.
### LR parsers
is usually the goto, unless you have a lot of time to waste and value performance; the grammar is so small where hand-writing is so easy, or you want convenience of another modern tool (say, ANTLR).

