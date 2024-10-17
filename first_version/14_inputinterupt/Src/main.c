
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "TIM.h"
#include "exti.h"

#define GPIODEN     (1U<<0)
#define PIN12       (1U<<12)
#define LED_PIN      PIN12

static void exti_callback(void);
int main (void)
{
	RCC->AHB1ENR |= GPIODEN;
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &=~(1U<<25);
	pa0_exti_init();
	while(1)
	{

	}


}
static void exti_callback(void)
{
	printf("btn pressed...\n\r");
}
void 	EXTI0_IRQHandler(void){
	if((EXTI->PR &LINE0)!=0)
	{
		EXTI->PR|=LINE0;
		exti_callback();
	}

}
