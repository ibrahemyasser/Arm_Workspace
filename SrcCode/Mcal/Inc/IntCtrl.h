/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  This file has the vector table
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCrtl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	/*********************** Processor Exceptions Numbers ***********************/
	Reset_IRQn						= -15,
	NMI_IRQn						= -14,
	HARD_FAULD_IRQn					= -13,
	Memory_Management_Fault_IRQn	= -12,
	Bus_Fault_IRQn					= -11,
	Usage_Fault_IRQn				= -10,
	SVCall_IRQn						= -5,
	PendSV_IRQn						= -2,
	SysTick_IRQn					= -1,
	//
	/*********************** Processor Interrupts Numbers ***********************/
	GPIO_PortA_IRQn					= 0,
	GPIO_PortB_IRQn					= 1,
	GPIO_PortC_IRQn					= 2,
	GPIO_PortD_IRQn					= 3,
	GPIO_PortE_IRQn					= 4,
	UART0_IRQn						= 5,
	UART1_IRQn						= 6,
	SSI0_IRQn						= 7,
	I2C0_IRQn						= 8,
	PWM0_Fault_IRQn					= 9,
	PWM0_Generator0_IRQn			= 10,
	PWM0_Generator1_IRQn			= 11,
	PWM0_Generator2_IRQn			= 12,
	QEI0_IRQn						= 13,
	ADC0_Sequence0_IRQn				= 14,
	ADC0_Sequence1_IRQn				= 15,
	ADC0_Sequence2_IRQn				= 16,
	ADC0_Sequence3_IRQn				= 17,
	Watchdog_Timers0_1_IRQn			= 18,
	_16_32_Timer_0A_IRQn			= 19,
	_16_32_Timer_0B_IRQn			= 20,
	_16_32_Timer_1A_IRQn			= 21,
	_16_32_Timer_1B_IRQn			= 22,
	_16_32_Timer_2A_IRQn			= 23,
	_16_32_Timer_2B_IRQn			= 24,
	Analog_Comparator0_IRQn			= 25,
	Analog_Comparator1_IRQn			= 26,
	System_Control_IRQn				= 28,
	Flash_And_EEPROM_Control_IRQn	= 29,
	GPIO_PortF_IRQn					= 30,
	UART2_IRQn						= 33,
	SSI1_IRQn						= 34,
	Timer_3A_IRQn					= 35,
	Timer_3B_IRQn					= 36,
	I2C1_IRQn						= 37,
	QEI1_IRQn						= 38,
	CAN0_IRQn						= 39,
	CAN1_IRQn						= 40,
	Hibernation_Module_IRQn			= 43,
	USB_IRQn						= 44,
	PWM_Generator3_IRQn				= 45,
	DMA_Software_IRQn				= 46,
	DMA_Error_IRQn					= 47,
	ADC1_Sequence0_IRQn				= 48,
	ADC1_Sequence1_IRQn				= 49,
	ADC1_Sequence2_IRQn				= 50,
	ADC1_Sequence3_IRQn				= 51,
	SSI2_IRQn						= 57,
	SSI3_IRQn						= 58,
	UART3_IRQn						= 59,
	UART4_IRQn						= 60,
	UART5_IRQn						= 61,
	UART6_IRQn						= 62,
	UART7_IRQn						= 63,
	I2C2_IRQn						= 68,
	I2C3_IRQn						= 69,
	_16_32_Timer_4A_IRQn			= 70,
	_16_32_Timer_4B_IRQn			= 71,
	_16_32_Timer_5A_IRQn			= 92,
	_16_32_Timer_5B_IRQn			= 93,
	_32_64_Timer_0A_IRQn			= 94,
	_32_64_Timer_0B_IRQn	  		= 95,
	_32_64_Timer_1A_IRQn			= 96,
	_32_64_Timer_1B_IRQn			= 97,
	_32_64_Timer_2A_IRQn			= 98,
	_32_64_Timer_2B_IRQn			= 99,
	_32_64_Timer_3A_IRQn			= 100,
	_32_64_Timer_3B_IRQn			= 101,
	_32_64_Timer_4A_IRQn			= 102,
	_32_64_Timer_4B_IRQn			= 103,
	_32_64_Timer_5A_IRQn			= 104,
	_32_64_Timer_5B_IRQn			= 105,
	System_Exception_IRQn			= 106,
	PWM1_Generator0_IRQn			= 134,
	PWM1_Generator1_IRQn			= 135,
	PWM1_Generator2_IRQn			= 136,
	PWM1_Generator3_IRQn			= 137,
	PWM1_Fault_IRQn					= 138
} IRQn_Type;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void);
 
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
