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
                       �Ӽ��ٲ���
********************************************************/
u8 nMaxEffClass = 0;  //������̨��
#define _ResetPulseNum   4000 
#define _MaxStepCount(a)  g_stPumpSetting[a].MaxStepCount//̨����
#define _FullStepPerClass(a)   g_stPumpSetting[a].FullStepPerClass  //ÿ��̨�׵������� ,���ٶ�
#define _nBackLash(a)   g_stPumpSetting[a].nBackLash
#define _nStep2Pulse(a)   g_stPumpSetting[a].nStep2Pulse
#define _nuL2Step(a)   g_stPumpSetting[a].nuL2Step
#define _MinFreqFactor(a)   g_stPumpSetting[a].MinFreqFactor
#define _MaxFreqFactor(a)   g_stPumpSetting[a].MaxFreqFactor
#define _OPTIC_OFF(a)                   (1-g_stOptSetting[a].OptShieldLevel)
#define _OPTIC_ON(a)                   g_stOptSetting[a].OptShieldLevel

#define _STEP_H(a)    ((g_stPumpSetting[a].MaxFreqFactor-g_stPumpSetting[a].MinFreqFactor)/g_stPumpSetting[a].MaxStepCount)


void PumpInit(void)
{
    GPIO0->FIODIR &= 0x00000000;
    GPIO0->FIODIR |= 0x07800fff;
    GPIO0->FIOSET |= 0x07800fff;
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


void PumpNormal(u8 PumpSel, u8 direction, u16 cntRun, u16 Freq) //ָ��������ĳ���̶���Ƶ���˶�
{
    if (cntRun <= 0) return;
    init_timer( 1, TIME_10MS_INTERVAL / Freq);
    enable_timer(1);
    PumpSetEnable(PumpSel, _PUMP_ENABLE);
    PumpSetLowPowerMode(PumpSel, _NORMAL_PWR);
    PumpSetStepMode(PumpSel, 2);//	������ʽ���� 1=HALF,0=FULL
    PumpSetDirection(PumpSel, 1 - direction);
    PumpSetClkLow(PumpSel);// �������λ

    PumpNum[PumpSel - 1] = cntRun;
    while(PumpNum[PumpSel - 1]);

    disable_timer(1);
    PumpSetLowPowerMode(PumpSel, _LOW_PWR);
    PumpSetEnable(PumpSel, _PUMP_DISABLE);
}
void PumpStop(u8 PumpSel, u8 direction)
{
    PumpNormal(PumpSel, direction, 5 * _nStep2Pulse(PumpSel-1), _MaxFreqFactor(PumpSel-1)); //5��������ֹͣ
}
void PumpDetect(u8 PumpSel, u8 direction, u16 cntRun, u16 Freq) //��ĳ���̶���Ƶ���˶�����������
{
    if (cntRun <= 0)
        return;
    init_timer(1, TIME_10MS_INTERVAL / Freq );
    enable_timer(1);

    PumpSetEnable(PumpSel, _PUMP_ENABLE);
    PumpSetLowPowerMode(PumpSel, _NORMAL_PWR);
    PumpSetStepMode(PumpSel, 2);//	������ʽ���� 1=HALF,0=FULL
    PumpSetDirection(PumpSel, 1 - direction);
    PumpSetClkLow(PumpSel);// �������λ

    PumpNum[PumpSel - 1] = cntRun;
    while(PumpNum[PumpSel - 1])
    {
        if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))   //idex����������ڵ��Ʋ���
        {
            //PumpStop(direction);//����϶��Ǻ��ģ���ͣ
            break;
        }
    }

    disable_timer(1);
    PumpSetLowPowerMode(PumpSel, _LOW_PWR);
    PumpSetEnable(PumpSel, _PUMP_DISABLE);
}

