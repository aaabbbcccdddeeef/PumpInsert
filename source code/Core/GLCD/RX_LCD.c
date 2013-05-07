/***************************************
*Mϵ��3.5��ר�ò��Գ���
*�ͺţ�VS32240M35
*оƬ��89S52(11.0592M)
*��д��Nicker
*���ڣ�2009/4/19
*�޸ģ�2011/3/18
*
***************************************/
#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "systick.h"
#include "RX_LCD.h"
//#include <reg52.h>
//#include "52-Driver.h"
//#include "Pictures.h"

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;




//#define LCD_PORT GPIOE
//#define LCD_DAT(x) GPIO_Write(LCD_PORT,(x))
/* 
void Delay2us(u32 Counter);
void Delay100us(u32 Counter);
void Delay1ms(u32 Counter);
void Delay10ms(u32 Counter);
void Delay100ms(u32 Counter);
*/ 
void Write_Command(unsigned char cmd);
void Write_Data(unsigned short Data);
void Chk_Busy(void);
void Reset(void);
unsigned short Read_Command(void);
unsigned char Read_Status(void);
unsigned short Read_Data(void);
void RA8870_PLL_ini(void);

#if 1
//********************��ʱ������
void Delay2us(u32 Counter)
{ 
  while(--Counter);
}

void Delay100us(u32 Counter)
{
  while(Counter--)
  {	
   Delay2us(100);
  }
}

void Delay1ms(u32 Counter)
{
  while(Counter--)
  {	
   Delay100us(11);			
  }
}

/* 
void Delay10ms(u32 Counter)
{
  while(Counter--)
  {	
   Delay1ms(11);			
  }
}  
*/ 
void Delay100ms(u32 Counter)
{
  while(Counter--)
  {
   Delay1ms(101);			
  }
}
#endif

//****ϵͳʱ���趨***����ͻ�ֱ����ֲ
void RA8870_PLL_ini(void)
{
    //Write_Command(0x88);      
    //Write_Data(0x06); 
    Write_Data(0x0a); 
    Delay10ms(10); //After REG[88h] or REG[89h] is programmed, a lock time (< 30us) must be kept to guarantee the stability of the PLL output. After the lock time period, a software reset must be asserted and user must re-program the RA8870 to complete the procedure
    Write_Command(0x89);     
    Write_Data(0x02); 
    Delay10ms(10); //After REG[88h] or REG[89h] is programmed, a lock time (< 30us) must be kept to guarantee the stability of the PLL output. After the lock time period, a software reset must be asserted and user must re-program the RA8870 to complete the procedure
    Write_Command(0x01);  //������ʱ������û��������һ�����Reset�����PLLƵ�ʸı�ĳ���   
    Write_Data(0x01);
    Write_Command(0x01);
    Write_Data(0x00);
    Delay10ms(10);
}


