/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
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
#include "Port_Cfg.h"
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
void Port_Init( const Port_ConfigType* ConfigPtr)
{
		
			SET_BIT_PERIPH_BAND(SYSCTRL->GPIOHBCTL,ConfigPtr->PortType);
	
			ConfigPtr->GPIOx->GPIOLOCK = GPIO_LOCKKEY;
			SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOCR,ConfigPtr->PortType);
			ConfigPtr->GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
	
			if(ConfigPtr->PinMode == DIGITAL_PIN)
			{
				SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODEN,ConfigPtr->ChannelId);
				
			}else if(ConfigPtr->PinMode && !ANALOG_ENABLE )
			{
				SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODEN,ConfigPtr->ChannelId);
				SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOAFSEL ,ConfigPtr->ChannelId);// enable the pin as an alternate function
				SET_BIT_PERIPH_BAND_VAL(ConfigPtr->GPIOx->GPIOPCTL ,(uint32_t)ConfigPtr->PinMode << (4 * (ConfigPtr->ChannelId)));//assign the pin to the specified alternate mode
			} 
			#if (ANALOG_ENABLE)
			{
				CLEAR_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODEN,ConfigPtr->ChannelId);
				SET_BIT_PERIPH_BAND_VAL(ConfigPtr->GPIOx->GPIOAMSEL,(0 * ConfigPtr->ChannelId),(uint32_t)ConfigPtr->PinMode);
			}
			#endif
			
			
			
			if(ConfigPtr->PortPinDirection == OUTPUT)
			{
					SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODIR , ConfigPtr->ChannelId);
			}else
			{
					CLEAR_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODIR, ConfigPtr->ChannelId);
			}
			
			
			if(ConfigPtr->PortPinLevelValue == LOW)
			{
					CLEAR_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODATA ,ConfigPtr->ChannelId);
			}else if(ConfigPtr->PortPinLevelValue == HIGH)
			{
					SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODATA ,ConfigPtr->ChannelId);
			}
			
			
			
			switch(ConfigPtr->PinOutputCurrent)
			{
				case R2R:
						SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIODR2R,ConfigPtr->ChannelId);
						break;
				case R4R:
						SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOR4R,ConfigPtr->ChannelId);
						break;
				case R8R:
						SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOR8R,ConfigPtr->ChannelId);
						break;
			}
			
			
			switch(ConfigPtr->PortPinInternalAttach)
			{
				case PULL_UP:
						SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOPUR,ConfigPtr->ChannelId);
						break;
				case PULL_DOWN:
						SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOPDR,ConfigPtr->ChannelId);
						break;
				case OPEN_DRAIN:
						SET_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOODR,ConfigPtr->ChannelId);
						break;
			}	
		

				
			ConfigPtr->GPIOx->GPIOLOCK = GPIO_LOCKKEY;
			CLEAR_BIT_PERIPH_BAND(ConfigPtr->GPIOx->GPIOCR , ConfigPtr->PortType );
			ConfigPtr->GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
	
		/*switch(ConfigPtr->PortType)
		{
			case PORTA:
					GPIOx = GPIOA;
					SYSCTRL->GPIOHBCTL |= ( 1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_LOCKKEY;
					GPIOx->GPIOCR |= (1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
					GPIOx->GPIODEN |= ( 1 << ConfigPtr->ChannelId);
					GPIOx->GPIOAFSEL |= ( 1 << (ConfigPtr->ChannelId )); // enable the pin as an alternate function
					GPIOx->GPIOPCTL |= ( (uint32_t)(ConfigPtr->PinMode.PORTA_alf ) << (4 * (ConfigPtr->ChannelId)) ); // assign the pin to the specified alternate mode
					if(ConfigPtr->PortPinDirection == OUTPUT)
					{
							SET_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}
					if(ConfigPtr->PortPinLevelValue == HIGH)
					{
							SET_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}
					switch(ConfigPtr->PinOutputCurrent)
					{
						case R2R:
								SET_BIT(GPIOx->GPIODR2R,ConfigPtr->ChannelId);
								break;
						case R4R:
								SET_BIT(GPIOx->GPIOR4R,ConfigPtr->ChannelId);
								break;
						case R8R:
								SET_BIT(GPIOx->GPIOR8R,ConfigPtr->ChannelId);
								break;
					}
					switch(ConfigPtr->PortPinInternalAttach)
					{
						case PULL_UP:
								SET_BIT(GPIOx->GPIOPUR,ConfigPtr->ChannelId);
								break;
						case PULL_DOWN:
								SET_BIT(GPIOx->GPIOPDR,ConfigPtr->ChannelId);
								break;
						case OPEN_DRAIN:
								SET_BIT(GPIOx->GPIOODR,ConfigPtr->ChannelId);
								break;
					}
					break;
			case PORTB:
					GPIOx = GPIOB;
					SYSCTRL->GPIOHBCTL |= ( 1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_LOCKKEY;
					GPIOx->GPIOCR |= (1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
					GPIOx->GPIODEN |= ( 1 << ConfigPtr->ChannelId);
					GPIOx->GPIOAFSEL |= ( 1 << (ConfigPtr->ChannelId )); // enable the pin as an alternate function
					GPIOx->GPIOPCTL |= ( (uint32_t)(ConfigPtr->PinMode.PORTB_alf ) << (4 * (ConfigPtr->ChannelId)) ); // assign the pin to the specified alternate mode
					if(ConfigPtr->PortPinDirection == OUTPUT)
					{
							SET_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}
					if(ConfigPtr->PortPinLevelValue == HIGH)
					{
							SET_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}
					switch(ConfigPtr->PinOutputCurrent)
					{
						case R2R:
								SET_BIT(GPIOx->GPIODR2R,ConfigPtr->ChannelId);
								break;
						case R4R:
								SET_BIT(GPIOx->GPIOR4R,ConfigPtr->ChannelId);
								break;
						case R8R:
								SET_BIT(GPIOx->GPIOR8R,ConfigPtr->ChannelId);
								break;
					}
					switch(ConfigPtr->PortPinInternalAttach)
					{
						case PULL_UP:
								SET_BIT(GPIOx->GPIOPUR,ConfigPtr->ChannelId);
								break;
						case PULL_DOWN:
								SET_BIT(GPIOx->GPIOPDR,ConfigPtr->ChannelId);
								break;
						case OPEN_DRAIN:
								SET_BIT(GPIOx->GPIOODR,ConfigPtr->ChannelId);
								break;
					}
					break;
			case PORTC:
					GPIOx = GPIOC;
					SYSCTRL->GPIOHBCTL |= ( 1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_LOCKKEY;
					GPIOx->GPIOCR |= (1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
					GPIOx->GPIODEN |= ( 1 << ConfigPtr->ChannelId);
					GPIOx->GPIOAFSEL |= ( 1 << (ConfigPtr->ChannelId )); // enable the pin as an alternate function
					GPIOx->GPIOPCTL |= ( (uint32_t)(ConfigPtr->PinMode.PORTC_alf ) << (4 * (ConfigPtr->ChannelId)) ); // assign the pin to the specified alternate mode
					if(ConfigPtr->PortPinDirection == OUTPUT)
					{
							SET_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}
					if(ConfigPtr->PortPinLevelValue == HIGH)
					{
							SET_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}
					switch(ConfigPtr->PinOutputCurrent)
					{
						case R2R:
								SET_BIT(GPIOx->GPIODR2R,ConfigPtr->ChannelId);
								break;
						case R4R:
								SET_BIT(GPIOx->GPIOR4R,ConfigPtr->ChannelId);
								break;
						case R8R:
								SET_BIT(GPIOx->GPIOR8R,ConfigPtr->ChannelId);
								break;
					}
					switch(ConfigPtr->PortPinInternalAttach)
					{
						case PULL_UP:
								SET_BIT(GPIOx->GPIOPUR,ConfigPtr->ChannelId);
								break;
						case PULL_DOWN:
								SET_BIT(GPIOx->GPIOPDR,ConfigPtr->ChannelId);
								break;
						case OPEN_DRAIN:
								SET_BIT(GPIOx->GPIOODR,ConfigPtr->ChannelId);
								break;
					}
					break;
			case PORTD:
					GPIOx = GPIOD;
					SYSCTRL->GPIOHBCTL |= ( 1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_LOCKKEY;
					GPIOx->GPIOCR |= (1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
					GPIOx->GPIODEN |= ( 1 << ConfigPtr->ChannelId);
					GPIOx->GPIOAFSEL |= ( 1 << (ConfigPtr->ChannelId )); // enable the pin as an alternate function
					GPIOx->GPIOPCTL |= ( (uint32_t)(ConfigPtr->PinMode.PORTD_alf ) << (4 * (ConfigPtr->ChannelId)) ); // assign the pin to the specified alternate mode
					if(ConfigPtr->PortPinDirection == OUTPUT)
					{
							SET_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}
					if(ConfigPtr->PortPinLevelValue == HIGH)
					{
							SET_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}
					switch(ConfigPtr->PinOutputCurrent)
					{
						case R2R:
								SET_BIT(GPIOx->GPIODR2R,ConfigPtr->ChannelId);
								break;
						case R4R:
								SET_BIT(GPIOx->GPIOR4R,ConfigPtr->ChannelId);
								break;
						case R8R:
								SET_BIT(GPIOx->GPIOR8R,ConfigPtr->ChannelId);
								break;
					}
					switch(ConfigPtr->PortPinInternalAttach)
					{
						case PULL_UP:
								SET_BIT(GPIOx->GPIOPUR,ConfigPtr->ChannelId);
								break;
						case PULL_DOWN:
								SET_BIT(GPIOx->GPIOPDR,ConfigPtr->ChannelId);
								break;
						case OPEN_DRAIN:
								SET_BIT(GPIOx->GPIOODR,ConfigPtr->ChannelId);
								break;
					}
					break;
			case PORTE:
					GPIOx = GPIOE;
					SYSCTRL->GPIOHBCTL |= ( 1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_LOCKKEY;
					GPIOx->GPIOCR |= (1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
					GPIOx->GPIODEN |= ( 1 << ConfigPtr->ChannelId);
					GPIOx->GPIOAFSEL |= ( 1 << (ConfigPtr->ChannelId )); // enable the pin as an alternate function
					GPIOx->GPIOPCTL |= ( (uint32_t)(ConfigPtr->PinMode.PORTE_alf ) << (4 * (ConfigPtr->ChannelId)) ); // assign the pin to the specified alternate mode
					if(ConfigPtr->PortPinDirection == OUTPUT)
					{
							SET_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}
					if(ConfigPtr->PortPinLevelValue == HIGH)
					{
							SET_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}
					switch(ConfigPtr->PinOutputCurrent)
					{
						case R2R:
								SET_BIT(GPIOx->GPIODR2R,ConfigPtr->ChannelId);
								break;
						case R4R:
								SET_BIT(GPIOx->GPIOR4R,ConfigPtr->ChannelId);
								break;
						case R8R:
								SET_BIT(GPIOx->GPIOR8R,ConfigPtr->ChannelId);
								break;
					}
					switch(ConfigPtr->PortPinInternalAttach)
					{
						case PULL_UP:
								SET_BIT(GPIOx->GPIOPUR,ConfigPtr->ChannelId);
								break;
						case PULL_DOWN:
								SET_BIT(GPIOx->GPIOPDR,ConfigPtr->ChannelId);
								break;
						case OPEN_DRAIN:
								SET_BIT(GPIOx->GPIOODR,ConfigPtr->ChannelId);
								break;
					}
					break;
			case PORTF:
				GPIOx = GPIOF;
					SYSCTRL->GPIOHBCTL |= ( 1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_LOCKKEY;
					GPIOx->GPIOCR |= (1 << ConfigPtr->PortType );
					GPIOx->GPIOLOCK = GPIO_UNLOCKKEY;
					GPIOx->GPIODEN |= ( 1 << ConfigPtr->ChannelId);
					GPIOx->GPIOAFSEL |= ( 1 << (ConfigPtr->ChannelId )); // enable the pin as an alternate function
					GPIOx->GPIOPCTL |= ( (uint32_t)(ConfigPtr->PinMode.PORTF_alf ) << (4 * (ConfigPtr->ChannelId)) ); // assign the pin to the specified alternate mode
					if(ConfigPtr->PortPinDirection == OUTPUT)
					{
							SET_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(GPIOx->GPIODIR, ConfigPtr->ChannelId);
					}
					if(ConfigPtr->PortPinLevelValue == HIGH)
					{
							SET_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}else
					{
							CLEAR_BIT(*((uint32_t*)((GPIOx->GPIODATA) + (1 << (2 + ConfigPtr->ChannelId) ))),ConfigPtr->ChannelId);
					}
					switch(ConfigPtr->PinOutputCurrent)
					{
						case R2R:
								SET_BIT(GPIOx->GPIODR2R,ConfigPtr->ChannelId);
								break;
						case R4R:
								SET_BIT(GPIOx->GPIOR4R,ConfigPtr->ChannelId);
								break;
						case R8R:
								SET_BIT(GPIOx->GPIOR8R,ConfigPtr->ChannelId);
								break;
					}
					switch(ConfigPtr->PortPinInternalAttach)
					{
						case PULL_UP:
								SET_BIT(GPIOx->GPIOPUR,ConfigPtr->ChannelId);
								break;
						case PULL_DOWN:
								SET_BIT(GPIOx->GPIOPDR,ConfigPtr->ChannelId);
								break;
						case OPEN_DRAIN:
								SET_BIT(GPIOx->GPIOODR,ConfigPtr->ChannelId);
								break;
					}
					break;
		}*/
		


}

/**********************************************************************************************************************
 *  END OF FILE: Portss.c
 *********************************************************************************************************************/
