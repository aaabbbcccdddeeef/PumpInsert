/*****************************************************************************
 *   systick.c:  Realtime clock C file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#define __SYSTICK__

#include "lpc17xx.h"
#include "type.h"
#include "define.h"
#include "main.h"
#include "systick.h"
#include "power.h"
/*****************************************************************************
** Function name:		SysTick_Handler
**
** Descriptions:		SysTick interrupt handler, it executes based on the
**						the Systick setting
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void SysTick_Handler(void)
{    
    if(g_ui10msTick != 0)
        g_ui10msTick--;
    
    if(g_uiPowerkeyTick != 0)
        g_uiPowerkeyTick--;

    if((g_u32WaitFlow1[g_u8RunningIndex]!=0)&&(g_u8FlowPumpOver==1))
    {
        if(--g_u32WaitFlow1[g_u8RunningIndex]==0)
        {
            GPIO0->FIOPIN &= ~(1 << 3);
            g_u8FlowWaitOver=1;
        }
    }
}
/*****************************************************************************
** Function name:		Delay10ms
**
** Descriptions:		Delay10ms
**						
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void Delay10ms(uint32_t time)
{
    g_ui10msTick = time;
    while(g_ui10msTick!=0);
}
