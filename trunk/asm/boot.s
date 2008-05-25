[BITS 32]
    
MBOOT_PAGE_ALIGN    equ 1<<0    			; Load kernel and modules on a page boundary
MBOOT_MEM_INFO      equ 1<<1    			; Provide your kernel with memory info
MBOOT_HEADER_MAGIC  equ 0x1BADB002 			; Multiboot Magic value
MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

mboot:
	dd	MBOOT_HEADER_MAGIC
	dd	MBOOT_HEADER_FLAGS
	dd	MBOOT_CHECKSUM

[GLOBAL entry]                  			; Kernel entry point.
[EXTERN init_kernel] 
entry:
    ; Load multiboot information:
    push	eax								; Push multiboot magic value
    push	ebx								; Push ptr to multiboot structure

    ; Execute the kernel:
    cli                         			; Disable interrupts.
    call init_kernel                   		; call init_kernel() function.
    jmp $                       			; Enter an infinite loop, to stop the processor.
                                			; executing whatever rubbish is in the memory
                                			; after our kernel!
