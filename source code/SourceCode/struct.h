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
    u16 WaterWeigh;
} StructUISetting;

typedef struct {
    u8 OptLineNum[4];  
    u8 OptShieldLevel[4];
} StructOptSetting;

typedef struct {
    u16 Freq[20];
    u8 Step[20];
    u8 StepNum;
    u16 BackLash;
    u8 uL2Step;    
    u8 Step2Pulse;     
    u8 StepMode;
    u16 SpecNum;
    u16 SerialNum;
} StructPumpSetting;

typedef struct {
    u16 xMin;
    u16 xMax;
    u16 yMin;
    u16 yMax;
} StructTouchPoint;

typedef struct{
	float pgain;
	float igain;
	float dgain;
	float e[3];
	float result;
}StructPID;

extern StructUISetting g_stUISetting;
extern StructTouchPoint g_stTouchPoint;
extern StructOptSetting g_stOptSetting;
extern StructPumpSetting g_stPumpSetting[2];
extern StructPID HumPID;

