#!/bin/bash
echo "**************************************************************"
echo "This shellscript setups for APE_macro"
echo "**************************************************************"
echo "This file write alias in ~/.bashrc"
read -p "OK? [y/n]: " choice
if [ "$choice" = "y" ]; then
touch ~/.bashrc
echo '# alias setting for APE macro' >>  ~/.bashrc
echo 'alias maketmp="source /Users/ryousuke/GitHub/APE/temp/temp.sh"' >>  ~/.bashrc
echo 'alias epp_temp="echo /Users/ryousuke/GitHub/APE/temp"' >>  ~/.bashrc
echo '' >>  ~/.bashrc
echo "**************************************************************"
echo "FINIFHED !"
echo "**************************************************************"
else
echo "SELL SCRIPT IS STOPPED"
fi
