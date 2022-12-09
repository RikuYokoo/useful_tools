# webotsR2022aとtensorflow1.14のdocker環境

## docker build

`docker build -t <tag名> -f Dockerfile.tensorflow_webots_gpu .`  
例：
`docker build -t webots_tensorflow_gpu -f Dockerfile.tensorflow_webots_gpu .`

## 実行
`run_webots.sh`の中の`docker_image`の部分を`docker build`時に指定したtag名に変更  
例の場合`docker_image="webots_tensorflow_gpu"`とする  
実行時の引数にマウントしたファイルを指定する．
GankenKun_webotsをマウントしたい場合
```
./run_webots ~/path/to/GankenKun_webots
```

## 参考
https://qiita.com/God_KonaBanana/items/c2cee09bc35cca722f2b  
https://www.linuxcapable.com/how-to-install-python-3-7-on-ubuntu-20-04-lts/  
https://qiita.com/pottava/items/452bf80e334bc1fee69a#dockerfile-%E3%83%99%E3%82%B9%E3%83%88%E3%83%97%E3%83%A9%E3%82%AF%E3%83%86%E3%82%A3%E3%82%B9  
