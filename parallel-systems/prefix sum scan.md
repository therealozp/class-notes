a chef cutting a big sausage. if the chef is a human, it is impossible to cut a bunch of segments at the same time. if we let the chef become a big octopus, he needs to be able to manage where his knives are cutting

## parallel scan
conduct a prefix sum scan for each block, grab the last value and do prefix sum over that, and add it back into the original.

```
[1, 1, 1, 1 || 1, 1, 1, 1 || 1, 1, 1, 1 || 1, 1, 1, 1 ]
  block 1        block 2      block 3        block 4

[1, 2, 3, 4 || 1, 2, 3, 4 || 1, 2, 3, 4 || 1, 2, 3, 4 ]
[4, 4, 4, 4] -> [4, 8, 12, 16]

```