/******************************************************************************/
/* Main.c:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define __MAIN__
#include "include.h"

void GPIOInit(void)
{
    GPIO2->FIODIR &= 0x00000000;
    GPIO2->FIODIR |= 0x0000001f;
    GPIO2->FIOSET |= 0x0000001f;
    GPIO1->FIODIR &= 0x00000000;
    GPIO1->FIODIR |= 0x00ffc713;
    GPIO1->FIOSET |= 0x00ffc713;
}
void CMainUserInitial(void)
{
    u8 i=0;
    for(i=0;i<21;i++)
    {
        g_t8MenuStack[i][0]=0;
        g_t8MenuStack[i][1]=0;
    }
    g_u8StackTop=0;
    g_u8CurrentPageLevel = 0;
    g_u8MenuLevel1Selected=0;
    g_u8MenuLevel2Selected=0;
    g_u8LcdLayer=0;
    MenuPageIndex=0;
    MenuItemIndex=1;
    g_u8Down_Done=0;
    g_u8Up_Done=0;
    g_u8TPStatus=0;
    g_u8TPDown=0;
    g_u8TPUp=0;

    PumpNum[0]=0;
    PumpNum[1]=0;
    MaxStepCount=40;		//̨����
    FullStepPerClass = 1;  //ÿ��̨�׵������� ,���ٶ�
    nMaxEffClass=0;    //������̨��
    nBackLash=40;
    nStep2Pulse=2;
    ResetPulseNum=4000;
    MinFreqFactor=10;
    MaxFreqFactor=50;
}

void CDeviceInit(void)
{
    SystemInit();

    SysTick_Config(SystemFrequency/100-1);/* Generate interrupt every 10 ms     */
	 
    CMainUserInitial();
    
    init_timer( 0, TIME_10MS_INTERVAL/MaxFreqFactor);
    disable_timer(0);

    init_timer( 1, TIME_10MS_INTERVAL/MaxFreqFactor);
    disable_timer(1);


    GPIOInit();
    
    RXLCD_init();

    SPIFlashMasterInit();

    CFlashStartupCheck();

    Layer1_Visible();

    PumpInit();
        
    return;
}
void CDisplayLogo(void)
{
    u8 i=0;
    
    RXLCD_EditCurrent();
    for(i=30;i<37;i++)
    {
        displaypicture(i);//д��ͼ��2
        Delay10ms(8);
    }
    //Delay10ms(150);
    //displaypicture(37);//д��ͼ��2
    //RXLCD_EditNext();
    //displaypicture(4);//д��ͼ��1

    //RXLCD_ScrollWindow_Next(0,175,479,271,80);
    
    RXLCD_EditCurrent();
    displaypicture(20);//д��ͼ��2
    RXLCD_EditNext();
    displaypicture(20);//д��ͼ��2
    RXLCD_ScrollWindow_Next(0,0,479,271,1);
    //MenuPageIndex = 1;
}
void delay(unsigned int nCount)	
{
  for(; nCount != 0; nCount--);
}

int main (void) 
{     
    CDeviceInit(); //����оƬ LPC1768��ʼ��
    CDisplayLogo();

    CDrawMainPage();

    while(1)
    {
        CTPHandle();
        CUIHandler();
    }

}
