void rootfile_setting(){
  TObjArray *leaves = tree->GetListOFLeaves();
  Int_t nleavess = leaves?leasves->GetEntriesFast():0;
  for(int i=0;i<nleaves;i++){
    TLeaf *leaf = (TLeaf*)leaves->UncheckedAt(i);
    TBranch *branch = leaf->GetBranch();
  }

}
