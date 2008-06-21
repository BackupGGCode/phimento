#ifndef __ATA_H
#define __ATA_H

/**
 * Port    Read/Write   Misc
 * ------  ------------ -------------------------------------------------
 * 0x1f0       r/w      data register, the bytes are written/read here
 * 0x1f1       r        error register  (look these values up yourself)
 * 0x1f2       r/w      sector count, how many sectors to read/write
 * 0x1f3       r/w      sector number, the actual sector wanted
 * 0x1f4       r/w      cylinder low, cylinders is 0-1024
 * 0x1f5       r/w      cylinder high, this makes up the rest of the 1024
 * 0x1f6       r/w      drive/head
 *                     	bit 7 = 1
 *                     	bit 6 = 0
 *                     	bit 5 = 1
 * 						bit 4 = 0  drive 0 select
 *                  		  = 1  drive 1 select
 *                  	bit 3-0    head select bits
 * 0x1f7       r      	status register
 *                  	bit 7 = 1  controller is executing a command
 * 						bit 6 = 1  drive is ready
 * 						bit 5 = 1  device fault
 * 						bit 4 = 1  seek complete
 * 						bit 3 = 1  set when the drive has PIO data to transfer, or is ready to accept PIO data.
 *                  	bit 2 = 1  disk data read corrected
 *                  	bit 1 = 1  index - set to 1 each revolution
 *                  	bit 0 = 1  previous command ended in an error
 * 0x1f7       w        command register
 * 						commands:
 *                  	0x50h format track
 *                  	0x20h read sectors with
 *                  	0x30h write sectors with
 *                  	0x70h seek
 */

/* ATA registers */
#define ATA_DATA  	0x0
#define ATA_ERROR	0x1
#define ATA_SC		0x2
#define ATA_SN		0x3
#define ATA_CL		0x4
#define ATA_CH		0x5
#define ATA_DH		0x6
#define ATA_COMMAND	0x7
#define ATA_STATUS	0x7

/* ATA status register */
#define ATA_STATUS_BUSY			0x80
#define ATA_STATUS_READY		0x40
#define ATA_STATUS_DF   		0x20
#define ATA_STATUS_SEEKC		0x10
#define ATA_STATUS_DRQ  		0x08
#define ATA_STATUS_CORRECTED 	0x04
#define ATA_STATUS_INDEX  		0x02
#define ATA_STATUS_ERROR  		0x01

/* ATA command register */
#define ATA_CMD_READ_SECTORS	0x20
#define ATA_CMD_WRITE_SECTORS	0x30
#define ATA_CMD_FORMAT_TRACK	0x50
#define ATA_CMD_SEEK			0x70
#define ATA_CMD_IDENTIFY_DEVICE	0xEC

/* ATA device/head register */
#define ATA_DH_DEV0				0x00
#define ATA_DH_DEV1				0x10


typedef struct hardisk
{
	u8_t	name[32];
	u16_t	type;
	u16_t	registers[10];
} hardisk_t;

#endif /* __ATA_H */
