/*****************************************************************************
 *   timer.c:  Timer C file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#include <lpc17xx.h>
#include "type.h"
#include "timer.h"
#include "pump.h"
#include "main.h"
#include "eeprom_flash.h"
volatile uint32_t PumpNum[3] = {0,0,0};
/*****************************************************************************
** Function name:		delayMs
**
** Descriptions:		Start the timer delay in milo seconds
**						until elapsed
**
** parameters:			timer number, Delay value in milo second			 
** 						
** Returned value:		None
** 
*****************************************************************************/
void Delay1ms(uint32_t delayInMs)
{
    /*
    * setup timer #0 for delay
    */
    TIM0 ->TCR = 0x02;		/* reset timer */
    TIM0 ->PR  = 0x00;		/* set prescaler to zero */
    TIM0 ->MR0 = delayInMs * (9000000 / 1000-1);
    TIM0 ->IR  = 0xff;		/* reset all interrrupts */
    TIM0 ->MCR = 0x04;		/* stop timer on match */
    TIM0 ->TCR = 0x01;		/* start timer */

    /* wait until delay time has elapsed */
    while (TIM0 ->TCR & 0x01);

    return;
}


/******************************************************************************
** Function name:		Timer0Handler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void TIMER0_IRQHandler (void) 
{  
    TIM0 ->IR = 1;			/* clear interrupt flag */

    if(g_u8RunningPause==0)
    {
        if((g_u32RunningFlow1[g_u8RunningIndex]!=0)&&(g_u8FlowWaitOver==1)&&(g_u8FlowPumpOver==0))
        {
            GPIO0->FIOPIN ^= (1<<2);
            if(--g_u32RunningFlow1[g_u8RunningIndex]==0)
            {
                GPIO0->FIOPIN |= 1 << 3;;//PumpSetLowPowerMode(1, _LOW_PWR);
                g_u8FlowPumpOver=1;
                if(g_u32WaitFlow1[g_u8RunningIndex]!=0)
                    g_u8FlowWaitOver=0;
            }
        }
        else
        {
            if(((g_u8RunningIndex+1)<g_u8FlowCount)&&(g_u8FlowPumpOver==1)&&(g_u8FlowWaitOver==1))
            {
                g_u8RunningIndex++;
                if(g_u8DirectionFlow1[g_u8RunningIndex]== _DIR_POS)
                    GPIO0->FIOPIN &= ~(1 << 1);
                else if(g_u8DirectionFlow1[g_u8RunningIndex] == _DIR_NEG)
                    GPIO0->FIOPIN |= 1 << 1;
                g_u8FlowPumpOver=0;
                
            }
            else if(((g_u8RunningIndex+1)==g_u8FlowCount)&&(g_u8FlowPumpOver==1)&&(g_u8FlowWaitOver==1))
            {
                GPIO0->FIOPIN |= 1 << 0;;//PumpSetEnable(1, _PUMP_DISABLE);
                g_u8RunningPause=1;
            }
            else
            {
                GPIO0->FIOPIN |= 1 << 0;;//PumpSetEnable(1, _PUMP_DISABLE);
            }
        }
    }

}


/******************************************************************************
** Function name:		Timer1Handler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void TIMER1_IRQHandler (void)  
{  
  TIM1 ->IR = 1;			/* clear interrupt flag */

    if(PumpNum[0]!=0)
    {
         PumpNum[0]--;
         GPIO0->FIOPIN ^= (1<<2);
    }
    /*
    if(PumpNum[1]!=0)
    {
         PumpNum[1]--;
         GPIO0->FIOPIN ^= (1<<6);
    }
*/
}


/******************************************************************************
** Function name:		Timer1Handler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void TIMER2_IRQHandler (void)  
{  
  TIM2 ->IR = 1;			/* clear interrupt flag */
    if(PumpNum[0]!=0)
    {
         PumpNum[0]--;
         GPIO0->FIOPIN ^= (1<<2);
    }


}


