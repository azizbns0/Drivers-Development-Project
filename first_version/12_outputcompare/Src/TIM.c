#include "stm32f4xx.h"

#define TIM2EN  (1U<<0)
#define CR1_CEN (1U<<0)
#define CCER_CC1E  (1U<<0)


#define AFR5_TIM  (1U<<20)
void TIM2_1hz_init(void)
{
	/*enable clock acces to tim2*/
	RCC->APB1ENR |=TIM2EN;
	/*set prescaler value */
	TIM2->PSC =1600-1;

	/*set auto reload value */
	TIM2->ARR =10000-1;
	/* clear counter*/
	TIM2->CNT =0;
	/*enable  timer */
	TIM2->CR1=CR1_CEN;

}
void TIM2_output_compare(void)
{
	/*enable clk acces to gpioa */
	RCC->AHB1ENR|=(1u<<0);
	/* set pa5 to alternate function*/
	GPIOA->MODER&=~(1U<<10);
	GPIOA->MODER|=(1U<<11);
	/*set alternate function type to tim2 ch1*/
	GPIOA->AFR[1]|= AFR5_TIM;





	/*enable clock acces to tim2*/
	RCC->APB1ENR |=TIM2EN;
	/*set prescaler value */
	TIM2->PSC =1600-1;

	/*set auto reload value */
	TIM2->ARR =10000-1;
	/*set output compare toggle mode*/
	TIM2->CCMR1=(1U<<4)|(1U<<5);
	/* enable tim2 ch1 in compare mode*/
	TIM2->CCER |=CCER_CC1E;


	/* clear counter*/
	TIM2->CNT =0;
	/*enable  timer */
	TIM2->CR1=CR1_CEN;

}



