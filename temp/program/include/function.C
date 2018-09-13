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
hogehoge->Fit(hogehoge,"Q","");
*/


TF1*f1_liner(){
  TF1*f = new TF1("f1_liner", "pol1(0)");
  f->SetParNames("Intercept", "Slope");
  f->SetLineColor(kRed);
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_exp(){
  TF1*f = new TF1("f1_exp", "exp(pol1(0))");
  f->SetParNames("Intercept", "Slope");
  f->SetLineColor(kRed);
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
// gausian
TF1*f1_gaus(){
  TF1*f = new TF1("f1_gaus", "gaus(0)");
  f->SetParNames("Height", "Mean", "Sigma");
  f->SetLineColor(kRed);
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
TF1*f1_landau(){
  TF1*f = new TF1("f1_landau", "landau(0)/0.18");
  f->SetParNames("Height", "Mu", "Sigma");
  f->SetLineColor(kRed);
  f->SetLineStyle(1);
  f->SetLineWidth(2);
  return f;
}
