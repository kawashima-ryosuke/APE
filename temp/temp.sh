#!/bin/bash
echo "**************************************************************"
echo "This shellscript makes a working directry for analysis."
echo "Current directry is"
pwd
curpath=`pwd`
SCRIPT_DIR=`epp_temp`
echo "**************************************************************"
read -p "Please input path and directory name: " name
echo "Now making"
mkdir $curpath/$name
mkdir $curpath/$name/out
mkdir $curpath/$name/data
mkdir $curpath/$name/data/tutorial
cp -r $SCRIPT_DIR/program $curpath/$name/
cp -r $SCRIPT_DIR/tutorial.root $curpath/$name/data/tutorial/tutorial.root
#fi
echo "Program finished"