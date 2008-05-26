#ifndef __MULTIBOOT_H
#define __MULTIBOOT_H

#define MULTIBOOT_FLAG_MEM     0x001
#define MULTIBOOT_FLAG_DEVICE  0x002
#define MULTIBOOT_FLAG_CMDLINE 0x004
#define MULTIBOOT_FLAG_MODS    0x008
#define MULTIBOOT_FLAG_AOUT    0x010
#define MULTIBOOT_FLAG_ELF     0x020
#define MULTIBOOT_FLAG_MMAP    0x040
#define MULTIBOOT_FLAG_CONFIG  0x080
#define MULTIBOOT_FLAG_LOADER  0x100
#define MULTIBOOT_FLAG_APM     0x200
#define MULTIBOOT_FLAG_VBE     0x400

/**
 * The symbol table for a.out. 
 */
typedef struct aout_symbol_table
{
	u32_t tabsize;
	u32_t strsize;
	u32_t addr;
	u32_t reserved;
} aout_symbol_table_t;

/**
 * The section header table for ELF. 
 */
typedef struct elf_section_header_table
{
	u32_t num;
	u32_t size;
	u32_t addr;
	u32_t shndx;
} elf_section_header_table_t;

/**
 * The Multiboot information.
 */
typedef struct multiboot_info
{
	u32_t flags;
	u32_t mem_lower;
	u32_t mem_upper;
	u32_t boot_device;
	u32_t cmdline;
	u32_t mods_count;
	u32_t mods_addr;
	union
	{
		aout_symbol_table_t aout_sym;
		elf_section_header_table_t elf_sec;
	} u;
	u32_t mmap_length;
	u32_t mmap_addr;
} multiboot_info_t;

#endif /* __MULTIBOOT_H */
