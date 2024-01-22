Organize by neighbors (cells that differ by only 1 variable e.g. AB and AB'), change everything to minimized SOP. For example, in a 2-variable K-map, representing $A + B'$

| B / A | 0   | 1   |
| ----- | --- | --- |
| 0     | x    |     |
| 1      | x    | x    |

For a combination of 4 variables $A,\ B,\ C,\ D$, we have the following K-map: 

| CD / AB | 00  | 01  | 11  | 10  |
| ------- | --- | --- | --- | --- |
| 00      | 0    | 4    | 12    | 8    |
| 01      | 1    | 5    | 13    | 9    |
| 11      | 3    | 7    | 15    | 11    |
| 10        | 2    | 6    | 14    | 10    |
In this case, the neighbors wrap around, so cell 10 has neighbors 11, 14, 2, and 8. 
## Grouping
In general, when minimizing with K-maps, there are 5 rules: 
1. each cell (minterm or maxterm) on a K-map of $n$ variables has $n$ logically adjacent cells, each differing exactly 1 variable.
2. when combining cells, **always group in powers of 2**. Grouping cells in $2^{n}$ cells eliminate $n$ variables.
3. group as many terms together as possible, more terms $\rightarrow$ less literals.
1. **make as few groups as possible** to cover all cells. A minterm or maxterm is covered if it is included in at least one group. the fewer the groups, the fewer the number of product terms in the minimized function. each minterm or maxterm **can be used as many times as needed, but it must be used at least once.** 
2. in combining cells on the map, always **begin with those cells which have the fewest number of adjacent** cells (**lonelies**). Terms with multiple adjacent minterms (**adjacencies**) should be combined later.

## Simplified PoS for each group
