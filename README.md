このリポジトリ内のプログラムは解析用マクロをつくるためのものです。
現在Gitのお勉強とともに工事中

このリポシトリをcloneした後にまずして欲しいこと。

1.~/.bashrc内に
	alias hogehoge='source /***/***/**/temp.sh'
　を記入しどこからでもシェルスクリプトを実行できるようにする。hogehogeのところは自由に名前をつけてください。

2.同様に~/.bashrc内に
	alias epp_temp='echo [eppのパス]/epp/temp'
　を記入し、temp.shが正常に動くようにする。epp_tempという名前は絶対に守ってください。
　
　