/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/x86/idt.h>

idt_ptr_t   idt_ptr;
idt_entry_t idt_entries[256];

/* This exists in 'idt.s', and is used to load our IDT */
extern void idt_load();

/**
 * Initialise the interrupt descriptor table.
 */
void init_idt()
{
	/* Initialise IDT pointer */
	idt_ptr.limit = (sizeof(idt_entry_t) * 256) -1;
	idt_ptr.base  = (unsigned int) &idt_entries;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt_entries, 0, sizeof(idt_entry_t) * 256);
	
    /* Points the processor's internal register to the new IDT */
    idt_load((u32_t)&idt_ptr);
}

/**
 * Set the value of one IDT entry.
 * 
 * @param _num
 * @param _base
 * @param _sel
 * @param _flags
 */
void idt_set_gate(u8_t _num, u32_t _base, u16_t _sel, u8_t _flags)
{
	 /* The interrupt routine's base address */
	idt_entries[_num].base_lo = _base & 0xFFFF;
	idt_entries[_num].base_hi = (_base >> 16) & 0xFFFF;

	/* The segment or 'selector' that this IDT entry will use
    *  is set here, along with any access flags */
	idt_entries[_num].sel     = _sel;
	idt_entries[_num].always0 = 0;
	
	idt_entries[_num].flags   = _flags;
}
