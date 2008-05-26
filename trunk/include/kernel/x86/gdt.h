#ifndef __GDT_H
#define __GDT_H

struct gdt_entry_s
{
    u16_t limit_low;
    u16_t base_low;
    u8_t base_middle;
    u8_t access;
    u8_t granularity;
    u8_t base_high;
} __attribute__((packed));
typedef struct gdt_entry_s gdt_entry_t;

struct gdt_ptr_s
{
    u16_t limit;
    u32_t base;
} __attribute__((packed));
typedef struct gdt_ptr_s gdt_ptr_t;

void init_gdt();

#endif /* __GDT_H */
