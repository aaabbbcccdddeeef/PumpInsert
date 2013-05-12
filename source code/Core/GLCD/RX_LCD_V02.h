/*
**************************************************************************
* File: RX_LCD_V02.h
* Descriptions:
* Version: V04 -> 使用宏来进行操作，方便以后的移植，更好的将程序分层
**************************************************************************
*/

#ifndef _RXLCD_V02_H_
#define _RXLCD_V02_H_

#define PCB_LCD_VERSION            002

#define PWM_REG                          0x8d

#define _TANSPERENT_ON              1
#define _TANSPERENT_OFF              0

#define _FONT_SIZE_MIN              0
#define _FONT_SIZE_NORMAL              1
#define _FONT_SIZE_MAX              2

#define color_brown   0x40c0
#define color_black   0x0000
#define color_white   0xffff
#define color_red     0xf800
#define color_green   0x07e0
#define color_blue    0x001f
#define color_yellow  color_red|color_green
#define color_cyan    color_green|color_blue
#define color_purple  color_red|color_blue
#define Black           0x0000		/*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x39E7//64,64,64 //0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255, 0   */
#define White           0xFFFF      /* 255, 255, 255 */

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

#define RST_L (GPIO2->FIOCLR = (1ul<< 4 ))
#define RST_H (GPIO2->FIOSET = (1ul<< 4 ))

#define CS_L (GPIO2->FIOCLR = (1ul<< 1 ))
#define CS_H (GPIO2->FIOSET = (1ul<< 1 ))

#define RD_L (GPIO2->FIOCLR = (1ul<< 3 ))
#define RD_H (GPIO2->FIOSET = (1ul<< 3 ))

#define WR_L (GPIO2->FIOCLR = (1ul<< 2 ))
#define WR_H (GPIO2->FIOSET = (1ul<< 2 ))

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
extern u8 g_u8LcdLayer;

extern void RXLCD_init(void);
extern void Write_Command(unsigned char  Cmd) ;
extern void Write_Data(unsigned short  Data) ;
extern unsigned char  Read_Status(void);
extern unsigned short  Read_Data(void) ;
extern unsigned short  Read_Command(void) ;
extern void Write_Dir(unsigned char  Cmd,unsigned short  Data);
extern void Chk_Busy(void);
extern void Chk_Busy_BTE(void);
extern void Chk_DMA_Busy(void);
extern void Active_Window(unsigned long XL,unsigned long XR ,unsigned long YT ,unsigned long YB);
extern void Text_Background_Color1(unsigned long b_color);
extern void Text_Foreground_Color1(unsigned long b_color);
extern void Text_Background_Color(unsigned char setR, unsigned char setG, unsigned char setB);
extern void Text_Foreground_Color(unsigned char setR,unsigned char setG,unsigned char setB);
extern void BTE_Size(unsigned short width,unsigned short height);
extern void BTE_Source(u8 SourceLayer, u8 DestiLayer,unsigned short SX,unsigned short DX ,unsigned short SY ,unsigned short DY);
extern void BTE_MovePositive(u8 SourceLayer, u8 DestiLayer, u16 x1, u16 y1, u16 x2, u16 y2,u16 x, u16 y);

extern void MemoryWrite_Position(unsigned short X,unsigned short Y);
extern void FontWrite_Position(unsigned short X,unsigned short Y);
extern void String(unsigned char *str);
extern void Cursor_Position(unsigned short X,unsigned short Y);
extern void Scroll_Window(unsigned short XL,unsigned short XR ,unsigned short YT ,unsigned short YB);
extern void Scroll(unsigned short X,unsigned short Y);
extern void DMA_block_mode_size_setting(unsigned short BWR,unsigned short BHR,unsigned short SPWR);
extern void DMA_Start_address_setting(unsigned long set_address);
extern void  Draw_Circle(unsigned short X,unsigned short Y,unsigned short R);
extern void  Draw_Ellipse(unsigned short X,unsigned short Y,unsigned short R1,unsigned short R2);
extern void Draw_Line(unsigned short XS,unsigned short XE ,unsigned short YS,unsigned short YE);
extern void Draw_Triangle(unsigned short X3,unsigned short Y3);
extern void displaypicture(unsigned char picnum);

extern void CutPicture(unsigned char picnum,unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,unsigned short x,unsigned short y);
extern void RXLCD_clear (unsigned char Color) ;
extern void RXLCD_SetPixelIndex(int x, int y, int PixelIndex) ;
extern void RXLCD_CutPicture(unsigned char picnum,unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2);
extern unsigned char Touch_Status(void);
extern unsigned char Chk_INT(void);
extern unsigned char Chk_INT2(void);
extern unsigned char ADC_X(void);
extern unsigned char ADC_Y(void);
extern unsigned char ADC_XY(void);
extern void Layer1_Visible(void);
extern void Layer2_Visible(void);
extern void Layers_Progressive(void);
extern void RXLCD_VisibleLayer(void);

extern void RXLCD_ScrollWindow_Next(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2, u8 Speed);
extern void RXLCD_ScrollWindow_Prev(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2, u8 Speed);
extern void RXLCD_ScrollWindow_Up(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2,unsigned char Speed);
extern void RXLCD_ScrollWindow_Down(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2,unsigned char Speed);

extern void RXLCD_EditNext(void);
extern void RXLCD_EditCurrent(void);
extern void WriteString(unsigned char *Str,u16 x, u16 y, u16 Color, u8 Size, u8 transperent );
extern void WriteString1(unsigned char *Str,u16 x, u16 y, u16 Color, u8 Size, u8 transperent );

extern void RXLCD_DrawLine(unsigned short XS,unsigned short YS,unsigned short XE ,unsigned short YE,unsigned short color);

#endif

