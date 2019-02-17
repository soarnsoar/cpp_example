  TFile *f = TFile::Open("Canvas_nolatex.root");
  TCanvas *c1 = (TCanvas*)f->Get("Canvas");
 c1->SetCanvasSize (992,900);
 c1->ls();
 TGraphErrors *Conf_Gain_Discharge_Prob = (TGraphErrors*)c1->FindObject("Conf_Gain_Discharge_Prob");
 TGraphErrors *Gr_Gain_Discharge_Prob =	(TGraphErrors*)c1->FindObject("Gr_Gain_Discharge_Prob");
