void bgsgdraw(){
    TFile *fx = TFile::Open("proj_sig_bg.root", "READ");
  TFile *fy = TFile::Open("proj_bg.root", "READ");

  TH1D * h1 = (TH1D*)fx->Get("Proj-y0");
  TH1D * h2 = (TH1D*)fy->Get("Proj-y0bg");

  TH1D * h3 = (TH1D*)fx->Get("Proj-y1");
  TH1D * h4 = (TH1D*)fy->Get("Proj-y1bg");
 
  TH1D * h5 = (TH1D*)fx->Get("Proj-y2");
  TH1D * h6 = (TH1D*)fy->Get("Proj-y2bg");

  TH1D * h7 = (TH1D*)fx->Get("Proj-y3");
  TH1D * h8 = (TH1D*)fy->Get("Proj-y3bg");

  TH1D * h9 = (TH1D*)fx->Get("Proj-y4");
  TH1D * h10 = (TH1D*)fy->Get("Proj-y4bg");
 
  TH1D * h11 = (TH1D*)fx->Get("Proj-y5");
  TH1D * h12 = (TH1D*)fy->Get("Proj-y5bg");
  
  TH1D * h13 = (TH1D*)fx->Get("Proj-y6");
  TH1D * h14 = (TH1D*)fy->Get("Proj-y6bg");

  TCanvas *c1 = new TCanvas("c1", "signal and background data of phi meson using invariant mass method", 1600,1000);

  c1->Divide(3,3,0,0);
  gStyle->SetOptStat(0);

  c1->cd(1);
  h1->GetXaxis()->SetTitle("Invariant Mass");
  h1->GetYaxis()->SetTitle("Counts");
  h1->SetLineColor(1);
  h1->SetMarkerColor(1);
  h1->SetMarkerStyle(20);
  h1->Draw();
  
  h2->Draw("SAME");
  h2->GetXaxis()->SetTitle("Invariant Mass");
  h2->GetYaxis()->SetTitle("Counts");
  h1->SetLineColor(2);  
  h2->SetMarkerColor(2);
  h2->SetMarkerStyle(20);


  c1->cd(2);
  h3->Draw();
  h3->GetXaxis()->SetTitle("Invariant Mass");
  h3->GetYaxis()->SetTitle("Counts");
  h3->SetMarkerColor(1);
  h3->SetMarkerStyle(20);
    
  h4->Draw("SAME");
  h4->GetXaxis()->SetTitle("Invariant Mass");
  h4->GetYaxis()->SetTitle("Counts");
  h4->SetMarkerColor(2);
  h4->SetMarkerStyle(20);

  c1->cd(3);
  h5->Draw();
  h5->GetXaxis()->SetTitle("Invariant Mass");
  h5->GetYaxis()->SetTitle("Counts");
  h5->SetMarkerColor(1);
  h5->SetMarkerStyle(20);
    
  h6->Draw("SAME");
  h6->GetXaxis()->SetTitle("Invariant Mass");
  h6->GetYaxis()->SetTitle("Counts");
  h6->SetMarkerColor(2);
  h6->SetMarkerStyle(20);

  c1->cd(4);
  h7->Draw();
  h7->GetXaxis()->SetTitle("Invariant Mass");
  h7->GetYaxis()->SetTitle("Counts");
  h7->SetMarkerColor(1);
  h7->SetMarkerStyle(20);
    
  h8->Draw("SAME");
  h8->GetXaxis()->SetTitle("Invariant Mass");
  h8->GetYaxis()->SetTitle("Counts");
  h8->SetMarkerColor(2);
  h8->SetMarkerStyle(20);


  c1->cd(5);
  h9->Draw();
  h9->GetXaxis()->SetTitle("Invariant Mass");
  h9->GetYaxis()->SetTitle("Counts");
  h9->SetMarkerColor(1);
  h9->SetMarkerStyle(20);
    
  h10->Draw("SAME");
  h10->GetXaxis()->SetTitle("Invariant Mass");
  h10->GetYaxis()->SetTitle("Counts");
  h10->SetMarkerColor(2);
  h10->SetMarkerStyle(20);

  c1->cd(6);
  h11->Draw();
  h11->GetXaxis()->SetTitle("Invariant Mass");
  h11->GetYaxis()->SetTitle("Counts");
  h11->SetMarkerColor(1);
  h11->SetMarkerStyle(20);
    
  h12->Draw("SAME");
  h12->GetXaxis()->SetTitle("Invariant Mass");
  h12->GetYaxis()->SetTitle("Counts");
  h12->SetMarkerColor(2);
  h12->SetMarkerStyle(20);

  c1->cd(7);
  h13->Draw();
  h13->GetXaxis()->SetTitle("Invariant Mass");
  h13->GetYaxis()->SetTitle("Counts");
  h13->SetMarkerColor(1);
  h13->SetMarkerStyle(20);
    
  h14->Draw("SAME");
  h14->GetXaxis()->SetTitle("Invariant Mass");
  h14->GetYaxis()->SetTitle("Counts");
  h14->SetMarkerColor(2);
  h14->SetMarkerStyle(20);

  
}


  
  
 
