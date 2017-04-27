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

unsigned char interruptsrc;

#if 0
#define TRIGGER_FALLING_EDGE 1
#define TRIGGER_LOW_LEVEL 0
void int0_init(void)
{
	IT0 = TRIGGER_FALLING_EDGE;
	EX0 = 0;
}

void int0_isr(void) interrupt 0
{
	D12_write_cmd(ID_READ_INT_REG);
	interruptsrc = D12_read_byte();
}
#endif

void main(void)
{
	unsigned short id;
#if 0
	unsigned char interruptsrc;
#endif
	
	uart_init(115200UL); /* 115200 bps, 8-N-1 */
	keypad_init();
	led_init();
	timer0_init(5);
//	int0_init();

	
	printf("\n\n*** USBMOUSE ***\n");
	printf("build: %s %s\n", __TIME__, __DATE__);
	
	id = D12_read_id();
	printf("D12 chip ID: 0x%04x\n", id);
	
	EA = 1; /* enable CPU interrupt */
	
	usb_set_bus(DISCONNECT);
	usb_set_bus(CONNECT);
#if 0
	while (1) {
		if (0 == D12_get_int()) {
			D12_write_cmd(ID_READ_INT_REG);
			interruptsrc = D12_read_byte();
			usb_interrupt_print(interruptsrc);
		}
	}
#else
	while(1) {
		if (interruptsrc) {
			usb_interrupt_print(interruptsrc);
			interruptsrc = 0;
		}
	}
#endif
}