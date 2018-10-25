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
#include "include/canvas_setting.h"
#include "include/histgram_setting.h"
#include "include/graph_setting.h"
#include "include/function.h"
#include "include/define.h"
/*
Version Informarion
ver 2.00 (latest,2018/10/25 kawashima)
*/

/*
This program is a templete macro for analysys.
When you use this macro, change "variables name" and set directories to save the results of this macro.
 */
#ifdef __CINT__
int temp_root_macro(){
#else
  int main(){
#endif
    //DIRECTORY SETTING
    //output_file name and mode (if you need, chage mode to ON)
    Int_t output_file_mode = OFF; //Set ON or OFF
    char output_file_directory[letter_num] = "../out/";
    char new_directory_name[letter_num] = "/hogehoge";//Set Directory name
    //logfile name and directory
    Int_t log_file_mode = ON; //Set ON or OFF
    char logfile_directory[letter_num] = "";
    strcpy(logfile_directory, output_file_directory);
    
    //CANVAS
    //canvas variables
    Double_t canvas_w = 1000.;//canvas width 
    Double_t canvas_h = 500.;//canvas height
    //canvas setting
    TCanvas *c1 = canvas_setting(canvas_w,canvas_h,right_top);

    //HISTGRAM
    //histgram variables
    Double_t x_min = 0.,x_max = 1000.;
    Int_t bin_w = 10.;
    Int_t x_bin = (x_max - x_min)/bin_w;
    char title[letter_num] = "title";
    char x_title[letter_num] = "x_title";
    char y_title[letter_num] = "y_title";
    //hist setting
    TH1D *hist = histgram_setting(x_min,x_max,x_bin,title,x_title,y_title);
    
    //GRAPH
    //graph setting
    TGraphErrors *gr = graph_setting(title,x_title,y_title);
    
    //FUNCTION
    //function
    char color[letter_num] = "kRed";
    TF1 *func = f1_exp(x_min,x_max,color);

    //DIRECTORY MAKING
    cout << "Make Directory" << endl;
    if(mkdir(Form("%s%s",output_file_directory,new_directory_name),0775)==0){
      cout << "Make Output file success" << endl;
    }
    else{
      cout << "CAN NOT make Output file or Already have existed" << endl;
    }
    strcat(output_file_directory,new_directory_name);
    strcat(logfile_directory,new_directory_name);

    //TTREE SET ADRESS
    char datafile_directry[letter_num] = "../data";//Set Directory
    char tree_name[letter_num] = "tr";//Set Directory
    Double_t branch1;
    cout << "Open Root File" <<endl;;
    TFile *rootfile = new TFile(Form("%s/tutorial.root", datafile_directry), "READ");
    if (rootfile -> IsZombie()){
      cout << "Error Open File" << endl;
      return 0;
    }
    cout << "Get Tree" << endl;
    TTree *tree = (TTree*)rootfile->Get(tree_name);
    cout << "Read Branch and Fill" << endl;
    tree -> SetBranchAddress("", &branch1);

    /************************************************************************
     MAIN PART OF THIS ANALYSIS
    ***************************************************************************/
    cout << "Start main part" <<endl;
    //variables of analysis part
    const Int_t I_array1_number = 10;//Set name and number
    const Int_t D_array1_number = 10;//Set name and number
    Int_t I_vari1=0;//Set name
    Double_t D_vari1=0;//Set name
    Int_t I_array1[I_array1_number]={};//Set name
    Double_t D_array1[D_array1_number]={};//Set name
    
    //MAIN ANARYLYS
    /************************************************************************
     END OF ANALYSIS
    ***************************************************************************/
    
    //Draw hist and graph
    c1->Clear();
    c1->SetTitle(title);
    hist->Draw();
    //hist->Fit("hist",S,f_min,f_max);
    c1->Print(Form("%s/hist.pdf",output_file_directory));
    
    //MAKE OUTPUT FILE
    if(output_file_mode){
      cout << "Output_File mode ON" <<endl;
      FILE *out_file;
      const char* outputfile = Form("%s/output.dat",output_file_directory);
      cout << "Make output_file" <<endl;
      cout << "Open File" << endl;
      if((out_file=fopen(outputfile,"w"))==NULL){
	cout << "File open Error" << endl;
	return 1;
      }
      cout << "Output File Writting" << endl;
      //=======================================================================
      //Contents of output file
      fprintf(out_file, "#temp_root_macro.cc Output file\n");
      fprintf(out_file, "#End of File");
      //=======================================================================
      fclose(out_file);
    }
    else{cout << "Output_File mode OFF" <<endl;}
    
    //MAKE LOGFILE
    if(log_file_mode){
      cout << "Output_File mode ON" <<endl;
      FILE *log_file;
      const char* logfile = Form("%s/LOG_FILE.txt",logfile_directory);
      cout << "Make log file" <<endl;
      cout << "Open File" << endl;
      if((log_file=fopen(logfile,"w"))==NULL){
	cout << "File open Error" << endl;
	return 1;
      }
      cout << "Log File Writting" << endl;
      //=======================================================================
      //Contents of log file
      fprintf(log_file, "#%s\n",date_function());
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
      //=======================================================================
      fclose(log_file);
    }
    else{cout << "Output_File mode OFF" <<endl;}
    cout << "PROGRAM FINISHED!!" << endl;
    return 0;
}
