/******************************************************************************/
/* aInclude.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


 /* 标准C库函数头文件 */
#include <stdio.h>				   	 
#include <ctype.h>				    
#include <stdlib.h>
#include <setjmp.h>
#include <rt_misc.h>
#include <string.h>
#include <math.h>
/* NXP LPC17xx definitions            */
#include "LPC17xx.h"                    
#include "type.h"
#include "define.h"//=======所有宏定义头文件
#include "struct.h"//=======所有结构定义头文件
#include "main.h"//=======所有全局变量头文件
#include "rtc.h"
#include "systick.h"
#include "ADC.h"
#include "dac.h"
#include "Serial.h"
#include "msd.h"
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbcore.h"
#include "hiduser.h"
#include "spi_flash.h"
#include "i2c.h"
#include "timer.h"
#include "pwm.h"
#include "rx_lcd_v02.h"
#include "touchpad.h"
#include "compress.h"
#include "power.h"
#include "system.h"
#include "extint.h"

#include "eeprom_flash.h"
#include "eeprom_default.h"

#include "menu.h"
#include "menufunc.h"
#include "pump.h"

