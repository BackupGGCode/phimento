/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/x86/registers.h>
#include <kernel/x86/irq.h>
#include <drivers/keyboard/keymap.h>
#include <drivers/keyboard/keyboard.h>

/* This load US keyboard map */
#include "keymaps/us.h"

s32_t shift;
static void keyboard_handler(registers_t _regs);

/**
 * Initialize the keyboard driver.
 */
void init_keyboard()
{
	register_interrupt(33, &keyboard_handler);
}

/**
 * Handles the keyboard interrupt.
 * 
 * @param _regs
 */
static void keyboard_handler(registers_t _regs)
{
    u8_t  _scancode;
    u32_t _ch;
    
    /* Read from the keyboard's data buffer */
    _scancode = inb(KB_DATA_READ);
    		
	/* If key was released */
    if (_scancode & 0x80)
    {
    	_ch = map_key(_scancode &= ASCII_MASK);
    	
		if((_ch) == KEY_SHIFT)
			shift = 0;
			
    }
    else /* Key pressed */
    {
    	_ch = map_key(_scancode);
    	
    	if(_ch == KEY_SHIFT)
			shift = 1;
		else
		{
			
			putc(_ch);
		}
    }

}

u16_t map_key(u8_t _scode)
{
	u16_t *_keyrow, column = 0;
	
	_keyrow = &keymap[_scode * NR_COLS];
	if(shift)
		column = 1;
	 
	return _keyrow[column];
}
