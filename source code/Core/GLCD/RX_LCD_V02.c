#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "type.h"
#include "systick.h"
#include "define.h"
#include "RX_LCD_V02.h"

void Write_Command(unsigned char cmd);
void Write_Data(unsigned short Data);
void Write_Dir(unsigned char  Cmd,unsigned short  Data);
void Chk_Busy(void);
void Reset(void);
unsigned short Read_Command(void);
unsigned char Read_Status(void);
unsigned short Read_Data(void);

#define _SCROLL_SPEED         8000
u8 g_u8LcdLayer=1;

//********************��ʱ������
void Delay2us(unsigned long Counter)
{ 
  while(--Counter);
}

//****ϵͳʱ���趨***����ͻ�ֱ����ֲ
void RA8870_PLL_ini(void)
{
    Write_Command(0x88);      
    Write_Data(0x0a);
    Delay10ms(2);     
    Write_Command(0x89);        
    Write_Data(0x02);  
    Delay10ms(2);
}


//-----ģ���ʼ������----------����ͻ�ֱ����ֲ---------------------------//
void RXLCD_init(void)
{ 	
    Reset();
    Delay10ms(5);
    RA8870_PLL_ini();

    Write_Command(0x10);	 //SYSR   bit[4:3]=00 256 color  bit[2:1]=  00 8bit MPU interface
    Write_Data(0x0f);   //                 1x 64k color             1x	16bit 						 

    Write_Command(0x04);    //PCLK
    Write_Data(0x03);   //
    Delay10ms(1);

    //Horizontal set
    Write_Command(0x14);	 //HDWR//Horizontal Display Width Setting Bit[6:0]  
    Write_Data(0x3b); //Horizontal display width(pixels) = (HDWR + 1)*8       0x27
    Write_Command(0x15);	 //HNDFCR//Horizontal Non-Display Period fine tune Bit[3:0] 
    Write_Data(0x02); //(HNDR + 1)*8 +HNDFCR
    Write_Command(0x16);	 //HNDR//Horizontal Non-Display Period Bit[4:0] 
    Write_Data(0x03); //Horizontal Non-Display Period (pixels) = (HNDR + 1)*8 
    Write_Command(0x17);	 //HSTR//HSYNC Start Position[4:0] 
    Write_Data(0x01); //HSYNC Start Position(PCLK) = (HSTR + 1)*8 
    Write_Command(0x18);	 //HPWR//HSYNC Polarity ,The period width of HSYNC. 
    Write_Data(0x03); //HSYNC Width [4:0]   HSYNC Pulse width(PCLK) = (HPWR + 1)*8 

    //Vertical set
    Write_Command(0x19); //VDHR0 //Vertical Display Height Bit [7:0] 
    Write_Data(0x0f); //Vertical pixels = VDHR + 1	0xef
    Write_Command(0x1a); //VDHR1 //Vertical Display Height Bit [8] 
    Write_Data(0x01); //Vertical pixels = VDHR + 1 	0x00
    Write_Command(0x1b); //VNDR0 //Vertical Non-Display Period Bit [7:0]
    Write_Data(0x0f); //Vertical Non-Display area = (VNDR + 1) 
    Write_Command(0x1c); //VNDR1 //Vertical Non-Display Period Bit [8] 
    Write_Data(0x00); //Vertical Non-Display area = (VNDR + 1) 
    Write_Command(0x1d); //VSTR0 //VSYNC Start Position[7:0]
    Write_Data(0x0e); //VSYNC Start Position(PCLK) = (VSTR + 1) 
    Write_Command(0x1e); //VSTR1 //VSYNC Start Position[8] 
    Write_Data(0x06); //VSYNC Start Position(PCLK) = (VSTR + 1) 
    Write_Command(0x1f);	 //VPWR //VSYNC Polarity ,VSYNC Pulse Width[6:0]
    Write_Data(0x01); //VSYNC Pulse Width(PCLK) = (VPWR + 1) 

    Write_Command(0x20);	 
    Write_Data(0x80); 
    Write_Dir(0x52,0xc1);//����Ϊ�����ģʽ
    Write_Dir(0x40,0x80);//����Ϊ����ģʽ
    Write_Dir(0x41,0x01);
Layer1_Visible();
    Write_Dir(0xf0,0x04);//�����ж�
    Write_Dir(0x71,0x04);//����Ϊ4�ߴ�����
    Write_Dir(0x70,0xB2);//�����������ܣ����ô�������
    Write_Dir(0xf1,0x04);//clear INT state �_���ϴ��|���� TP_interrupt ���

    
    Write_Command(0x8c);//PWM��������
    Write_Data(0x80);//����PWM
    Write_Command(0x8c);//PWM��������
    Write_Data(0x81);//����PWM
    Write_Command(0x8d);//��������
    Write_Data(0x80);//���Ȳ���0xff-0x00

    Active_Window(0,479,0,271);//����������ʾ����
    Text_Foreground_Color1(0x0000);//ǰ����ɫ�趨
    Text_Background_Color1(0xffff);//������ɫ�趨
    Write_Dir(0X8E,0X80);//��ʼ����(��ʾ����)
    Delay10ms(1); 

    Write_Dir(0X01,0X80);//������ʾ
    
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

  unsigned short Data;
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
  //Chk_Busy();
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
void Chk_DMA_Busy(void)
{
	unsigned char temp; 	
	do
	{
	Write_Command(0xBF);
	temp =Read_Data();
	}while((temp&0x01)==0x01);   
}
//********���ù�����������
void Active_Window(unsigned long XL,unsigned long XR ,unsigned long YT ,unsigned long YB)
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
void Text_Background_Color1(unsigned long b_color)
{
	
	Write_Command(0x60);//BGCR0
	Write_Data((unsigned short)(b_color>>11));
	
	Write_Command(0x61);//BGCR0
	Write_Data((unsigned short)(b_color>>5));
	
	Write_Command(0x62);//BGCR0
	Write_Data((unsigned short)(b_color));
} 


//********ǰ����ɫ����
void Text_Foreground_Color1(unsigned long b_color)
{
	
	Write_Command(0x63);//BGCR0
	Write_Data((unsigned short)(b_color>>11));
	
	Write_Command(0x64);//BGCR0
	Write_Data((unsigned short)(b_color>>5));
	
	Write_Command(0x65);//BGCR0
	Write_Data((unsigned short)(b_color));
} 
//********������ɫ����2
void Text_Background_Color(unsigned char setR, unsigned char setG, unsigned char setB)
{
    Write_Command(0x60);//BGCR0
	Write_Data(setR);
   
    Write_Command(0x61);//BGCR0
	Write_Data(setG);

    Write_Command(0x62);//BGCR0
	Write_Data(setB);
} 

//********ǰ����ɫ����2
void Text_Foreground_Color(unsigned char setR,unsigned char setG,unsigned char setB)
{	    
    Write_Command(0x63);//BGCR0
	Write_Data(setR);
   
    Write_Command(0x64);//BGCR0
	Write_Data(setG);

    Write_Command(0x65);//BGCR0��
	Write_Data(setB);
}
//***********************BTE�����С����
void BTE_Size(unsigned short width,unsigned short height)
{
    unsigned char temp;
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

//***********************BTE��ʼλ������
void BTE_Source(u8 SourceLayer, u8 DestiLayer,unsigned short SX,unsigned short DX ,unsigned short SY ,unsigned short DY)
{
	unsigned char temp,temp1;//temp2;
    
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
    //Write_Command(0x57);
	//temp1 = Read_Data();
	//temp1 &= 0x80;
       temp1 = SourceLayer<<7;
       //temp1 = temp1 & temp2;
    temp=temp|temp1; 
	Write_Command(0x57);//BTE��ȡ���ݴ�ֱλ��  
	Write_Data(temp);

	temp=DY;   
    Write_Command(0x5a);//BTEд�����ݴ�ֱλ��
	Write_Data(temp);
	temp=DY>>8;   
    //Write_Command(0x5b);
	//temp1 = Read_Data();
	//temp1 &= 0x80;
      temp1 = DestiLayer<<7;
      // temp1 = temp1 & temp2;
	temp=temp|temp1;	
	Write_Command(0x5b);//BTEд�����ݴ�ֱλ��  
	Write_Data(temp);
}				
void BTE_MovePositive(u8 SourceLayer, u8 DestiLayer, u16 x1, u16 y1, u16 x2, u16 y2,u16 x, u16 y)
{
    BTE_Source(SourceLayer, DestiLayer, x1, x, y1, y);
    BTE_Size((x2-x1+1), (y2-y1+1));
    Write_Command(0x51);//д��BTE ���������դ������
    Write_Data(0xc2);
    Write_Command(0x50);//д��BTE ���������դ������
    Write_Data(0x80);
    Chk_Busy_BTE();
}
//********�ڴ�д��λ��
void MemoryWrite_Position(unsigned short X,unsigned short Y)
{
	unsigned char temp;

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

//********����д��λ��
void FontWrite_Position(unsigned short X,unsigned short Y)
{
	unsigned char temp;
	temp=X;   
    Write_Command(0x2A);
	Write_Data(temp);
	temp=X>>8;   
    Write_Command(0x2B);	   
	Write_Data(temp);

	temp=Y;   
    Write_Command(0x2C);
	Write_Data(temp);
	temp=Y>>8;   
    Write_Command(0x2D);	   
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
	unsigned char temp;    
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

//****************�����ڴ�С
void Scroll_Window(unsigned short XL,unsigned short XR ,unsigned short YT ,unsigned short YB)
{
	unsigned char temp;    
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
	unsigned char temp;
    
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

//********FLASH��ȡ��������
void DMA_block_mode_size_setting(unsigned short BWR,unsigned short BHR,unsigned short SPWR)
{
  Write_Command(0xB4);
  Write_Data(BWR);
  Write_Command(0xB5);
  Write_Data(BWR>>8);

  Write_Command(0xB6);
  Write_Data(BHR);
  Write_Command(0xB7);
  Write_Data(BHR>>8);

  Write_Command(0xB8);
  Write_Data(SPWR);
  Write_Command(0xB9);
  Write_Data(SPWR>>8);  
}

//********FLASH��ȡ��ʼλ������
void DMA_Start_address_setting(unsigned long set_address)
{ 
  Write_Command(0xB0);
  Write_Data(set_address);

  Write_Command(0xB1);
  Write_Data(set_address>>8);

  Write_Command(0xB2);
  Write_Data(set_address>>16);

  Write_Command(0xB3);
  Write_Data(set_address>>24);
}
//********��Բ�����ĵ㣬�뾶
void  Draw_Circle(unsigned short X,unsigned short Y,unsigned short R)
{
	unsigned char temp;
    
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

//********��Բ���ߣ����ĵ㣬������
void  Draw_Ellipse(unsigned short X,unsigned short Y,unsigned short R1,unsigned short R2)
{
	unsigned char temp;    
	temp=X;   
    Write_Command(0xA5);
	Write_Data(temp);
	temp=X>>8;   
    Write_Command(0xA6);	   
	Write_Data(temp);  
	  
	temp=Y;   
    Write_Command(0xA7);
	Write_Data(temp);
	temp=Y>>8;   
    Write_Command(0xA8);	   
	Write_Data(temp);

	temp=R1;   
    Write_Command(0xA1);
	Write_Data(temp);
	temp=R1>>8;   
    Write_Command(0xA2);	   
	Write_Data(temp);  
	  
	temp=R2;   
    Write_Command(0xA3);
	Write_Data(temp);
	temp=R2>>8;   
    Write_Command(0xA4);	   
	Write_Data(temp);
} 

//********���ߡ������Ρ������Σ���ʼ����
void Draw_Line(unsigned short XS,unsigned short XE ,unsigned short YS,unsigned short YE)
{	
    unsigned char temp;    
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

//********�������ε�������
void Draw_Triangle(unsigned short X3,unsigned short Y3)
{
    unsigned char temp;    
	temp=X3;   
    Write_Command(0xA9);
	Write_Data(temp);
	temp=X3>>8;   
    Write_Command(0xAA);	   
	Write_Data(temp);

	temp=Y3;
    Write_Command(0xAB);
	Write_Data(temp);
	temp=Y3>>8;   
    Write_Command(0xAC);	   
	Write_Data(temp);
}
//****************��ʾflashͼƬ(VS32240M35һ��FLASH���Դ洢107��ͼƬ����������һ��FLASH����214��ͼƬ)
void displaypicture(unsigned char picnum)
{  
   unsigned int picnumtemp;
   Write_Dir(0X06,0X00);//FLASHƵ���趨
   if(picnum<61)
   {
   Write_Dir(0X05,0X07);//FLASH����   ac cs1,2c cs0
    Write_Dir(0Xc7,0X01);
picnumtemp=picnum;
   }
   if(picnum>60&picnum<121)
   {
   Write_Dir(0X05,0X87); //ac
    Write_Dir(0Xc7,0X00);
picnumtemp=picnum-60;
   }
   Write_Dir(0XBF,0X02);//FLASH����
   Active_Window(0,479,0,271); 
   //Write_Dir(0x41,(1-g_u8LcdLayer));
   MemoryWrite_Position(0,0);//�ڴ�д��λ��
   DMA_Start_address_setting(262144*(picnumtemp-1));
   DMA_block_mode_size_setting(480,272,480);   
   Write_Dir(0XBF,0X03);//FLASH����
Chk_DMA_Busy();
}  
//****************����ͼƬ
//���е�picnum����ͼƬ������x1,y1,x2,y2����Ļ��ʾ����������,x,yΪҪ����ͼƬ�����Ͻ�����
void CutPicture(unsigned char picnum,unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,unsigned short x,unsigned short y)
{
unsigned long cutaddress, picnumtemp;
    Write_Dir(0X06,0X00);//FLASHƵ���趨
   if(picnum<61)
   {
   Write_Dir(0X05,0X06);//FLASH����	  ac cs1,2c cs0
    Write_Dir(0Xc7,0X01);
	picnumtemp=picnum;
   }
   if(picnum>60&picnum<121)
   {
   Write_Dir(0X05,0X86); //ac
    Write_Dir(0Xc7,0X00);
	picnumtemp=picnum-60;
   }
   Write_Dir(0XBF,0X02);//FLASH����
   Active_Window(x1,x2,y1,y2);		
   MemoryWrite_Position(x1,y1);//�ڴ�д��λ��
   cutaddress=(picnumtemp-1)*262144+y*960+x*2;
   DMA_Start_address_setting(cutaddress);
   DMA_block_mode_size_setting(x2-x1+1,y2-y1+1,480);
   Write_Dir(0XBF,0X03);//FLASH����
Chk_DMA_Busy();
}

//****************�����ж��ж�
unsigned char Touch_Status(void)
{	
    unsigned char temp;
    Write_Command(0xF1);//INTC	
    temp =Read_Data();
    if ((temp&0x04)==0x04)
        return 1;
    else 
        return 0;
}

unsigned char Chk_INT(void)
{
    unsigned char temp; 	
    temp=Read_Data();
    if ((temp&0x20)==0x20)
        return 1;
    else 
        return 0;	   
}

unsigned char Chk_INT2(void)
{
    unsigned char temp; 	
    Write_Command(0x74);//INTC
    temp =Read_Data();
    if ((temp&0x80)==0x80)
        return 1;
    else 
        return 0;	   
}

//**************��ȡX����
unsigned char ADC_X(void)
{
    unsigned char temp;
	Write_Command(0x72);//TPXH	 X_coordinate high byte
	//Chk_Busy();
	temp=Read_Data();
	return temp;
}

//**************��ȡY����
unsigned char ADC_Y(void)
{
    unsigned char temp;
	Write_Command(0x73);//TPYH	  Y_coordinate high byte
    //Chk_Busy();
	temp=Read_Data();
	return temp;
}

//**************��ȡXY���꣨��λ����ֵ��
unsigned char ADC_XY(void)
{	
    unsigned char temp;
 	Write_Command(0x74);//TPXYL	  bit[3:2] Y_coordinate low byte  bit[1:0] X_coordinate low byte 
	//Chk_Busy();
	temp=Read_Data();
	return temp;
}   
void RXLCD_clear (unsigned char Color) 
{
    Active_Window(0,479,0,271);//����������ʾ����
    Text_Foreground_Color1(0xffff);//ǰ����ɫ�趨
    Text_Background_Color1(0xffff);//������ɫ�趨
    Write_Dir(0X8E,0X80);//��ʼ����(��ʾ����)
    Delay10ms(5); 
}
void RXLCD_SetPixelIndex(int x, int y, int PixelIndex) 
{
	unsigned char temp;

	temp=x;   
    Write_Command(0x46);
	Write_Data(temp);
	temp=x>>8;   
    Write_Command(0x47);	   
	Write_Data(temp);

	temp=y;   
    Write_Command(0x48);
	Write_Data(temp);
	temp=y>>8;   
    Write_Command(0x49);	   
	Write_Data(temp);

  Write_Command(0x02); 
  Write_Data(PixelIndex); 
}

void RXLCD_CutPicture(unsigned char picnum,unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2)
{
    CutPicture(picnum,x1,y1,x2,y2,x1,y1);
}
void Layer1_Visible(void)
{
    unsigned char temp;
    Write_Command(0x52);//LTPR0
    temp = Read_Data();
    temp&=0xf8;
    Write_Data(temp);  
}
void Layer2_Visible(void)
{
    unsigned char temp;
    Write_Command(0x52);//LTPR0
    temp = Read_Data();
    temp&=0xf8;
    temp|=0x01;
    Write_Data(temp);  
}	
void Layers_Progressive(void)
{
    unsigned char temp;
    Write_Command(0x52);//LTPR0
    temp = Read_Data();
    temp&=0xf8;
    temp|=0x02;
    Write_Data(temp);  
    Write_Command(0x53);//LTPR1
    for(temp=0;temp<9;temp++)
    {
        Write_Data(temp);  
        Delay10ms(100);
    }
}	
void RXLCD_VisibleLayer(void)
{
    if(g_u8LcdLayer==1)
    {
        Layer1_Visible();
    }
    else if(g_u8LcdLayer==0)
    {
        Layer2_Visible();
    }
}
void RXLCD_ScrollWindow_Next(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2, u8 Speed)
{
    u16 i=0;
    
    Scroll_Window(x1,x2,y1,y2);    
    if(g_u8LcdLayer==1)
    {
        Layer2_Visible();
        for(i= 1;i<=(x2-x1+1);i++) 
        {
            Scroll(i,0); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=0;
    }
    else if(g_u8LcdLayer==0)
    {
        Layer1_Visible();
        for(i= 1;i<=(x2-x1+1);i++) 
        {
            Scroll(i,0); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=1;
    }

}
void RXLCD_ScrollWindow_Prev(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2, u8 Speed)
{
    u16 i=0;
    
    Scroll_Window(x1,x2,y1,y2);    
    if(g_u8LcdLayer==1)
    {
        Layer1_Visible();
        for(i= (x2-x1+2);i>0;i--) 
        {
            Scroll(i-1,0); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=0;
    }
    else if(g_u8LcdLayer==0)
    {
        Layer2_Visible();
        for(i= (x2-x1+2);i>0;i--) 
        {
            Scroll(i-1,0); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=1;
    }
}
void RXLCD_ScrollWindow_Up(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2,unsigned char Speed)
{
    u16 i=0;
    
    Scroll_Window(x1,x2,y1,y2);    
    if(g_u8LcdLayer==1)
    {
        Layer2_Visible();
        for(i= 1;i<=(y2-y1+1);i++) 
        {
            Scroll(0,i); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=0;
    }
    else if(g_u8LcdLayer==0)
    {
        Layer1_Visible();
        for(i= 1;i<=(y2-y1+1);i++) 
        {
            Scroll(0,i); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=1;
    }
}
void RXLCD_ScrollWindow_Down(unsigned short x1,unsigned short y1 ,unsigned short x2 ,unsigned short y2,unsigned char Speed)
{
    u16 i=0;
    
    Scroll_Window(x1,x2,y1,y2);    
    if(g_u8LcdLayer==1)
    {
        Layer1_Visible();
        for(i= (y2-y1+2);i>0;i--) 
        {
            Scroll(0,i-1); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=0;
    }
    else if(g_u8LcdLayer==0)
    {
        Layer2_Visible();
        for(i= (y2-y1+2);i>0;i--) 
        {
            Scroll(0,i-1); 
            Delay2us(Speed*2000);
        }
        g_u8LcdLayer=1;
    }
}
void RXLCD_EditNext(void)
{
    Write_Dir(0x41,(1-g_u8LcdLayer));
}
void RXLCD_EditCurrent(void)
{
    Write_Dir(0x41,g_u8LcdLayer);
}
void WriteString(unsigned char *Str,u16 x, u16 y, u16 Color, u8 Size, u8 transperent )
{
    Size = Size<<6;
    Write_Dir(0x21,0x20);//??????
    Write_Dir(0x06,0x03);//??FLASH??
    Write_Dir(0x2F,0x81);//????IC
    Write_Dir(0x05,0xA8);//????IC
    Write_Dir(0x22,0x80|(transperent<<6));//????IC
    Write_Dir(0x2E,Size);//??????16x16/??1
    Text_Foreground_Color1(Color);//??????

    FontWrite_Position(x,y);//??????
    String(Str);

    Write_Dir(0x21,0x00);//?????
    Write_Dir(0x2F,0x00);//?????
}
void RXLCD_DrawLine(unsigned short XS,unsigned short YS,unsigned short XE ,unsigned short YE,unsigned short color)
{
Draw_Line(XS,XE,YS,YE);//������
    Text_Foreground_Color1(color);//��ɫ�趨
	Write_Dir(0X90,0X30);//�趨����
    Write_Dir(0X90,0XB0);//��ʼ��
}


