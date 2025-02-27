/*****************************************************************************
 *   i2c.c:  I2C C file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#include <lpc17xx.h>
#include "type.h"
#include "i2c.h"
#include "systick.h"

volatile uint32_t I2CMasterState = I2C_IDLE;
volatile uint32_t I2CSlaveState = I2C_IDLE;

volatile uint32_t I2CCmd;
volatile uint32_t I2CMode;

volatile uint8_t I2CMasterBuffer[BUFSIZE];
volatile uint8_t I2CSlaveBuffer[BUFSIZE];
volatile uint32_t I2CCount = 0;
volatile uint32_t I2CReadLength;
volatile uint32_t I2CWriteLength;

volatile uint32_t RdIndex = 0;
volatile uint32_t WrIndex = 0;

/* 
From device to device, the I2C communication protocol may vary, 
in the example below, the protocol uses repeated start to read data from or 
write to the device:
For master read: the sequence is: STA,Addr(W),offset,RE-STA,Addr(r),data...STO 
for master write: the sequence is: STA,Addr(W),length,RE-STA,Addr(w),data...STO
Thus, in state 8, the address is always WRITE. in state 10, the address could 
be READ or WRITE depending on the I2CCmd.
*/   

/*****************************************************************************
** Function name:		I2C0MasterHandler
**
** Descriptions:		I2C0 interrupt handler, deal with master mode
**				only.
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void I2C0_IRQHandler(void)  
{
  uint8_t StatValue;

  /* this handler deals with master read and master write only */
  StatValue = I2C0->I2STAT;
	
  switch ( StatValue )
  {
	case 0x08:			/* A Start condition is issued. */
	I2C0 ->I2DAT = I2CMasterBuffer[0];
	I2C0 ->I2CONCLR = (I2CONCLR_SIC | I2CONCLR_STAC);
	I2CMasterState = I2C_STARTED;
	break;
	
	case 0x10:			/* A repeated started is issued */
     
	if ( I2CCmd == AD5245_CMD_DATA )
	{
	  I2C0 ->I2DAT = I2CMasterBuffer[2];
	}
    
	I2C0 ->I2CONCLR = (I2CONCLR_SIC | I2CONCLR_STAC);
	I2CMasterState = I2C_RESTARTED;
	break;
	
	case 0x18:			/* Regardless, it's a ACK */
	if ( I2CMasterState == I2C_STARTED )
	{
	  I2C0 ->I2DAT = I2CMasterBuffer[1+WrIndex];
	  WrIndex++;
	  I2CMasterState = DATA_ACK;
	}
	I2C0 ->I2CONCLR = I2CONCLR_SIC;
	break;

	case 0x28:	/* Data byte has been transmitted, regardless ACK or NACK */
	case 0x30:
     #if 0
	if ( WrIndex != I2CWriteLength )
	{   
	  I2C0 ->I2DAT = I2CMasterBuffer[1+WrIndex]; /* this should be the last one */
	  WrIndex++;

	  if ( WrIndex != I2CWriteLength )
	  {   
		I2CMasterState = DATA_ACK;
	  }
	  else
	  {
		I2CMasterState = DATA_NACK;
		if ( I2CReadLength != 0 )
		{
		  I2C0 ->I2CONSET = I2CONSET_STA;	/* Set Repeated-start flag */
		  I2CMasterState = I2C_REPEATED_START;
		}
	  }
	}
	else
	{
	  if ( I2CReadLength != 0 )
	  {
		I2C0 ->I2CONSET = I2CONSET_STA;	/* Set Repeated-start flag */
		I2CMasterState = I2C_REPEATED_START;
	  }
	  else
	  {
		I2CMasterState = DATA_NACK;
		I2C0 ->I2CONSET = I2CONSET_STO;      /* Set Stop flag */
	  }
	}

	I2C0 ->I2CONCLR = I2CONCLR_SIC;
    #else
        if( WrIndex < I2CWriteLength )
            {
            
            I2C0 ->I2DAT = I2CMasterBuffer[1+WrIndex];
            WrIndex++;
            
            }
        else
            I2CMasterState = DATA_NACK;
        I2C0 ->I2CONCLR = I2CONCLR_SIC;
    #endif
	break;
	
	case 0x40:	/* Master Receive, SLA_R has been sent */
	I2C0 ->I2CONSET = I2CONSET_AA;	/* assert ACK after data is received */
	I2C0 ->I2CONCLR = I2CONCLR_SIC;
	break;
	
	case 0x50:	/* Data byte has been received, regardless following ACK or NACK */
	case 0x58:
	I2CMasterBuffer[3+RdIndex] = I2C0 ->I2DAT;
	RdIndex++;
	if ( RdIndex != I2CReadLength )
	{   
	  I2CMasterState = DATA_ACK;
	}
	else
	{
	  RdIndex = 0;
	  I2CMasterState = DATA_NACK;
	}
	I2C0 ->I2CONSET = I2CONSET_AA;	/* assert ACK after data is received */
	I2C0 ->I2CONCLR = I2CONCLR_SIC;
	break;
	
	case 0x20:		/* regardless, it's a NACK */

	case 0x48:
	I2C0 ->I2CONCLR = I2CONCLR_SIC;
	I2CMasterState = DATA_NACK;
	break;
	
	case 0x38:		/* Arbitration lost, in this example, we don't
					deal with multiple master situation */
	default:
	I2C0 ->I2CONCLR = I2CONCLR_SIC;	
	break;
  }


}

