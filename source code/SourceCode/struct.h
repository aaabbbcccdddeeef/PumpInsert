/*****************************************************************************
 *   struct.h:  EEPROM module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/


typedef union{
    u8 array[4];
    float fvalue;
}FloatAndArray;

typedef union{
    u8 array[8];
    double dvalue;
}DoubleAndArray;

typedef struct {
    u8 RTC_Sec;     /* Second value - [0,59] */
    u8 RTC_Min;     /* Minute value - [0,59] */
    u8 RTC_Hour;    /* Hour value - [0,23] */
    u8 RTC_Mday;    /* Day of the month value - [1,31] */
    u8 RTC_Mon;     /* Month value - [1,12] */
    u32 RTC_Year;    /* Year value - [0,4095] */
} RecordDate;

typedef struct {
    u16 DebugPumpStep;   
    u8 TestVol1;
    
} StructUISetting;
typedef struct {
    u16 nBackLash;
    u8 MinFreqFactor;   
    u8 MaxFreqFactor;     
    u8 FullStepPerClass;    
    u8 nuL2Step;    
    u8 nStep2Pulse;     
    u8 MaxStepCount;
    u8 StepMode;
} StructPumpSetting;
typedef struct {
    u8 OptLineNum;  
    u8 OptShieldLevel;
} StructOptSetting;

typedef struct {
    u16 Freq[20];
    u8 Step[20];
    u8 StepNum;
} StructAccelerationSetting;

typedef struct {
    u16 xMin;
    u16 xMax;
    u16 yMin;
    u16 yMax;
} StructTouchPoint;

extern StructUISetting g_stUISetting;
extern StructTouchPoint g_stTouchPoint;
extern StructPumpSetting g_stPumpSetting[2];
extern StructOptSetting g_stOptSetting[4];
extern StructAccelerationSetting g_stAccelerationSetting[2];

