
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "TIM.h"

#define GPIODEN     (1U<<0)
#define PIN12       (1U<<12)
#define LED_PIN      PIN12




int main (void)
{

	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &=~(1U<<25);
	TIM2_1hz_init();
	while(1)
	{

        while(!(TIM2->SR & SR_UIF)){}
        TIM2->SR &=~SR_UIF;
		printf("a second passed :  \n\r");
		GPIOD->ODR ^=LED_PIN;

	}
}
