void projbg(){
  TFile *f01 = TFile::Open("Bg_with_0-10%_centrality_histogram.root", "READ");
  TH2D  *h01 = (TH2D*)f01->Get("hist0bg");

  h01->Sumw2();
  
  
 
  Int_t binL0 = h01->GetXaxis()->FindBin(0.2);
  Int_t binH0 = h01->GetXaxis()->FindBin(0.4);
  
  cout<<binH0<<"\t"<<binL0<<endl;
  
  Int_t binL1 = h01->GetXaxis()->FindBin(0.4);
  Int_t binH1 = h01->GetXaxis()->FindBin(0.6);
  cout<<binH1<<"\t"<<binL1<<endl;
   
  Int_t binL2 = h01->GetXaxis()->FindBin(0.6);
  Int_t binH2 = h01->GetXaxis()->FindBin(0.8);
  cout<<binH2<<"\t"<<binL2<<endl;
  
  Int_t binL3 = h01->GetXaxis()->FindBin(0.8);
  Int_t binH3 = h01->GetXaxis()->FindBin(1.0);
  cout<<binH3<<"\t"<<binL3<<endl;
    
  Int_t binL4 = h01->GetXaxis()->FindBin(1.0);
  Int_t binH4 = h01->GetXaxis()->FindBin(1.2);
  cout<<binH4<<"\t"<<binL4<<endl;

  Int_t binL5 = h01->GetXaxis()->FindBin(1.2);
  Int_t binH5 = h01->GetXaxis()->FindBin(1.4);
  cout<<binH5<<"\t"<<binL5<<endl;

  Int_t binL6 = h01->GetXaxis()->FindBin(1.4);
  Int_t binH6 = h01->GetXaxis()->FindBin(1.6);
  cout<<binH6 <<"\t"<<binL6<<endl;

  Int_t binL7 = h01->GetXaxis()->FindBin(1.6);
  Int_t binH7 = h01->GetXaxis()->FindBin(1.8);
  cout<<binH7 <<"\t"<<binL7<<endl;

  Int_t binL8 = h01->GetXaxis()->FindBin(1.8);
  Int_t binH8 = h01->GetXaxis()->FindBin(2.0);
  cout<<binH8 <<"\t"<<binL8<<endl;


   
   TFile * fy = new TFile ("proj_bg.root", "RECREATE");

   
   TH1D *proj0 = h01->ProjectionY("Proj-y0bg", binL0, binH0, "E");
   proj0->GetXaxis()->SetTitle("Invariant Mass");
   proj0->GetYaxis()->SetTitle("Counts");   
   proj0->Write();
     
   TH1D *proj1 = h01->ProjectionY("Proj-y1bg", binL1, binH1, "E");
   proj1->GetXaxis()->SetTitle("Invariant Mass");
   proj1->GetYaxis()->SetTitle("Counts");
   proj1->Write();
     
   TH1D *proj2 = h01->ProjectionY("Proj-y2bg", binL2, binH2, "E");
   proj2->GetXaxis()->SetTitle("Invariant Mass");
   proj2->GetYaxis()->SetTitle("Counts");
   proj2->Write();
   
   TH1D *proj3 = h01->ProjectionY("Proj-y3bg", binL3, binH3, "E");
   proj3->GetXaxis()->SetTitle("Invariant Mass");
   proj3->GetYaxis()->SetTitle("Counts");
   proj3->Write();
   
   TH1D *proj4 = h01->ProjectionY("Proj-y4bg", binL4, binH4, "E");
   proj4->GetXaxis()->SetTitle("Invariant Mass");
   proj4->GetYaxis()->SetTitle("Counts");
   proj4->Write();
   
   TH1D *proj5 = h01->ProjectionY("Proj-y5bg", binL5, binH5, "E");
   proj5->GetXaxis()->SetTitle("Invariant Mass");
   proj5->GetYaxis()->SetTitle("Counts");
   proj5->Write();
   
   TH1D *proj6 = h01->ProjectionY("Proj-y6bg", binL6, binH6, "E");
   proj6->GetXaxis()->SetTitle("Invariant Mass");
   proj6->GetYaxis()->SetTitle("Counts");
   proj6->Write();

   TH1D *proj7 = h01->ProjectionY("Proj-y7bg", binL7, binH7, "E");
   proj7->GetXaxis()->SetTitle("Invariant Mass");
   proj7->GetYaxis()->SetTitle("Counts");
   proj7->Write();

   TH1D *proj8 = h01->ProjectionY("Proj-y8bg", binL8, binH8, "E");
   proj8->GetXaxis()->SetTitle("Invariant Mass");
   proj8->GetYaxis()->SetTitle("Counts");
   proj8->Write();


   fy->Write();
   fy->Close();
}
   
