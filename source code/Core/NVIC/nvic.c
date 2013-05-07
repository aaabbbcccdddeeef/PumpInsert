#include "LPC17xx.h"
#include "CortexM3.h"
#include "type.h"
#include "nvic.h"

/*******************************************************************************
* Function Name  : NVIC_DeInit
* Description    : Deinitializes the NVIC peripheral registers to their default
*                  reset values.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_DeInit(void)
{
  NVIC_DISABLE0 = 0xFFFFFFFF;
  NVIC_DISABLE1 = 0x00000001;
  NVIC_UNPEND0 = 0xFFFFFFFF;
  NVIC_UNPEND1 = 0x00000001;
  
  NVIC_PRI0 = 0x00000000;
  NVIC_PRI1 = 0x00000000;
  NVIC_PRI2 = 0x00000000;
  NVIC_PRI3 = 0x00000000;
  NVIC_PRI4 = 0x00000000;
  NVIC_PRI5 = 0x00000000;
  NVIC_PRI6 = 0x00000000;
  NVIC_PRI7 = 0x00000000;
  NVIC_PRI8 = 0x00000000;
}

/*******************************************************************************
* Function Name  : NVIC_SCBDeInit
* Description    : Deinitializes the SCB peripheral registers to their default 
*                  reset values.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_SCBDeInit(void)
{
  NVIC_INT_CTRL = 0x0A000000;
  NVIC_VECT_TABLE = 0x00000000;
  NVIC_AP_INT_RST = 0x05FA0000;
  NVIC_SYS_CTRL = 0x00000000;
  NVIC_CFG_CTRL = 0x00000000;
  NVIC_SYS_H_PRI1 = 0x00000000;
  NVIC_SYS_H_PRI2 = 0x00000000;
  NVIC_SYS_H_PRI3 = 0x00000000;
  NVIC_SYS_H_CTRL = 0x00000000;
  NVIC_FAULT_STA = 0xFFFFFFFF;
  NVIC_HARD_F_STA = 0xFFFFFFFF;
  NVIC_DBG_F_STA = 0xFFFFFFFF;
}

/*******************************************************************************
* Function Name  : NVIC_PriorityGroupConfig
* Description    : Configures the priority grouping: pre-emption priority
*                  and subpriority.
* Input          : - NVIC_PriorityGroup: specifies the priority grouping bits
*                    length. This parameter can be one of the following values:
*                       - NVIC_PriorityGroup_0: 0 bits for pre-emption priority
*                         5 bits for subpriority
*                       - NVIC_PriorityGroup_1: 1 bits for pre-emption priority
*                         4 bits for subpriority
*                       - NVIC_PriorityGroup_2: 2 bits for pre-emption priority
*                         3 bits for subpriority
*                       - NVIC_PriorityGroup_3: 3 bits for pre-emption priority
*                         2 bits for subpriority
*                       - NVIC_PriorityGroup_4: 4 bits for pre-emption priority
*                         1 bits for subpriority
*                       - NVIC_PriorityGroup_5: 5 bits for pre-emption priority
*                         0 bits for subpriority
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_PriorityGroupConfig(DWORD NVIC_PriorityGroup)
{
  /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
  NVIC_AP_INT_RST = 0x05FA0000 | NVIC_PriorityGroup;
}

/*******************************************************************************
* Function Name  : NVIC_Init
* Description    : Initializes the NVIC peripheral according to the specified
*                  parameters in the NVIC_InitStruct.
* Input          : - NVIC_InitStruct: pointer to a NVIC_InitTypeDef structure
*                    that contains the configuration information for the
*                    specified NVIC peripheral.
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
{
  DWORD tmppriority = 0x00, tmpreg = 0x00, tmpmask = 0x00;
  DWORD tmppre = 0, tmpsub = 0x1F;

  if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
  {
    /* Compute the Corresponding IRQ Priority --------------------------------*/    
    tmppriority = (0x700 - (NVIC_AP_INT_RST & 0x700))>> 0x08;
    tmppre = (0x5 - tmppriority);
    tmpsub = tmpsub >> tmppriority;
    
    tmppriority = NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority << tmppre;
    tmppriority |=  NVIC_InitStruct->NVIC_IRQChannelSubPriority & tmpsub;

    tmppriority = tmppriority << 0x03;
    tmppriority = tmppriority << ((NVIC_InitStruct->NVIC_IRQChannel & 0x03) * 0x08);
    
    if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 0)
	{
      tmpreg = NVIC_PRI0;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 1)
	{
      tmpreg = NVIC_PRI1;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 2)
	{
      tmpreg = NVIC_PRI2;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 3)
	{
      tmpreg = NVIC_PRI3;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 4)
	{
      tmpreg = NVIC_PRI4;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 5)
	{
      tmpreg = NVIC_PRI5;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 6)
	{
      tmpreg = NVIC_PRI6;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 7)
	{
      tmpreg = NVIC_PRI7;
	}
	else
	{
      tmpreg = NVIC_PRI8;
	}
    tmpmask = 0xFF << ((NVIC_InitStruct->NVIC_IRQChannel & 0x03) * 0x08);
    tmpreg &= ~tmpmask;
    tmppriority &= tmpmask;  
    tmpreg |= tmppriority;
    if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 0)
	{
      NVIC_PRI0 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 1)
	{
      NVIC_PRI1 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 2)
	{
      NVIC_PRI2 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 3)
	{
      NVIC_PRI3 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 4)
	{
      NVIC_PRI4 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 5)
	{
      NVIC_PRI5 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 6)
	{
      NVIC_PRI6 = tmpreg;
	}
	else if ((NVIC_InitStruct->NVIC_IRQChannel >> 0x02) == 7)
	{
      NVIC_PRI7 = tmpreg;
	}
	else
	{
      NVIC_PRI8 = tmpreg;
	}

    /* Enable the Selected IRQ Channels --------------------------------------*/
    if (NVIC_InitStruct->NVIC_IRQChannel >> 0x05)
	{
      NVIC_ENABLE1 = 0x01 << (NVIC_InitStruct->NVIC_IRQChannel & 0x1F);
    }
	else
	{
      NVIC_ENABLE0 = 0x01 << (NVIC_InitStruct->NVIC_IRQChannel & 0x1F);
	}
  }
  else
  {
    /* Disable the Selected IRQ Channels -------------------------------------*/
    if (NVIC_InitStruct->NVIC_IRQChannel >> 0x05)
	{
      NVIC_DISABLE1 = 0x01 << (NVIC_InitStruct->NVIC_IRQChannel & 0x1F);
    }
	else
	{
      NVIC_DISABLE0 = 0x01 << (NVIC_InitStruct->NVIC_IRQChannel & 0x1F);
	}
  }
}

