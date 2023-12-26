
xhost +

#XAUTH=/tmp/.docker.xauth
#if [ ! -f $XAUTH ]; then
#	xauth_list=$(xauth nlist :0 | sed -e 's/^..../ffff/')
#	if [ ! -z "$xauth_list" ]; then
#		echo $xauth_list | xauth -f $XAUTH nmerge -
#	else
#		touch $XAUTH
#	fi
#		chmod a+r $XAUTH
#fi

docker run --runtime=nvidia --gpus=all  -it --rm --privileged \
    	   -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
                -v /dev:/dev:rw \
		   --env="QT_X11_NO_MITSHM=1" \
		   --name=ros2_realsense \
		   riku/ros2:huble-realsense \
		   bash
		   echo "done"

#default
#docker run --gpus=all  -it --privileged \
#    	   -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix:rw \
#		   --env="QT_X11_NO_MITSHM=1" \
#		   --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
#		   --env="XAUTHORITY=$XAUTH" \
#		   --volume="$XAUTH:$XAUTH" \
#		   --runtime=nvidia \
#		   --name=ros1_noetic \
#		   riku/ros:cuda_115 \
#		   bash
#		   echo "done"
