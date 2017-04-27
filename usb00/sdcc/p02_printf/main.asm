;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
; This file was generated Thu Mar  9 19:33:20 2017
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _timer0_isr
	.globl _timer0_init
	.globl _uart_isr
	.globl _uart_init
	.globl _printf
	.globl _P4_6
	.globl _P4_5
	.globl _P4_4
	.globl _P4_3
	.globl _P4_2
	.globl _P4_1
	.globl _P4_0
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _FL
	.globl _P
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ET2
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _T2EX
	.globl _T2
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _P4
	.globl _ISP_CONTR
	.globl _ISP_TRIG
	.globl _ISP_CMD
	.globl _ISP_ADDRL
	.globl _ISP_ADDRH
	.globl _ISP_DATA
	.globl _WDT_CONTR
	.globl _XICON
	.globl _SADEN
	.globl _IPH
	.globl _SADDR
	.globl _AUXR1
	.globl _AUXR
	.globl _B
	.globl _A
	.globl _ACC
	.globl _PSW
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2MOD
	.globl _T2CON
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _toggle
	.globl _val
	.globl _t0_initval
	.globl _putchar
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCAP2L	=	0x00ca
_RCAP2H	=	0x00cb
_TL2	=	0x00cc
_TH2	=	0x00cd
_PSW	=	0x00d0
_ACC	=	0x00e0
_A	=	0x00e0
_B	=	0x00f0
_AUXR	=	0x008e
_AUXR1	=	0x00a2
_SADDR	=	0x00a9
_IPH	=	0x00b7
_SADEN	=	0x00b9
_XICON	=	0x00c0
_WDT_CONTR	=	0x00e1
_ISP_DATA	=	0x00e2
_ISP_ADDRH	=	0x00e3
_ISP_ADDRL	=	0x00e4
_ISP_CMD	=	0x00e5
_ISP_TRIG	=	0x00e6
_ISP_CONTR	=	0x00e7
_P4	=	0x00e8
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_T2	=	0x0090
_T2EX	=	0x0091
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_ET2	=	0x00ad
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_PT2	=	0x00bd
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
_P	=	0x00d0
_FL	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_P4_0	=	0x00e8
_P4_1	=	0x00e9
_P4_2	=	0x00ea
_P4_3	=	0x00eb
_P4_4	=	0x00ec
_P4_5	=	0x00ed
_P4_6	=	0x00ee
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
	.area REG_BANK_1	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_is_tx_busy:
	.ds 1
_t0_initval::
	.ds 2
_timer0_init_sloc0_1_0:
	.ds 4
_val::
	.ds 1
_toggle::
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	ljmp	_timer0_isr
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_uart_isr
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	main.c:38: static unsigned char is_tx_busy = 0;
	mov	_is_tx_busy,#0x00
;	main.c:95: volatile unsigned char val = 0x55;
	mov	_val,#0x55
;	main.c:97: volatile unsigned toggle = 0;
	clr	a
	mov	_toggle,a
	mov	(_toggle + 1),a
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'uart_init'
;------------------------------------------------------------
;baudrate                  Allocated to registers r4 r5 r6 r7 
;------------------------------------------------------------
;	main.c:17: void uart_init(unsigned long baudrate)
;	-----------------------------------------
;	 function uart_init
;	-----------------------------------------
_uart_init:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
;	main.c:26: SCON = 0x50;
	mov	_SCON,#0x50
;	main.c:29: TMOD &= 0x0F; /* set timer 1 as mode 2, autoload */
	anl	_TMOD,#0x0F
;	main.c:30: TMOD |= 0x20;
	orl	_TMOD,#0x20
;	main.c:31: TH1 = TL1 = 256 - (FCLK / (12 * 16 * baudrate));
	mov	__mullong_PARM_2,r4
	mov	(__mullong_PARM_2 + 1),r5
	mov	(__mullong_PARM_2 + 2),r6
	mov	(__mullong_PARM_2 + 3),r7
	mov	dptr,#(0xC0&0x00ff)
	clr	a
	mov	b,a
	lcall	__mullong
	mov	__divulong_PARM_2,dpl
	mov	(__divulong_PARM_2 + 1),dph
	mov	(__divulong_PARM_2 + 2),b
	mov	(__divulong_PARM_2 + 3),a
	mov	dptr,#0x8000
	mov	b,#0x51
	mov	a,#0x01
	lcall	__divulong
	mov	r4,dpl
	clr	c
	clr	a
	subb	a,r4
	mov	r4,a
	mov	_TL1,r4
	mov	_TH1,r4
