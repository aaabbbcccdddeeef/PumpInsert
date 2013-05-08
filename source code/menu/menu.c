/******************************************************************************/
/* menu.c:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#define __MENU__
/* NXP LPC17xx definitions            */
#include "LPC17xx.h"                    
#include "type.h"
#include "define.h"//=======所有宏定义头文件
#include "struct.h"
#include "main.h"//=======所有全局变量头文件
#include "menudef.h"
#include "menutbl.h"
#include "menu.h"
#include "menufunc.h"
#include "power.h"
#include "touchpad.h"
#include "rx_lcd_v02.h"

//extern MenuPageType tblMenus[];

//--------------------------------------------------
// Description  : UI handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CUIHandler(void)
{
    if((g_u8TPDown == 1)||(g_u8TPUp==1))
    {
        u8 i=0;

        if(g_u8CurrentPageLevel<4)
        {
            for(i=0;i<g_u8StackTop;i++)
            {
                if(g_u8TPDown == 1)
                {
                    if(TP_IsClickDown(tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].x1,tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].y1,tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].x2,tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].y2)==0)
                    {
                        g_u8TPStatus = _TP_DOWN_MOVE;
                    }
                    else
                    {
                        g_u8TPStatus=_TP_DOWN;
                        MenuPageIndex = g_t8MenuStack[i][0];
                        MenuItemIndex = g_t8MenuStack[i][1];

                        break;
                    }
                }
                else if(g_u8TPUp==1)
                {
                    if(TP_IsClickUp(tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].x1,tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].y1,tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].x2,tblMenus[g_t8MenuStack[i][0]].MenuItems[g_t8MenuStack[i][1]].y2)==1)
                    {
                        g_u8TPStatus = _TP_UP;
                        break;
                    }
                    else
                    {
                        g_u8TPStatus=_TP_NONE;
                    }

                }
            }
        }
        else
        {
            for(i=1;i<MenuItemCount;i++)
            {
                if(g_u8TPDown == 1)
                {
                    if(TP_IsClickDown(CurrentMenuItems[i].x1,CurrentMenuItems[i].y1,CurrentMenuItems[i].x2,CurrentMenuItems[i].y2)==0)
                    {
                        g_u8TPStatus = _TP_DOWN_MOVE;
                    }
                    else
                    {
                        g_u8TPStatus=_TP_DOWN;
                        MenuItemIndex = i;
                        break;
                    }
                }
                else if(g_u8TPUp==1)
                {
                    if(TP_IsClickUp(CurrentMenuItems[i].x1,CurrentMenuItems[i].y1,CurrentMenuItems[i].x2,CurrentMenuItems[i].y2)==1)
                    {
                        g_u8TPStatus = _TP_UP;
                        break;
                    }
                    else
                    {
                        g_u8TPStatus=_TP_NONE;
                    }

                }
            }
        }
        g_u8TPUp=0;
        
        switch(g_u8TPStatus)
        {
            case _TP_DOWN:
                if(g_u8Down_Done==0)
                {
                    g_u8Down_Done=1;
                    if(CurrentMenuItem.Flags == menu_level_1)
                        CurrentMenuItems[g_u8MenuLevel1Selected].UnselPicFunction(g_u8MenuLevel1Selected);
                    else if(CurrentMenuItem.Flags == menu_level_2)
                        CurrentMenuItems[g_u8DrawedItemIndex].UnselPicFunction(g_u8DrawedItemIndex);
                    CurrentMenuItem.SelPicFunction();
                    if(CurrentMenuItem.Flags == menu_level_2)
                        g_u8DrawedItemIndex = MenuItemIndex;
                    if(MenuPageIndex == MainMenu)
                        g_u8MenuLevel1Selected=MenuItemIndex;
                }
                break;
            case _TP_UP:
                if(g_u8Down_Done==1)
                {
                    g_u8Down_Done=0;
                    g_u32TP_U_x=0;
                    g_u32TP_U_y=0;
                    //g_u8DrawedItemIndex=MenuItemIndex;
                    CurrentMenuItem.DoBeforeExec();
                    CurrentMenuItem.ExecFunction();
                    CurrentMenuItem.DoAfterExec();                        
                    switch(CurrentMenuItem.Flags)
                    {
                        case edit_line:
                            CDrawInputMenu();
                            break;
                        case input_num_button:
                            CurrentMenuItem.UnselPicFunction(MenuItemIndex);
                            break;
                        case menu_level_4:
                            CurrentMenuItem.UnselPicFunction(MenuItemIndex);
                            break;
                    }
                    if(g_u8MenuLevel2Selected==0)
                        g_u8DrawedItemIndex=0;
                }
                break;
            case _TP_DOWN_MOVE:
                if(g_u8Down_Done==1)
                {
                    //if(CurrentMenuItem.Flags == menu_level_2)
                        //CurrentMenuItems[g_u8DrawedItemIndex].UnselPicFunction(g_u8DrawedItemIndex);
                    g_u8Down_Done=0;
                }
                break;
            case _TP_NONE:
                break;
        }
    }
}


//*******************************END OF LINE***********************************//

