/**
 * phiMento OS - ghalex@gmail.com
 * 
 * @author Ghiura Alexandru
 * @version 0.1.0
 */

#include <kernel/types.h>
#include <drivers/disk/ata.h>

hardisk_t ds[2];

/**
 * Read one sector.
 * 
 * @param _hdd
 * @param _lba_addr
 * @param _buff
 */
s32_t read_lba28(hardisk_t* _hdd, u32_t _lba_addr, char* _buff)
{
	//0000 00000000 00000000 00000000
	//0000 00000000 00000000 00000001
	
	//CHS
	//Chilinder Head Sector
	
	//Sector = 1;
	
	u16_t _i, _tmp;
	
	/* Send sectors count */
	outb(_hdd->registers[ATA_SC], 0x01);
	
	/* Send LBA address */
	outb(_hdd->registers[ATA_SN], (u8_t)(_lba_addr));
	outb(_hdd->registers[ATA_CL], (u8_t)(_lba_addr >> 8));
	outb(_hdd->registers[ATA_CH], (u8_t)(_lba_addr >> 16));
	
	/* Send LBA address high 4 bits & drive number */
	outb(_hdd->registers[ATA_DH], 0xE0 | (_hdd->type << 4) | ((_lba_addr >> 24) & 0x0F));
	
	/* Send command */
	outb(_hdd->registers[ATA_COMMAND], ATA_CMD_READ_SECTORS);
	
	/* Wait */
	while(!(inb(_hdd->registers[ATA_STATUS]) & ATA_STATUS_DRQ));
	
	/* Read bytes */
	for (_i = 0; _i < 256; _i++)
	{
		_tmp = inw(_hdd->registers[ATA_DATA]);
		
		_buff[_i*2] 	= _tmp;
		_buff[_i*2 +1]	= _tmp >> 8;
		
		//printf("Reading... %d\n", _i);
	}
	
	return 1;
}

/**
 * Write one sector.
 * 
 * @param _hdd
 * @param _lba_addr
 * @param _buff
 */
u32_t write_lba28(hardisk_t* _hdd, u32_t _lba_addr, char* _buff)
{
	u16_t _i, _tmp;
	
	/* Send sectors count */
	outb(_hdd->registers[ATA_SC], 0x01);
	
	/* Send LBA address */
	outb(_hdd->registers[ATA_SN], (u8_t)(_lba_addr));
	outb(_hdd->registers[ATA_CL], (u8_t)(_lba_addr >> 8));
	outb(_hdd->registers[ATA_CH], (u8_t)(_lba_addr >> 16));
	
	/* Send LBA address high 4 bits & drive number */
	outb(_hdd->registers[ATA_DH], 0xE0 | (_hdd->type << 4) | ((_lba_addr >> 24) & 0x0F));
	//outb(_hdd->registers[ATA_DH], 0xA0);
	
	/* Send command */
	outb(_hdd->registers[ATA_COMMAND], ATA_CMD_WRITE_SECTORS);
	
	/* Wait */
	while(!(inb(_hdd->registers[ATA_STATUS]) & ATA_STATUS_DRQ));
	
	char s[32];
	
	/* Write bytes */
	for (_i = 0; _i < 256; _i++)
	{
		_tmp = _buff[_i * 2] | (_buff[_i * 2 + 1] << 8);
		outw(_hdd->registers[ATA_DATA], _tmp);
	}
	
	return 1;
}

/**
 * Get a drive.
 * 
 * @param _drive
 */
hardisk_t* get_drive(u32_t _drive)
{
	return &ds[_drive];
}

/**
 * Check to see if a drive is connect.
 * 
 * @param _drive
 */
u32_t detect_drive(hardisk_t* _hdd)
{
	/* Select device */
	outb(_hdd->registers[ATA_DH], ATA_DH_DEV0);
	
	/* Send indentify command */
	outb(_hdd->registers[ATA_COMMAND], ATA_CMD_IDENTIFY_DEVICE);
		
	/* Read and check status reg. */
	u8_t _status = inb(_hdd->registers[ATA_STATUS]);
	
	/* No drive detect */
	if(_status == 0)
		return 0;
		
	return 1;
}

/**
 * 
 * 
 * @param _name
 * @param _drive
 * @param _port
 */
void setup_drive(u8_t _name[32], u32_t _drive, u16_t _port)
{
	hardisk_t* _hd = get_drive(_drive);
	
	/* Name */
	strcpy(_hd->name, _name);
	
	/* Registers */
	_hd->registers[ATA_DATA]	= _port + ATA_DATA;
	_hd->registers[ATA_ERROR] 	= _port + ATA_ERROR;
	_hd->registers[ATA_SC] 		= _port + ATA_SC;
	_hd->registers[ATA_SN] 		= _port + ATA_SN;
	_hd->registers[ATA_CL] 		= _port + ATA_CL;
	_hd->registers[ATA_CH] 		= _port + ATA_CH;
	_hd->registers[ATA_DH] 		= _port + ATA_DH;
	_hd->registers[ATA_COMMAND] = _port + ATA_COMMAND;
	_hd->registers[ATA_STATUS] 	= _port + ATA_STATUS;
	
	/* Type : MASTER = 0 OR SLAVE = 1 */
	_hd->type = _drive;
	
}

/**
 * 
 */
void init_hdd()
{
	setup_drive("hdd0", 0, 0x1F0);
	setup_drive("hdd1", 1, 0x170);
	
}

void drive_info(u32_t _drive)
{
	hardisk_t* hd = get_drive(_drive);
	
	printf("\n");
	printf("Drive name:\t\t%s\n", hd->name);
	
	printf("ATA_DATA reg.:\t\t%x\n", 	hd->registers[ATA_DATA]);
	printf("ATA_ERROR reg.:\t\t%x\n", 	hd->registers[ATA_ERROR]);
	printf("ATA_SC reg.:\t\t%x\n", 		hd->registers[ATA_SC]);
	printf("ATA_SN reg.:\t\t%x\n", 		hd->registers[ATA_SN]);
	printf("ATA_CL reg.:\t\t%x\n", 		hd->registers[ATA_CL]);
	printf("ATA_CH reg.:\t\t%x\n", 		hd->registers[ATA_CH]);
	printf("ATA_DH reg.:\t\t%x\n", 		hd->registers[ATA_DH]);
	printf("ATA_COMMAND reg.:\t%x\n", 	hd->registers[ATA_COMMAND]);
	printf("ATA_STATUS reg.:\t%x\n", 	hd->registers[ATA_STATUS]);
}

