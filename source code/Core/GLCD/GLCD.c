/*----------------------------------------------------------------------------
 * Name:    GLCD.c
 * Purpose: MCB1700 low level Graphic LCD (320x240 pixels) functions
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

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "define.h"
#include "GLCD.h"
#include "font.h"


/*********************** Hardware specific configuration **********************/

/*------------------------- Speed dependant settings -------------------------*/

/* If processor works on high frequency delay has to be increased, it can be 
   increased by factor 2^N by this constant                                   */
#define DELAY_2N    18

/*---------------------- Graphic LCD size definitions ------------------------*/

#define WIDTH       320                 /* Screen Width (in pixels)           */
#define HEIGHT      240                 /* Screen Hight (in pixels)           */
#define BPP         16                  /* Bits per pixel                     */
#define BYPP        ((BPP+7)/8)         /* Bytes per pixel                    */

/*--------------- Graphic LCD interface hardware definitions -----------------*/

#define SSP_START   (0x70)              /* Start byte for SSP transfer        */
#define SSP_RD      (0x01)              /* WR bit 1 within start              */
#define SSP_WR      (0x00)              /* WR bit 0 within start              */
#define SSP_DATA    (0x02)              /* RS bit 1 within start byte         */
#define SSP_INDEX   (0x00)              /* RS bit 0 within start byte         */
 
/*---------------------------- Global variables ------------------------------*/

/******************************************************************************/
static volatile unsigned short TextColor = Black, BackColor = White;


/************************ Local auxiliary functions ***************************/

/*******************************************************************************
* Delay in while loop cycles                                                   *
*   Parameter:    cnt:    number of while cycles to delay                      *
*   Return:                                                                    *
*******************************************************************************/

static void delay (int cnt) 
{

  cnt <<= DELAY_2N;
  while (cnt--);
}


/*******************************************************************************
* Send 1 byte over serial communication                                        *
*   Parameter:    byte:   byte to be sent                                      *
*   Return:                                                                    *
*******************************************************************************/

static unsigned char ssp_send (unsigned char byte) 
{

  SSP1->DR = byte;
  while (SSP1->SR & (1 << 4));          /* Wait for transfer to finish        */
  return (SSP1->DR);                    /* Return received value              */
}


/*******************************************************************************
* Write command to LCD controller                                              *
*   Parameter:    c:      command to be written                                *
*   Return:                                                                    *
*******************************************************************************/

static void wr_cmd (unsigned char c) 
{

  GPIO0->FIOPIN &= ~(1 << 6);
  ssp_send(SSP_START | SSP_WR | SSP_INDEX);   /* Write : RS = 0, RW = 0       */
  ssp_send(0);
  ssp_send(c);
  GPIO0->FIOPIN |=  (1 << 6);
}


/*******************************************************************************
* Write data to LCD controller                                                 *
*   Parameter:    c:      data to be written                                   *
*   Return:                                                                    *
*******************************************************************************/

static void wr_dat (unsigned short c) 
{

  GPIO0->FIOPIN &= ~(1 << 6);
  ssp_send(SSP_START | SSP_WR | SSP_DATA);    /* Write : RS = 1, RW = 0       */
  ssp_send((c >>   8));                       /* Write D8..D15                */
  ssp_send((c & 0xFF));                       /* Write D0..D7                 */
  GPIO0->FIOPIN |=  (1 << 6);
}


/*******************************************************************************
* Read data from LCD controller                                                *
*   Parameter:                                                                 *
*   Return:               read data                                            *
*******************************************************************************/

static unsigned short rd_dat (void) 
{
  unsigned short val = 0;

  GPIO0->FIOPIN &= ~(1 << 6);
  ssp_send(SSP_START | SSP_RD | SSP_DATA);    /* Read: RS = 1, RW = 1         */
  ssp_send(0);                                /* Dummy read                   */
  val   = ssp_send(0);                        /* Read D8..D15                 */
  val <<= 8;
  val  |= ssp_send(0);                        /* Read D0..D7                  */
  GPIO0->FIOPIN |=  (1 << 6);
  return (val);
}

/*******************************************************************************
* Write to LCD register                                                        *
*   Parameter:    reg:    register to be read                                  *
*                 val:    value to write to register                           *
*******************************************************************************/

static void wr_reg (unsigned char reg, unsigned short val) 
{

  wr_cmd(reg);
  wr_dat(val);
}


/*******************************************************************************
* Read from LCD register                                                       *
*   Parameter:    reg:    register to be read                                  *
*   Return:               value read from register                             *
*******************************************************************************/

static unsigned short rd_reg (unsigned char reg) 
{

  wr_cmd(reg);
  return (rd_dat());
}


