/******************************************************************************/
/* menufunc.c:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define __MENUFUNC__

#include "include.h"
#include "menudef.h"
#include "menutbl.h"
#include "menu.h"
#include "rx_lcd_v02.h"
#include "pump.h"
#include <stdio.h>				   	 
#include <ctype.h>				    
#include <stdlib.h>
#include <setjmp.h>
#include <rt_misc.h>
#include <string.h>
#include <math.h>

u32  test[350]=
    {
    7634 ,
7364 ,
7176 ,
7010 ,
6856 ,
6714 ,
6573 ,
6452 ,
6335 ,
6229 ,
6133 ,
6049 ,
5972 ,
5911 ,
5861 ,
5829 ,
5804 ,
5802 ,
5813 ,
5845 ,
5891 ,
5965 ,
6062 ,
6193 ,
6340 ,
6528 ,
6741 ,
6992 ,
7253 ,
7528 ,
7770 ,
7959 ,
8062 ,
8085 ,
8011 ,
7872 ,
7678 ,
7470 ,
7242 ,
6999 ,
6741 ,
6472 ,
6185 ,
5886 ,
5577 ,
5273 ,
4981 ,
4719 ,
4490 ,
4293 ,
4129 ,
3992 ,
3880 ,
3779 ,
3691 ,
3610 ,
3535 ,
3472 ,
3412 ,
3357 ,
3305 ,
3263 ,
3225 ,
3189 ,
3155 ,
3123 ,
3097 ,
3072 ,
3046 ,
3026 ,
3006 ,
2987 ,
2969 ,
2954 ,
2941 ,
2925 ,
2915 ,
2901 ,
2893 ,
2884 ,
2876 ,
2867 ,
2865 ,
2861 ,
2857 ,
2858 ,
2860 ,
2865 ,
2876 ,
2888 ,
2906 ,
2930 ,
2963 ,
3007 ,
3062 ,
3127 ,
3217 ,
3327 ,
3457 ,
3620 ,
3817 ,
4060 ,
4337 ,
4662 ,
5027 ,
5441 ,
5876 ,
6332 ,
6767 ,
7167 ,
7460 ,
7590 ,
7522 ,
7289 ,
6916 ,
6486 ,
6085 ,
5746 ,
5442 ,
5175 ,
4944 ,
4763 ,
4610 ,
4491 ,
4388 ,
4301 ,
4221 ,
4156 ,
4095 ,
4043 ,
3989 ,
3935 ,
3879 ,
3819 ,
3759 ,
3696 ,
3630 ,
3565 ,
3505 ,
3450 ,
3394 ,
3347 ,
3309 ,


3282 ,
3263 ,
3252 ,
3251 ,
3261 ,
3276 ,
3306 ,
3346 ,
3398 ,
3463 ,
3551 ,
3661 ,
3799 ,
3959 ,
4155 ,
4376 ,
4642 ,
4940 ,
5282 ,
5649 ,
6049 ,
6456 ,
6839 ,
7140 ,
7285 ,
7238 ,
7042 ,
6788 ,
6546 ,
6324 ,
6118 ,
5935 ,
5773 ,
5629 ,
5499 ,
5384 ,
5289 ,
5201 ,
5124 ,
5061 ,
4997 ,
4937 ,
4882 ,
4819 ,
4755 ,
4690 ,
4622 ,
4550 ,
4478 ,
4412 ,
4353 ,
4305 ,
4264 ,
4233 ,
4209 ,
4193 ,
4183 ,
4179 ,
4177 ,
4181 ,
4188 ,
4192 ,
4202 ,
4212 ,
4224 ,
4238 ,
4258 ,
4270 ,
4288 ,
4307 ,
4329 ,
4349 ,
4373 ,
4393 ,
4415 ,
4439 ,
4463 ,
4486 ,
4511 ,
4535 ,
4561 ,
4586 ,
4611 ,
4633 ,
4663 ,
4686 ,
4715 ,
4741 ,
4770 ,
4794 ,
4824 ,
4852 ,
4880 ,
4911 ,
4942 ,
4977 ,
5012 ,
5047 ,
5088 ,
5130 ,
5176 ,
5224 ,
5280 ,
5339 ,
5408 ,
5483 ,
5567 ,
5662 ,
5762 ,
5875 ,
5993 ,
6108 ,
6221 ,
6320 ,
6402 ,
6451 ,
6470 ,
6451 ,
6400 ,
6317 ,
6201 ,
6063 ,
5918 ,
5769 ,
5629 ,
5511 ,
5417 ,
5343 ,
5286 ,
5240 ,
5202 ,
5173 ,
5142 ,
5121 ,
5106 ,
5101 ,
5103 ,
5115 ,
5133 ,
5154 ,
5178 ,
5201 ,
5230 ,
5258 ,
5286 ,
5319 ,
5351 ,
5381 ,
5416 ,
5447 ,
5484 ,
5520 ,
5557 ,
5594 ,
5634 ,
5671 ,
5712 ,
5749 ,
5792 ,
5835 ,
5878 ,
5918 ,
5965 ,
6006 ,
6048 ,
6093 ,
6141 ,
6184 ,
6233 ,
6275 ,
6312 ,
6360 ,
6411 ,
6455 ,
6506 ,
6556 ,
6602 ,
6649 ,
6704 ,
6749 ,
6804 ,
6853 ,
6903 ,
6957 ,
7006 ,
7057 ,
7111 ,
7166 ,
7217 ,
7269 ,
7325 ,
7377 ,
7428 ,
7481 ,
7539 ,
7592 ,
7647 ,
7700 ,
7757 ,
7809 ,
7862 ,
7919 ,
7971 ,
8027 ,
8076 ,
8129 ,
8184 ,
    };

void CNull(void){}
void CNull_u8(u8 a){}
void CDrawSelPicture(void)
{
    RXLCD_EditCurrent();
    CutPicture(CurrentMenuItem.SelPic , CurrentMenuItem.x1, CurrentMenuItem.y1, CurrentMenuItem.x2, CurrentMenuItem.y2, CurrentMenuItem.x, CurrentMenuItem.y);
    RXLCD_EditNext();
    CutPicture(CurrentMenuItem.SelPic , CurrentMenuItem.x1, CurrentMenuItem.y1, CurrentMenuItem.x2, CurrentMenuItem.y2, CurrentMenuItem.x, CurrentMenuItem.y);

}
void CDrawUnselPicture(u8 Index)
{
    RXLCD_EditCurrent();
    CutPicture(CurrentMenuItems[Index].UnSelPic , CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1, CurrentMenuItems[Index].x2, CurrentMenuItems[Index].y2, CurrentMenuItems[Index].x, CurrentMenuItems[Index].y);
    RXLCD_EditNext();
    CutPicture(CurrentMenuItems[Index].UnSelPic , CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1, CurrentMenuItems[Index].x2, CurrentMenuItems[Index].y2, CurrentMenuItems[Index].x, CurrentMenuItems[Index].y);
}
void CDrawUnselMenuLevel1(u8 Index)
{
    if(g_u8MenuLevel1Selected>0)
    {
        RXLCD_EditCurrent();
        CutPicture(tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].UnSelPic , tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].x1, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].y1, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].x2, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].y2, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].x1, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].y1);
        RXLCD_EditNext();
        CutPicture(tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].UnSelPic , tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].x1, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].y1, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].x2, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].y2, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].x1, tblMenus[MainMenu].MenuItems[g_u8MenuLevel1Selected].y1);
    }
}
void CDrawUnselMenuLevel2(u8 Index)
{
    if(g_u8MenuLevel2Selected>0)
    {
        RXLCD_EditCurrent();
        CutPicture(CurrentMenuItems[g_u8MenuLevel2Selected].UnSelPic ,CurrentMenuItems[g_u8MenuLevel2Selected].x1, CurrentMenuItems[g_u8MenuLevel2Selected].y1, CurrentMenuItems[g_u8MenuLevel2Selected].x2, CurrentMenuItems[g_u8MenuLevel2Selected].y2, CurrentMenuItems[g_u8MenuLevel2Selected].x1, CurrentMenuItems[g_u8MenuLevel2Selected].y1);
        RXLCD_EditNext();
        CutPicture(CurrentMenuItems[g_u8MenuLevel2Selected].UnSelPic , CurrentMenuItems[g_u8MenuLevel2Selected].x1, CurrentMenuItems[g_u8MenuLevel2Selected].y1, CurrentMenuItems[g_u8MenuLevel2Selected].x2, CurrentMenuItems[g_u8MenuLevel2Selected].y2, CurrentMenuItems[g_u8MenuLevel2Selected].x1, CurrentMenuItems[g_u8MenuLevel2Selected].y1);
    }
}
void CDrawSelInputPicture(void)
{
    CutPicture(CurrentMenuItem.SelPic , CurrentMenuItem.x1, CurrentMenuItem.y1, CurrentMenuItem.x2, CurrentMenuItem.y2, CurrentMenuItem.x, CurrentMenuItem.y);

}
void CDrawUnselInputPicture(u8 Index)
{
    CutPicture(CurrentMenuItems[Index].UnSelPic , CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1, CurrentMenuItems[Index].x2, CurrentMenuItems[Index].y2, CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1);
}
void CDrawMainPage(void)
{
    u8 i=0;
    u8 j=1;
    
    MenuPageIndex = NextMenuPage;
    RXLCD_EditNext();
    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x1,CurrentMenu.y1);//写入图层1
    Delay10ms(1);
    RXLCD_ScrollWindow_Prev(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,10);
    //BTE_MovePositive(g_u8LcdLayer, (1-g_u8LcdLayer), CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2);
    for(i=PageStackStartPoint[CurrentMenuLevel];i<(PageStackStartPoint[CurrentMenuLevel]+MenuItemCount-1);i++)
    {
        g_t8MenuStack[i][0]=MenuPageIndex;
        g_t8MenuStack[i][1]=j;
        j++;
    }
    g_u8StackTop = i;
    g_u8CurrentPageLevel = CurrentMenuLevel;
    MenuItemIndex = 0;
}
void CDrawNextPage(void)
{
    u8 i=0;
    u8 j=1;

    if(CurrentMenuItem.Flags == menu_level_2)
        g_u8MenuLevel2Selected = MenuItemIndex;
    
    MenuPageIndex = NextMenuPage;

    RXLCD_EditCurrent();
    CutPicture(20,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
    Delay10ms(1);
    RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);

    BTE_MovePositive(1-g_u8LcdLayer, g_u8LcdLayer,0,0,479,271, 0,0);
    //Delay10ms(1);
    RXLCD_EditNext();
    //Delay10ms(1);
    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层2
    //Delay10ms(1);
    RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,5);

    for(i=PageStackStartPoint[CurrentMenuLevel];i<21;i++)
    {
        g_t8MenuStack[i][0]=0;
        g_t8MenuStack[i][1]=0;
    }

    for(i=PageStackStartPoint[CurrentMenuLevel];i<(PageStackStartPoint[CurrentMenuLevel]+MenuItemCount-1);i++)
    {
        g_t8MenuStack[i][0]=MenuPageIndex;
        g_t8MenuStack[i][1]=j;
        j++;
    }
    g_u8StackTop = i;
    g_u8CurrentPageLevel = CurrentMenuLevel;


    MenuItemIndex = 0;

}
void CDrawPageLevel4(void)
{    
    u8 i=0;
    u8 j=1;
    
    for(i=PageStackStartPoint[CurrentMenuLevel];i<21;i++)
    {
        g_t8MenuStack[i][0]=0;
        g_t8MenuStack[i][1]=0;
    }

    for(i=PageStackStartPoint[CurrentMenuLevel];i<(PageStackStartPoint[CurrentMenuLevel]+MenuItemCount-1);i++)
    {
        g_t8MenuStack[i][0]=MenuPageIndex;
        g_t8MenuStack[i][1]=j;
        j++;
    }
    g_u8StackTop = i;
    
    MenuPageIndex = NextMenuPage;

    RXLCD_EditNext();
    CutPicture(20,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
    RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,3);

//BTE_MovePositive(1-g_u8LcdLayer, g_u8LcdLayer,0,0,479,271, 0,0);
    //Scroll_Window(0,479,0,271);
    //RXLCD_ScrollWindow_Next(165,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);
    RXLCD_EditNext();
    //Delay10ms(1);
    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层2
    //Delay10ms(1);
    RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,3);

    g_u8CurrentPageLevel = CurrentMenuLevel;

    MenuItemIndex = 0;
}
void CDrawPageLevel5(void)
{    

    MenuPageIndex = NextMenuPage;

    RXLCD_EditNext();
    CutPicture(20,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
    RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);


    RXLCD_EditNext();
    //Delay10ms(1);
    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层2
    //Delay10ms(1);
    RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,3);

    g_u8CurrentPageLevel = CurrentMenuLevel;

    MenuItemIndex = 0;
}

void CDrawPrevPage(void)
{
    u8 i=0;
    u8 j=1;
    
    //MenuPageIndex = PrevMenuPage;
    RXLCD_EditNext();
    CutPicture(20,0,0,479,271,0,0);//写入图层2
    RXLCD_ScrollWindow_Prev(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);

    BTE_MovePositive(g_u8LcdLayer, 1-g_u8LcdLayer,0,0,479,271, 0,0);

    MenuPageIndex = g_t8MenuStack[0][0];
    MenuItemIndex = tblMenus[g_t8MenuStack[7][0]].FatherItemNum;
    RXLCD_EditNext();
    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x1,CurrentMenu.y1);//写入图层1
    Delay10ms(1);
    RXLCD_ScrollWindow_Prev(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,5);
    CurrentMenuItem.SelPicFunction();
    if(g_u8StackTop>14)
    {
        MenuPageIndex = g_t8MenuStack[7][0];
        MenuItemIndex = g_u8MenuLevel2Selected;//tblMenus[g_t8MenuStack[15][0]].FatherItemNum;
        RXLCD_EditCurrent();
        CutPicture(20,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
        Delay10ms(1);
        RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);

        BTE_MovePositive(1-g_u8LcdLayer, g_u8LcdLayer,0,0,479,271, 0,0);
        //Delay10ms(1);
        RXLCD_EditNext();
        //Delay10ms(1);
        CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层2
        //Delay10ms(1);
        RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,2);
        CurrentMenuItem.SelPicFunction();
        MenuPageIndex = g_t8MenuStack[15][0];
        RXLCD_EditCurrent();
        CutPicture(20,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
        Delay10ms(1);
        RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);

        BTE_MovePositive(1-g_u8LcdLayer, g_u8LcdLayer,0,0,479,271, 0,0);
        //Delay10ms(1);
        RXLCD_EditNext();
        //Delay10ms(1);
        CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层2
        //Delay10ms(1);
        RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,4);
        for(i=PageStackStartPoint[CurrentMenuLevel];i<23;i++)
        {
            g_t8MenuStack[i][0]=0;
            g_t8MenuStack[i][1]=0;
        }

        for(i=PageStackStartPoint[CurrentMenuLevel];i<(PageStackStartPoint[CurrentMenuLevel]+MenuItemCount-1);i++)
        {
            g_t8MenuStack[i][0]=MenuPageIndex;
            g_t8MenuStack[i][1]=j;
            j++;
        }
        g_u8StackTop = i;
        g_u8CurrentPageLevel = CurrentMenuLevel;
        MenuItemIndex = 0;
    }
    else if(g_u8StackTop>6)
    {
        MenuPageIndex = g_t8MenuStack[7][0];
        MenuItemIndex = tblMenus[g_t8MenuStack[15][0]].FatherItemNum;
        RXLCD_EditCurrent();
        CutPicture(20,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
        Delay10ms(1);
        RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);

        BTE_MovePositive(1-g_u8LcdLayer, g_u8LcdLayer,0,0,479,271, 0,0);
        //Delay10ms(1);
        RXLCD_EditNext();
        //Delay10ms(1);
        CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层2
        //Delay10ms(1);
        RXLCD_ScrollWindow_Next(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,5);
        for(i=PageStackStartPoint[CurrentMenuLevel];i<23;i++)
        {
            g_t8MenuStack[i][0]=0;
            g_t8MenuStack[i][1]=0;
        }

        for(i=PageStackStartPoint[CurrentMenuLevel];i<(PageStackStartPoint[CurrentMenuLevel]+MenuItemCount-1);i++)
        {
            g_t8MenuStack[i][0]=MenuPageIndex;
            g_t8MenuStack[i][1]=j;
            j++;
        }
        g_u8StackTop = i;
        g_u8CurrentPageLevel = CurrentMenuLevel;
        MenuItemIndex = 0;
    }
    
//    RXLCD_EditNext();
//    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层1
//    RXLCD_ScrollWindow_Prev(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,5);
//    MenuItemIndex=0;


}

void CDrawPrevPage5(void)
{
    //u8 i=0;
    //u8 j=1;
    
    RXLCD_EditNext();
    CutPicture(20,0,0,479,271,0,0);//写入图层2
    RXLCD_ScrollWindow_Prev(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,1);

    BTE_MovePositive(g_u8LcdLayer, 1-g_u8LcdLayer,0,0,479,271, 0,0);
    MenuPageIndex = PrevMenuPage;

    RXLCD_EditNext();
    CutPicture(CurrentMenu.PicNum,CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,CurrentMenu.x,CurrentMenu.y);//写入图层1
    RXLCD_ScrollWindow_Prev(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,5);
    MenuItemIndex=0;
}

void CDrawInputMenu(void)
{
    u8 i=0;

    for(i=0;i<8;i++)
        g_t8InputNumber[i]=0;
    g_u32InputResult=0;
    BTE_MovePositive(g_u8LcdLayer, (1-g_u8LcdLayer), 0,0,479,271, 0,0);
    
    //*******************光标功能测试
    FontWrite_Position(CurrentMenuItem.x1+5, CurrentMenuItem.y1+10);
    Write_Dir(0x40,0xe0);//设置文字模式光标
    Write_Dir(0x2e,0x00);//设置文字模式光标
    Text_Foreground_Color1(0x0000);//前景颜色设定
    Write_Dir(0x41,0x00);//关闭图形光标
    Write_Dir(0x44,0x20);//光标闪烁周期
    Write_Dir(0x4e,0x03);//光标大小
    Write_Dir(0x4f,0x1f);//光标大小


    CurrentMenuItem.UnselPicFunction(MenuItemIndex);
    TempPageIndex = MenuPageIndex;
    TempItemIndex = MenuItemIndex;
    MenuPageIndex = InputMenu;
    g_u8NumberBit=0;
    RXLCD_EditNext();
    displaypicture(CurrentMenu.PicNum);
    RXLCD_ScrollWindow_Up(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,10);
    g_u8MaxInputLength=8;
    g_u8Inputing=1;
}
void CDrawInputMenuMin(u8 InputLength)
{
    u8 i=0;

    for(i=0;i<8;i++)
        g_t8InputNumber[i]=0;
    g_u32InputResult=0;
    BTE_MovePositive(g_u8LcdLayer, (1-g_u8LcdLayer), 0,0,479,271, 0,0);
    
    //*******************光标功能测试
    FontWrite_Position(CurrentMenuItem.x1, CurrentMenuItem.y1);
    Write_Dir(0x40,0xe0);//设置文字模式光标
    Write_Dir(0x2e,0x00);//设置文字模式光标
    Text_Foreground_Color1(color_red);//前景颜色设定
    Write_Dir(0x41,0x00);//关闭图形光标
    Write_Dir(0x44,0x20);//光标闪烁周期
    Write_Dir(0x4e,0x02);//光标大小
    Write_Dir(0x4f,0x0f);//光标大小


    CurrentMenuItem.UnselPicFunction(MenuItemIndex);
    TempPageIndex = MenuPageIndex;
    TempItemIndex = MenuItemIndex;
    MenuPageIndex = InputMenu;
    g_u8NumberBit=0;
    RXLCD_EditNext();
    displaypicture(CurrentMenu.PicNum);
    RXLCD_ScrollWindow_Up(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,10);
    if((TempMenuItem.VariableMaxValue==0x00ff)&&(InputLength>3))
        g_u8MaxInputLength=3;
    else
        g_u8MaxInputLength=InputLength;
    g_u8Inputing=1;
}
void CHideInputMenu(void)
{
    RXLCD_EditNext();
    //displaypicture(CurrentMenu.PicNum);
    RXLCD_ScrollWindow_Down(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,10);
    MenuPageIndex = TempPageIndex;
    MenuItemIndex = TempItemIndex;
}
void CPopUpInputResult(void)
{
    //u8 i=0;
    if(TempMenuItem.VariableMaxValue==0xffff)
    {
        if(g_u32InputResult>0xffff)
            g_u32InputResult=0xffff;
        *TempMenuItem.pU16value = g_u32InputResult;
    }
    else if(TempMenuItem.VariableMaxValue==0x00ff)
    {
        if(g_u32InputResult>0x00ff)
            g_u32InputResult=0x00ff;
        *TempMenuItem.pU8value = g_u32InputResult;
    }
    CHideInputMenu();

    Write_Dir(0x21,0x00);//复原寄存器
    Write_Dir(0x40,0x00);//复原寄存器
    MenuItemIndex=0;
    g_u8Inputing=0;
}
void CGetInputBit(void)
{
    if(g_u8NumberBit<g_u8MaxInputLength)
    {
        g_t8InputNumber[g_u8NumberBit] = 0x30 + MenuItemIndex%10;
        if(g_u8NumberBit>0)
            g_u32InputResult = g_u32InputResult*10+MenuItemIndex%10;
        else
            g_u32InputResult = MenuItemIndex%10;

        if((MenuItemIndex%10==0)&&(g_u8NumberBit==0));
        else
        {
            RXLCD_EditNext();
            //Delay10ms(1);
            RXLCD_VisibleLayer();
            //Delay10ms(1);
            Active_Window(0,479,0,271);//设置区域显示窗口
            Write_Dir(0x40,0x80);//设置文字模
            Write_Dir(0x21,0x20);//选择外部字库
            Write_Dir(0x06,0x03);//设置FLASH频率
            Write_Dir(0x05,0xA8);//设置字符IC	
            Write_Dir(0x2E,0x80);//设置字符模式32x32/间距0
            Write_Dir(0x2F,0x81);//设置字符IC
            Write_Dir(0x22,0x40);//设置为通透模式

            //if(g_u8NumberBit==0)
                //FontWrite_Position(TempMenuItem.x1, TempMenuItem.y1-4);   //設定顯示位置
            if(TempMenuItem.Flags == edit_line_min)    
                WriteString1(g_t8InputNumber, TempMenuItem.x1, TempMenuItem.y1, color_red, 0, 1);
            else
                WriteString1(g_t8InputNumber, TempMenuItem.x1, TempMenuItem.y1-4, color_black, 2, 1);
            //Write_Command(0x02);
            //String(&g_t8InputNumber[g_u8NumberBit]);
            //Delay10ms(1);

            //Write_Data(g_t8InputNumber[g_u8NumberBit]);
            //Delay10ms(1);

            //Write_Dir(0x40,0xc0);//设置文字模式光标
            //Write_Dir(0x2e,0x40);//设置文字模式光标
            //Write_Dir(0x41,0x00);//关闭图形光标
            //Write_Dir(0x44,0x1f);//光标闪烁周期
            //Write_Dir(0x4e,0x03);//光标大小
            //Write_Dir(0x4f,0x14);//光标大小
            //Delay10ms(1);
            RXLCD_EditCurrent();
            //Delay10ms(1);

            g_u8NumberBit++;
        }
    }
    
}
void CInputBackSpace(void)
{
    if(g_u8NumberBit>0)
    {
        g_u8NumberBit--;
        g_t8InputNumber[g_u8NumberBit]=0;
        g_u32InputResult = g_u32InputResult/10;
        RXLCD_EditNext();
        CutPicture(TempMenuItem.UnSelPic , TempMenuItem.x1, TempMenuItem.y1, TempMenuItem.x2, TempMenuItem.y2, TempMenuItem.x1, TempMenuItem.y1);
        //Delay10ms(1);
        RXLCD_VisibleLayer();
        //Delay10ms(1);
        Active_Window(0,479,0,271);//设置区域显示窗口
        Write_Dir(0x40,0x80);//设置文字模
        Write_Dir(0x21,0x20);//选择外部字库
        Write_Dir(0x06,0x03);//设置FLASH频率
        Write_Dir(0x05,0xA8);//设置字符IC	
        Write_Dir(0x2E,0x80);//设置字符模式32x32/间距0
        Write_Dir(0x2F,0x81);//设置字符IC
        Write_Dir(0x22,0x40);//设置为通透模式
        WriteString1(g_t8InputNumber, TempMenuItem.x1, TempMenuItem.y1-4, color_black, 2, 1);
        /*
        FontWrite_Position(TempMenuItem.x1, TempMenuItem.y1-4);   //設定顯示位置
        Write_Command(0x02);
        Delay10ms(1);
        String(" ");

        //Write_Data(g_t8InputNumber[g_u8NumberBit]);
        Delay10ms(1);
*/
        //Write_Dir(0x40,0xc0);//设置文字模式光标
        //Write_Dir(0x2e,0x40);//设置文字模式光标
        //Write_Dir(0x41,0x00);//关闭图形光标
        //Write_Dir(0x44,0x1f);//光标闪烁周期
        //Write_Dir(0x4e,0x03);//光标大小
        //Write_Dir(0x4f,0x14);//光标大小
        //Delay10ms(1);
        RXLCD_EditCurrent();
    }
}
void CDrawResultCurve(void)
{
    u16 i=0;
    CDrawPageLevel5();
    Write_Dir(0X90,0X00);//设定参数
    Write_Dir(0X40,0x00);    
    CCurveCompress(350, &test[0]);
    for(i=0;i<300;i++)
    {
        if(i<299)
        {
            Text_Foreground_Color1(0xf800);//前景颜色设定
            RXLCD_SetPixelIndex(i+29,t_u16CompressPoint[i]+37,0xff0f);
            RXLCD_SetPixelIndex(i+1+29,t_u16CompressPoint[i+1]+37,0xff0f);
            Draw_Line(i+29,i+1+29,t_u16CompressPoint[i]+36,t_u16CompressPoint[i+1]+37);//画线段
            Write_Dir(0X90,0X80);//开始画 
        }
    }
}
void CDrawBurninStatus(void)
{
    CDrawPageLevel5();
    /*
    Write_Dir(0X90,0X00);//设定参数
    Write_Dir(0X40,0x00);    
    CCurveCompress(350, &test[0]);
    for(i=0;i<300;i++)
    {
        if(i<299)
        {
            Text_Foreground_Color1(0xf800);//前景颜色设定
            RXLCD_SetPixelIndex(i+29,t_u16CompressPoint[i]+37,0xff0f);
            RXLCD_SetPixelIndex(i+1+29,t_u16CompressPoint[i+1]+37,0xff0f);
            Draw_Line(i+29,i+1+29,t_u16CompressPoint[i]+36,t_u16CompressPoint[i+1]+37);//画线段
            Write_Dir(0X90,0X80);//开始画 
        }
    }
    */
}
void CDrawButton(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2, u8 Row, u8 col)
{
    RXLCD_EditCurrent();
    CutPicture(5, x1, y1, x2, y2, col*90, Row*40);
}
void CDrawIconDone(u8 Sel)
{
    RXLCD_EditCurrent();
    CutPicture(19-(8*Sel), 410, 106, 454, 147, 410, 106);
}
#define   CharDot 0x2E;
#define nLog2(x)        log(x)/log(2)
const u32 Pow10[10] = {
  1 , 10, 100, 1000, 10000,
  100000, 1000000, 10000000, 100000000, 1000000000
};
const u8 tStepMode[4]={1,1,2,4};
static int _Check_NegLong(signed long *pv, unsigned char**ps) 
{
    if (*pv < 0) 
    {
        *(*ps)++ = '-';
        *pv = -*pv;
        return 1;
    }
    return 0;
}
int Long2Len(signed long vSign) 
{
    int Len = 1;
    signed long v = (vSign > 0) ? vSign : -vSign;
    while (( ((u32)v) >= Pow10[Len]) && (Len < 9)) 
    {
        Len++;
    }
    if (vSign < 0) 
    {
    	Len++;
    }
    return Len;
}
void CAddDecShift(signed long v, u8 Len, u8 Shift, unsigned char**ps) 
{
    char c;
    long d;

    Len -= _Check_NegLong(&v, ps); /* TASKING: Tool internal error S003: asertion failed - please report */
    if (Shift) 
    {
        Len--;
    }

    if ((u32)v >= Pow10[Len])
        v = Pow10[Len] - 1;
    while (Len) 
    {
        if (Len-- == Shift)
            *(*ps)++ = CharDot;
        d = Pow10[Len];
        c = (char) (v / d);
        v -= c * d;
        *(*ps)++ = c + '0';
    }
    **ps = 0;
}
static void CDispFloatFix(float f, char Fract,  unsigned char* s) 
{
    char Len;
    Len = Long2Len((long)f);
    if ((f < 0) && (f > -1)) 
    { 
        Len++;
    }
    Len = (char)(Len + Fract + (Fract ? 1 : 0));

    f *= Pow10[(unsigned)Fract];
    f = (float) floor (f);
    CAddDecShift(f, Len, Fract, &s);
}
void CDispFloatAt(float f, char Fract,u16 x, u16 y, u16 Color, u8 Size, u8 transperent)
{
    unsigned char ac[12];
    unsigned char* s = ac;

    CDispFloatFix(f, Fract, s);
    
    WriteString(ac, x, y, Color, Size, transperent);
}

