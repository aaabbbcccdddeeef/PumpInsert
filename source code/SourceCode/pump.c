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

/********************************************************
                       �Ӽ��ٲ���
********************************************************/
u8 MaxStepCount=40;		//̨����
u8 FullStepPerClass = 1;  //ÿ��̨�׵������� ,���ٶ�
u8 nMaxEffClass=0;    //������̨��
u16 nBackLash=40;
u8 nStep2Pulse=2;
u16 ResetPulseNum=4000;
u8 MinFreqFactor=10;
u8 MaxFreqFactor=50;
#define _STEP_H    ((MaxFreqFactor-MinFreqFactor)/MaxStepCount)


void PumpInit(void)
{
    GPIO0->FIODIR &= 0x00000000;
    GPIO0->FIODIR |= 0x07800fff;
    GPIO0->FIOSET |= 0x07800fff;
}
void PumpSetEnable(u8 PumpSel, u32 enable)
{
    if(PumpSel==1)
    {
        if(enable == _PUMP_ENABLE)
            GPIO0->FIOPIN &= ~(1<<0);
        else if(enable == _PUMP_DISABLE)
            GPIO0->FIOPIN |= 1<<0;
    }
    else if(PumpSel==2)
    {
        if(enable == _PUMP_ENABLE)
            GPIO0->FIOPIN &= ~(1<<4);
        else if(enable == _PUMP_DISABLE)
            GPIO0->FIOPIN |= 1<<4;
    }
}

void PumpSetDirection(u8 PumpSel,u32 dir)
{
    if(PumpSel==1)
    {
        if(dir == _DIR_POS)
            GPIO0->FIOPIN &= ~(1<<1);
        else if(dir == _DIR_NEG)
            GPIO0->FIOPIN |= 1<<1;
    }
    else if(PumpSel==2)
    {
        if(dir == _DIR_POS)
            GPIO0->FIOPIN &= ~(1<<5);
        else if(dir == _DIR_NEG)
            GPIO0->FIOPIN |= 1<<5;
    }
}

void PumpSetStepMode(u8 PumpSel, u32 SetBit)
{
    if(PumpSel==1)
    {
        GPIO0->FIOPIN &= ~(3<<23);
        GPIO0->FIOPIN |= SetBit<<23;
    }
    else if(PumpSel==2)
    {
        GPIO0->FIOPIN &= ~(3<<25);
        GPIO0->FIOPIN |= SetBit<<25;
    }
}

void PumpSetValveState(u8 ValveSel, u32 SetBit)
{
    switch(ValveSel)
    {
        case 1:
            if(SetBit == _VALVE_OFF)
                GPIO0->FIOPIN &= ~(1<<8);
            else if(SetBit == _VALVE_ON)
                GPIO0->FIOPIN |= 1<<8;
            break;
        case 2:
            if(SetBit == _VALVE_OFF)
                GPIO0->FIOPIN &= ~(1<<9);
            else if(SetBit == _VALVE_ON)
                GPIO0->FIOPIN |= 1<<9;
            break;
        case 3:
            if(SetBit == _VALVE_OFF)
                GPIO0->FIOPIN &= ~(1<<10);
            else if(SetBit == _VALVE_ON)
                GPIO0->FIOPIN |= 1<<10;
            break;
        case 4:
            if(SetBit == _VALVE_OFF)
                GPIO0->FIOPIN &= ~(1<<11);
            else if(SetBit == _VALVE_ON)
                GPIO0->FIOPIN |= 1<<11;
            break;
        default:
            break;
    }
}
void PumpSetClkLow(u8 PumpSel)
{
	if(PumpSel==1)
	{
		GPIO0->FIOPIN &= ~(1<<2);
	}
	else if(PumpSel==2)
	{
		GPIO0->FIOPIN &= ~(1<<6);
	}
}
void PumpSetLowPowerMode(u8 PumpSel, u8 Mode)
{
    if(PumpSel==1)
    {
        if(Mode == _NORMAL_PWR)
            GPIO0->FIOPIN &= ~(1<<3);
        else if(Mode == _LOW_PWR)
            GPIO0->FIOPIN |= 1<<3;
    }
    else if(PumpSel==2)
    {
        if(Mode == _NORMAL_PWR)
            GPIO0->FIOPIN &= ~(1<<7);
        else if(Mode == _LOW_PWR)
            GPIO0->FIOPIN |= 1<<7;
    }
}
u32 PumpGetOpticStatus(u8 OptSel)
{
    u32 TempValue=0;
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
    return TempValue;
}


