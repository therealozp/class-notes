goal of forecasting is always to predict your future as well as possible; so the loss functions dictate the penalty if you are wrong.

consider case where we can either run a backup generator if it is cold.

| case   | run generators | not run generators |
| ------ | -------------- | ------------------ |
| cold   | 0              | 1.5 million        |
| normal | 1 million      | 0                  |

this type of loss function is said to be non-symmetrical, meaning that the loss values is not the same. if it were symmetrical:

| case   | run generators | not run generators |
| ------ | -------------- | ------------------ |
| cold   | 0              | 1 million          |
| normal | 1 million      | 0                  |

then, we can choose the forecast option with the lowest expected loss. 

## properties
a mathematical function ${L}(e)$ is a loss function if it satisfies the three properties:
1. ${L}(0) = 0$
2. $L$ is continuous (not disjoint)
3. $L(e)$ is **increasing** on both sides of the origin

