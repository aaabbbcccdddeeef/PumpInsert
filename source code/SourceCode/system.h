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
void CMonitorOptEvent(u8 OptSel);
void CBurnInEvent(void);
#else
extern void CSystemEventHandler(void);

#endif

