
#include "Dio_Cfg.h"
#include "Mcu_Hw.h"
#include "stdio.h"

int main()
{
	SYSCTRL_Type *pSYS = SYSCTRL;
	GPIO_Type *pGPIO = GPIOA;
	pSYS->PLLSTAT = 1;
	pSYS->RCGCGPIO |= 1 << 0;
	pGPIO->GPIOLOCK = GPIO_LOCKKEY;
	pGPIO->GPIOCR = 0x01;
	pGPIO->GPIOLOCK = GPIO_UNLOCKKEY;
	pGPIO->GPIODEN = 0x01;
	pGPIO->GPIODIR = 0x01;
	
	while(1)
	{
		pGPIO->GPIODATA = 0x01;
	}
	
}

