/******************************************************************************/
/* menufunc.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


#ifdef __MENUFUNC__

#else
extern void CNull(void);
extern void CNull_u8(u8 a);
extern  void CDrawSelPicture(void);
extern void CDrawUnselPicture(u8 Index);
extern void CDrawUnselMenuLevel1(u8 Index);
extern void CDrawUnselMenuLevel2(u8 Index);
extern void CDrawSelInputPicture(void);
extern void CDrawUnselInputPicture(u8 Index);
extern void CDrawMainPage(void);
extern void CDrawNextPage(void);
extern void CDrawPageLevel4(void);
extern void CDrawPageLevel5(void);

extern void CDrawPrevPage(void);
extern void CDrawPrevPage5(void);

extern void CDrawInputMenu(void);
extern void CHideInputMenu(void);
extern void CGetInputBit(void);
extern void CPopUpInputResult(void);
extern void CInputBackSpace(void);
extern void CDrawResultCurve(void);
extern void CDebugOpt1Start(void);
extern void CDebugOpt1PageStyle(void);
extern void CDebugOpt1Stop(void);
extern void CDebugOpt2Start(void);
extern void CDebugOpt2PageStyle(void);
extern void CDebugOpt2Stop(void);
extern void CDebugOpt3Start(void);
extern void CDebugOpt3PageStyle(void);
extern void CDebugOpt3Stop(void);
extern void CDebugOpt4Start(void);
extern void CDebugOpt4PageStyle(void);
extern void CDebugOpt4Stop(void);
extern void CDebugPump1PageStyle(void);
extern void CDebugPump1RunPositive(void);
extern void CDebugPump1RunNegative(void);
extern void CDebugPump2PageStyle(void);
extern void CDebugPump2RunPositive(void);
extern void CDebugPump2RunNegative(void);
#endif











//******************************end of line***************************************


