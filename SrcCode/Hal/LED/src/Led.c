/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Led.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led.h"
#include "Led_Lcfg.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
//static IntCtr_Config Int_ButtonCtr;
//static IntCtr_Config Int_ButtonOn;
//static IntCtr_Config Int_ButtonOff;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Led_Init()
{
	Port_Init(&Led_CFG);
	Port_Init(&Button_Ctr);
	Port_Init(&Button_ON);
	Port_Init(&Button_OFF);
	SYSCTRL->RCGCGPIO = 0x0F;
	GPIOA->GPIOIM = 0x01;
	GPIOC->GPIOIM = 0x01;
	GPIOD->GPIOIM = 0x01;
	
	GPIOA->GPIOIS = 0x01;
	GPIOC->GPIOIS = 0x01;
	GPIOD->GPIOIS = 0x01;
	
	GPIOA->GPIOIEV = 0x01;
	GPIOC->GPIOIEV = 0x01;
	GPIOD->GPIOIEV = 0x01;
	
	GPIOA->GPIOIBE = 0x00;
	GPIOC->GPIOIBE = 0x00;
	GPIOD->GPIOIBE = 0x00;
	
	GPIOA->GPIOICR = 0x01;
	GPIOC->GPIOICR = 0x01;
	GPIOD->GPIOICR = 0x01;
	
}
void Interrupt_Init(void)
{
	IntCtrl_EnableIRQ(GPIO_PortA_IRQn	);
	IntCtrl_EnableIRQ(GPIO_PortC_IRQn	);
	IntCtrl_EnableIRQ(GPIO_PortD_IRQn	);
}
void Led_On(void)
{
	
	DIO_WriteChannel(Led_CFG.PortType,Led_CFG.ChannelId,HIGH);
}
void Led_Off(void)
{
	DIO_WriteChannel(Led_CFG.PortType,Led_CFG.ChannelId,LOW);
}



/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
/*Std_ReturnType FunctionName(AnyType parameterName)
{
	
	
}*/

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
