/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>

/**
 * Read one byte from I/O ports.
 * 
 * @param _port
 */
u8_t inb(u16_t _port)
{
    u8_t ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (ret) : "dN" (_port));
    
    return ret;
}

/** 
 * Write one byte to I/O ports.
 * 
 * @param _port
 * @param _data
 */
void outb(u16_t _port, u8_t _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

/**
 * Read one word from I/O ports.
 * 
 * @param _port
 */
u16_t inw(u16_t _port)
{
	u16_t ret;
    __asm__ __volatile__ ("inw %1, %0" : "=a" (ret) : "dN" (_port));
    
    return ret;
}

/** 
 * Write one word to I/O ports.
 * 
 * @param _port
 * @param _data
 */
void outw(u16_t _port, u16_t _data)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN" (_port), "a" (_data));
}
