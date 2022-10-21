
#include "Dio_Cfg.h"
#include "Port_Cfg.h"
#include "Mcu_Hw.h"
#include "stdio.h"
#include "Bit_Math.h"
#include "cpu_driver.h"

#include "IntCtrl.h"
#include "Led.h"
#include "Interrupts.h"
#include "Systick.h"

static volatile uint32_t 	state = 1;
static uint32_t 					ON_TIME = 0;
static uint32_t 					OFF_TIME = 0;
static uint32_t 					On_Off = 0;
static volatile uint8_t 	On_Off_Ctr = 1;


int main()
{
	cpuDriver_EnableGlobalInterrupt();
	Led_Init();
	Systick_Init();
	Interrupt_Init();
	while(On_Off_Ctr);
	Systick_StartTimer(ON_TIME);
	while(1)
	{
		
	}
	
}

void SysTick_Handler(void)
{
	if(state)
	{
		Led_Off();
		Systick_ChangeTiming(OFF_TIME);
		state = 0;
	}
	else
	{
		Led_On();
		Systick_ChangeTiming(ON_TIME);		
		state = 1;
	}
		
}
void GPIOA_Handler(void)
{
	if(On_Off == 0)
	{
		On_Off++;
		
		if(On_Off > 2)
			On_Off =0;
	}
	
}
void GPIOC_Handler(void)
{
	
	if(On_Off == 1)
	{
		ON_TIME++;

	}
	if(ON_TIME > 0 && OFF_TIME > 0)
	{
		On_Off_Ctr = 0;
	}

}
void GPIOD_Handler(void)
{
	if(On_Off == 2)
	{
		OFF_TIME++;
	}
	if(ON_TIME > 0 && OFF_TIME > 0)
	{
		On_Off_Ctr = 0;
	}
}


