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
    CFlow1Event();
    CFlow2Event();
	CPump1LostEvent();
	CPump2LostEvent();
    CHTEvent();
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
    if(g_u8RunningStart1==1)
    {

    //PumpBurnIn(1, g_stUISetting.TestVol1);
    //CDispFloatAt(++g_u32BurninCount1,0,_LEVEL5_VALUE_2_x,_LEVEL5_VALUE_2_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);

        //PumpBurnIn(2, 100);
    }
}
void CFlow1Event(void)
{
    if(g_u8RunningStart1==1)
    {
        if((PumpCount[0]==0)&&(g_u8FlowWaitOver1==1)&&(g_u8RunningIndex1<g_u8FlowCount1))
        {
            if(g_u8RunningIndex1%2==0)
            {
                TIM0 ->MR0 = TIME_10MS_INTERVAL/g_u16FreqFlow1[g_u8RunningIndex1/2];
                reset_timer(0);
                enable_timer(0);
                if(g_u8RunningIndex1==0)
                {
                    PumpSetEnable(1, _PUMP_ENABLE);
                    PumpSetLowPowerMode(1, _NORMAL_PWR);
                    PumpSetStepMode(1, g_stPumpSetting[0].StepMode);
                    PumpSetDirection(1, g_u8DirectionFlow1[g_u8RunningIndex1/2]);
                    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
                    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
                }
                PumpCount[0]= g_u32RunningFlow1[g_u8RunningIndex1/2];
            }
            else
            {
                g_u8FlowWaitOver1=0;
                g_u32FlowWaitCount1 = g_u32WaitFlow1[(g_u8RunningIndex1-1)/2];
                if(g_u32FlowWaitCount1==0)
                    g_u8FlowWaitOver1=1;
                g_u8RunningIndex1++;
            }

        }
        else if((g_u8RunningIndex1==g_u8FlowCount1)&&(g_u8FlowWaitOver1==1))
        {
            //g_u8RunningIndex1=0;
            //g_u8RunningStart1=0;
            PumpSetEnable(1, _PUMP_DISABLE);
            PumpSetLowPowerMode(1, _LOW_PWR);
            if(++g_u8SchemeIndex1==LenOfScheme1)
            {
                g_u8SchemeIndex1=0;
	            CDispFloatAt(++g_u32BurninCount1,0,_LEVEL5_VALUE_2_x,_LEVEL5_VALUE_2_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);
				CDispFloatAt(g_u32LostCount1,0,20,120,color_black, _FONT_SIZE_MAX,_TANSPERENT_OFF);
				g_uiPump1LostTimeout=300;
				g_u8Pump1Lost=0;
				g_u8Lost1SaveFlag=0;

            }
            disable_timer(0);
            Pump1ReloadScheme(g_u8SchemeIndex1);

            //g_u8FlowCount1=0;
        }
    }
}
void CFlow2Event(void)
{
    if(g_u8RunningStart2==1)
    {
        if((PumpCount[1]==0)&&(g_u8FlowWaitOver2==1)&&(g_u8RunningIndex2<g_u8FlowCount2))
        {
            if(g_u8RunningIndex2%2==0)
            {
                TIM1 ->MR0 = TIME_10MS_INTERVAL/g_u16FreqFlow2[g_u8RunningIndex2/2];
                reset_timer(1);
                enable_timer(1);
                if(g_u8RunningIndex2==0)
                {
                    PumpSetEnable(2, _PUMP_ENABLE);
                    PumpSetLowPowerMode(2, _NORMAL_PWR);
                    PumpSetStepMode(2, g_stPumpSetting[1].StepMode);
                    PumpSetDirection(2, g_u8DirectionFlow2[g_u8RunningIndex2/2]);
                    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
                    __nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();__nop();
                }
                PumpCount[1]= g_u32RunningFlow2[g_u8RunningIndex2/2];
            }
            else
            {
                g_u8FlowWaitOver2=0;
                g_u32FlowWaitCount2 = g_u32WaitFlow2[(g_u8RunningIndex2-1)/2];
                if(g_u32FlowWaitCount2==0)
                    g_u8FlowWaitOver2=1;
                g_u8RunningIndex2++;
            }

        }
        else if((g_u8RunningIndex2==g_u8FlowCount2)&&(g_u8FlowWaitOver2==1))
        {
            //g_u8RunningIndex2=0;
            //g_u8RunningStart2=0;
            //g_u8FlowCount2=0;
            PumpSetEnable(2, _PUMP_DISABLE);
            PumpSetLowPowerMode(2, _LOW_PWR);
            if(++g_u8SchemeIndex2==LenOfScheme2)
            {
                g_u8SchemeIndex2=0;
	            CDispFloatAt(++g_u32BurninCount2,0,_LEVEL5_VALUE_3_x,_LEVEL5_VALUE_3_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);
				CDispFloatAt(g_u32LostCount2,0,20,160,color_black, _FONT_SIZE_MAX,_TANSPERENT_OFF);
				g_uiPump2LostTimeout=500;
				g_u8Pump2Lost=0;
				g_u8Lost2SaveFlag=0;

            }
            disable_timer(1);
            Pump2ReloadScheme(g_u8SchemeIndex2);
        }
    }
}
void CPump1LostEvent(void)
{
	if((g_u8Lost1SaveFlag==0)&&(g_u8Pump1Lost==1))
	{
		g_u8Lost1SaveFlag=1;
		g_u32LostCount1++;
	}
}
void CPump2LostEvent(void)
{
	if((g_u8Lost2SaveFlag==0)&&(g_u8Pump2Lost==1))
	{
		g_u8Lost2SaveFlag=1;
		g_u32LostCount2++;
	}
}
void CHTEvent(void)
{
    u16 ad_H=0;
    u16 ad_T=0;
    u32 TempValue=0;
    float Hvalue=0;
    float Tvalue=0;
    u8 SampleDone=0;
    

    
    if((g_u8HTTestStart==1)&&(g_uiHTsampleCounter==0))
    {
        if(g_u16HTnumber==10)
        {
            g_u16HTnumber=0;
            SampleDone=1;
        }
        
        TempValue = ADC45_Get();
        g_u16Hvalues[g_u16HTnumber++] = TempValue>>16;
        g_u16Tvalues[g_u16HTnumber++] = TempValue&0x0000ffff;

        g_uiHTsampleCounter = 50;
    }

    if(SampleDone==1)
    {
        ad_H = CSystemMedianFilter(10,&g_u16Hvalues[0]);
        ad_T = CSystemMedianFilter(10,&g_u16Tvalues[0]);
        Hvalue = (float)ad_H*3.3/4095/0.03;
        Tvalue = (float)ad_T*3.3/4095/0.01;
        CDispFloatAt(Hvalue, 1, 120, 140, color_black, _FONT_SIZE_NORMAL, _TANSPERENT_OFF);
        CDispFloatAt(Tvalue, 1, 260, 140, color_black, _FONT_SIZE_NORMAL, _TANSPERENT_OFF);
    }
    
}

