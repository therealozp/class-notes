just makes everything more convenient by eliminating the need for fluff like semicolons, braces, and parenthesis. made possible by pushing this to another dimension.

## construction
### for LL
hijacking the parse functions given from an LL parser, we can derive something like:

```c
AST * parseN() {
	switch (peek()) {
		case 0 {
			consume(0);
			A = parseN'();
		}
		case 1...
		case 2...
	}
}
```
### for LR
for a rule defined in the `yacc` file:

```y
pgm: expr {
	// this part contains semantic-action code
	// that only executes when reducing by this rule
	return 0;
}
```

so, we can also hijack this to generate our AST:

```
pgm: expr {
	// bison syntax, $1 indicates the first token on the RHS of the rule
	return newPgmAST($1);
}

// bison syntax, \$\$ indicates the token on the LHS
// yytext matches the actual semantic value of ID
expr: ID { $$ = newIDAST(yytext)}
	| expr PLUS expr {SOMETHING HERE}
	;
```

inside the processing for `expr PLUS expr`, we also put `$$ = newPlustAST($1, $3)`, which generates a new AST that takes in `expr` and `expr` as the nodes. note that whatever token that goes inside the AST creation **should never** be a token (PLUS, MINUS, etc.), it should just be a non-terminal.







