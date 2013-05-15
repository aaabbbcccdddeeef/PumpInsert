/*----------------------------------------------------------------------------
 * Name:    pump.c
 * Purpose: MCB1700 Low level serial functions
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
 * Copyright (c) 2008 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/
#include <lpc17xx.h>
#include "type.h"
#include "pump.h"
#include "timer.h"
#include "math.h"
#include "systick.h"
#include "struct.h"
/********************************************************
                       加减速参数
********************************************************/
u8 nMaxEffClass = 0;  //最大可用台阶
#define _ResetPulseNum   4000 
#define _MaxStepCount(a)  g_stPumpSetting[a].StepNum//台阶数
#define _FullStepPerClass(a)   g_stPumpSetting[a].Step  //每个台阶的整步数 ,加速度
#define _nBackLash(a)   g_stPumpSetting[a].BackLash
#define _nStep2Pulse(a)   g_stPumpSetting[a].Step2Pulse
#define _nuL2Step(a)   g_stPumpSetting[a].uL2Step
#define _MinFreqFactor(a)   g_stPumpSetting[a].Freq[0]
#define _MaxFreqFactor(a)   (g_stPumpSetting[a].Freq[g_stPumpSetting[a].StepNum-1])
#define _StepMode(a)            g_stPumpSetting[a].StepMode
#define _OPTIC_OFF(a)                   (1-g_stOptSetting.OptShieldLevel[a])
#define _OPTIC_ON(a)                   g_stOptSetting.OptShieldLevel[a]

#define _STEP_H(a)      g_stPumpSetting[a].Freq


void PumpInit(void)
{
    GPIO0->FIODIR &= 0x00000000;
    GPIO0->FIODIR |= 0x07800fff;
    GPIO0->FIOSET |= 0x07800fff;

    //PumpSetEnable(2, _PUMP_ENABLE);
    //PumpSetLowPowerMode(2, _NORMAL_PWR);
}
void PumpSetEnable(u8 PumpSel, u32 enable)
{
    if(PumpSel == 1)
    {
        if(enable == _PUMP_ENABLE)
            GPIO0->FIOPIN &= ~(1 << 0);
        else if(enable == _PUMP_DISABLE)
            GPIO0->FIOPIN |= 1 << 0;
    }
    else if(PumpSel == 2)
    {
        if(enable == _PUMP_ENABLE)
            GPIO0->FIOPIN &= ~(1 << 4);
        else if(enable == _PUMP_DISABLE)
            GPIO0->FIOPIN |= 1 << 4;
    }
    else if(PumpSel == 3)
    {
        if(enable == _PUMP_ENABLE)
        {
            GPIO0->FIOPIN &= ~(1 << 0);
            GPIO0->FIOPIN &= ~(1 << 4);
        }
        else if(enable == _PUMP_DISABLE)
        {
            GPIO0->FIOPIN |= 1 << 0;
            GPIO0->FIOPIN |= 1 << 4;
        }
    }
}

void PumpSetDirection(u8 PumpSel, u32 dir)
{
    if(PumpSel == 1)
    {
        if(dir == _DIR_POS)
            GPIO0->FIOPIN &= ~(1 << 1);
        else if(dir == _DIR_NEG)
            GPIO0->FIOPIN |= 1 << 1;
    }
    else if(PumpSel == 2)
    {
        if(dir == _DIR_POS)
            GPIO0->FIOPIN &= ~(1 << 5);
        else if(dir == _DIR_NEG)
            GPIO0->FIOPIN |= 1 << 5;
    }
    else if(PumpSel == 3)
    {
        if(dir == _DIR_POS)
        {
            GPIO0->FIOPIN &= ~(1 << 1);
            GPIO0->FIOPIN &= ~(1 << 5);
        }
        else if(dir == _DIR_NEG)
        {
            GPIO0->FIOPIN |= 1 << 1;
            GPIO0->FIOPIN |= 1 << 5;
        }
    }
}

