/*
 * Project "led" lights up the LED on NuTiny-EVB-NUC140
 *
 * Exercise 1
 */
#include "nuc100.h"

int main(void)
{
	sys_init();
	
	/* Configure PA.10 as Output mode and PE.1 as Input mode */
	GPIO_SetMode(PA, BIT10, GPIO_PMD_OUTPUT);
	
	PA10 = 0;
	
	while (1);
}