/*****************************************************************************
** Function name:		I2CStart
**
** Descriptions:		Create I2C start condition, a timeout
**				value is set if the I2C never gets started,
**				and timed out. It's a fatal error. 
**
** parameters:			None
** Returned value:		true or false, return false if timed out
** 
*****************************************************************************/
uint32_t I2CStart( void )
{
  uint32_t timeout = 0;
  uint32_t retVal = FALSE;
 
  /*--- Issue a start condition ---*/
  I2C0->I2CONSET = I2CONSET_STA;	/* Set Start flag */
    
  /*--- Wait until START transmitted ---*/
  while( 1 )
  {
	if ( I2CMasterState == I2C_STARTED )
	{
	  retVal = TRUE;
	  break;	
	}
	if ( timeout >= MAX_TIMEOUT )
	{
	  retVal = FALSE;
	  break;
	}
	timeout++;
  }
  return( retVal );
}

/*****************************************************************************
** Function name:		I2CStop
**
** Descriptions:		Set the I2C stop condition, if the routine
**				never exit, it's a fatal bus error.
**
** parameters:			None
** Returned value:		true or never return
** 
*****************************************************************************/
uint32_t I2CStop( void )
{
  I2C0 ->I2CONSET = I2CONSET_STO;      /* Set Stop flag */ 
  I2C0 ->I2CONCLR = I2CONCLR_SIC;  /* Clear SI flag */ 
            
  /*--- Wait for STOP detected ---*/
  while( I2C0 ->I2CONSET & I2CONSET_STO );
  return TRUE;
}

/*****************************************************************************
** Function name:		I2CInit
**
** Descriptions:		Initialize I2C controller
**
** parameters:			I2c mode is either MASTER or SLAVE
** Returned value:		true or false, return false if the I2C
**				interrupt handler was not installed correctly
** 
*****************************************************************************/
uint32_t I2CInit( uint32_t I2cMode ) 
{

  SC ->PCONP |= (1 << 19);
  PINCON ->PINSEL1 &= ~0x03C00000;
  PINCON ->PINSEL1 |= 0x01400000;	/* set PIO0.27 and PIO0.28 to I2C0 SDA and SCK */
							/* function to 01 on both SDA and SCK. */
  /*--- Clear flags ---*/
  I2C0 ->I2CONCLR = I2CONCLR_AAC | I2CONCLR_SIC | I2CONCLR_STAC | I2CONCLR_I2ENC;    

  /*--- Reset registers ---*/
  I2C0 ->I2SCLL   = I2SCLL_SCLL;
  I2C0 ->I2SCLH   = I2SCLH_SCLH;

  /* Install interrupt handler */	

  NVIC_EnableIRQ(I2C0_IRQn);

  I2C0 ->I2CONSET = I2CONSET_I2EN;
  return( TRUE );
}

/*****************************************************************************
** Function name:		I2CEngine
**
** Descriptions:		The routine to complete a I2C transaction
**				from start to stop. All the intermitten
**				steps are handled in the interrupt handler.
**				Before this routine is called, the read
**				length, write length, I2C master buffer,
**				and I2C command fields need to be filled.
**				see i2cmst.c for more details. 
**
** parameters:			None
** Returned value:		true or false, return false only if the
**				start condition can never be generated and
**				timed out. 
** 
*****************************************************************************/
uint32_t I2CEngine( void ) 
{
  I2CMasterState = I2C_IDLE;
  RdIndex = 0;
  WrIndex = 0;
  if ( I2CStart() != TRUE )
  {
	I2CStop();
	return ( FALSE );
  }

  while ( 1 )
  {
	if ( I2CMasterState == DATA_NACK )
	{
	  I2CStop();
	  break;
	}
  }    
  return ( TRUE );      
}

void AD5245_Write(u8 addr, u8 cmd, u8 data)
{
    uint32_t i;

    I2CStop();
    Delay10ms(1);
    
    for ( i = 0; i < BUFSIZE; i++ )	/* clear buffer */
    {
        I2CMasterBuffer[i] = 0;
    }
    I2CWriteLength = 2;
    I2CReadLength = 0;
    I2CMasterBuffer[0] = addr;
    I2CMasterBuffer[1] = cmd<<6;
    I2CMasterBuffer[2] = data;	/* configuration value, no change from 
    							default */
    I2CCmd = AD5245_CMD_DATA;
    I2CEngine(); 
}
void AD5245_Read(u8 addr)
{
    uint32_t i;

    I2CStop();
    Delay10ms(1);

    for ( i = 0; i < BUFSIZE; i++ )	/* clear buffer */
    {
        I2CMasterBuffer[i] = 0;
    }
    I2CWriteLength = 0;
    I2CReadLength = 1;
    I2CMasterBuffer[0] = addr|RD_BIT;
    //I2CCmd = LM75_TEMP;
    I2CEngine();
}
/******************************************************************************
**                            End Of File
******************************************************************************/