void PumpSetStepMode(u8 PumpSel, u32 SetBit)
{
    if(PumpSel == 1)
    {
        GPIO0->FIOPIN &= ~(3 << 23);
        GPIO0->FIOPIN |= SetBit << 23;
    }
    else if(PumpSel == 2)
    {
        GPIO0->FIOPIN &= ~(3 << 25);
        GPIO0->FIOPIN |= SetBit << 25;
    }
}

void PumpSetValveState(u8 ValveSel, u32 SetBit)
{
    switch(ValveSel)
    {
    case 1:
        if(SetBit == _VALVE_OFF)
            GPIO0->FIOPIN &= ~(1 << 8);
        else if(SetBit == _VALVE_ON)
            GPIO0->FIOPIN |= 1 << 8;
        break;
    case 2:
        if(SetBit == _VALVE_OFF)
            GPIO0->FIOPIN &= ~(1 << 9);
        else if(SetBit == _VALVE_ON)
            GPIO0->FIOPIN |= 1 << 9;
        break;
    case 3:
        if(SetBit == _VALVE_OFF)
            GPIO0->FIOPIN &= ~(1 << 10);
        else if(SetBit == _VALVE_ON)
            GPIO0->FIOPIN |= 1 << 10;
        break;
    case 4:
        if(SetBit == _VALVE_OFF)
            GPIO0->FIOPIN &= ~(1 << 11);
        else if(SetBit == _VALVE_ON)
            GPIO0->FIOPIN |= 1 << 11;
        break;
    default:
        break;
    }
}
void PumpSetClkLow(u8 PumpSel)
{
    if(PumpSel == 1)
    {
        GPIO0->FIOPIN &= ~(1 << 2);
    }
    else if(PumpSel == 2)
    {
        GPIO0->FIOPIN &= ~(1 << 6);
    }
    else if(PumpSel == 3)
    {
        GPIO0->FIOPIN &= ~(1 << 2);
        GPIO0->FIOPIN &= ~(1 << 6);
    }
}
void PumpSetLowPowerMode(u8 PumpSel, u8 Mode)
{
    if(PumpSel == 1)
    {
        if(Mode == _NORMAL_PWR)
            GPIO0->FIOPIN &= ~(1 << 3);
        else if(Mode == _LOW_PWR)
            GPIO0->FIOPIN |= 1 << 3;
    }
    else if(PumpSel == 2)
    {
        if(Mode == _NORMAL_PWR)
            GPIO0->FIOPIN &= ~(1 << 7);
        else if(Mode == _LOW_PWR)
            GPIO0->FIOPIN |= 1 << 7;
    }
}
u32 PumpGetOpticStatus(u8 OptSel)
{
    u32 TempValue = 0;
    switch(OptSel)
    {
    case 1:
        TempValue = GPIO0->FIOPIN & (1 << 19);
        TempValue = TempValue >> 19;
        break;
    case 2:
        TempValue = GPIO0->FIOPIN & (1 << 20);
        TempValue = TempValue >> 20;
        break;
    case 3:
        TempValue = GPIO0->FIOPIN & (1 << 21);
        TempValue = TempValue >> 21;
        break;
    case 4:
        TempValue = GPIO0->FIOPIN & (1 << 22);
        TempValue = TempValue >> 22;
        break;
    default:
        break;
    }
    return TempValue;
}


