/******************************************************************************/
/* menufunc.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define _LEVEL4_TITLE_x     15
#define _LEVEL4_TITLE_y     18

#define _LEVEL5_ITEM_1_x     15
#define _LEVEL5_ITEM_1_y     55

#define _LEVEL5_ITEM_2_x     15
#define _LEVEL5_ITEM_2_y     80

#define _LEVEL5_VALUE_1_x     120
#define _LEVEL5_VALUE_1_y     55

#define _LEVEL5_VALUE_2_x     120
#define _LEVEL5_VALUE_2_y     80

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
extern void CDispFloatAt(float f, char Fract,u16 x, u16 y, u16 Color, u8 Size, u8 transperent);
extern void CDrawButton(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, u8 Row, u8 col);

extern void CDrawInputMenu(void);
extern void CHideInputMenu(void);
extern void CGetInputBit(void);
extern void CPopUpInputResult(void);
extern void CInputBackSpace(void);
extern void CDrawResultCurve(void);
extern void CDrawBurninStatus(void);

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
extern void CDebugPump1SetValue(void);

extern void CDebugPump2PageStyle(void);
extern void CDebugPump2RunPositive(void);
extern void CDebugPump2RunNegative(void);
extern void CDebugValve1PageStyle(void);
extern void CDebugValve2PageStyle(void);
extern void CDebugValve3PageStyle(void);
extern void CDebugValve4PageStyle(void);
extern void CTestPump1Reset(void);
extern void CTestPump2Reset(void);
extern void CTestValve1Reset(void);
extern void CTestValve2Reset(void);
extern void CTestValve3Reset(void);
extern void CTestValve4Reset(void);
extern void CTestBurnInPageStyle(void);
extern void CTestBurninSetVol(void);
extern void CTestBruninContinue(void);

extern void CTestBurninStatusPageStyle(void);

extern void CTestWaterWeighPageStyle(void);
extern void CTestBacklashPageStyle(void);
extern void CTestLeakagePageStyle(void);
extern void CSettingAccelerationPageStyle(void);
extern void CSettingBalancePageStyle(void);
extern void CSettingMicrometerPageStyle(void);
extern void CSettingOpt1PageStyle(void);
extern void CSettingOpt2PageStyle(void);
extern void CSettingOpt3PageStyle(void);
extern void CSettingOpt4PageStyle(void);
extern void CSettingOpt1ShieldValue(void);
extern void CSettingOpt2ShieldValue(void);
extern void CSettingOpt3ShieldValue(void);
extern void CSettingOpt4ShieldValue(void);
extern void CSettingDivider1PageStyle(void);
extern void CSettingDivider2PageStyle(void);
extern void CSettingDivider1Value(void);
extern void CSettingDivider2Value(void);
#endif











//******************************end of line***************************************


