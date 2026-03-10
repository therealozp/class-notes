rzea **trace** (or **run**, or **execution**) is a sequence of security relevant actions (or **events**). 

consider the program `echo`,  where our traces are (separated by semicolons). traces may be **converging** (terminating) or **diverging** (non-terminating).

```
input('a');output('a') // if the program waits for inputs and hangs
in('a'); out('a'); in(Ctrl + C); exit
ε // for an empty trace
in(a);out(a);in(a);out(a);... // infinite length trace
```

let's denote a program as $\mathcal{p}$. then, $\mathcal{p}_{\text{echo}}=\{ \text{all of the above choices},\dots \}$. there are uncountably infinite traces of $\mathcal{p}_{\text{echo}}$. 

then, a program is just a set of traces. and a policy is a set of programs (of all *good*/*secure*/*valid* programs). so that means a policy is a **set of sets of traces**.

a policy $P=\{\mathcal{p_{1}}, \mathcal{p_{2}},\dots\}$
a policy $P=\{\{ t_{1}^{1};t_{2}^{1};t_{3}^{1},\dots \}, \{ t_{1}^{2};t_{2}^{2};t_{3}^{2},\dots \},\dots\}$
a policy $P$ where there are no null dereferencing: $P_{1}=\{ \{ t_{1}, t_{2},\dots \}\ |\ \forall i: \text{read(0)}\not\in t_{i}\}$
