ファイルにコピーしたいファイルの数字を書く
cat cplist.txt | xargs printf "%06d\n" > cplist_06.txt
のコマンドで数字を0で埋める6桁にする

cpfile=`cat cplist_06.txt` ; for i in $cpfile ; do echo $i ; cp $i select_wlimg/ ; done

select_wlimgはコピー先のディレクトリ名
