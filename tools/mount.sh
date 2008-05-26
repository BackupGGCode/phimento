#!/bin/sh

# Mount a Image
# Constants 
DIR="bin"
IMG="phimento.img"
LOOP="loop0"

# Load args
if [ "$1" != "" ]; then
	IMG=$1;
	if [ "$2" != "" ]; then
		LOOP=$2;
	fi;
fi;

# Mount script
echo "#Mount image: $IMG."
if sudo /sbin/losetup /dev/$LOOP $DIR/$IMG; then
	if sudo mount /dev/$LOOP /mnt; then
		echo "#Image mounted!";
		return 0;
	fi;
else
	echo "#Image not mounted!";
	return 1;
fi;
