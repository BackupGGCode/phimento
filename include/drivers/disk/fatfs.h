#ifndef __FATFS_H
#define __FATFS_H

/* BIOS Parameter Block structure */
struct bpb_s
{
	u16_t 	byts_per_sec;		/* Bytes per sector */
	u8_t	sec_per_clus;		/* Sectors per cluster (1, 2, 4, 8, 16, 32, 64,128 are valid) */
	u16_t	rsvd_sec_cnt;		/* Reserved sectors */
	u8_t	num_fats;			/* Number of FAT copies */
	u16_t	root_ent_cnt;		/* Number of root dir entries */
	u16_t	total_sec16;		/* Total count of sectors */
	u8_t	media_type;			/* Media descriptor byte (0xF0, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE are valid) */
	u16_t 	sec_per_fat;		/* Sectors per FAT */
	u16_t 	sec_per_trk;		/* Sectors per track */
	u16_t	num_heads;			/* Number of heads for interrupt 0x13 */
	u32_t	hidd_sec;			/* Hidden sectors */
	u32_t	total_sec32;		/* Total count of sectors */
} __attribute__((packed));
typedef struct bpb_s bpb_t;

/* Extended BIOS Parameter Block structure (FAT12/16) */
struct ebpb16_s
{
	u8_t	drv_num;			/* Int 0x13 drive number */
	u8_t 	head;				/* Archaic, used by Windows NT-class OSes for flags */
	u8_t	boot_sig;			/* Extended boot signature (0x29). */
	u32_t	vol_id;				/* Volume serial number */
	u8_t	vol_label[11];		/* Volume label */
	u8_t	fs_type[8];			/* FIlesystem type (FAT12, FAT16, FAT are valid) */
} __attribute__((packed));
typedef struct ebpb16_s ebpb16_t;

/* Logical Boot Sector structure */
struct lbs_s
{
	u8_t 	 jump[3];			/* JMP instruction */
	u8_t 	 oemid[8];			/* OEM ID, space-padded */
	bpb_t	 bpb;				/* BIOS Parameter Block */
	ebpb16_t ebpb;				/* FAT12/16 Extended BIOS Parameter Block */
	u8_t 	 code[448];			/* Boot sector code */
	u8_t 	 sig_55;			/* 0x55 signature byte */
	u8_t 	 sig_aa;			/* 0xAA signature byte */
} __attribute__((packed));
typedef struct lbs_s lbs_t;

/* Root Directory entry */
struct dir_entry_s
{
	u32_t filename	 	:11;	/* File name (0-7), File extension (8-10) */
	u32_t attributes 	:1;		/* File attributes */
	u32_t reserved	 	:1;		/* Unused */
	u32_t crt_time_ms	:1;		/* Create time in milliseconds */
	u32_t crt_time		:2;		/* Created time */
	u32_t crt_date		:2;		/* Created date */
	u32_t lst_acc_date	:2;		/* Last access date */
	u32_t ea_idx		:2;		/* EA Index (Used in OS/2 and NT) */
	u32_t wrt_time		:2;		/* Last Modified time */
	u32_t wrt_date		:2;		/* Last modified date */
	u32_t fst_clus		:2;		/* Starting cluster number */
	u32_t file_size		:2;		/* Size of the file */
} __attribute__((packed));
typedef struct dir_entry_s dir_entry_t;

#endif /* __FATFS_H */