//-----ģ���ʼ������----------����ͻ�ֱ����ֲ---------------------------//
void RXLCD_init(void)
{ 	
    Reset();
    Delay10ms(10);
    RA8870_PLL_ini();

    Write_Command(0x10);	 //SYSR   bit[4:3]=00 256 color  bit[2:1]=  00 8bit MPU interface  
    Write_Data(0x1f);
    //internal 64k color  one layer
    			 
    Write_Command(0x11);	 //DRGB bit[2:0]  data bus of parallel panel  000=RGB 001=RBG
    Write_Data(0x00); 
    Write_Command(0x12);	 //IOCR  GPIO& analog TFT interface
    Write_Data(0x00); //
    Write_Command(0x13);	 //IODR  GPIO
    Write_Data(0x05);

    //Horizontal set
    Write_Command(0x14);	 //HDWR//Horizontal Display Width Setting Bit[6:0] 
    Write_Data(0x27); //Horizontal display width(pixels) = (HDWR + 1)*8 
    Write_Command(0x15);	 //HNDFCR//Horizontal Non-Display Period fine tune Bit[3:0] 
    Write_Data(0x8C); //(HNDR + 1)*8 +HNDFCR
    Write_Command(0x16);	 //HNDR//Horizontal Non-Display Period Bit[4:0] 
    Write_Data(0x02); //Horizontal Non-Display Period (pixels) = (HNDR + 1)*8 
    Write_Command(0x17);	 //HSTR//HSYNC Start Position[4:0] 
    Write_Data(0x01); //HSYNC Start Position(PCLK) = (HSTR + 1)*8 
    Write_Command(0x18);	 //HPWR//HSYNC Polarity ,The period width of HSYNC. 
    Write_Data(0x03); //HSYNC Width [4:0]   HSYNC Pulse width(PCLK) = (HPWR + 1)*8 

    //Vertical set
    Write_Command(0x19); //VDHR0 //Vertical Display Height Bit [7:0] 
    Write_Data(0xef); //Vertical pixels = VDHR + 1
    Write_Command(0x1a); //VDHR1 //Vertical Display Height Bit [8] 
    Write_Data(0x00); //Vertical pixels = VDHR + 1 
    Write_Command(0x1b); //VNDR0 //Vertical Non-Display Period Bit [7:0]
    Write_Data(0x0A); //Vertical Non-Display area = (VNDR + 1) 
    Write_Command(0x1c); //VNDR1 //Vertical Non-Display Period Bit [8] 
    Write_Data(0x00); //Vertical Non-Display area = (VNDR + 1) 
    Write_Command(0x1d); //VSTR0 //VSYNC Start Position[7:0]
    Write_Data(0x0e); //VSYNC Start Position(PCLK) = (VSTR + 1) 
    Write_Command(0x1e); //VSTR1 //VSYNC Start Position[8] 
    Write_Data(0x06); //VSYNC Start Position(PCLK) = (VSTR + 1) 
    Write_Command(0x1f);	 //VPWR //VSYNC Polarity ,VSYNC Pulse Width[6:0]
    Write_Data(0x01); //VSYNC Pulse Width(PCLK) = (VPWR + 1) 
    //----PWM initial for Backlight  add by mountain 
    Write_Command(0x8a);//PWM��������
    Write_Data(0x80);//����PWM
    //Write_Command(0x8a);//PWM��������
    //Write_Data(0x81);//����PWM
    Write_Command(0x8b);//��������
    Write_Data(0x05);//���Ȳ���0xff-0x00
    //Write_Command(0x28);  //if use font ROM Speed setting
    //Write_Data(0x02);

    Write_Dir(0x01,0x80);//������ʾ

    //RXLCD_clear();
}

//********************д����
void Write_Command(unsigned char  Cmd) // Command Write
{ 
  CS_L;
  RS_H;
  DATA_BUS_WR(Cmd);
  WR_L;
  Delay2us(1);
  WR_H;
  CS_H;
  DATA_BUS_WR(0xffff);
  RS_L;
}

//********************д����
void Write_Data(unsigned short  Data) 
{

  CS_L;
  RS_L;
  DATA_BUS_WR(Data);
  WR_L;
  Delay2us(1);
  WR_H;
  CS_H;
  DATA_BUS_WR(0xffff);
  RS_H;
}

//********************��״̬
unsigned char  Read_Status(void) // Read Status Register
{

  u16 Data;
  DATA_BUS_INPUT;
  CS_L;
  RS_H;
  WR_H;
  RD_L;
  Delay2us(5);
  Data = DATA_BUS_RD;
  RD_H;
  CS_H;
  DATA_BUS_OUTPUT;
  DATA_BUS_WR(0xffff);
  RS_L;
  
  
  return Data;

}

//********************������
unsigned short  Read_Data(void) // Data Read
{
  unsigned short  Data;

  DATA_BUS_INPUT;
  WR_H;
  CS_L;
  RS_L;
  RD_L;
  Delay2us(5);
  Data = DATA_BUS_RD;
  RD_H;
  CS_H;
  DATA_BUS_OUTPUT;
  DATA_BUS_WR(0xffff);
  RS_H;
  
  
  return Data;
}

//*********************������
unsigned short  Read_Command(void) // Command Read��Read Register��
{
  unsigned short  Data;

  DATA_BUS_INPUT;
  CS_L;
  RS_H;
  WR_H;
  RD_L;
  Delay2us(5);
  Data = DATA_BUS_RD;
  RD_H;
  CS_H;
  DATA_BUS_OUTPUT;
  DATA_BUS_WR(0xffff);
  RS_L;
  
  
  return Data;
}

