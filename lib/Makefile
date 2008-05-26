# phiMento OS lib makefile
# Directories
INCLUDE_DIR = ../include

# Macros
RLIB		= ranlib
CFLAGS 		= -I$(INCLUDE_DIR) -nostdlib -nostdinc -fno-builtin
DEPEND		= makedepend -I$(INCLUDE_DIR)

# Objects
OUT			= lib.a
OBJS		= stdlib.o printf.o string.o
SRCS		= stdlib.c printf.c string.c

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
	rm -f $(OUT) *.o
# DO NOT DELETE

stdlib.o: ../include/kernel/types.h ../include/lib/stdlib.h
printf.o: ../include/kernel/types.h ../include/kernel/x86/stdarg.h
string.o: ../include/kernel/types.h ../include/lib/string.h
