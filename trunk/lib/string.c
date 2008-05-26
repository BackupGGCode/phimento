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
