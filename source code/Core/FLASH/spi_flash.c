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
//32M bits, 64 bank, 256 page, 256 byte
/* Includes ------------------------------------------------------------------*/
#include "lpc17xx.h"
#include "define.h"
#include "SPI.h"
#include "spi_flash.h"
#include "main.h"
#include "systick.h"



void SPIFlashMasterInit(void)
{
    spi_init();
    spi_ss(_FLASH_NUM0,1);
    spi_ss(_FLASH_NUM1,1);
    spi_send(SPI_DUMMY);
    Delay10ms(5);
}
void SPIFlash_CheckBusy(u32 cs)
{
    u8 rvalue = 0x00;
  spi_ss(cs,0);  
    do
    {
        rvalue = spi_send(_SPI_FLASH_RDSR);
    }while(rvalue&0x01);
  spi_ss(cs,1);  
}
void SPIFlash_WriteEn(u32 cs)
{
    spi_ss(cs,0);
    spi_send(_SPI_FLASH_WREN);
    spi_ss(cs,1);
}
void SPIFlash_WritePage(u32 cs,u8* pBuffer, u32 WritePage, u16 NumByteToWrite)
{
    int i=0;
    
    /* Enable the write access to the FLASH */
    SPIFlash_WriteEn(cs);

    /* Select the FLASH: Chip Select low */
    spi_ss(cs,0);
    /* Send "Write to Memory " instruction */
    spi_send(_SPI_FLASH_PP);
    /* Send WriteAddr high nibble address byte to write to */
    spi_send((WritePage & 0xFF0000) >> 16);
    /* Send WriteAddr medium nibble address byte to write to */
    spi_send((WritePage & 0xFF00) >> 8);
    /* Send WriteAddr low nibble address byte to write to */
    spi_send(WritePage & 0xFF);

    /* while there is data to be written on the FLASH */
    for(i=0;i<NumByteToWrite;i++)
    {
        /* Send the current byte */
        spi_send(*pBuffer);
        /* Point on the next byte to be written */
        pBuffer++;
    }

    /* Deselect the FLASH: Chip Select high */
    spi_ss(cs,1);

    /* Wait the end of Flash writing */
    SPIFlash_CheckBusy(cs);
}

void SPIFlash_Read(u32 cs,u8* pBuffer, u32 ReadAddr, u16 NumByteToRead)
{
    int i=0;
    /* Select the FLASH: Chip Select low */
    spi_ss(cs,0);

    /* Send "Read from Memory " instruction */
    spi_send(_SPI_FLASH_READ);

    /* Send the 24-bit address of the address to read from -----------------------*/
    /* Send ReadAddr high nibble address byte */
    spi_send((ReadAddr & 0xFF0000) >> 16);
    /* Send ReadAddr medium nibble address byte */
    spi_send((ReadAddr& 0xFF00) >> 8);
    /* Send ReadAddr low nibble address byte */
    spi_send(ReadAddr & 0xFF);

    for(i=0;i<NumByteToRead;i++)
    {
        *pBuffer = spi_send(SPI_DUMMY);
        pBuffer++;
    }

    /* Deselect the FLASH: Chip Select high */
    spi_ss(cs,1);
}

void SPIFlash_EraseSector(u32 cs,u32 SectorNum)
{
  /* Send write enable instruction */
  SPIFlash_WriteEn(cs);

  /* Sector Erase */
  /* Select the FLASH: Chip Select low */
  spi_ss(cs,0);
  /* Send Sector Erase instruction */
  spi_send(_SPI_FLASH_SE);
  /* Send SectorAddr high nibble address byte */
  spi_send((SectorNum & 0xFF0000) >> 16);
  /* Send SectorAddr medium nibble address byte */
  spi_send((SectorNum & 0xFF00) >> 8);
  /* Send SectorAddr low nibble address byte */
  spi_send(SectorNum & 0xFF);
  /* Deselect the FLASH: Chip Select high */
  spi_ss(cs,1);

  /* Wait the end of Flash writing */
  SPIFlash_CheckBusy(cs);
}
void SPIFlash_EraseBulk(u32 cs)
{
  /* Send write enable instruction */
  SPIFlash_WriteEn(cs);

  /* Bulk Erase */
  /* Select the FLASH: Chip Select low */
  spi_ss(cs,0);
  /* Send Bulk Erase instruction  */
  spi_send(_SPI_FLASH_BE);
  /* Deselect the FLASH: Chip Select high */
  spi_ss(cs,1);

  /* Wait the end of Flash writing */
  SPIFlash_CheckBusy(cs);
}
u32 SPIFlash_ReadID(u32 cs)
{
  u32 Temp = 0, Temp0 = 0, Temp1 = 0, Temp2 = 0;

  /* Select the FLASH: Chip Select low */
  spi_ss(cs,0);

  /* Send "RDID " instruction */
  spi_send(_SPI_FLASH_RDID);

  /* Read a byte from the FLASH */
  Temp0 = spi_send(SPI_DUMMY);

  /* Read a byte from the FLASH */
  Temp1 = spi_send(SPI_DUMMY);

  /* Read a byte from the FLASH */
  Temp2 = spi_send(SPI_DUMMY);

  /* Deselect the FLASH: Chip Select high */
  spi_ss(cs,1);

  Temp = (Temp0 << 16) | (Temp1 << 8) | Temp2;

  return Temp;
}
u8 SPIFlash_ReadWP(u32 cs)
{  
    u8 Data;
    
    /* Select the FLASH: Chip Select low */
    spi_ss(cs,0);

    /* Send "RDID " instruction */
    spi_send(_SPI_FLASH_RDSR);

    /* Read a byte from the FLASH */
    Data = spi_send(SPI_DUMMY);
    
    /* Deselect the FLASH: Chip Select high */
    spi_ss(cs,1);

    return Data;
}


