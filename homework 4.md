1. How can Amdahl's Law be used to estimate the speedup of a machine learning algorithm when parallelizing both the convolutional and fully connected layers of a neural network?

Amdahl's law specify the "returns of investment", specifically, which parts will yield the best time saved when improved. in a neural network, every computation is highly parallel, in the fact that the same operations are performed numerous times on different parts of the input (think, a convolution layer walking over each part of the image and convolving it to produce a result). 

similarly, the fully-connected layers also perform an extremely large amount of MAC operations, which can heavily utilize the parallelism offered by these accelerators to reduce a significant chunk of time running input through these layers.

however, that isn't the entire picture in a neural network. aside from these two different layers, CNNs also has to perform activation functions, compute loss between labels and predictions, perform backpropagation and update gradients, etc. these sections are noticeably less parallelizable than the layers themselves. 

since MAC operations and convolutions comprise the bulk of the neural network, combined with the fact that they are highly improvable, it makes sense for us to search for different ways to improve that process and extract as much performance gained possible with having to sacrifice too much performance.

2. Given the two specific scenarios presented and a) and b) parts below, calculate the respective speedups applying Amdahl’s law as seen in class
*a. A machine learning algorithm takes 50 seconds to run on a single-core processor. If 20% of the algorithm cannot be parallelized, what is the maximum speedup that can be achieved using an infinite number of processing elements? Using a line chart, explain what happens if you can modify the algorithm so that more parallelization is possible.*

the formula for Amdahl's law is as follows:
$$T_{improved}=\frac{T_{affected}}{\text{improvement factor}} + T_{\text{{unaffected}}}$$
so, with a 20% parallelizability factor, we can get the $T_{affected} = 10$, and $T_{unaffected} = 50\times 80\% = 40$.

assuming that we have an infinite amount of processors, we theorize that the $affected$ portion of the program can be completed instantaneously, i.e.
$$\frac{T_{affected}}{\text{improvement factor}} = 0$$
so, the maximum speedup achievable with 20% of code being unparallelizable is: $$\frac{50}{5} =10\times$$we can get the equation:
$$T_{improved} = T_{total}\times (1-\%\text{parallizable code})$$
which gives us the line chart:
![[Pasted image 20250418113035.png]]
and speedup as follows:
![[Pasted image 20250418220133.png]]

*b. A brilliant student was able to modify the algorithm from part a) such that the parallelized portion of the algorithm now represents 95% of the total runtime. Suppose this machine learning algorithm runs on a system with 20 processors, and the parallelizable portion of the algorithm achieves a speedup of 16x.*  
*What is the overall speedup that can be achieved?*

Applying Amdahl's law:
$$T_{improved}=\frac{T_{affected}}{\text{improvement factor}} + T_{\text{{unaffected}}}$$

we get:
$$T_{improved} = \frac{50\times 0.95}{16} + 50\times 0.05=5.46875$$
 so, the final speedup is:
 $$
 \frac{50}{5.46875} = 9.142\times
$$
3. Using the information in Figures 1a, 1b, and 1c, as well as Amdahl's law, complete the following tasks:
a. *Calculate the speed-up of the memory module when each CiM circuit (B,C,D) is used as an accelerator with respect to the GPU implementation (setup A).*

the total portion that can benefit from speedup in the memory module is anything but "other", which constitutes a total of 96.5% of the memory module.

so, compared to the GPU implementation, we can yield speedups from CiMs as follows:

TCAM:
$$\text{speedup} = \frac{T}{\frac{T\times 0.965}{31.8} + 0.035\times T} = 15.303$$

Separate TCAM + GPCiM:
$$\text{speedup} = \frac{T}{\frac{T\times 0.965}{71.3} + 0.035\times T} = 20.603$$

CMA TCAM/CiM
$$\text{speedup} = \frac{T}{\frac{T\times 0.965}{31.8} + 0.035\times T} = 19.707$$

b. *Calculate the energy improvement of the memory module when each CiM circuit (B,C,D) is used as an accelerator with respect to the GPU implementation (setup A).*

