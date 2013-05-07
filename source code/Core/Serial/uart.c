/*****************************************************************************
 *   uart.c:  UART API file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.27  ver 1.00    Prelimnary version, first Release
 *
******************************************************************************/
#include <lpc17xx.h>
#include "type.h"
#include "uart.h"
//#include "GUI.h"

volatile uint32_t UART3Status;
volatile uint8_t UART3TxEmpty = 1;
volatile uint8_t UART3Buffer[RS_BUFSIZE];
volatile uint32_t UART3Count = 0;

/*****************************************************************************
** Function name:		UART0Handler
**
** Descriptions:		UART0 interrupt handler
**
** parameters:			None
** Returned value:		None
** 
*****************************************************************************/
void UART3_IRQHandler (void) 
{
  uint8_t IIRValue, LSRValue;
  uint8_t Dummy = Dummy;
	
  IIRValue = UART3->IIR;
    
  IIRValue >>= 1;			/* skip pending bit in IIR */
  IIRValue &= 0x07;			/* check bit 1~3, interrupt identification */
  if ( IIRValue == IIR_RLS )		/* Receive Line Status */
  {
	LSRValue = UART3->LSR;
	/* Receive Line Status */
	if ( LSRValue & (LSR_OE|LSR_PE|LSR_FE|LSR_RXFE|LSR_BI) )
	{
	  /* There are errors or break interrupt */
	  /* Read LSR will clear the interrupt */
	  UART3Status = LSRValue;
	  Dummy = UART3->RBR;		/* Dummy read on RX to clear 
							interrupt, then bail out */
	  return;
	}
	if ( LSRValue & LSR_RDR )	/* Receive Data Ready */			
	{
	  /* If no error on RLS, normal ready, save into the data buffer. */
	  /* Note: read RBR will clear the interrupt */
	  UART3Buffer[UART3Count] = UART3->RBR;
	  UART3Count++;
	  if ( UART3Count == RS_BUFSIZE )
	  {
		UART3Count = 0;		/* buffer overflow */
	  }	
	}
  }
  else if ( IIRValue == IIR_RDA )	/* Receive Data Available */
  {
	/* Receive Data Available */
	UART3Buffer[UART3Count] = UART3->RBR;
	UART3Count++;
	if ( UART3Count == RS_BUFSIZE )
	{
	  UART3Count = 0;		/* buffer overflow */
	}
  }
  else if ( IIRValue == IIR_CTI )	/* Character timeout indicator */
  {
	/* Character Time-out indicator */
	UART3Status |= 0x100;		/* Bit 9 as the CTI error */
  }
  else if ( IIRValue == IIR_THRE )	/* THRE, transmit holding register empty */
  {
	/* THRE interrupt */
	LSRValue = UART3->LSR;		/* Check status in the LSR to see if
							valid data in U0THR or not */
	if ( LSRValue & LSR_THRE )
	{
	  UART3TxEmpty = 1;
	}
	else
	{
	  UART3TxEmpty = 0;
	}
  }
    
}

/*****************************************************************************
** Function name:		UARTInit
**
** Descriptions:		Initialize UART0 port, setup pin select,
**						clock, parity, stop bits, FIFO, etc.
**
** parameters:			portNum(0 or 1) and UART baudrate
** Returned value:		true or false, return false only if the 
**						interrupt handler can't be installed to the 
**						VIC table
** 
*****************************************************************************/
uint32_t UARTInit( uint32_t PortNum, uint32_t baudrate )
{
  uint32_t Fdiv;


  {
       SC->PCONP |= (1 << 25);
	PINCON->PINSEL9 |= 0x0f000000;	/* Enable RxD3 P4.28, TxD3 P4.29 */
	
   
    
	UART3->LCR = 0x83;		/* 8 bits, no Parity, 1 Stop bit */
	/* By default, the PCLKSELx value is zero, thus, the PCLK for
	all the peripherals is 1/4 of the SystemFrequency. */ 
    Fdiv = ( SystemFrequency/4/16 ) / baudrate ;	/*baud rate */
    UART3->DLM = Fdiv/256;							
    UART3->DLL = (Fdiv%256)+1;
    UART3->LCR = 0x03;		/* DLAB = 0 */
    UART3->FCR = 0x07;		/* Enable and reset TX and RX FIFO. */

    NVIC_EnableIRQ(UART3_IRQn);

    UART3->IER = IER_RBR | IER_THRE | IER_RLS;	/* Enable UART1 interrupt */
    return (TRUE);
  }

}

/*****************************************************************************
** Function name:		UARTSend
**
** Descriptions:		Send a block of data to the UART 0 port based
**						on the data length
**
** parameters:			portNum, buffer pointer, and data length
** Returned value:		None
** 
*****************************************************************************/
void UARTSend( uint32_t portNum, uint8_t *BufferPtr, uint32_t Length )
{

    {
    while ( Length != 0 )
    {
	  /* THRE status, contain valid data */
	  while ( !(UART3TxEmpty & 0x01) );	
	  UART3->THR = *BufferPtr;
	  UART3TxEmpty = 0;	/* not empty in the THR until it shifts out */
	  BufferPtr++;
	  Length--;
	}
    }
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
