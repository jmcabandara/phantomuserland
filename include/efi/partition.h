/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Portions Copyright 2008 Sun Microsystems, Inc. (CDDL)
 * Portions Copyright 2009 Digital Zone, Ltd.
 */

#ifndef    _SYS_EFI_PARTITION_H
#define    _SYS_EFI_PARTITION_H

//#pragma ident    "%Z%%M%    %I%    %E% SMI"

#include <sys/uuid.h>

/*
 * GUID Partition Table Header
 */

#define    EFI_LABEL_SIZE    512
#define    LEN_EFI_PAD    (EFI_LABEL_SIZE - \
                ((5 * sizeof (diskaddr_t)) + \
                (7 * sizeof (u_int32_t)) + \
                (8 * sizeof (char)) + \
                (1 * (sizeof (struct uuid)))))

#define    EFI_SIGNATURE    0x5452415020494645ULL

/* EFI Guid Partition Table Header -- little endian on-disk format */
typedef struct efi_gpt {
    u_int64_t    	efi_gpt_Signature;
    u_int32_t        	efi_gpt_Revision;
    u_int32_t        	efi_gpt_HeaderSize;
    u_int32_t        	efi_gpt_HeaderCRC32;
    u_int32_t        	efi_gpt_Reserved1;
    u_int64_t    	efi_gpt_MyLBA;
    u_int64_t    	efi_gpt_AlternateLBA;
    u_int64_t    	efi_gpt_FirstUsableLBA;
    u_int64_t    	efi_gpt_LastUsableLBA;
    struct uuid    	efi_gpt_DiskGUID;
    u_int64_t    	efi_gpt_PartitionEntryLBA;
    u_int32_t        	efi_gpt_NumberOfPartitionEntries;
    u_int32_t        	efi_gpt_SizeOfPartitionEntry;
    u_int32_t        	efi_gpt_PartitionEntryArrayCRC32;
    char        	efi_gpt_Reserved2[LEN_EFI_PAD];
} efi_gpt_t;

/* EFI Guid Partition Entry Attributes -- little endian format */
typedef struct efi_gpe_Attrs {
    u_int32_t    	PartitionAttrs        :16,
            		Reserved2        :16;
    u_int32_t    	Reserved1        :31,
            		RequiredPartition    :1;
} efi_gpe_Attrs_t;

/*
 * 6a96237f-1dd2-11b2-99a6-080020736631    V_UNASSIGNED (not used as such)
 * 6a82cb45-1dd2-11b2-99a6-080020736631    V_BOOT
 * 6a85cf4d-1dd2-11b2-99a6-080020736631    V_ROOT
 * 6a87c46f-1dd2-11b2-99a6-080020736631    V_SWAP
 * 6a898cc3-1dd2-11b2-99a6-080020736631    V_USR
 * 6a8b642b-1dd2-11b2-99a6-080020736631    V_BACKUP
 * 6a8d2ac7-1dd2-11b2-99a6-080020736631    V_STAND (not used)
 * 6a8ef2e9-1dd2-11b2-99a6-080020736631    V_VAR
 * 6a90ba39-1dd2-11b2-99a6-080020736631    V_HOME
 * 6a9283a5-1dd2-11b2-99a6-080020736631    V_ALTSCTR
 * 6a945a3b-1dd2-11b2-99a6-080020736631    V_CACHE
 */

#define    EFI_UNUSED    { 0x00000000, 0x0000, 0x0000, 0x00, 0x00, \
                { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } }
#define    EFI_RESV1    { 0x6a96237f, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_BOOT    { 0x6a82cb45, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_ROOT    { 0x6a85cf4d, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_SWAP    { 0x6a87c46f, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_USR        { 0x6a898cc3, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_BACKUP    { 0x6a8b642b, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_RESV2    { 0x6a8d2ac7, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_VAR        { 0x6a8ef2e9, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_HOME    { 0x6a90ba39, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_ALTSCTR    { 0x6a9283a5, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_RESERVED    { 0x6a945a3b, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_SYSTEM    { 0xC12A7328, 0xF81F, 0x11d2, 0xBA, 0x4B, \
                { 0x00, 0xA0, 0xC9, 0x3E, 0xC9, 0x3B } }
#define    EFI_LEGACY_MBR    { 0x024DEE41, 0x33E7, 0x11d3, 0x9D, 0x69, \
                { 0x00, 0x08, 0xC7, 0x81, 0xF3, 0x9F } }
#define    EFI_RESV3    { 0x6a9630d1, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_RESV4    { 0x6a980767, 0x1dd2, 0x11b2, 0x99, 0xa6, \
                { 0x08, 0x00, 0x20, 0x73, 0x66, 0x31 } }
#define    EFI_MSFT_RESV    { 0xE3C9E316, 0x0B5C, 0x4DB8, 0x81, 0x7D, \
                { 0xF9, 0x2D, 0xF0, 0x02, 0x15, 0xAE } }
#define    EFI_DELL_BASIC    { 0xebd0a0a2, 0xb9e5, 0x4433, 0x87, 0xc0, \
                { 0x68, 0xb6, 0xb7, 0x26, 0x99, 0xc7 } }
