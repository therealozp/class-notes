within each warp, the hardware must **wait** for the longest-running thread to accomplish. this is called **barrier synchronization**, and is very similar to control divergence when some of the threads do not run, resulting in wasted resources. 

however, when considering it on the warp level, mismatching finish times do **NOT** affect performance as much as the thread level does. this is because threads will not be able have the same start anyway, and it will always release computing resources when it is done with execution.

