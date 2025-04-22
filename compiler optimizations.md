## Turing machines
general models of computation, to show that something is impossible (certain algorithms do not exist to solve some problems).

TMs are all FSMs, so they have finite states and finite input, but infinitely long tape. a Turing machine can either converge (aka terminate, halt) or diverge: 
1. eventually accept -> enter accept state
2. eventually rejects -> enter reject state
3. diverge (i.e. not halt)

a TM is a 7 tuple:
- state set
- multiple alphabets $\Sigma$, also called the "input alphabet". $\_{}\not\in \Sigma$
- tape alphabet (every symbol that could appear on the tape) $\Gamma$
- transition function $\delta$: from a position on the tape with a certain state and input $Q\times \Gamma$, we can go to another state, rewrite the current cell, and move the head left or right $Q\times \Gamma \times \{ L, R \}$
- initial state
- accept state
- reject state

a TM can also have multiple tapes. this doesn't really affect the overall power of the TM, just makes it faster.

anything a non-deterministic TM can do, a TM can also do (with extra steps). non-determinism does not give a TM extra power.

## decidability
a set $S$ of strings is **decidable** (or **computable**, or **recursive**) if there exists a TM that:
- when input any string $s\in S$, eventually accepts
- when input any string $s \not \in S$, eventually rejects
either way, they need to **halt**. *divergence is not allowed*.
### the Church-Turing thesis
lambda calculus (founded by Church) is good for programs, TMs are good for resource analysis and computation complexity.

a thesis because the notion that TM $\equiv$ algorithms cannot be proven, because TM is trying to model something that needs a definition.
### halting problem
let $H = \{ <M, s> | M\text{ halts on input }s \}$
theorem: $H$ is undecidable