#define    EFI_DELL_RAID    { 0xa19d880f, 0x05fc, 0x4d3b, 0xa0, 0x06, \
                { 0x74, 0x3f, 0x0f, 0x84, 0x91, 0x1e } }
#define    EFI_DELL_SWAP    { 0x0657fd6d, 0xa4ab, 0x43c4, 0x84, 0xe5, \
                { 0x09, 0x33, 0xc8, 0x4b, 0x4f, 0x4f } }
#define    EFI_DELL_LVM    { 0xe6d6d379, 0xf507, 0x44c2, 0xa2, 0x3c, \
                { 0x23, 0x8f, 0x2a, 0x3d, 0xf9, 0x28 } }
#define    EFI_DELL_RESV    { 0x8da63339, 0x0007, 0x60c0, 0xc4, 0x36, \
                { 0x08, 0x3a, 0xc8, 0x23, 0x09, 0x08 } }
#define    EFI_AAPL_HFS    { 0x48465300, 0x0000, 0x11aa, 0xaa, 0x11, \
                { 0x00, 0x30, 0x65, 0x43, 0xec, 0xac } }
#define    EFI_AAPL_UFS    { 0x55465300, 0x0000, 0x11aa, 0xaa, 0x11, \
                { 0x00, 0x30, 0x65, 0x43, 0xec, 0xac } }

/* minimum # of bytes for partition table entires, per EFI spec */
#define    EFI_MIN_ARRAY_SIZE    (16 * 1024)

#define    EFI_PART_NAME_LEN    36

/* size of the "reserved" partition, in blocks */
#define    EFI_MIN_RESV_SIZE    (16 * 1024)

/* EFI Guid Partition Entry */
typedef struct efi_gpe {
    struct uuid    	efi_gpe_PartitionTypeGUID;
    struct uuid    	efi_gpe_UniquePartitionGUID;
    u_int64_t    	efi_gpe_StartingLBA;
    u_int64_t    	efi_gpe_EndingLBA;
    efi_gpe_Attrs_t    	efi_gpe_Attributes;
    u_int16_t    	efi_gpe_PartitionName[EFI_PART_NAME_LEN];
} efi_gpe_t;








#if 0

/*
 * passed to the useful (we hope) routines (efi_alloc_and_read and
 * efi_write) that take this VTOC-like struct.  These routines handle
 * converting this struct into the EFI struct, generate UUIDs and
 * checksums, and perform any necessary byte-swapping to the on-disk
 * format.
 */
/* Solaris library abstraction for EFI partitons */
typedef struct dk_part    {
    diskaddr_t    p_start;    /* starting LBA */
    diskaddr_t    p_size;        /* size in blocks */
    struct uuid    p_guid;        /* partion type GUID */
    ushort_t    p_tag;        /* converted to part'n type GUID */
    ushort_t    p_flag;        /* attributes */
    char        p_name[EFI_PART_NAME_LEN]; /* partition name */
    struct uuid    p_uguid;    /* unique partition GUID */
    u_int32_t        p_resv[8];    /* future use - set to zero */
} dk_part_t;

/* Solaris library abstraction for an EFI GPT */
#define    EFI_VERSION102        0x00010002
#define    EFI_VERSION100        0x00010000
#define    EFI_VERSION_CURRENT    EFI_VERSION100
typedef struct dk_gpt {
    u_int32_t        efi_version;    /* set to EFI_VERSION_CURRENT */
    u_int32_t        efi_nparts;    /* number of partitions below */
    u_int32_t        efi_part_size;    /* size of each partition entry */
                    /* efi_part_size is unused */
    u_int32_t        efi_lbasize;    /* size of block in bytes */
    diskaddr_t    efi_last_lba;    /* last block on the disk */
    diskaddr_t    efi_first_u_lba; /* first block after labels */
    diskaddr_t    efi_last_u_lba;    /* last block before backup labels */
    struct uuid    efi_disk_uguid;    /* unique disk GUID */
    u_int32_t        efi_flags;
    u_int32_t        efi_reserved1;    /* future use - set to zero */
    diskaddr_t    efi_altern_lba;    /* lba of alternate GPT header */
    u_int32_t        efi_reserved[12]; /* future use - set to zero */
    struct dk_part    efi_parts[1];    /* array of partitions */
} dk_gpt_t;

/* possible values for "efi_flags" */
#define    EFI_GPT_PRIMARY_CORRUPT    0x1    /* primary label corrupt */

/* the private ioctl between libefi and the driver */
typedef struct dk_efi {
    diskaddr_t     dki_lba;    /* starting block */
    len_t         dki_length;    /* length in bytes */
    union {
        efi_gpt_t     *_dki_data;
        u_int64_t    _dki_data_64;
    } dki_un;
#define    dki_data    dki_un._dki_data
#define    dki_data_64    dki_un._dki_data_64
} dk_efi_t;

struct partition64 {
    struct uuid    p_type;
    u_int32_t        p_partno;
    u_int32_t        p_resv1;
    diskaddr_t    p_start;
    diskaddr_t    p_size;
};

#endif // 0



#endif /* _SYS_EFI_PARTITION_H */