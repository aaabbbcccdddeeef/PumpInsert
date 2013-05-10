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
#define _DT_FORMAT_DEF                              0
#define _BACKLIGHT_OFF_DEF                          5
#define _AUTO_POWER_OFF_DEF                     5    
#define _AUDIO_KEY_DEF                                  0
#define _AUDIO_TIP_DEF                                1
#define _AUDIO_TIMEOUT_DEF                          0
#define _PASSWORD_ON_DEF                            0
#define _LANGUAGE_DEF                                    0

StructUISetting tEEPROM_UISetting_DEFAULT =
{
    _DT_FORMAT_DEF,
    _BACKLIGHT_OFF_DEF,                  
    _AUTO_POWER_OFF_DEF,              
    _AUDIO_KEY_DEF,                         
    _AUDIO_TIP_DEF,                      
    _PASSWORD_ON_DEF,                   
    _LANGUAGE_DEF,   
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
#define _MIN_FREQ_DEF                          10
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
//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
#endif
