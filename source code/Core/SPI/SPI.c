/*----------------------------------------------------------------------------
 *      R T L  -  F l a s h   F i l e   S y s t e m
 *----------------------------------------------------------------------------
 *      Name:    SPI_LPC17xx.C 
 *      Purpose: Serial Peripheral Interface Driver for LPC17xx
 *      Rev.:    V3.50
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2008 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#include "lpc17xx.h"                              /* LPC17xx definitions    */
#include "SPI.h"


/* SSPxSR - bit definitions. */
#define TFE     0x01
#define TNF     0x02
#define RNE     0x04
#define RFF     0x08
#define BSY     0x10

/*----------------------------------------------------------------------------
 *      SPI Driver Functions
 *----------------------------------------------------------------------------
 *  Required functions for SPI driver module:
 *   - void spi_init ()
 *   - void spi_ss (U32 cs ,U32 ss)
 *   - U8   spi_send (U8 outb)
 *   - void spi_hi_speed (BOOL on)
 *---------------------------------------------------------------------------*/

/*--------------------------- spi_init --------------------------------------*/

void spi_init (void) {
   /* Initialize and enable the SSP Interface module. */

  SC->PCONP        |= (1 << 21);              /* Enable power to SSPI0 block  */

  /* SSEL is GPIO, output set to high. */
  GPIO0->FIODIR  |=  (1<<16);                 /* P0.16 is output */
  GPIO0->FIOPIN  |=  (1<<16);                 /* set P0.16 high (SSEL inactiv) */
  PINCON->PINSEL1 &= ~(3<<0);                 /* P0.16 SSEL (used as GPIO) */

  /* SCK, MISO, MOSI are SSP pins. */
  PINCON->PINSEL0 &= ~(3UL<<30);              /* P0.15 cleared */
  PINCON->PINSEL0 |=  (2UL<<30);              /* P0.15 SCK0 */
  PINCON->PINSEL1 &= ~((3<<2) | (3<<4));      /* P0.17, P0.18 cleared */
  PINCON->PINSEL1 |=  ((2<<2) | (2<<4));      /* P0.17 MISO0, P0.18 MOSI0 */

  SC->PCLKSEL1 &= ~(3<<10);                   /* PCLKSP0 = CCLK/4 (18MHz) */
  SC->PCLKSEL1 |=  (1<<10);                   /* PCLKSP0 = CCLK   (72MHz) */

  SSP0->CPSR = 180;                           /* 72MHz / 180 = 400kBit */
                                              /* maximum of 18MHz is possible */    
  SSP0->CR0  = 0x0007;                        /* 8Bit, CPOL=0, CPHA=0         */
  SSP0->CR1  = 0x0002;                        /* SSP0 enable, master          */
}


/*--------------------------- spi_hi_speed ----------------------------------*/

void spi_hi_speed (BOOL on) {
   /* Set a SPI clock speed to desired value. */

   if (on == TRUE) {
      /* Max. 12 MBit used for Data Transfer. */
    SSP0->CPSR =   6;                         /* 72MHz / 6   = 12MBit */
   }
   else {
      /* Max. 400 kBit used in Card Initialization. */
    SSP0->CPSR = 180;                         /* 72MHz / 180 = 400kBit */
   }
}


/*--------------------------- spi_ss ----------------------------------------*/

void spi_ss (U32 cs, U32 ss) {
   /* Enable/Disable SPI Chip Select (drive it high or low). */
    if(cs)
    {
        if (ss) {
        GPIO0->FIOPIN |= (1<<19);                 /* SSEL is GPIO, output set to high. */
        } else {
        GPIO0->FIOPIN &= ~(1<<19);                /* SSEL is GPIO, output set to high. */
        }
    }
    else
    {
        if (ss) {
        GPIO0->FIOPIN |= (1<<16);                 /* SSEL is GPIO, output set to high. */
        } else {
        GPIO0->FIOPIN &= ~(1<<16);                /* SSEL is GPIO, output set to high. */
        }	
    }

}

/*--------------------------- spi_send --------------------------------------*/

U8 spi_send (U8 outb) {
   /* Write and Read a byte on SPI interface. */

  SSP0->DR = outb;
  while (SSP0->SR & BSY);                     /* Wait for transfer to finish */
  return (SSP0->DR);                          /* Return received value */

}


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
