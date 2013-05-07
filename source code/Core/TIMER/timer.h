/*****************************************************************************
 *   timer.h:  Header file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifndef __TIMER_H 
#define __TIMER_H

	
#define TIME0_INTERVAL	(18000000/1000 - 200)//1500)
#define TIME_10MS_INTERVAL         (180000)// 10ms

extern volatile uint32_t PumpNum[2];

extern void Delay1ms(uint32_t delayInMs);
extern uint32_t init_timer( uint8_t timer_num, uint32_t timerInterval );
extern void enable_timer( uint8_t timer_num );
extern void disable_timer( uint8_t timer_num );
extern void reset_timer( uint8_t timer_num );
extern void TIMER0_IRQHandler (void);
extern void TIMER1_IRQHandler (void);

#endif /* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
