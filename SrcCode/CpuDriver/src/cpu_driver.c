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
#include "cpu_driver.h"

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

void cpuDriver_EnableGlobalInterrupt(void)
{
	__asm("CPSIE i;");
}
void cpuDriver_DisableGlobalInterrupt(void)
{
	__asm("CPSID i;");
}

void cpuDriver_EnablePriviledgeMode(void)
{
	__asm("SVC #0;");
}

void cpuDriver_DisablePriviledgeMode(void)
{
	__asm(
					"MOVS 	R0, 		#4;"
					"MSR 		CONTROL, R0;"
	);
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
