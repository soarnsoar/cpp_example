/*
  KEY: TH1Dh_dR1;1h_dR1
  KEY: TH1Dh_dR2;1h_dR2
  KEY: TH1Dh_dRboson;1h_dRboson
  KEY: TH1Dh_dPhi1;1h_dPhi1
  KEY: TH1Dh_dPhi2;1h_dPhi2
  KEY: TH1Dh_dPhiboson;1h_dPhiboson
  KEY: TH1Dh_Ephoton;1h_Ephoton
  KEY: TH1Dh_Nphoton;1h_Nphoton
  KEY: TH1Dh_dR1_fsr;1h_dR1_fsr
  KEY: TH1Dh_dR2_fsr;1h_dR2_fsr
  KEY: TH1Dh_dRboson_fsr;1h_dRboson_fsr
  KEY: TH1Dh_dPhi1_fsr;1h_dPhi1_fsr
  KEY: TH1Dh_dPhi2_fsr;1h_dPhi2_fsr
  KEY: TH1Dh_dPhiboson_fsr;1h_dPhiboson_fsr
  KEY: TH1Dh_Ephoton_fsr;1h_Ephoton_fsr
  KEY: TH1Dh_Nphoton_fsr;1h_Nphoton_fsr
  KEY: TH1Dh_dR12;1h_dR12
  KEY: TH1Dh_dPhi12;1h_dPhi12
  KEY: TH1Dh_M_boson;1h_M_boson
  KEY: TH1Dh_PT_boson;1h_PT_boson
  KEY: TH1Dh_PT_lep1;1h_PT_lep1
  KEY: TH1Dh_dRboson_lep1;1h_dRboson_lep1
  KEY: TH1Dh_PT_lep2;1h_PT_lep2
  KEY: TH1Dh_dRboson_lep2;1h_dRboson_lep2
*/


#include <iostream>
using namespace std;
class sample_info {
private:
  TString _filename;
  TString _mass, _lepton,_addvirtual,_pythiaPhoton,_showerL,_photos;
  vector<TString> _vhistoname;
  vector<int> _vcolor; 
 
  vector<TString> _vlegTL;
  vector<TString> _vlegTR;
  vector<TString> _vlegBL;
  vector<TString> _vlegBR;
  // TString _histoname;
  /*
    _vcolor.push_back(4);
  _vcolor.push_back(2);
  _vcolor.push_back(3);
  _vcolor.push_back(1);
  _vcolor.push_back(6);
  _vcolor.push_back(7);
  _vcolor.push_back(8);
  */
public:
  sample_info();
  ///Histograms for photons/////                                                                                                                               
  vector<TH1D*> vhisto;


  void Add_histo(TString _histoname_);
  //void Load_histos();
  void Clear_histos();
  void Delete_histo();
  void Draw_histos();
  void Compare_histos(TString _name_);


  void Set_mass(TString mass);
  void Set_lepton(TString lepton);
  void Set_addvirtual(TString addvirtual);
  void Set_pythiaPhoton(TString pythiaPhoton);
  void Set_showerL(TString showerL);
  void Set_photos(TString photos);

  void Add_LegendTL(TString keyword);//move legend to topleft
  void Add_LegendTR(TString keyword);//move legend to topRightdefault
  void Add_LegendBL(TString keyword);//move legend to bottmleft
  void Add_LegendBR(TString keyword);//move legend to bottomRight

  TString Get_Xname();

  void Set_filename();
  
};
void sample_info::Add_LegendTL(TString keyword){
  _vlegTL.push_back(keyword);
}
void sample_info::Add_LegendTR(TString keyword){
  _vlegTR.push_back(keyword);
}
void sample_info::Add_LegendBL(TString keyword){
  _vlegBL.push_back(keyword);
}
void sample_info::Add_LegendBR(TString keyword){
  _vlegBR.push_back(keyword);
}
sample_info::sample_info(void){
  _vcolor.push_back(4);
  _vcolor.push_back(2);
  _vcolor.push_back(6);
  _vcolor.push_back(3);
  _vcolor.push_back(1);
  _vcolor.push_back(7);
  _vcolor.push_back(8);   
}
//TString sample_info::Get_Xname(){
// return _histoname;//
//}
void sample_info::Add_histo(TString _histoname_){
  
  TFile *f = TFile::Open(_filename);
  //  TFile f(_filename);
  TH1D* h=(TH1D*)f->Get("DY/"+_histoname_);
  h->SetDirectory(0); 
  f->Close();
  vhisto.push_back(h);
 
}

