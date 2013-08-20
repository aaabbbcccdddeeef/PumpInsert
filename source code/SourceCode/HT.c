/******************************************************************************/
/* HT.c:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define __HT_H__

#include "include.h"


u32 GetPID(float Delta)
{
	return pid_hum(Delta);
}

u8 HumidityMonitor(float cur_H)
{
	float delta=0;

	delta = cur_H - _Humidity_obj;
	
	pid_value = pid_hum(delta);
	if((delta < 0.5)&&(delta > -0.5))
		return 0;
	
	/*
	if(delta > 0)
	{
		g_u8HumDirect=1;
		hobj+=pid_value/100;
	}
	else
	{
		g_u8HumDirect=0;
		hobj-=pid_value/100;
	}
*/
	if(delta > 0)
	{
		g_u8HumDirect=0;
	}
	else
	{
		g_u8HumDirect=1;
	}
	g_u16HumResult = pid_value*500;
	//PumpFreeRun(1, g_u8HumDirect, g_u16HumResult);

	return 1;
}





//****************************END OF LINE*************************************//

