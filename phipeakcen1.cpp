void phipeakcen1()
{
  
  TFile *fx = TFile::Open("proj_sig_bg.root", "READ");
  TFile *fy = TFile::Open("proj_bg.root", "READ");

  TH1D * h1 = (TH1D*)fx->Get("Proj-y0");
  TH1D * h2 = (TH1D*)fy->Get("Proj-y0bg");

  h1->Add( h2,-1);
  h1->GetXaxis()->SetTitle("Invariant Mass");
  h1->GetYaxis()->SetTitle("Counts");

  

  TH1D * h3 = (TH1D*)fx->Get("Proj-y1");
  TH1D * h4 = (TH1D*)fy->Get("Proj-y1bg");

  h3->Add( h4,-1);
  h3->GetXaxis()->SetTitle("Invariant Mass");
  h3->GetYaxis()->SetTitle("Counts");
  
  TH1D * h5 = (TH1D*)fx->Get("Proj-y2");
  TH1D * h6 = (TH1D*)fy->Get("Proj-y2bg");

  h5->Add( h6,-1);
  h5->GetXaxis()->SetTitle("Invariant Mass");
  h5->GetYaxis()->SetTitle("Counts");

  TH1D * h7 = (TH1D*)fx->Get("Proj-y3");
  TH1D * h8 = (TH1D*)fy->Get("Proj-y3bg");

  h7->Add( h8,-1);
  h7->GetXaxis()->SetTitle("Invariant Mass");
  h7->GetYaxis()->SetTitle("Counts");
  

  TH1D * h9 = (TH1D*)fx->Get("Proj-y4");
  TH1D * h10 = (TH1D*)fy->Get("Proj-y4bg");

  h9->Add( h10,-1);
  h9->GetXaxis()->SetTitle("Invariant Mass");
  h9->GetYaxis()->SetTitle("Counts");

  TH1D * h11 = (TH1D*)fx->Get("Proj-y5");
  TH1D * h12 = (TH1D*)fy->Get("Proj-y5bg");

  h11->Add( h12,-1);
  h11->GetXaxis()->SetTitle("Invariant Mass");
  h11->GetYaxis()->SetTitle("Counts");
  
  TH1D * h13 = (TH1D*)fx->Get("Proj-y6");
  TH1D * h14 = (TH1D*)fy->Get("Proj-y6bg");
  
  h13->Add( h14,-1);
  h13->GetXaxis()->SetTitle("Invariant Mass");
  h13->GetYaxis()->SetTitle("Counts");

  TH1D * h15 = (TH1D*)fx->Get("Proj-y7");
  TH1D * h16 = (TH1D*)fy->Get("Proj-y7bg");
  
  h15->Add( h16,-1);
  h15->GetXaxis()->SetTitle("Invariant Mass");
  h15->GetYaxis()->SetTitle("Counts");


  TH1D * h17 = (TH1D*)fx->Get("Proj-y8");
  TH1D * h18 = (TH1D*)fy->Get("Proj-y8bg");
  
  h17->Add( h18,-1);
  h17->GetXaxis()->SetTitle("Invariant Mass");
  h17->GetYaxis()->SetTitle("Counts");


   

  TF1* myfit1;
  TF1* Func1;
  //ist
  myfit1 = new TF1("myfit1", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);                                                 myfit1->SetParameters(90, 0.068, 0.896, -980, 1.0);
  h1->Fit("myfit1", "R");//0.2-0.4
  Func1 = new TF1("Func1"," [0]*x + [1]", 0.6, 1.5);
  Func1->FixParameter(0, myfit1->GetParameter(3));
  Func1->FixParameter(1, myfit1->GetParameter(4));
  
  Func1->SetLineWidth(2);
  Func1->SetLineStyle(2);
  Func1->SetLineColor(1);
  Func1->Draw("SAME");
  Float_t yield1 = myfit1->GetParameter(0)/ h1->GetBinWidth(1);
  Float_t yield1error = myfit1->GetParError(0)/h1->GetBinWidth(1);

  yield1 = yield1/9300;
  yield1error = yield1error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit1->GetParameter(0)<<endl;
  cout<<myfit1->GetParError(0)<<endl;
  cout<<h1->GetBinWidth(7)<<endl;
  cout<<yield1<<endl;
  cout<<"*********************************"<<endl;
  //***************************************************************************************************************

  
  TF1* myfit2;
  TF1* Func2;
  //2nd fit
  myfit2 = new TF1("myfit2", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit2->SetParameters(90, 0.068, 0.896, -980, 1.0);
  h3->Fit("myfit2", "R");//0.4-0.6
  Func2 = new TF1("Func2"," [0]*x + [1]", 0.6, 1.5);
  Func2->FixParameter(0, myfit2->GetParameter(3));
  Func2->FixParameter(1, myfit2->GetParameter(4));
  
  Func2->SetLineWidth(2);
  Func2->SetLineStyle(2);
  Func2->SetLineColor(1);
  Func2->Draw("SAME");
  Float_t yield3 = myfit2->GetParameter(0)/ h3->GetBinWidth(2);
  Float_t yield3error = myfit2->GetParError(0)/h3->GetBinWidth(2);

  yield3 = yield3/9300;
  yield3error = yield3error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit2->GetParameter(0)<<endl;
  cout<<h3->GetBinWidth(7)<<endl;
  cout<<yield3<<endl;
  cout<<"*********************************"<<endl;
  //***************************************************************************************************************

  TF1* myfit3;
  TF1* Func3;
  //3rd fit
  myfit3 = new TF1("myfit3", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit3->SetParameters(90, 0.068, 0.896, -980, 1.0);
  h5->Fit("myfit3", "R");//0.6-0.8
  Func3 = new TF1("Func3"," [0]*x + [1]", 0.6, 1.5);
  Func3->FixParameter(0, myfit3->GetParameter(3));
  Func3->FixParameter(1, myfit3->GetParameter(4));
  Func3->SetLineWidth(2);
  Func3->SetLineStyle(2);
  Func3->SetLineColor(1);
  Func3->Draw("SAME");
  Float_t yield5 = myfit3->GetParameter(0)/ h5->GetBinWidth(3);
  Float_t yield5error = myfit3->GetParError(0)/h5->GetBinWidth(3);
   
  yield5 = yield5/9300;
  yield5error = yield5error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit3->GetParameter(0)<<endl;
  cout<<h5->GetBinWidth(7)<<endl;
  cout<<yield5<<endl;
  cout<<"*********************************"<<endl;
  //******************************************************************************************************************

  TF1* myfit4;
  TF1* Func4;
  //4th fit
  myfit4 = new TF1("myfit4", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit4->SetParameters(90, 0.048, 0.896, -980, 1.0); //area, fwhm, mass, const0 , const1
  h7->Fit("myfit4","R");//0.8-1.0
  Func4 = new TF1("Func4"," [0]*x + [1]", 0.6, 1.5);
  Func4->FixParameter(0, myfit4->GetParameter(3));
  Func4->FixParameter(1, myfit4->GetParameter(4));
  Func4->SetLineWidth(2);
  Func4->SetLineStyle(2);
  Func4->SetLineColor(1);
  Func4->Draw("SAME");
  Float_t yield7 = myfit4->GetParameter(0)/ h7->GetBinWidth(4);
  Float_t yield7error = myfit4->GetParError(0)/h7->GetBinWidth(4);
  yield7 = yield7/9300;
  yield7error = yield7error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit4->GetParameter(0)<<endl;
  cout<<h7->GetBinWidth(7)<<endl;
  cout<<yield7<<endl;
  cout<<"*********************************"<<endl;
  //*********************************************************************************************************************

  //5th fit
  TF1* myfit5;
  TF1* Func5;
  myfit5 = new TF1("myfit5", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit5->SetParameters(90, 0.048, 0.896, -980, 1.0); //area, fwhm, mass, const0 , const1
  h9->Fit("myfit5", "R");//1.0-1.2
  Func5 = new TF1("Func5"," [0]*x + [1]", 0.6, 1.5);
  Func5->FixParameter(0, myfit5->GetParameter(3));
  Func5->FixParameter(1, myfit5->GetParameter(4));
  Func5->SetLineWidth(2);
  Func5->SetLineStyle(2);
  Func5->SetLineColor(1);
  Func5->Draw("SAME");
  Float_t yield9 = myfit5->GetParameter(0)/ h9->GetBinWidth(4);
  Float_t yield9error = myfit5->GetParError(0)/h9->GetBinWidth(4);
  yield9 = yield9/9300;
  yield9error = yield9error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit5->GetParameter(0)<<endl;
  cout<<h7->GetBinWidth(7)<<endl;
  cout<<yield7<<endl;
  cout<<"*********************************"<<endl;

  //***********************************************************************************************************************

  //6th fit
  TF1* myfit6;
  TF1* Func6;
  myfit6 = new TF1("myfit6", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit6->SetParameters(90, 0.028, 0.896, -980, 1.0);
  h11->Fit("myfit6", "R");//1.2-1.4 
  Func6 = new TF1("Func6"," [0]*x + [1]", 0.6, 1.5);
  Func6->FixParameter(0, myfit6->GetParameter(3));
  Func6->FixParameter(1, myfit6->GetParameter(4));
  Func6->SetLineWidth(2);
  Func6->SetLineStyle(2);
  Func6->SetLineColor(1);
  Func6->Draw("SAME");
  Float_t yield11 = myfit6->GetParameter(0)/ h11->GetBinWidth(6);
  Float_t yield11error = myfit6->GetParError(0)/h11->GetBinWidth(6);
  yield11 = yield11/9300;
  yield11error = yield11error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit6->GetParameter(0)<<endl;
  cout<<h11->GetBinWidth(7)<<endl;
  cout<<yield11<<endl;
  cout<<"*********************************"<<endl;
  //***********************************************************************************************************************


  //7th fit
  TF1* myfit7;
  TF1* Func7;
  myfit7 = new TF1("myfit7", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit7->SetParameters(90, 0.058, 0.896, -980, 1.0);
  h13->Fit("myfit7", "R");//1.4-1.6
  Func7 = new TF1("Func7", "[0]*x + [1]" , 0.6 , 1.5 );
  Func7->FixParameter(0, myfit7->GetParameter(3));
  Func7->FixParameter(1, myfit7->GetParameter(4));
  Func7->SetLineWidth(2);
  Func7->SetLineStyle(2);
  Func7->SetLineColor(1);
  Func7->Draw("SAME");
  Float_t yield13 = myfit7->GetParameter(0)/ h13->GetBinWidth(7);
  Float_t yield13error = myfit7->GetParError(0)/h13->GetBinWidth(7);
  yield13 = yield13/9300;
  yield13error = yield13error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit7->GetParameter(0)<<endl;
  cout<<h13->GetBinWidth(7)<<endl;
  cout<<yield13<<endl;
  cout<<"*********************************"<<endl;
  //***********************************************************************************************************************

  
  //8th fit
  TF1* myfit8;
  TF1* Func8;
  myfit8 = new TF1("myfit", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit8->SetParameters(90, 0.048, 0.896, -980, 1.0);
  h15->Fit("myfit", "R");//1.6-1.8
  Func8 = new TF1("Func8"," [0]*x + [1]", 0.6, 1.5);
  Func8->FixParameter(0, myfit8->GetParameter(3));
  Func8->FixParameter(1, myfit8->GetParameter(4));
  Func8->SetLineWidth(2);
  Func8->SetLineStyle(2);
  Func8->SetLineColor(1);
  Func8->Draw("SAME");
  Float_t yield15 = myfit8->GetParameter(0)/ h15->GetBinWidth(8);
  Float_t yield15error = myfit8->GetParError(0)/h15->GetBinWidth(8);
  yield15 = yield15/9300;
  yield15error = yield15error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit8->GetParameter(0)<<endl;
  cout<<h15->GetBinWidth(7)<<endl;
  cout<<yield15<<endl;
  cout<<"*********************************"<<endl;
  //************************************************************************************************************************


  //9th fit
  TF1* myfit9;
  TF1* Func9;
  myfit9 = new TF1("myfit9", "(1.0/(2*3.14159))*(([0]*[1])/((x-[2])*(x-[2]) +([1]*[1]/4))) + [3]*x + [4]", 0.98, 1.06);
  myfit9->SetParameters(90, 0.028, 0.896, -980, 1.0);
  h17->Fit("myfit9", "R");//1.8-2.0
  Func9 = new TF1("Func9"," [0]*x + [1]", 0.6, 1.5);
  Func9->FixParameter(0, myfit9->GetParameter(3));
  Func9->FixParameter(1, myfit9->GetParameter(4));
  Func9->SetLineWidth(2);
  Func9->SetLineStyle(2);
  Func9->SetLineColor(1);
  Func9->Draw("SAME");
  Float_t yield17 = myfit9->GetParameter(0)/ h17->GetBinWidth(9);
  Float_t yield17error = myfit9->GetParError(0)/h17->GetBinWidth(9);
  yield17 = yield17/9300;
  yield17error = yield17error/9300;
  cout<<"*********************************"<<endl;
  cout<<myfit9->GetParameter(0)<<endl;
  cout<<h17->GetBinWidth(9)<<endl;
  cout<<yield17<<endl;
  cout<<"*********************************"<<endl;
  //************************************************************************************************************************
  

  

 
  // Defining a pt distribution histogram
  const Int_t nbins =9;
  double bin_edge[10] = {0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0};
 
  TH1D *hinvy = new TH1D("hinvy", "Pt vs Invariant Yield of Phi_Meson",nbins, bin_edge);

  Float_t dpt1 = hinvy->GetBinWidth(1);
  Float_t pt1 = hinvy->GetBinCenter(1);
  yield1 = yield1/(2* 1.0 *TMath::Pi() * dpt1 * pt1);
  yield1error = yield1error/ (2 * 1.0 * TMath::Pi() * dpt1 * pt1);

  cout<<"yield in 1st bin"<<"\t"<<yield1<<"\t" <<"Yield error in ist bin"<<"\t"<<yield1error<<endl;

  Float_t dpt2 = hinvy->GetBinWidth(2);
  Float_t pt2 = hinvy->GetBinCenter(2);
  yield3 = yield3/(2* 1.0 *TMath::Pi() * dpt2 * pt2);
  yield3error = yield3error/ (2 * 1.0 * TMath::Pi() * dpt2 * pt2);

  cout<<"yield in 2nd bin"<<"\t"<<yield3<<"\t" <<"Yield error in 2nd bin"<<"\t"<<yield3error<<endl;


  Float_t dpt3 = hinvy->GetBinWidth(3);
  Float_t pt3 = hinvy->GetBinCenter(3);
  yield5 = yield5/(2* 1.0 *TMath::Pi() * dpt3 * pt3);
  yield5error = yield5error/ (2 * 1.0 * TMath::Pi() * dpt3 * pt3);

  cout<<"yield in 3rd bin"<<"\t"<<yield5<<"\t" <<"Yield error in 3rd bin"<<"\t"<<yield5error<<endl;

  Float_t dpt4 = hinvy->GetBinWidth(4);
  Float_t pt4 = hinvy->GetBinCenter(4);
  yield7 = yield7/(2* 1.0 *TMath::Pi() * dpt4 * pt4);
  yield7error = yield7error/(2 * 1.0 * TMath::Pi() * dpt4 * pt4);

  cout<<"yield in 4th bin"<<"\t"<<yield7<<"\t"<<"Yield error in 4th bin"<<"\t"<<yield7error<<endl;

  Float_t dpt5 = hinvy->GetBinWidth(5);
  Float_t pt5 = hinvy->GetBinCenter(5);
  yield9 = yield9/(2* 1.0 *TMath::Pi() * dpt5 * pt5);
  yield9error = yield9error/ (2 * 1.0 * TMath::Pi() * dpt5 * pt5);

  cout<<"yield in 5th bin"<<"\t"<<yield9<<"\t" <<"Yield error in 5th bin"<<"\t"<<yield9error<<endl;
  
  Float_t dpt6 = hinvy->GetBinWidth(6);
  Float_t pt6 = hinvy->GetBinCenter(6);
  yield11 = yield11/(2* 1.0 *TMath::Pi() * dpt6 * pt6);
  yield11error = yield11error/ (2 * 1.0 * TMath::Pi() * dpt6 * pt6);

  cout<<"yield in 6th bin"<<"\t"<<yield11<<"\t"<<"Yield error in 6th bin"<<"\t"<<yield11error<<endl;

  Float_t dpt7 = hinvy->GetBinWidth(7);
  Float_t pt7 = hinvy->GetBinCenter(7);
  yield13 = yield13/(2* 1.0 *TMath::Pi() * dpt7 * pt7);
  yield13error = yield13error/ (2 * 1.0 * TMath::Pi() * dpt7 * pt7);

  cout<<"yield in 7th bin"<<"\t"<<yield13<<"\t"<<"Yield error in 7th bin"<<"\t"<<yield13error<<endl;

  Float_t dpt8 = hinvy->GetBinWidth(8);
  Float_t pt8 = hinvy->GetBinCenter(8);
  yield15 = yield15/(2* 1.0 *TMath::Pi() * dpt8 * pt8);
  yield15error = yield15error/ (2 * 1.0 * TMath::Pi() * dpt8 * pt8);
  cout<<"yield in 8th bin"<<"\t"<<yield15<<"\t"<<"Yield error in 8th bin"<<"\t"<<yield15error<<endl;

  Float_t dpt9 = hinvy->GetBinWidth(9);
  Float_t pt9 = hinvy->GetBinCenter(9);
  yield17 = yield17/(2* 1.0 *TMath::Pi() * dpt9 * pt9);
  yield17error = yield17error/ (2 * 1.0 * TMath::Pi() * dpt9 * pt9);
  cout<<"yield in 9th bin"<<"\t"<<yield17<<"\t"<<"Yield error in 9th bin"<<"\t"<<yield17error<<endl;
  



  hinvy->SetBinContent(1,yield1);
  hinvy->SetBinError(1,yield1error);
  
  
  hinvy->SetBinContent(2,yield3);
  hinvy->SetBinError(2,yield3error);
  

  
  hinvy->SetBinContent(3,yield5);
  hinvy->SetBinError(3,yield5error);

  

  
  hinvy->SetBinContent(4,yield7);
  hinvy->SetBinError(4,yield7error);
  

  
  hinvy->SetBinContent(5,yield9);
  hinvy->SetBinError(5,yield9error);
  
  
  hinvy->SetBinContent(6,yield11);
  hinvy->SetBinError(6,yield11error);
  

  
  hinvy->SetBinContent(7,yield13);
  hinvy->SetBinError(7,yield13error);

  
  hinvy->SetBinContent(8,yield15);
  hinvy->SetBinError(8,yield15error);

  hinvy->SetBinContent(9,yield17);
  hinvy->SetBinError(9,yield17error);












  
 
  TFile *fz = new TFile("phianalysis_invariant_yield.root", "RECREATE");

  TCanvas * c1 = new TCanvas("c1", "Invariant yield of phi meson with respect to Pt");

  

  hinvy->Draw();
  c1->SetLogy();
  hinvy->GetXaxis()->SetTitle("Pt");
  hinvy->GetYaxis()->SetTitle("Invariant Yield");
  hinvy->SetMarkerSize(1);
  hinvy->SetMarkerStyle(20);
  c1->SaveAs("invariant yield of phi meson.png");
  
  h1->Write();
  h3->Write();
  h5->Write();
  h7->Write();
  h9->Write();
  h11->Write();
  h13->Write();
  h15->Write();
  
  hinvy->Write();
 
  
  

   
  
	 

  fz->Write();
  fz->Close();
  
}
/*
Number of Events in Each Centrality Range:
Centrality: 0% - 10%, Sum: 9300
Centrality: 10% - 20%, Sum: 18280
Centrality: 20% - 30%, Sum: 27150
Centrality: 30% - 40%, Sum: 36050
Centrality: 40% - 50%, Sum: 45660
Centrality: 50% - 60%, Sum: 54540
Centrality: 60% - 70%, Sum: 66470
Centrality: 70% - 80%, Sum: 79470
Centrality: 80% - 90%, Sum: 90000
Multiplicity Cuts for Centrality Ranges:
0% - 10%: 5998.5
10% - 20%: 4324.5
20% - 30%: 3115.5
30% - 40%: 2278.5
40% - 50%: 1534.5
50% - 60%: 1069.5
60% - 70%: 697.5
70% - 80%: 511.5
80% - 90%: 418.5
*/
