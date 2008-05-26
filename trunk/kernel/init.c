/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/multiboot.h>
#include <drivers/video/text.h>

void kstatus_msg(s8_t *_msg,  s8_t* _status);

/**
 * phiMento kernel entry.
 * 
 * @param _mbd
 */
void init_kernel(multiboot_info_t* _mboot)
{	
	/* Initialize kernel */
	init_video();	 kstatus_msg("Text Mode Video Driver", "OK");
	init_gdt();		 kstatus_msg("Global Descriptor Table", "OK");
	init_idt();		 kstatus_msg("Interrupt Descriptor Table", "OK");
	init_isr();		 kstatus_msg("Interrupt Service Routines", "OK");
	init_irq();		 kstatus_msg("Interrupt Request System", "OK");
	init_keyboard(); kstatus_msg("Keyboard Driver", "OK");
	printf("System initialized with success.\n\n");
	asm volatile("sti");
	
	/* Call kernel main function */
	main(_mboot);
	
}

void kstatus_msg(s8_t *_msg,  s8_t* _status)
{
	printf("%s", _msg);
	
	set_text_color(COLOR_BLACK, COLOR_GREEN);
	set_xpos(74);
	printf("[ %s ]\n", _status);
	
	set_text_color(COLOR_BLACK, COLOR_WHITE);
}
