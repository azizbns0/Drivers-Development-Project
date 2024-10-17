
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "adc.h"
#include "systick.h"
#include "TIM.h"

#define SR_UIF (1<<0)

int main (void)
{
	TIM2_output_compare();


}
