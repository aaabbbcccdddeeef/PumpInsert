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
        menu_level_2  // Flags
    },
    //1 4 TestWaterWeighMenu
    { 
        178, 137, 320, 165,// x1,y1,x2,y2;
        178, 137,// x, y;
        25, 26, // UnSelPic, SelPic;
        TestWaterWeighMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselMenuLevel2,			// UnselPicFunction
        CDrawNextPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 4 Opt4
    { 
        333, 99, 475, 127,// x1,y1,x2,y2;
        333, 236,// x, y;
        23, 24, // UnSelPic, SelPic;
        DebugOpt3Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        0  // Flags
    },

    //1 1 Exit
    { 
        304, 11, 386, 45,// x1,y1,x2,y2;
        304, 11,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CDebugOpt1Stop,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 2 Enter
    { 
        389, 11, 471, 45,// x1,y1,x2,y2;
        389, 11,// x, y;
        19, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CDebugOpt1Stop,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        0  // Flags
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
        0  // Flags
    },
    //1 1 Valve1
    { 
        333, 69, 475, 97,// x1,y1,x2,y2;
        168, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        SquareWaveMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 2 Valve2
    { 
        333, 99, 475, 127,// x1,y1,x2,y2;
        168, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        DifferentialPulseMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 3 Valve3
    { 
        333, 129, 475, 157,// x1,y1,x2,y2;
        168, 69,// x, y;
        23, 24, // UnSelPic, SelPic;
        SquareWaveMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 4 Valve4
    { 
        333, 159, 475, 187,// x1,y1,x2,y2;
        168, 99,// x, y;
        23, 24, // UnSelPic, SelPic;
        DifferentialPulseMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        0  // Flags
    },
    //1 1 Pump1
    { 
        333, 47, 475, 75,// x1,y1,x2,y2;
        333, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestPumpReset1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 2 Pump2
    { 
        333, 77, 475, 95,// x1,y1,x2,y2;
        333, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestPumpReset2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        0  // Flags
    },
    //1 1 Valve1
    { 
        333, 77, 475, 105,// x1,y1,x2,y2;
        168, 9,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 2 Valve2
    { 
        333, 107, 475, 135,// x1,y1,x2,y2;
        168, 39,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 3 Valve3
    { 
        333, 137, 475, 165,// x1,y1,x2,y2;
        168, 69,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset3Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 4 Valve4
    { 
        333, 167, 475, 195,// x1,y1,x2,y2;
        168, 99,// x, y;
        23, 24, // UnSelPic, SelPic;
        TestValveReset4Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
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
        0  // Flags
    },
    //1 1 Divider1
    { 
        333, 145, 475, 173,// x1,y1,x2,y2;
        168, 141,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingDivider1Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 2 Divider2
    { 
        333, 175, 475, 203,// x1,y1,x2,y2;
        168, 171,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingDivider2Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 3 Divider4
    { 
        333, 205, 475, 233,// x1,y1,x2,y2;
        168, 201,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingDivider4Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 4 Divider16
    { 
        333, 235, 475, 263,// x1,y1,x2,y2;
        168, 231,// x, y;
        23, 24, // UnSelPic, SelPic;
        SettingDivider16Menu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CDrawPageLevel4,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
};
//==========================PoleActiveMenuItems============================================
MenuItemType PoleActiveMenuItems[]=
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
        0  // Flags
    },
    //1 1 MaxVoltage
    { 
        118, 74, 225, 102,// x1,y1,x2,y2;
        118, 74,// x, y;
        16, 16, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 2 MinVoltage
    { 
        118, 104, 225, 132,// x1,y1,x2,y2;
        118, 104,// x, y;
        16, 16, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 3 ScanNumber
    { 
        118, 134, 225, 162,// x1,y1,x2,y2;
        118, 134,// x, y;
        16, 16, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 4 ScanSpeed
    { 
        118, 164, 225, 192,// x1,y1,x2,y2;
        118, 164,// x, y;
        16, 16, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 5 SampleTime
    { 
        118, 194, 225, 222,// x1,y1,x2,y2;
        118, 194,// x, y;
        16, 16, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 6 Exit
    { 
        304, 35, 386, 69,// x1,y1,x2,y2;
        304, 35,// x, y;
        16, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 7 Enter
    { 
        389, 35, 471, 69,// x1,y1,x2,y2;
        389, 35,// x, y;
        16, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
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
        0  // Flags
    },
    //1 1 CleanVoltage
    { 
        118, 74, 225, 102,// x1,y1,x2,y2;
        118, 74,// x, y;
        19, 19, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 2 CleanTime
    { 
        118, 104, 225, 132,// x1,y1,x2,y2;
        118, 104,// x, y;
        19, 19, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 3 SampleTime
    { 
        118, 134, 225, 162,// x1,y1,x2,y2;
        118, 134,// x, y;
        19, 19, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 4 MixSpeed
    { 
        118, 164, 225, 192,// x1,y1,x2,y2;
        118, 164,// x, y;
        19, 19, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 5 MixTime
    { 
        118, 194, 225, 222,// x1,y1,x2,y2;
        118, 194,// x, y;
        19, 19, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
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
        0  // Flags
    },
};
//==========================SquareWaveMenuItems============================================
MenuItemType SquareWaveMenuItems[]=
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
        0  // Flags
    },
    //1 1 GatheringVoltage
    { 
        105, 71, 212, 96,// x1,y1,x2,y2;
        0, 0,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 2 GatheringTime
    { 
        105, 98, 212, 123,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 3 MixSpeed
    { 
        105, 125, 212, 150,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 4 MixTime
    { 
        105, 152, 212, 177,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 5 BalanceVoltage
    { 
        105, 179, 212, 204,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 6 BalanceTime
    { 
        105, 206, 212, 231,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 7 StartVoltage
    { 
        340, 71, 447, 96,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 8 EndVoltage
    { 
        340, 98, 447, 123,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 9 Amplitude
    { 
        340, 125, 447, 150,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 10 Period
    { 
        340, 152, 447, 177,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 11 StepVoltage
    { 
        340, 179, 447, 204,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 12 SampleWidth
    { 
        340, 206, 447, 231,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 13 Exit
    { 
        304, 35, 386, 69,// x1,y1,x2,y2;
        304, 35,// x, y;
        16, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 14 Enter
    { 
        389, 35, 471, 69,// x1,y1,x2,y2;
        389, 35,// x, y;
        16, 11, // UnSelPic, SelPic;
        SquareWaveTestMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawResultCurve,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
};
//==========================DifferentialPulseMenuItems============================================
MenuItemType DifferentialPulseMenuItems[]=
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
        0  // Flags
    },
    //1 1 GatheringVoltage
    { 
        105, 71, 212, 96,// x1,y1,x2,y2;
        0, 0,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 2 GatheringTime
    { 
        105, 98, 212, 123,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 3 MixSpeed
    { 
        105, 125, 212, 150,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 4 MixTime
    { 
        105, 152, 212, 177,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 5 BalanceVoltage
    { 
        105, 179, 212, 204,// x1,y1,x2,y2;
        48, 82,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 6 BalanceTime
    { 
        105, 206, 212, 231,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 7 StartVoltage
    { 
        340, 71, 447, 96,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 8 EndVoltage
    { 
        340, 98, 447, 123,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 9 PulseAmplitude
    { 
        340, 125, 447, 150,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 10 PulsePeriod
    { 
        340, 152, 447, 177,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 11 StepVoltage
    { 
        340, 179, 447, 204,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 12 SampleWidth
    { 
        340, 206, 447, 231,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 13 PulseWidth
    { 
        340, 233, 447, 258,// x1,y1,x2,y2;
        380, 220,// x, y;
        17, 1, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CNull,			// SelPicFunction
        CDrawUnselPicture,			// UnselPicFunction
        CNull,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        edit_line  // Flags
    },
    //1 14 Exit
    { 
        304, 35, 386, 69,// x1,y1,x2,y2;
        304, 35,// x, y;
        16, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
    //1 15 Enter
    { 
        389, 35, 471, 69,// x1,y1,x2,y2;
        389, 35,// x, y;
        16, 11, // UnSelPic, SelPic;
        DifferentialPulseTestMenu, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawResultCurve,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    },
};
//==========================SquareWaveTestMenuItems============================================
MenuItemType SquareWaveTestMenuItems[]=
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
        0  // Flags
    },

    //1 1 Exit
    { 
        113, 228, 193, 260,// x1,y1,x2,y2;
        305, 36,// x, y;
        12, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage5,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    }
};
//==========================DifferentialPulseTestMenuItems============================================
MenuItemType DifferentialPulseTestMenuItems[]=
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
        0  // Flags
    },

    //1 1 Exit
    { 
        113, 228, 193, 260,// x1,y1,x2,y2;
        305, 36,// x, y;
        12, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelPicture,			// SelPicFunction
        CNull_u8,			// UnselPicFunction
        CDrawPrevPage5,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        0  // Flags
    }
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
        0  // Flags
    },
    //1 1 
    { 
        11, 233, 40, 262,// x1,y1,x2,y2;
        11, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction

        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 2 
    { 
        47, 233, 76, 262,// x1,y1,x2,y2;
        47, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 3
    { 
        83, 233, 112, 262,// x1,y1,x2,y2;
        83, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 4
    { 
        119, 233, 148, 262,// x1,y1,x2,y2;
        119, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 5
    { 
        155, 233, 184, 262,// x1,y1,x2,y2;
        155, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 6
    { 
        191, 233, 220, 262,// x1,y1,x2,y2;
        191, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 7
    { 
        227, 233, 256, 262,// x1,y1,x2,y2;
        227, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 8
    { 
        263, 233, 292, 262,// x1,y1,x2,y2;
        263, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 9
    { 
        299, 233, 328, 262,// x1,y1,x2,y2;
        299, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 0
    { 
        335, 233, 364, 262,// x1,y1,x2,y2;
        335, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CGetInputBit,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_num_button  // Flags
    },
    //1 Cancle
    { 
        376, 233, 418, 262,// x1,y1,x2,y2;
        376, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CInputBackSpace,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
        input_func_button  // Flags
    },
    //1 Enter
    { 
        426, 233, 468, 262,// x1,y1,x2,y2;
        426, 188,// x, y;
        11, 11, // UnSelPic, SelPic;
        0, //NextMenuPage;
        CDrawSelInputPicture,			// SelPicFunction
        CDrawUnselInputPicture,			// UnselPicFunction
        CPopUpInputResult,			// ExecFunction
        CNull,			// DoBeforeExec
        CNull,			// DoAfterExec
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
        0,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 17 TestWaterWeighMenu
    { 
        331, 41, 479, 105,// 	x1, y1, x2, y2;
        331, 41,//x ,y
        3,//PageLevel
        23,//PicNum;
        TestMenu,// PrevMenuPage;
        4,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        331, 142, 479, 268,// 	x1, y1, x2, y2;
        166, 138,//x ,y
        3,//PageLevel
        23,//PicNum;
        SettingMenu,// PrevMenuPage;
        0,// FatherItemNum;
        SettingDividerMenuItems, // MenuItems;
        sizeof(SettingDividerMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 23 SettingAccelerationMenu
    { 
        331, 41, 479, 105,// 	x1, y1, x2, y2;
        331, 41,//x ,y
        4,//PageLevel
        23,//PicNum;
        SettingMenu,// PrevMenuPage;
        4,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
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
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 52 SettingDivider3Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        3,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 53 SettingDivider4Menu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        19,//PicNum;
        SettingMenu,// PrevMenuPage;
        3,// FatherItemNum;
        PoleCleanMenuItems, // MenuItems;
        sizeof(PoleCleanMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 4 SquareWaveMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        17,//PicNum;
        DebugPumpMenu,// PrevMenuPage;
        0,// FatherItemNum;
        SquareWaveMenuItems, // MenuItems;
        sizeof(SquareWaveMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 5 DifferentialPulseMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        4,//PageLevel
        18,//PicNum;
        DebugPumpMenu,// PrevMenuPage;
        0,// FatherItemNum;
        DifferentialPulseMenuItems, // MenuItems;
        sizeof(DifferentialPulseMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 6 SquareWaveTestMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        5,//PageLevel
        12,//PicNum;
        SquareWaveMenu,// PrevMenuPage;
        0,// FatherItemNum;
        SquareWaveTestMenuItems, // MenuItems;
        sizeof(SquareWaveTestMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 7 DifferentialPulseTestMenu
    { 
        0, 0, 479, 271,// 	x1, y1, x2, y2;
        0, 0,//x ,y
        5,//PageLevel
        12,//PicNum;
        DifferentialPulseMenu,// PrevMenuPage;
        0,// FatherItemNum;
        DifferentialPulseTestMenuItems, // MenuItems;
        sizeof(DifferentialPulseTestMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },
    //1 0xFE InputMenu
    { 
        0, 228, 479, 271,// 	x1, y1, x2, y2;
        0, 228,//x ,y
        0xfe,//PageLevel
        11,//PicNum;
        0,// PrevMenuPage;
        0,// FatherItemNum;
        InputMenuItems, // MenuItems;
        sizeof(InputMenuItems)/sizeof(MenuItemType), // MenuItemCount;
        0 //   Flags;
    },

};
//*******************************END OF LINE***********************************//

