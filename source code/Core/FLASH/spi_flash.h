/*****************************************************************************
 *   spi_flash.c:  spi flash for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/

#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

/* Dummy byte */
#define SPI_DUMMY   0xFF

/*  SPI FLASH INSTRUCTIONS  */
#define _SPI_FLASH_WREN                         0x06
#define _SPI_FLASH_WRDI                         0x04
#define _SPI_FLASH_RDID                         0x9f
#define _SPI_FLASH_RDSR                         0x05
#define _SPI_FLASH_WRSR                         0x01
#define _SPI_FLASH_READ                         0x03
#define _SPI_FLASH_FAST_READ                      0x0b   
#define _SPI_FLASH_PP                         0x02
#define _SPI_FLASH_SE                         0xd8
#define _SPI_FLASH_BE                         0xc7
#define _SPI_FLASH_DP                         0xb9
#define _SPI_FLASH_RES                         0xab


extern void SPIFlashMasterInit(void);
extern void SPIFlash_WriteEn(u32 cs);
extern u8 SPIFlash_ReadWP(u32 cs);
extern void SPIFlash_CheckBusy(u32 cs);
extern void SPIFlash_WritePage(u32 cs,u8* pBuffer, u32 WritePage,u16 NumByteToWrite);
extern void SPIFlash_Read(u32 cs,u8* pBuffer, u32 ReadAddr, u16 NumByteToRead);
extern void SPIFlash_EraseSector(u32 cs,u32 SectorNum);
extern void SPIFlash_EraseBulk(u32 cs);
extern u32 SPIFlash_ReadID(u32 cs);
#endif
