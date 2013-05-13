/******************************************************************************/
/* menudef.h:                                      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2009 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

typedef void (*fpExecFunc)(void);
typedef void (*fpExecFunc_u8)(u8);
typedef unsigned char (*fpItemIndex)(void);



typedef enum 
{ 
    BlankMenu,
    MainMenu,
    DebugMenu,
    TestMenu,
    SettingMenu,
    StatusMenu,
    InfoMenu,
    WarningMenu,
    AboutMenu,
    DebugOptMenu,
    DebugPumpMenu,
    DebugValveMenu,
    DebugMeasureDevMenu,
    DebugSetFreqMenu,
    TestPumpResetMenu,
    TestValveResetMenu,
    TestBurnInMenu,
    TestWaterWeighMenu,
    TestBacklashMenu,
    TestLeakageMenu,
    SettingOptMenu,
    SettingPumpMenu,
    SettingDividerMenu,
    SettingAccelerationMenu,
    SettingBalanceMenu,
    SettingMicroMeterMenu,
    DebugOpt1Menu,
    DebugOpt2Menu,
    DebugOpt3Menu,
    DebugOpt4Menu,
    DebugPump1Menu,
    DebugPump2Menu,
    DebugValve1Menu,
    DebugValve2Menu,
    DebugValve3Menu,
    DebugValve4Menu,
    DebugBalanceMenu,
    DebugMicrometerMenu,
    TestPumpReset1Menu,
    TestPumpReset2Menu,
    TestValveReset1Menu,
    TestValveReset2Menu,
    TestValveReset3Menu,
    TestValveReset4Menu,
    SettingOpt1Menu,
    SettingOpt2Menu,
    SettingOpt3Menu,
    SettingOpt4Menu,
    SettingPump1Menu,
    SettingPump2Menu,
    SettingDivider1Menu,
    SettingDivider2Menu,
    TestBurnInStatusMenu,
    SquareWaveMenu,
    DifferentialPulseMenu,
    SquareWaveTestMenu,
    DifferentialPulseTestMenu,
    // user definition end
    InputMenu,
    MaxMenu
} MenuPageIndexType;

typedef struct
{ 
    unsigned short x1,y1,x2,y2;//条目大小，即接受触摸区域大小，设置按下的截取区域也使用此坐标
    unsigned short x,y;//选中选项的图片截取起始坐标
    unsigned char UnSelPic, SelPic;//选项的选中与否图片
    unsigned char NextPage;//点击选项显示 的页面
    fpExecFunc SelPicFunction;//选中时执行函数
    fpExecFunc_u8 UnselPicFunction;//未选中时执行函数
    fpExecFunc ExecFunction;//点击时执行，一般为页面跳转
    fpExecFunc DoBeforeExec;//点击时执行，优先级在ExecFunction之前，一般为所要实现的功能
    fpExecFunc DoAfterExec;//点击时执行，优先级在ExecFunction之后，一般为第四级菜单的绘制
    unsigned char* pU8value;
    unsigned short* pU16value;
    unsigned short VariableMaxValue;
    unsigned short Flags; //0928
} MenuItemType;



typedef struct
{ 
    unsigned short x1,y1,x2,y2; //代表点击此按钮出的菜单的大小
    unsigned short x,y;//截取的图片起始坐标
    unsigned short PageLevel;//点击此按钮出的菜单的层级
    unsigned char PicNum;//点击此按钮出的菜单所在的图片索引
    unsigned char PrevPage;  //点击此按钮出的菜单所在的前级菜单
    unsigned char FatherItemNum;//此按钮所在的Items index
    MenuItemType* MenuItems;//此按钮下的菜单的Items
    unsigned char  ItemCount;//此按钮下的菜单的Items 数量
    unsigned short Flags;
} MenuPageType;


//*******************************END OF LINE***********************************//