/************************ Exported functions **********************************/

/*******************************************************************************
* Initialize the Graphic LCD controller                                        *
*   Parameter:                                                                 *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_init (void) 
{ 
  //static unsigned short driverCode;

  /* Configure the LCD Control pins ------------------------------------------*/
  PINCON->PINSEL9 &= ~(3 << 24);        /* Pin P4.28 used for backlight       */
  GPIO4->FIODIR   |=  (1 << 28);        /* Pin P2.28 is output                */
  PINCON->PINSEL9 &= ~(3 << 26);        /* Pin P4.29 used for LCD CS          */
  GPIO4->FIODIR   |=  (1 << 29);        /* Pin P2.29 is output                */
  GPIO4->FIOPIN   |=  (1 << 29);        /* Pin P2.29 is high                  */

  /*-- SSP Configuration -----------------------------------------------------*/
  SC->PCONP       |=  (1 << 10);        /* Enable power to SSP1 block         */
  SC->PCLKSEL0    |=  (1 << 20);        /* SSP1 clock = CCLK / 2              */
  GPIO0->FIODIR   |=  (1 <<  6);        /* Pin P0.6 is GPIO output (SSEL1)    */
  GPIO0->FIOSET    =  (1 <<  6);        /* Set P0.6 high                      */
  PINCON->PINSEL0 &= ~0x000FC000;
  PINCON->PINSEL0 |=  0x000A8000;       /* Select SSP mode for SSP pins       */

  SSP1->CR0        =  (    1  << 7) |   /* CPHA = 1                           */
                      (    1  << 6) |   /* CPOL = 1                           */
                      (    0  << 4) |   /* Frame format = SPI                 */
                      (( 8-1) << 0) ;   /* Data size = 8 bits                 */
  SSP1->CPSR       =  2;                /* Clock Rate = 18MHz                 */
  SSP1->CR1        =  (    1  << 1);    /* Enable SSP1                        */

  delay(5);                             /* Delay 50 ms                        */
  //driverCode = rd_reg(0x00);

  /* Start Initial Sequence --------------------------------------------------*/
  wr_reg(0xE3, 0x3008);  
  wr_reg(0xE7, 0x0012);  
  wr_reg(0xEF, 0x1231);  
  
//  wr_reg(0xE5, 0x8000);                 /* Set the internal vcore voltage     */
  wr_reg(0x00, 0x0001);                 /* Start internal OSC                 */
  wr_reg(0x01, 0x0100);                 /* Set SS and SM bit                  */
  wr_reg(0x02, 0x0700);                 /* Set 1 line inversion               */
  wr_reg(0x03, 0x1030);                 /* Set GRAM write direction and BGR=1 */
  wr_reg(0x04, 0x0000);                 /* Resize register                    */
  wr_reg(0x08, 0x0207);                 /* 2 lines each, back and front porch */
  wr_reg(0x09, 0x0000);                 /* Set non-disp area refresh cyc ISC  */
  wr_reg(0x0A, 0x0000);                 /* FMARK function                     */
  wr_reg(0x0C, 0x0000);                 /* RGB interface setting              */
  wr_reg(0x0D, 0x0000);                 /* Frame marker Position              */
  wr_reg(0x0F, 0x0000);                 /* RGB interface polarity             */

  /* Power On sequence -------------------------------------------------------*/
  wr_reg(0x10, 0x0000);                 /* Reset Power Control 1              */
  wr_reg(0x11, 0x0007);                 /* Reset Power Control 2              */
  wr_reg(0x12, 0x0000);                 /* Reset Power Control 3              */
  wr_reg(0x13, 0x0000);                 /* Reset Power Control 4              */
  delay(20);                            /* Discharge cap power voltage (200ms)*/
  wr_reg(0x10, 0x1690);                 /* SAP, BT[3:0], AP, DSTB, SLP, STB   */
  wr_reg(0x11, 0x0227);                 /* DC1[2:0], DC0[2:0], VC[2:0]        */
  delay(5);                             /* Delay 50 ms                        */
  wr_reg(0x12, 0x001B);                 /* VREG1OUT voltage                   */
  delay(5);                             /* Delay 50 ms                        */
  wr_reg(0x13, 0x1600);                 /* VDV[4:0] for VCOM amplitude        */
  wr_reg(0x29, 0x0018);                 /* VCM[4:0] for VCOMH                 */
  wr_reg(0x2B, 0x000C);  
  delay(5);                             /* Delay 50 ms                        */
  wr_reg(0x20, 0x0000);                 /* GRAM horizontal Address            */
  wr_reg(0x21, 0x0000);                 /* GRAM Vertical Address              */

  /* Adjust the Gamma Curve --------------------------------------------------*/
  wr_reg(0x30, 0x0000);
  wr_reg(0x31, 0x0404);
  wr_reg(0x32, 0x0304);
  wr_reg(0x35, 0x0005);
  wr_reg(0x36, 0x1604);
  wr_reg(0x37, 0x0304);
  wr_reg(0x38, 0x0303);
  wr_reg(0x39, 0x0707);
  wr_reg(0x3C, 0x0500);
  wr_reg(0x3D, 0x000F);
  
  /* Set GRAM area -----------------------------------------------------------*/
  wr_reg(0x50, 0x0000);                 /* Horizontal GRAM Start Address      */
  wr_reg(0x51, (HEIGHT-1));             /* Horizontal GRAM End   Address      */
  wr_reg(0x52, 0x0000);                 /* Vertical   GRAM Start Address      */
  wr_reg(0x53, (WIDTH-1));              /* Vertical   GRAM End   Address      */
  wr_reg(0x60, 0xA700);                 /* Gate Scan Line                     */
  wr_reg(0x61, 0x0001);                 /* NDL,VLE, REV                       */
  wr_reg(0x6A, 0x0000);                 /* Set scrolling line                 */

  /* Partial Display Control -------------------------------------------------*/
  wr_reg(0x80, 0x0000);
  wr_reg(0x81, 0x0000);
  wr_reg(0x82, 0x0000);
  wr_reg(0x83, 0x0000);
  wr_reg(0x84, 0x0000);
  wr_reg(0x85, 0x0000);

  /* Panel Control -----------------------------------------------------------*/
  wr_reg(0x90, 0x0010);
  wr_reg(0x92, 0x6000);
