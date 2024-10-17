#define <stdint.h>
#define PERIPH_BASE        (0x40000000UL)
#define AHB1PERI_OFFSET    (0x00020000UL)
#define AHB1PERI_BASE      (PERIPH_BASE + AHB1PERI_OFFSET)
#define GPIOD_OFFSET       (0x00020C00UL)

#define GPIOD_BASE         (PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET         (0x3800UL)
#define RCC_BASE           (AHB1PERI_BASE+RCC_OFFSET)



#define GPIODEN            (1u<<3)

#define PIN12              (1U<<12)
#define LED_PIN            PIN12

#define __IO volatile
typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;

}RCC_typeDef;
typedef struct
{
	volatile uint32_t MODDER;
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;

}GPIO_TypeDef;
#define RCC ((RCC_TypeDef*)RCC_BASE)
#define GPIOD ((GPIO_TypeDef*)GPIOD_BASE)

// (1U<<24)
// &=~(1U<<25) &=~(1U<<25)
int main (void)
{
     //RCC_AHB1EN_R |= GPIODEN;
     RCC->AHB1ENR |= GPIODEN;

     //GPIOD_MODE_R |=(1U<<24);
     GPIOD->MODDER |=(1U<<24);

     GPIOD_MODE_R  &=~(1U<<25);
     GPIOD->MODDER &=~(1U<<25);



   while(1)
   {
	   //GPIOD_OD_R |=LED_PIN;
	   GPIOD_OD_R ^=LED_PIN;
	   for (int i=0; i<1000000; i++);


   }
}
