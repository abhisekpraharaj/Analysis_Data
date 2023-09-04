void projsgbg(){
  TFile *f0 = TFile::Open("Sigbg_with_0-10%_centrality_histogram.root", "READ");
  TH2D  *h0 = (TH2D*)f0->Get("hist0");
  h0->Sumw2();
  
  
 
  Int_t binL0 = h0->GetXaxis()->FindBin(0.2);
  Int_t binH0 = h0->GetXaxis()->FindBin(0.4);
  
  cout<<binH0<<"\t"<<binL0<<endl;
  
  Int_t binL1 = h0->GetXaxis()->FindBin(0.4);
  Int_t binH1 = h0->GetXaxis()->FindBin(0.6);
  cout<<binH1<<"\t"<<binL1<<endl;
  
   
  Int_t binL2 = h0->GetXaxis()->FindBin(0.6);
  Int_t binH2 = h0->GetXaxis()->FindBin(0.8);
  cout<<binH2<<"\t"<<binL2<<endl;
  
  Int_t binL3 = h0->GetXaxis()->FindBin(0.8);
  Int_t binH3 = h0->GetXaxis()->FindBin(1.0);
  cout<<binH3<<"\t"<<binL3<<endl;
    
  Int_t binL4 = h0->GetXaxis()->FindBin(1.0);
  Int_t binH4 = h0->GetXaxis()->FindBin(1.2);
  cout<<binH4<<"\t"<<binL4<<endl;

  Int_t binL5 = h0->GetXaxis()->FindBin(1.2);
  Int_t binH5 = h0->GetXaxis()->FindBin(1.4);
  cout<<binH5<<"\t"<<binL5<<endl;

  Int_t binL6 = h0->GetXaxis()->FindBin(1.4);
  Int_t binH6 = h0->GetXaxis()->FindBin(1.6);
  cout<<binH6 <<"\t"<<binL6<<endl;

  Int_t binL7 = h0->GetXaxis()->FindBin(1.6);
  Int_t binH7 = h0->GetXaxis()->FindBin(1.8);
  cout<<binH7 <<"\t"<<binL7<<endl;

  Int_t binL8 = h0->GetXaxis()->FindBin(1.8);
  Int_t binH8 = h0->GetXaxis()->FindBin(2.0);
  cout<<binH8 <<"\t"<<binL8<<endl;

   
   TFile * fx = new TFile ("proj_sig_bg.root", "RECREATE");

   
   TH1D *proj0 = h0->ProjectionY("Proj-y0", binL0, binH0, "E");
   proj0->GetXaxis()->SetTitle("Invariant Mass");
   proj0->GetYaxis()->SetTitle("Counts");
   proj0->Write();
     
   TH1D *proj1 = h0->ProjectionY("Proj-y1", binL1, binH1, "E");
   proj1->GetXaxis()->SetTitle("Invariant Mass");
   proj1->GetYaxis()->SetTitle("Counts");
   proj1->Write();
     
   TH1D *proj2 = h0->ProjectionY("Proj-y2", binL2, binH2, "E");
   proj2->GetXaxis()->SetTitle("Invariant Mass");
   proj2->GetYaxis()->SetTitle("Counts");
   proj2->Write();
   
   TH1D *proj3 = h0->ProjectionY("Proj-y3", binL3, binH3, "E");
   proj3->GetXaxis()->SetTitle("Invariant Mass");
   proj3->GetYaxis()->SetTitle("Counts");
   proj3->Write();
   
   TH1D *proj4 = h0->ProjectionY("Proj-y4", binL4, binH4, "E");
   proj4->GetXaxis()->SetTitle("Invariant Mass");
   proj4->GetYaxis()->SetTitle("Counts");
   proj4->Write();
   
   TH1D *proj5 = h0->ProjectionY("Proj-y5", binL5, binH5, "E");
   proj5->GetXaxis()->SetTitle("Invariant Mass");
   proj5->GetYaxis()->SetTitle("Counts");
   proj5->Write();
   
   TH1D *proj6 = h0->ProjectionY("Proj-y6", binL6, binH6, "E");
   proj6->GetXaxis()->SetTitle("Invariant Mass");
   proj6->GetYaxis()->SetTitle("Counts");
   proj6->Write();

   TH1D *proj7 = h0->ProjectionY("Proj-y7", binL7, binH7, "E");
   proj7->GetXaxis()->SetTitle("Invariant Mass");
   proj7->GetYaxis()->SetTitle("Counts");
   proj7->Write();

   TH1D *proj8 = h0->ProjectionY("Proj-y8", binL8, binH8, "E");
   proj8->GetXaxis()->SetTitle("Invariant Mass");
   proj8->GetYaxis()->SetTitle("Counts");
   proj8->Write();

   
   


   fx->Write();
   fx->Close();
}
   
