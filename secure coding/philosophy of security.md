what does it mean for software, practices, etc. to be secure?

historically, security is often hard-coded. it would be secure for passwords to be changed every set amount of time, or auto logouts.

in reality, there is no one-size-fits-all scheme that can satisfy this. so, secure software adheres to constraints specified by a policy. a policy is some sort of specification of good or bad behavior of a program (what is good/bad, allow/disallow, etc.)

then, a mechanism is (active) a concrete implementation ensuring that software adheres to a policy (passive). when a mechanism $M$ ensures software obeys a policy $P$, we say that **$M$ enforces $P$**. so, all the foundational ideas boil down to a mechanism, a policy, a program, and enforcement.