void sample_info::Clear_histos(){
  
  vhisto.clear();
}
void sample_info::Delete_histo(){
 
  vhisto.pop_back();;

}

void sample_info::Set_filename(){
 
  _filename=_lepton+"_"+_mass+"_addvirtual_"+_addvirtual+"_pythiaPhoton_"+_pythiaPhoton+"_showerL_"+_showerL+"_photos_"+_photos+".root";
}
void sample_info::Set_lepton(TString lepton){
  
  _lepton=lepton;
}
void sample_info::Set_mass(TString mass){
  
  _mass=mass;
}
void sample_info::Set_addvirtual(TString addvirtual){
  
  _addvirtual=addvirtual;
}
void sample_info::Set_pythiaPhoton(TString pythiaPhoton){
  
  _pythiaPhoton=pythiaPhoton;
}
void sample_info::Set_showerL(TString showerL){
  
  _showerL=showerL;
}
void sample_info::Set_photos(TString photos){
  
  _photos=photos;
}

//void sample_info::Load_histos(){
// TFile *f = TFile::Open(_filename);
  /*
  h_dR1=f->Get("DY/h_dR1");
  h_dR2=f->Get("DY/h_dR2");
  h_dRboson=f->Get("DY/h_dRboson");

  h_dPhi1=f->Get("DY/h_dPhi1");
  h_dPhi2=f->Get("DY/h_dPhi2");
  h_dPhiboson=f->Get("DY/h_dPhiboson");

  h_Ephoton=f->Get("DY/h_Ephoton");
  h_Nphoton=f->Get("DY/h_Nphoton");

  h_dR1_fsr=f->Get("DY/h_dR1_fsr");
  h_dR2_fsr=f->Get("DY/h_dR2_fsr");
  h_dRboson_fsr=f->Get("DY/h_dRboson_fsr");

  h_dPhi1_fsr=f->Get("DY/h_dPhi1_fsr");
  h_dPhi2_fsr=f->Get("DY/h_dPhi2_fsr");
  h_dPhiboson_fsr=f->Get("DY/h_dPhiboson_fsr");

  h_Ephoton_fsr=f->Get("DY/h_Ephoton_fsr");
  h_Nphoton_fsr=f->Get("DY/h_Nphoton_fsr");

  h_dR12=f->Get("DY/h_dR12");
  h_dPhi12=f->Get("DY/h_dPhi12");

  h_M_boson=f->Get("DY/h_M_boson");
  h_PT_boson=f->Get("DY/h_PT_boson");

  h_PT_lep1=f->Get("DY/h_PT_lep1");
  h_dRboson_lep1=f->Get("DY/h_dRboson_lep1");

  h_PT_lep2=f->Get("DY/h_PT_lep2");
  h_dRboson_lep2=f->Get("DY/h_dRboson_lep2");
  */

//}

void sample_info::Draw_histos(){
  //  cout<<"Draw_histos"<<endl;
  for(int ih=0; ih<vhisto.size(); ih++){
    TCanvas *c = new TCanvas();   
    vhisto[ih]->Draw();
    TString dirname="histograms/"+_lepton+"_"+_mass+"_"+_addvirtual+"_"+_pythiaPhoton+"_"+_showerL+"_"+_photos;
    gSystem->Exec("mkdir -p "+dirname);
    c->SaveAs(dirname+"/"+vhisto[ih]->GetName()+".pdf");
    c->SaveAs(dirname+"/"+vhisto[ih]->GetName()+".png");
    
  }
}

