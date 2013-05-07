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

#define __POWER__

#include "include.h"

extern void CDeviceInit(void);

//--------------------------------------------------
// Description  : power init
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CPowerInit(void)
{
    g_uiPowerStatus = 1;
    g_uiSystemState = _INITIAL_STATE;

    return;
}
//--------------------------------------------------
// Description  : power flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
uint32_t CPowerHandler(void)
{
    CPowerPanelControl();
    CPowerSystemControl();
    if(g_uiPowerSwitch == 1)
    {
        CPowerControl();
        g_uiPowerSwitch = 0;
        return TRUE;
    }
    return FALSE;
}
//--------------------------------------------------
// Description  : Execute power up/down process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CPowerControl(void)
{
    if(g_uiPowerStatus == 1)//power down process
    {
        g_uiPowerStatus = 0;
        g_uiSystemState = _PWOFF_STATE;
        #if(_PANEL_TYPE == _PANEL_EMBEST)
        GPIO4->FIOCLR   = (1UL<< 28);             /* Turn backlight off */        
        GLCD_clear(Black);
        #elif(_PANEL_TYPE == _PANEL_RX)
        //Write_Dir(0x01,0x00);
        //Write_Dir(0x8b,0x00);
       // RXLCD_clear(0x00);
        #endif
       // SC->PCONP     = PCONP_STANDBY_Val;        /* Power Control for Peripherals      */
       GPIO0->FIOCLR |= (1ul<<8);
        Write_Dir(0X01,0X00);
    }
    else//power up process
    {
        g_uiPowerStatus = 1;
        g_uiSystemState = _INITIAL_STATE;
        GPIO4->FIOSET   = (1UL<< 28);             /* Turn backlight on */
        CDeviceInit();
        
    }

    return;
}
//--------------------------------------------------
// Description  : LCD backlight control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CPowerPanelControl(void)
{
    if(g_uiPowerStatus == 1)
    {
        if(g_uiBacklightOffCounter == 0x0)
        {
            if(g_uiPanelStatus == 1)//((GPIO4->FIOPIN & (1UL<< 28)) == (1UL<< 28))
            {
                g_uiPanelStatus = 0;
                #if(_PANEL_TYPE == _PANEL_EMBEST)
                GPIO4->FIOCLR   = (1UL<< 28);             /* Turn backlight off */        
                #elif(_PANEL_TYPE == _PANEL_RX)
                Write_Dir(0x01,0x00);
                Write_Dir(0x8b,0x00);
                #endif
            }
        }
        else
        {
            if(g_uiPanelStatus == 0)//((GPIO4->FIOPIN & (1UL<< 28)) == 0x00)
            {
                g_uiPanelStatus = 1;
                #if(_PANEL_TYPE == _PANEL_EMBEST)
                GPIO4->FIOSET   = (1UL<< 28);             /* Turn backlight on */
                #elif(_PANEL_TYPE == _PANEL_RX)
                Write_Dir(0x01,0x80);
                Write_Dir(0x8b,0x05);
                #endif
            }
        }
    }
}
//--------------------------------------------------
// Description  : LCD backlight control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void CPowerSystemControl(void)
{
    if((g_uiAutoPowerOffCounter == 0x0)&&(g_uiPowerStatus == 1))
    {
        g_uiPowerSwitch = 1;
    }
}
/**************************end of file************************************/
