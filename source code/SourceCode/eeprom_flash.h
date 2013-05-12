/*****************************************************************************
 *   eeprom.h:  EEPROM module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/

#define RTC_CKS                                                 0x12
#define UI_CKS                                                   0x22
#define PUMP1_CKS                                            0x32
#define PUMP2_CKS                                            0x42
#define OPT_CKS                                            0x51
#define TP_CKS                                                     0x74

#define SPI_FLASH_CKS                                       0x93



#define INDEX_RTC_CKS                                                   0
#define INDEX_UI_CKS                                                     1
#define INDEX_PUMP1_CKS                                       2
#define INDEX_TP_CKS                                                    3
#define INDEX_PUMP2_CKS                                       4
#define INDEX_OPT1_CKS                                          5
#define INDEX_OPT2_CKS                                          6
#define INDEX_OPT3_CKS                                          7
#define INDEX_OPT4_CKS                                          8
#define INDEX_CKS_NUM                                                   9



#define SECTOR_SIZE  0x10000
#define SECTOR_NUM   64
#define PAGE_SIZE    0x100
#define PAGE_NUM     0x100

#define CELL_SIZE                                 32
#define SAVE_NUM_OF_PAGE                (PAGE_SIZE/CELL_SIZE)  ////////代表每个page能存多少个区块


#define SECTOR_TP_VALUE      0                                                                                             // 0
#define PAGE_TP_VALUE          (SECTOR_TP_VALUE*PAGE_NUM)
#define SECTOR_TP_VALUE_NUM                                  1

#define SECTOR_UI_SETTING       1                         // 1
#define PAGE_UI_SETTING           (SECTOR_UI_SETTING*PAGE_NUM)
#define SECTOR_UI_SETTING_NUM                               1                

#define SECTOR_PUMP1_SETTING       2                         // 2
#define PAGE_PUMP1_SETTING           (SECTOR_PUMP1_SETTING*PAGE_NUM)
#define SECTOR_PUMP1_SETTING_NUM                               1             

#define SECTOR_PUMP2_SETTING       3                         // 3
#define PAGE_PUMP2_SETTING           (SECTOR_PUMP2_SETTING*PAGE_NUM)
#define SECTOR_PUMP2_SETTING_NUM                               1             

#define SECTOR_OPT_SETTING       3                         // 3
#define PAGE_OPT_SETTING           (SECTOR_OPT_SETTING*PAGE_NUM)
#define SECTOR_OPT_SETTING_NUM                               4    



#define SECTOR_CKS                                                           62                         
#define PAGE_CKS                          (SECTOR_CKS*PAGE_NUM)
#define SECTOR_CKS_NUM                                                  1

#define SECTOR_FLASH_CKS                                               63
#define PAGE_SPI_FLASH_CKS                                                         (SECTOR_FLASH_CKS*PAGE_NUM)
#define SECTOR_FLASH_CKS_NUM                                       1

//=============================FLASH 1==================================
#define SECTOR_PROJECT                                               0
#define PAGE_PROJECT         (SECTOR_PROJECT*PAGE_NUM)
#define SECTOR_PROJECT_NUM                                       1



#ifdef __FLASH__
//--------------------------------------------------
// Global Variables
//--------------------------------------------------
u32 g_u32CellIndex=0;
u8 g_u8MoveTable[256];
u8 g_u8CellLast=0;
u8 g_u8CellNew=0;
u32 g_u32PageLast=0;
u32 g_u32PageNew=0;
u8 g_u8InitSector=0;
//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------
void CFlashStartupCheck(void);
void CFlashCheck(void);
void CFlashRTCCheck(void);
void CFlashUICheck(void);
void CFlashPump1Check(void);
void CFlashPump2Check(void);
void CFlashTPCheck(void);
void CFlashOptCheck(u8 Index);

void CFlashClearFlashBuff(void);
void CFlashClearFlashMoveBuff(void);
void CEepromClearFlashIDBuff(void);
void CFlashSaveUISetting(void);
void CFlashLoadUISetting(void);
void CFlashLoadUISettingDefault(void);
void CFlashSaveTouchPoint(void);
void CFlashLoadTouchPoint(void);
void CFlashLoadTouchPointDefault(void);
void CFlashSavePump1Setting(void);
void CFlashLoadPump1Setting(void);
void CFlashLoadPump1SettingDefault(void);
void CFlashSavePump2Setting(void);
void CFlashLoadPump2Setting(void);
void CFlashLoadPump2SettingDefault(void);
void CFlashSaveOptSetting(u8 Index);
void CFlashLoadOptSetting(u8 Index);
void CFlashLoadOptSettingDefault(u8 Index);
#else
//--------------------------------------------------
// Extern Global Variables
//--------------------------------------------------
extern u32 g_u32CellIndex;
extern u8 g_u8MoveTable[256];
extern u8 g_u8CellLast;
extern u8 g_u8CellNew;
extern u32 g_u32PageLast;
extern u32 g_u32PageNew;
extern u8 g_u8InitSector;


//--------------------------------------------------
// Extern Function Prototypes
//--------------------------------------------------
extern void CFlashStartupCheck(void);
extern void CFlashRTCCheck(void);
extern void CFlashClearFlashBuff(void);
extern void CFlashClearFlashMoveBuff(void);
extern void CFlashSaveUISetting(void);
extern void CFlashLoadUISetting(void);
extern void CFlashLoadUISettingDefault(void);
extern void CFlashSaveTouchPoint(void);
extern void CFlashLoadTouchPoint(void);
extern void CFlashLoadTouchPointDefault(void);
extern void CFlashSavePump1Setting(void);
extern void CFlashLoadPump1Setting(void);
extern void CFlashLoadPump1SettingDefault(void);
extern void CFlashSavePump2Setting(void);
extern void CFlashLoadPump2Setting(void);
extern void CFlashLoadPump2SettingDefault(void);
extern void CFlashSaveOptSetting(u8 Index);
extern void CFlashLoadOptSetting(u8 Index);
extern void CFlashLoadOptSettingDefault(u8 Index);
#endif

