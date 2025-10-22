comparison between different seeds to verify any difference (bifurcations, minutiae, etc.)
![[Pasted image 20250916213916.png]]

position of the seeds does matter for Gabor filtering. however, unable to control minutiae, because of the generation process making everything spurious. trying to reconstruct a fingerprint by explicitly filtering on the black regions do not help with controlling minutiae, despite the overall fingerprint shape being accurate. 

approach 2: moving away from fingerprint filtering using gabor filters (or using them relatively more sparingly), only at the final smoothing steps. use an approach similar to Jain-Feng, where we determine a phase field, use that phase field to induce some minutiae with spiral phase insertion => controls which kind of minutiae and direction of said minutiae.

current challenge: going from the orientation + frequency maps to the phase field. current findings:
1. very difficult to find explicit function to model the continuous phase
2. splitting a fingerprint image into many large sections will introduce blocking when being filtered, but can be somewhat mitigated with gabor filtering.

how do we go from the orientation + frequency map 

issue: going from a phase gradient to a phase itself.
- strategy 