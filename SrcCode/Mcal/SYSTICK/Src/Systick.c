/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "Systick.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"
#include "IntCtrl_Types.h"
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
void Systick_Init(void)
{
	SYSTICK->STCTRL = 0x02;
}
void Systick_StartTimer(uint32_t time)
{
	SYSTICK->STRELOAD = (time * SYSTICK_CLOCK) - 1;
	SYSTICK->STCURRENT = 0;
	SYSTICK->STCTRL = 0x03;
}
void Systick_StopTimer(void)
{
	SYSTICK->STCTRL = 0x02;
}
void Systick_ChangeTiming(uint32_t time)
{
	SYSTICK->STRELOAD = (time * SYSTICK_CLOCK) - 1;
	SYSTICK->STCURRENT = 0;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
