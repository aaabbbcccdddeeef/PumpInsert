/*----------------------------------------------------------------------------
 * U S B  -  K e r n e l
 *----------------------------------------------------------------------------
 * Name:    hiduser.c
 * Purpose: HID Custom User Module
 * Version: V1.20
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
 *          V1.20 
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/
#include "lpc17xx.h"
#include "type.h"

#include "usb.h"
#include "hid.h"
#include "usbcfg.h"
#include "usbcore.h"
#include "hiduser.h"
#include "define.h"
#include "main.h"
#include "systick.h"
#include "usbhw.h"
U8 HID_Protocol;
U8 HID_IdleTime[HID_REPORT_NUM];


/*------------------------------------------------------------------------------
  Get HID Input Report -> InReport
 *------------------------------------------------------------------------------*/
void GetInReport (void) 
{

}


/*------------------------------------------------------------------------------
  Set HID Output Report <- OutReport
 *------------------------------------------------------------------------------*/
void SetOutReport (void) 
{
    u32 i;
    u8 Cks=0;

    //USB_ReceiveEnd = 1;
    for(i=0;i<7;i++)
    {
        USB_RxBuff[i] = EP0Buf[i];
        USB_TxBuff[56+i] = USB_RxBuff[i];
        Cks += USB_RxBuff[i];
        USB_TxBuff[63]=Cks;
    }
    if(Cks == EP0Buf[7])
        USB_ReceiveEnd = 1;
    else
        USB_ReceiveEnd = 0;

    USB_WriteEP(HID_EP_IN, &USB_TxBuff[56], 8);
    
    i = USB_RxBuff[3];
    g_ucUSBValue = i;
    i= USB_RxBuff[4];
    g_ucUSBValue = (g_ucUSBValue<<8)|i;
    i = USB_RxBuff[5];
    g_ucUSBValue = (g_ucUSBValue<<8)|i;
    i = USB_RxBuff[6];
    g_ucUSBValue = (g_ucUSBValue<<8)|i;
    //printf("value ===%d",g_ucUSBValue);
    //printf("PASS?? ===%d",USB_ReceiveEnd);

}
/*
 *  HID Get Report Request Callback
 *   Called automatically on HID Get Report Request
 *    Parameters:      None (global SetupPacket and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetReport (void) {

  /* ReportID = SetupPacket.wValue.WB.L; */
  switch (SetupPacket.wValue.WB.H) {
    case HID_REPORT_INPUT:
      return (FALSE);        /* Not Supported */
      //break;
    case HID_REPORT_OUTPUT:
      return (FALSE);        /* Not Supported */
    case HID_REPORT_FEATURE:
      /* EP0Buf[] = ...; */
      /* break; */
      return (FALSE);        /* Not Supported */
  }
  return (TRUE);
}


/*
 *  HID Set Report Request Callback
 *   Called automatically on HID Set Report Request
 *    Parameters:      None (global SetupPacket and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetReport (void) {

  /* ReportID = SetupPacket.wValue.WB.L; */
  switch (SetupPacket.wValue.WB.H) {
    case HID_REPORT_INPUT:
      return (FALSE);        /* Not Supported */
    case HID_REPORT_OUTPUT:
      SetOutReport();
        //USB_ReceiveEnd = 1;
      break;
    case HID_REPORT_FEATURE:
      return (FALSE);        /* Not Supported */
  }
  return (TRUE);
}


/*
 *  HID Get Idle Request Callback
 *   Called automatically on HID Get Idle Request
 *    Parameters:      None (global SetupPacket and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetIdle (void) {

  EP0Buf[0] = HID_IdleTime[SetupPacket.wValue.WB.L];
  return (TRUE);
}


/*
 *  HID Set Idle Request Callback
 *   Called automatically on HID Set Idle Request
 *    Parameters:      None (global SetupPacket)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetIdle (void) {

  HID_IdleTime[SetupPacket.wValue.WB.L] = SetupPacket.wValue.WB.H;

  /* Idle Handling if needed */
  /* ... */

  return (TRUE);
}


/*
 *  HID Get Protocol Request Callback
 *   Called automatically on HID Get Protocol Request
 *    Parameters:      None (global SetupPacket)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetProtocol (void) {

  EP0Buf[0] = HID_Protocol;
  return (TRUE);
}


/*
 *  HID Set Protocol Request Callback
 *   Called automatically on HID Set Protocol Request
 *    Parameters:      None (global SetupPacket)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetProtocol (void) {

  HID_Protocol = SetupPacket.wValue.WB.L;

  /* Protocol Handling if needed */
  /* ... */

  return (TRUE);
}

