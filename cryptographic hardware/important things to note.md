to resolve issues with setup time violations, reduce the frequency of the circuit
for hold time violations, add a buffer in between (to add more delay)

interpolate + add data to db later

going from a Omap and D map + learn to generate the fprint through filter
- does the seed image matter? (test this), different seed, same image
- pass the original image (fprint) as a seed, and theoretically, with the correct density map and orientation map, the final fingerprint should not change

gate equivalence: the total area divided by the size of the 2-input NAND gate used in the architecture.

most important things in AES:
- substitution boxes (S-boxes) - most important of all time, 90% responsible for the AES algorithm
- mix columns: second most important
delay of key scheduling unit should not compete with the delay inside datapath.

why pipelining? to break critical path delay
is it free? no, because you need to add registers
are registers free? no, it uses up space (area), but on some platforms, the cost is minimal.
we have to be careful in adding registers, and not over-pipeline, pipeline randomly, so that we get maximum gain from our pipelining.