/*----------------------------------------------------------------------------
 * Name:    Pump.h
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

#ifndef __PUMP_H
#define __PUMP_H

#define _PUMP_ENABLE             0
#define _PUMP_DISABLE            1    

#define _VALVE_ON                   1
#define _VALVE_OFF                   0

#define _OPTIC_OFF                   0
#define _OPTIC_ON                   1

#define _DIR_POS            0
#define _DIR_NEG            1

#define _NORMAL_PWR          0
#define _LOW_PWR          1

#define _STEP_MODE_FULL                 0
#define _STEP_MODE_HALF                 1
#define _STEP_MODE_QUARTER          2
#define _STEP_MODE_SIXTEENTH       3

extern u8 nMaxEffClass;

extern void PumpInit(void);
extern void PumpSetEnable(u8 PumpSel, u32 enable);
extern void PumpSetDirection(u8 PumpSel,u32 dir);
extern void PumpSetStepMode(u8 PumpSel, u32 SetBit);
extern void PumpSetValveState(u8 ValveSel, u32 SetBit);
extern void PumpSetClkLow(u8 PumpSel);
extern void PumpSetLowPowerMode(u8 PumpSel, u8 Mode);
extern void PumpNormal(u8 PumpSel, u8 direction,u16 cntRun, u16 Freq);
extern void PumpStop(u8 PumpSel, u8 direction);
extern void PumpDetect(u8 PumpSel, u8 direction,u16 cntRun, u16 Freq) ;
extern void PumpDetectRun(u8 PumpSel, u8 direction, u16 cntRun) ;
extern void PumpFreeRun(u8 PumpSel, u8 direction, u16 cntRun) ;
extern void PumpIn( u8 PumpSel, u16  cntRun);
extern void PumpOut(u8 PumpSel,  u16 cntRun);
extern void PumpReset(u8 PumpSel );
extern void PumpTest(void);
extern void PumpBurnIn(u8 PumpSel, u8 VolTest);
extern u32 PumpGetOpticStatus(u8 OptSel);
#endif




