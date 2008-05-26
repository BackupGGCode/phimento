# phiMento OS kernel makefile
# Directories
INCLUDE_DIR = ../include
CORE_DIR	= x86
MEMORY_DIR	= memory

# Macros
RLIB		= ranlib
CFLAGS 		= -I$(INCLUDE_DIR) -nostdlib -nostdinc -fno-builtin
DEPEND		= makedepend -I$(INCLUDE_DIR)

# Objects
MEMORY		= memory.a
MEMORY_OBJS	= $(MEMORY_DIR)/paging.o
MEMORY_SRCS	= $(MEMORY_DIR)/paging.c
CORE		= core.a
CORE_OBJ	= $(CORE_DIR)/x86.o $(CORE_DIR)/gdt.o $(CORE_DIR)/idt.o \
			  $(CORE_DIR)/isr.o $(CORE_DIR)/pic.o $(CORE_DIR)/irq.o
CORE_SRCS	= $(CORE_DIR)/x86.c $(CORE_DIR)/gdt.c $(CORE_DIR)/idt.c \
			  $(CORE_DIR)/isr.c $(CORE_DIR)/pic.c $(CORE_DIR)/irq.c
OUT			= kernel.a
OBJS		= init.o main.o
SRCS		= init.c main.c

all: $(OUT) $(CORE) $(MEMORY)
$(OUT): $(OBJS)
	$(AR) rvu $@ $(OBJS)
	$(RLIB) $(OUT)

# Arhive core objects
$(CORE): $(CORE_OBJ)
	$(AR) rvu $@ $(CORE_OBJ)
	$(RLIB) $(CORE)
	
# Arhive memory objects
$(MEMORY): $(MEMORY_OBJS)
	$(AR) rvu $@ $(MEMORY_OBJS)
	$(RLIB) $(MEMORY)


# Compile all .c files
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
	
# what are the source dependencies
depend: $(SRCS) $(CORE_SRCS) $(MEMORY_SRCS)
	$(DEPEND) $(SRCS) $(CORE_SRCS) $(MEMORY_SRCS)
	
clean:
	rm -f $(OUT) *.a *.o $(CORE_DIR)/*.o
# DO NOT DELETE

init.o: ../include/kernel/types.h ../include/drivers/video/text.h
main.o: ../include/kernel/types.h ../include/drivers/video/text.h
x86/x86.o: ../include/kernel/types.h
x86/gdt.o: ../include/kernel/types.h ../include/kernel/x86/gdt.h
x86/idt.o: ../include/kernel/types.h ../include/kernel/x86/idt.h
x86/isr.o: ../include/kernel/types.h ../include/kernel/x86/isr.h
x86/isr.o: ../include/kernel/x86/registers.h
x86/pic.o: ../include/kernel/types.h ../include/kernel/x86/pic.h
x86/irq.o: ../include/kernel/types.h ../include/kernel/x86/registers.h
x86/irq.o: ../include/kernel/x86/irq.h
