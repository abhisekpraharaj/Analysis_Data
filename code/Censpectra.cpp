void Censpectra(){
  TFile *f1 = TFile::Open("Au_AU_90kfile2.root");
  TTree *tr = dynamic_cast<TTree*>(f1->Get("tr"));

  double invariant_yield_k;
  double invariant_yield_k1;
  double invariant_yield_k2;
  double invariant_yield_k3;
  double invariant_yield_k4;
  double invariant_yield_k5;
  double invariant_yield_k6;
  double invariant_yield_k7;
  double invariant_yield_k8;



  const Int_t arr = 100000;
  Int_t Event;
  Int_t Mult;
  Float_t Imp;
  Int_t PID[arr] = {0};
  Float_t Px[arr] = {0.0};
  Float_t Py[arr] = {0.0};
  Float_t Pz[arr] = {0.0};
  Float_t Mass[arr] = {0.0};
  Float_t XX[arr] = {0.0};
  Float_t YY[arr] = {0.0};
  Float_t ZZ[arr] = {0.0};
  Float_t TT[arr] = {0.0};

  Float_t PT[arr] = {0.0};
  Float_t P[arr] = {0.0};
  Float_t PxSQ[arr] = {0.0};
  Float_t PySQ[arr] ={0.0};
  Float_t PzSQ[arr] = {0.0};
  Float_t PO[arr] = {0.0};
  Float_t MSQ = {0.0};
  Float_t PSQ = {0.0};
  Float_t RAP[arr] = {0.0};
  Float_t Eta[arr] = {0.0};

  TH1F * hMult = new TH1F("hMult", "Mult histogram",150,0,0.);

  TH1F * hip = new TH1F("hip", "Impact Parameter histogram",150,0,25);
  TH1F * h12 = new TH1F("h21", "Pt or Transverse Momentum histogram",200,0,4);
  TH1F * h13 = new TH1F("h22", "Po or Energy histogram",1000,0,100);
  TH1F * h14 = new TH1F("h23", "P or Total Momentum histogram",200,0,150);
  TH1F *h15 = new TH1F("h24", "Rapidity histogram",90,-7,7);
  TH1F *h16 = new TH1F("h25", "Pseudorapidity histogram",200,-7,7);


   //kaon histograms//0-10%Centrality   
  TH1F *hkPt = new TH1F("hkPt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 2);
  TH1F *hkpt = new TH1F("hkpt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,2);

  //kaon histograms//10-20%Centrality  
  TH1F *hk1Pt = new TH1F("hk1Pt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 2);
  TH1F *hk1pt = new TH1F("hk1pt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,2);

  
  //kaon histograms//20-30%Centrality  
  TH1F *hk2Pt = new TH1F("hk2Pt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 3);
  TH1F *hk2pt = new TH1F("hk2pt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,3);

  //kaon histograms//30-40%Centrality  
  TH1F *hk3Pt = new TH1F("hk3Pt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 2);
  TH1F *hk3pt = new TH1F("hk3pt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,2);

  //kaon histograms//40-50%Centrality  
  TH1F *hk4Pt = new TH1F("hk4Pt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 2);
  TH1F *hk4pt = new TH1F("hk4pt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,2);

  //kaon histograms//50-60%Centrality  
  TH1F *hk5Pt = new TH1F("hk5Pt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 2);
  TH1F *hk5pt = new TH1F("hk5pt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,2);

  //kaon histograms//60-70%Centrality  
  TH1F *hk6Pt = new TH1F("hk6Pt", "Spectrum of Transverse Momentum with conditions(PX and Py=0, |y| < 0.1) for Kaon", 100, 0, 2);
  TH1F *hk6pt = new TH1F("hk6pt","Histogram Spectrum of Pt vs Invariant Yield for Kaon",100,0,2);


  tr->SetBranchAddress("Event", &Event);
  tr->SetBranchAddress("Mult", &Mult);
  tr->SetBranchAddress("Imp", &Imp);
  tr->SetBranchAddress("PID",PID);
  tr->SetBranchAddress("Px",Px);
  tr->SetBranchAddress("Py",Py);
  tr->SetBranchAddress("Pz",Pz);
  tr->SetBranchAddress("Mass",Mass);
  tr->SetBranchAddress("XX",XX);
  tr->SetBranchAddress("YY",YY);
  tr->SetBranchAddress("ZZ",ZZ);
  tr->SetBranchAddress("TT",TT);
  Int_t cen;

  for(int j=0; j<tr->GetEntries();j++){
    tr->GetEntry(j);
    hMult->Fill(Mult);
    if(j%1000 ==0) cout<<"Working on the event # "<<j<<endl;
    if(Mult>5998.5) {cen =1;}
    else if(Mult>4324 && Mult<5998){cen =2;}
    else if(Mult>3115 && Mult<4324){cen =3;}
    else if(Mult>2278 && Mult<3115){cen =4;}
    else if(Mult>1534 && Mult<2278){cen =5;}
    else if(Mult>1069 && Mult<1534){cen =6;}
    else if(Mult>697 && Mult<1069){cen =7;}
    else if(Mult>511  && Mult<697){cen =8;}
    
    for(int i=0; i<Mult; i++){
      if (Mult>5998){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hkPt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }
      if (Mult>4324 && Mult<5998){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hk1Pt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }
      if (Mult>2278 && Mult<3115){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hk2Pt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }
      if (Mult>1534 && Mult<2278){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hk3Pt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }
      if (Mult>1069 && Mult<1534){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hk4Pt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }

      if (Mult>697 && Mult<106){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hk5Pt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }

      if (Mult>511  && Mult<697){
	if (Px[i] == 0 && Py[i] == 0) continue;
	Float_t PxSQ = Px[i] * Px[i]; //squared value of Px Value
	Float_t PySQ = Py[i] * Py[i]; //Squared value of py value
	Float_t PzSQ = Pz[i] * Pz[i]; //Squared value of Pz value
	Float_t PSQ = P[i] * P[i];
	Float_t MSQ = Mass[i] * Mass[i];
	
	PO[i] = std::sqrt(PSQ + MSQ); //Energy
	P[i] = std::sqrt(PxSQ + PySQ + PzSQ); //Total Momentum
	PT[i] = std::sqrt(PxSQ + PySQ); //Transverse Momentum
	
	RAP[i] = 0.5 * std::log((PO[i] + Pz[i]) / (PO[i] - Pz[i])); //Rapidity 
	Eta[i] = 0.5 * std::log((P[i] + Pz[i]) / (P[i] - Pz[i])); //PseudoRapidity
	
	// Apply the condition: absolute rapidity value is 0.1
	if (fabs(RAP[i]) < 0.1){
	  
	  //Prticle ID 321 or Kaon
	  if (PID[i] == 321){
	    //Transverse Momentum
	   
	    hk6Pt->Fill(PT[i]);// Fill the histogram with Pt values
	  }
	}
      }
    }
  }
  
  
  for (int bin = 1; bin <= hkPt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hkPt->GetBinCenter(bin);
    
      // Get the bin content (dN)
    double bin_content = hkPt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hkPt->GetBinWidth(bin);
    double bin_error = hkPt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hkpt->SetBinError(bin, binerror_k);
    hkpt->SetBinContent(bin, invariant_yield_k);
  }
  
  for (int bin = 1; bin <= hk1Pt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hk1Pt->GetBinCenter(bin);
    
    // Get the bin content (dN)
    double bin_content = hk1Pt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hk1Pt->GetBinWidth(bin);
    double bin_error = hk1Pt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k1 = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k1 = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hk1pt->SetBinError(bin, binerror_k1);
    hk1pt->SetBinContent(bin, invariant_yield_k1);
  }
    for (int bin = 1; bin <= hk2Pt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hk2Pt->GetBinCenter(bin);
    
      // Get the bin content (dN)
    double bin_content = hk2Pt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hk2Pt->GetBinWidth(bin);
    double bin_error = hk2Pt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k2 = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k2 = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hk2pt->SetBinError(bin, binerror_k2);
    hk2pt->SetBinContent(bin, invariant_yield_k2);
  }
      for (int bin = 1; bin <= hk3Pt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hk3Pt->GetBinCenter(bin);
    
      // Get the bin content (dN)
    double bin_content = hk3Pt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hk3Pt->GetBinWidth(bin);
    double bin_error = hk3Pt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k3 = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k3 = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hk3pt->SetBinError(bin, binerror_k3);
    hk3pt->SetBinContent(bin, invariant_yield_k3);
  }
    for (int bin = 1; bin <= hk4Pt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hk4Pt->GetBinCenter(bin);
    
      // Get the bin content (dN)
    double bin_content = hk4Pt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hk4Pt->GetBinWidth(bin);
    double bin_error = hk4Pt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k4 = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k4 = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hk4pt->SetBinError(bin, binerror_k4);
    hk4pt->SetBinContent(bin, invariant_yield_k4);
  }
    for (int bin = 1; bin <= hk5Pt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hk5Pt->GetBinCenter(bin);
    
      // Get the bin content (dN)
    double bin_content = hk5Pt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hk5Pt->GetBinWidth(bin);
    double bin_error = hk5Pt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k5 = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k5 = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hk5pt->SetBinError(bin, binerror_k5);
    hk5pt->SetBinContent(bin, invariant_yield_k5);
  }
      for (int bin = 1; bin <= hk6Pt->GetNbinsX(); bin++) {
    // Get the bin center
    double bin_center = hk6Pt->GetBinCenter(bin);
    
      // Get the bin content (dN)
    double bin_content = hk6Pt->GetBinContent(bin);
    
    // Get the bin width (dpt)
    double bin_width = hk6Pt->GetBinWidth(bin);
    double bin_error = hk6Pt->GetBinError(bin);
    
    
    // Calculate the invariant yield (d^2N/(dy * dpt * 2π * pt))
    invariant_yield_k6 = bin_content / (bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
    double binerror_k6 = bin_error/(bin_width * 0.2  * 2.0 * TMath::Pi() * bin_center * 9000);
      
    hk6pt->SetBinError(bin, binerror_k6);
    hk6pt->SetBinContent(bin, invariant_yield_k6);
  }

  

  
  
    TCanvas * c2 = new TCanvas();
    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9); // (x1, y1, x2, y2)
    
    // Draw each histogram with the specified marker and color
    hkpt->SetMarkerStyle(107);
    hkpt->SetMarkerColor(4);
    hkpt->GetXaxis()->SetTitle("Pt(GeV/C)");
    hkpt->GetYaxis()->SetTitle("Invariant Yield (d^{2}N/(dy * dpt * 2#pi * pt))per Event[(GeV/c)^{-2}]");
    hkpt->SetStats(0);
    
    hkpt->Draw("P");
    legend->AddEntry(hkpt, "0-10%", "p");
    TLatex* legend1 = new TLatex(0.65,0.75, "K+");
    legend1->SetTextSize(0.04);
    legend1->SetNDC();
    legend1->Draw();

    hk1pt->SetMarkerStyle(25);
    hk1pt->SetMarkerColor(3);
    hk1pt->Draw("POSAME");
    legend->AddEntry(hk1pt, "10-20%", "p");
    legend->Draw();

    hk2pt->SetMarkerStyle(26);
    hk2pt->SetMarkerColor(6);
    hk2pt->Draw("POSAME");
    legend->AddEntry(hk2pt, "20-30%", "p");
    legend->Draw();

    hk3pt->SetMarkerStyle(32);
    hk3pt->SetMarkerColor(7);
    hk3pt->Draw("POSAME");
    legend->AddEntry(hk3pt, "30-40%", "p");
    legend->Draw();

    hk4pt->SetMarkerStyle(111);
    hk4pt->SetMarkerColor(kBlack);
    hk4pt->Draw("POSAME");
    legend->AddEntry(hk4pt, "40-50%", "p");
    legend->Draw();

    hk5pt->SetMarkerStyle(30);
    hk5pt->SetMarkerColor(2);
    hk5pt->Draw("POSAME");
    legend->AddEntry(hk5pt, "50-60%", "p");
    legend->Draw();

    hk6pt->SetMarkerStyle(30);
    hk6pt->SetMarkerColor(1);
    hk6pt->Draw("POSAME");
    legend->AddEntry(hk6pt, "60-70%", "p");
    legend->Draw();

    c2->SetLogy();
    c2->SaveAs("Kaon all centrality data for Pb Pb collision of 200 gev data.jpeg");
   
}
  
