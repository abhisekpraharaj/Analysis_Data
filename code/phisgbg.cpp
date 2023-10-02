void phisgbg(){
    TFile *f0 = TFile::Open("Au_AU_90kfile2.root");
    TTree *tr = dynamic_cast<TTree*>(f0->Get("tr"));
    
    
    const Int_t arr = 100000;
    Int_t Event;
    Int_t Mult;
    Float_t Ip;
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
    
    tr->SetBranchAddress("Event", &Event);
    tr->SetBranchAddress("Mult", &Mult);
    tr->SetBranchAddress("Imp", &Ip);
    tr->SetBranchAddress("PID",PID);
    tr->SetBranchAddress("Px",Px);
    tr->SetBranchAddress("Py",Py);
    tr->SetBranchAddress("Pz",Pz);
    tr->SetBranchAddress("Mass",Mass);
    tr->SetBranchAddress("XX",XX);
    tr->SetBranchAddress("YY",YY);
    tr->SetBranchAddress("ZZ",ZZ);
    tr->SetBranchAddress("TT",TT);
    
    //creating histograms
    TH2D * h0 = new TH2D ("hist0", "2d_histogram_of_Signal_and_Background_of_phi_meson", 90, 0.0 ,3.0, 80 ,0.98, 1.06);//0-10%

   TH2D * h1 = new TH2D ("hist1", "2d_histogram_of_Signal_and_Background_of_phi_meson", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
   TH2D * h2 = new TH2D ("hist2", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
   TH2D * h3 = new TH2D ("hist3", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
   TH2D * h4 = new TH2D ("hist4", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
   TH2D * h5 = new TH2D ("hist5", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
   TH2D * h6 = new TH2D ("hist6", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
   TH2D * h7 = new TH2D ("hist7", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);

   h0->Sumw2();
    

    
    //***********************************
    
    TLorentzVector t_kplus(0,0,0,0);
    TLorentzVector t_kminus(0,0,0,0);
    
    TLorentzVector t_V1(0,0,0,0);
    TLorentzVector t_V2(0,0,0,0);
    
    TLorentzVector t_phi(0,0,0,0);

    std::vector<TLorentzVector> vs1;
    std::vector<TLorentzVector> vs2;
    
    Double_t Pt_phi;
    Float_t Inv_m;
    Float_t cen;
    
    for(int j=0; j<tr->GetEntries();j++){
      tr->GetEntry(j);
      if(j%1000==0){
	cout<< "Working on EventNumber" << j <<endl;
    }
      
  
      
      t_kplus.SetXYZM(0,0,0,0);
      t_kminus.SetXYZM(0,0,0,0);
      
      
      for(int i=0; i<Mult; i++){
	if (Mult<5998.5){           //0%-10%
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
	  
	  // Apply the condition: absolute rapidity value is 1
	  if (fabs(RAP[i]) < 0.5){
	    
	    
	    
	    if (PID[i] == 321){
	      t_kplus.SetXYZM(Px[i],Py[i],Pz[i],0.493);
	      vs1.push_back(t_kplus);
	    }
	    
	    else if (PID[i] == -321){
	      t_kminus.SetXYZM(Px[i],Py[i],Pz[i],0.493);
	      vs2.push_back(t_kminus);
	    }
	  }
	}
      }
      for(int i =0; i<vs1.size(); i++){
	for(int k=0; k<vs2.size(); k++){
	  t_V1 = vs1.at(i);
	  t_V2 = vs2.at(k);
	  t_phi = t_V1 + t_V2;
	  Inv_m = t_phi.M();
	  Pt_phi = t_phi.Pt();
	  h0->Fill(Pt_phi,Inv_m);
	}
      }
      vs1.clear();
      vs2.clear();
      
      t_V1.SetXYZM(0,0,0,0);
      t_V2.SetXYZM(0,0,0,0);
      t_kplus.SetXYZM(0,0,0,0);
      t_kminus.SetXYZM(0,0,0,0);
    }
    TFile *f00 = new TFile("Sigbg_with_0-10%_centrality_histogram.root","RECREATE");
    h0->Write();
  
    f00->Write();
    f00->Close();
    
    
    
}

    
    
  
  
  
  