//***********************дָ��
void Write_Dir(unsigned char  Cmd,unsigned short  Data)
{
  Write_Command(Cmd);
  Write_Data(Data);
}

// **********************Reset 

void Reset(void)
{ 
  RST_L;
  Delay10ms(10);
  RST_H;
  Delay10ms(10);
  Chk_Busy();
}

//***********************��æ
void Chk_Busy(void)
{
  unsigned char  temp;
   do
   { 
    temp=Read_Status();
   } 
  while((temp&0x80)==0x80);
}

void Chk_Busy_BTE(void)
{
  unsigned char temp;
   do
   {
    temp=Read_Status();
   }
  while((temp&0x40)==0x40);	   
}	
//�������ڵ��趨����������趨��������ο��û��ֲ�
void Set_WinSize(unsigned short XL,unsigned short XR ,unsigned short YT ,unsigned short YB)
{
	unsigned short temp;
    //setting active window X
	temp=XL;   
    Write_Command(0x30);//HSAW0
	Write_Data(temp);
	temp=XL>>8;   
    Write_Command(0x31);//HSAW1	   
	Write_Data(temp);

	temp=XR;   
    Write_Command(0x34);//HEAW0
	Write_Data(temp);
	temp=XR>>8;   
    Write_Command(0x35);//HEAW1	   
	Write_Data(temp);

    //setting active window Y
	temp=YT;   
    Write_Command(0x32);//VSAW0
	Write_Data(temp);
	temp=YT>>8;   
    Write_Command(0x33);//VSAW1	   
	Write_Data(temp);

	temp=YB;   
    Write_Command(0x36);//VEAW0
	Write_Data(temp);
	temp=YB>>8;   
    Write_Command(0x37);//VEAW1	   
	Write_Data(temp);
}
//********����д���ַ����
void MemoryWrite_Position(unsigned short X,unsigned short Y)
{
	unsigned short temp;

	temp=X;   
    Write_Command(0x46);
	Write_Data(temp);
	temp=X>>8;   
    Write_Command(0x47);	   
	Write_Data(temp);

	temp=Y;   
    Write_Command(0x48);
	Write_Data(temp);
	temp=Y>>8;   
    Write_Command(0x49);	   
	Write_Data(temp);
}

//****************���߻������ʼλ������
void Draw_Line(unsigned short XS,unsigned short XE ,unsigned short YS,unsigned short YE)
{
    unsigned short temp;    
	temp=XS;   
    Write_Command(0x91);
	Write_Data(temp);
	temp=XS>>8;   
    Write_Command(0x92);	   
	Write_Data(temp);

	temp=XE;
    Write_Command(0x95);
	Write_Data(temp);
	temp=XE>>8;   
    Write_Command(0x96);	   
	Write_Data(temp);

	temp=YS;   
    Write_Command(0x93);
	Write_Data(temp);
	temp=YS>>8;   
    Write_Command(0x94);	   
	Write_Data(temp);

	temp=YE;   
    Write_Command(0x97);
	Write_Data(temp);
	temp=YE>>8;   
    Write_Command(0x98);	   
	Write_Data(temp);
}

//****************Բ��ͼ��Բ��λ�ü��뾶����`
void  Draw_Circle(unsigned short X,unsigned short Y,unsigned short R)
{
	unsigned short temp;
    
	temp=X;   
    Write_Command(0x99);
	Write_Data(temp);
	temp=X>>8;   
    Write_Command(0x9a);	   
	Write_Data(temp);  
	  
	temp=Y;   
    Write_Command(0x9b);
	Write_Data(temp);
	temp=Y>>8;   
    Write_Command(0x9c);	   
	Write_Data(temp);

	temp=R;   
    Write_Command(0x9d);
	Write_Data(temp);
} 

