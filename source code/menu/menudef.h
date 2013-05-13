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
    unsigned short x1,y1,x2,y2;//��Ŀ��С�������ܴ��������С�����ð��µĽ�ȡ����Ҳʹ�ô�����
    unsigned short x,y;//ѡ��ѡ���ͼƬ��ȡ��ʼ����
    unsigned char UnSelPic, SelPic;//ѡ���ѡ�����ͼƬ
    unsigned char NextPage;//���ѡ����ʾ ��ҳ��
    fpExecFunc SelPicFunction;//ѡ��ʱִ�к���
    fpExecFunc_u8 UnselPicFunction;//δѡ��ʱִ�к���
    fpExecFunc ExecFunction;//���ʱִ�У�һ��Ϊҳ����ת
    fpExecFunc DoBeforeExec;//���ʱִ�У����ȼ���ExecFunction֮ǰ��һ��Ϊ��Ҫʵ�ֵĹ���
    fpExecFunc DoAfterExec;//���ʱִ�У����ȼ���ExecFunction֮��һ��Ϊ���ļ��˵��Ļ���
    unsigned char* pU8value;
    unsigned short* pU16value;
    unsigned short VariableMaxValue;
    unsigned short Flags; //0928
} MenuItemType;



typedef struct
{ 
    unsigned short x1,y1,x2,y2; //�������˰�ť���Ĳ˵��Ĵ�С
    unsigned short x,y;//��ȡ��ͼƬ��ʼ����
    unsigned short PageLevel;//����˰�ť���Ĳ˵��Ĳ㼶
    unsigned char PicNum;//����˰�ť���Ĳ˵����ڵ�ͼƬ����
    unsigned char PrevPage;  //����˰�ť���Ĳ˵����ڵ�ǰ���˵�
    unsigned char FatherItemNum;//�˰�ť���ڵ�Items index
    MenuItemType* MenuItems;//�˰�ť�µĲ˵���Items
    unsigned char  ItemCount;//�˰�ť�µĲ˵���Items ����
    unsigned short Flags;
} MenuPageType;


//*******************************END OF LINE***********************************//

