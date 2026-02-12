also called **predictive parsing**, **recursive-descent**, or **top-down**. called the **LL** parser because:
- process input from left to right
- it expands non-terminals with rules from left-to-right, creating a **leftmost** derivation.

![[parser sets.png]]

easier to code. consists of three main things:

```c
// peeks the immediate next token
Token peek() {
	...
}

// consumes the character
void consume(Token t) {
	if (peek() != t) {
		error
	} else {
		consume t from the input stream
	}
}
```

for example, take the language 

```
S -> e$
e -> IF e THEN e | PRINT e | 0 | 1
```

then, we can write some pseudocode for the parse functions for each non-terminal as follows:

```c
void consume(Token t) {
	if (peek == t) {
		consume t from input
	} else {
		throw EXTERNAL syntax err
	}
}

void parseS() {
	parseE();
	consume($);
}

void parseE() {
	switch peek() {
		case IF: {
			consume('IF');
			parseE();
			consume('THEN'); 
			parseE();
			return;
		}
		case PRINT: {
			consume("PRINT");
			parseE();
			
			// MANDATORY RETURN TO AVOID FALL THROUGH
			return; 
		}
		case 0: {
			consume("0");
			return; 
		}
		case 1: {
			consume("1");
			return; 
		}
		default: error // EXTERNAL ERROR
	}
}
```

the parse stack we mentioned before is not explicitly defined, but rather, we make use of the **recursive call stack** to parse.

> you can **NEVER** have a left-recursive language be parsed with an LL parser. thus, we have the one-way implication: left recursive $\Rightarrow \not\in L L(1)$. note that this implication only applies **one-way**, meaning if it is not in $L L(1)$, it does not have to be left-recursive.

### LL parse table
### auxiliary sets
- $follows(N)$ indicates all **tokens** that immediately follows a substring derived from $N$
- $nullable(\Sigma)$ is true if and only if $\Sigma$ can expand into $\epsilon$
- $first(\Sigma)$ indicates all **tokens** that can begin an expansion of $\Sigma$

to start the LL-parsing process, we first need to construct the table:

| production rule | $first(RHS)$                                | $n ullable(RHS)$ | $follows(LHS)$        |
| --------------- | ------------------------------------------- | ---------------- | --------------------- |
| prod 1          | all beginning tokens of the right-hand side | is RHS nullable? | what follows the LHS? |
**to save time**: we only ever have to compute the follow set *if the RHS is nullable*.

### parse table
to compute the parse table, we construct the following, where $N$ are production rules and $T$ are terminals:

| token / peek | $T_{1}$ | $T_{2}$ | ... |
| ------------ | ------- | ------- | --- |
| $N_1$        | rule#   |         |     |
| $N_2$        |         |         |     |
| ...          |         |         |     |
each cell means "if we are on the token $N_{1}$ and encounter the peek $T_{1}$, parse by the rule defined there."

to build the parse table, we follow: $\forall N\to\Sigma$:
- $\forall T \in first(\Sigma)$: put $N \to \Sigma$ at (row N, column T) **and**
- if $nullable(\Sigma)$, $\forall T \in follows(N)$, put $N\to\Sigma$ at row N column T

**ambiguous grammars cannot be parsed by any parser. you can always write left-recursive into right-recursive rules, and vice-versa.**

the fewer tokens inside the first/null/follows table, the better as it lowers the chance of a parse conflict.

making a language LL-parsable usually means constructing a few artificial transformations to make it work. examples include:
- left-recursive to right-recursive transformation
- disambiguation
- left-factorization

left-factorization applies for cases like:

```
S -> E$
E -> if E then 0 else 0
E -> if E then 0
E -> 0
```

because there is the same E token, this language is infinitely recursive, and does not even belong in $LL(k)$.

## $L L (k)$ and $L L (*)$
for some languages, for example

```
S -> A$
A -> Bx
A -> By
B -> xB
B -> y
```

because of the nature of `B`'s expansion, which is $x^*y$, we are unable to determine the $k$-lookahead of `A`, for any finite value of $k$. so, a solution is to use $L L (*)$, which matches a **regular expression** instead of a token.

```c
parseA() {
	switch (lookaheads match): 
		case x*yx: {
			parseB();
			consume(x);
			return;
		}
		
		case x*yy: {
			parseB();
			consume(y);
			return;
		} 
}
```

the quadratic time arises from the processing of these regexes, which have to go through the entire sequence of lookaheads (length $n$) for each character in the input (length $n$). TODO: disambiguate