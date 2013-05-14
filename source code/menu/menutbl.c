/******************************************************************************/
/* menutbl.c:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/


#define __MENUTBL__
/* NXP LPC17xx definitions            */
#include "LPC17xx.h"                    
#include "type.h"
#include "define.h"
#include "struct.h"
#include "menudef.h"
#include "menutbl.h"
#include "menu.h"
#include "menufunc.h"
#include "pump.h"
//==========================BlankMenuItems============================================
MenuItemType BlankMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 MenuActive
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,// x, y;
        2, 3, // UnSelPic, SelPic;
        MainMenu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawMainPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

};

//==========================MainMenuItems============================================
MenuItemType MainMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 DebugMenu
    { 
        0, 0, 168, 41,// x1,y1,x2,y2;
        0, 0,// x, y;
        21, 22, // UnSelPic, SelPic;
        DebugMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    },
    //1 2 TestMenu
    { 
        0, 43, 168, 79,// x1,y1,x2,y2;
        0, 43,// x, y;
        21, 22, // UnSelPic, SelPic;
        TestMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    },
    //1 3 SettingMenu
    { 
        0, 81, 168, 117,// x1,y1,x2,y2;
        0, 81,// x, y;
        21, 22, // UnSelPic, SelPic;
        SettingMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    },
    //1 4 StatusMenu
    { 
        0, 119, 168, 155,// x1,y1,x2,y2;
        0, 119,// x, y;
        21, 22, // UnSelPic, SelPic;
        StatusMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    },
    //1 5 InfoMenu
    { 
        0, 157, 168, 193,// x1,y1,x2,y2;
        0, 157,// x, y;
        21, 22, // UnSelPic, SelPic;
        InfoMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    },
    //1 6 WarningMenu
    { 
        0, 195, 168, 231,// x1,y1,x2,y2;
        0, 195,// x, y;
        21, 22, // UnSelPic, SelPic;
        WarningMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    },
    //1 7 AboutMenu
    { 
        0, 233, 168, 269,// x1,y1,x2,y2;
        0, 233,// x, y;
        21, 22, // UnSelPic, SelPic;
        AboutMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel1,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_1  // Flags
    }
};

