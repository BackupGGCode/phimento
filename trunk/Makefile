# phiMento OS master makefile
# Directories
ASM_DIR 	= asm
DRIVERS_DIR	= drivers
KERNEL_DIR	= kernel
LIB_DIR		= lib
BIN_DIR		= bin
TOOLS_DIR	= tools

# Macros
UPDATE_SH 	= ./$(TOOLS_DIR)/update.sh
RUN_SH		= ./$(TOOLS_DIR)/run.sh
LDSCRIPT 	= $(TOOLS_DIR)/link.ld
LDFLAGS 	= -T $(LDSCRIPT)

# File
KERNEL 		= $(BIN_DIR)/kernel.bin
HEAD		= $(ASM_DIR)/boot.o
OBJS		= $(KERNEL_DIR)/kernel.a $(DRIVERS_DIR)/drivers.a $(KERNEL_DIR)/core.a $(ASM_DIR)/asm.a $(LIB_DIR)/lib.a

# Build kernel
all:
	cd $(ASM_DIR); $(MAKE) $@
	cd $(DRIVERS_DIR); $(MAKE) $@
	cd $(KERNEL_DIR); $(MAKE) $@
	cd $(LIB_DIR); $(MAKE) $@
	$(LD) $(LDFLAGS) -o $(KERNEL) $(HEAD) $(OBJS)

clean:
	rm -f $(KERNEL)
	cd $(ASM_DIR) &&  $(MAKE) $@
	cd $(DRIVERS_DIR); $(MAKE) $@
	cd $(KERNEL_DIR) &&  $(MAKE) $@
	cd $(LIB_DIR); $(MAKE) $@

depend:
	cd $(DRIVERS_DIR); $(MAKE) $@
	cd $(KERNEL_DIR) &&  $(MAKE) $@
	cd $(LIB_DIR); $(MAKE) $@

# Update phiMento image.
image:
	$(UPDATE_SH);

# Mount & Run phiMento image
run:
	$(RUN_SH);
