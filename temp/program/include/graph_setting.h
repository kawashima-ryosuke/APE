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

TGraphErrors *grapherr_setting(char* title,char* x_title,char *y_title){
  TGraphErrors* gr = new TGraphErrors();
  Float_t size = 0.05;
  char space[2]=";";
  strcat(title,space);
  strcat(title,x_title);
  strcat(title,space);
  strcat(title,y_title);

  //SetTitle("title;x_title;y_title")
  gr -> SetTitle(title);
  gr -> SetMarkerColor(kBlack);
  gr -> SetMarkerSize(1);
  gr -> SetMarkerStyle(20);
  gStyle->SetTitleXSize(size);
  gStyle->SetTitleYSize(size);
  gStyle->SetLabelSize(size,"XY");

  return gr;
}

TGraph *graph_setting(char* title,char* x_title,char *y_title){
  TGraph* gr = new TGraphErrors();
  Float_t size = 0.05;
  char space[2]=";";
  strcat(title,space);
  strcat(title,x_title);
  strcat(title,space);
  strcat(title,y_title);

  //SetTitle("title;x_title;y_title")
  gr -> SetTitle(title);
  gr -> SetMarkerColor(kBlack);
  gr -> SetMarkerSize(1);
  gr -> SetMarkerStyle(20);
  gStyle->SetTitleXSize(size);
  gStyle->SetTitleYSize(size);
  gStyle->SetLabelSize(size,"XY");

  return gr;
}