//*******************BET��ȡλ���趨
void BTE_Source(unsigned short SX,unsigned short DX ,unsigned short SY ,unsigned short DY)
{
	unsigned short temp,temp1;
    
	temp=SX;   
    Write_Command(0x54);//BTE��ȡ����ˮƽλ��
	Write_Data(temp);
	temp=SX>>8;   
    Write_Command(0x55);//BET��ȡ����ˮƽλ��   
	Write_Data(temp);

	temp=DX;
    Write_Command(0x58);//BETд��Ŀ��ˮƽλ��
	Write_Data(temp);
	temp=DX>>8;   
    Write_Command(0x59);//BETд��Ŀ��ˮƽλ��	   
	Write_Data(temp); 
    
	temp=SY;   
    Write_Command(0x56);//BTE��ȡ���ݴ�ֱλ��
	Write_Data(temp);
	temp=SY>>8;   
    Write_Command(0x57);
	temp1 = Read_Data();
    temp=temp|temp1; 
	Write_Command(0x57);//BTE��ȡ���ݴ�ֱλ��  
	Write_Data(temp);

	temp=DY;   
    Write_Command(0x5a);//BTEд�����ݴ�ֱλ��
	Write_Data(temp);
	temp=DY>>8;   
    Write_Command(0x5b);
	temp1 = Read_Data();
	temp=temp|temp1;	
	Write_Command(0x5b);//BTEд�����ݴ�ֱλ��  
	Write_Data(temp);
}				

//****************BTE�ߴ�		  
void BTE_Size(unsigned short width,unsigned short height)
{	unsigned short temp;
	temp=width;   
    Write_Command(0x5c);//BET��д������
	Write_Data(temp);
	temp=width>>8;   
    Write_Command(0x5d);//BET��д������	   
	Write_Data(temp);

	temp=height;   
    Write_Command(0x5e);//BET��д����߶�
	Write_Data(temp);
	temp=height>>8;   
    Write_Command(0x5f);//BET��д����߶�	   
	Write_Data(temp);
}		

//****************���ھ�����
void Scroll_Window(unsigned short XL,unsigned short XR ,unsigned short YT ,unsigned short YB)
{
	unsigned short temp;
    
	temp=XL;   
    Write_Command(0x38);//HSSW0
	Write_Data(temp);
	temp=XL>>8;   
    Write_Command(0x39);//HSSW1	   
	Write_Data(temp);

	temp=XR;   
    Write_Command(0x3c);//HESW0
	Write_Data(temp);
	temp=XR>>8;   
    Write_Command(0x3d);//HESW1	   
	Write_Data(temp);   
    
	temp=YT;   
    Write_Command(0x3a);//VSSW0
	Write_Data(temp);
	temp=YT>>8;   
    Write_Command(0x3b);//VSSW1	   
	Write_Data(temp);

	temp=YB;   
    Write_Command(0x3e);//VESW0
	Write_Data(temp);
	temp=YB>>8;   
    Write_Command(0x3f);//VESW1	   
	Write_Data(temp);
}  

//****************���ھ�ƫ��������
void Scroll(unsigned short X,unsigned short Y)
{
	unsigned short temp;
    
	temp=X;   
    Write_Command(0x24);//HOFS0
	Write_Data(temp);
	temp=X>>8;   
    Write_Command(0x25);//HOFS1	   
	Write_Data(temp);

	temp=Y;   
    Write_Command(0x26);//VOFS0
	Write_Data(temp);
	temp=Y>>8;   
    Write_Command(0x27);//VOFS1	   
	Write_Data(temp); 
}	   	  

//****************�����ַ�
void String(unsigned char *str)
{   
    Write_Dir(0x40,0x80);//�����ַ�ģʽ
	Write_Command(0x02);
	while(*str != '\0')
	{
	 Write_Data(*str);
	 ++str;	 	
	 Chk_Busy();		
	}
 
}

//****************�����ʾλ��
void Cursor_Position(unsigned short X,unsigned short Y)
{
	unsigned short temp;
    
	temp=X;   
    Write_Command(0x80);//GCHP0
	Write_Data(temp);
	temp=X>>8;   
    Write_Command(0x81);//GCHP1	   
	Write_Data(temp);

	temp=Y;   
    Write_Command(0x82);//GCVP0
	Write_Data(temp);
	temp=Y>>8;   
    Write_Command(0x83);//GCVP1	   
	Write_Data(temp);  
}			

