/*
--------------Definition of fitting function-----------
updated 2018/02/14 by kawashima
---------------------how to use ------------------
write following statement in your main proggram.(example is gaus fitting)
hogehoge is function name. Don't use same name.

TF1 *hogehoge = f1_gaus();
hogehoge->SetParameter("Height", Height_value);
hogehoge->SetParameter("Mean"  , Mean_value  );
hogehoge->SetParameter("Sigma" , Sigma_value );
hist->Fit(hogehoge,"Q","");
*/
Int_t color_function(char *color){
  Int_t col_num = 1;
  
  if(color == "kRed"){
    col_num = 632;
  }
  else if(color == "kBlue"){
    col_num = 600;
  }
  else if(color == "kYellow"){
    col_num = 400;
  }
  else if(color == "kMagenta"){
    col_num = 616;
  }
  else if(color == "kCyan"){
    col_num = 432;
  }
  else if(color == "kViolet"){
    col_num = 880;
  }
  else{
    col_num = 1;
  }
  return col_num;
}

TF1*f1_linear(Double_t x_min,Double_t x_max,char *color){
  TF1*f = new TF1("f1_liner", "pol1(0)",x_min, x_max);
  f->SetParNames("Intercept", "Slope");
  f->SetLineColor(color_function(color));
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_exp(Double_t x_min,Double_t x_max,char *color){
  TF1*f = new TF1("f1_exp", "[0]*exp(-x/[1])",x_min,x_max);
  f->SetParNames("Initial", "Half_time");
  f->SetLineColor(color_function(color));
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
// gausian
TF1*f1_gaus(Double_t x_min,Double_t x_max,char *color){
  TF1*f = new TF1("f1_gaus", "gaus(0)",x_min, x_max);
  f->SetParNames("Height", "Mean", "Sigma");
  f->SetLineColor(color_function(color));
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_landau(Double_t x_min,Double_t x_max,char *color){
  TF1*f = new TF1("f1_landau", "landau(0)/0.18");
  f->SetParNames("Height", "Mu", "Sigma");
  f->SetLineColor(color_function(color));
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}


