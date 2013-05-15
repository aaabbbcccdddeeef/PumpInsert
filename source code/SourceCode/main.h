/*****************************************************************************
 *   main.h:  main C entry file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.23  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifdef __MAIN__
//--------------------------------------------------
// Global Variables
//--------------------------------------------------



u8 MenuPageIndex = 0;
u8 MenuItemIndex = 0;
u8 TempPageIndex = 0;
u8 TempItemIndex = 0;
u8 InReport;                                /* HID Input Report    */
u8 OutReport;                               /* HID Out Report      */
u32 OutReport32;                               /* HID Out Report      */
u8 USB_TxBuff[64];
u8 USB_RxBuff[8];
u32 g_ucUSBValue = 0;
u8 flash_buf[256];
u8 CheckSumData[32];
u8 g_8Flash0BulkErase = 0;
u8 g_8Flash1BulkErase = 0;
u8 g_aPasswordTemp[8];
u8 g_stTPx[100];
u8 g_stTPy[100];
u32 g_u32TP_D_x = 0;
u32 g_u32TP_D_y = 0;
u32 g_u32TP_U_x = 0;
u32 g_u32TP_U_y = 0;
u8 g_u8TP_Done = 0;
u8 g_u8Down_Done = 0;
u8 g_u8Up_Done = 0;
u8 g_u8TPDown = 0;
u8 g_u8TPUp = 0;
u8 g_u8TPStatus = 0;
u16 g_u16TPSamIndex = 0;
u32 g_u32totalnum = 0;
u16 t_u16CompressPoint[300];
u8 g_t8InputNumber[8];
u8 g_u8NumberBit = 0;
u8 g_u8MaxInputLength=0;
u32 g_u32InputResult = 0;
u8 g_u8FontSettingFlag = 0;
u8 g_u8DrawedItemIndex = 0;
u8 g_t8MenuStack[23][2];
u8 g_u8StackTop = 0;
u8 g_u8CurrentPageLevel = 0;
u8 g_u8MenuLevel1Selected = 0;
u8 g_u8MenuLevel2Selected = 0;
u32 t_HPoint[300];
u32 t_AValue[300];
u8 g_u8DetectOptSelect = 0xff;
u8 g_u8DetectOptStart = 0;
u8 g_u32OptLevel = 0;
u8 g_u8RunningPause = 0;
u8 g_u8RunningStop=0;
u8 g_u8Inputing=0;


volatile u32 g_u32BurninCount1=0;
volatile u32 g_u32RunningFlow1[50];
volatile u32 g_u32WaitFlow1[50];
volatile u8 g_u8DirectionFlow1[50];
volatile u8 g_u8RunningIndex1=0;
volatile u8 g_u8FlowWaitOver1=0;
volatile u8 g_u8FlowCount1=0;
volatile u8 g_u8RunningStart1=0;
volatile u32 g_u32FlowWaitCount1=0;

volatile u32 g_u32BurninCount2=0;
volatile u32 g_u32RunningFlow2[50];
volatile u32 g_u32WaitFlow2[50];
volatile u8 g_u8DirectionFlow2[50];
volatile u8 g_u8RunningIndex2=0;
volatile u8 g_u8FlowWaitOver2=0;
volatile u8 g_u8FlowCount2=0;
volatile u8 g_u8RunningStart2=0;
volatile u32 g_u32FlowWaitCount2=0;
//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------

#else
//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern u8 MenuPageIndex;
extern u8 MenuItemIndex;
extern u8 TempPageIndex;
extern u8 TempItemIndex;

extern u8 InReport;
extern u8 OutReport;
extern u32 OutReport32;
extern u8 USB_TxBuff[64];
extern u8 USB_RxBuff[8];
extern u32 g_ucUSBValue;
extern u8 flash_buf[256];
extern u8 CheckSumData[32];
extern u8 g_8Flash0BulkErase;
extern u8 g_8Flash1BulkErase;
extern u8 g_aPasswordTemp[8];
extern u8 g_stTPx[100];
extern u8 g_stTPy[100];
extern u32 g_u32TP_D_x;
extern u32 g_u32TP_D_y;
extern u32 g_u32TP_U_x;
extern u32 g_u32TP_U_y;
extern u8 g_u8TP_Done;
extern u8 g_u8Down_Done;
extern u8 g_u8Up_Done;
//--------------------------------------------------
extern u8 g_u8TPDown;
extern u8 g_u8TPUp;
extern u8 g_u8TPStatus;
extern u16 g_u16TPSamIndex;
extern u32 g_u32totalnum;
extern u16 t_u16CompressPoint[400];
extern u8 g_t8InputNumber[10];
extern u8 g_u8NumberBit;
extern u8 g_u8MaxInputLength;

extern u32 g_u32InputResult;
extern u8 g_u8FontSettingFlag;
extern u8 g_u8DrawedItemIndex;
extern u8 g_t8MenuStack[23][2];
extern u8 g_u8StackTop;
extern u8 g_u8CurrentPageLevel;
extern u8 g_u8MenuLevel1Selected;
extern u8 g_u8MenuLevel2Selected;
extern u32 t_HPoint[300];
extern  u32 t_AValue[300];
extern u8 g_u8DetectOptSelect;
extern u8 g_u8DetectOptStart;
extern u8 g_u32OptLevel;
extern u8 g_u8RunningPause;
extern u8 g_u8RunningStop;
extern u8 g_u8Inputing;

extern volatile u32 g_u32BurninCount1;
extern volatile u32 g_u32RunningFlow1[50];
extern volatile u32 g_u32WaitFlow1[50];
extern volatile u8 g_u8DirectionFlow1[50];
extern volatile u8 g_u8RunningIndex1;
extern volatile u8 g_u8FlowWaitOver1;
extern volatile u8 g_u8FlowCount1;
extern volatile u8 g_u8RunningStart1;
extern volatile u32 g_u32FlowWaitCount1;

extern volatile u32 g_u32BurninCount2;
extern volatile u32 g_u32RunningFlow2[50];
extern volatile u32 g_u32WaitFlow2[50];
extern volatile u8 g_u8DirectionFlow2[50];
extern volatile u8 g_u8RunningIndex2;
extern volatile u8 g_u8FlowWaitOver2;
extern volatile u8 g_u8FlowCount2;
extern volatile u8 g_u8RunningStart2;
extern volatile u32 g_u32FlowWaitCount2;
//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void delay(unsigned int nCount)	;

#endif
