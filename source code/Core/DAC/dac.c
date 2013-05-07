/*----------------------------------------------------------------------------
 * Name:    DAC.c
 * Purpose: MCB1700 low level ADC functions
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

#include <LPC17xx.H>                             /* LPC17xx definitions */
#include "dac.h"
#include "systick.h"
/*----------------------------------------------------------------------------
  initialize DAC Pins
 *----------------------------------------------------------------------------*/
void DAC_init (void)
{
    int init_value = 0x3ff;
    
    PINCON->PINSEL1 &= ~(3 << 20);		// P0.26 is GPIO
    PINCON->PINSEL1 |= 2 << 20;			// P0.26 is DAC

    SC->PCONP		|= 1 << 11;		// Enable power to DAC block

    DAC->DACR      = init_value<<6 | 0<<16;
}

void DAC_out(void)
{
    u32 i = 0;
    u32 DACValue = 0x01;
    int reverse = 0;

    DAC->DACR      = DACValue<<6 | 0<<16;
    for(i=0;i<20000;i++)
    {
        if (DACValue == 0x180)
            reverse = 1;
        else if(DACValue == 0)
            reverse = 0;
        DAC->DACR = DACValue<<6 | 0<<16;
        if(reverse == 0)
            DACValue++;
        else
            DACValue--;

    }
}
