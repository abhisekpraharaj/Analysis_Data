# A Multi-Phase Transport (AMPT) Model
 
The AMPT model is a widely used framework for simulating heavy-ion collisions at relativistic energies. It combines several components to provide a comprehensive description of the various stages of the collision process, including initial conditions, parton evolution, hadronization, and hadronic interactions[1][3].
## Key Features of the AMPT Model
- **Initial Conditions**: The AMPT model utilizes the HIJING (Heavy Ion Jet Interaction Generator) framework to generate the initial conditions for the collision, including soft string fragmentation and hard minijets[1][3].
- **Parton Evolution**: The parton cascade component, ZPC (Zhang's Parton Cascade), simulates the interactions and dynamics of partons as they approach thermal equilibrium[1][3].
- **Hadronization**: The model employs two different approaches for hadronization: the default AMPT uses the Lund string fragmentation model, while the string melting version (AMPT-SM) utilizes a quark coalescence model[1][3].
- **Hadronic Transport**: The final stage of the collision is simulated using a hadronic transport model, such as the extended ART (A Relativistic Transport) model, which includes interactions among various hadron species until they freeze out[1][3].
## Parameters that Can Be Changed for Data Production
1. **Collision Energy**: The collision energy can be set using the `EFRM` parameter in the input file[1].
1. **Collision System**: The projectile and target nuclei can be specified using the `PROJ`, `TARG`, `IAP`, `IZP`, `IAT`, and `IZT` parameters[1].
1. **Number of Events**: The total number of events to be simulated can be set using the `NEVNT` parameter[1].
1. **Impact Parameter Range**: The minimum and maximum impact parameters can be adjusted using the `BMIN` and `BMAX` parameters[1].
1. **Lund String Fragmentation Parameters**: For the default AMPT version, the Lund string fragmentation parameters, such as `PARJ(1)`, `PARJ(2)`, and `PARJ(3)`, can be modified[1].
1. **Parton Cascade Parameters**: Parameters related to the parton cascade, such as the parton-parton cross-section and the screening mass, can be tuned[1].
1. **Quark Coalescence Parameters**: For the string melting version, parameters related to the quark coalescence model, such as the spatial and momentum coalescence criteria, can be adjusted[1].

For more detailed information on the AMPT model and its parameters, please refer to the official paper:

Z.W. Lin, C.M. Ko, B.A. Li, B. Zhang, and S. Pal, "A Multi-Phase Transport Model for Relativistic Heavy-Ion Collisions," Physical Review C, vol. 72, no. 6, p. 064901, 2005. [arXiv:nucl-th/0411110](https://arxiv.org/abs/nucl-th/0411110)
# Centrality Range Analysis in Heavy-Ion Collisions
## Overview
The provided code snippet is designed to analyze the multiplicity of events in heavy-ion collisions, specifically for the Au+Au collision data. The goal is to divide the collision data into different centrality ranges based on the multiplicity counts, which are crucial for understanding the dynamics of the collision and the properties of the produced matter.
## Logic of the Code
1. **File and Tree Initialization**:
   - The code begins by opening a ROOT file containing event data and retrieves a TTree object for analysis. This TTree holds information about various event properties, including multiplicity.
1. **Multiplicity Histogram Creation**:
   - A histogram (`hMult`) is created to store multiplicity counts. The histogram is initialized with 100 bins covering a range from 0 to an unspecified upper limit (which should ideally be defined).
1. **Setting Branch Address**:
   - The branch address for multiplicity (`Mult`) is set so that its value can be accessed during event processing.
1. **Event Loop**:
   - The code iterates over all entries in the TTree, filling the histogram with multiplicity values for each event. This provides a distribution of multiplicity across all events.
1. **Centrality Calculation**:
   - The total integral of the multiplicity histogram is calculated to determine the overall number of events.
   - The code defines an array of centrality percentages (10% to 90%) and initializes an array to store corresponding multiplicity cuts.
   - For each centrality range, the code sums up the histogram bin contents until it reaches the specified percentage of the total integral. This identifies the multiplicity cut-off value for each centrality range.
1. **Output of Centrality Ranges**:
   - The code prints out the multiplicity cuts corresponding to each centrality range, allowing researchers to understand how events are categorized based on their multiplicities.
1. **Visualization**:
   - A canvas (`c1`) is created to visualize the multiplicity histogram.
   - Vertical lines are drawn on the histogram at specified multiplicity values, indicating thresholds for different centralities.
   - Finally, the histogram is saved as a PNG file for further analysis or presentation.
## Importance of Centrality Ranges
- **Understanding Collision Dynamics**: Centrality ranges provide insight into different collision regimes, from peripheral (less overlap) to central (more overlap) collisions, affecting particle production and interaction dynamics.
- **Data Selection**: By categorizing events into centrality ranges, researchers can focus on specific collision conditions that are relevant for studying phenomena such as quark-gluon plasma formation and hadronic interactions.
- **Comparative Studies**: Centrality-based analyses allow for comparisons between different collision systems or energies, facilitating a deeper understanding of nuclear matter under extreme conditions.

This code serves as a valuable tool in heavy-ion physics research, enabling effective categorization and analysis of collision data based on multiplicity and centrality.
# Understanding the Phi Meson Decay Simulation Code
This document provides an overview of the code used to simulate the decay of a phi meson into kaon particles (K+ and K-) in a heavy ion collision. The focus is on the logic behind the simulation and how the background is calculated by rotating the K- vectors.
## Logic Behind the Simulation
In high-energy collisions, the phi meson decays into K+ and K- particles, which typically move in opposite directions to conserve momentum. To analyze this process, we need to reconstruct the signal from these decay products. The code implements a method to generate a background by rotating the K- vectors by 180 degrees and summing them with the K+ vectors.
### Key Steps in the Code
1. **File and Tree Initialization**:
   - The code opens a ROOT file containing event data and retrieves a TTree object for analysis.
1. **Variable Declaration**:
   - Arrays are declared to store event data such as particle IDs, momenta (Px, Py, Pz), mass, position coordinates (XX, YY, ZZ), and other relevant quantities.
1. **Branch Address Setup**:
   - The TTree branches are linked to the declared variables for easy access during event processing.
1. **Histogram Creation**:
   - Histograms are created to store results related to the background processes.
1. **Event Loop**:
   - The main loop iterates over each event in the TTree:
     - For each particle in an event, it calculates various physical properties (energy, momentum, rapidity) and checks if they meet certain criteria.
     - K+ and K- particles are identified based on their particle ID (PID).
     - For K-, the momentum vector is rotated 180 degrees before storing it.
1. **Filling Histograms**:
   - After collecting K+ and rotated K- vectors, their combined invariant mass and transverse momentum are calculated and filled into the histogram.
1. **Output**:
   - Finally, the histogram is saved to a new ROOT file for further analysis.
## Conclusion
The provided code effectively simulates the decay of phi mesons into kaons while calculating background events through a rotational method for K- particles. This approach allows researchers to analyze particle interactions in heavy ion collisions more accurately.
# Understanding the Signal and Background Calculation for Phi Meson Decay
This document provides an overview of the code used to calculate the signal and background from the decay of a phi meson into kaon particles (K+ and K-) in a heavy ion collision. The focus is on the logic behind the simulation and how the signal is derived without rotating the K- vectors.
## Logic Behind the Simulation
In high-energy collisions, the phi meson decays into K+ and K- particles. To analyze this process, we need to reconstruct both the signal from these decay products and account for any background. The code implements a method to calculate the signal by directly summing the K+ and K- vectors without applying any rotation.
### Key Steps in the Code
1. **File and Tree Initialization**:
   - The code opens a ROOT file containing event data and retrieves a TTree object for analysis.
1. **Variable Declaration**:
   - Arrays are declared to store event data such as particle IDs, momenta (Px, Py, Pz), mass, position coordinates (XX, YY, ZZ), and other relevant quantities.
1. **Branch Address Setup**:
   - The TTree branches are linked to the declared variables for easy access during event processing.
1. **Histogram Creation**:
   - Histograms are created to store results related to both the signal and background processes.
1. **Event Loop**:
   - The main loop iterates over each event in the TTree:
     - For each particle in an event, it calculates various physical properties (energy, momentum, rapidity) and checks if they meet certain criteria.
     - K+ and K- particles are identified based on their particle ID (PID).
     - Both K+ and K- vectors are added directly without any rotation.
1. **Filling Histograms**:
   - After collecting K+ and K- vectors, their combined invariant mass and transverse momentum are calculated and filled into the histogram representing both signal and background.
1. **Output**:
   - Finally, the histogram is saved to a new ROOT file for further analysis.
## Conclusion
The provided code effectively simulates the decay of phi mesons into kaons while calculating the signal by directly summing K+ and K- vectors. This approach allows researchers to analyze particle interactions in heavy ion collisions while considering both signal and background contributions accurately.
## Projection of Signal and Background for Specific Pt Bins
In the analysis of particle collisions, it is essential to distinguish between signal and background contributions to accurately interpret the data. After obtaining 2D histograms of invariant mass versus transverse momentum (Pt) for both signal and background, projections are made for specific Pt bins. This process involves the following steps:

1. **Histogram Preparation**:
   - The 2D histograms are created from the collected data, where one axis represents the transverse momentum (Pt) and the other represents the invariant mass of the decay products.
1. **Projection**:
   - For each specified Pt bin, the histogram is projected onto the invariant mass axis. This is done by summing the counts over the range of Pt values defined by the bin limits. The resulting 1D histogram provides a clearer view of how the invariant mass distribution behaves within that particular Pt range.
1. **Subtraction for Signal Extraction**:
   - After obtaining projections for both signal and background histograms, the background projection is subtracted from the signal projection for corresponding Pt bins. This subtraction yields a clean signal representation, isolating the actual decay events from any noise or unrelated processes.
## Breit-Wigner Function Fitting
Following the extraction of signals, a fitting procedure is employed using the Breit-Wigner function. The Breit-Wigner distribution is defined as:

$$
d\_{S}(E) = \frac{\Gamma}{2\pi} \frac{1}{(E - M)^2 + \left(\frac{\Gamma}{2}\right)^2}
$$

where:

- (E) is the energy,
- (M) is the mass of the resonance,
- (\Gamma) is the decay width.
### Importance of Fitting with Breit-Wigner
- **Resonance Characterization**: The Breit-Wigner function is crucial for characterizing resonances in particle decays, providing insights into their mass and decay properties.
- **Statistical Analysis**: Fitting experimental data with this function allows researchers to quantify how well their data matches theoretical predictions, facilitating a better understanding of underlying physical processes.
- **Yield Calculation**: The area under the fitted curve corresponds to the yield of events associated with that resonance, which can then be normalized for further analysis.
## Yield Calculation and Normalization
Once the signal has been extracted and fitted with a Breit-Wigner function, yield calculations are performed:

1. **Yield Extraction**:
   - The yield is determined by integrating the fitted Breit-Wigner curve over its relevant range. This integration provides a measure of how many events correspond to that particular resonance.
1. **Normalization**:
   - To ensure comparability across different datasets or experimental conditions, yields are normalized. This normalization might involve factors such as integrated luminosity or detector efficiency, allowing researchers to present results in a standardized manner.
1. **Plotting Results**:
   - Finally, normalized yields can be plotted against various parameters (e.g., Pt or centrality) to visualize trends and draw conclusions about particle production mechanisms in heavy ion collisions.

In summary, projecting signal and background distributions for specific Pt bins followed by fitting with a Breit-Wigner function allows for precise extraction and normalization of yields, contributing significantly to our understanding of particle interactions in high-energy physics.
