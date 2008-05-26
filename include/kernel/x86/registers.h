#ifndef __REGISTERS_H
#define __REGISTERS_H

typedef struct registers_s
{
   u32_t ds;                  						
   u32_t edi, esi, ebp, esp, ebx, edx, ecx, eax; 	
   u32_t int_no, err_code;    						
   u32_t eip, cs, eflags, useresp, ss;
} registers_t;

#endif /* __REGISTERS_H */
