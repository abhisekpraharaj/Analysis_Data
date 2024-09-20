# Understanding the Phi Meson Decay Simulation Code

This document provides an overview of the code used to simulate the decay of a phi meson into kaon particles (K+ and K-) in a heavy ion collision. The focus is on the logic behind the simulation and how the background is calculated by rotating the K- vectors.

## Logic Behind the Simulation

In high-energy collisions, the phi meson decays into K+ and K- particles, which typically move in opposite directions to conserve momentum. To analyze this process, we need to reconstruct the signal from these decay products. The code implements a method to generate a background by rotating the K- vectors by 180 degrees and summing them with the K+ vectors.

### Key Steps in the Code

1. **File and Tree Initialization**:
   - The code opens a ROOT file containing event data and retrieves a TTree object for analysis.

2. **Variable Declaration**:
   - Arrays are declared to store event data such as particle IDs, momenta (Px, Py, Pz), mass, position coordinates (XX, YY, ZZ), and other relevant quantities.

3. **Branch Address Setup**:
   - The TTree branches are linked to the declared variables for easy access during event processing.

4. **Histogram Creation**:
   - Histograms are created to store results related to the background processes.

5. **Event Loop**:
   - The main loop iterates over each event in the TTree:
     - For each particle in an event, it calculates various physical properties (energy, momentum, rapidity) and checks if they meet certain criteria.
     - K+ and K- particles are identified based on their particle ID (PID).
     - For K-, the momentum vector is rotated 180 degrees before storing it.

6. **Filling Histograms**:
   - After collecting K+ and rotated K- vectors, their combined invariant mass and transverse momentum are calculated and filled into the histogram.

7. **Output**:
   - Finally, the histogram is saved to a new ROOT file for further analysis.

## Conclusion

The provided code effectively simulates the decay of phi mesons into kaons while calculating background events through a rotational method for K- particles. This approach allows researchers to analyze particle interactions in heavy ion collisions more accurately.