void PumpDetectRun(u8 PumpSel, u8 direction, u16 cntRun) //�������źţ������������������
{
    u8 i;
    if (cntRun <= 0) return;

    if (cntRun > 2 * _MaxStepCount(PumpSel-1) * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1)) //�����Ӽ���������
    {
        nMaxEffClass = _MaxStepCount(PumpSel-1);
        for(i = 0; i < nMaxEffClass; i++)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))	 break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MinFreqFactor(PumpSel-1) + (i * _STEP_H(PumpSel-1)));
        }

        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpDetect(PumpSel, direction, cntRun - 2 * nMaxEffClass * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1), _MaxFreqFactor(PumpSel-1));

        for(i = 1; i <= nMaxEffClass; i++)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))
                break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MaxFreqFactor(PumpSel-1) - (i * _STEP_H(PumpSel-1)));
        }

    }
    else if (cntRun <= 2 * 1 * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1)) //��������һ��̨��
    {
        nMaxEffClass = 1;
        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpDetect(PumpSel, direction, cntRun, _MinFreqFactor(PumpSel-1));

    }
    else
    {
        nMaxEffClass = ceil(cntRun * 1.0 / (2 * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1))) - 1;
        for(i = 0; i < nMaxEffClass; i++)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))
                break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MinFreqFactor(PumpSel-1) + (i * _STEP_H(PumpSel-1)));
        }
        if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1))
            PumpDetect(PumpSel, direction, cntRun - 2 * nMaxEffClass * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1), _MinFreqFactor(PumpSel-1) + nMaxEffClass);
        for(i = 1; i <= nMaxEffClass; i++)
        {
            if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON(PumpSel-1))
                break;
            PumpDetect(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MinFreqFactor(PumpSel-1) + nMaxEffClass - (i * _STEP_H(PumpSel-1)));
        }

    }

}

void PumpFreeRun(u8 PumpSel, u8 direction, u16 cntRun) //���ܹ����źţ������������������
{

    u16 i;
    if (cntRun <= 0) return;
    if (cntRun > 2 * _MaxStepCount(PumpSel-1) * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1)) //�����Ӽ���������
    {
        nMaxEffClass = _MaxStepCount(PumpSel-1);
        for(i = 0; i < nMaxEffClass; i++)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MinFreqFactor(PumpSel-1) + (i * _STEP_H(PumpSel-1)));
        PumpNormal(PumpSel, direction, cntRun - 2 * nMaxEffClass * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1), _MaxFreqFactor(PumpSel-1));
        for(i = 1; i <= nMaxEffClass; i++)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MaxFreqFactor(PumpSel-1) - (i * _STEP_H(PumpSel-1)));

    }
    else if ((cntRun <= 2 * 1 * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1)) && (cntRun > 0)) //��������һ��̨��
    {
        nMaxEffClass = 1;
        PumpNormal(PumpSel, direction, cntRun, _MinFreqFactor(PumpSel-1));

    }
    else
    {
        nMaxEffClass = ceil(cntRun * 1.0 / (2 * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1))) - 1;
        for(i = 0; i < nMaxEffClass; i++)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) ,  _MinFreqFactor(PumpSel-1) + (i * _STEP_H(PumpSel-1)));
        PumpNormal(PumpSel, direction, cntRun - 2 * nMaxEffClass * _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1),  _MinFreqFactor(PumpSel-1) + nMaxEffClass);
        for(i = 1; i <= nMaxEffClass; i++)
            PumpNormal(PumpSel, direction, _FullStepPerClass(PumpSel-1) * _nStep2Pulse(PumpSel-1) , _MinFreqFactor(PumpSel-1) + nMaxEffClass - (i * _STEP_H(PumpSel-1)));

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

    //����ƽ̨reset

    while(PumpGetOpticStatus(PumpSel) != _OPTIC_ON(PumpSel-1) && maxTry < 21)
    {
        PumpDetectRun(PumpSel, 1, 200);
        Delay10ms(50);
        maxTry++;
    }
    //PumpIn(uint cntRun)(MaxPulseNum-1000);Delay50us(65000);//һ���
    PumpIn(PumpSel, _ResetPulseNum);
    Delay10ms(50);//pul�ü���dt���
    PumpDetectRun(PumpSel, 1, _ResetPulseNum + _nBackLash(PumpSel-1)); //Delay50us(65000);

}

void PumpBurnIn(u8 PumpSel, u8 VolTest)
{
    PumpReset(PumpSel);
    Delay10ms(100);
    //DelayMeasure(6); //1����λ����
    PumpIn(PumpSel, 1000);
    Delay10ms(100); //��������϶
    //DelayMeasure(7);//2�����뱳϶����
    PumpIn(PumpSel, VolTest * _nuL2Step(PumpSel-1) * _nStep2Pulse(PumpSel-1));
    Delay10ms(100); //�ޱ�϶����
    //DelayMeasure(6);//3���������
    PumpOut(PumpSel, _nBackLash(PumpSel-1));
    Delay10ms(100); //�ų�����϶
    //DelayMeasure(6); //4���ų���϶����
    PumpOut(PumpSel, VolTest * _nuL2Step(PumpSel-1) * _nStep2Pulse(PumpSel-1));
    Delay10ms(100); //�ޱ�϶�ų�
    Delay10ms(100); //5����Һ����
}
/*-------------------------end of line--------------------------------*/




