/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <kernel/multiboot.h>
#include <drivers/video/text.h>
#include <drivers/disk/fatfs.h>

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
		
	set_text_color(COLOR_BLACK, COLOR_WHITE);
	puts("ghalex@phimento:$\n");
	
	/* Reafing Boot Sector */		
	read_lba28(get_drive(0), 0x0, &boot_sec);
	
	u8_t volLabel[11];
	u8_t fsType[8];
	
	strncpy(volLabel, boot_sec.ebpb.vol_label, 0, 11);
	strncpy(fsType, boot_sec.ebpb.fs_type, 0, 8);
	
	volLabel[10] = '\0';
	fsType[7] = '\0';
	
	u32_t rootDirSectors;
	u32_t fatSz;
	u32_t totSec;
	
	rootDirSectors = ((boot_sec.bpb.root_ent_cnt * 32)  + (boot_sec.bpb.byts_per_sec - 1)) / boot_sec.bpb.byts_per_sec;
	
	if(boot_sec.bpb.sec_per_fat != 0)
	    fatSz = boot_sec.bpb.sec_per_fat;
	
	if(boot_sec.bpb.total_sec16 != 0)
		totSec = boot_sec.bpb.total_sec16;
	else
		totSec = boot_sec.bpb.total_sec32;
		
	u32_t dataSec = totSec - (boot_sec.bpb.rsvd_sec_cnt+ (boot_sec.bpb.num_fats * fatSz) + rootDirSectors);
	u32_t countOfClusters = dataSec / boot_sec.bpb.sec_per_clus;
	
	if(countOfClusters < 4085)
	{
		printf("Volume is FAT12\n");
	} else if(countOfClusters < 65525)
	{
		printf("Volume is FAT16\n");
	} else 
	{
		printf("Volume is FAT32\n");
	}

	
	printf("Number of FATs: %d\n", boot_sec.bpb.num_fats);
	printf("Sectors per FAT: %d\n", boot_sec.bpb.sec_per_fat);
	printf("Number of directory entris: %d\n", 512);
	
	u32_t rootSec = boot_sec.bpb.num_fats * boot_sec.bpb.sec_per_fat;
	
	u32_t _i = 0;
	dir_entry_t dir[boot_sec.bpb.root_ent_cnt];
	//for(_i=0;i<4;i++)
	//{
	//	u8_t tmp_buff[512]
		
	//}
	
	
	
	for(;;);
	return 0;
}
