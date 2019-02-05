#ifndef   DRSBASE_H
#define   DRSBASE_H
#include <stdlib.h>
#include "define.h"

Void drs4_baseline_read(char *baseline_path,Double_t *baseline)
{
  cout << "+ Baseline read" << endl;
  ifstream data1(baselina_path);
  Int_t col1,col2,col3;
  Double_t col4;
  while(!data1.eof()){
    data1 >> col1 >> col2 >> col3 >> col4;
    //ch*chip c_group c_number
    baseline[col1][col3][col2] = col4;
  }
}

#endif // DRSBASE_H
