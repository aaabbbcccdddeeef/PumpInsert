/*****************************************************************************
 *   rtc.c:  Realtime clock C file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#define __RTC__
    
#include "lpc17xx.h"
#include "type.h"
#include "rtc.h"
#include "main.h"
//#include "char.h"
//#include "GLCD.h"
//#include "eeprom.h"
#include "define.h"
#include "struct.h"
/*****************************************************************************
** Function name:		RTC_IRQHandler
**
** Descriptions:		RTC interrupt handler, it executes based on the
**						the alarm setting
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTC_IRQHandler (void) 
{  
  RTC->ILR |= ILR_RTCCIF;		/* clear interrupt flag */
  //g_uiDateTime_reload = 1;
  //GPIO1->FIOSET=1<<31;
  return;
}

/*****************************************************************************
** Function name:		RTCInit
**
** Descriptions:		Initialize RTC timer
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTCInit( void )
{
  g_uiDateTime_reload = 0;

  /* Enable CLOCK into RTC */
  SC->PCONP |= (1 << 9);

  /* If RTC is stopped, clear STOP bit. */
  if ( RTC->PWRCTRL & (0x1<<4) )
  {
	RTC->PWRCTRL |= (0x1<<4);	
  }
  
  /*--- Initialize registers ---*/    
  RTC->AMR = 0;
  RTC->CIIR = 0;
  RTC->CCR = 0;

  //NVIC_EnableIRQ(RTC_IRQn);

  RTC->CIIR = IMSEC;
    
  RTCStart();
  
  return;
}

/*****************************************************************************
** Function name:		RTCStart
**
** Descriptions:		Start RTC timer
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTCStart( void ) 
{
  /*--- Start RTC counters ---*/
  RTC->CCR |= CCR_CLKEN;
  RTC->ILR = ILR_RTCCIF;
  return;
}

/*****************************************************************************
** Function name:		RTCStop
**
** Descriptions:		Stop RTC timer
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTCStop( void )
{   
  /*--- Stop RTC counters ---*/
  RTC->CCR &= ~CCR_CLKEN;
  return;
} 

/*****************************************************************************
** Function name:		RTC_CTCReset
**
** Descriptions:		Reset RTC clock tick counter
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTC_CTCReset( void )
{   
  /*--- Reset CTC ---*/
  RTC->CCR |= CCR_CTCRST;
  return;
}


/*****************************************************************************
** Function name:		RTCSetTime
**
** Descriptions:		Setup RTC timer value
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTCSetTime( RTCTime Time ) 
{
  RTC->SEC = Time.RTC_Sec;
  RTC->MIN = Time.RTC_Min;
  RTC->HOUR = Time.RTC_Hour;
  RTC->DOM = Time.RTC_Mday;
  //RTC->DOW = Time.RTC_Wday;
  //RTC->DOY = Time.RTC_Yday;
  RTC->MONTH = Time.RTC_Mon;
  RTC->YEAR = Time.RTC_Year;    
  return;
}

/*****************************************************************************
** Function name:		RTCSetAlarm
**
** Descriptions:		Initialize RTC timer
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTCSetAlarm( RTCTime Alarm ) 
{   
  RTC->ALSEC = Alarm.RTC_Sec;
  RTC->ALMIN = Alarm.RTC_Min;
  RTC->ALHOUR = Alarm.RTC_Hour;
  RTC->ALDOM = Alarm.RTC_Mday;
  //RTC->ALDOW = Alarm.RTC_Wday;
  //RTC->ALDOY = Alarm.RTC_Yday;
  RTC->ALMON = Alarm.RTC_Mon;
  RTC->ALYEAR = Alarm.RTC_Year;    
  return;
}

/*****************************************************************************
** Function name:		RTCGetTime
**
** Descriptions:		Get RTC timer value
**
** parameters:			None
** Returned value:		The data structure of the RTC time table
** 
*****************************************************************************/
RTCTime RTCGetTime( void ) 
{
  RTCTime LocalTime;
    
  LocalTime.RTC_Sec = RTC->SEC;
  LocalTime.RTC_Min = RTC->MIN;
  LocalTime.RTC_Hour = RTC->HOUR;
  LocalTime.RTC_Mday = RTC->DOM;
  //LocalTime.RTC_Wday = RTC->DOW;
  //LocalTime.RTC_Yday = RTC->DOY;
  LocalTime.RTC_Mon = RTC->MONTH;
  LocalTime.RTC_Year = RTC->YEAR;
  return ( LocalTime );    
}

/*****************************************************************************
** Function name:		RTCSetAlarmMask
**
** Descriptions:		Set RTC timer alarm mask
**
** parameters:			Alarm mask setting
** Returned value:		None
** 
*****************************************************************************/
void RTCSetAlarmMask( uint32_t AlarmMask ) 
{
  /*--- Set alarm mask ---*/    
  RTC->AMR = AlarmMask;
  return;
}

/*****************************************************************************
** Function name:		RTCSetTimeDefault
**
** Descriptions:		Setup RTC timer default
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void RTCSetTimeDefault(void) 
{
    RTCStop();
  g_stTemp_time.RTC_Sec = 0;
  g_stTemp_time.RTC_Min = 0;
  g_stTemp_time.RTC_Hour = 0;
  g_stTemp_time.RTC_Mday = 25;
  //g_stTemp_time.RTC_Wday = 4;
  //g_stTemp_time.RTC_Yday = 0;		/* Default date 2011/08/25 */
  g_stTemp_time.RTC_Mon = 8;
  g_stTemp_time.RTC_Year = 2011;
  RTCSetTime( g_stTemp_time );		/* Set local time */
  RTCStart();
  return;
}

/*****************************************************************************
**                            End Of File
******************************************************************************/

