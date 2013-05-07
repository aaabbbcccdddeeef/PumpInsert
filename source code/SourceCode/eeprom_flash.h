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
#define UI_CKS                                                   0x21
#define PASSWORD_CKS                                     0x32
#define TP_CKS                                                     0x74

#define SPI_FLASH_CKS                                       0x91



#define INDEX_RTC_CKS                                                   0
#define INDEX_UI_CKS                                                     1
#define INDEX_PASSWORD_CKS                                       2
#define INDEX_TP_CKS                                                    3
#define INDEX_CKS_NUM                                                   4



#define SECTOR_SIZE  0x10000
#define SECTOR_NUM   64
#define PAGE_SIZE    0x100
#define PAGE_NUM     0x100

#define CELL_SIZE                                 32
#define SAVE_NUM_OF_PAGE                (PAGE_SIZE/CELL_SIZE)  ////////代表每个page能存多少个区块

#if(_SAMPLE_RELEASE == TRUE)
#define RECORD_SIZE                                              32//0x100 
#else
#define RECORD_SIZE                                              64 
#endif
#define RECORD_NUM                                              (PAGE_SIZE/RECORD_SIZE)  //4///4

#define CALI_SIZE                                               256
#define CALI_NUM                                            (PAGE_SIZE/CALI_SIZE)


#define SECTOR_RECORD                                               0
#define PAGE_RECORD         (SECTOR_RECORD*PAGE_NUM)
#define SECTOR_RECORD_NUM                                       1

#define SECTOR_RECORD_BUFF                                      (SECTOR_RECORD+SECTOR_RECORD_NUM)
#define PAGE_RECORD_BUFF         (SECTOR_RECORD_BUFF*PAGE_NUM)
#define SECTOR_RECORD_BUFF_NUM                                       1

#define SECTOR_RECORD_DETAIL                      (SECTOR_RECORD_BUFF+SECTOR_RECORD_BUFF_NUM)                         
#define PAGE_RECORD_DETAIL                          (SECTOR_RECORD_DETAIL*PAGE_NUM)
#define SECTOR_RECORD_DETAIL_NUM                                                  1

#define SECTOR_CALI                                               3
#define PAGE_CALI                                         (SECTOR_CALI*PAGE_NUM)
#define SECTOR_CALI_NUM                                       1

#define SECTOR_CALI_BUFF                                               (SECTOR_CALI+SECTOR_CALI_NUM)
#define PAGE_CALI_BUFF                                         (SECTOR_CALI_BUFF*PAGE_NUM)
#define SECTOR_CALI_BUFF_NUM                                       1

#define SECTOR_CALI_DETAIL                                               (SECTOR_CALI_BUFF+SECTOR_CALI_BUFF_NUM)
#define PAGE_CALI_DETAIL                                         (SECTOR_CALI_DETAIL*PAGE_NUM)
#define SECTOR_CALI_DETAIL_NUM                                       1


#define SECTOR_TP_VALUE      32                                                                                             //32
#define PAGE_TP_VALUE          (SECTOR_TP_VALUE*PAGE_NUM)
#define SECTOR_TP_VALUE_NUM                                  1

#define SECTOR_UI_SETTING       (SECTOR_TP_VALUE+SECTOR_TP_VALUE_NUM)                         //33
#define PAGE_UI_SETTING           (SECTOR_UI_SETTING*PAGE_NUM)
#define SECTOR_UI_SETTING_NUM                               1                

#define SECTOR_PASSWORD       (SECTOR_UI_SETTING+SECTOR_UI_SETTING_NUM)                         //34
#define PAGE_PASSWORD           (SECTOR_PASSWORD*PAGE_NUM)
#define SECTOR_PASSWORD_NUM                               1             


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
void CFlashTPCheck(void);

void CFlashPasswordCheck(void);

u8 CPasswordVerify(void);
void CFlashClearFlashBuff(void);
void CFlashClearFlashMoveBuff(void);
void CEepromClearFlashIDBuff(void);
void CFlashSaveUISetting(void);
void CFlashLoadUISetting(void);
void CFlashLoadUISettingDefault(void);
void CFlashSaveTouchPoint(void);
void CFlashLoadTouchPoint(void);
void CFlashLoadTouchPointDefault(void);




void CFlashSavePassword(void);
void CFlashLoadPasswordDefault(void);
void CFlashLoadDefault(void);
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
extern u8 CPasswordVerify(void);
extern void CFlashClearFlashBuff(void);
extern void CFlashClearFlashMoveBuff(void);
extern void CFlashSaveUISetting(void);
extern void CFlashLoadUISetting(void);
extern void CFlashLoadUISettingDefault(void);
extern void CFlashSaveTouchPoint(void);
extern void CFlashLoadTouchPoint(void);
extern void CFlashLoadTouchPointDefault(void);





extern void CFlashSavePassword(void);
extern void CFlashLoadPasswordDefault(void);
extern void CFlashLoadDefault(void);
#endif