;	main.c:32: PCON |= 0x80;
	orl	_PCON,#0x80
;	main.c:33: ES = 1; /* enable uart interrupt */
	setb	_ES
;	main.c:34: TR1 = 1; /* start timer 1 */
	setb	_TR1
;	main.c:35: REN = 1; /* enable input */
	setb	_REN
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'putchar'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	main.c:40: void putchar(char c)
;	-----------------------------------------
;	 function putchar
;	-----------------------------------------
_putchar:
	mov	r7,dpl
;	main.c:42: while (is_tx_busy);
00101$:
	mov	a,_is_tx_busy
	jnz	00101$
;	main.c:44: ACC = c; /* calculate parity */
	mov	_ACC,r7
;	main.c:46: if (P) {
	mov	c,_P
;	main.c:61: is_tx_busy = 1;
	mov	_is_tx_busy,#0x01
;	main.c:62: SBUF = ACC;
	mov	_SBUF,_ACC
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uart_isr'
;------------------------------------------------------------
;c                         Allocated to registers r7 
;------------------------------------------------------------
;	main.c:65: void uart_isr(void) __interrupt (4) __using (1)
;	-----------------------------------------
;	 function uart_isr
;	-----------------------------------------
_uart_isr:
	ar7 = 0x0F
	ar6 = 0x0E
	ar5 = 0x0D
	ar4 = 0x0C
	ar3 = 0x0B
	ar2 = 0x0A
	ar1 = 0x09
	ar0 = 0x08
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x08
;	main.c:67: char c = SBUF;
	mov	r7,_SBUF
;	main.c:69: if (RI) {
;	main.c:70: RI = 0;
	jbc	_RI,00118$
	sjmp	00104$
00118$:
;	main.c:71: printf("%c", c);
	mov	a,r7
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
	push	ar7
	push	ar5
	push	ar6
	mov	a,#___str_0
	push	acc
	mov	a,#(___str_0 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	psw,#0x00
	lcall	_printf
	mov	psw,#0x08
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	pop	ar7
;	main.c:72: if ('\r' == c)
	cjne	r7,#0x0D,00104$
;	main.c:73: printf("\n");
	mov	a,#___str_1
	push	acc
	mov	a,#(___str_1 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	psw,#0x00
	lcall	_printf
	mov	psw,#0x08
	dec	sp
	dec	sp
	dec	sp
00104$:
;	main.c:76: if (TI) {
;	main.c:77: TI = 0;
	jbc	_TI,00121$
	sjmp	00107$
00121$:
;	main.c:78: is_tx_busy = 0;
	mov	_is_tx_busy,#0x00
00107$:
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'timer0_init'
;------------------------------------------------------------
;ms                        Allocated to registers r6 r7 
;sloc0                     Allocated with name '_timer0_init_sloc0_1_0'
;------------------------------------------------------------
;	main.c:83: void timer0_init(unsigned ms)
;	-----------------------------------------
;	 function timer0_init
;	-----------------------------------------
_timer0_init:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
	mov	r7,dph
;	main.c:85: TMOD &= 0xF0; /* set timer0 as mode 1, 16-bit timer/counter */
	anl	_TMOD,#0xF0
;	main.c:86: TMOD |= 0x01;
	orl	_TMOD,#0x01
;	main.c:88: TH0 = t0_initval[HI_BYTE] = (65536 - FCLK/1000/12 * ms - MAGIC) / 256;
	mov	__mullong_PARM_2,r6
	mov	(__mullong_PARM_2 + 1),r7
	mov	(__mullong_PARM_2 + 2),#0x00
	mov	(__mullong_PARM_2 + 3),#0x00
	mov	dptr,#0x0733
	clr	a
	mov	b,a
	lcall	__mullong
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	clr	a
	clr	c
	subb	a,r4
	mov	_timer0_init_sloc0_1_0,a
	clr	a
	subb	a,r5
	mov	(_timer0_init_sloc0_1_0 + 1),a
	mov	a,#0x01
	subb	a,r6
	mov	(_timer0_init_sloc0_1_0 + 2),a
	clr	a
	subb	a,r7
	mov	(_timer0_init_sloc0_1_0 + 3),a
	mov	r2,(_timer0_init_sloc0_1_0 + 1)
	mov	_t0_initval,r2
	mov	_TH0,r2
;	main.c:89: TL0 = t0_initval[LO_BYTE] = (65536 - FCLK/1000/12 * ms - MAGIC) % 256;
	mov	r4,_timer0_init_sloc0_1_0
	mov	(_t0_initval + 0x0001),r4
	mov	_TL0,r4
;	main.c:91: ET0 = 1; /* enable timer0 interrupt */
	setb	_ET0
;	main.c:92: TR0 = 1; /* start timer0 */
	setb	_TR0
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer0_isr'
;------------------------------------------------------------
;	main.c:98: void timer0_isr(void) __interrupt (1) __using (1)
;	-----------------------------------------
;	 function timer0_isr
;	-----------------------------------------
_timer0_isr:
	ar7 = 0x0F
	ar6 = 0x0E
	ar5 = 0x0D
	ar4 = 0x0C
	ar3 = 0x0B
	ar2 = 0x0A
	ar1 = 0x09
	ar0 = 0x08
	push	acc
	push	psw
;	main.c:100: TR0 = 0; /* stop timer0 */
	clr	_TR0
;	main.c:101: TH0 = t0_initval[HI_BYTE];
	mov	_TH0,_t0_initval
;	main.c:102: TL0 = t0_initval[LO_BYTE]; /*
	mov	_TL0,(_t0_initval + 0x0001)
;	main.c:110: if (toggle > 10)
	clr	c
	mov	a,#0x0A
	subb	a,_toggle
	clr	a
	subb	a,(_toggle + 1)
	jnc	00102$
;	main.c:111: toggle = 0;
	clr	a
	mov	_toggle,a
	mov	(_toggle + 1),a
	sjmp	00103$
00102$:
;	main.c:113: toggle++;
	mov	a,#0x01
	add	a,_toggle
	mov	_toggle,a
	clr	a
	addc	a,(_toggle + 1)
	mov	(_toggle + 1),a
00103$:
;	main.c:115: TR0 = 1; /* start timer0 */
	setb	_TR0
	pop	psw
	pop	acc
	reti
;	eliminated unneeded mov psw,# (no regs used in bank)
;	eliminated unneeded push/pop dpl
;	eliminated unneeded push/pop dph
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;c                         Allocated with name '_main_c_1_30'
;------------------------------------------------------------
;	main.c:118: void main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	main.c:122: P2 = val;
	mov	_P2,_val
;	main.c:123: uart_init(115200UL);
	mov	dptr,#0xC200
	mov	b,#0x01
	clr	a
	lcall	_uart_init
;	main.c:124: timer0_init(100);
	mov	dptr,#0x0064
	lcall	_timer0_init
;	main.c:125: EA = 1;
	setb	_EA
;	main.c:126: printf("build: %s %s\r\n", __TIME__, __DATE__);	
	mov	a,#___str_4
	push	acc
	mov	a,#(___str_4 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#___str_3
	push	acc
	mov	a,#(___str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#___str_2
	push	acc
	mov	a,#(___str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_printf
	mov	a,sp
	add	a,#0xf7
	mov	sp,a
;	main.c:127: while (1) {
00102$:
	sjmp	00102$
	.area CSEG    (CODE)
	.area CONST   (CODE)
___str_0:
	.ascii "%c"
	.db 0x00
___str_1:
	.db 0x0A
	.db 0x00
___str_2:
	.ascii "build: %s %s"
	.db 0x0D
	.db 0x0A
	.db 0x00
___str_3:
	.ascii "19:33:20"
	.db 0x00
___str_4:
	.ascii "Mar  9 2017"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
