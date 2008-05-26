#!/bin/sh

# Mount a Image
# Constants 
LOOP="loop0"

# Load args
if [ "$1" != "" ]; then
	LOOP=$1;
fi;

# Unmount script
echo "#Unmount loop: $LOOP."
if sudo umount /dev/$LOOP; then
	if sudo /sbin/losetup -d /dev/$LOOP; then
		echo "#Loop unmounted!";
	fi;
else
	echo "#Loop not unmounted!";
fi;
