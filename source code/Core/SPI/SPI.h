/*----------------------------------------------------------------------------
 * Name:    SPI.h
 * Purpose: MCB1700 Low level serial definitions
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef __SPI_H
#define __SPI_H

extern void spi_init (void);
extern U8   spi_send (U8 outb);
extern void spi_ss (U32 cs, U32 ss);
extern void spi_hi_speed (BOOL on);
extern void spi_command (U8 *cmd, U8 *tbuf, U8 *rbuf, U32 sz);

#endif