void PumpNormal(u8 PumpSel, u8 direction,u16 cntRun, u16 Freq) //ָ��������ĳ���̶���Ƶ���˶�
{
    if (cntRun<=0) return;
    init_timer( 0, TIME_10MS_INTERVAL/Freq);
    enable_timer(0);
    PumpSetEnable(PumpSel, _PUMP_ENABLE);
    PumpSetLowPowerMode(PumpSel, _NORMAL_PWR);
    PumpSetStepMode(PumpSel, 1);//	������ʽ���� 1=HALF,0=FULL
    PumpSetDirection(PumpSel, 1-direction);
    PumpSetClkLow(PumpSel);// �������λ

    PumpNum[PumpSel-1] = cntRun;
    while(PumpNum[PumpSel-1]);

    disable_timer(0);
    PumpSetLowPowerMode(PumpSel, _LOW_PWR);
    PumpSetEnable(PumpSel, _PUMP_DISABLE);
}
void PumpStop(u8 PumpSel, u8 direction)
{
	PumpNormal(PumpSel,direction, 5*nStep2Pulse, MaxFreqFactor);   //5��������ֹͣ
}
void PumpDetect(u8 PumpSel, u8 direction,u16 cntRun, u16 Freq) //��ĳ���̶���Ƶ���˶�����������
{
    if (cntRun<=0) 
        return;
    init_timer( 0, TIME_10MS_INTERVAL/Freq );
    enable_timer(0);

    PumpSetEnable(PumpSel, _PUMP_ENABLE);
    PumpSetLowPowerMode(PumpSel, _NORMAL_PWR);
    PumpSetStepMode(PumpSel, 1);//	������ʽ���� 1=HALF,0=FULL
    PumpSetDirection(PumpSel, 1-direction);
    PumpSetClkLow(PumpSel);// �������λ

    PumpNum[PumpSel-1] = cntRun;
    while(PumpNum[PumpSel-1])
    {
    if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON)   //idex����������ڵ��Ʋ���
        {
            //PumpStop(direction);//����϶��Ǻ��ģ���ͣ
            break;
        }
    }

    disable_timer(0);
    PumpSetLowPowerMode(PumpSel, _LOW_PWR);
    PumpSetEnable(PumpSel, _PUMP_DISABLE);
}

void PumpDetectRun(u8 PumpSel, u8 direction, u16 cntRun) //�������źţ������������������
{
	u8 i;
	if (cntRun<=0) return;

	if (cntRun>2*MaxStepCount*FullStepPerClass*nStep2Pulse) //�����Ӽ���������
	{
		nMaxEffClass=MaxStepCount;
		for(i=0;i<nMaxEffClass;i++)  
		{
			if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON)	 break;
			PumpDetect(PumpSel,direction,FullStepPerClass*nStep2Pulse , MinFreqFactor+(i*_STEP_H));
		}

		if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON) 
                PumpDetect(PumpSel,direction, cntRun-2*nMaxEffClass*FullStepPerClass*nStep2Pulse, MaxFreqFactor);

		for(i=1;i<=nMaxEffClass;i++)  
		{
			if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON)	 
                        break;
			PumpDetect(PumpSel,direction,FullStepPerClass*nStep2Pulse , MaxFreqFactor-(i*_STEP_H));
		}
		
	}
	else if (cntRun<=2*1*FullStepPerClass*nStep2Pulse) //��������һ��̨��
	{
		nMaxEffClass=1;
		if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON) 
                    PumpDetect(PumpSel,direction, cntRun, MinFreqFactor);
		
	}
	else
	{
		nMaxEffClass = ceil(cntRun*1.0/(2*FullStepPerClass*nStep2Pulse))-1;
		for(i=0;i<nMaxEffClass;i++)  
		{
			if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON)	 
                        break;
			PumpDetect(PumpSel,direction,FullStepPerClass*nStep2Pulse , MinFreqFactor+(i*_STEP_H));
		}
		if(PumpGetOpticStatus(PumpSel) != _OPTIC_ON) 
                PumpDetect(PumpSel,direction, cntRun-2*nMaxEffClass*FullStepPerClass*nStep2Pulse,MinFreqFactor+nMaxEffClass);
		for(i=1;i<=nMaxEffClass;i++)  
		{
			if(PumpGetOpticStatus(PumpSel) == _OPTIC_ON)	 
                        break;
			PumpDetect(PumpSel,direction,FullStepPerClass*nStep2Pulse , MinFreqFactor+nMaxEffClass-(i*_STEP_H));
		}
		
	}

}