supposing that Amdahl's law can estimate power efficiency similar to speedup, we can get the following power efficiency **for the memory module**:

TCAM:
$$\text{energy efficiency} = \frac{T}{\frac{T\times 0.965}{13.1} + 0.035\times T} = 9.202$$

Separate TCAM + GPCiM:
$$\text{energy efficiency} = \frac{T}{\frac{T\times 0.965}{10.8} + 0.035\times T} = 8.04$$
CMA TCAM/CiM:
$$\text{energy efficiency} = \frac{T}{\frac{T\times 0.965}{9.8} + 0.035\times T} = 7.49$$

c. *Calculate the end-to-end meta-test speed-up of the CiM-accelerated MANN with respect to the GPU implementation (setup A) when each CiM circuit (B,C,D) is used as an accelerator.*
to achieve this, we need to find that, from end-to-end, how much of the program is actually parallelizable. since memory module takes up 80% of the workload, 96.5% of which is parallelizable, we get the final number: 77.2%, which leaves 22.8% that needs to be sequential.

TCAM: 
$$\text{speedup} = \frac{T}{\frac{T\times 0.772}{31.8} + 0.228\times T} = 3.96$$

Separate TCAM + GPCiM
$$\text{speedup} = \frac{T}{\frac{T\times 0.772}{71.3} + 0.228\times T} = 4.19$$

CMA TCAM/CiM
$$\text{speedup} = \frac{T}{\frac{T\times 0.772}{61.3} + 0.228\times T} = 4.16$$

d. *Calculate the end-to-end meta-test energy improvement of the CiM-accelerated MANN with respect to the GPU implementation (setup A) when each CiM circuit (B,C,D) is used as an accelerator, assuming Amdahl's law can be used to estimate both the speedup and energy improvement.*

TCAM:
$$\text{energy efficiency} = \frac{T}{\frac{T\times 0.772}{13.1} + 0.228\times T} = 3.49$$
Separate TCAM + GPCiM
$$\text{energy efficiency} = \frac{T}{\frac{T\times 0.772}{10.8} + 0.228\times T} = 3.34$$
CMA TCAM/CiM
$$\text{energy efficiency} = \frac{T}{\frac{T\times 0.772}{9.8} + 0.228\times T} = 3.26$$
e. *Based on the meta-test end-to-end speed-up and energy improvement of the CiM designs with respect to the GPU (calculated in items c and d), as well as the accuracy of each implementation setup (shown in Figure 1c), discuss which CiM circuit option(s) are best suited for significantly accelerating MANNs with reasonable energy efficiency and without a significant accuracy drop.*

| architecture          | speedup wrt GPU | energy efficiency wrt GPU | accuracy |
| --------------------- | --------------- | ------------------------- | -------- |
| GPU                   | 1               | 1                         | 99.7     |
| TCAM                  | 3.96            | 3.49                      | 69.1     |
| Separate TCAM + GPCiM | 4.19            | 3.34                      | 95.1     |
| CMA TCAM/CiM          | 4.16            | 3.26                      | 95.1     |

plain TCAM design achieves a solid 3.96× speedup and 3.49× energy efficiency compared to the GPU, but it suffers a significant accuracy drop to 69.1%. this level of degradation is substantial and likely unacceptable for most applications involving MANNs, which rely heavily on precise memory operations.

separate TCAM + GPCiM design achieves the highest speedup (4.19×) and strong energy efficiency (3.34×), while maintaining a much higher accuracy of 95.1%. this makes it a compelling option, as it strikes a good balance between performance, energy savings, and acceptable accuracy loss.

similarly, the CMA TCAM/CiM design offers a very close speedup (4.16×) and energy efficiency (3.26×), with the same 95.1% accuracy. although its performance and energy metrics are slightly lower than separate TCAM + GPCiM, the differences are minimal. 

for the final verdict however, I would choose TCAM + GPCiM for the best tradeoff. however, the TCAM/CiM option is not too far off in terms of both metrics, yielding the same accuracy more or less.