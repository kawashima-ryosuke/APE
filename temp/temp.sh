#!/bin/bash
echo "**************************************************************"
echo "This shellscript makes a working directry for analysis."
echo "Current directry is"
pwd
curpath=`pwd`
SCRIPT_DIR=`epp_temp`
echo "**************************************************************"
read -p "Please input path and directory name: " name
#if [-n "$name"]; then
#echo "Directory name is empty"
#echo "Making tutorial directry"
#mkdir $curpath/tutorial
#mkdir $curpath/tutorial/out
#mkdir $curpath/tutorial/data
#cp -r $SCRIPT_DIR/program $curpath/tutorial/
#else
echo "Now making"
mkdir $curpath/$name
mkdir $curpath/$name/out
mkdir $curpath/$name/data
cp -r $SCRIPT_DIR/program $curpath/$name/
#fi
echo "Program finished"