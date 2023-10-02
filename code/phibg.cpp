void phibg(){
  TFile *f1 = TFile::Open("Au_AU_90kfile2.root");
  TTree *tr = dynamic_cast<TTree*>(f1->Get("tr"));
  
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
    TH2D * h01 = new TH2D ("hist0bg", "histogram_og_bg_phimeson", 90, 0.0 ,3.0, 80 ,0.98, 1.06);//0-10%
  
    TH2D * h02 = new TH2D ("hist1bg", "histogram_sg_bg_phimeson", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    TH2D * h2 = new TH2D ("hist2", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    TH2D * h3 = new TH2D ("hist3", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    TH2D * h4 = new TH2D ("hist4", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    TH2D * h5 = new TH2D ("hist5", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    TH2D * h6 = new TH2D ("hist6", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    TH2D * h7 = new TH2D ("hist7", "HISTOGRAM1", 90, 0.0 ,3.0, 80 ,0.98, 1.06);
    h01->Sumw2();
    
    
    
    
    TLorentzVector t_kaonPlus(0,0,0,0);
    TLorentzVector t_kaonMinus(0,0,0,0);
    TLorentzVector v1(0,0,0,0);
    TLorentzVector v2(0,0,0,0);
    TLorentzVector t_phi(0,0,0,0);
    
    std::vector<TLorentzVector> vk1;
    std::vector<TLorentzVector> vk2;
    
    
    
    Float_t pt_phi;
    Float_t invm_phi;
    
    
    //Rotational Method
    
    for(int j=0; j<tr->GetEntries();j++){
      tr->GetEntry(j);
      if(j%1000==0)
	{
	  cout<<"Working on Event Number # "<< j<<endl;
	}
      t_kaonPlus.SetXYZM(0,0,0,0);
      t_kaonMinus.SetXYZM(0,0,0,0);
      
      
      for(int i=0; i<Mult; i++){
	if (Mult<5998.5){
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
	    if (Px[i] == 0 && Py[i] == 0) continue;
	    
	    if (PID[i] == 321){
	      t_kaonPlus.SetXYZM(Px[i],Py[i],Pz[i],0.493);
	      vk1.push_back(t_kaonPlus);
	    }
	    
	    else if (PID[i] == -321){
	      t_kaonMinus.SetXYZM(-1.0 * Px[i], -1.0 * Py[i], -1.0 * Pz[i],0.493); //Rotational Method//
	      vk2.push_back(t_kaonMinus);
	    }
	  }
	}
      }
      for(int i =0; i<vk1.size(); i++){
	for(int k=0; k<vk2.size(); k++){
	  TLorentzVector v1 = vk1.at(i);
	  TLorentzVector v2 = vk2.at(k);
	  t_phi = v1 + v2;
	  invm_phi = t_phi.M();
	  pt_phi = t_phi.Pt();
	  h01->Fill(pt_phi,invm_phi);
	
	}
      }
      vk1.clear();
      vk2.clear();
      
      v1.SetXYZM(0,0,0,0);
      v2.SetXYZM(0,0,0,0);
      t_kaonPlus.SetXYZM(0,0,0,0);
      t_kaonMinus.SetXYZM(0,0,0,0);
    }
    TFile *f01 = new TFile("Bg_with_0-10%_centrality_histogram.root","RECREATE");
    h01->Write();
  
    f01->Write();
    f01->Close();
    
    
    
    
}
