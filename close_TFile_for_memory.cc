
  TFile *f = TFile::Open(_filename);
  //  TFile f(_filename);
  TH1D* h=(TH1D*)f->Get("DY/"+_histoname_);
  h->SetDirectory(0); 
  f->Close();
  vhisto.push_back(h);
 