void RXLCD_SetPixelIndex(int x, int y, int PixelIndex) 
{
  int iTemp;
  
  iTemp = x & 0x00ff;    
  Write_Command(0x46); 
  Write_Data(iTemp); 
  iTemp =(x & 0xff00) >> 8;    
  Write_Command(0x47);
  Write_Data(iTemp); 
  iTemp = y & 0x00ff;    
  Write_Command(0x48); 
  Write_Data(iTemp); 
  iTemp = (y & 0xff00) >> 8;    
  Write_Command(0x49);     
  Write_Data(iTemp); 

  Write_Command(0x02); 
  Write_Data(PixelIndex); 
}

unsigned int RXLCD_GetPixelIndex(int x, int y) 
{
    u16 temp;
    
  temp = x & 0x00ff;    
  Write_Command(0x46); 
  Write_Data(temp); 
  temp =(x & 0xff00) >> 8;    
  Write_Command(0x47);
  Write_Data(temp); 
  temp = y & 0x00ff;    
  Write_Command(0x48); 
  Write_Data(temp); 
  temp = (y & 0xff00) >> 8;    
  Write_Command(0x49);     
  Write_Data(temp); 
  
  Write_Command(0x02); 
  temp = Read_Data();

    return  (((temp)  & 0x1f)<<11) + (((temp>>5)  & 0x3f)<<5) + (((temp>>11) & 0x1f));
}

void RXLCD_XorPixel(int x, int y)
{
  u16 Index = RXLCD_GetPixelIndex(x,y);
  RXLCD_SetPixelIndex(x,y,0xFFFF -Index);
}

void RXLCD_DrawHLine(int x0, int y,  int x1, int color)
{
    u16 temp;
    
    temp = x0 & 0x00ff;    
    Write_Command(0x46); 
    Write_Data(temp); 
    temp =(x0 & 0xff00) >> 8;    
    Write_Command(0x47);
    Write_Data(temp); 
    temp = y & 0x00ff;    
    Write_Command(0x48); 
    Write_Data(temp); 
    temp = (y & 0xff00) >> 8;    
    Write_Command(0x49);     
    Write_Data(temp);

    Write_Command(0x02); 
    for(;x0<=x1;x0++)
    {
        
        Write_Data(color);
    }
}
void RXLCD_DrawXorHLine(int x0, int y,  int x1, int color)
{
    u16 temp;
    
    temp = x0 & 0x00ff;    
    Write_Command(0x46); 
    Write_Data(temp); 
    temp =(x0 & 0xff00) >> 8;    
    Write_Command(0x47);
    Write_Data(temp); 
    temp = y & 0x00ff;    
    Write_Command(0x48); 
    Write_Data(temp); 
    temp = (y & 0xff00) >> 8;    
    Write_Command(0x49);     
    Write_Data(temp);

    Write_Command(0x02); 
    for(;x0<=x1;x0++)
    {
        
        Write_Data(0xffff-color);
    }
}
void RXLCD_DrawVLine(int x, int y0,  int y1, int color)
{
    u16 temp;
    /* 
    temp = x & 0x00ff;    
    Write_Command(0x46); 
    Write_Data(temp); 
    temp =(x & 0xff00) >> 8;    
    Write_Command(0x47);
    Write_Data(temp); 
    */ 
    for(;y0<=y1;y0++)
    {
        temp = x & 0x00ff;    
    Write_Command(0x46); 
    Write_Data(temp); 
    temp =(x & 0xff00) >> 8;    
    Write_Command(0x47);
    Write_Data(temp); 
    temp = y0 & 0x00ff;    
    Write_Command(0x48); 
    Write_Data(temp); 
    temp = (y0 & 0xff00) >> 8;    
    Write_Command(0x49);     
    Write_Data(temp);
    //Write_Command(0x02); 
    Write_Dir(0x02, color);
    }
}


void RXLCD_clear (unsigned char Color) 
{
    Set_WinSize(0,319,0,239);//����������ʾ����
  Write_Dir(0x43,0xff);//�������ֱ�����ɫ(��ɫ)
  Write_Dir(0x8e,0x01);//�����趨(��ʾ����)
  Write_Dir(0x8e,0x81);//��ʼ���������ֱ�����ɫ
    Delay10ms(5); 

}

//*********************


