/*****************************************************************************
 *   eeprom.c:  EEPROM module file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.25  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#define __FLASH__
#include "include.h"
/*
#include "lpc17xx.h"
#include <stdio.h>				   	

#include "type.h"
#include "struct.h"
#include "define.h"
#include "spi_flash.h"
#include "eeprom_flash.h"
#include "rtc.h"
#if(_PANEL_VERSION == _RX_V01)
#include "uifunc.h"
#elif(_PANEL_VERSION == _RX_V02)
#include "uifunc_v02.h"
#endif
#include "ui.h"
#include "power.h"
#include "eeprom_default.h"
#include "msd.h"
#include "main.h"
#include "systick.h"
#include "uifunc_v03.h"
*/

/*****************************************************************************
** Function name:		Reset Funtion
**
** Descriptions:		Reset setting
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
//=================================
//每个sector 划分为最小单位为32BYTE 的小区块(0-2040)
//每个sector 的最后一个page 存放当前最小可以用的区块的index
//根据flash 的读写特性，以最后一个page 的每一位来代表区块的index
//=================================


void CFlashSaveIndex(u8 Flash_num, u32 Page, u32 Index)
{
    int i=0;
    int j=0;
    
    if(Index == (SAVE_NUM_OF_SECTOR-1))
    {
        CFlashClearFlashMoveBuff();
        SPIFlash_Read(Flash_num, flash_buf, (Page+254)*PAGE_SIZE, PAGE_SIZE);
        for(i=0;i<CELL_SIZE;i++)
            g_u8MoveTable[i]=flash_buf[PAGE_SIZE-CELL_SIZE+i];
        SPIFlash_EraseSector(Flash_num, Page*PAGE_SIZE);
        SPIFlash_WritePage(Flash_num, g_u8MoveTable, Page*PAGE_SIZE, PAGE_SIZE);
        Index = 1;
    }
    else
    {
        Index++;
    }
    CFlashClearFlashBuff();
    //把写过的Index赋0
    for(i=0;i<(Index/8);i++) 
    {
        for(j=0;j<8;j++)
        {
            flash_buf[255-i] = flash_buf[255-i] & (~(1<<j));
        }
    }

    for(j=0;j<(Index%8);j++)
    {
        flash_buf[255-i] = flash_buf[255-i] & (~(1<<j));
    }
    SPIFlash_WritePage(Flash_num, flash_buf, (Page+255)*PAGE_SIZE, PAGE_SIZE);
}
u32 CFlashLoadIndex(u8 Flash_num, u32 Page)
{
    u32 Index = SAVE_NUM_OF_SECTOR-1;
    int i=0;
    int j=0;
    
    SPIFlash_Read(Flash_num, flash_buf, (Page+255)*PAGE_SIZE, PAGE_SIZE);
    for(i=0;i<(0x100-1);i++) //最后一个page为index page，所以减1
    {
        for(j=0;j<8;j++)
        {
            if(flash_buf[255-i] & (1<<j))
            {
                Index = (i*8)+j;
                return Index;
            }
        }
    }

    return Index;
}
void CFlashGetCell(u8 Flash_num, u32 Page)
{
    g_u32CellIndex = CFlashLoadIndex(Flash_num, Page);
    if(g_u32CellIndex == 0)
    {
        g_u8InitSector = 1;
    }
    else
    {
        g_u32PageLast = (g_u32CellIndex-1)/SAVE_NUM_OF_PAGE;
        g_u32PageNew= g_u32CellIndex/SAVE_NUM_OF_PAGE;
        g_u8CellLast = (g_u32CellIndex-1)%SAVE_NUM_OF_PAGE;
        g_u8CellNew = g_u32CellIndex%SAVE_NUM_OF_PAGE;
    }
}
void CFlashLoadCheckSum(void)
{
    int i;
    
    SPIFlash_Read(_FLASH_NUM0, flash_buf, PAGE_CKS*PAGE_SIZE, PAGE_SIZE);
    for(i=0;i<INDEX_CKS_NUM;i++)
        CheckSumData[i] = flash_buf[i];
}
void CFlashSaveCheckSum(void)
{
    int i;
    
    for(i=0;i<INDEX_CKS_NUM;i++)
        flash_buf[i] = CheckSumData[i];    
    SPIFlash_EraseSector(_FLASH_NUM0, SECTOR_CKS*SECTOR_SIZE);
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, PAGE_CKS*PAGE_SIZE, PAGE_SIZE);
}
void CFlashStartupCheck(void)
{
    CFlashCheck();
    CFlashLoadCheckSum();
    //CFlashRTCCheck();
    CFlashUICheck();
    //CFlashTPCheck();
    CFlashOptCheck();
    CFlashPumpCheck(0);
    CFlashPumpCheck(1);
    CFlashSaveCheckSum();
    return;
   
}
void CFlashLoadDefault(void)
{
    CFlashLoadUISettingDefault();
}

void CFlashCheck(void)
{
    
    SPIFlash_Read(_FLASH_NUM0, flash_buf, PAGE_SPI_FLASH_CKS*PAGE_SIZE, PAGE_SIZE);

    if(flash_buf[0]!= SPI_FLASH_CKS)
    {
        SPIFlash_EraseBulk(_FLASH_NUM0);
        g_8Flash0BulkErase = 1;
        CFlashClearFlashBuff();
        flash_buf[0] = SPI_FLASH_CKS;
        SPIFlash_WritePage(_FLASH_NUM0, flash_buf, PAGE_SPI_FLASH_CKS*PAGE_SIZE, PAGE_SIZE);
    }
}
void CFlashRTCCheck(void)
{
    if(CheckSumData[INDEX_RTC_CKS]!=RTC_CKS)
    {
        RTCSetTimeDefault();
        CheckSumData[INDEX_RTC_CKS] = RTC_CKS;
    }
    else
    {
        g_stCurrent_time = RTCGetTime();
    }
}
void CFlashUICheck(void)
{
    if(CheckSumData[INDEX_UI_CKS]!= UI_CKS)
    {
        CFlashLoadUISettingDefault();
        CheckSumData[INDEX_UI_CKS] = UI_CKS;
    }
    else
    {
        CFlashLoadUISetting();
    }
}
void CFlashOptCheck(void)
{
    if(CheckSumData[INDEX_OPT_CKS]!= OPT_CKS)
    {
        CFlashLoadOptSettingDefault();
        CheckSumData[INDEX_OPT_CKS] = OPT_CKS;
    }
    else
    {
        CFlashLoadOptSetting();
    }
}
void CFlashPumpCheck(u8 Index)
{
    if(CheckSumData[INDEX_PUMP1_CKS+Index]!= PUMP_CKS)
    {
        CFlashLoadPumpSettingDefault(Index);
        CheckSumData[INDEX_PUMP1_CKS+Index] = PUMP_CKS;
    }
    else
    {
        CFlashLoadPumpSetting(Index);
    }
}
void CFlashTPCheck(void)
{
    if(CheckSumData[INDEX_TP_CKS]!= TP_CKS)
    {
        CFlashLoadTouchPointDefault();
        CheckSumData[INDEX_TP_CKS] = TP_CKS;
    }
    else
    {
        CFlashLoadTouchPoint();
    }
}
void CFlashClearFlashBuff(void)
{
    int j;

    for(j=0;j<PAGE_SIZE;j++)
        flash_buf[j] = 0xff;
}
void CFlashClearFlashMoveBuff(void)
{
    int j;

    for(j=0;j<PAGE_SIZE;j++)
        g_u8MoveTable[j] = 0xff;
}
void CEepromClearFlashIDBuff(void)
{
    int j;

    for(j=0;j<PAGE_SIZE;j++)
    {
        if(j<12)
            flash_buf[j] = 0x20;
        else
            flash_buf[j] = 0xff;
    }
}
void CFlashSaveUISetting(void)
{
    CFlashGetCell(_FLASH_NUM0, PAGE_UI_SETTING);
    if(g_u8CellNew == 0)
    {
        CFlashClearFlashBuff();
        flash_buf[0] = g_stUISetting.DebugPumpStep>>8;
        flash_buf[1] = g_stUISetting.DebugPumpStep&0x00ff;
        flash_buf[2] = g_stUISetting.TestVol1;
        flash_buf[3] = g_stUISetting.WaterWeigh>>8;
        flash_buf[4] = g_stUISetting.WaterWeigh&0x00ff;
    }
    else
    {
        SPIFlash_Read(_FLASH_NUM0, flash_buf, (PAGE_UI_SETTING+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
        flash_buf[(CELL_SIZE*g_u8CellNew)+0] = g_stUISetting.DebugPumpStep>>8;
        flash_buf[(CELL_SIZE*g_u8CellNew)+1] = g_stUISetting.DebugPumpStep&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+2] = g_stUISetting.TestVol1;
        flash_buf[(CELL_SIZE*g_u8CellNew)+3] = g_stUISetting.WaterWeigh>>8;
        flash_buf[(CELL_SIZE*g_u8CellNew)+4] = g_stUISetting.WaterWeigh&0x00ff;

    }
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, (PAGE_UI_SETTING+g_u32PageNew)*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, PAGE_UI_SETTING, g_u32CellIndex);
}
void CFlashLoadUISetting(void)
{
    u16 tempValue=0;
    CFlashGetCell(_FLASH_NUM0, PAGE_UI_SETTING);
    
    SPIFlash_Read(_FLASH_NUM0, flash_buf, (PAGE_UI_SETTING+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
    tempValue = flash_buf[(CELL_SIZE*g_u8CellLast)+0];
    g_stUISetting.DebugPumpStep = (tempValue<<8|flash_buf[(CELL_SIZE*g_u8CellLast)+1]);
    g_stUISetting.TestVol1 = flash_buf[(CELL_SIZE*g_u8CellLast)+2];
    tempValue = flash_buf[(CELL_SIZE*g_u8CellLast)+3];
    g_stUISetting.WaterWeigh= (tempValue<<8|flash_buf[(CELL_SIZE*g_u8CellLast)+4]);

}
void CFlashLoadUISettingDefault(void)
{
    g_stUISetting = tEEPROM_UISetting_DEFAULT;
    CFlashClearFlashBuff();
    flash_buf[0] = g_stUISetting.DebugPumpStep>>8;
    flash_buf[1] = g_stUISetting.DebugPumpStep&0x00ff;
    flash_buf[2] = g_stUISetting.TestVol1;
    flash_buf[3] = g_stUISetting.WaterWeigh>>8;
    flash_buf[4] = g_stUISetting.WaterWeigh&0x00ff;
    
    SPIFlash_EraseSector(_FLASH_NUM0, SECTOR_UI_SETTING*SECTOR_SIZE);
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, PAGE_UI_SETTING*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, PAGE_UI_SETTING, 0);
}
void CFlashSaveTouchPoint(void)
{
    CFlashGetCell(_FLASH_NUM0, PAGE_TP_VALUE);
    if(g_u8CellNew == 0)
    {
        CFlashClearFlashBuff();
        flash_buf[0] =(g_stTouchPoint.xMin>>8)&0x00ff;
        flash_buf[1] = g_stTouchPoint.xMin&0x00ff;
        flash_buf[2] =(g_stTouchPoint.xMax>>8)&0x00ff;
        flash_buf[3] = g_stTouchPoint.xMax&0x00ff;
        flash_buf[4] =(g_stTouchPoint.yMin>>8)&0x00ff;
        flash_buf[5] = g_stTouchPoint.yMin&0x00ff;
        flash_buf[6] =(g_stTouchPoint.yMax>>8)&0x00ff;
        flash_buf[7] = g_stTouchPoint.yMax&0x00ff;
    }
    else
    {
        SPIFlash_Read(_FLASH_NUM0, flash_buf, (PAGE_TP_VALUE+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
        flash_buf[(CELL_SIZE*g_u8CellNew)+0] = (g_stTouchPoint.xMin>>8)&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+1] =  g_stTouchPoint.xMin&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+2] = (g_stTouchPoint.xMax>>8)&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+3] =  g_stTouchPoint.xMax&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+4] = (g_stTouchPoint.yMin>>8)&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+5] = g_stTouchPoint.yMin&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+6] = (g_stTouchPoint.yMax>>8)&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+7] =  g_stTouchPoint.yMax&0x00ff;

    }
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, (PAGE_TP_VALUE+g_u32PageNew)*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, PAGE_TP_VALUE, g_u32CellIndex);
}
void CFlashLoadTouchPoint(void)
{
    u16 Temp;
    
    CFlashGetCell(_FLASH_NUM0, PAGE_UI_SETTING);
    
    SPIFlash_Read(_FLASH_NUM0, flash_buf, (PAGE_TP_VALUE+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
    Temp = flash_buf[(CELL_SIZE*g_u8CellLast)+0];
    g_stTouchPoint.xMin= (Temp<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+1];
    Temp = flash_buf[(CELL_SIZE*g_u8CellLast)+2];
    g_stTouchPoint.xMax= (Temp<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+3];
    Temp = flash_buf[(CELL_SIZE*g_u8CellLast)+4];
    g_stTouchPoint.yMin= (Temp<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+5];
    Temp = flash_buf[(CELL_SIZE*g_u8CellLast)+6];
    g_stTouchPoint.yMax= (Temp<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+7];

}
void CFlashLoadTouchPointDefault(void)
{
    g_stTouchPoint= tEEPROM_TouchPoint_DEFAULT;
    CFlashClearFlashBuff();
    flash_buf[0] =(g_stTouchPoint.xMin>>8)&0x00ff;
    flash_buf[1] = g_stTouchPoint.xMin&0x00ff;
    flash_buf[2] =(g_stTouchPoint.xMax>>8)&0x00ff;
    flash_buf[3] = g_stTouchPoint.xMax&0x00ff;
    flash_buf[4] =(g_stTouchPoint.yMin>>8)&0x00ff;
    flash_buf[5] = g_stTouchPoint.yMin&0x00ff;
    flash_buf[6] =(g_stTouchPoint.yMax>>8)&0x00ff;
    flash_buf[7] = g_stTouchPoint.yMax&0x00ff;


    
    SPIFlash_EraseSector(_FLASH_NUM0, SECTOR_TP_VALUE*SECTOR_SIZE);
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, PAGE_TP_VALUE*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, PAGE_TP_VALUE, 0);
}
void CFlashSaveOptSetting(void)
{
    u8 i=0;
    
    CFlashGetCell(_FLASH_NUM0, (PAGE_OPT_SETTING*PAGE_NUM));
    if(g_u8CellNew == 0)
    {
        CFlashClearFlashBuff();
        for(i=0;i<4;i++)
        {
            flash_buf[0+i] = g_stOptSetting.OptLineNum[i];
            flash_buf[4+i] = g_stOptSetting.OptShieldLevel[i];
        }
    }
    else
    {
        SPIFlash_Read(_FLASH_NUM0, flash_buf, ((PAGE_OPT_SETTING*PAGE_NUM)+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
        for(i=0;i<4;i++)
        {
            flash_buf[(CELL_SIZE*g_u8CellNew)+0+i] = g_stOptSetting.OptLineNum[i];
            flash_buf[(CELL_SIZE*g_u8CellNew)+4+i] = g_stOptSetting.OptShieldLevel[i];
        }

    }
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, ((PAGE_OPT_SETTING*PAGE_NUM)+g_u32PageNew)*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, (PAGE_OPT_SETTING*PAGE_NUM), g_u32CellIndex);
}
void CFlashLoadOptSetting(void)
{
    u8 i=0;
    
    CFlashGetCell(_FLASH_NUM0, (PAGE_OPT_SETTING*PAGE_NUM));
    
    SPIFlash_Read(_FLASH_NUM0, flash_buf, ((PAGE_OPT_SETTING*PAGE_NUM)+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
    for(i=0;i<4;i++)
    {
        g_stOptSetting.OptLineNum[i] = flash_buf[(CELL_SIZE*g_u8CellLast)+0+i];
        g_stOptSetting.OptShieldLevel[i] = flash_buf[(CELL_SIZE*g_u8CellLast)+4+i];
    }

}
void CFlashLoadOptSettingDefault(void)
{
    u8 i=0;
    g_stOptSetting = tEEPROM_OptSetting_DEFAULT;
    CFlashClearFlashBuff();
    for(i=0;i<4;i++)
    {
        flash_buf[0+i] = g_stOptSetting.OptLineNum[i];
        flash_buf[4+i] = g_stOptSetting.OptShieldLevel[i];
    }

    
    SPIFlash_EraseSector(_FLASH_NUM0, PAGE_OPT_SETTING*SECTOR_SIZE);
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, (PAGE_OPT_SETTING*PAGE_NUM)*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, (PAGE_OPT_SETTING*PAGE_NUM), 0);
}
void CFlashSavePumpSetting(u8 Index)
{
    u8 i=0;
    CFlashGetCell(_FLASH_NUM0, ((SECTOR_PUMP_SETTING+Index)*PAGE_NUM));
    if(g_u8CellNew == 0)
    {
        CFlashClearFlashBuff();
        for(i=0;i<20;i++)
        {
            flash_buf[2*i+0] = g_stPumpSetting[Index].Freq[i]>>8;
            flash_buf[2*i+1] = g_stPumpSetting[Index].Freq[i]&0x00ff;
        }
        for(i=0;i<20;i++)
            flash_buf[40+i] = g_stPumpSetting[Index].Step[i];
        flash_buf[60] = g_stPumpSetting[Index].StepNum;
        flash_buf[61] = g_stPumpSetting[Index].BackLash>>8;
        flash_buf[62] = g_stPumpSetting[Index].BackLash&0x00ff;
        flash_buf[63] = g_stPumpSetting[Index].uL2Step;
        flash_buf[64] = g_stPumpSetting[Index].Step2Pulse;
        flash_buf[65] = g_stPumpSetting[Index].StepMode;
        flash_buf[66] = g_stPumpSetting[Index].SpecNum>>8;
        flash_buf[67] = g_stPumpSetting[Index].SpecNum&0x00ff;
        flash_buf[68] = g_stPumpSetting[Index].SerialNum>>8;
        flash_buf[69] = g_stPumpSetting[Index].SerialNum&0x00ff;
    }
    else
    {
        SPIFlash_Read(_FLASH_NUM0, flash_buf, ((SECTOR_PUMP_SETTING+Index)+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
        for(i=0;i<20;i++)
        {
            flash_buf[(CELL_SIZE*g_u8CellNew)+2*i+0] = g_stPumpSetting[Index].Freq[i]>>8;
            flash_buf[(CELL_SIZE*g_u8CellNew)+2*i+1] = g_stPumpSetting[Index].Freq[i]&0x00ff;
        }
        for(i=0;i<20;i++)
            flash_buf[(CELL_SIZE*g_u8CellNew)+40+i] = g_stPumpSetting[Index].Step[i];
        flash_buf[(CELL_SIZE*g_u8CellNew)+60] = g_stPumpSetting[Index].StepNum;
        flash_buf[(CELL_SIZE*g_u8CellNew)+61] = g_stPumpSetting[Index].BackLash>>8;
        flash_buf[(CELL_SIZE*g_u8CellNew)+62] = g_stPumpSetting[Index].BackLash&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+63] = g_stPumpSetting[Index].uL2Step;
        flash_buf[(CELL_SIZE*g_u8CellNew)+64] = g_stPumpSetting[Index].Step2Pulse;
        flash_buf[(CELL_SIZE*g_u8CellNew)+65] = g_stPumpSetting[Index].StepMode;
        flash_buf[(CELL_SIZE*g_u8CellNew)+66] = g_stPumpSetting[Index].SpecNum>>8;
        flash_buf[(CELL_SIZE*g_u8CellNew)+67] = g_stPumpSetting[Index].SpecNum&0x00ff;
        flash_buf[(CELL_SIZE*g_u8CellNew)+68] = g_stPumpSetting[Index].SerialNum>>8;
        flash_buf[(CELL_SIZE*g_u8CellNew)+69] = g_stPumpSetting[Index].SerialNum&0x00ff;
        
    }
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, (((SECTOR_PUMP_SETTING+Index)*PAGE_NUM)+g_u32PageNew)*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, ((SECTOR_PUMP_SETTING+Index)*PAGE_NUM), g_u32CellIndex);
}
void CFlashLoadPumpSetting(u8 Index)
{
    u8 i=0;
    u16 tempValue=0;
    CFlashGetCell(_FLASH_NUM0, ((SECTOR_PUMP_SETTING+Index)*PAGE_NUM));
    
    SPIFlash_Read(_FLASH_NUM0, flash_buf, (((SECTOR_PUMP_SETTING+Index)*PAGE_NUM)+g_u32PageLast)*PAGE_SIZE, PAGE_SIZE);
    for(i=0;i<20;i++)
    {
        tempValue = flash_buf[(CELL_SIZE*g_u8CellLast)+2*i+0];
        g_stPumpSetting[Index].Freq[i] = (tempValue<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+2*i+1];
    }
    for(i=0;i<20;i++)
        g_stPumpSetting[Index].Step[i] = flash_buf[(CELL_SIZE*g_u8CellLast)+40+i];
    g_stPumpSetting[Index].StepNum = flash_buf[(CELL_SIZE*g_u8CellLast)+60];
    tempValue = flash_buf[(CELL_SIZE*g_u8CellLast)+61];
    g_stPumpSetting[Index].BackLash = (tempValue<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+62];
    g_stPumpSetting[Index].uL2Step = flash_buf[(CELL_SIZE*g_u8CellLast)+63];
    g_stPumpSetting[Index].Step2Pulse = flash_buf[(CELL_SIZE*g_u8CellLast)+64];
    g_stPumpSetting[Index].StepMode= flash_buf[(CELL_SIZE*g_u8CellLast)+65];
    tempValue = flash_buf[(CELL_SIZE*g_u8CellLast)+66];
    g_stPumpSetting[Index].SpecNum= (tempValue<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+67];
    tempValue = flash_buf[(CELL_SIZE*g_u8CellLast)+68];
    g_stPumpSetting[Index].SerialNum = (tempValue<<8)|flash_buf[(CELL_SIZE*g_u8CellLast)+69];
}
void CFlashLoadPumpSettingDefault(u8 Index)
{
    u8 i=0;
    g_stPumpSetting[Index] = tEEPROM_PUMP_DEFAULT;
    CFlashClearFlashBuff();
    for(i=0;i<20;i++)
    {
        flash_buf[2*i+0] = g_stPumpSetting[Index].Freq[i]>>8;
        flash_buf[2*i+1] = g_stPumpSetting[Index].Freq[i]&0x00ff;
    }
    for(i=0;i<20;i++)
        flash_buf[40+i] = g_stPumpSetting[Index].Step[i];
    flash_buf[60] = g_stPumpSetting[Index].StepNum;
    flash_buf[61] = g_stPumpSetting[Index].BackLash>>8;
    flash_buf[62] = g_stPumpSetting[Index].BackLash&0x00ff;
    flash_buf[63] = g_stPumpSetting[Index].uL2Step;
    flash_buf[64] = g_stPumpSetting[Index].Step2Pulse;
    flash_buf[65] = g_stPumpSetting[Index].StepMode;
    flash_buf[66] = g_stPumpSetting[Index].SpecNum>>8;
    flash_buf[67] = g_stPumpSetting[Index].SpecNum&0x00ff;
    flash_buf[68] = g_stPumpSetting[Index].SerialNum>>8;
    flash_buf[69] = g_stPumpSetting[Index].SerialNum&0x00ff;
    
    SPIFlash_EraseSector(_FLASH_NUM0, (SECTOR_PUMP_SETTING+Index)*SECTOR_SIZE);
    SPIFlash_WritePage(_FLASH_NUM0, flash_buf, ((SECTOR_PUMP_SETTING+Index)*PAGE_NUM)*PAGE_SIZE, PAGE_SIZE);
    CFlashSaveIndex(_FLASH_NUM0, ((SECTOR_PUMP_SETTING+Index)*PAGE_NUM), 0);
}

//====================end of line==========================


