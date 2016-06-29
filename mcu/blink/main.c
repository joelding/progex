/**
 * Project 2: make LED blink every 1 second
 */
#include "nuc100.h"

static int i;

#ifdef ENABLE_TMR0
void TMR0_IRQHandler(void)
{
	if(TIMER_GetIntFlag(TIMER0) == 1)
	{
		/* Clear Timer0 time-out interrupt flag */
		TIMER_ClearIntFlag(TIMER0);
	    
		if (i) 
		{
			PA10 = 1;
			i = 0;
		}
		else
		{
			PA10 = 0;
			i = 1;
		}
	}
}
#endif

int main(void)
{
	sys_init();
	
	/* Configure PA.10 as Output mode and PE.1 as Input mode */
	GPIO_SetMode(PA, BIT10, GPIO_PMD_OUTPUT);
	
	/* Open Timer0 in periodic mode, enable interrupt and 1 interrupt tick per second */
	TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 1);
	TIMER_EnableInt(TIMER0);
	NVIC_EnableIRQ(TMR0_IRQn);
	TIMER_Start(TIMER0);
	
	PA10 = 1;
	while (1);
}