/*******************************************************************************
* Function Name  : NVIC_StructInit
* Description    : Fills each NVIC_InitStruct member with its default value.
* Input          : - NVIC_InitStruct: pointer to a NVIC_InitTypeDef structure which
*                    will be initialized.
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_StructInit(NVIC_InitTypeDef* NVIC_InitStruct)
{
  /* NVIC_InitStruct members default value */
  NVIC_InitStruct->NVIC_IRQChannel = 0x00;
  NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority = 0x00;
  NVIC_InitStruct->NVIC_IRQChannelSubPriority = 0x00;
  NVIC_InitStruct->NVIC_IRQChannelCmd = DISABLE;
}

/*******************************************************************************
* Function Name  : NVIC_GetCurrentPendingIRQChannel
* Description    : Returns the current pending IRQ channel identifier.
* Input          : None
* Output         : None
* Return         : Pending IRQ Channel Identifier.
*******************************************************************************/
WORD NVIC_GetCurrentPendingIRQChannel(void)
{
  return (WORD)((NVIC_INT_CTRL & 0x003FF000) >> 0x0C);
}

/*******************************************************************************
* Function Name  : NVIC_GetIRQChannelPendingBitStatus
* Description    : Checks whether the specified IRQ Channel pending bit is set
*                  or not.
* Input          : - NVIC_IRQChannel: specifies the interrupt pending bit to check.
* Output         : None
* Return         : The new state of IRQ Channel pending bit(SET or RESET).
*******************************************************************************/
ITStatus NVIC_GetIRQChannelPendingBitStatus(BYTE NVIC_IRQChannel)
{
  ITStatus pendingirqstatus = RESET;
  DWORD tmp = 0x00;
  
  tmp = (0x01 << (NVIC_IRQChannel & 0x1F));

  if (NVIC_IRQChannel >> 0x05)
  {
    if ((NVIC_PEND1 & tmp) == tmp)
    {
      pendingirqstatus = SET;
    }
    else
    {
      pendingirqstatus = RESET;
    }
  }
  else
  {
    if ((NVIC_PEND0 & tmp) == tmp)
    {
      pendingirqstatus = SET;
    }
    else
    {
      pendingirqstatus = RESET;
    }
  }
  return pendingirqstatus;
}

