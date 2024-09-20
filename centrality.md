# Centrality Range Analysis in Heavy-Ion Collisions

## Overview

The provided code snippet is designed to analyze the multiplicity of events in heavy-ion collisions, specifically for the Au+Au collision data. The goal is to divide the collision data into different centrality ranges based on the multiplicity counts, which are crucial for understanding the dynamics of the collision and the properties of the produced matter.

## Logic of the Code

1. **File and Tree Initialization**:
   - The code begins by opening a ROOT file containing event data and retrieves a TTree object for analysis. This TTree holds information about various event properties, including multiplicity.

2. **Multiplicity Histogram Creation**:
   - A histogram (`hMult`) is created to store multiplicity counts. The histogram is initialized with 100 bins covering a range from 0 to an unspecified upper limit (which should ideally be defined).

3. **Setting Branch Address**:
   - The branch address for multiplicity (`Mult`) is set so that its value can be accessed during event processing.

4. **Event Loop**:
   - The code iterates over all entries in the TTree, filling the histogram with multiplicity values for each event. This provides a distribution of multiplicity across all events.

5. **Centrality Calculation**:
   - The total integral of the multiplicity histogram is calculated to determine the overall number of events.
   - The code defines an array of centrality percentages (10% to 90%) and initializes an array to store corresponding multiplicity cuts.
   - For each centrality range, the code sums up the histogram bin contents until it reaches the specified percentage of the total integral. This identifies the multiplicity cut-off value for each centrality range.

6. **Output of Centrality Ranges**:
   - The code prints out the multiplicity cuts corresponding to each centrality range, allowing researchers to understand how events are categorized based on their multiplicities.

7. **Visualization**:
   - A canvas (`c1`) is created to visualize the multiplicity histogram.
   - Vertical lines are drawn on the histogram at specified multiplicity values, indicating thresholds for different centralities.
   - Finally, the histogram is saved as a PNG file for further analysis or presentation.

## Importance of Centrality Ranges

- **Understanding Collision Dynamics**: Centrality ranges provide insight into different collision regimes, from peripheral (less overlap) to central (more overlap) collisions, affecting particle production and interaction dynamics.
  
- **Data Selection**: By categorizing events into centrality ranges, researchers can focus on specific collision conditions that are relevant for studying phenomena such as quark-gluon plasma formation and hadronic interactions.

- **Comparative Studies**: Centrality-based analyses allow for comparisons between different collision systems or energies, facilitating a deeper understanding of nuclear matter under extreme conditions.

This code serves as a valuable tool in heavy-ion physics research, enabling effective categorization and analysis of collision data based on multiplicity and centrality.
