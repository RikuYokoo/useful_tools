## 実行コマンド
file=($(ls labels_back | grep txt));while [ $(ls all | grep txt | wc -w) -lt 100 ]; do rand=$((RANDOM % 304)); txt=${file[$rand]}; jpg_=`basename $txt .txt`; jpg=${jpg_}.jpg; if [ ! -e all/$txt ]; then cp labels_back/$txt all; cp labels_back/$jpg all; fi ; done

## コマンド説明
端末内でこのコマンドを入力する．
指定したファイルからランダムで指定したファイル数を移動する．