/*******************************************************************************
* Function Name  : NVIC_SetIRQChannelPendingBit
* Description    : Sets the NVIC’s interrupt pending bit.
* Input          : - NVIC_IRQChannel: specifies the interrupt pending bit to Set.
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_SetIRQChannelPendingBit(BYTE NVIC_IRQChannel)
{
  NVIC_SW_TRIG = (DWORD)NVIC_IRQChannel;
}

/*******************************************************************************
* Function Name  : NVIC_ClearIRQChannelPendingBit
* Description    : Clears the NVIC’s interrupt pending bit.
* Input          : - NVIC_IRQChannel: specifies the interrupt pending bit to clear.
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_ClearIRQChannelPendingBit(BYTE NVIC_IRQChannel)
{
  if (NVIC_IRQChannel >> 0x05)
  {
    NVIC_UNPEND1 = 0x01 << (NVIC_IRQChannel & 0x1F);
  }
  else
  {
    NVIC_UNPEND0 = 0x01 << (NVIC_IRQChannel & 0x1F);
  }
}

/*******************************************************************************
* Function Name  : NVIC_GetCurrentActiveHandler
* Description    : Returns the current active Handler (IRQ Channel and
*                  SystemHandler) identifier.
* Input          : None
* Output         : None
* Return         : Active Handler Identifier.
*******************************************************************************/
WORD NVIC_GetCurrentActiveHandler(void)
{
  return (WORD)(NVIC_INT_CTRL & 0x1FF);
}

/*******************************************************************************
* Function Name  : NVIC_GetIRQChannelActiveBitStatus
* Description    : Checks whether the specified IRQ Channel active bit is set
*                  or not.
* Input          : - NVIC_IRQChannel: specifies the interrupt active bit to check.
* Output         : None
* Return         : The new state of IRQ Channel active bit(SET or RESET).
*******************************************************************************/
ITStatus NVIC_GetIRQChannelActiveBitStatus(BYTE NVIC_IRQChannel)
{
  ITStatus activeirqstatus = RESET;
  DWORD tmp = 0x00;

  tmp = (0x01 << (NVIC_IRQChannel & 0x1F));

  if (NVIC_IRQChannel >> 0x05)
  {
    if ((NVIC_ACTIVE1 & tmp) == tmp )
    {
      activeirqstatus = SET;
    }
    else
    {
      activeirqstatus = RESET;
    }
  }
  else
  {
    if ((NVIC_ACTIVE0 & tmp) == tmp )
    {
      activeirqstatus = SET;
    }
    else
    {
      activeirqstatus = RESET;
    }
  }
  return activeirqstatus;
}

/*******************************************************************************
* Function Name  : NVIC_GetCPUID
* Description    : Returns the ID number, the version number and the implementation
*                  details of the Cortex-M3 core.
* Input          : None
* Output         : None
* Return         : CPU ID.
*******************************************************************************/
DWORD NVIC_GetCPUID(void)
{
  return NVIC_CPUID;
}

/*******************************************************************************
* Function Name  : NVIC_SetVectorTable
* Description    : Sets the vector table location and Offset.
* Input          : - NVIC_VectTab: specifies if the vector table is in RAM or
*                    FLASH memory.
*                    This parameter can be one of the following values:
*                       - NVIC_VectTab_RAM
*                       - NVIC_VectTab_FLASH
*                  - Offset: Vector Table base offset field. 
*                            This value must be a multiple of 0x100.
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_SetVectorTable(DWORD NVIC_VectTab, DWORD Offset)
{ 
  NVIC_VECT_TABLE = NVIC_VectTab | (Offset & 0x1FFFFF80);
}

/*******************************************************************************
* Function Name  : NVIC_GenerateSystemReset
* Description    : Generates a system reset.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_GenerateSystemReset(void)
{
  NVIC_AP_INT_RST = 0x05FA0000 | 0x04;
}

/*******************************************************************************
* Function Name  : NVIC_GenerateCoreReset
* Description    : Generates a Core (Core + NVIC) reset.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_GenerateCoreReset(void)
{
  NVIC_AP_INT_RST = 0x05FA0000 | 0x01;
}

/*******************************************************************************
* Function Name  : NVIC_SystemLPConfig
* Description    : Selects the condition for the system to enter low power mode.
* Input          : - LowPowerMode: Specifies the new mode for the system to enter
*                    low power mode.
*                    This parameter can be one of the following values:
*                       - NVIC_LP_SEVONPEND
*                       - NVIC_LP_SLEEPDEEP
*                       - NVIC_LP_SLEEPONEXIT
*                  - NewState: new state of LP condition.
*                    This parameter can be: ENABLE or DISABLE.
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_SystemLPConfig(BYTE LowPowerMode, FunctionalState NewState)
{
  if (NewState != DISABLE)
  {
    NVIC_SYS_CTRL |= (DWORD)LowPowerMode;
  }
  else
  {
    NVIC_SYS_CTRL &= ~(DWORD)LowPowerMode;
  }
}

/******************************************************************************
**                            End Of File
******************************************************************************/
