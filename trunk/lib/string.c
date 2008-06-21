/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <lib/string.h>

/**
 *  Writes _len copies of _val into dest.
 * 
 * @param _dest
 * @param _val
 * @param _len
 */
void memset(u8_t* _dest, u8_t _val, u32_t _len)
{
	for(;_len != 0; _len--)
		*_dest++ = _val;
}

/**
 * Copy src string in dest.
 *
 * @param _dest
 * @param _src
 */
u32_t strcpy(u8_t *_dest, u8_t *_src)
{
	u8_t *_d = _dest;
	u8_t *_s = _src;
	u32_t _count = 0;
	
	while (*_s)
	{
		*(_d++) = *(_s++);
		_count++;
	} *(_d++) = '\0';
	
	return _count;
}

/**
 * Copies a string to another string from a 
 * certain offset to a certain len.
 * 
 * @param _dest
 * @param _src
 * @param _off
 * @param _len
 */
u32_t strncpy(u8_t *_dest, u8_t *_src, u32_t _off, u32_t _len)
{
	u8_t *_d = _dest;
	u8_t *_s = _src;
	
	u32_t _count = 0;
	u32_t _i	 = 0;
	
	for (_i = 0; _i < _off; _i++)
		*(_s++);
		
	for(_i = 0; _i < _len; _i++)
	{
		*(_d++) = *(_s++);
		_count++;
	}
	
	return _count;
}
