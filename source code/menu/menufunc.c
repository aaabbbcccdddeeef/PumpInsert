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
    CutPicture(CurrentMenuItems[Index].UnSelPic , CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1, CurrentMenuItems[Index].x2, CurrentMenuItems[Index].y2, CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1);
    RXLCD_EditNext();
    CutPicture(CurrentMenuItems[Index].UnSelPic , CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1, CurrentMenuItems[Index].x2, CurrentMenuItems[Index].y2, CurrentMenuItems[Index].x1, CurrentMenuItems[Index].y1);
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
    CutPicture(1,CurrentMenu.x1,0,CurrentMenu.x2,271,CurrentMenu.x1,0);//写入图层2
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
    CutPicture(1,0,0,479,271,0,0);//写入图层2
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
    RXLCD_ScrollWindow_Up(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,30);

}
void CHideInputMenu(void)
{
    RXLCD_EditNext();
    //displaypicture(CurrentMenu.PicNum);
    RXLCD_ScrollWindow_Down(CurrentMenu.x1,CurrentMenu.y1,CurrentMenu.x2,CurrentMenu.y2,30);
    MenuPageIndex = TempPageIndex;
    MenuItemIndex = TempItemIndex;
}
void CPopUpInputResult(void)
{
    //u8 i=0;
    CHideInputMenu();

    Write_Dir(0x21,0x00);//复原寄存器
    Write_Dir(0x40,0x00);//复原寄存器
    MenuItemIndex=0;
}
void CGetInputBit(void)
{
    if(g_u8NumberBit<8)
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
            Write_Dir(0x2E,0x00);//设置字符模式32x32/间距0
            Write_Dir(0x2F,0x81);//设置字符IC
            Write_Dir(0x22,0x40);//设置为通透模式

            if(g_u8NumberBit==0)
                FontWrite_Position(TempMenuItem.x1+5, TempMenuItem.y1+10);   //設定顯示位置
            Write_Command(0x02);
            //String(&g_t8InputNumber[g_u8NumberBit]);
            Delay10ms(1);

            Write_Data(g_t8InputNumber[g_u8NumberBit]);
            Delay10ms(1);

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
        Write_Dir(0x2E,0x00);//设置字符模式32x32/间距0
        Write_Dir(0x2F,0x81);//设置字符IC
        Write_Dir(0x22,0x40);//设置为通透模式
        FontWrite_Position(TempMenuItem.x1+5, TempMenuItem.y1+10);   //設定顯示位置
        Write_Command(0x02);
        Delay10ms(1);
        String(&g_t8InputNumber[0]);

        //Write_Data(g_t8InputNumber[g_u8NumberBit]);
        Delay10ms(1);

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
void CDebugOpt1Start(void)
{
    g_u8DetectOptSelect=1;
    g_u8DetectOptStart=1;
    g_u32OptLevel = 0xff; 
}
void CDebugOpt1PageStyle(void)
{
    WriteString("光耦调试( 序号 : 1 )", 15, 15, color_black, _FONT_SIZE_NORMAL,_TANSPERENT_ON);
    WriteString("提示: 此电位代表光耦在当前状态下,MCU读取到的电位水平", 15, 240, color_brown, _FONT_SIZE_MIN,_TANSPERENT_ON);
}
void CDebugOpt1Stop(void)
{
    g_u8DetectOptSelect=0xff;
    g_u8DetectOptStart=0;
    g_u32OptLevel = 0xff; 
}

//******************************end of line***************************************


