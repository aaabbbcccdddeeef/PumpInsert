/*****************************************************************************
 *   systick.h:  Realtime clock C file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#ifdef __SYSTICK__
//--------------------------------------------------
// Global Variables
//--------------------------------------------------
volatile u32 g_ui10msTick = 0; 
volatile u32 g_uiPowerkeyTick = 0;
volatile u32 g_uiTpUpTick=0;
volatile u32 g_uiPump1LostTimeout=0;
volatile u32 g_uiPump2LostTimeout=0;
//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void SysTick_Handler(void);
void Delay10ms(uint32_t time);

#else
//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern volatile u32 g_ui10msTick;
extern volatile u32 g_uiPowerkeyTick;
extern volatile u32 g_uiTpUpTick;
extern volatile u32 g_uiPump1LostTimeout;
extern volatile u32 g_uiPump2LostTimeout;
//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void SysTick_Handler(void);
extern void Delay10ms(uint32_t time);
#endif

