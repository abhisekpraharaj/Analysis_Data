void cencheck() {
  TFile *f1 = TFile::Open("Au_AU_90kfile2.root");
  TTree *tr = dynamic_cast<TTree*>(f1->Get("tr"));
  
  
  Int_t Mult;

  TH1F *hMult = new TH1F("hMult", "multiplicity counts", 100, 0, 0.);
  
  tr->SetBranchAddress("Mult", &Mult);
  
  Int_t entries = tr->GetEntries();

  for (int i = 0; i < entries; i++) {
    tr->GetEntry(i);
    hMult->Fill(Mult);
  }
  
  const int ncen = 9;
  double totalIntegral = hMult->Integral();
  cout<<totalIntegral<<endl;
  double percent[ncen] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  Int_t bNum;
  Double_t cencut[ncen] = {0.0};
  Double_t con_;
  double Sum;
  
  std::cout << "Number of Events in Each Centrality Range:" << std::endl;
  for (int i = 0; i < ncen; i++) {
    Sum = 0.0;
    for (int j = hMult->GetNbinsX(); j >= 1; j--) {
      con_ = hMult->GetBinContent(j);
      Sum += con_;
      if (Sum >= percent[i] * totalIntegral / 100) {
	bNum = j;
	cencut[i] = hMult->GetXaxis()->GetBinCenter(bNum);
	std::cout << "Centrality: " << percent[i-1] << "% - " << percent[i] << "%, Sum: " << Sum << std::endl;
	break;
      }
    }
  }
  
  std::cout << "Multiplicity Cuts for Centrality Ranges:" << std::endl;
  for (int range = 0; range < ncen; ++range) {
    std::cout << (range * 10) << "% - " << ((range + 1) * 10) << "%: " << cencut[range] << std::endl;
  }


  // Mult values for which you want to draw vertical lines
  double multValues[9] = {5998.5, 4324.5, 311.5, 2278.5, 1534.5, 1069.5, 697.5, 511.5, 418.5};

  // Create a TCanvas to draw the histogram
  TCanvas *c1 = new TCanvas("c1", "Multiplicity Histogram", 800, 600);

  // Draw the histogram
  hMult->Draw();

  // Add vertical lines at the specified mult values
  for (int i = 0; i < 9; ++i) {
    TLine *line = new TLine(multValues[i], 0, multValues[i], hMult->GetMaximum());
    line->SetLineColor(kRed); // Set line color to red
    line->Draw("same"); // Draw the line on the same canvas
  }
  c1->SaveAs("Multiplicity with respect to centrality Distribution.png");
  

}


