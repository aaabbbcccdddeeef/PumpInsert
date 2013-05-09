/*****************************************************************************
 *   extint.c:  External interrupt API C file for NXP LPC17xx 
 *   Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#include <lpc17xx.h>
#include "type.h"
#include "extint.h"
#include "pump.h"
#include "main.h"


volatile uint32_t eint0_counter;

/*****************************************************************************
** Function name:		EINT0_Handler
**
** Descriptions:		external INT handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void EINT0_IRQHandler (void) 
{
  SC -> EXTINT = EINT0;		/* clear interrupt */
		
  //eint0_counter++;
  g_u8RunningPause=1;
  //PumpReset(2);
 #if 0
  if ( eint0_counter & 0x01 )	/* alternate the LED display */
  {
	GPIO2 -> FIOSET = 0x0000000F;	/* turn off P2.0~3 */	
	GPIO2 -> FIOCLR = 0x000000F0;	/* turn on P2.4~7 */
  }
  else
  {
	GPIO2 -> FIOSET = 0x000000F0;	/* turn on P2.0~3 */	
	GPIO2 -> FIOCLR = 0x0000000F;	/* turn off P2.4~7 */
  }
#endif
}

/*****************************************************************************
** Function name:		EINTInit
**
** Descriptions:		Initialize external interrupt pin and
**						install interrupt handler
**
** parameters:			None
** Returned value:		true or false, return false if the interrupt
**						handler can't be installed to the VIC table.
** 
*****************************************************************************/
uint32_t EINTInit( void )
{

  PINCON -> PINSEL4 &= ~(1<<21);	/* set P2.10 as EINT0  */
						
PINCON -> PINSEL4 |=0x00100000;

  GPIOINT -> IO2IntEnF = 0x200;	/* Port2.10 is falling edge. */
  SC -> EXTMODE = EINT0_EDGE;	/* INT0 edge trigger */
  SC -> EXTPOLAR = 0;			/* INT0 is falling edge by default */

	NVIC_EnableIRQ(EINT0_IRQn);

  return( TRUE );
}

/******************************************************************************
**                            End Of File
******************************************************************************/

