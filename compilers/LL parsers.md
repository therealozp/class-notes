also called **predictive parsing**, **recursive-descent**, or **top-down**. called the **LL** parser because:
- process input from left to right
- it expands non-terminals with rules from left-to-right, creating a **leftmost** derivation.

![[Pasted image 20250219173245.png]]

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

then, we can write some parse functions for each non-terminal as follows:

```c
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
		}
		case 0: {
			consume("0");
			return; 
		}
		case 1: {
			consume("1");
			return; 
		}
		default: error
	}
}
```

the parse stack we mentioned before is not explicitly defined, but rather, we make use of the **recursive call stack** to parse.

> you can **NEVER** have a left-recursive language be parsed with an LL parser.

### LL parse table

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