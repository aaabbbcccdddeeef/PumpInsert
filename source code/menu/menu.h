/******************************************************************************/
/* menu.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/



#ifdef __MENU__
u8 g_u8ActiveItem=0;
const unsigned int BacklightOffTime[]={1000,2000,3000,6000,12000,30000};//unit:10ms
const unsigned long AutoPowerOffTime[]={6000,12000,30000,60000,180000,360000};//unit:10ms
const unsigned char PageStackStartPoint[]={0,0,7,15};
const unsigned char PageStackMaxNum[]={0,7,8,8};
#else
extern const unsigned int BacklightOffTime[];
extern const unsigned long AutoPowerOffTime[];
extern const unsigned char PageStackStartPoint[];
extern const unsigned char PageStackMaxNum[];
extern void CUIHandler(void);
#endif
//*******************************END OF LINE***********************************//