void PumpNormal(u8 PumpSel, u8 direction, u16 cntRun, u16 Freq) //指定方向以某个固定倍频数运动
{
    if (cntRun <= 0) return;
    init_timer( (PumpSel-1), TIME_10MS_INTERVAL / Freq);
    PumpSetEnable(PumpSel, _PUMP_ENABLE);
    PumpSetLowPowerMode(PumpSel, _NORMAL_PWR);
    PumpSetStepMode(PumpSel, _StepMode(PumpSel-1));//	工作方式控制 1=HALF,0=FULL
    PumpSetDirection(PumpSel, 1 - direction);
    PumpSetClkLow(PumpSel);// 脉冲控制位

    PumpCount[PumpSel - 1] = cntRun;
    enable_timer((PumpSel-1));
    while(PumpCount[PumpSel - 1]);

    disable_timer((PumpSel-1));
    PumpSetLowPowerMode(PumpSel, _LOW_PWR);
    PumpSetEnable(PumpSel, _PUMP_DISABLE);
}
void PumpStop(u8 PumpSel, u8 direction)
{
    PumpNormal(PumpSel, direction, 5 * _nStep2Pulse(PumpSel-1), _MaxFreqFactor(PumpSel-1)); //5个整步后停止
}
void PumpDetect(u8 PumpSel, u8 direction, u16 cntRun, u16 Freq) //以某个固定倍频数运动，并检测光耦
{
    if (cntRun <= 0)
        return;
    init_timer((PumpSel-1), TIME_10MS_INTERVAL / Freq );

    PumpSetEnable(PumpSel, _PUMP_ENABLE);
    PumpSetLowPowerMode(PumpSel, _NORMAL_PWR);
    PumpSetStepMode(PumpSel, _StepMode(PumpSel-1));//	工作方式控制 1=HALF,0=FULL
    PumpSetDirection(PumpSel, 1 - direction);
    PumpSetClkLow(PumpSel);// 脉冲控制位

    PumpCount[PumpSel - 1] = cntRun;
    enable_timer((PumpSel-1));
    while(PumpCount[PumpSel - 1])
    {
        if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))   //idex光耦输出不遮挡灯不亮
        {
            //PumpStop(direction);//这里肯定是核心，急停
            break;
        }
    }

    disable_timer((PumpSel-1));
    PumpSetLowPowerMode(PumpSel, _LOW_PWR);
    PumpSetEnable(PumpSel, _PUMP_DISABLE);
}
u16 PumpStartStopSteps(u8 PumpSel,u8 StepNum)
{
    u8 i=0;
    u16 TotalSteps=0;
    
    for(i=0;i<StepNum;i++)
        TotalSteps+=g_stPumpSetting[PumpSel-1].Step[i];

    return (TotalSteps*2);
}
u16 PumpGetMiddleStepIndex(u8 PumpSel, u16 cntRun)
{
    u8 i=0;
    u16 sum=0;

    cntRun=ceil(cntRun * 1.0/(2* _nStep2Pulse(PumpSel-1)));

    for(i=0;i<g_stPumpSetting[PumpSel-1].StepNum;i++)
    {
        sum+=g_stPumpSetting[PumpSel-1].Step[i];
        if(cntRun<=sum)
            break;
    }

    return i;

}
void PumpDetectRun(u8 PumpSel, u8 direction, u16 cntRun) //检测光耦信号，按方向和脉冲数运行
{
    u8 i;
    if (cntRun <= 0) return;

    if (cntRun > PumpStartStopSteps(PumpSel,_MaxStepCount(PumpSel-1)) * _nStep2Pulse(PumpSel-1)) //超过加减速脉冲数
    {
        nMaxEffClass = _MaxStepCount(PumpSel-1);
        for(i = 0; i < nMaxEffClass; i++)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))	 break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i]);
        }

        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpDetect(PumpSel, direction, cntRun - PumpStartStopSteps(PumpSel,_MaxStepCount(PumpSel-1)) * _nStep2Pulse(PumpSel-1), _STEP_H(PumpSel-1)[_MaxStepCount(PumpSel-1)-1]);

        for(i = _MaxStepCount(PumpSel-1); i >0; i--)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))
                break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i-1] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i-1]);
        }

    }
    else if (cntRun <= 2 * 1 * _FullStepPerClass(PumpSel-1)[0] * _nStep2Pulse(PumpSel-1)) //不超过第一个台阶
    {
        nMaxEffClass = 1;
        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpDetect(PumpSel, direction, cntRun, _STEP_H(PumpSel-1)[0]);
    }
    else
    {
        nMaxEffClass = PumpGetMiddleStepIndex(PumpSel, cntRun);
        for(i = 0; i < nMaxEffClass; i++)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))
                break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i]);
        }
        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpDetect(PumpSel, direction, cntRun - PumpStartStopSteps(PumpSel,nMaxEffClass) * _nStep2Pulse(PumpSel-1), _STEP_H(PumpSel-1)[nMaxEffClass]);
        for(i = _MaxStepCount(PumpSel-1); i >0; i--)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))
                break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i-1] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i-1]);
        }

    }

}

