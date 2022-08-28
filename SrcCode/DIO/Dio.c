/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
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
#include "Mcu_Hw.h"
#include "Dio_Cfg.h"
#include "Bit_Math.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


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

DIO_LevelType DIO_ReadChannel (DIO_PortType PortId ,DIO_ChannelType ChannelId)
{
	switch(PortId)
	{
		case PORTA:
				return GET_BIT(((GPIOA->GPIODATA) + (1 << (2 + ChannelId) )),ChannelId);
		case PORTB:
				return GET_BIT(((GPIOB->GPIODATA) + (1 << (2 + ChannelId) )),ChannelId);
		case PORTC:
				return GET_BIT(((GPIOC->GPIODATA) + (1 << (2 + ChannelId) )),ChannelId);
		case PORTD:
				return GET_BIT(((GPIOD->GPIODATA) + (1 << (2 + ChannelId) )),ChannelId);
		case PORTE:
				return GET_BIT(((GPIOE->GPIODATA) + (1 << (2 + ChannelId) )),ChannelId);
		case PORTF:
				return GET_BIT(((GPIOF->GPIODATA) + (1 << (2 + ChannelId) )),ChannelId);
	}
	

	return 0;
}

void DIO_WriteChannel ( DIO_PortType PortId , DIO_ChannelType ChannelId, DIO_LevelType Level)
{
	if (Level)
	{
		switch(PortId)
		{
			case PORTA:
					SET_BIT(*((uint32_t*)((GPIOA->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					
					break;
			case PORTB:
					SET_BIT(*((uint32_t*)((GPIOB->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTC:
					SET_BIT(*((uint32_t*)((GPIOC->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTD:
					SET_BIT(*((uint32_t*)((GPIOD->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTE:
					SET_BIT(*((uint32_t*)((GPIOE->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTF:
					SET_BIT(*((uint32_t*)((GPIOF->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
		}
	}else
	{
		switch(PortId)
		{
			case PORTA:
					CLEAR_BIT(*((uint32_t*)((GPIOA->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					
					break;
			case PORTB:
					CLEAR_BIT(*((uint32_t*)((GPIOB->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTC:
					CLEAR_BIT(*((uint32_t*)((GPIOC->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTD:
					CLEAR_BIT(*((uint32_t*)((GPIOD->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTE:
					CLEAR_BIT(*((uint32_t*)((GPIOE->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTF:
					CLEAR_BIT(*((uint32_t*)((GPIOF->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
		}
	}
}

DIO_PortLevelType DIO_ReadPort (DIO_PortType PortId)
{
	switch(PortId)
	{
		case PORTA:
				return (DIO_PortLevelType)((GPIOA->GPIODATA) + (255 << (2) ));
		case PORTB:
				return (DIO_PortLevelType)((GPIOB->GPIODATA) + (255 << (2) ));
		case PORTC:
				return (DIO_PortLevelType)((GPIOC->GPIODATA) + (255 << (2) ));
		case PORTD:
				return (DIO_PortLevelType)((GPIOD->GPIODATA) + (255 << (2) ));
		case PORTE:
				return (DIO_PortLevelType)((GPIOE->GPIODATA) + (255 << (2) ));
		case PORTF:
				return (DIO_PortLevelType)((GPIOF->GPIODATA) + (255 << (2) ));
	}

	return 0;
}

void DIO_WritePort (DIO_PortType PortId, DIO_PortLevelType Level)
{
	switch(PortId)
	{
		case PORTA:
				*(uint32_t*)((GPIOF->GPIODATA) + (255 << (2) )) = Level;
				break;
		case PORTB:
				*(uint32_t*)((GPIOF->GPIODATA) + (255 << (2) )) = Level;
				break;	
		case PORTC:
				*(uint32_t*)((GPIOF->GPIODATA) + (255 << (2) )) = Level;
				break;
		case PORTD:
				*(uint32_t*)((GPIOF->GPIODATA) + (255 << (2) )) = Level;
				break;
		case PORTE:
				*(uint32_t*)((GPIOF->GPIODATA) + (255 << (2) )) = Level;
				break;
		case PORTF:
				*(uint32_t*)((GPIOF->GPIODATA) + (255 << (2) )) = Level;
				break;
	}

}

void DIO_FlipChannel (DIO_PortType PortId,DIO_ChannelType ChannelId)
{
	switch(PortId)
		{
			case PORTA:
					TOGGLE_BIT(*((uint32_t*)((GPIOA->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					
					break;
			case PORTB:
					TOGGLE_BIT(*((uint32_t*)((GPIOB->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTC:
					TOGGLE_BIT(*((uint32_t*)((GPIOC->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTD:
					TOGGLE_BIT(*((uint32_t*)((GPIOD->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTE:
					TOGGLE_BIT(*((uint32_t*)((GPIOE->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
			case PORTF:
					TOGGLE_BIT(*((uint32_t*)((GPIOF->GPIODATA) + (1 << (2 + ChannelId) ))),ChannelId);
					break;
		}

}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
