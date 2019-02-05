#ifndef   FITFUNC_H
#define   FITFUNC_H

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <cmath>

//fitting function
TF1*f1_linear(Double_t x_min,Double_t x_max){
  TF1*f = new TF1("f1_liner", "pol1(0)",x_min, x_max);
  f->SetParNames("Intercept", "Slope");
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_exp(Double_t x_min,Double_t x_max){
  TF1*f = new TF1("f1_exp", "[0]*exp(-x/[1])",x_min,x_max);
  f->SetParNames("Initial", "Half_time");
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_gaus(Double_t x_min,Double_t x_max){
  TF1*f = new TF1("f1_gaus", "gaus(0)",x_min, x_max);
  f->SetParNames("Height", "Mean", "Sigma");
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_landau(Double_t x_min,Double_t x_max){
  TF1*f = new TF1("f1_landau", "landau(0)/0.18");
  f->SetParNames("Height", "Mu", "Sigma");
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
#endif // FITFUNC_H

