/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/x86/stdarg.h>

/**
 * Print formatted data to stdout.
 * 
 * @param _format
 * @param _arguments
 */
s32_t printf(const s8_t* _format, ... )
{
	va_list _list;
	va_start(_list, _format);
	
	s8_t  _buff[32];
	s32_t _i = 0;
	while(_format[_i])
	{
		switch(_format[_i])
		{
			case '%':
			{
				_i++;
				if( !_format[_i] )
					return;
		
				switch(_format[_i])
				{
					/* Print an int as a signed decimal number */
					case 'd':
					case 'i':
					{
						s32_t _val = va_arg(_list, s32_t);
						itoa(_val, _buff, 10);
						
						puts(_buff);
					}
					break;
					
					/* 	Print decimal unsigned int. */
					case 'u':
					{
						u32_t _val = va_arg(_list, u32_t);
						itoa(_val, _buff, 10);
						
						puts(_buff);
					}
					break;
					
					/* Print an unsigned int as a hexadecimal number */
					case 'X':
					case 'x':
					{
						u32_t _val = va_arg(_list, u32_t);
						itoa(_val, _buff, 16);
						
						puts("0x");
						puts(_buff);
					}
					break;
					
					/* 	Print decimal unsigned int as a binary number. */
					case 'b':
					{
						u32_t _val = va_arg(_list, u32_t);
						itoa(_val, _buff, 2);
						
						puts(_buff);
					}
					break;
						
					/* Print a char */
					case 'c':
					{
						s8_t _val = va_arg(_list, s8_t);
						putc(_val);
					}
					break;
										
					/* Print a character string. */
					case 's':
					{
						s8_t* _val = va_arg(_list, s8_t*);
						puts(_val);
					}
					break;
				}
				
			}
			break;
			
			default:
				putc(_format[_i]);
		}
		
		_i++;
	}
	
	va_end(_list);
	return 0;
}
