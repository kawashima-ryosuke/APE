#ifndef   OUTPUTFILE_H
#define   OUTPUTFILE_H
#include "../include/define.h"

int logfile_func(char *logfile_directory){
  cout << "> LOG FILE mode ON" <<endl;
  FILE *log_file;
  const char* logfile = Form("%s/LOG_FILE.txt",logfile_directory);
  cout << "  + Make LOG_FILE.txt" <<endl;
  cout << "  + Open File" << endl;
  if((log_file=fopen(logfile,"w"))==NULL){
    cout << "  + File open Error" << endl;
    return 1;
  }
  cout << "  + LOG_FILE Writting" << endl;
  char date[letter_num];
  time_t t = time(NULL);
  strftime(date, sizeof(date), "%Y/%m/%d/ %a %H:%M:%S", localtime(&t));
  //=======================================================================
  //Contents of log file
  fprintf(log_file, "#%s\n",date);
  fprintf(log_file, "#End of File");
  //=======================================================================
  fclose(log_file);
  return 0;
}

#endif // OUTPUTFILE_H
