//for histgram
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

TH1D *histgram_setting(Double_t x_min,Double_t x_max,Double_t x_bin,char* title,char* x_title,char* y_title){
  TH1D* hist = new TH1D(title,title,x_bin,x_min,x_max);
  hist->GetXaxis()->SetTitle(x_title);
  hist->GetYaxis()->SetTitle(y_title);
  //  gStyle->SetStatY(0.9);
  //gStyle->SetStatX(0.9);

  /*
  // line
  hist1->SetLineStyle(hist_line_style);
  hist1->SetLineWidth(hist_line_width);
  // axis title
  hist1->GetXaxis()->SetTitleSize(title_char_height);
  hist1->GetYaxis()->SetTitleSize(title_char_height);
  hist1->GetXaxis()->SetTitleOffset(title_x_offset);
  hist1->GetYaxis()->SetTitleOffset(title_y_offset);
  // axis label
  hist1->GetXaxis()->SetLabelSize(label_char_height);
  hist1->GetYaxis()->SetLabelSize(label_char_height);
  hist1->GetXaxis()->SetLabelOffset(label_offset);
  hist1->GetYaxis()->SetLabelOffset(label_offset);
  // axis division
  hist1->GetXaxis()->SetNdivisions(label_divisions);
  hist1->GetYaxis()->SetNdivisions(label_divisions);
  */

  return hist;
}
