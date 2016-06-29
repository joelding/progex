#include "nuc100.h"

/**
 * The Timer0 default IRQ, declared in startup_NUC100Series.s.
 */
#if 0 /* ENABLE_TMR0 */
void TMR0_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER0) == 1)
    {
        /* Clear Timer0 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER0);
    }
}
#endif

#if 0 /* ENABLE_TMR1 */
void TMR1_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER1) == 1)
    {
        /* Clear Timer1 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER1);
    }
}
#endif

#if 0 /* ENABLE_TMR2 */
void TMR2_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER2) == 1)
    {
        /* Clear Timer2 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER2);
    }
}
#endif

#if 0 /* ENABLE_TMR3 */
void TMR3_IRQHandler(void)
{
    if(TIMER_GetIntFlag(TIMER3) == 1)
    {
        /* Clear Timer3 time-out interrupt flag */
        TIMER_ClearIntFlag(TIMER3);
    }
}
#endif

void sys_init(void)
{
	/* Unlock protected registers */
	SYS_UnlockReg();

	/*-------------------------------------------------------------------*/
	/* Init System Clock                                                 */
	/*-------------------------------------------------------------------*/

	/* Enable Internal RC 22.1184MHz clock */
	CLK_EnableXtalRC(CLK_PWRCON_OSC22M_EN_Msk);

	/* Waiting for Internal RC clock ready */
	CLK_WaitClockReady(CLK_CLKSTATUS_OSC22M_STB_Msk);

	/* Switch HCLK clock source to Internal RC and HCLK source divide 1 */
	CLK_SetHCLK(CLK_CLKSEL0_HCLK_S_HIRC, CLK_CLKDIV_HCLK(1));

	/* Enable external XTAL 12MHz clock */
	CLK_EnableXtalRC(CLK_PWRCON_XTL12M_EN_Msk);

	/* Waiting for external XTAL clock ready */
	CLK_WaitClockReady(CLK_CLKSTATUS_XTL12M_STB_Msk);

	/* Set core clock as PLL_CLOCK from PLL */
	CLK_SetCoreClock(PLL_CLOCK);
	
	/* Enable Timer 0~3 module clock */
#ifdef ENABLE_TMR0
	CLK_EnableModuleClock(TMR0_MODULE);    
	CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0_S_HXT, NULL);
#endif

#ifdef ENABLE_TMR1
	CLK_EnableModuleClock(TMR1_MODULE);    
	CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1_S_HCLK, NULL);
#endif

#ifdef ENABLE_TMR2
	CLK_EnableModuleClock(TMR2_MODULE);    
	CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2_S_HIRC, NULL);
#endif

#ifdef ENABLE_TMR3
	CLK_EnableModuleClock(TMR3_MODULE); 
	CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3_S_HXT, NULL);
#endif
	
#if 0
	/* Enable UART module clock */
	CLK_EnableModuleClock(UART0_MODULE);

	/* Select UART module clock source */
	CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART_S_HXT, CLK_CLKDIV_UART(1));

	/*-------------------------------------------------------------------*/
	/* Init I/O Multi-function                                           */
	/*-------------------------------------------------------------------*/

	/* Set GPB multi-function pins for UART0 RXD and TXD */
	SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
	SYS->GPB_MFP |= (SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD);
#endif

	/* Lock protected registers */
	SYS_LockReg();
}


