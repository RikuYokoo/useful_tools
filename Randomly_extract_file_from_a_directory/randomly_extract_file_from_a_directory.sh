#!/bin/sh

if [ $# -eq 2 ]; then
	extract_file=$1
	output_file=${extract_file}_output
	total_num=$2
	file=($(ls ${extract_file} | grep txt))
	rand=($(ls ${extract_file} | grep txt | wc -w))
	if [ ! -d ./${output_file} ]; then
		echo "mkdir in"
		mkdir ${output_file}
	fi
	while [ $(ls ${output_file} | grep txt | wc -w) -lt $total_num ]; do
		echo while
		rand_num=$((RANDOM % $rand))
		txt_file=${file[$rand_num]}
		jpg_=`basename $txt_file .txt`
		jpg=${jpg_}.jpg
		if [ ! -e $output_file/$txt_file ]; then
			echo in
			cp $extract_file/$txt_file $output_file
			cp $extract_file/$jpg $output_file
		fi
	done
else
	echo error
fi
