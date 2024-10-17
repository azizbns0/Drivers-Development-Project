#include <stdint.h>
#include "stm32f4xx.h"

#define GPIODEN     (1U<<3)
#define GPIOAEN     (1U<<0)
#define UART2EN     (1U<<17)
#define CR1_TE      (1U<<3)
#define CR1_UE      (1U<<13)
#define SR_TXE      (1U<<7)


#define SYS_FREQ    16000000
#define APB1_CLK    SYS_FREQ

#define UART_BAUDRATE   115200

static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk,uint32_t baudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t baudRate);

void uart2_tx_init(void);
void uart2_write(int ch);
int main (void)
{
	uart2_tx_init();
	while(1)
	{
		uart2_write('y');

	}
}
void uart2_tx_init(void)
{
	//configure uart gpio pin//

	  //enable clock access to gpioa
	RCC->AHB1ENR |=GPIOAEN ;
	  //set pa2 mode to alternate function mode
	GPIOA->MODER  &=~(1U<<4);
	GPIOA->MODER  |=(1U<<5);
	 //set pa2 alternate function type to UART_TX(af07)
	GPIOA->AFR[0] |=(1U<<8);
	GPIOA->AFR[0] |=(1U<<9);
	GPIOA->AFR[0] |=(1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);


	//    configure uart module//
	 //enable clOck access to uart2
	RCC->APB1ENR |=UART2EN;

	 // configure baudrate
	uart_set_baudrate(USART2,APB1_CLK,UART_BAUDRATE );

	 //configure the transfert direction
	USART2->CR1= CR1_TE;

	 // enable UART module
	USART2->CR1 |= CR1_UE;



}
void uart2_write(int ch)
{
	while (!(USART2->SR & SR_TXE)){}
	USART2->DR =(ch& 0xFF);
}
static void uart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriphClk,uint32_t baudRate)
{
	USARTx->BRR=compute_uart_bd(PeriphClk,baudRate);
}
static uint16_t compute_uart_bd(uint32_t PeriphClk,uint32_t baudRate)
{
	return ((PeriphClk+ (baudRate)/2U)/ baudRate);
}