void CDebugOpt1Start(void)
{
    g_u8DetectOptSelect=1;
    g_u8DetectOptStart=1;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt1PageStyle(void)
{
    WriteString("光耦调试( 序号 : 1 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("提示: 此电位代表光耦在当前状态下,MCU读取到的电位水平", 15, 240, color_brown, _FONT_SIZE_MIN,_TANSPERENT_ON);
}
void CDebugOpt1Stop(void)
{
    g_u8DetectOptSelect=0xff;
    g_u8DetectOptStart=0;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt2Start(void)
{
    g_u8DetectOptSelect=2;
    g_u8DetectOptStart=1;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt2PageStyle(void)
{
    WriteString("光耦调试( 序号 : 2 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("提示: 此电位代表光耦在当前状态下,MCU读取到的电位水平", 15, 240, color_brown, _FONT_SIZE_MIN,_TANSPERENT_ON);
}
void CDebugOpt2Stop(void)
{
    g_u8DetectOptSelect=0xff;
    g_u8DetectOptStart=0;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt3Start(void)
{
    g_u8DetectOptSelect=3;
    g_u8DetectOptStart=1;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt3PageStyle(void)
{
    WriteString("光耦调试( 序号 : 3 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("提示: 此电位代表光耦在当前状态下,MCU读取到的电位水平", 15, 240, color_brown, _FONT_SIZE_MIN,_TANSPERENT_ON);
}
void CDebugOpt3Stop(void)
{
    g_u8DetectOptSelect=0xff;
    g_u8DetectOptStart=0;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt4Start(void)
{
    g_u8DetectOptSelect=4;
    g_u8DetectOptStart=1;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt4PageStyle(void)
{
    WriteString("光耦调试( 序号 : 4 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("提示: 此电位代表光耦在当前状态下,MCU读取到的电位水平", 15, 240, color_brown, _FONT_SIZE_MIN,_TANSPERENT_ON);
}
void CDebugOpt4Stop(void)
{
    g_u8DetectOptSelect=0xff;
    g_u8DetectOptStart=0;
    g_u32OptLevel = 0xff; 
}
void CDebugPump1PageStyle(void)
{
    WriteString("电机调试( 序号 : 1 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("运行脉冲数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stUISetting.DebugPumpStep,0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_OFF);

    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(130,220,215,255,0,1);
    CDrawButton(265,220,350,255,0,0);
}
void CDebugPump1RunPositive(void)
{
    PumpFreeRun(1,1,g_stUISetting.DebugPumpStep);
}
void CDebugPump1RunNegative(void)
{
    PumpFreeRun(1,0,g_stUISetting.DebugPumpStep);
}
void CDebugPump1SetValue(void)
{
    if(CurrentMenuItem.VariableMaxValue==0xffff)
        CurrentMenuItem.pU16value = &g_stUISetting.DebugPumpStep;
}
void CDebugPump2PageStyle(void)
{
    WriteString("电机调试( 序号 : 2 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("运行脉冲数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stUISetting.DebugPumpStep,0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_OFF);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(130,220,215,255,0,1);
    CDrawButton(265,220,350,255,0,0);
}
void CDebugPump2RunPositive(void)
{
    PumpFreeRun(2,1,g_stUISetting.DebugPumpStep);
}
void CDebugPump2RunNegative(void)
{
    PumpFreeRun(2,0,g_stUISetting.DebugPumpStep);
}
void CDebugValve1PageStyle(void)
{
    WriteString("阀调试( 序号 : 1 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CDebugValve2PageStyle(void)
{
    WriteString("阀调试( 序号 : 2 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CDebugValve3PageStyle(void)
{
    WriteString("阀调试( 序号 : 3 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CDebugValve4PageStyle(void)
{
    WriteString("阀调试( 序号 : 4 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CTestPump1Reset(void)
{
    PumpReset(1);    
}
void CTestPump2Reset(void)
{
    PumpReset(2);    
}
void CTestValve1Reset(void)
{
    PumpSetValveState(1, _VALVE_OFF);
}
void CTestValve2Reset(void)
{
    PumpSetValveState(2, _VALVE_OFF);
}
void CTestValve3Reset(void)
{
    PumpSetValveState(3, _VALVE_OFF);
}
void CTestValve4Reset(void)
{
    PumpSetValveState(4, _VALVE_OFF);
}
void CTestBurnInPageStyle(void)
{
    WriteString("老化测试", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("老化行程(ul):", 50, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stUISetting.TestVol1,0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_OFF);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CTestBurninStatusPageStyle(void)
{
    RXLCD_EditCurrent();
    WriteString("老化测试状态表", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("当前老化行程:", _LEVEL5_ITEM_1_x, _LEVEL5_ITEM_1_y, color_black, _FONT_SIZE_MIN,_TANSPERENT_ON);
    CDispFloatAt(g_stUISetting.TestVol1,0,_LEVEL5_VALUE_1_x,_LEVEL5_VALUE_1_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_ON);
    WriteString("已运行次数(泵 1):", _LEVEL5_ITEM_2_x, _LEVEL5_ITEM_2_y, color_black, _FONT_SIZE_MIN,_TANSPERENT_ON);
    CDispFloatAt(g_u32BurninCount1,0,_LEVEL5_VALUE_2_x,_LEVEL5_VALUE_2_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);
    WriteString("已运行次数(泵 2):", _LEVEL5_ITEM_3_x, _LEVEL5_ITEM_3_y, color_black, _FONT_SIZE_MIN,_TANSPERENT_ON);
    CDispFloatAt(g_u32BurninCount2,0,_LEVEL5_VALUE_3_x,_LEVEL5_VALUE_3_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);

    //WriteString("提示: 点击暂停或停止后，将放弃本次老化立即生效", 15, 200, DarkGreen, _FONT_SIZE_MIN,_TANSPERENT_ON);
    CDrawButton(15,220,100,255,1,0);
    CDrawButton(120,220,205,255,1,2);

    CDrawButton(275,220,360,255,1,0);
    CDrawButton(380,220,465,255,1,2);
}
void CTestBurninSetVol(void)
{

    g_u32BurninCount1=0;
    g_u8FlowWaitOver1=1;
    g_u8RunningIndex1=0;
    g_u32RunningFlow1[0]=64000;
    g_u32RunningFlow1[1]=64000;
    g_u32WaitFlow1[0]=1;
    g_u32WaitFlow1[1]=1;
    g_u8DirectionFlow1[0]=1;
    g_u8DirectionFlow1[1]=0;
    g_u8FlowCount1=4;
    enable_timer(0);
    g_u8RunningStart1=1;

    g_u32BurninCount2=0;
    g_u8FlowWaitOver2=1;
    g_u8RunningIndex2=0;
    g_u32RunningFlow2[0]=64000;
    g_u32RunningFlow2[1]=64000;
    g_u32WaitFlow2[0]=1;
    g_u32WaitFlow2[1]=1;
    g_u8DirectionFlow2[0]=1;
    g_u8DirectionFlow2[1]=0;
    g_u8FlowCount2=4;
    enable_timer(1);
    g_u8RunningStart2=1;

}
void CTestBurninContinue1(void)
{
    if(g_u8RunningStart1==1)
    {
        PumpCount[0]=0;
        PumpSetEnable(1, _PUMP_DISABLE);
        PumpSetLowPowerMode(1, _LOW_PWR);
        g_u32FlowWaitCount1=0;
        g_u8RunningStart1=0;
        g_u8RunningIndex1=0;
        g_u8FlowWaitOver1=1;
        CDrawButton(15,220,100,255,1,1);
    }
    else
    {
        CDrawButton(15,220,100,255,1,0);
        g_u8RunningStart1=1;
    }
}
void CTestBurninContinue2(void)
{
    if(g_u8RunningStart2==1)
    {
        PumpCount[1]=0;
        PumpSetEnable(2, _PUMP_DISABLE);
        PumpSetLowPowerMode(2, _LOW_PWR);
        g_u32FlowWaitCount2=0;
        g_u8RunningStart2=0;
        g_u8RunningIndex2=0;
        g_u8FlowWaitOver2=1;
        CDrawButton(275,220,360,255,1,1);
    }
    else
    {
        CDrawButton(275,220,360,255,1,0);
        g_u8RunningStart2=1;
    }
}
void CTestBurninStop1(void)
{
    if(g_u8RunningStart1==1)
    {
        PumpCount[0]=0;
        PumpSetEnable(1, _PUMP_DISABLE);
        PumpSetLowPowerMode(1, _LOW_PWR);
        g_u32FlowWaitCount1=0;
        g_u8RunningStart1=0;
        g_u8RunningIndex1=0;
        g_u8FlowWaitOver1=1;
        g_u32BurninCount1=0;
        WriteString("              ", _LEVEL5_VALUE_2_x,_LEVEL5_VALUE_2_y,color_white, _FONT_SIZE_MIN,_TANSPERENT_OFF);
        CDispFloatAt(g_u32BurninCount1,0,_LEVEL5_VALUE_2_x,_LEVEL5_VALUE_2_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);
        CDrawButton(15,220,100,255,1,1);
    }
}
void CTestBurninStop2(void)
{
    if(g_u8RunningStart2==1)
    {
        PumpCount[1]=0;
        PumpSetEnable(2, _PUMP_DISABLE);
        PumpSetLowPowerMode(2, _LOW_PWR);
        g_u32FlowWaitCount2=0;
        g_u8RunningStart2=0;
        g_u8RunningIndex2=0;
        g_u8FlowWaitOver2=1;
        g_u32BurninCount2=0;
        WriteString("              ", _LEVEL5_VALUE_3_x,_LEVEL5_VALUE_3_y,color_white, _FONT_SIZE_MIN,_TANSPERENT_OFF);
        CDispFloatAt(g_u32BurninCount2,0,_LEVEL5_VALUE_3_x,_LEVEL5_VALUE_3_y,color_black, _FONT_SIZE_MIN,_TANSPERENT_OFF);
        CDrawButton(275,220,360,255,1,1);
    }
}
void CTestWaterWeighPageStyle(void)
{
    WriteString("称水测试", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CTestBacklashPageStyle(void)
{
    WriteString("背隙测试", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CTestLeakagePageStyle(void)
{
    WriteString("泄漏测试", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CSettingAcceleration1PageStyle(void)
{
    u8 i=0;
    WriteString("启止台阶设定( 序号:1 )", _LEVEL4_TITLE_x, 230, color_black, _FONT_SIZE_MIN,_TANSPERENT_ON);
    CDrawButton(197,220,282,255,0,2);
    for(i=0;i<20;i++)
    {
        CDispFloatAt(g_stPumpSetting[0].Freq[i], 0, 33+(110*(i/5)), 32+(27*(i%5)), Black, _FONT_SIZE_MIN, _TANSPERENT_OFF);
        CDispFloatAt(g_stPumpSetting[0].Step[i], 0, 87+(110*(i/5)), 32+(27*(i%5)), Black, _FONT_SIZE_MIN, _TANSPERENT_OFF);
    }
}
void CSettingAcceleration2PageStyle(void)
{
    u8 i=0;
    WriteString("启止台阶设定( 序号:2 )", _LEVEL4_TITLE_x, 230, color_black, _FONT_SIZE_MIN,_TANSPERENT_ON);
    CDrawButton(197,220,282,255,0,2);
    for(i=0;i<20;i++)
    {
        CDispFloatAt(g_stPumpSetting[1].Freq[i], 0, 33+(110*(i/5)), 32+(27*(i%5)), Black, _FONT_SIZE_MIN, _TANSPERENT_OFF);
        CDispFloatAt(g_stPumpSetting[1].Step[i], 0, 87+(110*(i/5)), 32+(27*(i%5)), Black, _FONT_SIZE_MIN, _TANSPERENT_OFF);
    }
}
void CSettingAcceleration1Value(void)
{
    u8 i=0;
    for(i=19;i>0;i--)
    {
        if(g_stPumpSetting[0].Freq[i]!=0)
            break;
    }
    g_stPumpSetting[0].StepNum = i+1;
    CFlashSavePumpSetting(0);
}
void CSettingAcceleration2Value(void)
{
    u8 i=0;
    for(i=19;i>0;i--)
    {
        if(g_stPumpSetting[1].Freq[i]!=0)
            break;
    }
    g_stPumpSetting[1].StepNum = i+1;
    CFlashSavePumpSetting(1);
}
void CSettingBalancePageStyle(void)
{
    WriteString("电子天平设定", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CSettingMicrometerPageStyle(void)
{
    WriteString("千分尺设定", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
}
void CSettingOpt1PageStyle(void)
{
    WriteString("光耦设定( 序号 : 1 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("光耦线数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stOptSetting.OptLineNum[0],0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    WriteString("(请在遮挡光耦后按下确定键)", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y+33, 0x0010, 0 ,1);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingOpt2PageStyle(void)
{
    WriteString("光耦设定( 序号 : 2 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("光耦线数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stOptSetting.OptLineNum[1],0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    WriteString("(请在遮挡光耦后按下确定键)", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y+33, 0x0010, 0 ,1);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingOpt3PageStyle(void)
{
    WriteString("光耦设定( 序号 : 3 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("光耦线数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stOptSetting.OptLineNum[2],0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    WriteString("(请在遮挡光耦后按下确定键)", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y+33, 0x0010, 0 ,1);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingOpt4PageStyle(void)
{
    WriteString("光耦设定( 序号 : 4 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("光耦线数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stOptSetting.OptLineNum[3],0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    WriteString("(请在遮挡光耦后按下确定键)", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y+33, 0x0010, 0 ,1);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingOpt1ShieldValue(void)
{
    CDrawIconDone(1);
    g_stOptSetting.OptShieldLevel[0] = PumpGetOpticStatus(1);
    CFlashSaveOptSetting();
}
void CSettingOpt2ShieldValue(void)
{
    CDrawIconDone(1);
    g_stOptSetting.OptShieldLevel[1] = PumpGetOpticStatus(2);
    CFlashSaveOptSetting();
}
void CSettingOpt3ShieldValue(void)
{
    CDrawIconDone(1);
    g_stOptSetting.OptShieldLevel[2] = PumpGetOpticStatus(3);
    CFlashSaveOptSetting();
}
void CSettingOpt4ShieldValue(void)
{
    CDrawIconDone(1);
    g_stOptSetting.OptShieldLevel[3] = PumpGetOpticStatus(4);
    CFlashSaveOptSetting();
}
void CSettingPump1PageStyle(void)
{
    WriteString("泵信息( 序号 : 1 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("规格号:", 60, 100, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    RXLCD_DrawLine(240,127,400,128,color_black);
    CDispFloatAt(g_stPumpSetting[0].SpecNum,0,240,96,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);

    WriteString("序列号:", 60, 140, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    RXLCD_DrawLine(240,167,400,168,color_black);
    CDispFloatAt(g_stPumpSetting[0].SerialNum,0,240,136,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingPump2PageStyle(void)
{
    WriteString("泵信息( 序号 : 2 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("规格号:", 60, 100, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    RXLCD_DrawLine(240,127,400,128,color_black);
    CDispFloatAt(g_stPumpSetting[1].SpecNum,0,240,96,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);

    WriteString("序列号:", 60, 140, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    RXLCD_DrawLine(240,167,400,168,color_black);
    CDispFloatAt(g_stPumpSetting[1].SerialNum,0,240,136,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingPump1Value(void)
{
    CFlashSavePumpSetting(0);
}
void CSettingPump2Value(void)
{
    CFlashSavePumpSetting(1);
}
void CSettingDivider1PageStyle(void)
{
    WriteString("细分选项( 序号 : 1 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("细分数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stPumpSetting[0].Step2Pulse,0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    WriteString("(1,2,4,16)", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y+33, 0x0010, 0 ,1);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingDivider2PageStyle(void)
{
    WriteString("细分选项( 序号 : 2 )", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("细分数:", 60, 120, color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    CDispFloatAt(g_stPumpSetting[1].Step2Pulse,0,240,116,color_black, _FONT_SIZE_MAX,_TANSPERENT_ON);
    WriteString("(1,2,4,16)", _LEVEL4_TITLE_x, _LEVEL4_TITLE_y+33, 0x0010, 0 ,1);
    RXLCD_DrawLine(240,147,400,148,color_black);
    CDrawButton(197,220,282,255,0,2);
}
void CSettingDivider1Value(void)
{
    CDrawIconDone(1);
    g_stPumpSetting[0].StepMode = nLog2(g_stPumpSetting[0].Step2Pulse);
    if(g_stPumpSetting[0].StepMode>3)
        g_stPumpSetting[0].StepMode-=1;
    CFlashSavePumpSetting(0);
}
void CSettingDivider2Value(void)
{
    CDrawIconDone(1);
    g_stPumpSetting[1].StepMode = nLog2(g_stPumpSetting[1].Step2Pulse);
    if(g_stPumpSetting[1].StepMode>3)
        g_stPumpSetting[1].StepMode-=1;
    CFlashSavePumpSetting(1);
}

//******************************end of line***************************************


