#!/bin/sh
# Scripts
MOUNT="mount.sh"
MOUNT_DIR="mnt"
UMOUNT="umount.sh"

# Constants
KERNEL="kernel.bin"
KERNEL_DIR="bin"

# Script
if ./tools/$MOUNT $1 $2; then
	if sudo cp $KERNEL_DIR/$KERNEL /$MOUNT_DIR/$KERNEL; then
		echo "#$KERNEL has been copied."
	fi;
	./tools/$UMOUNT;
fi;
