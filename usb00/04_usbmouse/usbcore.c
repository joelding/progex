#include <stdio.h>
#include "usbcore.h"

void delayms(unsigned short ms)
{
	unsigned short i, j;
	
	for (i = 0; i < ms; i++) {
		for (j = 0; j < 227; j++);
	}
}

#define NO_LAZYCLOCK (1 << 1)
#define CLOCK_ALWAYS_RUNNING (1 << 2)
#define INTERRUPT_ALL_ERRORS (1 << 3)
#define CONN_UPSTREAM_PULLUP (1 << 4)

#define SET_TO_ONE (1 << 6)
#define CLK_DIV_FACTOR (7) /* 48MHz/(7+1) = 6MHz */

/*
* s: 1, to connect; 0, to disconnect
*/
void usb_set_bus(unsigned char s)
{
	D12_write_cmd(ID_SET_MODE);
	
	if (s) {
		
		D12_write_byte(CLOCK_ALWAYS_RUNNING | NO_LAZYCLOCK);
	} else {

		D12_write_byte(CONN_UPSTREAM_PULLUP | CLOCK_ALWAYS_RUNNING | NO_LAZYCLOCK);		
	}
	
	D12_write_byte(SET_TO_ONE | CLK_DIV_FACTOR);
	
	if (!s) {		
		printf("bus disconnects\n");
		delayms(1000);
	} else {
		printf("bus connects\n");
	}
}

#define SUSPEND_CHANGE (1 << 7)
#define BUS_RESET (1 << 6)
#define MAIN_IN_ENDPOINT (1 << 5)
#define MAIN_OUT_ENDPOINT (1 << 4)
#define ENDPOINT_1_IN (1 << 3)
#define ENDPOINT_1_OUT (1 << 2)
#define CONTROL_IN_ENDPOINT (1 << 1)
#define CONTROL_OUT_ENDPOINT (1 << 0)

void usb_interrupt_print(unsigned char c)
{
	if (c & (SUSPEND_CHANGE))
		printf("bus suspend change\n");
	if (c & BUS_RESET)
		printf("bus reset\n");
	if (c & MAIN_IN_ENDPOINT)
		printf("main in endpoint\n");
	if (c & MAIN_OUT_ENDPOINT)
		printf("main out endpoint\n");
	if (c & ENDPOINT_1_IN)
		printf("endpoint 1 in\n");
	if (c & ENDPOINT_1_OUT)
		printf("endpoint 1 out\n");
	if (c & CONTROL_IN_ENDPOINT)
		printf("control in endpoint\n");
	if (c & CONTROL_OUT_ENDPOINT)
		printf("control out endpoint\n");
}