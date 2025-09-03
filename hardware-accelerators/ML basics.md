## the MP neuron
a neuron (point of computation) that sends a 0/1 signal depending on the input signal. 
### number of parameters in model
take a classical MNIST-10 number classification dataset on 28x28 images. Then, the layers we have are:
- 784 input neurons
- 15 hidden layer
- 10 outputs

then, the number of parameters can be calculated as:
$$(784\times 15 + 15) + (15 \times 10 + 10)$$
## inference: forward propagation
assume that a linear model is constructed, with 5 nodes lined up with each other. the input signal (node 0) has value $t$, and nodes 1 to 4 have outputs $o_{1-4}$ accordingly.

given that the activation function is $g(z)$, we get the signals:
- $o_{1} = g(z_{1}) = g(b_{1} + w_{1}t)$
- $o_{2} = g(z_{2}) = g(b_{2} + w_{2}o_{1})$
- and so on

## training: back propagation
speaking from a very high level standpoint, we are trying to **minimize loss (or cost)** in training, or minimize the difference that the model outputs versus the expected results.

a possible loss function can be the mean-squared-error (MSE) loss, which takes the mean of the differences of squares between model output and the expected result.

backpropagation (or gradient descent) computes this by taking derivatives. the math is nothing short of magic, but in short, it takes partial derivatives of outputs and attempts to relate them to previous nodes, and adjusting their weights and biases accordingly.
$$\frac{\delta c}{\delta b_{4}} = g'(z_{4})\times \frac{\delta c}{\delta o_{4}}$$
$$\frac{\delta c}{\delta b_{3}} = g'(z_{3})w_{4}\times g'(z_{4})\times \frac{\delta c}{\delta o_{4}}$$
## convolutional neural networks
CNNs always have a kernel that slides across the image. we call the map from input layer to hidden layer a **feature map**.

the shared weights and biases define a **kernel** or a **filter**, and a complete convolutional layer may consist of several different feature maps, which learns different features from the images.

