/*----------------------------------------------------------------------------
 * Name:    ADC.c
 * Purpose: MCB1700 low level ADC functions
 * Version: V1.00
 * Note(s):
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
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#define __ADC_H

#include <LPC17xx.H>                             /* LPC17xx definitions */
#include "ADC.h"

/*----------------------------------------------------------------------------
  initialize ADC Pins
 *----------------------------------------------------------------------------*/
void ADC_init (void) {

  //PINCON->PINSEL1 &= ~(3<<14);                   /* P0.23 is GPIO */
  //PINCON->PINSEL1 |=  (1<<14);                   /* P0.23 is AD0.0 */

  //PINCON->PINSEL1 &= ~(3<<16);                   /* P0.24 is GPIO */
  //PINCON->PINSEL1 |=  (1<<16);                   /* P0.24 is AD0.1 */

  //PINCON->PINSEL1 &= ~(3<<18);                   /* P0.25 is GPIO */
  //PINCON->PINSEL1 |=  (1<<18);                   /* P0.25 is AD0.2 */

  //PINCON->PINSEL1 &= ~(3<<20);                   /* P0.26 is GPIO */
  //PINCON->PINSEL1 |=  (1<<20);                   /* P0.26 is AD0.3 */

  //PINCON->PINSEL0 &= ~(3<<6);                   /* P0.3 is GPIO */
  //PINCON->PINSEL0 |=  (1<<7);                   /* P0.3 is AD0.6 */


  PINCON->PINSEL3 |= 0xf0000000;                   /*P1.30 is AD0.4 P1.31 is AD0.5 */
  
  SC->PCONP       |=  (1<<12);                   /* Enable power to ADC block */

  ADC->ADCR        =1|  
                        (1<< 1) |                  /* select AD0.1 pin */
                        (1<< 2) |                  /* select AD0.2 pin */
                        (1<< 3) |                  /* select AD0.3 pin */
                        (1<< 4) |                  /* select AD0.4 pin */
                        (1<< 5) |                  /* select AD0.5 pin */
                        (1<< 6) |                  /* select AD0.6 pin */
                        (1<< 7) |                  /* select AD0.7 pin */
                      (1<< 8) |                  /* ADC clock is 18MHz/2 */
                      (1<<16)|
                      (1<<21);                   /* enable ADC */ 
}


/*----------------------------------------------------------------------------
  start ADC Conversion
 *----------------------------------------------------------------------------*/
void ADC_startCnv (void) {
  ADC->ADCR &= ~(7<<24);                         /* stop conversion  */
  //ADC->ADCR |=  (1<<24);                         /* start conversion */
  ADC->ADCR |=  (1<<16);                         /* start conversion */
}


/*----------------------------------------------------------------------------
  stop ADC Conversion
 *----------------------------------------------------------------------------*/
void ADC_stopCnv (void) {
  //ADC->ADCR &= ~(7<<24);                         /* stop conversion */
  ADC->ADCR &= ~(1<<16);                         /* stop conversion */
}


/*----------------------------------------------------------------------------
  get converted ADC value
 *----------------------------------------------------------------------------*/
