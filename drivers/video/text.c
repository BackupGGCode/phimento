/**
 * phiMento OS - ghalex@gmail.com
 * Text Mode Driver
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <drivers/video/text.h>
#include <drivers/keyboard/keymap.h>

u16_t* textmemptr;
s32_t  attrib = 0x0F;
s32_t  csr_x = 0, csr_y = 0;

/**
 * Sets our text-mode VGA pointer.
 */
void init_video()
{
    textmemptr = (u16_t*) 0xB8000;
    
    csr_x = 0;
    csr_y = 0;
    clear();
}

/** 
 * Clears the screen.
 */
void clear()
{
	u16_t* _temp = (u16_t*) textmemptr;
    u16_t  _blank;
    s32_t _i, _j;

    _blank = 0x20 | (attrib << 8);

    for(_i = 0; _i < 25; _i++)
    	for(_j = 0 ; _j < 80; _j++)
    	{
    		_temp  = textmemptr + (_i * 80 + _j);
        	*_temp = _blank;
		}

    csr_x = 0;
    csr_y = 0;
    move_csr();
}

/**
 * Updates the hardware cursor: the little blinking line
 * on the screen under the last character pressed.
 */
void move_csr()
{
    u16_t _temp = csr_y * 80 + csr_x;

    outb(0x3D4, 14);
    outb(0x3D5, _temp >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, _temp);
}

/**
 * Puts a single character on the screen.
 * 
 * @param _ch
 */
void putc(u8_t _ch)
{
	u16_t* _where;
	u16_t _att = attrib << 8;
	u16_t _blank = 0x20 | (attrib << 8);
	
	if(_ch == '\b')
	{
		if(csr_x < 1)
		{
			csr_x = 79;
			csr_y--;
			
		} else
		{
			csr_x--;
			
			_where  = textmemptr + (csr_y * 80 + csr_x);
			*_where = _blank;
		}		
	} else if (_ch == '\t')
   	{
       csr_x = (csr_x + 8) & ~(8-1);
	}else if (_ch == '\n')
    {
        csr_x = 0;
        csr_y++;
        
    } else if(_ch >= ' ')
    {
		_where  = textmemptr + (csr_y * 80 + csr_x);
		*_where = _ch | _att;
	
		csr_x++;
	}
	
	scroll();
	move_csr();
}

/**
 * Output a string on the screen.
 * 
 * @param _text
 */
void puts(u8_t* _text)
{
   	s32_t _i = 0;
   	while(_text[_i])
		putc(_text[_i++]);
}

/**
 * Scroll one line.
 */
void scroll()
{
   u16_t _blank;
   _blank = 0x20 | (attrib << 8);

   if(csr_y >= 25)
   {
       /* Move the current text chunk that makes up the screen
        * back in the buffer by a line */
       s32_t _i;
       for (_i = 0*80; _i < 24*80; _i++)
       {
           textmemptr[_i] = textmemptr[_i+80];
       }

       /* The last line should now be blank. Do this by writing
        * 80 spaces to it. */
       for (_i = 24*80; _i < 25*80; _i++)
       {
           textmemptr[_i] = _blank;
       }
       
       /* The cursor should now be on the last line. */
       csr_y = 24;
   }
}

/**
 * Sets the forecolor and backcolor that we will use.
 * 
 * @param _backcolor
 * @param _forecolor
 */
void set_text_color(u8_t _backcolor, u8_t _forecolor)
{
	attrib = (_backcolor << 4 ) | _forecolor;
}

/**
 * Get cursor X position
 */
s32_t get_xpos()
{
	return csr_x;
}

/**
 * Get cursor Y position.
 */
s32_t get_ypos()
{
	return csr_y;
}

/**
 * Set cursor X position.
 * 
 * @param _x
 */
void set_xpos(s32_t _x)
{
	csr_x = _x;
}

/**
 * Set cursor Y position.
 */
void set_ypos(s32_t _y)
{
	csr_y = _y;
}

