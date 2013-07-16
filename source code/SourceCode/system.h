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


#ifdef __SYSTEM__
u8 g_u8Lost1SaveFlag=0;
u8 g_u8Lost2SaveFlag=0;

void CMonitorOptEvent(u8 OptSel);
void CBurnInEvent(void);
void CFlow1Event(void);
void CFlow2Event(void);
void CPump1LostEvent(void);
void CPump2LostEvent(void);
void CHTEvent(void);


#else
extern void CSystemEventHandler(void);
extern u8 g_u8Lost1SaveFlag;
extern u8 g_u8Lost2SaveFlag;
#endif

