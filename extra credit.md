1. How can Amdahl's Law be used to estimate the speedup of a machine learning algorithm when parallelizing both the convolutional and fully connected layers of a neural network?

Amdahl's law specify the "returns of investment", specifically, which parts will yield the best time saved when improved. in a neural network, every computation is highly parallel, in the fact that the same operations are performed numerous times on different parts of the input (think, a convolution layer walking over each part of the image and convolving it to produce a result). 

similarly, the fully-connected layers also perform an extremely large amount of MAC operations, which can heavily utilize the parallelism offered by these accelerators to reduce a significant chunk of time running input through these layers.

however, that isn't the entire picture in a neural network. aside from these two different layers, CNNs also has to perform activation functions, compute loss between labels and predictions, perform backpropagation and update gradients, etc. these sections are noticeably less parallelizable than the layers themselves. 

since MAC operations and convolutions comprise the bulk of the neural network, combined with the fact that they are highly improvable, it makes sense for us to search for different ways to improve that process and extract as much performance gained possible with having to sacrifice too much performance.

