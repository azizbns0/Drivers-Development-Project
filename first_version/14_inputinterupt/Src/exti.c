
#include "exti.h"

#define GPIOAEN (1U<<0)
#define SYSCFGEN (1U<14)
void pa0_exti_init(void)
{
	/*disable global interrupt*/
	__disable_irq();
	/*enable clk access for gpioa*/
	RCC-> AHB1ENR|=GPIOAEN;
	/* enable clk access to syscfg*/
	RCC->APB2ENR |=SYSCFGEN;
	/*set pa0 as an input */
	GPIOA->MODER &=~(1U<<0);
	GPIOA->MODER &=~(1U<<1);

	/*select porta for exti0*/
	SYSCFG->EXTICR[0] &=~(1U<<0);
	SYSCFG->EXTICR[0] &=~(1U<<1);
	SYSCFG->EXTICR[0] &=~(1U<<2);
	SYSCFG->EXTICR[0] &=~(1U<<3);


	/* unmask exti0*/
	EXTI->IMR |=(1U<<0);
	/*select falling edge trigger00*/
	EXTI->FTSR |=(1U<<0);
	/*enable EXTIline in NVIC*/
	NVIC_EnableIRQ(EXTI0_IRQn );
	/*ENABLE GLOBAL INTERRUPT*/
	__enable_irq();
}