//==========================DebugMenuItems============================================
MenuItemType DebugMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 DebugOptMenu
    { 
        178, 9, 320, 37,// x1,y1,x2,y2;
        178, 9,// x, y;
        21, 22, // UnSelPic, SelPic;
        DebugOptMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 2 DebugPumpMenu
    { 
        178, 39, 320, 67,// x1,y1,x2,y2;
        178, 39,// x, y;
        21, 22, // UnSelPic, SelPic;
        DebugPumpMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 3 DebugValveMenu
    { 
        178, 69, 320, 97,// x1,y1,x2,y2;
        178, 69,// x, y;
        21, 22, // UnSelPic, SelPic;
        DebugValveMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 4 DebugMeasureDevMenu
    { 
        178, 99, 320, 127,// x1,y1,x2,y2;
        178, 99,// x, y;
        21, 22, // UnSelPic, SelPic;
        DebugMeasureDevMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 5 DebugSetFreqMenu
    { 
        178, 129, 320, 157,// x1,y1,x2,y2;
        178, 129,// x, y;
        21, 22, // UnSelPic, SelPic;
        DebugSetFreqMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
};

//==========================TestMenuItems============================================
MenuItemType TestMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 TestPumpResetMenu
    { 
        178, 47, 320, 75,// x1,y1,x2,y2;
        178, 47,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestPumpResetMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 2 TestValveResetMenu
    { 
        178, 77, 320, 105,// x1,y1,x2,y2;
        178, 77,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestValveResetMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 3 TestBurnInMenu
    { 
        178, 107, 320, 135,// x1,y1,x2,y2;
        178, 107,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestBurnInMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 4 TestWaterWeighMenu
    { 
        178, 137, 320, 165,// x1,y1,x2,y2;
        178, 137,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestWaterWeighMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 5 TestBacklashMenu
    { 
        178, 167, 320, 195,// x1,y1,x2,y2;
        178, 167,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestBacklashMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 6 TestLeakageMenu
    { 
        178, 197, 320, 225,// x1,y1,x2,y2;
        178, 197,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestLeakageMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
};

//==========================SettingMenuItems============================================
MenuItemType SettingMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 SettingOptMenu
    { 
        178, 85, 320, 113,// x1,y1,x2,y2;
        178, 85,// x, y;
        27, 28, // UnSelPic, SelPic;
        SettingOptMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 2 SettingPumpMenu
    { 
        178, 115, 320, 143,// x1,y1,x2,y2;
        178, 115,// x, y;
        27, 28, // UnSelPic, SelPic;
        SettingPumpMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 3 SettingDividerMenu
    { 
        178, 145, 320, 173,// x1,y1,x2,y2;
        178, 145,// x, y;
        27, 28, // UnSelPic, SelPic;
        SettingDividerMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 4 SettingAccelerationMenu
    { 
        178, 175, 320, 203,// x1,y1,x2,y2;
        178, 175,// x, y;
        27, 28, // UnSelPic, SelPic;
        SettingAccelerationMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 5 SettingBalanceMenu
    { 
        178, 205, 320, 233,// x1,y1,x2,y2;
        178, 205,// x, y;
        27, 28, // UnSelPic, SelPic;
        SettingBalanceMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
    //1 6 SettingMicroMeterMenu
    { 
        178, 235, 320, 263,// x1,y1,x2,y2;
        178, 235,// x, y;
        27, 28, // UnSelPic, SelPic;
        SettingMicroMeterMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_2  // Flags
    },
};

//==========================AboutMenuItems============================================
MenuItemType AboutMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};
//==========================DebugOptMenuItems============================================
MenuItemType DebugOptMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Opt1
    { 
        333, 9, 475, 37,// x1,y1,x2,y2;
        333, 146,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugOpt1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CDebugOpt1Start,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Opt2
    { 
        333, 39, 475, 67,// x1,y1,x2,y2;
        333, 176,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugOpt2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CDebugOpt2Start,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 3 Opt3
    { 
        333, 69, 475, 97,// x1,y1,x2,y2;
        333, 206,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugOpt3Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CDebugOpt3Start,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 4 Opt4
    { 
        333, 99, 475, 127,// x1,y1,x2,y2;
        333, 236,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugOpt4Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CDebugOpt4Start,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugOpt1MenuItems============================================
MenuItemType DebugOpt1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugOpt1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CDebugOpt1Stop,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugOpt2MenuItems============================================
MenuItemType DebugOpt2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugOpt2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },


    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CDebugOpt2Stop,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugOpt3MenuItems============================================
MenuItemType DebugOpt3MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugOpt3PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },


    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CDebugOpt3Stop,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugOpt4MenuItems============================================
MenuItemType DebugOpt4MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugOpt4PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },


    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CDebugOpt4Stop,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugPumpMenuItems============================================
MenuItemType DebugPumpMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Pump1
    { 
        333, 39, 475, 67,//// x1,y1,x2,y2;
        333, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugPump1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pump2
    { 
        333, 69, 475, 97,// x1,y1,x2,y2;
        333, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugPump2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugPump1MenuItems============================================
MenuItemType DebugPump1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugPump1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1SetValue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================DebugPump2MenuItems============================================
MenuItemType DebugPump2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugPump2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1SetValue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump2RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump2RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================DebugValveMenuItems============================================
MenuItemType DebugValveMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Valve1
    { 
        333, 69, 475, 97,// x1,y1,x2,y2;
        168, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugValve1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Valve2
    { 
        333, 99, 475, 127,// x1,y1,x2,y2;
        168, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugValve2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 3 Valve3
    { 
        333, 129, 475, 157,// x1,y1,x2,y2;
        168, 69,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugValve3Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 4 Valve4
    { 
        333, 159, 475, 187,// x1,y1,x2,y2;
        168, 99,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugValve4Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugValve1MenuItems============================================
MenuItemType DebugValve1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugValve1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugValve2MenuItems============================================
MenuItemType DebugValve2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugValve2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },


    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugValve3MenuItems============================================
MenuItemType DebugValve3MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugValve3PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },


    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================DebugValve4MenuItems============================================
MenuItemType DebugValve4MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CDebugValve4PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },


    //1 2 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};
//==========================DebugMeasureDevMenuItems============================================
MenuItemType DebugMeasureDevMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 DebugBalanceMenu
    { 
        333, 99, 475, 127,// x1,y1,x2,y2;
        333, 78,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugBalanceMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 DebugMicrometerMenu
    { 
        333, 129, 475, 157,// x1,y1,x2,y2;
        333, 108,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugMicrometerMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

};
//==========================TestPumpResetMenuItems============================================
MenuItemType TestPumpResetMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Pump1
    { 
        333, 47, 475, 75,// x1,y1,x2,y2;
        333, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestPumpReset1Menu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestPump1Reset,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pump2
    { 
        333, 77, 475, 95,// x1,y1,x2,y2;
        333, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestPumpReset2Menu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestPump2Reset,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

};

//==========================TestValveResetMenuItems============================================
MenuItemType TestValveResetMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Valve1
    { 
        333, 77, 475, 105,// x1,y1,x2,y2;
        168, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset1Menu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestValve1Reset,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Valve2
    { 
        333, 107, 475, 135,// x1,y1,x2,y2;
        168, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset2Menu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestValve1Reset,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 3 Valve3
    { 
        333, 137, 475, 165,// x1,y1,x2,y2;
        168, 69,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset3Menu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestValve1Reset,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 4 Valve4
    { 
        333, 167, 475, 195,// x1,y1,x2,y2;
        168, 99,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset4Menu, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestValve1Reset,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================TestBurnInMenuItems============================================
MenuItemType TestBurnInMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CTestBurnInPageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stUISetting.TestVol1,                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        TestBurnInStatusMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawBurninStatus,			// ExecFunction
        CTestBurninSetVol,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================TestBurninStatusMenuItems============================================
MenuItemType TestBurninStatusMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CTestBurninStatusPageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage5,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Start
    { 
        15,220,100,255,// x1,y1,x2,y2;
        0,40,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CTestBruninContinue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================TestWaterWeighMenuItems============================================
MenuItemType TestWaterWeighMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CTestWaterWeighPageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================TestBacklashMenuItems============================================
MenuItemType TestBacklashMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CTestBacklashPageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================TestLeakageMenuItems============================================
MenuItemType TestLeakageMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CTestLeakagePageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================SettingOptMenuItems============================================
MenuItemType SettingOptMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Opt1
    { 
        333, 85, 475, 113,// x1,y1,x2,y2;
        333, 146,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingOpt1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Opt2
    { 
        333, 115, 475, 143,// x1,y1,x2,y2;
        333, 176,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingOpt2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 3 Opt3
    { 
        333, 145, 475, 173,// x1,y1,x2,y2;
        333, 206,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingOpt3Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 4 Opt4
    { 
        333, 175, 475, 203,// x1,y1,x2,y2;
        333, 236,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingOpt4Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};
//==========================SettingPumpMenuItems============================================
MenuItemType SettingPumpMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Pump1
    { 
        333, 115, 475, 143,//// x1,y1,x2,y2;
        333, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingPump1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pump2
    { 
        333, 145, 475, 173,// x1,y1,x2,y2;
        333, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingPump2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};
//==========================SettingDividerMenuItems============================================
MenuItemType SettingDividerMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Divider1
    { 
        333, 145, 475, 173,// x1,y1,x2,y2;
        333, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingDivider1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Divider2
    { 
        333, 175, 475, 203,// x1,y1,x2,y2;
        333, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingDivider2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

};
//==========================SettingAccelerationMenuItems============================================
MenuItemType SettingAccelerationMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Acceleration1
    { 
        333, 175, 475, 203,// x1,y1,x2,y2;
        333, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingAcceleration1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Acceleration2
    { 
        333, 205, 475, 233,// x1,y1,x2,y2;
        333, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingAcceleration2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },

};

//==========================SettingOpt1MenuItems============================================
MenuItemType SettingOpt1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingOpt1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stOptSetting.OptLineNum[0],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingOpt1ShieldValue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================SettingOpt2MenuItems============================================
MenuItemType SettingOpt2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingOpt2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stOptSetting.OptLineNum[1],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingOpt2ShieldValue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },};
//==========================SettingOpt3MenuItems============================================
MenuItemType SettingOpt3MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingOpt3PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stOptSetting.OptLineNum[2],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingOpt3ShieldValue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================SettingOpt4MenuItems============================================
MenuItemType SettingOpt4MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingOpt4PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stOptSetting.OptLineNum[3],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingOpt4ShieldValue,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================SettingPump1MenuItems============================================
MenuItemType SettingPump1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingPump1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,100,400,126,// x1,y1,x2,y2;
        240,100,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].SpecNum,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 2 Line Number
    { 
        240,140,400,166,// x1,y1,x2,y2;
        240,140,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].SerialNum,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingPump1Value,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================SettingPump2MenuItems============================================
MenuItemType SettingPump2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingPump2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,100,400,126,// x1,y1,x2,y2;
        240,100,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].SpecNum,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 2 Line Number
    { 
        240,140,400,166,// x1,y1,x2,y2;
        240,140,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].SerialNum,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingPump2Value,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================SettingDivider1MenuItems============================================
MenuItemType SettingDivider1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingDivider1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step2Pulse,                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingDivider1Value,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================SettingDivider2MenuItems============================================
MenuItemType SettingDivider2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingDivider2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Exit
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Line Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step2Pulse,                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line  // Flags
    },
    //1 3 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingDivider2Value,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};
//==========================SettingAcceleration1MenuItems============================================
MenuItemType SettingAcceleration1MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingAcceleration1PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingAcceleration1Value,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*0),30+(27*0),74+(110*0),50+(27*0),// x1,y1,x2,y2;
        33+(110*0),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[0],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*0),30+(27*0),128+(110*0),50+(27*0),// x1,y1,x2,y2;
        87+(110*0),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[0],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*1),74+(110*0),50+(27*1),// x1,y1,x2,y2;
        33+(110*0),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[1],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*1),128+(110*0),50+(27*1),// x1,y1,x2,y2;
        87+(110*0),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[1],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*2),74+(110*0),50+(27*2),// x1,y1,x2,y2;
        33+(110*0),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[2],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*2),128+(110*0),50+(27*2),// x1,y1,x2,y2;
        87+(110*0),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[2],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*3),74+(110*0),50+(27*3),// x1,y1,x2,y2;
        33+(110*0),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[3],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*3),128+(110*0),50+(27*3),// x1,y1,x2,y2;
        87+(110*0),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[3],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*4),74+(110*0),50+(27*4),// x1,y1,x2,y2;
        33+(110*0),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[4],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*1),128+(110*0),50+(27*1),// x1,y1,x2,y2;
        87+(110*0),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[4],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*1),30+(27*0),74+(110*1),50+(27*0),// x1,y1,x2,y2;
        33+(110*1),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[5],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*1),30+(27*0),128+(110*1),50+(27*0),// x1,y1,x2,y2;
        87+(110*1),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[5],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*1),74+(110*1),50+(27*1),// x1,y1,x2,y2;
        33+(110*1),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[6],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*1),128+(110*1),50+(27*1),// x1,y1,x2,y2;
        87+(110*1),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[6],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*2),74+(110*1),50+(27*2),// x1,y1,x2,y2;
        33+(110*1),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[7],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*2),128+(110*1),50+(27*2),// x1,y1,x2,y2;
        87+(110*1),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[7],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*3),74+(110*1),50+(27*3),// x1,y1,x2,y2;
        33+(110*1),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[8],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*3),128+(110*1),50+(27*3),// x1,y1,x2,y2;
        87+(110*1),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[8],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*4),74+(111*1),50+(27*4),// x1,y1,x2,y2;
        33+(110*1),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[9],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*1),128+(110*1),50+(27*1),// x1,y1,x2,y2;
        87+(110*1),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[9],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*2),30+(27*0),74+(110*2),50+(27*0),// x1,y1,x2,y2;
        33+(110*2),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[10],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*2),30+(27*0),128+(110*2),50+(27*0),// x1,y1,x2,y2;
        87+(110*2),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[10],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*1),74+(110*2),50+(27*1),// x1,y1,x2,y2;
        33+(110*2),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[11],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*1),128+(110*2),50+(27*1),// x1,y1,x2,y2;
        87+(110*2),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[11],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*2),74+(110*2),50+(27*2),// x1,y1,x2,y2;
        33+(110*2),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[12],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*2),128+(110*2),50+(27*2),// x1,y1,x2,y2;
        87+(110*2),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[12],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*3),74+(110*2),50+(27*3),// x1,y1,x2,y2;
        33+(110*2),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[13],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*3),128+(110*2),50+(27*3),// x1,y1,x2,y2;
        87+(110*2),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[13],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*4),74+(110*2),50+(27*4),// x1,y1,x2,y2;
        33+(110*2),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[14],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*1),128+(110*2),50+(27*1),// x1,y1,x2,y2;
        87+(110*2),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[14],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*3),30+(27*0),74+(110*3),50+(27*0),// x1,y1,x2,y2;
        33+(110*3),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[15],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*3),30+(27*0),128+(110*3),50+(27*0),// x1,y1,x2,y2;
        87+(110*3),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[15],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*1),74+(110*3),50+(27*1),// x1,y1,x2,y2;
        33+(110*3),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[16],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*1),128+(110*3),50+(27*1),// x1,y1,x2,y2;
        87+(110*3),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[16],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*2),74+(110*3),50+(27*2),// x1,y1,x2,y2;
        33+(110*3),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[17],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*2),128+(110*3),50+(27*2),// x1,y1,x2,y2;
        87+(110*3),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[17],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*3),74+(110*3),50+(27*3),// x1,y1,x2,y2;
        33+(110*3),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[18],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*3),128+(110*3),50+(27*3),// x1,y1,x2,y2;
        87+(110*3),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[18],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*4),74+(111*3),50+(27*4),// x1,y1,x2,y2;
        33+(110*3),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[0].Freq[19],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*1),128+(110*3),50+(27*1),// x1,y1,x2,y2;
        87+(110*3),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[0].Step[19],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
};
//==========================SettingAcceleration2MenuItems============================================
MenuItemType SettingAcceleration2MenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingAcceleration2PageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        197,220,282,255,// x1,y1,x2,y2;
        180,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CSettingAcceleration2Value,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*0),30+(27*0),74+(110*0),50+(27*0),// x1,y1,x2,y2;
        33+(110*0),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[0],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*0),30+(27*0),128+(110*0),50+(27*0),// x1,y1,x2,y2;
        87+(110*0),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[0],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*1),74+(110*0),50+(27*1),// x1,y1,x2,y2;
        33+(110*0),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[1],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*1),128+(110*0),50+(27*1),// x1,y1,x2,y2;
        87+(110*0),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[1],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*2),74+(110*0),50+(27*2),// x1,y1,x2,y2;
        33+(110*0),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[2],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*2),128+(110*0),50+(27*2),// x1,y1,x2,y2;
        87+(110*0),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[2],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*3),74+(110*0),50+(27*3),// x1,y1,x2,y2;
        33+(110*0),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[3],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*3),128+(110*0),50+(27*3),// x1,y1,x2,y2;
        87+(110*0),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[3],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*0),30+(27*4),74+(110*0),50+(27*4),// x1,y1,x2,y2;
        33+(110*0),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[4],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*0),30+(27*1),128+(110*0),50+(27*1),// x1,y1,x2,y2;
        87+(110*0),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[4],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*1),30+(27*0),74+(110*1),50+(27*0),// x1,y1,x2,y2;
        33+(110*1),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[5],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*1),30+(27*0),128+(110*1),50+(27*0),// x1,y1,x2,y2;
        87+(110*1),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[5],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*1),74+(110*1),50+(27*1),// x1,y1,x2,y2;
        33+(110*1),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[6],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*1),128+(110*1),50+(27*1),// x1,y1,x2,y2;
        87+(110*1),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[6],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*2),74+(110*1),50+(27*2),// x1,y1,x2,y2;
        33+(110*1),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[7],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*2),128+(110*1),50+(27*2),// x1,y1,x2,y2;
        87+(110*1),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[7],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*3),74+(110*1),50+(27*3),// x1,y1,x2,y2;
        33+(110*1),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[8],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*3),128+(110*1),50+(27*3),// x1,y1,x2,y2;
        87+(110*1),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[8],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*1),30+(27*4),74+(111*1),50+(27*4),// x1,y1,x2,y2;
        33+(110*1),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[9],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*1),30+(27*1),128+(110*1),50+(27*1),// x1,y1,x2,y2;
        87+(110*1),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[9],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*2),30+(27*0),74+(110*2),50+(27*0),// x1,y1,x2,y2;
        33+(110*2),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[10],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*2),30+(27*0),128+(110*2),50+(27*0),// x1,y1,x2,y2;
        87+(110*2),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[10],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*1),74+(110*2),50+(27*1),// x1,y1,x2,y2;
        33+(110*2),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[11],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*1),128+(110*2),50+(27*1),// x1,y1,x2,y2;
        87+(110*2),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[11],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*2),74+(110*2),50+(27*2),// x1,y1,x2,y2;
        33+(110*2),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[12],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*2),128+(110*2),50+(27*2),// x1,y1,x2,y2;
        87+(110*2),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[12],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*3),74+(110*2),50+(27*3),// x1,y1,x2,y2;
        33+(110*2),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[13],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*3),128+(110*2),50+(27*3),// x1,y1,x2,y2;
        87+(110*2),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[13],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*2),30+(27*4),74+(110*2),50+(27*4),// x1,y1,x2,y2;
        33+(110*2),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[14],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*2),30+(27*1),128+(110*2),50+(27*1),// x1,y1,x2,y2;
        87+(110*2),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[14],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq1
    { 
        33+(110*3),30+(27*0),74+(110*3),50+(27*0),// x1,y1,x2,y2;
        33+(110*3),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[15],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step1
    { 
        87+(110*3),30+(27*0),128+(110*3),50+(27*0),// x1,y1,x2,y2;
        87+(110*3),30+(27*0),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[15],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*1),74+(110*3),50+(27*1),// x1,y1,x2,y2;
        33+(110*3),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[16],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*1),128+(110*3),50+(27*1),// x1,y1,x2,y2;
        87+(110*3),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[16],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*2),74+(110*3),50+(27*2),// x1,y1,x2,y2;
        33+(110*3),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[17],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*2),128+(110*3),50+(27*2),// x1,y1,x2,y2;
        87+(110*3),30+(27*2),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[17],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*3),74+(110*3),50+(27*3),// x1,y1,x2,y2;
        33+(110*3),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[18],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*3),128+(110*3),50+(27*3),// x1,y1,x2,y2;
        87+(110*3),30+(27*3),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[18],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
    //1 2 Freq2
    { 
        33+(110*3),30+(27*4),74+(111*3),50+(27*4),// x1,y1,x2,y2;
        33+(110*3),30+(27*4),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        &g_stPumpSetting[1].Freq[19],                   //u16* value
        0xffff,               // variable max
        edit_line_min  // Flags
    },
    //1 3 Step2
    { 
        87+(110*3),30+(27*1),128+(110*3),50+(27*1),// x1,y1,x2,y2;
        87+(110*3),30+(27*1),// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        &g_stPumpSetting[1].Step[19],                   //u8* value
        NULL,                   //u16* value
        0x00ff,               // variable max
        edit_line_min  // Flags
    },
};

