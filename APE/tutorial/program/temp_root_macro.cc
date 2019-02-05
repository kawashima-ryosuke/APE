//header
//for main program
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TMath.h>
#include <TF1.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TMultiGraph.h>
//My include
#include "include/canvas_setting.C"
#include "include/histgram_setting.C"
#include "include/function.C"
/*
Version Informarion
ver 1.00 (latest,2018/9/3 kawashima)
*/

/*
This program is a templete macro for analysys.
When you use this macro, change "variables name" and set directories to save the results of this macro.
 */

Int_t main(){
  const Int_t ON = 1;
  const Int_t OFF = 0;
  const Int_t letter_num = 256;//any
  //veriables
  //output_file name and mode (if you need, chage mode to ON)
  Int_t output_file_mode = OFF; //Set ON or OFF
  char output_file_directory[letter_num] = "../out";//Set Directory of output file (if you need)
  //logfile name and directory
  Int_t log_file_mode = ON; //Set ON or OFF
  char logfile_directory[letter_num] = "../out";//Set Directory
  //canvas
  Double_t canvas_w = 500.;//canvas width 
  Double_t canvas_h = 500.;//canvas height
  //histgram
  Int_t x_min = 0.,x_max = 1000.;
  //Int_t bin_w = 10.;
  //Int_t x_bin = (x_max - x_min)/bin_w;
  Int_t x_bin = 1000;
  //trre
  Int_t wf[16][2024];
  //fit function
  //TF1 *gs = f1_gaus();
  //Double_t f_min,f_max;
  //Double_t x_bin = 100;
  char title[letter_num] = "Title";
  char x_title[letter_num] = "X Title";
  char y_title[letter_num] = "Y Title";
  //main part
  
  //tree part
  char datafile_directry[letter_num] = "../data";//Set Directory
  char tree_name[letter_num] = "tree";//Set Directory
  //analysis part
  const Int_t I_array1_number = 10;//Set name and number
  const Int_t D_array1_number = 10;//Set name and number
  Int_t I_vari1=0;//Set name
  Double_t D_vari1=0;//Set name
  Int_t I_array1[I_array1_number]={};//Set name
  Double_t D_array1[D_array1_number]={};//Set name
  //Tree
  //----- Tree -----
  cout << "Open Root File" <<endl;;
  TFile *rootfile = new TFile(Form("%s/tutorial.root", datafile_directry), "READ");
  if (rootfile -> IsZombie()){
    cout << "Error Open File" << endl;
    return 0;
  }
  cout << "Get Tree" << endl;
  TTree *tree = (TTree*)rootfile -> Get(tree_name);
  cout << "Read Branch and Fill" << endl;
  tree -> SetBranchAddress("wf", wf);
  
  //canvas
  //TCanvas *c1 = canvas_setting(width,height);
  TCanvas *c1 = canvas_setting(canvas_w,canvas_h);

  //histgram 
  //TH1D *hist = histgram_setting(x_min,x_max,x_bin,title,x_title,y_title);
  TH1D *hist = histgram_setting(x_min,x_max,x_bin,title,x_title,y_title);

  //graph
  //TGraph *gr = SetHist(x_min,x_max,title,x_title,y_title,log_scale);
  //TGraph *gr = SetGraph();

  //main part
  cout << "Start main part" <<endl;
  Int_t n = 0;
  while( n < (tree->GetEntries()) ){
      tree -> GetEntry(n);
      for(int i=0;i<1024;i++){
	hist->Fill(wf[0][i]);
      }
      n++;
    }

  //Draw hist and graph
  c1->Clear();
  c1->SetTitle(title);
  hist->Draw();
  //hist->Fit("hist",S,f_min,f_max);
  c1->Print(Form("%s/hist.pdf",output_file_directory));
  //output_file
  if(output_file_mode){
    cout << "Output_File mode ON" <<endl;
    FILE *out_file;
    const char* outputfile = Form("%s/output.dat",output_file_directory);
    cout << "Make output_file" <<endl;
    cout << "Open File" << endl;
    if((out_file=fopen(outputfile,"w"))==NULL){
      cout << "output file open Error" << endl;
      return 1;
    }
    cout << "Output File Writting" << endl;
    //**********************************************************************************************
    fprintf(out_file, "#temp_root_macro.cc Output file\n");
    fprintf(out_file, "#End of File");
    //*********************************************************************************************
    fclose(out_file);
  }
  else{cout << "Output_File mode OFF" <<endl;}

  //Taking log
  if(log_file_mode){
    cout << "Output_File mode ON" <<endl;
    FILE *log_file;
    const char* logfile = Form("%s/LOG_FILE.txt",logfile_directory);
    cout << "Make log file" <<endl;
    cout << "Open File" << endl;
    if((log_file=fopen(logfile,"w"))==NULL){
      cout << "log file open Error" << endl;
      return 1;
    }
    cout << "Log File Writting" << endl;
    //note time in the log file
    char date[letter_num];
    time_t t = time(NULL);
    strftime(date, sizeof(date), "%Y/%m/%d/ %a %H:%M:%S", localtime(&t));
    //**********************************************************************************************
    fprintf(log_file, "#%s\n",date);
    fprintf(log_file, "#temp_root_macro.cc Result\n");
    fprintf(log_file, "I_vari1 = %d\n",I_vari1);
    fprintf(log_file, "D_vari1 = %f\n",D_vari1);
    for(int i=0;i<I_array1_number;i++){
      fprintf(log_file, "I_array1[%d] = %d\n",i,I_array1[i]);
    }
    fprintf(log_file, "D_array1[%d] = {",D_array1_number);
    for(int i=0;i<D_array1_number;i++){
      fprintf(log_file, "%f ",D_array1[i]);
    }
    fprintf(log_file, "}\n");
    fprintf(log_file, "#End of File");
    //*********************************************************************************************
    fclose(log_file);
  }
    else{cout << "Output_File mode OFF" <<endl;}
    return 0;
}
