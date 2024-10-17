#include "stm32f4xx.h"






#define GPIODEN     (1U<<3)
#define GPIOAEN     (1U<<0)


#define PIN12       (1U<<12)
#define PIN0        (1U<0)
#define LED_PIN      PIN12
#define BTN_PIN      PIN0



int main (void)
{
	RCC->AHB1ENR |= GPIODEN;
	RCC->AHB1ENR |= GPIOAEN;
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &=~(1U<<25);

    //SET PA0 AS INPUT PIN
	GPIOA->MODER &=~(1U<<0);
	GPIOA->MODER &=~(1U<<1);

	while(1)
	{
		//check if btn is pressed
		if(GPIOA->IDR & BTN_PIN )
		{
		GPIOD->BSRR=LED_PIN;

		}
		else {
		GPIOD->BSRR=(1U<<28);
		}

	}
}
