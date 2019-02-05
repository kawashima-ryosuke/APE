#ifndef   BRSET_H
#define   BRSET_H
#include <stdlib.h>
#include "define.h"

TTree *branch_setting(char** argv,char *rootfile_directry,char *tree_name)
{
  TFile *rootfile = new TFile(Form("%s/%s.root",rootfile_directry,argv[1]), "READ");
  cout << "> Open Root File" <<endl;
  if (rootfile -> IsZombie()){
    cout << "  + Error Open File" << endl;
    exit(1);
  }
  cout << "  + Get Tree" << endl;
  TTree *tree = (TTree*)rootfile->Get(tree_name);
  /*
  cout << "  + Read Branch and Fill" << endl;
  for(int br=0;br<branch_num;br++){
    if(tree->GetBranch(branch_name[br])){
      tree -> SetBranchAddress(branch_name[br], &branch[br]);
    }
  }
  */

  return tree;
}

#endif // BRSET_H
