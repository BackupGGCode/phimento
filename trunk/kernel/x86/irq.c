/**
 * TinyOS - ghalex@gmail.com
 * Interrupt Request
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/x86/registers.h>
#include <kernel/x86/irq.h>

irq_t interrupt_handlers[256];

/**
 * Add entreys to IDT.
 */
void init_irq()
{
	/* Init the PICs and remap them
	 * PIC1 : 32 .. 40
	 * PIC2 : 40 .. 48 */	 
	pics_remap(0x20, 0x28);
	
	idt_set_gate(32, (u32_t)irq0,  0x08, 0x8E);
	idt_set_gate(33, (u32_t)irq1,  0x08, 0x8E);
	idt_set_gate(34, (u32_t)irq2,  0x08, 0x8E);
	idt_set_gate(35, (u32_t)irq3,  0x08, 0x8E);
	idt_set_gate(36, (u32_t)irq4,  0x08, 0x8E);
	idt_set_gate(37, (u32_t)irq5,  0x08, 0x8E);
	idt_set_gate(38, (u32_t)irq6,  0x08, 0x8E);
	idt_set_gate(39, (u32_t)irq7,  0x08, 0x8E);
	
	idt_set_gate(40, (u32_t)irq8,  0x08, 0x8E);
	idt_set_gate(41, (u32_t)irq9,  0x08, 0x8E);
	idt_set_gate(42, (u32_t)irq10, 0x08, 0x8E);
	idt_set_gate(43, (u32_t)irq11, 0x08, 0x8E);
	idt_set_gate(44, (u32_t)irq12, 0x08, 0x8E);
	idt_set_gate(45, (u32_t)irq13, 0x08, 0x8E);
	idt_set_gate(46, (u32_t)irq14, 0x08, 0x8E);
  	idt_set_gate(47, (u32_t)irq15, 0x08, 0x8E);
}

/**
 * This function is call from irq.s
 * 
 * @param _regs
 */
void irq_handler(registers_t _regs)
{
	pics_send_end(_regs.int_no);
	
	if (interrupt_handlers[_regs.int_no] != 0)
	{
		irq_t _handler = interrupt_handlers[_regs.int_no];
		_handler(_regs);
	}
}

/**
 * Register a new irq handler.
 * 
 * @param _n
 * @param _handler
 */
void register_interrupt(s8_t _n, irq_t _handler)
{
	interrupt_handlers[_n] = _handler;
}

/**
 * Delete a irq handler.
 * 
 * @param _n
 */
void unregister_interrupt(s8_t _n)
{
	interrupt_handlers[_n] = 0;
}
