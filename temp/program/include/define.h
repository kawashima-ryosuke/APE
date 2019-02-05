#ifndef   DEFINE_H
#define   DEFINE_H

#define letter_num 256
#define par_num 16
#define branch_num 32
#define ON 1
#define OFF 0
#define right_top 0
#define left_top 1
#define right_bottom 2
#define left_bottom 3

//DIRECTORY SETTING
//output_file name and mode (if you need, chage mode to ON)
Int_t output_file_mode = ON; //Set ON or OFF
char output_file_directory[letter_num] = "../out/";
//logfile name and directory(if you need, chage mode to ON)
Int_t log_file_mode = ON; //Set ON or OFF
char logfile_directory[letter_num] = "../out/";

char new_directory_name[letter_num];//Set Directory name

#endif // DEFINE_H
