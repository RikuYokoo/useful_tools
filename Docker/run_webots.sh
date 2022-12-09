#/bin/bash 

docker_image="tensorflow_webots_check"
if [ "$#" -lt 1 ]; then 
	echo "Usage ${0} <input_file>"
	exit
fi

echo ${1}

xhost +
docker run --gpus=all -it --rm -e DISPLAY --privileged -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
				  -e QT_X11_NO_MITSHM=1 \
				  --name webots_tensorflow \
				  -v ${1}:/GankenKun_webots:rw \
				  ${docker_image} /bin/bash
#				  cyberbotics/webots:R2022a-ubuntu20.04 \
#				  /bin/bash
