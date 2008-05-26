/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/x86/gdt.h>

extern void gdt_flush(u32_t);

gdt_ptr_t   gdt_ptr;
gdt_entry_t gdt_entries[5];

/**
 * Set the value of one GDT entry.
 * 
 * @param _num
 * @param _base
 * @param _limit
 * @param _access
 * @param _gran
 */
static void gdt_set_gate(u32_t _num, u32_t _base, u32_t _limit, u8_t _access, u8_t _gran)
{
   gdt_entries[_num].base_low    = (_base & 0xFFFF);
   gdt_entries[_num].base_middle = (_base >> 16) & 0xFF;
   gdt_entries[_num].base_high   = (_base >> 24) & 0xFF;

   gdt_entries[_num].limit_low   = (_limit & 0xFFFF);
   gdt_entries[_num].granularity = (_limit >> 16) & 0x0F;

   gdt_entries[_num].granularity |= _gran & 0xF0;
   gdt_entries[_num].access       = _access;
}

/**
 * Initialise the global descriptor table.
 */
void init_gdt()
{
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base  = (u32_t) &gdt_entries;
	
	gdt_set_gate(0, 0, 0, 0, 0);                	/** Null segment */
	gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); 	/** Code segment */
	gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); 	/** Data segment */
	gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); 	/** User mode code segment */
	gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); 	/** User mode data segment */
	
	gdt_flush((u32_t)&gdt_ptr);
}
