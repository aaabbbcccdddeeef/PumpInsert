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
    u8 DTFormat;   /* DT Format value - [0,5] */
    u8 BacklightOff;     /* Backlight off value - [0,5] */
    u8 AutoPowerOff;    /* Auto power off value - [0,5] */
    u8 AudioKey;    /* Audio key setting - [0,1] */
    u8 AudioTip;     /* Audio read setting - [0,1] */
    u8 PasswordOn;    /* password setting - [0,1] */
    u8 Language;    /* Language setting - [0,1] */
    
} StructUISetting;
typedef struct {
    u16 nBackLash;
    u8 MinFreqFactor;   /* DT Format value - [0,5] */
    u8 MaxFreqFactor;     /* Backlight off value - [0,5] */
    u8 FullStepPerClass;    /* Auto power off value - [0,5] */
    u8 nuL2Step;    /* Audio key setting - [0,1] */
    u8 nStep2Pulse;     /* Audio read setting - [0,1] */    
    u8 MaxStepCount;
} StructPumpSetting;
typedef struct {
    u16 xMin;
    u16 xMax;
    u16 yMin;
    u16 yMax;
} StructTouchPoint;

extern StructUISetting g_stUISetting;
extern StructTouchPoint g_stTouchPoint;
extern StructPumpSetting g_stPumpSetting[2];

