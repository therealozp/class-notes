in a branch instruction, why are we not fetching the next instruction during the decode phase, but instead during the execute phase?

- to avoid flushing out extra instructions. if we fetch next during decode, then by the time we reach execute, we will have already fetched another one. 
- if we fetch during execute, if the branch fails, we will only have to flush out one instruction.