void sample_info::Compare_histos(TString _name_){

    TCanvas *c = new TCanvas();
    double x1=0.9,y1=0.85,x2=0.45,y2=0.7;

    /*    if(_name_.Contains("h_dRboson")||_name_.Contains("h_dPhiboson")){//RrightBottom
      x1=0.9,y1=0.25,x2=0.45,y2=0.1;
    }
    if(_name_.Contains("h_dR12")){ //LeftTop
	x1=0.5,y1=0.85,x2=0.05,y2=0.7;
      }
    else if(_name_.Contains("h_dPhi12")){
      x1=0.6,y1=0.85,x2=0.15,y2=0.7;
    }
    if(_name_.Contains("Nphoton") && !_name_.Contains("fsr")){
      x1=0.7,y1=0.25,x2=0.25,y2=0.1;
    }
    */
    for(int iTL=0; iTL<_vlegTL.size(); iTL++){
      if(_name_.Contains(_vlegTL[iTL])) x1=0.5,y1=0.85,x2=0.05,y2=0.7; 
    }
    for(int iTR=0; iTR<_vlegTR.size(); iTR++){
      if(_name_.Contains(_vlegTR[iTR])) x1=0.95,y1=0.85,x2=0.5,y2=0.7;
    }
    for(int iBL=0; iBL<_vlegBL.size(); iBL++){
      if(_name_.Contains(_vlegBL[iBL])) x1=0.5,y1=0.25,x2=0.05,y2=0.1;
    }
    for(int iBR=0; iBR<_vlegBR.size(); iBR++){
      if(_name_.Contains(_vlegBR[iBR])) x1=0.95,y1=0.25,x2=0.5,y2=0.1;
    }


    //TLegend *leg = new TLegend(0.9,0.85,0.45,0.7);
    TLegend *leg = new TLegend(x1,y1,x2,y2);
   
   
    
    double max=-1;
    double min=0;
    //    if(vhisto[0]->GetMinimum() > 0) min =vhisto[0]->GetMinimum();
    for(int ih=0; ih<vhisto.size(); ih++){
      TH1D *h=(TH1D*)vhisto[ih]->Clone();
      h->Scale(1/h->Integral());
      if((h->GetMinimum() > 0)&&(ih==0)) min = h->GetMinimum();
      double max_i=h->GetMaximum();
      double min_i=h->GetMinimum();
      if(max_i>max) max=max_i;
      if((min_i<min)&&(min_i>0)) min=min_i;
    } 
    
    for(int ih=0; ih<vhisto.size(); ih++){
      TH1D *h=(TH1D*)vhisto[ih]->Clone();
      h->Sumw2();
      h->Scale(1/h->Integral());
      if(ih==0){
	h->Draw("E");
	if(_name_.Contains("Nphoton") && !_name_.Contains("fsr")){
	  h->GetXaxis()->SetRangeUser(0,500);

	}
	else if(_name_.Contains("h_PT")){
          h->GetXaxis()->SetRangeUser(0,50);

        }
	else if(_name_.Contains("h_Ephoton_fsr")){
          h->GetXaxis()->SetRangeUser(0,5);

        }
	else if(_name_.Contains("h_Nphoton_fsr")){
          h->GetXaxis()->SetRangeUser(-1,3);

        }

	else if(_name_.Contains("10to50")&&_name_.Contains("h_M_boson")){
          h->GetXaxis()->SetRangeUser(10,50);	  
	}
	else if(_name_.Contains("50plus")&&_name_.Contains("h_M_boson")){
          h->GetXaxis()->SetRangeUser(50,500);
	}
	else if(_name_.Contains("200to400")&&_name_.Contains("h_Mboson")){
          h->GetXaxis()->SetRangeUser(200,400);
	}

      }
      else h->Draw("sames E");

      if((_name_.Contains("Nphoton") && !_name_.Contains("Nphoton_fsr"))||_name_.Contains("Ephoton")){
	c->SetLogy();
	if(min==0) min=0.1;     
      }
      if(_name_.Contains("Nphoton_fsr")){
	cout<<_name_<<endl;
	cout<<"h->GetEntries()="<<h->GetMean()<<endl;
      } 
      //      else if(_name_.Contains("Ephoton")) c->SetLogy();

      
  
      h->GetYaxis()->SetRangeUser(min,max);
      //else h->GetYaxis()->SetRangeUser(0.1,max);
      //h->GetYaxis()->SetRangeUser(0.1,max);
      //cout<<"max="<<max<<endl;
      //cout<<"min"<<min<<endl;
           
      leg->TLegend::AddEntry(h,vhisto[ih]->GetName());
      h->SetLineColor(_vcolor[ih]);
      h->SetMarkerColor(_vcolor[ih]);
      // h->SetMarkerStyle(0);
      h->SetStats(0);
      
    }

    leg->Draw();
    
    c->SaveAs(_name_);
}
void draw_histo_all(){
    //h_dR1
  /*
  void Add_histo(TString _histoname_);
  void Load_histos();

  void Set_mass(TString mass);
  void Set_lepton(TString lepton);
  void Set_addvirtual(TString addvirtual);
  void Set_pythiaPhoton(TString pythiaPhoton);
  void Set_showerL(TString showerL);
  void Set_photos(TString photos);

  void Set_filename();
   */
  vector<TString> vlep; vlep.push_back("muon");vlep.push_back("electron");
  vector<TString> vmass; vmass.push_back("10to50");vmass.push_back("50plus");vmass.push_back("200to400");
  vector< vector<TString> > vsample;
  vector<TString> apsp;//addvirtual/pythiaPhoton//showerL/photos/
 
  apsp.clear(); 
  apsp.push_back("Z");
  apsp.push_back("off");
  apsp.push_back("off");
  apsp.push_back("on");
  vsample.push_back(apsp);

  apsp.clear();
  apsp.push_back("gamma");
  apsp.push_back("off");
  apsp.push_back("off");
  apsp.push_back("on");
  vsample.push_back(apsp);

  apsp.clear();
  apsp.push_back("off");
  apsp.push_back("off");
  apsp.push_back("off");
  apsp.push_back("on");
  vsample.push_back(apsp);

  apsp.clear();
  apsp.push_back("off");
  apsp.push_back("on");
  apsp.push_back("on");
  apsp.push_back("off");
  vsample.push_back(apsp);



  for(int il=0;il<vlep.size();il++){
    for(int im=0;im<vmass.size();im++){
      for(int is=0;is<vsample.size();is++){
	sample_info mysample;
	mysample.Set_lepton(vlep[il]);
	mysample.Set_mass(vmass[im]);
	mysample.Set_addvirtual(vsample[is][0]);
	mysample.Set_pythiaPhoton(vsample[is][1]);
	mysample.Set_showerL(vsample[is][2]);
	mysample.Set_photos(vsample[is][3]);      
	mysample.Set_filename();
	
	mysample.Add_histo("h_dR1");
	mysample.Add_histo("h_dR2");
	mysample.Add_histo("h_dRboson");
	mysample.Add_histo("h_dPhi1");
	mysample.Add_histo("h_dPhi2");
	mysample.Add_histo("h_dPhiboson");
	mysample.Add_histo("h_Ephoton");
	mysample.Add_histo("h_Nphoton");
	
	mysample.Add_histo("h_dR1_fsr");
	mysample.Add_histo("h_dR2_fsr");
	mysample.Add_histo("h_dRboson_fsr");
	mysample.Add_histo("h_dPhi1_fsr");
	mysample.Add_histo("h_dPhi2_fsr");
	mysample.Add_histo("h_dPhiboson_fsr");
	mysample.Add_histo("h_Ephoton_fsr");
	mysample.Add_histo("h_Nphoton_fsr");
	
	mysample.Add_histo("h_dR12");
	mysample.Add_histo("h_dPhi12");
	mysample.Add_histo("h_M_boson");
	mysample.Add_histo("h_PT_boson");
	mysample.Add_histo("h_PT_lep1");
	mysample.Add_histo("h_dRboson_lep1");
	mysample.Add_histo("h_PT_lep2");
	mysample.Add_histo("h_dRboson_lep2");
	
	
	mysample.Draw_histos();  
	mysample.Clear_histos();
      }
    }
  }
  
  
}


