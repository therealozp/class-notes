## problem 1
(a) k = 1. With the rule “a point can be its own neighbor,” 1-NN memorizes the training set, so the training error is 0.

(b) If k is too large, the neighborhood for points in the left cluster will include many points from the other (right) cluster and the global majority class will dominate, causing misclassification. If kkk is too small (e.g., 1), the classifier is very sensitive to noise/outliers and yields a very jagged decision boundary (overfitting).

(c) k=1 minimizes leave-one-out CV error. Each point’s nearest neighbor (with that point left out) is from its own cluster, so the LOO error is 0.

## problem 2

### Iteration 1 
- To $(c_1^{(0)}): ((3,3),(4,5),(0,1),(0,9),(8,1),(4,3))$
- To $(c_2^{(0)}): ((8,4),(10,2),(3,7),(9,4))$
Update centroids (arithmetic means):
- $(c_1^{(1)}=\big(\frac{3+4+0+0+8+4}{6},\frac{3+5+1+9+1+3}{6}\big)=(3.\overline{1},,3.\overline{6}))$
- $(c_2^{(1)}=\big(\frac{8+10+3+9}{4},\frac{4+2+7+4}{4}\big)=(7.5,,4.25))$
### Iteration 2 
- To $(c_1^{(1)}): ((3,3),(4,5),(0,1),(3,7),(0,9),(4,3))$
- To $(c_2^{(1)}): ((8,4),(10,2),(8,1),(9,4))$
Update:
- $(c_1^{(2)}=\big(\frac{3+4+0+3+0+4}{6},\frac{3+5+1+7+9+3}{6}\big)=(2.\overline{3},,4.\overline{6}))$
- $(c_2^{(2)}=\big(\frac{8+10+8+9}{4},\frac{4+2+1+4}{4}\big)=(8.75,,2.75))$

**Result after two iterations**
- Centroids: $(c_1=(2.\overline{3},,4.\overline{6})), (c_2=(8.75,,2.75))$
- Clusters:
    - $(C_1={(3,3),(4,5),(0,1),(3,7),(0,9),(4,3)})$
    - $(C_2={(8,4),(10,2),(8,1),(9,4)})$


## (b) k-NN for point ((5,3))

### i) Three closest points to ((5,3)) (Manhattan)
the three closest are **((4,3),(3,3),(4,5))**.

### ii) k-NN with (K=3)

Labels of those neighbors: **yes, yes, no** → majority **yes**.

**Prediction for ((5,3)): yes.**