//==========================SettingBalanceMenuItems============================================
MenuItemType SettingBalanceMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingBalancePageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================SettingMicrometerMenuItems============================================
MenuItemType SettingMicrometerMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CSettingMicrometerPageStyle,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 Enter
    { 
        407, 8, 462, 51,// x1,y1,x2,y2;
        407, 8,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 2 Pulse Number
    { 
        240,120,400,146,// x1,y1,x2,y2;
        240,120,// x, y;
        2, 2, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        edit_line  // Flags
    },
    //1 3 P
    { 
        130,220,215,255,// x1,y1,x2,y2;
        90,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunPositive,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
    //1 4 N
    { 
        265,220,350,255,// x1,y1,x2,y2;
        0,0,// x, y;
        5, 6, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CDebugPump1RunNegative,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        menu_level_4  // Flags
    },
};

//==========================PoleCleanMenuItems============================================
MenuItemType PoleCleanMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 6 Exit
    { 
        304, 11, 386, 45,// x1,y1,x2,y2;
        304, 11,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 7 Enter
    { 
        389, 11, 471, 45,// x1,y1,x2,y2;
        389, 11,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
};

//==========================PoleCleanMenuItems============================================
MenuItemType InputMenuItems[]=
{
    //1 0 NULL
    { 
        0, 0, 0, 0,// x1,y1,x2,y2;
        0, 0,// x, y;
        1, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        0  // Flags
    },
    //1 1 
    { 
        19, 186, 72, 215,// x1,y1,x2,y2;
        19, 186,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 2 
    { 
        91, 186, 144, 215,// x1,y1,x2,y2;
        91, 186,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 3
    { 
        163, 186, 216, 215,// x1,y1,x2,y2;
        163, 186,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 4
    { 
        235, 186, 288, 215,// x1,y1,x2,y2;
        235, 186,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 5
    { 
        307, 186, 360, 215,// x1,y1,x2,y2;
        307, 186,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 6
    { 
        19, 230, 72, 258,// x1,y1,x2,y2;
        19, 230,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 7
    { 
        91, 230, 144, 258,// x1,y1,x2,y2;
        91, 230,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 8
    { 
        163, 230, 216, 258,// x1,y1,x2,y2;
        163, 230,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 9
    { 
        235, 230, 288, 258,// x1,y1,x2,y2;
        235, 230,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 0
    { 
        307, 230, 360, 258,// x1,y1,x2,y2;
        307, 230,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_num_button  // Flags
    },
    //1 Cancle
    { 
        390, 185, 460, 214,// x1,y1,x2,y2;
        390, 185,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CInputBackSpace,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_func_button  // Flags
    },
    //1 Enter
    { 
        390, 229, 460, 259,// x1,y1,x2,y2;
        390, 229,// x, y;
        12, 12, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CPopUpInputResult,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        NULL,                   //u8* value
        NULL,                   //u16* value
        0xffff,               // variable max
        input_func_button  // Flags
    },

};

//==============================================================================================
MenuPageType tblMenus[]=
{
    //1 0 BlankMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        0,//PageLevel
        20,//PicNum;
        0,// PrevMenuPage;
        0,// FatherItemNum;
        BlankMenuItems, // MenuItems;
        sizeof(BlankMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 1 MainMenu
    { 
        0,0,170,271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        1,//PageLevel
        21,//PicNum;
        0,// PrevMenuPage;
        0,// FatherItemNum;
        MainMenuItems, // MenuItems;
        sizeof(MainMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 2 DebugMenu
    { 
        175,6,479,160,// 	x1, y1, x2, y2;
        175, 6,//x ,y
        2,//PageLevel
        21,//PicNum;
        0,// PrevMenuPage;
        1,// FatherItemNum;
        DebugMenuItems, // MenuItems;
        sizeof(DebugMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 3 TestMenu
    { 
        175,44,479,230,// 	x1, y1, x2, y2;
        175, 44,//x ,y
        2,//PageLevel
        25,//PicNum;
        0,// PrevMenuPage;
        2,// FatherItemNum;
        TestMenuItems, // MenuItems;
        sizeof(TestMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 4 SettingMenu
    { 
        175,82,479,266,// 	x1, y1, x2, y2;
        175,82,//x ,y
        2,//PageLevel
        27,//PicNum;
        0,// PrevMenuPage;
        3,// FatherItemNum;
        SettingMenuItems, // MenuItems;
        sizeof(SettingMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 5 StatusMenu
    { 
        175,0,479,271,// 	x1, y1, x2, y2;
        175, 0,//x ,y
        2,//PageLevel
        1,//PicNum;
        0,// PrevMenuPage;
        4,// FatherItemNum;
        AboutMenuItems, // MenuItems;
        sizeof(AboutMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 6 InfoMenu
    { 
        175,0,479,271,// 	x1, y1, x2, y2;
        175, 0,//x ,y
        2,//PageLevel
        1,//PicNum;
        0,// PrevMenuPage;
        5,// FatherItemNum;
        AboutMenuItems, // MenuItems;
        sizeof(AboutMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 7 WarningMenu
    { 
        175,0,479,271,// 	x1, y1, x2, y2;
        175, 0,//x ,y
        2,//PageLevel
        1,//PicNum;
        0,// PrevMenuPage;
        6,// FatherItemNum;
        AboutMenuItems, // MenuItems;
        sizeof(AboutMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 8 AboutMenu
    { 
        175,0,479,271,// 	x1, y1, x2, y2;
        175, 0,//x ,y
        2,//PageLevel
        1,//PicNum;
        0,// PrevMenuPage;
        7,// FatherItemNum;
        AboutMenuItems, // MenuItems;
        sizeof(AboutMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 9 DebugOptMenu
    { 
        331, 6, 479, 132,// 	x1, y1, x2, y2;
        331, 143,//x ,y
        3,//PageLevel
        23,//PicNum;
        DebugMenu,// PrevMenuPage;
        1,// FatherItemNum;
        DebugOptMenuItems, // MenuItems;
        sizeof(DebugOptMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 10 DebugPumpMenu
    { 
        331, 36, 479, 100,// 	x1, y1, x2, y2;
        331, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        DebugMenu,// PrevMenuPage;
        2,// FatherItemNum;
        DebugPumpMenuItems, // MenuItems;
        sizeof(DebugPumpMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 11 DebugValveMenu
    { 
        331, 66, 479, 192,// 	x1, y1, x2, y2;
        166, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        DebugMenu,// PrevMenuPage;
        3,// FatherItemNum;
        DebugValveMenuItems, // MenuItems;
        sizeof(DebugValveMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 12 DebugMeasureDevMenu
    { 
        331, 96, 479, 159,// 	x1, y1, x2, y2;
        331, 75,//x ,y
        3,//PageLevel
        23,//PicNum;
        DebugMenu,// PrevMenuPage;
        4,// FatherItemNum;
        DebugMeasureDevMenuItems, // MenuItems;
        sizeof(DebugMeasureDevMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 13 DebugSetFreqMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        0,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 14 TestPumpResetMenu
    { 
        331, 44, 479, 108,// 	x1, y1, x2, y2;
        331, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        TestMenu,// PrevMenuPage;
        1,// FatherItemNum;
        TestPumpResetMenuItems, // MenuItems;
        sizeof(TestPumpResetMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 15 TestValveResetMenu
    { 
        331, 74, 479, 200,// 	x1, y1, x2, y2;
        166, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        TestMenu,// PrevMenuPage;
        2,// FatherItemNum;
        TestValveResetMenuItems, // MenuItems;
        sizeof(TestValveResetMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 16 TestBurnInMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        3,// FatherItemNum;
        TestBurnInMenuItems, // MenuItems;
        sizeof(TestBurnInMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 17 TestWaterWeighMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        4,// FatherItemNum;
        TestWaterWeighMenuItems, // MenuItems;
        sizeof(TestWaterWeighMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 18 TestBacklashMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        5,// FatherItemNum;
        TestBacklashMenuItems, // MenuItems;
        sizeof(TestBacklashMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 19 TestLeakageMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        6,// FatherItemNum;
        TestLeakageMenuItems, // MenuItems;
        sizeof(TestLeakageMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 20 SettingOptMenu
    { 
        331, 82, 479, 208,// 	x1, y1, x2, y2;
        331, 143,//x ,y
        3,//PageLevel
        23,//PicNum;
        SettingMenu,// PrevMenuPage;
        1,// FatherItemNum;
        SettingOptMenuItems, // MenuItems;
        sizeof(SettingOptMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 21 SettingPumpMenu
    { 
        331, 112, 479, 176,// 	x1, y1, x2, y2;
        331, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        SettingMenu,// PrevMenuPage;
        2,// FatherItemNum;
        SettingPumpMenuItems, // MenuItems;
        sizeof(SettingPumpMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 22 SettingDividerMenu
    { 
        331, 142, 479, 206,// 	x1, y1, x2, y2;
        331, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        SettingMenu,// PrevMenuPage;
        3,// FatherItemNum;
        SettingDividerMenuItems, // MenuItems;
        sizeof(SettingDividerMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 23 SettingAccelerationMenu
    { 
        331, 172, 479, 236,// 	x1, y1, x2, y2;
        331, 6,//x ,y
        3,//PageLevel
        23,//PicNum;
        SettingMenu,// PrevMenuPage;
        4,// FatherItemNum;
        SettingAccelerationMenuItems, // MenuItems;
        sizeof(SettingAccelerationMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 24 SettingBalanceMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        5,// FatherItemNum;
        SettingBalanceMenuItems, // MenuItems;
        sizeof(SettingBalanceMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 25 SettingMicroMeterMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        6,// FatherItemNum;
        SettingMicrometerMenuItems, // MenuItems;
        sizeof(SettingMicrometerMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 26 DebugOpt1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        1,// FatherItemNum;
        DebugOpt1MenuItems, // MenuItems;
        sizeof(DebugOpt1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 27 DebugOpt2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        1,// FatherItemNum;
        DebugOpt2MenuItems, // MenuItems;
        sizeof(DebugOpt2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 28 DebugOpt3Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        1,// FatherItemNum;
        DebugOpt3MenuItems, // MenuItems;
        sizeof(DebugOpt3MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 29 DebugOpt4Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        1,// FatherItemNum;
        DebugOpt4MenuItems, // MenuItems;
        sizeof(DebugOpt4MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 30 DebugPump1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        2,// FatherItemNum;
        DebugPump1MenuItems, // MenuItems;
        sizeof(DebugPump1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 31 DebugPump2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        2,// FatherItemNum;
        DebugPump2MenuItems, // MenuItems;
        sizeof(DebugPump2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 32 DebugValve1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        3,// FatherItemNum;
        DebugValve1MenuItems, // MenuItems;
        sizeof(DebugValve1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 33 DebugValve2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        3,// FatherItemNum;
        DebugValve2MenuItems, // MenuItems;
        sizeof(DebugValve2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 34 DebugValve3Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        3,// FatherItemNum;
        DebugValve3MenuItems, // MenuItems;
        sizeof(DebugValve3MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 35 DebugValve4Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        3,// FatherItemNum;
        DebugValve4MenuItems, // MenuItems;
        sizeof(DebugValve4MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 36 DebugBalanceMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        4,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 37 DebugMicrometerMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        DebugMenu,// PrevMenuPage;
        4,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 38 TestPumpReset1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        1,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 39 TestPumpReset2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        1,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 40 TestValveReset1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        2,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 41 TestValveReset2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        2,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 42 TestValveReset3Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        2,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 43 TestValveReset4Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        TestMenu,// PrevMenuPage;
        2,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 44 SettingOpt1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        1,// FatherItemNum;
        SettingOpt1MenuItems, // MenuItems;
        sizeof(SettingOpt1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 45 SettingOpt2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        1,// FatherItemNum;
        SettingOpt2MenuItems, // MenuItems;
        sizeof(SettingOpt2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 46 SettingOpt3Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        1,// FatherItemNum;
        SettingOpt3MenuItems, // MenuItems;
        sizeof(SettingOpt3MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 47 SettingOpt4Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        1,// FatherItemNum;
        SettingOpt4MenuItems, // MenuItems;
        sizeof(SettingOpt4MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 48 SettingPump1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        2,// FatherItemNum;
        SettingPump1MenuItems, // MenuItems;
        sizeof(SettingPump1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 49 SettingPump2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        2,// FatherItemNum;
        SettingPump2MenuItems, // MenuItems;
        sizeof(SettingPump2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 50 SettingDivider1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        3,// FatherItemNum;
        SettingDivider1MenuItems, // MenuItems;
        sizeof(SettingDivider1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 51 SettingDivider2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        3,// FatherItemNum;
        SettingDivider2MenuItems, // MenuItems;
        sizeof(SettingDivider2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 52 SettingAcceleration1Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        13,//PicNum;
        SettingMenu,// PrevMenuPage;
        4,// FatherItemNum;
        SettingAcceleration1MenuItems, // MenuItems;
        sizeof(SettingAcceleration1MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 53 SettingAcceleration2Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        13,//PicNum;
        SettingMenu,// PrevMenuPage;
        4,// FatherItemNum;
        SettingAcceleration2MenuItems, // MenuItems;
        sizeof(SettingAcceleration2MenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 54 TestBurnInStatusMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        5,//PageLevel
        19,//PicNum;
        TestBurnInMenu,// PrevMenuPage;
        0,// FatherItemNum;
        TestBurninStatusMenuItems, // MenuItems;
        sizeof(TestBurninStatusMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },

    //1 0xFE InputMenu
    { 
        0, 170, 479, 271,// 	x1, y1, x2, y2;
        0, 228,//x ,y
        0xfe,//PageLevel
        12,//PicNum;
        0,// PrevMenuPage;
        0,// FatherItemNum;
        InputMenuItems, // MenuItems;
        sizeof(InputMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },

};
//*******************************END OF LINE***********************************//

