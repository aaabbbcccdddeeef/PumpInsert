/*
**************************************************************************
* File: OCM324240.C
* Descriptions:
* Version: V04 -> 使用宏来进行操作，方便以后的移植，更好的将程序分层
**************************************************************************
*/

#ifndef _RXLCD_H_
#define _RXLCD_H_

#define PCB_LCD_VERSION            002

#define PWM_REG                          0x8b

#if(PCB_LCD_VERSION == 002)
#define DATA_BUS_WR_MASK1   0x00ffc000
#define DATA_BUS_WR_MASK2   0x00000700
#define DATA_BUS_WR_MASK3   0x00000010
#define DATA_BUS_WR_MASK4   0x00000003
#define DATA_BUS_RD_MASK1    0x0000ffc0
#define DATA_BUS_RD_MASK2    0x00000038
#define DATA_BUS_RD_MASK3    0x00000004
#define DATA_BUS_RD_MASK4    0x00000003

#define DATA_BUS_WR(x) (GPIO1->FIOPIN = (((x<<8)&DATA_BUS_WR_MASK1)|((x<<5)&DATA_BUS_WR_MASK2)|((x<<2)&DATA_BUS_WR_MASK3)|(x&DATA_BUS_WR_MASK4)))            
#define DATA_BUS_RD (((GPIO1->FIOPIN >> 8)&DATA_BUS_RD_MASK1)|((GPIO1->FIOPIN >> 5)&DATA_BUS_RD_MASK2)|((GPIO1->FIOPIN >> 2)&DATA_BUS_RD_MASK3)|(GPIO1->FIOPIN & DATA_BUS_RD_MASK4))
#define DATA_BUS_OUTPUT                GPIO1->FIODIR |= 0x00ffc713;
#define DATA_BUS_INPUT                GPIO1->FIODIR &= ~0x00ffc713;

#define RST_L (GPIO2->FIOCLR = (1ul<< 6 ))
#define RST_H (GPIO2->FIOSET = (1ul<< 6 ))

#define CS_L (GPIO2->FIOCLR = (1ul<< 1 ))
#define CS_H (GPIO2->FIOSET = (1ul<< 1 ))

#define RD_L (GPIO2->FIOCLR = (1ul<< 12 ))
#define RD_H (GPIO2->FIOSET = (1ul<< 12 ))

#define WR_L (GPIO2->FIOCLR = (1ul<< 11 ))
#define WR_H (GPIO2->FIOSET = (1ul<< 11 ))

#define RS_L (GPIO2->FIOCLR = (1ul<< 0 ))
#define RS_H (GPIO2->FIOSET = (1ul<< 0 ))
#elif(PCB_LCD_VERSION == 001)
#define DATA_BUS_WR_MASK1   0x00ffc000
#define DATA_BUS_WR_MASK2   0x00000700
#define DATA_BUS_WR_MASK3   0x00000010
#define DATA_BUS_WR_MASK4   0x00000003
#define DATA_BUS_RD_MASK1    0x0000ffc0
#define DATA_BUS_RD_MASK2    0x00000038
#define DATA_BUS_RD_MASK3    0x00000004
#define DATA_BUS_RD_MASK4    0x00000003

#define DATA_BUS_WR(x) (GPIO1->FIOPIN = (((x<<8)&DATA_BUS_WR_MASK1)|((x<<5)&DATA_BUS_WR_MASK2)|((x<<2)&DATA_BUS_WR_MASK3)|(x&DATA_BUS_WR_MASK4)))            
#define DATA_BUS_RD (((GPIO1->FIOPIN >> 8)&DATA_BUS_RD_MASK1)|((GPIO1->FIOPIN >> 5)&DATA_BUS_RD_MASK2)|((GPIO1->FIOPIN >> 2)&DATA_BUS_RD_MASK3)|(GPIO1->FIOPIN & DATA_BUS_RD_MASK4))
#define DATA_BUS_OUTPUT                GPIO1->FIODIR |= 0x00ffc713;
#define DATA_BUS_INPUT                GPIO1->FIODIR &= ~0x00ffc713;

#define RST_L (GPIO2->FIOCLR = (1ul<< 0 ))
#define RST_H (GPIO2->FIOSET = (1ul<< 0 ))

#define CS_L (GPIO2->FIOCLR = (1ul<< 3 ))
#define CS_H (GPIO2->FIOSET = (1ul<< 3 ))

#define RD_L (GPIO2->FIOCLR = (1ul<< 1 ))
#define RD_H (GPIO2->FIOSET = (1ul<< 1 ))

#define WR_L (GPIO2->FIOCLR = (1ul<< 2 ))
#define WR_H (GPIO2->FIOSET = (1ul<< 2 ))

#define RS_L (GPIO2->FIOCLR = (1ul<< 4 ))
#define RS_H (GPIO2->FIOSET = (1ul<< 4 ))
#endif


extern void RA8870_PLL_ini(void);
extern void RXLCD_init(void);
extern void Write_Command(unsigned char  Cmd) ;
extern void Write_Data(unsigned short  Data) ;
extern unsigned char  Read_Status(void);
extern unsigned short  Read_Data(void);
extern unsigned short  Read_Command(void) ;
extern void Write_Dir(unsigned char  Cmd,unsigned short  Data);
extern void Reset(void);
extern void Chk_Busy(void);
extern void Chk_Busy_BTE(void);
extern void Set_WinSize(unsigned short XL,unsigned short XR ,unsigned short YT ,unsigned short YB);
extern void MemoryWrite_Position(unsigned short X,unsigned short Y);
extern void Draw_Line(unsigned short XS,unsigned short XE ,unsigned short YS,unsigned short YE);
extern void  Draw_Circle(unsigned short X,unsigned short Y,unsigned short R);
extern void BTE_Source(unsigned short SX,unsigned short DX ,unsigned short SY ,unsigned short DY);
extern void BTE_Size(unsigned short width,unsigned short height);
extern void Scroll_Window(unsigned short XL,unsigned short XR ,unsigned short YT ,unsigned short YB);
extern void Scroll(unsigned short X,unsigned short Y);
extern void String(unsigned char *str);
extern void Cursor_Position(unsigned short X,unsigned short Y);
extern void RXLCD_SetPixelIndex(int x, int y, int PixelIndex) ;
extern unsigned int RXLCD_GetPixelIndex(int x, int y) ;
extern void RXLCD_XorPixel(int x, int y);
extern void RXLCD_DrawHLine(int x0, int y,  int x1, int color);
extern void RXLCD_DrawXorHLine(int x0, int y,  int x1, int color);
extern void RXLCD_DrawVLine(int x, int y0,  int y1, int color);
extern void RXLCD_clear (unsigned char  Color) ;

#endif
