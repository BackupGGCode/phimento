# phiMento OS assembly makefile
# Macros
ASM 		= nasm
RLIB		= ranlib
ASMFLAGS	= -f elf

# Objects
OUT		= asm.a
HEAD	= boot.o
OBJS	= gdt.o idt.o isr.o irq.o

all: $(HEAD) $(OUT)
$(OUT): $(OBJS)
	$(AR) rvu $@ $(OBJS)
	$(RLIB) $(OUT)

# Assembly all .s files
.s.o:
	$(ASM) $(ASMFLAGS) -o $@ $<
	
clean: 
	rm -f $(OUT) *.o
