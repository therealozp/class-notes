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

## Simplified PoS for each group