//  wr_reg(0x93, 0x0003);
//  wr_reg(0x95, 0x0110);
//  wr_reg(0x97, 0x0000);
//  wr_reg(0x98, 0x0000);

  /* Set GRAM write direction and BGR = 1
     I/D=10 (Horizontal : increment, Vertical : increment)
     AM=1 (address is updated in vertical writing direction)                  */
  wr_reg(0x03, 0x1038);

  wr_reg(0x07, 0x0133);                 /* 262K color and display ON          */
  GPIO4->FIOPIN   |=  (1 << 28);        /* Turn backlight on                  */
}


void GLCD_SetPixelIndex(int x, int y, int PixelIndex) 
{

    //wr_reg(0x21, (319-x));
       
       wr_cmd(0x21);
  wr_dat((319-x));
    //wr_reg(0x20, y);
      wr_cmd(0x20);
  wr_dat(y);
    //wr_reg(0x22, PixelIndex);
  wr_cmd(0x22);
  wr_dat(PixelIndex);


}

unsigned int GLCD_GetPixelIndex(int x, int y) 
{
    u16 temp;
    
    //wr_reg(0x21, (319-x));
           wr_cmd(0x21);
  wr_dat((319-x));
    //wr_reg(0x20, y);
          wr_cmd(0x20);
  wr_dat(y);
  
    //temp = rd_reg(0x22);
      wr_cmd(0x22);
  temp = rd_dat();

    return  (((temp)  & 0x1f)<<11) + (((temp>>5)  & 0x3f)<<5) + (((temp>>11) & 0x1f));
}

void GLCD_XorPixel(int x, int y)
{
  u16 Index = GLCD_GetPixelIndex(x,y);
  GLCD_SetPixelIndex(x,y,0xFFFF -Index);
}

void GLCD_DrawHLine(int x0, int y,  int x1, int color)
{
    wr_reg(0x20, y);
    wr_reg(0x21, (319-x1));
    wr_cmd(0x22);
    for(;x0<=x1;x0++)
    {
        
        wr_dat(color);
    }
}
void GLCD_DrawXorHLine(int x0, int y,  int x1, int color)
{
    wr_reg(0x20, y);
    wr_reg(0x21, (319-x1));
    wr_cmd(0x22);
    for(;x0<=x1;x0++)
    {
        
        wr_dat(0xffff-color);
    }
}
void GLCD_DrawVLine(int x, int y0,  int y1, int color)
{
    wr_reg(0x21, (319-x));
    for(;y0<=y1;y0++)
    {
        wr_reg(0x20, y0);
        wr_reg(0x22, color);
    }
    
}
void GLCD_FillRect(int x0, int y0, int x1, int y1 ,int color)
{
    for (; y0 <= y1; y0++)
    {
        GLCD_DrawHLine(x0,y0, x1, color);
    }
}
/*******************************************************************************
* Set foreground color                                                         *
*   Parameter:    color:  color for clearing display                           *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_setTextColor(unsigned short color) 
{
  TextColor = color;
}


/*******************************************************************************
* Set background color                                                         *
*   Parameter:    color:  color for clearing display                           *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_setBackColor(unsigned short color) 
{
  BackColor = color;
}


/*******************************************************************************
* Clear display                                                                *
*   Parameter:    color:  color for clearing display                           *
*   Return:                                                                    *
*******************************************************************************/

