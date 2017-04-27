/*
* main.c: in this example, keypads are scanned every 5ms
*/
#include <STC89C5xRC.H>

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

void main(void)
{
	keypad_init();
	led_init();
	timer0_init(5);
	EA = 1; /* enable CPU interrupt */
	
	while (1);
}