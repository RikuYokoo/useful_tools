#!/bin/sh


function init()
{
	if [ ! -d "top_dir" ];then
		mkdir top_dir
	fi
	cd "top_dir"
	if [ ! -d "kernel_out" ];then
		mkdir kernel_out
	fi

	if [ ! -d "kernel_sources" ];then
		mkdir kernel_sources
	fi


	TOP_DIR="`pwd`"
	RELEASE_PACK_DIR="$TOP_DIR/e-CAM50_CUNX_AVER_L4T32.5.1_25-JUN-2021_R01_RC2"
	L4T_DIR="$TOP_DIR/Linux_for_Tegra"
	LDK_ROOTFS_DIR="$TOP_DIR/Linux_for_Tegra/rootfs"
	ARCH="arm64"
	export CROSS_COMPILE="$TOP_DIR/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-"
	TEGRA_KERNEL_OUT="$TOP_DIR/kernel_out"
	NVIDIA_SRC="$TOP_DIR/kernel_sources/Linux_for_Tegra/source/public"
	PATH="$TOP_DIR/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu/bin:$PATH"
}

function download_file()
{
	cd $TOP_DIR

	#wget --no-check-certificate "https://drive.google.com/uc?export=download&id=1LhfCYaNivC3R7NxxRzZTOf3mfZYJ2Gtl" -O e-CAM50_CUNX_AVER_L4T32.5.1_25-JUN-2021_R01_RC2.tar.gz
	#FILE_ID=1LhfCYaNivC3R7NxxRzZTOf3mfZYJ2Gtl
	#curl -sc /tmp/cookie "https://drive.google.com/uc?export=download&id=${FILE_ID}" > /dev/null
	#CODE="$(awk '/_warning_/ {print $NF}' /tmp/cookie)"
	#curl -Lb /tmp/cookie "https://drive.google.com/uc?export=download&confirm=${CODE}\$id=${FILE_ID}" -O e-CAM50_CUNX_AVER_L4T32.5.1_25-JUN-2021_R01_RC2.tar.gz 

	#curl -sc /tmp/cookie "https://drive.google.com/uc?export=download&id=${FILE_ID}" > /dev/null

	wget "https://developer.nvidia.com/embedded/dlc/l4t-gcc-7-3-1-toolchain-64-bit" -O gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz
	#tar -xf

	wget "https://developer.nvidia.com/embedded/l4t/r32_release_v5.2/t186/jetson_linux_r32.5.2_aarch64.tbz2" -O Jetson_Linux_R32.5.2_aarch64.tbz2

	#wget "https://developer.nvidia.com/embedded/l4t/r32_release_v5.2/t186/tegra_linux_sample-root-filesystem_r32.5.2_aarch64.tbz2" -O Tegra_Linux_Sample-Root-Filesystem_R32.5.2_aarch64.tbz2

	wget "https://developer.nvidia.com/embedded/l4t/r32_release_v5.2/sources/t186/public_sources.tbz2" -O public_sources.tbz2

}

function file_extraction()
{
	echo "start file extaction"
	cd $TOP_DIR
	echo "jetson linux aarch64 start"
	sudo tar -xjpf Jetson_Linux_R32.5.2_aarch64.tbz2
	sleep 2;

	cd $LDK_ROOTFS_DIR
	echo "start root file system" 
	mv $TOP_DIR/Tegra_Linux_Sample-Root-Filesystem_R32.5.2_aarch64.tbz2 .
	sudo tar -xjpf Tegra_Linux_Sample-Root-Filesystem_R32.5.2_aarch64.tbz2
	echo "sample root filesystem extraction succes!!"
	sleep 2


	cd $L4T_DIR
	sudo ./apply_binaries.sh
	sleep 2;

	echo "start extactioning public_sources"
	mv $TOP_DIR/public_sources.tbz2 $TOP_DIR/kernel_sources/
	cd $TOP_DIR/kernel_sources
	tar -xjpf public_sources.tbz2
	sleep 2;

	echo "extract e-con release"
	cd $TOP_DIR
	tar -xaf e-CAM50_CUNX_AVER_L4T32.5.1_25-JUN-2021_R01_RC2.tar.gz
	echo "succes extract e-con release"

	tar -xf gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz

	cd $NVIDIA_SRC
	tar -xjpf kernel_src.tbz2


	echo "succes extracted public_sources"



}

function apply_patch()
{
	cd $NVIDIA_SRC
	patch -p1 -i $RELEASE_PACK_DIR/Kernel/e-CAM50_CUNX_AVERMEDIA_XAVIER_NX_L4T32.5.1_kernel.patch
	patch -p1 -i $RELEASE_PACK_DIR/Kernel/e-CAM50_CUNX_AVERMEDIA_XAVIER_NX_L4T32.5.1_dtb.patch
	patch -p1 -i $RELEASE_PACK_DIR/Kernel/e-CAM50_CUNX_AVERMEDIA_XAVIER_NX_L4T32.5.1_module.patch
}

function make_kernel()
{
	cd $NVIDIA_SRC/kernel/kernel-4.9
	make ARCH=arm64 O=$TEGRA_KERNEL_OUT tegra_ecam_defconfig
	make ARCH=arm64 O=$TEGRA_KERNEL_OUT Image -j8
	make ARCH=arm64 O=$TEGRA_KERNEL_OUT modules -j8
	make ARCH=arm64 O=$TEGRA_KERNEL_OUT dtbs
	sudo make ARCH=arm64 O=$TEGRA_KERNEL_OUT modules_install INSTALL_MOD_PATH=$LDK_ROOTFS_DIR

	sleep 5;
	cd $NVIDIA_SRC/e-CAM50_CUNANO
	make ARCH=arm64 KERNEL_PATH=$TEGRA_KERNEL_OUT ar0521

	sudo make -C $TEGRA_KERNEL_OUT M=$PWD INSTALL_MOD_PATH=$LDK_ROOTFS_DIR modules_install

	sudo cp $TEGRA_KERNEL_OUT/arch/arm64/boot/Image $L4T_DIR/kernel/ -f
	sudo cp $TEGRA_KERNEL_OUT/arch/arm64/boot/dts/tegra194-p3668-all-p3509-0000-ar0521.dtb $L4T_DIR/kernel/dtb/tegra194-p3668-all-p3509-0000.dtb -f
}
function modifying_the_rootfs()
{
	sudo cp $RELEASE_PACK_DIR/misc/modules $LDK_ROOTFS_DIR/etc/modules -f 

	sudo cp $RELEASE_PACK_DIR/misc/xorg.conf.t194_ref $LDK_ROOTFS_DIR/etc/X11/xorg.t194_ref
}

init
download_file
file_extraction
apply_patch
make_kernel
modifying_the_rootfs
