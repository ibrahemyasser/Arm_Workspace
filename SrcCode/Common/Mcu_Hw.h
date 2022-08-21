/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :3;
    uint32 VECPEND  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/*********************** Register map for GPIO ***********************/
typedef struct
{
	volatile const uint32_t RESERVED[255];
	volatile uint32_t 		GPIODATA;
	volatile uint32_t 		GPIODIR;
	volatile uint32_t 		GPIOIS;
	volatile uint32_t 		GPIOIBE;
	volatile uint32_t 		GPIOIEV;
	volatile uint32_t 		GPIOIM;
	volatile uint32_t 		GPIORIS;
	volatile uint32_t 		GPIOMIS;
	volatile uint32_t 		GPIOICR;
	volatile uint32_t 		GPIOAFSEL;
	volatile uint32_t 		RESERVED1[55];
	volatile uint32_t 		GPIODR2R;
	volatile uint32_t 		GPIOR4R;
	volatile uint32_t 		GPIOR8R;
	volatile uint32_t 		GPIOODR;
	volatile uint32_t 		GPIOPUR;
	volatile uint32_t 		GPIOPDR;
	volatile uint32_t 		GPIOSLR;
	volatile uint32_t 		GPIODEN;
	volatile uint32_t 		GPIOLOCK;
	volatile uint32_t 		GPIOCR;
	volatile uint32_t 		GPIOAMSEL;
	volatile uint32_t 		GPIOPCTL;
	volatile uint32_t 		GPIOADCCTL;
	volatile uint32_t 		GPIOADMACTL;
}GPIO_Type;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             	0xE000E000
#define APINT                                  	*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                	*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))

/*********************** GPIO base address ***********************/
#define GPIOA_BASE							   	0x40004000UL
#define GPIOA_BASE_AHB						   	0x40058000UL
#define GPIOB_BASE							   	0x40005000UL
#define GPIOB_BASE_AHB							0x40059000UL
#define GPIOC_BASE							  	0x40006000UL
#define GPIOC_BASE_AHB							0x4005A000UL
#define GPIOD_BASE							   	0x40007000UL
#define GPIOD_BASE_AHB						   	0x4005B000UL
#define GPIOE_BASE							   	0x40024000UL
#define GPIOE_BASE_AHB							0x4005C000UL
#define GPIOF_BASE							  	0x40025000UL
#define GPIOF_BASE_AHB							0x4005D000UL


/*********************** Peripheral Declaration ***********************/

#define GPIOA									((GPIO_Type		*)	GPIOA_BASE)
#define GPIOA_AHB								((GPIO_Type		*)	GPIOA_BASE_AHB)
#define GPIOB									((GPIO_Type		*)	GPIOB_BASE)
#define GPIOB_AHB								((GPIO_Type		*)	GPIOB_BASE_AHB)
#define GPIOC									((GPIO_Type		*)	GPIOC_BASE)
#define GPIOC_AHB								((GPIO_Type		*)	GPIOC_BASE_AHB)
#define GPIOD									((GPIO_Type		*)	GPIOD_BASE)
#define GPIOD_AHB								((GPIO_Type		*)	GPIOD_BASE_AHB)
#define GPIOE									((GPIO_Type		*)	GPIOE_BASE)
#define GPIOE_AHB								((GPIO_Type		*)	GPIOE_BASE_AHB)
#define GPIOF									((GPIO_Type		*)	GPIOF_BASE)
#define GPIOF_AHB								((GPIO_Type		*)	GPIOF_BASE_AHB)


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
