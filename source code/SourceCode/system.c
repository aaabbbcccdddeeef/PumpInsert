/*****************************************************************************
 *   system.c:  system module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/

#define __SYSTEM__

#include "include.h"
/*
unsigned char  tHigh_STR[]={"高电平"};
unsigned char  tLow_STR[]={"低电平"};
unsigned char  *tOptLevel_TABLE[]=
{
    tLow_STR,tHigh_STR, 
};
*/
void CSystemEventHandler(void)
{
    CMonitorOptEvent(g_u8DetectOptSelect);
    CBurnInEvent();
}

void CMonitorOptEvent(u8 OptSel)
{
    u32 TempValue=0;
    if(g_u8DetectOptStart)
    {
        switch(OptSel)
        {
            case 1:
                TempValue = GPIO0->FIOPIN & (1<<19);
                TempValue = TempValue>>19;
                break;
            case 2:
                TempValue = GPIO0->FIOPIN & (1<<20);
                TempValue = TempValue>>20;
                break;
            case 3:
                TempValue = GPIO0->FIOPIN & (1<<21);
                TempValue = TempValue>>21;
                break;
            case 4:
                TempValue = GPIO0->FIOPIN & (1<<22);
                TempValue = TempValue>>22;
                break;
            default:
                break;
        }
        if(g_u32OptLevel!=TempValue)
        {
            g_u32OptLevel=TempValue;
            if(g_u32OptLevel==0)
            {
                WriteString("            ", 200, 120, color_white, _FONT_SIZE_MAX,_TANSPERENT_OFF);
                WriteString("低电平", 200, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
            }
            else 
            {
                WriteString("            ", 200, 120, color_white, _FONT_SIZE_MAX,_TANSPERENT_OFF);
                WriteString("高电平", 200, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
            }
        }
    }

}
void CBurnInEvent(void)
{
    if(g_u8RunningPause==0)
    {

    PumpBurnIn(1, g_stUISetting.TestVol1);
    CDispFloatAt(++g_u32BurninCount,0,_LEVEL5_VALUE_2_x,_LEVEL5_VALUE_2_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);

        //PumpBurnIn(2, 100);
    }
}


