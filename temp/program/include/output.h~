#ifndef   LOGFILE_H
#define   LOGFILE_H
#include "../include/define.h"

int output_func(Double_t *fit_par,Double_t *fit_par_err,char *output_file_directory)
{
  cout << "> Output_File mode ON" << endl;
  FILE *out_file;
  const char* outputfile = Form("%s/output.dat",output_file_directory);
  cout << "  + Make output_file" <<endl;
  cout << "  + Open File" << endl;
  if((out_file=fopen(outputfile,"w"))==NULL){
    cout << "  + File open Error" << endl;
    return 1;
  }
  cout << "  + Output File Writting" << endl;
  //=======================================================================
  //Contents of output file
  fprintf(out_file, "#temp_root_macro.cc Output file\n");
  for(int i=0;i<par_num;i++){
    if(fit_par[i] != 0.){
      fprintf(out_file, "%d %f %f\n",i,fit_par[i],fit_par_err[i]);
    }
  }
  fprintf(out_file, "#End of File");
  //=======================================================================
  fclose(out_file);
  return 0;
}

#endif // LOGFILE_H
