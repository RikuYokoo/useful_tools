ARG BASE_IMAGE=nvidia/cuda:11.8.0-cudnn8-devel-ubuntu22.04
FROM ${BASE_IMAGE} as build-env
ENV DEBIAN_FRONTEND noninteractive
ENV NVIDIA_VISIBLE_DEVICES all
ENV NVIDIA_DRIVER_CAPABILITIES graphics,utility,compute

RUN apt-get update && apt-get install -y \
        build-essential \
        cmake \
        git \
        software-properties-common \
        vim \
        wget \
        zip \
        locales \
        cmake-curses-gui \
        curl \
        && rm -rf /var/lib/apt/lists/*
RUN apt-get update && apt-get install -y language-pack-ja && update-locale LANG=ja_JP.UTF-8 && rm -rf /var/lib/apt/lists/*
ENV LANG ja_JP.UTF-8
ENV LANGUAGE ja_JP:ja
ENV LC_ALL ja_JP.UTF-8

RUN add-apt-repository universe

RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" |  tee /etc/apt/sources.list.d/ros2.list > /dev/null

RUN apt-get update && apt-get -y upgrade && apt install -y \ 
        ros-humble-desktop \
        python3-colcon-common-extensions \
        gazebo \
        ros-humble-gazebo-* \
        ros-humble-rqt-* \
        && rm -rf /var/lib/apt/lists/*

        
RUN curl -sSf https://librealsense.intel.com/Debian/librealsense.pgp | tee /etc/apt/keyrings/librealsense.pgp > /dev/null
RUN echo "deb [signed-by=/etc/apt/keyrings/librealsense.pgp] https://librealsense.intel.com/Debian/apt-repo `lsb_release -cs` main" | tee /etc/apt/sources.list.d/librealsense.list

RUN apt-get update && apt-get install -y librealsense2-dkms librealsense2-utils \
        ros-humble-librealsense2* \
        ros-humble-realsense2-camera \
        && rm -rf /var/lib/apt/lists/*
