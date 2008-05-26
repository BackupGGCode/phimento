# phiMento OS drivers makefile
# Directories
INCLUDE_DIR 	= ../include
VIDEO_DIR		= video
KEYBOARD_DIR	= keyboard

# Macros
RLIB		= ranlib
CFLAGS 		= -I$(INCLUDE_DIR) -nostdlib -nostdinc -fno-builtin
DEPEND		= makedepend -I$(INCLUDE_DIR)

# Objects
OUT				= drivers.a
VIDEO_SRCS		= $(VIDEO_DIR)/text.c
VIDEO_OBJS		= $(VIDEO_DIR)/text.o
KEYBOARD_SRCS	= $(KEYBOARD_DIR)/keyboard.c
KEYBOARD_OBJS	= $(KEYBOARD_DIR)/keyboard.o
OBJS			= $(VIDEO_OBJS) $(KEYBOARD_OBJS)
SRCS			= $(VIDEO_SRCS) $(KEYBOARD_SRCS)

all: $(OUT)
$(OUT): $(OBJS)
	$(AR) rvu $@ $(OBJS)
	$(RLIB) $(OUT)

# Compile all .c files
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
	
# what are the source dependencies
depend: $(SRCS)
	$(DEPEND) $(SRCS)
	
clean: 
	rm -f $(OUT) *.o $(VIDEO_DIR)/*.o
# DO NOT DELETE

video/text.o: ../include/kernel/types.h ../include/drivers/video/text.h
video/text.o: ../include/drivers/keyboard/keymap.h
keyboard/keyboard.o: ../include/kernel/types.h
keyboard/keyboard.o: ../include/kernel/x86/registers.h
keyboard/keyboard.o: ../include/kernel/x86/irq.h
keyboard/keyboard.o: ../include/drivers/keyboard/keymap.h
keyboard/keyboard.o: ../include/drivers/keyboard/keyboard.h
keyboard/keyboard.o: keyboard/keymaps/us.h
