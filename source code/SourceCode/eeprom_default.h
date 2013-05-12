/*****************************************************************************
 *   eeprom_default.h:  EEPROM module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#ifdef __FLASH__

//--------------------------------------------------
// Global Variables
//--------------------------------------------------
#define _DEBUG_PUMP_STEP_DEF                              4000
#define _SETTING_BURNIN_VOL_DEF                              10

StructUISetting tEEPROM_UISetting_DEFAULT =
{
    _DEBUG_PUMP_STEP_DEF,
    _SETTING_BURNIN_VOL_DEF,
};
#define _TP_XMIN_DEF                                          32
#define _TP_XMAX_DEF                                          244
#define _TP_YMIN_DEF                                      25
#define _TP_YMAX_DEF                                     231
StructTouchPoint tEEPROM_TouchPoint_DEFAULT =
{
    _TP_XMIN_DEF,
    _TP_XMAX_DEF,                  
    _TP_YMIN_DEF,              
    _TP_YMAX_DEF,                         
};
#define _BACKLASH_DEF                              40
#define _MIN_FREQ_DEF                          20
#define _MAX_FREQ_DEF                     50    
#define _FULL_STEP_PER_CLASS_DEF                                  1
#define _NUL2STEP_DEF                            2
#define _STEP2PULSE_DEF                                    2

StructPumpSetting tEEPROM_PumpSetting_DEFAULT =
{
    _BACKLASH_DEF,
    _MIN_FREQ_DEF,                  
    _MAX_FREQ_DEF,              
    _FULL_STEP_PER_CLASS_DEF,                         
    _NUL2STEP_DEF,                      
    _STEP2PULSE_DEF,                   
};
#define _DEBUG_OPT_LINE_DEF                              5
#define _DEBUG_OPT_SHIELD_DEF                              1

StructOptSetting tEEPROM_OptSetting_DEFAULT =
{
    _DEBUG_OPT_LINE_DEF,
    _DEBUG_OPT_SHIELD_DEF,
};
//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
#else
//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern StructUISetting tEEPROM_UISetting_DEFAULT;
extern StructTouchPoint tEEPROM_TouchPoint_DEFAULT;
extern StructPumpSetting tEEPROM_PumpSetting_DEFAULT;
extern StructOptSetting tEEPROM_OptSetting_DEFAULT;
//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
#endif
