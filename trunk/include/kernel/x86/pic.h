#ifndef __PIC_H
#define __PIC_H

/** PIC 1 COMMAND & DATA PORT */
#define PIC1_COMMAND 0x20
#define PIC1_DATA	 0x21

/** PIC 2 COMMAND & DATA PORT */
#define PIC2_COMMAND 0xA0
#define PIC2_DATA	 0xA1

/**
 * ICW1 is used to tell the PICs if a ICW4 is following and if the PIC is working in a cascaded PIC environment.
 * ICW2 is tells the PIC where to map IRQ0 and IRQ8.
 * ICW3 is used for telling the PIC which IRQ to use for the communication between each other.
 * ICW4 is used for telling that we are working in a 80x86 architecture.
 */
#define ICW1 		0x11
#define ICW3_PIC1	0x04	
#define ICW3_PIC2	0x02
#define ICW4 		0x01

/** End-of-interrupt command code */
#define PIC_EOI		0x20


void pics_remap(s32_t _pic1, s32_t _pic2);
void pics_send_end(u8_t _irq);

#endif /* __PIC_H */
