/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/multiboot.h>
#include <drivers/video/text.h>

/**
 * phiMento main function.
 * 
 * @param _mbd
 * @param _magic
 */
int main(multiboot_info_t* _mboot)
{
	set_text_color(COLOR_BLACK, COLOR_GREEN);
	puts("Welcome to phiMento OS!\n");
	puts("[v0.1 Alpha]\n\n");
	
	//u32_t _phy_size = (_mboot->mem_upper - _mboot->mem_lower)*1024;
	//printf("%d of physical memory instaled.\n", _phy_size);
	
	set_text_color(COLOR_BLACK, COLOR_WHITE);
	puts("ghalex@phimento:$");
	
	for(;;);
	return 0;
}