void GLCD_clear (unsigned short color) 
{
  unsigned int   i;

  wr_reg(0x20, 0);
  wr_reg(0x21, 0);
  wr_cmd(0x22);
  for(i = 0; i < (WIDTH*HEIGHT); i++)
    wr_dat(color);
}


/*******************************************************************************
* Draw character on given position (line, coloum                               *
*   Parameter:     x :        horizontal position                              *
*                  y :        vertical position                                *
*                  c*:        pointer to color value                           *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_drawChar(unsigned int x, unsigned int y, unsigned short *c) 
{
  unsigned int index = 0;
  int  i = 0;
  unsigned int Xaddress = 0;
   
  Xaddress = x;
  
  wr_reg(0x20, Xaddress);
  wr_reg(0x21, y);
  
  for(index = 0; index < 24; index++)
  {
    wr_cmd(0x22);              /* Prepare to write GRAM */
    for(i = 15; i >= 0; i--)
//    for(i = 0; i < 16; i++)
    {
      if((c[index] & (1 << i)) == 0x00) {
        wr_dat(BackColor);
      } else {
        wr_dat(TextColor);
      }
    }
    Xaddress++;
    wr_reg(0x20, Xaddress);
    wr_reg(0x21, y);
  }
}


/*******************************************************************************
* Disply character on given line                                               *
*   Parameter:     c :        ascii character                                  *
*                  ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_displayChar(unsigned int ln, unsigned int col, unsigned char  c) 
{
  c -= 32;
  GLCD_drawChar(ln, col, &ASCII_Table[c * 24]);
}


/*******************************************************************************
* Disply string on given line                                                  *
*   Parameter:     s*:        pointer to string                                *
*                  ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_displayStringLn(unsigned int ln, unsigned char *s) 
{
  unsigned int i = 0;
  unsigned int refcolumn = (WIDTH/*-1*/)-16;

  while ((*s != 0) & (i < 20))                   /* write the string character by character on lCD */
  {
    GLCD_displayChar(ln, refcolumn, *s);         /* Display one character on LCD */
    refcolumn -= 16;                             /* Decrement the column position by 16 */
    s++;                                         /* Point on the next character */
    i++;                                         /* Increment the character counter */
  }
}
/*******************************************************************************
* Disply string on given line                                                  *
*   Parameter:     s*:        pointer to string                                *
*                  ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_displayStringAt(const char *s,unsigned int x, unsigned int y )
{

  while (*s != 0)                   /* write the string character by character on lCD */
  {
    GLCD_displayChar(y, x, *s);         /* Display one character on LCD */
    s++;                                         /* Point on the next character */
  }
}

/*******************************************************************************
* Clear given line                                                             *
*   Parameter:     ln:        line number                                      *
*   Return:                                                                    *
*******************************************************************************/
void GLCD_clearLn(unsigned int ln) 
{
  GLCD_displayStringLn(ln, "                    ");
}


/*******************************************************************************
* Display graphical bitmap image at position x horizontally and y vertically   *
* (This function is optimized for 16 bits per pixel format, it has to be       *
*  adapted for any other bits per pixel format)                                *
*   Parameter:      x:        horizontal position                              *
*                   y:        vertical position                                *
*                   w:        width of bitmap                                  *
*                   h:        height of bitmap                                 *
*                   bitmap:   address at which the bitmap data resides         *
*   Return:                                                                    *
*******************************************************************************/

void GLCD_bitmap (unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned char *bitmap) 
{
  unsigned int   i;
  unsigned int   len = w*h;
  unsigned short *bitmap_ptr = (unsigned short *)bitmap;

  wr_reg(0x50, y);                      /* Horizontal GRAM Start Address      */
  wr_reg(0x51, y+h-1);                  /* Horizontal GRAM End   Address (-1) */
  wr_reg(0x52, x);                      /* Vertical   GRAM Start Address      */
  wr_reg(0x53, x+w-1);                  /* Vertical   GRAM End   Address (-1) */

  wr_reg(0x20, y);
  wr_reg(0x21, x);

  wr_cmd(0x22);
  for (i = 0; i < len; i++) {
    wr_dat(*bitmap_ptr++);
  }
}



/******************************************************************************/
