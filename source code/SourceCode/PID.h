/******************************************************************************/
/* PID.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#ifdef __PID_H__
float pid_value=0;
#else
extern float pid_value;
extern void pid_init(StructPID *pid, float p_gain, float i_gain, float d_gain);

extern float pid_hum(float eLast);


#endif

//****************************END OF LINE*************************************//
