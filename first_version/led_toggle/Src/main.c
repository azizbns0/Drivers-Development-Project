#define PERIPH_BASE        (0x40000000UL)



#define AHB1PERI_OFFSET    (0x00020000UL)
#define AHB1PERI_BASE      (PERIPH_BASE + AHB1PERI_OFFSET)
#define GPIOD_OFFSET       (0x00020C00UL)

#define GPIOD_BASE         (PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET         (0x3800UL)
#define RCC_BASE           (AHB1PERI_BASE+RCC_OFFSET)


#define AHB1_ENR_OFFSET    (0x30UL)
#define RCC_AHB1EN_R       (*(volatile unsigned int *)( AHB1_ENR_OFFSET+RCC_BASE ))

#define MODE_R_OFFSET      (0x00UL)
#define GPIOD_MODE_R       (*(volatile unsigned int *)(MODE_R_OFFSET+ GPIOD_BASE))

#define OD_R_OFFSET         (0x14UL)
#define GPIOD_OD_R          (*(volatile unsigned int *) (OD_R_OFFSET +GPIOD_BASE ))


#define GPIODEN            (1u<<3)

#define PIN12              (1U<<12)
#define LED_PIN            PIN12


// (1U<<24)
// &=~(1U<<25) &=~(1U<<25)
int main (void)
{
     RCC_AHB1EN_R |= GPIODEN;

     GPIOD_MODE_R |=(1U<<24);
     GPIOD_MODE_R  &=~(1U<<25);


   while(1)
   {
	   //GPIOD_OD_R |=LED_PIN;
	   GPIOD_OD_R ^=LED_PIN;
	   for (int i=0; i<1000000; i++);


   }
}