/******************************************************************************
** Function name:		Timer1Handler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void TIMER3_IRQHandler (void)  
{  
  TIM3 ->IR = 1;			/* clear interrupt flag */
  if(PumpNum[1]!=0)
    {
         PumpNum[1]--;
         GPIO0->FIOPIN ^= (1<<6);
    }
}




/******************************************************************************
** Function name:		enable_timer
**
** Descriptions:		Enable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
** 
******************************************************************************/
void enable_timer( uint8_t timer_num )
{
  if ( timer_num == 0 )
  {
	TIM0 ->TCR = 1;
  }
  else if( timer_num == 1 )
  {
	TIM1 ->TCR = 1;
  }
  else if( timer_num == 2 )
  {
	TIM2 ->TCR = 1;
  }
  else if( timer_num == 3 )
  {
	TIM3 ->TCR = 1;
  }
  return;
}

/******************************************************************************
** Function name:		disable_timer
**
** Descriptions:		Disable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
** 
******************************************************************************/
void disable_timer( uint8_t timer_num )
{
  if ( timer_num == 0 )
  {
	TIM0 ->TCR = 0;
  }
  else if( timer_num == 1 )
  {
	TIM1 ->TCR = 0;
  }
  else if( timer_num == 2 )
  {
	TIM2 ->TCR = 0;
  }
  else if( timer_num == 3 )
  {
	TIM3 ->TCR = 0;
  }
  return;
}

/******************************************************************************
** Function name:		reset_timer
**
** Descriptions:		Reset timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
** 
******************************************************************************/
void reset_timer( uint8_t timer_num )
{
  uint32_t regVal;

  if ( timer_num == 0 )
  {
	regVal = TIM0 ->TCR;
	regVal |= 0x02;
	TIM0 ->TCR = regVal;
  }
  else
  {
	regVal = TIM1 ->TCR;
	regVal |= 0x02;
	TIM1 ->TCR = regVal;
  }
  return;
}

/******************************************************************************
** Function name:		init_timer
**
** Descriptions:		Initialize timer, set timer interval, reset timer,
**						install timer interrupt handler
**
** parameters:			timer number and timer interval
** Returned value:		true or false, if the interrupt handler can't be
**						installed, return false.
** 
******************************************************************************/
uint32_t init_timer ( uint8_t timer_num, uint32_t TimerInterval ) 
{

  if ( timer_num == 0 )
  {
	PumpNum[0] = 0;
	TIM0 ->MR0 = TimerInterval;
	TIM0 ->MCR = 3;				/* Interrupt and Reset on MR0 */

	NVIC_EnableIRQ(TIMER0_IRQn);

	return (TRUE);
  }
  else if ( timer_num == 1 )
  {
	PumpNum[1] = 0;
	TIM1 ->MR0 = TimerInterval;
	TIM1 ->MCR = 3;				/* Interrupt and Reset on MR1 */

	NVIC_EnableIRQ(TIMER1_IRQn);

	return (TRUE);
  }
  else if ( timer_num == 2 )
  {
      SC->PCONP       |=  (1<<22);                
	PumpNum[0] = 0;
	TIM2 ->MR0 = TimerInterval;
	TIM2 ->MCR = 3;				/* Interrupt and Reset on MR1 */

	NVIC_EnableIRQ(TIMER2_IRQn);

	return (TRUE);
  }
  else if ( timer_num == 3 )
  {
        SC->PCONP       |=  (1<<23);                
	PumpNum[1] = 0;
	TIM3 ->MR0 = TimerInterval;
	TIM3 ->MCR = 3;				/* Interrupt and Reset on MR1 */

	NVIC_EnableIRQ(TIMER3_IRQn);

	return (TRUE);
  }
  return (FALSE);
}

/******************************************************************************
**                            End Of File
******************************************************************************/