void PumpFreeRun(u8 PumpSel, u8 direction, u16 cntRun) //不管光耦信号，按方向和脉冲数运行
{

    u16 i;
    if (cntRun <= 0) return;
    if (cntRun > PumpStartStopSteps(PumpSel,_MaxStepCount(PumpSel-1)) * _nStep2Pulse(PumpSel-1)) //超过加减速脉冲数
    {
        nMaxEffClass = _MaxStepCount(PumpSel-1);
        for(i = 0; i < nMaxEffClass; i++)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i]);
        PumpNormal(PumpSel, direction, cntRun - PumpStartStopSteps(PumpSel,_MaxStepCount(PumpSel-1)) * _nStep2Pulse(PumpSel-1), _STEP_H(PumpSel-1)[_MaxStepCount(PumpSel-1)-1]);
        for(i = _MaxStepCount(PumpSel-1); i >0; i--)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i-1] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i-1]);
    }
    else if (cntRun <= 2 * 1 * _FullStepPerClass(PumpSel-1)[0] * _nStep2Pulse(PumpSel-1)) //不超过第一个台阶
    {
        nMaxEffClass = 1;
        PumpNormal(PumpSel, direction, cntRun, _STEP_H(PumpSel-1)[0]);
    }
    else
    {
        nMaxEffClass = PumpGetMiddleStepIndex(PumpSel, cntRun);
        for(i = 0; i < nMaxEffClass; i++)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i]);
        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpNormal(PumpSel, direction, cntRun - PumpStartStopSteps(PumpSel,nMaxEffClass) * _nStep2Pulse(PumpSel-1), _STEP_H(PumpSel-1)[nMaxEffClass]);
        for(i = _MaxStepCount(PumpSel-1); i >0; i--)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1)[i-1] * _nStep2Pulse(PumpSel-1) , _STEP_H(PumpSel-1)[i-1]);
    }

}

void PumpIn( u8 PumpSel, u16  cntRun)
{
    if (cntRun <= 0) return;
    PumpFreeRun(PumpSel, 0, cntRun);
}

void PumpOut(u8 PumpSel,  u16 cntRun)
{
    if (cntRun <= 0) return;
    PumpFreeRun(PumpSel, 1, cntRun);

}

void PumpReset(u8 PumpSel )
{
    u8 maxTry = 0;

    //其他平台reset

    while(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1) && maxTry < 21)
    {
        PumpDetectRun(PumpSel, 1, 200);
        Delay10ms(50);
        maxTry++;
    }
    //PumpIn(uint cntRun)(MaxPulseNum-1000);Delay50us(65000);//一般泵
    PumpIn(PumpSel, _ResetPulseNum);
    Delay10ms(50);//pul泵加上dt电机
    PumpDetectRun(PumpSel, 1, _ResetPulseNum + _nBackLash(PumpSel-1)); //Delay50us(65000);

}

void PumpBurnIn(u8 PumpSel, u8 VolTest)
{
/*
    PumpReset(PumpSel);
    Delay10ms(100);
    //DelayMeasure(6); //1，复位称重
    PumpIn(PumpSel, 1000);
    Delay10ms(100); //吸入消背隙
    //DelayMeasure(7);//2，吸入背隙称重
    PumpIn(PumpSel, VolTest * _nuL2Step(PumpSel-1) * _nStep2Pulse(PumpSel-1));
    Delay10ms(100); //无背隙吸入
    //DelayMeasure(6);//3，吸入称重
    PumpOut(PumpSel, _nBackLash(PumpSel-1));
    Delay10ms(100); //排出消背隙
    //DelayMeasure(6); //4，排出背隙称重
    PumpOut(PumpSel, VolTest * _nuL2Step(PumpSel-1) * _nStep2Pulse(PumpSel-1));
    Delay10ms(100); //无背隙排出
    Delay10ms(100); //5，排液称重
    */
    PumpFreeRun(1, 0, 64000);
 Delay10ms(1);
 PumpFreeRun(1, 1, 64000);
 Delay10ms(1);

}
/*-------------------------end of line--------------------------------*/




