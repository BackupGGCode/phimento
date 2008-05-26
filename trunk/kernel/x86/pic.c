/**
 * TinyOS - ghalex@gmail.com
 * Programmable Interface Controller
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/x86/pic.h>

/**
 * Init the PICs and remap them.
 * 
 * @param _pic1
 * @param _pic2
 */
void pics_remap(s32_t _pic1, s32_t _pic2)
{	
	/* Send ICW1 */
	outb(PIC1_COMMAND, ICW1);
	outb(PIC2_COMMAND, ICW1);
	
   	/* Send ICW2 */
	outb(PIC1_DATA, _pic1);
	outb(PIC2_DATA, _pic2);
	 
	
   	/* Send ICW3
	 * IRQ2 -> connection to slave */
	outb(PIC1_DATA, ICW3_PIC1);	
	outb(PIC2_DATA, ICW3_PIC2);
	
    /* Send ICW4 */
	outb(PIC1_DATA, ICW4);
	outb(PIC2_DATA, ICW4);
}

/**
 * Send EOI to PICs
 * 
 * @param _irq
 */
void pics_send_end(u8_t _irq)
{
	/* If _irq is on slave PIC 
	 * we must send PIC_EOI twice */
	if(_irq >= 40)
		outb(PIC2_COMMAND, PIC_EOI);
	
	outb(PIC1_COMMAND, PIC_EOI);
}
