/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>

/**
 * Read from I/O ports to get data
 * from devices.
 * 
 * @param _port
 */
u8_t inb (u16_t _port)
{
    unsigned char ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (ret) : "dN" (_port));
    return ret;
}

/** 
 * Write to I/O ports to send bytes to devices.
 * 
 * @param _port
 * @param _data
 */
void outb (u16_t _port, u8_t _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
