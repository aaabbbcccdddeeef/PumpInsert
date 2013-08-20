/******************************************************************************/
/* HT.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define _Humidity_obj		82
#define _Humidity_offset	0.5

#ifdef __HT_H__

u16 g_u16HumResult=0;
u8 g_u8HumDirect=0;
float hobj=70;
#else
extern u16 g_u16HumResult;
extern u8 g_u8HumDirect;
extern float hobj;


extern u8 HumidityMonitor(float cur_H);
#endif
 
//****************************END OF LINE*************************************//
