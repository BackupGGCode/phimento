#ifndef __IDT_H
#define __IDT_H

struct idt_entry_s
{
   u16_t base_lo;
   u16_t sel;
   u8_t  always0;
   u8_t  flags;
   u16_t base_hi;
} __attribute__((packed));
typedef struct idt_entry_s idt_entry_t;

struct idt_ptr_s
{
   u16_t limit;
   u32_t base;
} __attribute__((packed));
typedef struct idt_ptr_s idt_ptr_t;

void init_idt();
void idt_set_gate(u8_t _num, u32_t _base, u16_t _sel, u8_t _flags);

#endif /* __IDT_H */
