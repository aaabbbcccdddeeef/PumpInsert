/*----------------------------------------------------------------------------
 * Name:    Serial.h
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

#ifndef __SERIAL_H
#define __SERIAL_H

#define _FRM_START          0
#define _FRM_ADDRESS      1
#define _FRM_TYPE             2
#define _FRM_OPRATE         3
#define _FRM_DATA           4
#define _FRM_CKS              8



extern void SER_init      (int uart);
extern int  SER_getChar   (int uart);
extern int  SER_getChar_nb(int uart);
extern int  SER_putChar   (int uart, int c);
extern void SER_putString (int uart, unsigned char *s);

#endif