void PumpFreeRun(u8 PumpSel, u8 direction, u16 cntRun) //���ܹ����źţ������������������
{

	u16 i;
	if (cntRun<=0) return;
	if (cntRun>2*MaxStepCount*FullStepPerClass*nStep2Pulse) //�����Ӽ���������
	{
		nMaxEffClass=MaxStepCount;
		for(i=0;i<nMaxEffClass;i++)  
          PumpNormal(PumpSel,direction,FullStepPerClass*nStep2Pulse , MinFreqFactor+(i*_STEP_H));
		PumpNormal(PumpSel,direction, cntRun-2*nMaxEffClass*FullStepPerClass*nStep2Pulse, MaxFreqFactor);
		for(i=1;i<=nMaxEffClass;i++)  
          PumpNormal(PumpSel,direction,FullStepPerClass*nStep2Pulse , MaxFreqFactor-(i*_STEP_H));
		
	}
	else if ((cntRun<=2*1*FullStepPerClass*nStep2Pulse) && (cntRun>0)) //��������һ��̨��
	{
		nMaxEffClass=1;
		PumpNormal(PumpSel,direction, cntRun, MinFreqFactor);
		
	}
	else
	{
		nMaxEffClass = ceil(cntRun*1.0/(2*FullStepPerClass*nStep2Pulse))-1;
		for(i=0;i<nMaxEffClass;i++)  
          PumpNormal(PumpSel,direction,FullStepPerClass*nStep2Pulse ,  MinFreqFactor+(i*_STEP_H));
		PumpNormal(PumpSel,direction, cntRun-2*nMaxEffClass*FullStepPerClass*nStep2Pulse,  MinFreqFactor+nMaxEffClass);
		for(i=1;i<=nMaxEffClass;i++)  
          PumpNormal(PumpSel,direction,FullStepPerClass*nStep2Pulse , MinFreqFactor+nMaxEffClass-(i*_STEP_H));
		
	}

}

void PumpIn( u8 PumpSel, u16  cntRun)
{
	if (cntRun<=0) return;
	PumpFreeRun(PumpSel,0,cntRun);
}

void PumpOut(u8 PumpSel,  u16 cntRun)
{
	if (cntRun<=0) return;
	PumpFreeRun(PumpSel,1,cntRun);

}

void PumpReset(u8 PumpSel )
{
	u8 maxTry=0;
	
	//����ƽ̨reset

	while(PumpGetOpticStatus(PumpSel) != _OPTIC_ON && maxTry < 21)
	{ 
		PumpDetectRun(PumpSel,1,200);
		Delay10ms(50);
		maxTry++;
	}
	//PumpIn(uint cntRun)(MaxPulseNum-1000);Delay50us(65000);//һ���
	PumpIn(PumpSel,ResetPulseNum);
    Delay10ms(50);//pul�ü���dt���
	PumpDetectRun(PumpSel,1,ResetPulseNum+nBackLash);//Delay50us(65000);

}

void PumpTest(void)
{
    PumpReset(1);
}
 /*-------------------------end of line--------------------------------*/


 
 
