このリポジトリ内のプログラムは解析用マクロをつくるためのものです。
現在Gitのお勉強とともに工事中

このリポシトリをcloneした後にまずして欲しいこと。
1.~/.bashrc内に
	alias hogehoge='source /***/***/**/temp.sh'
　を記入しどこからでもシェルスクリプトを実行できるようにする。

2.temp.sh内の
　SCRIPT_DIR="eppのディレクトリ/epp/temp"
　の部分を編集して、適当なものに変える。