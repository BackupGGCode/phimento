#!/bin/sh
# Scripts
MOUNT="mount.sh"
UMOUNT="umount.sh"

# Constants
BOCHS="bochs"
BOCHS_DIR="bochs"
BOCHS_CONF="bochsrc.txt"
BOCHS_DB="bochdb.txt"

# Script
if ./tools/$MOUNT $1 $2; then
	sudo bochs -q -f tools/$BOCHS_DIR/$BOCHS_CONF
	./tools/$UMOUNT;
fi;
