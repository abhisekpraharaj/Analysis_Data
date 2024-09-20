## Projection of Signal and Background for Specific Pt Bins

In the analysis of particle collisions, it is essential to distinguish between signal and background contributions to accurately interpret the data. After obtaining 2D histograms of invariant mass versus transverse momentum (Pt) for both signal and background, projections are made for specific Pt bins. This process involves the following steps:

1. **Histogram Preparation**:
   - The 2D histograms are created from the collected data, where one axis represents the transverse momentum (Pt) and the other represents the invariant mass of the decay products.

2. **Projection**:
   - For each specified Pt bin, the histogram is projected onto the invariant mass axis. This is done by summing the counts over the range of Pt values defined by the bin limits. The resulting 1D histogram provides a clearer view of how the invariant mass distribution behaves within that particular Pt range.

3. **Subtraction for Signal Extraction**:
   - After obtaining projections for both signal and background histograms, the background projection is subtracted from the signal projection for corresponding Pt bins. This subtraction yields a clean signal representation, isolating the actual decay events from any noise or unrelated processes.

## Breit-Wigner Function Fitting

Following the extraction of signals, a fitting procedure is employed using the Breit-Wigner function. The Breit-Wigner distribution is defined as:

$$
d_{S}(E) = \frac{\Gamma}{2\pi} \frac{1}{(E - M)^2 + \left(\frac{\Gamma}{2}\right)^2}
$$


where:
- \(E\) is the energy,
- \(M\) is the mass of the resonance,
- \(\Gamma\) is the decay width.

### Importance of Fitting with Breit-Wigner

- **Resonance Characterization**: The Breit-Wigner function is crucial for characterizing resonances in particle decays, providing insights into their mass and decay properties.
  
- **Statistical Analysis**: Fitting experimental data with this function allows researchers to quantify how well their data matches theoretical predictions, facilitating a better understanding of underlying physical processes.

- **Yield Calculation**: The area under the fitted curve corresponds to the yield of events associated with that resonance, which can then be normalized for further analysis.

## Yield Calculation and Normalization

Once the signal has been extracted and fitted with a Breit-Wigner function, yield calculations are performed:

1. **Yield Extraction**:
   - The yield is determined by integrating the fitted Breit-Wigner curve over its relevant range. This integration provides a measure of how many events correspond to that particular resonance.

2. **Normalization**:
   - To ensure comparability across different datasets or experimental conditions, yields are normalized. This normalization might involve factors such as integrated luminosity or detector efficiency, allowing researchers to present results in a standardized manner.

3. **Plotting Results**:
   - Finally, normalized yields can be plotted against various parameters (e.g., Pt or centrality) to visualize trends and draw conclusions about particle production mechanisms in heavy ion collisions.

In summary, projecting signal and background distributions for specific Pt bins followed by fitting with a Breit-Wigner function allows for precise extraction and normalization of yields, contributing significantly to our understanding of particle interactions in high-energy physics.
