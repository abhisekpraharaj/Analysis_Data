# Understanding the Signal and Background Calculation for Phi Meson Decay

This document provides an overview of the code used to calculate the signal and background from the decay of a phi meson into kaon particles (K+ and K-) in a heavy ion collision. The focus is on the logic behind the simulation and how the signal is derived without rotating the K- vectors.

## Logic Behind the Simulation

In high-energy collisions, the phi meson decays into K+ and K- particles. To analyze this process, we need to reconstruct both the signal from these decay products and account for any background. The code implements a method to calculate the signal by directly summing the K+ and K- vectors without applying any rotation.

### Key Steps in the Code

1. **File and Tree Initialization**:
   - The code opens a ROOT file containing event data and retrieves a TTree object for analysis.

2. **Variable Declaration**:
   - Arrays are declared to store event data such as particle IDs, momenta (Px, Py, Pz), mass, position coordinates (XX, YY, ZZ), and other relevant quantities.

3. **Branch Address Setup**:
   - The TTree branches are linked to the declared variables for easy access during event processing.

4. **Histogram Creation**:
   - Histograms are created to store results related to both the signal and background processes.

5. **Event Loop**:
   - The main loop iterates over each event in the TTree:
     - For each particle in an event, it calculates various physical properties (energy, momentum, rapidity) and checks if they meet certain criteria.
     - K+ and K- particles are identified based on their particle ID (PID).
     - Both K+ and K- vectors are added directly without any rotation.

6. **Filling Histograms**:
   - After collecting K+ and K- vectors, their combined invariant mass and transverse momentum are calculated and filled into the histogram representing both signal and background.

7. **Output**:
   - Finally, the histogram is saved to a new ROOT file for further analysis.

## Conclusion

The provided code effectively simulates the decay of phi mesons into kaons while calculating the signal by directly summing K+ and K- vectors. This approach allows researchers to analyze particle interactions in heavy ion collisions while considering both signal and background contributions accurately.
