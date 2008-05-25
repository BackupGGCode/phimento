/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <lib/stdlib.h>

/**
 * Convert a string into a numerical 
 * representation.
 * 
 * @param _string
 */
s8_t atoi(const s8_t* _string)
{
	s32_t _i 		= 0;
	s32_t _sign 	= 1;
	u32_t _return 	= 0;
	u32_t _digit	= 0;
	
	s8_t _ch;	
	do
	{
		_ch = *_string;
		if (_ch >= '0' && _ch <= '9')
		{
			_digit  = (u32_t)(_ch - '0');
			_return = (_return * 10) + _digit;
		}
		
		if (_ch == '-')
			_sign = -1;
			
		if (_ch == '+')
			_sign = 1;

	} while (*(_string++));
	
	return (_sign * _return);
}

/**
 * Takes the integer input value _value and converts it to a 
 * number in base _base. The resulting number is written 
 * to the output buffer _buff.
 * 
 * @param _value
 * @param _buff
 * @param _base
 */
void itoa(s32_t _value, s8_t* _buff, s8_t _base)
{	
	s8_t  _num[] 	= "0123456789ABCDEF";
	s8_t* _p		= _buff;
	s8_t  _sign		= 0;
	
	if(_value < 0)
	{
		_value = -_value;
		_sign  = 1;
	}
	
	do
	{
		*_p++ = _num[_value % _base]; 
		
	} while(_value /= _base);
	
	if(_sign)
		*_p++ = '-';
		
	*_p = '\0';
	str_reverse(_buff, _p-1);
}

/**
 * Reverse a string.
 * 
 * @param _begin
 * @param _end
 */
void str_reverse(s8_t* _begin, s8_t* _end)
{
	s8_t _aux;
	while(_end > _begin)
		_aux=*_end, *_end--=*_begin, *_begin++=_aux;
	
}
