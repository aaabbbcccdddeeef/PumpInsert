/*----------------------------------------------------------------------------
 *      R T L  -  F l a s h   F i l e   S y s t e m
 *----------------------------------------------------------------------------
 *      Name:    RETARGET.C 
 *      Purpose: Retarget low level functions
 *      Rev.:    V3.50
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2008 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/
#include <stdio.h>

#include <rt_misc.h>

#include "Serial.h"


#pragma import(__use_no_semihosting_swi)

/* The following macro definitions may be used to translate this file:

  STDIO - use standard Input/Output device
          (default is NOT used)
 */
struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;



/*----------------------------------------------------------------------------
  Write character to Serial Port
 *----------------------------------------------------------------------------*/
int sendchar (int c) {

  if (c == '\n')  {
    SER_putChar (1, 0x0D);
  }
  SER_putChar (1, c);

  return (c);
}


/*----------------------------------------------------------------------------
  Read character from Serial Port   (blocking read)
 *----------------------------------------------------------------------------*/
int getkey (void) {

  return (SER_getChar(1));
}

int fputc(int ch, FILE *f) {
  return (sendchar(ch));
}
/*--------------------------- _ttywrch --------------------------------------*/

void _ttywrch (int ch) {

   sendchar(ch);

}
 void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}
/*--------------------------- _sys_open -------------------------------------*/

