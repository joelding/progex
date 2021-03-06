/*
* main.c: in this example, keypads are scanned every 5ms
*/
#include <STC89C5xRC.H>
#include <stdio.h>
#include "pdiusbd12.h"
#include "usbcore.h"

#define FCLK 22118400UL /* Hz */
#define MAGIC 0
#define TRUE 1
#define FALSE 0
#define KEY_DEBOUNCE 25

static unsigned char timer0_hi, timer0_lo;

void timer0_init(int ms)
{
	TMOD &= 0xF0; /* set timer0 as mode 1, 16-bit timer/counter */
	TMOD |= 0x01;
	
	TH0 = timer0_hi = (65536 - FCLK/1000/12 * ms - MAGIC) / 256;
	TL0 = timer0_lo = (65536 - FCLK/1000/12 * ms - MAGIC) % 256;
	
	ET0 = 1; /* enable timer0 interrupt */
	TR0 = 1; /* start timer0 */
}

volatile unsigned char idata key_tmp; /* instant key value */
volatile unsigned char idata key_val; /* confirmed key value */
volatile unsigned char idata key_is_init;
volatile unsigned idata key_cnt;

void keypad_init(void)
{
	key_val = 0xFF;
	key_is_init = TRUE;
}

void led_init(void)
{
	P2 = 0xFF;
}

void led_set(unsigned char s)
{
	P2 = ~s;
}

void timer0_isr(void) interrupt 1
{
	TH0 = timer0_hi;
	TL0 = timer0_lo;
	
	if (!key_is_init) {
		return;
	}
	
	key_tmp = ~P1;
	
	if (key_tmp != key_val) { /* read new input */
		key_cnt = 0;
		key_val = key_tmp;
	} else {
		key_cnt++;
	}
	
	if (key_cnt < KEY_DEBOUNCE) {
		return;
	}
	
	led_set(key_val);
}

void uart_init(unsigned long bitrate)
{
	TMOD &= 0x0F; /* set timer1 as mode 2, auto-reload */
	TMOD |= 0x20;
	SCON = 0x50;
	TH1 = 256 - FCLK/(bitrate * 12 * 16);
	TL1 = 256 - FCLK/(bitrate * 12 * 16);
	PCON |= 0x80;
	ES = 1; /* enable uart interrupt */
	TR1 = 1; /* start timer1 */
	REN = 1; /* allow receive */
}

volatile unsigned char is_sending;

#define SW1 (1 << 0)
#define SW2 (1 << 1)
#define SW3 (1 << 2)
#define SW4 (1 << 3)
#define SW5 (1 << 4)
#define SW6 (1 << 5)
#define SW7 (1 << 6)
#define SW8 (1 << 7)
#define MOVE_LEFT SW1
#define MOVE_RIGHT SW2
#define MOVE_DOWN SW3
#define MOVE_UP SW4
#define ROLL_UP SW5
#define ROLL_DOWN SW6
#define CLICK_LEFT SW7
#define CLICK_RIGHT SW8

#define CLICK 0
#define AXIS_X 1
#define AXIS_Y 2
#define ROLL 3

void uart_isr(void) interrupt 4
{
	if (RI) { /* if received */
		RI = 0;
	}
	
	if (TI) { /* if transmitted a byte */
		TI = 0;
		is_sending = FALSE;
	}
}

void send_mouse_data(void)
{
	/* byte[0] bit0: left button, bit1: right button, bit2: middle button
	 * byte[1] x-axis
	 * byte[2] y-axis
	 * byte[3] roll
	 */
	unsigned char byte[4] = {0};
	extern unsigned char ep1_in_is_busy;
	
	if (key_val & MOVE_LEFT)
		byte[AXIS_X] = -1;
	
	if (key_val & MOVE_RIGHT)
		byte[AXIS_X] = 1;
	
	if (key_val & MOVE_UP)
		byte[AXIS_Y] = 1;
	
	if (key_val & MOVE_DOWN)
		byte[AXIS_Y] = -1;
	
	if (key_val & ROLL_UP)
		byte[ROLL] = 1;
	
	if (key_val & ROLL_DOWN)
		byte[ROLL] = -1;
	
	if (key_val & CLICK_LEFT)
		byte[CLICK] |= 0x1;
	
	if (key_val & CLICK_RIGHT)
		byte[CLICK] |= 0x2;
	
	D12_write_endpoint_buffer(ENDP_1_IN, 4, byte);
	ep1_in_is_busy = 1;
	printf("%02bX %02bX %02bX %02bX\n", byte[0], byte[1], byte[2], byte[3]);
}

void main(void)
{
	unsigned short id;
	unsigned char interruptsrc;
	extern unsigned char conf_status;
	extern unsigned char ep1_in_is_busy;
	
	uart_init(115200UL); /* 115200 bps, 8-N-1 */
	keypad_init();
	led_init();
	timer0_init(5);
	EA = 1; /* enable CPU interrupt */
	
	printf("\n\n\n****************\n");
	printf(      "*** USBMOUSE ***\n");
	printf(      "****************\n");
	printf("build: %s %s\n", __TIME__, __DATE__);
	
	id = D12_read_id();
	printf("D12 chip ID: 0x%04x\n", id);

	usb_set_bus(DISCONNECT);
	usb_set_bus(CONNECT);
	while (1) {
		if (0 == D12_get_int()) {
			printf("interrupt: ");
		
		/* The endpoint interrupt bits are cleared by reading the endpoint 
		last transaction status register through Read Last Transaction Status command 
		The other bits are cleared after reading the interrupt registers. */
			D12_write_cmd(ID_READ_INTERRUPT_REGISTER);
			interruptsrc = D12_read_byte();
			//usb_interrupt_print(interruptsrc);
		
			if (interruptsrc & SUSPEND_CHANGE) {
				usb_suspend();
			}
		
			if (interruptsrc & BUS_RESET) {
				usb_reset();
			}
			
			if (interruptsrc & CONTROL_OUT_ENDPOINT) {
				usb_endpoint0_out();
			}
				
			if (interruptsrc & CONTROL_IN_ENDPOINT) {
				usb_endpoint0_in();
			}
				
			if (interruptsrc & ENDPOINT_1_IN) {
				usb_endpoint1_in();
			}
				
			if (interruptsrc & ENDPOINT_1_OUT) {
				usb_endpoint1_out();
			}
				
			if (interruptsrc & MAIN_OUT_ENDPOINT) {
				usb_endpoint2_out();
			}
				
			if (interruptsrc & MAIN_IN_ENDPOINT) {
				usb_endpoint2_in();
			}
		}
		
		if (conf_status) {
			if (!ep1_in_is_busy) {
				send_mouse_data();
			}
		}
	}
}