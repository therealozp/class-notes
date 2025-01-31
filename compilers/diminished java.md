## method

```ds
main {
	variable declarations
	series of expressions (expression list)
}
```

```ds
// a function that doesn't use arguments
[final] nat f(nat unused) {
	expression list here
	0 // returns 0
}
```
## class

```ds
[final] class C extends S {
	variable declarations
	method declarations
}
```

anything that has the keyword `final` means that:
`final` classes **may not be extended** (subclassed), and `final` methods **may not be overridden**. 