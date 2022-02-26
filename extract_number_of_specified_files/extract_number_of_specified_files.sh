#!/bin/sh

if [ $# == 2 ]; then
	input_file=$1
	make_dir=$2
	cd $input_file
	file_num=`ls  | wc -w` #ディレクトリにあるファイル数を取得

	rand_file=`ls | sort -R` #sort -R でランダムにソートするその結果を入れる

	dir_num=$((file_num/make_dir))
	echo dirnum = $dir_num

	sleep 5
	for i in `seq 1 $dir_num` ;do
		mkdir img_$i 
	done

	num=0

	for i in $rand_file ; do
		cp $i img_$((${num}%${dir_num}+1))
		let num=num+1
	done
fi