uint32_t ADC0_getCnv (void) {
  uint32_t adGdr;
//  uint32_t adDr2;

  while (!(ADC->ADDR0 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr = ADC->ADDR0;
  //adGdr = ADC->ADGDR;
//  adDr2 = ADC->ADDR2;
  return((adGdr >> 4) & ADC_VALUE_MAX);          /* read converted value */
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
unsigned int ADC0_Get (void)
{
  unsigned int val;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC0_getCnv();                    
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*----------------------------------------------------------------------------
  get converted ADC value
 *----------------------------------------------------------------------------*/
u16 ADC1_getCnv (void) {
  u16 adGdr;
//  uint32_t adDr2;

  while (!(ADC->ADDR1 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr = ADC->ADDR1;
//  adDr2 = ADC->ADDR2;
  return((adGdr >> 4) & ADC_VALUE_MAX);          /* read converted value */
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
u16 ADC1_Get (void)
{
  u16 val;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC1_getCnv();                    
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
 uint32_t ADC01_getCnv (void) {
  uint32_t adGdr0;
  uint32_t adGdr1;

  while (!(ADC->ADDR1 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr0 = ADC->ADDR0;
  adGdr1 = ADC->ADDR1;
  adGdr0 = (adGdr0 >> 4) & ADC_VALUE_MAX;
  adGdr1 = (adGdr1 >> 4) & ADC_VALUE_MAX;
  adGdr0 = (adGdr0<<16)|adGdr1;
  return adGdr0;          /* read converted value */
}

unsigned int ADC01_Get (void)
{
  u32 val;
  //u32 Temp;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC01_getCnv();                    
  //Temp = ADC1_getCnv();
  //val = (val<<16)|Temp;
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*----------------------------------------------------------------------------
  get converted ADC value
 *----------------------------------------------------------------------------*/
u16 ADC2_getCnv (void) {
  u16 adGdr;
//  uint32_t adDr2;

  while (!(ADC->ADDR2 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr = ADC->ADDR2;
  return((adGdr >> 4) & ADC_VALUE_MAX);          /* read converted value */
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
u16 ADC2_Get (void)
{
  u16 val;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC2_getCnv();                    
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*----------------------------------------------------------------------------
  get converted ADC value
 *----------------------------------------------------------------------------*/
uint32_t ADC3_getCnv (void) {
  uint32_t adGdr;
//  uint32_t adDr2;

  while (!(ADC->ADDR3 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr = ADC->ADDR3;
  return((adGdr >> 4) & ADC_VALUE_MAX);          /* read converted value */
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
unsigned int ADC3_Get (void)
{
  unsigned int val;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC3_getCnv();                    
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
 uint32_t ADC23_getCnv (void) {
  uint32_t adGdr2;
  uint32_t adGdr3;

  while (!(ADC->ADDR3 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr2 = ADC->ADDR2;
  adGdr3 = ADC->ADDR3;
  adGdr2 = (adGdr2 >> 4) & ADC_VALUE_MAX;
  adGdr3 = (adGdr3 >> 4) & ADC_VALUE_MAX;
  adGdr2 = (adGdr2<<16)|adGdr3;
  return adGdr2;          /* read converted value */
}

unsigned int ADC23_Get (void)
{
  u32 val;
  //u32 Temp;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC23_getCnv();                    
  //Temp = ADC1_getCnv();
  //val = (val<<16)|Temp;
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
 uint32_t ADC12_getCnv (void) {
  uint32_t adGdr1;
  uint32_t adGdr2;

  while (!(ADC->ADDR2 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr1 = ADC->ADDR1;
  adGdr2 = ADC->ADDR2;
  adGdr1 = (adGdr1 >> 4) & ADC_VALUE_MAX;
  adGdr2 = (adGdr2 >> 4) & ADC_VALUE_MAX;
  adGdr1 = (adGdr1<<16)|adGdr2;
  return adGdr1;          /* read converted value */
}

u32 ADC12_Get (void)
{
  u32 val;
  //u32 Temp;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC12_getCnv();                    
  //Temp = ADC1_getCnv();
  //val = (val<<16)|Temp;
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}
/*----------------------------------------------------------------------------
  get converted ADC value
 *----------------------------------------------------------------------------*/
uint32_t ADC4_getCnv (void) {
  uint32_t adGdr;
//  uint32_t adDr2;

  while (!(ADC->ADDR4 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr = ADC->ADDR4;
  return((adGdr >> 4) & ADC_VALUE_MAX);          /* read converted value */
}

/*----------------------------------------------------------------------------
  get converted ADC value
 *----------------------------------------------------------------------------*/
uint32_t ADC5_getCnv (void) {
  uint32_t adGdr;
//  uint32_t adDr2;

  while (!(ADC->ADDR5 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr = ADC->ADDR5;
  //adGdr = ADC->ADGDR;
//  adDr2 = ADC->ADDR2;
  return((adGdr >> 4) & ADC_VALUE_MAX);          /* read converted value */
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
unsigned int ADC4_Get (void)
{
  unsigned int val;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC4_getCnv();                    
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
unsigned int ADC5_Get (void)
{
  unsigned int val;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC5_getCnv();                    
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
 uint32_t ADC45_getCnv (void) {
  uint32_t adGdr1;
  uint32_t adGdr2;

  while (!(ADC->ADDR5 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr1 = ADC->ADDR4;
  adGdr2 = ADC->ADDR5;
  adGdr1 = (adGdr1 >> 4) & ADC_VALUE_MAX;
  adGdr2 = (adGdr2 >> 4) & ADC_VALUE_MAX;
  adGdr1 = (adGdr1<<16)|adGdr2;
  return adGdr1;          /* read converted value */
}

u32 ADC45_Get (void)
{
  u32 val;
  //u32 Temp;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC45_getCnv();                    
  //Temp = ADC1_getCnv();
  //val = (val<<16)|Temp;
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}

/*------------------------------------------------------------------------------
  read a converted value from the Analog/Digital converter
 *------------------------------------------------------------------------------*/
 uint32_t ADC56_getCnv (void) {
  uint32_t adGdr1;
  uint32_t adGdr2;

  while (!(ADC->ADDR6 & (1UL<<31)));             /* Wait for Conversion end */
  adGdr1 = ADC->ADDR5;
  adGdr2 = ADC->ADDR6;
  adGdr1 = (adGdr1 >> 4) & ADC_VALUE_MAX;
  adGdr2 = (adGdr2 >> 4) & ADC_VALUE_MAX;
  adGdr1 = (adGdr1<<16)|adGdr2;
  return adGdr1;          /* read converted value */
}

u32 ADC56_Get (void)
{
  u32 val;
  //u32 Temp;

  ADC_startCnv();                                 /* start A/D conversion */
  val = ADC56_getCnv();                    
  //Temp = ADC1_getCnv();
  //val = (val<<16)|Temp;
  ADC_stopCnv();                                  /* stop A/D conversion */
	
  return (val);
}


