#ifndef __KEYBOARD_H
#define __KEYBOARD_H

/**
 * AT keyboard.
 * 
 * KB_DATA_WRITE 	- "I/O port for keyboard write data."
 * KB_DATA_READ		- "I/O port for keyboard read data."
 * KB_COMMAND		- "I/O port for commands on AT."
 * KB_STATUS		- "I/O port for status on AT."
 */
#define KB_DATA_WRITE	0x60
#define KB_DATA_READ	0x60
#define KB_COMMAND		0x64
#define KB_STATUS		0x64

void init_keyboard();
u16_t map_key(u8_t _scode);

#endif /* __KEYBOARD_H */
