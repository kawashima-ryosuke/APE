//for canvas
#include <TStyle.h>
#include <TFile.h>
#include <TTree.h>
#include <TMath.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TText.h>
#include <TLegend.h>
#include <TPaletteAxis.h>
#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
#include <TPaveText.h>
#include <TPaveStats.h>

TCanvas *canvas_setting(Double_t c1_w, Double_t c1_h, Int_t position){
  //canvas parameter
  //const Int_t    c1_w = 700; // canvas width
  //const Int_t    c1_h = 500; // canvas height
  const Int_t    c1_mw =  2; // width margin ( canvas size is contain toolbar height & flame width )
  const Int_t    c1_mh = 28; // height margin
  const Double_t pad_margin_top    = 0.132;
  const Double_t pad_margin_bottom = 0.148;
  const Double_t pad_margin_left   = 0.100;
  const Double_t pad_margin_right  = pad_margin_left;
  //const Double_t pad_margin_square_left  = (1.-(1.-pad_margin_top-pad_margin_bottom)*(c1_h/c1_w)/2.;
  //const Double_t pad_margin_square_right = pad_margin_square_left;
   
  gStyle->SetPadTopMargin(     pad_margin_top     );
  gStyle->SetPadBottomMargin(  pad_margin_bottom  );
  gStyle->SetPadLeftMargin(    pad_margin_left    );
  gStyle->SetPadRightMargin(   pad_margin_right   );

  TCanvas *c1 = new TCanvas("c1", "c1", c1_w + c1_mw, c1_h + c1_mh);
  c1->SetGrid();
  gStyle->SetOptStat(110); // print entries & mean
  gStyle->SetOptFit (111); // print parameter & error & Chi^2
  //gStyle->SetStatFontSize(legend_char_height);
  if(position == 0){
    //right side
    gStyle->SetStatX(1.0-pad_margin_right+0.03);
    gStyle->SetStatY(1.0-pad_margin_top  +0.03);
  }
  if(position == 1){
    //left side
    gStyle->SetStatX(0.5);
    gStyle->SetStatY(1.0 - pad_margin_top +0.03);
  }
  TGaxis::SetMaxDigits(4);

  return c1;
}