void draw_compare_histos(){
  vector<TString> vlep; vlep.push_back("muon");vlep.push_back("electron");
  vector<TString> vmass; vmass.push_back("10to50");vmass.push_back("50plus");vmass.push_back("200to400");


  ////
  vector<TString> vX;
  vX.push_back("h_dR1");
  vX.push_back("h_dR2");
  vX.push_back("h_dRboson");
  vX.push_back("h_dPhi1");
  vX.push_back("h_dPhi2");
  vX.push_back("h_dPhiboson");
  vX.push_back("h_Ephoton");
  vX.push_back("h_Nphoton");

  vX.push_back("h_dR1_fsr");
  vX.push_back("h_dR2_fsr");
  vX.push_back("h_dRboson_fsr");
  vX.push_back("h_dPhi1_fsr");
  vX.push_back("h_dPhi2_fsr");
  vX.push_back("h_dPhiboson_fsr");
  vX.push_back("h_Ephoton_fsr");
  vX.push_back("h_Nphoton_fsr");

  vX.push_back("h_dR12");
  vX.push_back("h_dPhi12");
  vX.push_back("h_M_boson");
  vX.push_back("h_PT_boson");
  vX.push_back("h_PT_lep1");
  vX.push_back("h_dRboson_lep1");
  vX.push_back("h_PT_lep2");
  vX.push_back("h_dRboson_lep2");

  for(int il=0; il<vlep.size(); il++){
    for(int im=0; im<vmass.size(); im++){
      for(int ix =0; ix<vX.size(); ix++){
	
	sample_info mysamples;

	//TL                                                                                                                                                                                                                                 
	mysamples.Add_LegendTL("h_dR12");
	mysamples.Add_LegendTL("h_dPhi12");

	//TR                                                                                                                    
	mysamples.Add_LegendTR("h_Nphoton_fsr");                                                                                                           
	
	//BR 
	mysamples.Add_LegendBR("h_dRboson");
	//	mysamples.Add_LegendBR("h_dRboson_fsr");
	mysamples.Add_LegendBR("h_dPhiboson");
	//	mysamples.Add_LegendBR("h_dPhiboson_fsr");
	mysamples.Add_LegendBR("h_dR1.");
	mysamples.Add_LegendBR("h_dR1_");
	mysamples.Add_LegendBR("h_dR2");
	mysamples.Add_LegendBR("h_dPhi1.");
	mysamples.Add_LegendBR("h_dPhi1_");
	mysamples.Add_LegendBR("h_dPhi2");
	mysamples.Add_LegendBR("Nphoton.");



	mysamples.Set_lepton(vlep[il]);
        mysamples.Set_mass(vmass[im]);
	mysamples.Set_addvirtual("off");
        mysamples.Set_pythiaPhoton("on");
        mysamples.Set_showerL("on");
        mysamples.Set_photos("off");
        mysamples.Set_filename();
        mysamples.Add_histo(vX[ix]);
        mysamples.vhisto[0]->SetName("PYTHIA8(default)");

       mysamples.Set_lepton(vlep[il]);
        mysamples.Set_mass(vmass[im]);
        mysamples.Set_addvirtual("Z");
        mysamples.Set_pythiaPhoton("off");
        mysamples.Set_showerL("off");
        mysamples.Set_photos("on");
        mysamples.Set_filename();   
	mysamples.Add_histo(vX[ix]);
	mysamples.vhisto[1]->SetName("PHOTOS++, add Z boson");

	mysamples.Set_lepton(vlep[il]);
        mysamples.Set_mass(vmass[im]);
        mysamples.Set_addvirtual("gamma");
        mysamples.Set_pythiaPhoton("off");
        mysamples.Set_showerL("off");
        mysamples.Set_photos("on");
        mysamples.Set_filename();
        mysamples.Add_histo(vX[ix]);
	mysamples.vhisto[2]->SetName("PHOTOS++,add gamma boson");
	
	mysamples.Set_lepton(vlep[il]);
	mysamples.Set_mass(vmass[im]);
	mysamples.Set_addvirtual("off");
	mysamples.Set_pythiaPhoton("off");
	mysamples.Set_showerL("off");
        mysamples.Set_photos("on");
        mysamples.Set_filename();
	mysamples.Add_histo(vX[ix]);
	mysamples.vhisto[3]->SetName("PHOTOS++,Not add boson");

	/*
	mysamples.Set_lepton(vlep[il]);
	mysamples.Set_mass(vmass[im]);
	mysamples.Set_addvirtual("off");
	mysamples.Set_pythiaPhoton("on");
	mysamples.Set_showerL("on");
        mysamples.Set_photos("off");
        mysamples.Set_filename();
	mysamples.Add_histo(vX[ix]);
	mysamples.vhisto[3]->SetName("PYTHIA8(default)");
	*/
	TString dirname="compare_histo/"+vlep[il]+"/"+vmass[im]+"/";
	gSystem->Exec("mkdir -p "+dirname);
	mysamples.Compare_histos(dirname+"/"+vX[ix]+".pdf");


      }            
    }
  }  


}


void draw_histo(){
  draw_compare_histos();
}
