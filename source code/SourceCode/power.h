/*****************************************************************************
 *   system.c:  system module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/

#define _PWOFF_STATE                    0
#define _INITIAL_STATE                  1
#define _ACTIVE_STATE                   2
#define _SLEEP_STATE                     3

#ifdef __POWER__
//--------------------------------------------------
// Global Variables
//--------------------------------------------------
u8 g_uiPowerSwitch=0;
u8 g_uiPowerStatus=0;
u8 g_uiPanelStatus=1;
u8 g_uiSystemState=0;
u8 g_uiPanelOn=0;
u32 g_uiBacklightOffCounter = 0;
u32 g_uiAutoPowerOffCounter = 0;
//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void CPowerInit(void);
uint32_t CPowerHandler(void);
void CPowerControl(void);
void CPowerPanelControl(void);
void CPowerSystemControl(void);
#else
//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern u8 g_uiPowerSwitch;
extern u8 g_uiPowerStatus;
extern u8 g_uiPanelStatus;
extern u8 g_uiSystemState;
extern u8 g_uiPanelOn;
extern u32 g_uiBacklightOffCounter;
extern u32 g_uiAutoPowerOffCounter;
//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void CPowerInit(void);
extern uint32_t CPowerHandler(void);
extern void CPowerControl(void);
extern void CPowerPanelControl(void);
extern void CPowerSystemControl(void);
#endif
//----------------------------------------------------------------------------------------------------

