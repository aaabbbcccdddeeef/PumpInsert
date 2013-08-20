/******************************************************************************/
/* PID.c:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define __PID_H__
#include "include.h"

/*------------------------------------------------------------------------
pid_tune

DESCRIPTION Sets the proportional gain (p_gain), integral gain (i_gain),
derivitive gain (d_gain), and the dead band (dead_band) of
a pid control structure StructPID.
------------------------------------------------------------------------*/

void pid_init(StructPID *pid, float p_gain, float i_gain, float d_gain)
{
	pid->pgain = p_gain;
	pid->igain = i_gain;
	pid->dgain = d_gain;
	pid->e[0]=0;
	pid->e[1]=0;
	pid->e[2]=0;
	pid->result=0;
}


/*------------------------------------------------------------------------
pid_update

DESCRIPTION update e(k)
------------------------------------------------------------------------*/
void pid_Eupdate(StructPID *pid, float eLast)
{
	pid->e[2] = pid->e[1];
	pid->e[1] = pid->e[0];
	pid->e[0] = eLast;
}

/*------------------------------------------------------------------------
pid_calc 　　
DESCRIPTION Performs PID calculations for the StructPID structure *a. This function uses the positional form of the pid equation, and incorporates an integral 

windup prevention algorithim. Rectangular integration is used, so this function must be repeated on a consistent time basis for accurate control.
　　
RETURN VALUE The new output value for the pid loop. 　　
------------------------------------------------------------------------*/
float pid_process(StructPID *pid)
{
	float delta=0;
	
	if(pid->e[2]!=0)
	{
		delta = pid->pgain*(pid->e[2]-pid->e[1]+(pid->e[2]/pid->igain)+(pid->dgain/(pid->e[2]-2*pid->e[1]+pid->e[0])));
		pid->result+=delta;
		if(pid->result>100)
			pid->result=100;
		else if(pid->result<-100)
			pid->result=-100;
		return pid->result;
	}
	else 
		return 0;
}

float pid_hum(float eLast)
{
	float pid_value=0;
	
 	pid_Eupdate(&HumPID, eLast);

	pid_value = pid_process(&HumPID);
	return pid_value;

}

//****************************END OF LINE*************************************//

