#include <TFile.h>
#include <TH1F.h>
#include <TPad.h>

int test( void ) {
TFile *f = new TFile( “test.root” );
TH1F *h = (TH1F *) gDirectory->Get(“EML1A01_SegmentResidual”);
h->SetDirectory(0); // “detach” the histogram from the file
f->Close();
h->Draw();
gPad->Print(“h.png”);
return 0;
}
