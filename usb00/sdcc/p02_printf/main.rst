                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Thu Mar  9 19:33:20 2017
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _timer0_isr
                                     14 	.globl _timer0_init
                                     15 	.globl _uart_isr
                                     16 	.globl _uart_init
                                     17 	.globl _printf
                                     18 	.globl _P4_6
                                     19 	.globl _P4_5
                                     20 	.globl _P4_4
                                     21 	.globl _P4_3
                                     22 	.globl _P4_2
                                     23 	.globl _P4_1
                                     24 	.globl _P4_0
                                     25 	.globl _CY
                                     26 	.globl _AC
                                     27 	.globl _F0
                                     28 	.globl _RS1
                                     29 	.globl _RS0
                                     30 	.globl _OV
                                     31 	.globl _FL
                                     32 	.globl _P
                                     33 	.globl _TF2
                                     34 	.globl _EXF2
                                     35 	.globl _RCLK
                                     36 	.globl _TCLK
                                     37 	.globl _EXEN2
                                     38 	.globl _TR2
                                     39 	.globl _C_T2
                                     40 	.globl _CP_RL2
                                     41 	.globl _T2CON_7
                                     42 	.globl _T2CON_6
                                     43 	.globl _T2CON_5
                                     44 	.globl _T2CON_4
                                     45 	.globl _T2CON_3
                                     46 	.globl _T2CON_2
                                     47 	.globl _T2CON_1
                                     48 	.globl _T2CON_0
                                     49 	.globl _PT2
                                     50 	.globl _PS
                                     51 	.globl _PT1
                                     52 	.globl _PX1
                                     53 	.globl _PT0
                                     54 	.globl _PX0
                                     55 	.globl _RD
                                     56 	.globl _WR
                                     57 	.globl _T1
                                     58 	.globl _T0
                                     59 	.globl _INT1
                                     60 	.globl _INT0
                                     61 	.globl _TXD
                                     62 	.globl _RXD
                                     63 	.globl _P3_7
                                     64 	.globl _P3_6
                                     65 	.globl _P3_5
                                     66 	.globl _P3_4
                                     67 	.globl _P3_3
                                     68 	.globl _P3_2
                                     69 	.globl _P3_1
                                     70 	.globl _P3_0
                                     71 	.globl _EA
                                     72 	.globl _ET2
                                     73 	.globl _ES
                                     74 	.globl _ET1
                                     75 	.globl _EX1
                                     76 	.globl _ET0
                                     77 	.globl _EX0
                                     78 	.globl _P2_7
                                     79 	.globl _P2_6
                                     80 	.globl _P2_5
                                     81 	.globl _P2_4
                                     82 	.globl _P2_3
                                     83 	.globl _P2_2
                                     84 	.globl _P2_1
                                     85 	.globl _P2_0
                                     86 	.globl _SM0
                                     87 	.globl _SM1
                                     88 	.globl _SM2
                                     89 	.globl _REN
                                     90 	.globl _TB8
                                     91 	.globl _RB8
                                     92 	.globl _TI
                                     93 	.globl _RI
                                     94 	.globl _T2EX
                                     95 	.globl _T2
                                     96 	.globl _P1_7
                                     97 	.globl _P1_6
                                     98 	.globl _P1_5
                                     99 	.globl _P1_4
                                    100 	.globl _P1_3
                                    101 	.globl _P1_2
                                    102 	.globl _P1_1
                                    103 	.globl _P1_0
                                    104 	.globl _TF1
                                    105 	.globl _TR1
                                    106 	.globl _TF0
                                    107 	.globl _TR0
                                    108 	.globl _IE1
                                    109 	.globl _IT1
                                    110 	.globl _IE0
                                    111 	.globl _IT0
                                    112 	.globl _P0_7
                                    113 	.globl _P0_6
                                    114 	.globl _P0_5
                                    115 	.globl _P0_4
                                    116 	.globl _P0_3
                                    117 	.globl _P0_2
                                    118 	.globl _P0_1
                                    119 	.globl _P0_0
                                    120 	.globl _P4
                                    121 	.globl _ISP_CONTR
                                    122 	.globl _ISP_TRIG
                                    123 	.globl _ISP_CMD
                                    124 	.globl _ISP_ADDRL
                                    125 	.globl _ISP_ADDRH
                                    126 	.globl _ISP_DATA
                                    127 	.globl _WDT_CONTR
                                    128 	.globl _XICON
                                    129 	.globl _SADEN
                                    130 	.globl _IPH
                                    131 	.globl _SADDR
                                    132 	.globl _AUXR1
                                    133 	.globl _AUXR
                                    134 	.globl _B
                                    135 	.globl _A
                                    136 	.globl _ACC
                                    137 	.globl _PSW
                                    138 	.globl _TH2
                                    139 	.globl _TL2
                                    140 	.globl _RCAP2H
                                    141 	.globl _RCAP2L
                                    142 	.globl _T2MOD
                                    143 	.globl _T2CON
                                    144 	.globl _IP
                                    145 	.globl _P3
                                    146 	.globl _IE
                                    147 	.globl _P2
                                    148 	.globl _SBUF
                                    149 	.globl _SCON
                                    150 	.globl _P1
                                    151 	.globl _TH1
                                    152 	.globl _TH0
                                    153 	.globl _TL1
                                    154 	.globl _TL0
                                    155 	.globl _TMOD
                                    156 	.globl _TCON
                                    157 	.globl _PCON
                                    158 	.globl _DPH
                                    159 	.globl _DPL
                                    160 	.globl _SP
                                    161 	.globl _P0
                                    162 	.globl _toggle
                                    163 	.globl _val
                                    164 	.globl _t0_initval
                                    165 	.globl _putchar
                                    166 ;--------------------------------------------------------
                                    167 ; special function registers
                                    168 ;--------------------------------------------------------
                                    169 	.area RSEG    (ABS,DATA)
      000000                        170 	.org 0x0000
                           000080   171 _P0	=	0x0080
                           000081   172 _SP	=	0x0081
                           000082   173 _DPL	=	0x0082
                           000083   174 _DPH	=	0x0083
                           000087   175 _PCON	=	0x0087
                           000088   176 _TCON	=	0x0088
                           000089   177 _TMOD	=	0x0089
                           00008A   178 _TL0	=	0x008a
                           00008B   179 _TL1	=	0x008b
                           00008C   180 _TH0	=	0x008c
                           00008D   181 _TH1	=	0x008d
                           000090   182 _P1	=	0x0090
                           000098   183 _SCON	=	0x0098
                           000099   184 _SBUF	=	0x0099
                           0000A0   185 _P2	=	0x00a0
                           0000A8   186 _IE	=	0x00a8
                           0000B0   187 _P3	=	0x00b0
                           0000B8   188 _IP	=	0x00b8
                           0000C8   189 _T2CON	=	0x00c8
                           0000C9   190 _T2MOD	=	0x00c9
                           0000CA   191 _RCAP2L	=	0x00ca
                           0000CB   192 _RCAP2H	=	0x00cb
                           0000CC   193 _TL2	=	0x00cc
                           0000CD   194 _TH2	=	0x00cd
                           0000D0   195 _PSW	=	0x00d0
                           0000E0   196 _ACC	=	0x00e0
                           0000E0   197 _A	=	0x00e0
                           0000F0   198 _B	=	0x00f0
                           00008E   199 _AUXR	=	0x008e
                           0000A2   200 _AUXR1	=	0x00a2
                           0000A9   201 _SADDR	=	0x00a9
                           0000B7   202 _IPH	=	0x00b7
                           0000B9   203 _SADEN	=	0x00b9
                           0000C0   204 _XICON	=	0x00c0
                           0000E1   205 _WDT_CONTR	=	0x00e1
                           0000E2   206 _ISP_DATA	=	0x00e2
                           0000E3   207 _ISP_ADDRH	=	0x00e3
                           0000E4   208 _ISP_ADDRL	=	0x00e4
                           0000E5   209 _ISP_CMD	=	0x00e5
                           0000E6   210 _ISP_TRIG	=	0x00e6
                           0000E7   211 _ISP_CONTR	=	0x00e7
                           0000E8   212 _P4	=	0x00e8
                                    213 ;--------------------------------------------------------
                                    214 ; special function bits
                                    215 ;--------------------------------------------------------
                                    216 	.area RSEG    (ABS,DATA)
      000000                        217 	.org 0x0000
                           000080   218 _P0_0	=	0x0080
                           000081   219 _P0_1	=	0x0081
                           000082   220 _P0_2	=	0x0082
                           000083   221 _P0_3	=	0x0083
                           000084   222 _P0_4	=	0x0084
                           000085   223 _P0_5	=	0x0085
                           000086   224 _P0_6	=	0x0086
                           000087   225 _P0_7	=	0x0087
                           000088   226 _IT0	=	0x0088
                           000089   227 _IE0	=	0x0089
                           00008A   228 _IT1	=	0x008a
                           00008B   229 _IE1	=	0x008b
                           00008C   230 _TR0	=	0x008c
                           00008D   231 _TF0	=	0x008d
                           00008E   232 _TR1	=	0x008e
                           00008F   233 _TF1	=	0x008f
                           000090   234 _P1_0	=	0x0090
                           000091   235 _P1_1	=	0x0091
                           000092   236 _P1_2	=	0x0092
                           000093   237 _P1_3	=	0x0093
                           000094   238 _P1_4	=	0x0094
                           000095   239 _P1_5	=	0x0095
                           000096   240 _P1_6	=	0x0096
                           000097   241 _P1_7	=	0x0097
                           000090   242 _T2	=	0x0090
                           000091   243 _T2EX	=	0x0091
                           000098   244 _RI	=	0x0098
                           000099   245 _TI	=	0x0099
                           00009A   246 _RB8	=	0x009a
                           00009B   247 _TB8	=	0x009b
                           00009C   248 _REN	=	0x009c
                           00009D   249 _SM2	=	0x009d
                           00009E   250 _SM1	=	0x009e
                           00009F   251 _SM0	=	0x009f
                           0000A0   252 _P2_0	=	0x00a0
                           0000A1   253 _P2_1	=	0x00a1
                           0000A2   254 _P2_2	=	0x00a2
                           0000A3   255 _P2_3	=	0x00a3
                           0000A4   256 _P2_4	=	0x00a4
                           0000A5   257 _P2_5	=	0x00a5
                           0000A6   258 _P2_6	=	0x00a6
                           0000A7   259 _P2_7	=	0x00a7
                           0000A8   260 _EX0	=	0x00a8
                           0000A9   261 _ET0	=	0x00a9
                           0000AA   262 _EX1	=	0x00aa
                           0000AB   263 _ET1	=	0x00ab
                           0000AC   264 _ES	=	0x00ac
                           0000AD   265 _ET2	=	0x00ad
                           0000AF   266 _EA	=	0x00af
                           0000B0   267 _P3_0	=	0x00b0
                           0000B1   268 _P3_1	=	0x00b1
                           0000B2   269 _P3_2	=	0x00b2
                           0000B3   270 _P3_3	=	0x00b3
                           0000B4   271 _P3_4	=	0x00b4
                           0000B5   272 _P3_5	=	0x00b5
                           0000B6   273 _P3_6	=	0x00b6
                           0000B7   274 _P3_7	=	0x00b7
                           0000B0   275 _RXD	=	0x00b0
                           0000B1   276 _TXD	=	0x00b1
                           0000B2   277 _INT0	=	0x00b2
                           0000B3   278 _INT1	=	0x00b3
                           0000B4   279 _T0	=	0x00b4
                           0000B5   280 _T1	=	0x00b5
                           0000B6   281 _WR	=	0x00b6
                           0000B7   282 _RD	=	0x00b7
                           0000B8   283 _PX0	=	0x00b8
                           0000B9   284 _PT0	=	0x00b9
                           0000BA   285 _PX1	=	0x00ba
                           0000BB   286 _PT1	=	0x00bb
                           0000BC   287 _PS	=	0x00bc
                           0000BD   288 _PT2	=	0x00bd
                           0000C8   289 _T2CON_0	=	0x00c8
                           0000C9   290 _T2CON_1	=	0x00c9
                           0000CA   291 _T2CON_2	=	0x00ca
                           0000CB   292 _T2CON_3	=	0x00cb
                           0000CC   293 _T2CON_4	=	0x00cc
                           0000CD   294 _T2CON_5	=	0x00cd
                           0000CE   295 _T2CON_6	=	0x00ce
                           0000CF   296 _T2CON_7	=	0x00cf
                           0000C8   297 _CP_RL2	=	0x00c8
                           0000C9   298 _C_T2	=	0x00c9
                           0000CA   299 _TR2	=	0x00ca
                           0000CB   300 _EXEN2	=	0x00cb
                           0000CC   301 _TCLK	=	0x00cc
                           0000CD   302 _RCLK	=	0x00cd
                           0000CE   303 _EXF2	=	0x00ce
                           0000CF   304 _TF2	=	0x00cf
                           0000D0   305 _P	=	0x00d0
                           0000D1   306 _FL	=	0x00d1
                           0000D2   307 _OV	=	0x00d2
                           0000D3   308 _RS0	=	0x00d3
                           0000D4   309 _RS1	=	0x00d4
                           0000D5   310 _F0	=	0x00d5
                           0000D6   311 _AC	=	0x00d6
                           0000D7   312 _CY	=	0x00d7
                           0000E8   313 _P4_0	=	0x00e8
                           0000E9   314 _P4_1	=	0x00e9
                           0000EA   315 _P4_2	=	0x00ea
                           0000EB   316 _P4_3	=	0x00eb
                           0000EC   317 _P4_4	=	0x00ec
                           0000ED   318 _P4_5	=	0x00ed
                           0000EE   319 _P4_6	=	0x00ee
                                    320 ;--------------------------------------------------------
                                    321 ; overlayable register banks
                                    322 ;--------------------------------------------------------
                                    323 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        324 	.ds 8
                                    325 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        326 	.ds 8
                                    327 ;--------------------------------------------------------
                                    328 ; overlayable bit register bank
                                    329 ;--------------------------------------------------------
                                    330 	.area BIT_BANK	(REL,OVR,DATA)
      000022                        331 bits:
      000022                        332 	.ds 1
                           008000   333 	b0 = bits[0]
                           008100   334 	b1 = bits[1]
                           008200   335 	b2 = bits[2]
                           008300   336 	b3 = bits[3]
                           008400   337 	b4 = bits[4]
                           008500   338 	b5 = bits[5]
                           008600   339 	b6 = bits[6]
                           008700   340 	b7 = bits[7]
                                    341 ;--------------------------------------------------------
                                    342 ; internal ram data
                                    343 ;--------------------------------------------------------
                                    344 	.area DSEG    (DATA)
      000010                        345 _is_tx_busy:
      000010                        346 	.ds 1
      000011                        347 _t0_initval::
      000011                        348 	.ds 2
      000013                        349 _timer0_init_sloc0_1_0:
      000013                        350 	.ds 4
      000017                        351 _val::
      000017                        352 	.ds 1
      000018                        353 _toggle::
      000018                        354 	.ds 2
                                    355 ;--------------------------------------------------------
                                    356 ; overlayable items in internal ram 
                                    357 ;--------------------------------------------------------
                                    358 	.area	OSEG    (OVR,DATA)
                                    359 ;--------------------------------------------------------
                                    360 ; Stack segment in internal ram 
                                    361 ;--------------------------------------------------------
                                    362 	.area	SSEG
      000049                        363 __start__stack:
      000049                        364 	.ds	1
                                    365 
                                    366 ;--------------------------------------------------------
                                    367 ; indirectly addressable internal ram data
                                    368 ;--------------------------------------------------------
                                    369 	.area ISEG    (DATA)
                                    370 ;--------------------------------------------------------
                                    371 ; absolute internal ram data
                                    372 ;--------------------------------------------------------
                                    373 	.area IABS    (ABS,DATA)
                                    374 	.area IABS    (ABS,DATA)
                                    375 ;--------------------------------------------------------
                                    376 ; bit data
                                    377 ;--------------------------------------------------------
                                    378 	.area BSEG    (BIT)
                                    379 ;--------------------------------------------------------
                                    380 ; paged external ram data
                                    381 ;--------------------------------------------------------
                                    382 	.area PSEG    (PAG,XDATA)
                                    383 ;--------------------------------------------------------
                                    384 ; external ram data
                                    385 ;--------------------------------------------------------
                                    386 	.area XSEG    (XDATA)
                                    387 ;--------------------------------------------------------
                                    388 ; absolute external ram data
                                    389 ;--------------------------------------------------------
                                    390 	.area XABS    (ABS,XDATA)
                                    391 ;--------------------------------------------------------
                                    392 ; external initialized ram data
                                    393 ;--------------------------------------------------------
                                    394 	.area XISEG   (XDATA)
                                    395 	.area HOME    (CODE)
                                    396 	.area GSINIT0 (CODE)
                                    397 	.area GSINIT1 (CODE)
                                    398 	.area GSINIT2 (CODE)
                                    399 	.area GSINIT3 (CODE)
                                    400 	.area GSINIT4 (CODE)
                                    401 	.area GSINIT5 (CODE)
                                    402 	.area GSINIT  (CODE)
                                    403 	.area GSFINAL (CODE)
                                    404 	.area CSEG    (CODE)
                                    405 ;--------------------------------------------------------
                                    406 ; interrupt vector 
                                    407 ;--------------------------------------------------------
                                    408 	.area HOME    (CODE)
      000000                        409 __interrupt_vect:
      000000 02 00 29         [24]  410 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  411 	reti
      000004                        412 	.ds	7
      00000B 02 01 C5         [24]  413 	ljmp	_timer0_isr
      00000E                        414 	.ds	5
      000013 32               [24]  415 	reti
      000014                        416 	.ds	7
      00001B 32               [24]  417 	reti
      00001C                        418 	.ds	7
      000023 02 00 EC         [24]  419 	ljmp	_uart_isr
                                    420 ;--------------------------------------------------------
                                    421 ; global & static initialisations
                                    422 ;--------------------------------------------------------
                                    423 	.area HOME    (CODE)
                                    424 	.area GSINIT  (CODE)
                                    425 	.area GSFINAL (CODE)
                                    426 	.area GSINIT  (CODE)
                                    427 	.globl __sdcc_gsinit_startup
                                    428 	.globl __sdcc_program_startup
                                    429 	.globl __start__stack
                                    430 	.globl __mcs51_genXINIT
                                    431 	.globl __mcs51_genXRAMCLEAR
                                    432 	.globl __mcs51_genRAMCLEAR
                                    433 ;	main.c:38: static unsigned char is_tx_busy = 0;
      000082 75 10 00         [24]  434 	mov	_is_tx_busy,#0x00
                                    435 ;	main.c:95: volatile unsigned char val = 0x55;
      000085 75 17 55         [24]  436 	mov	_val,#0x55
                                    437 ;	main.c:97: volatile unsigned toggle = 0;
      000088 E4               [12]  438 	clr	a
      000089 F5 18            [12]  439 	mov	_toggle,a
      00008B F5 19            [12]  440 	mov	(_toggle + 1),a
                                    441 	.area GSFINAL (CODE)
      00008D 02 00 26         [24]  442 	ljmp	__sdcc_program_startup
                                    443 ;--------------------------------------------------------
                                    444 ; Home
                                    445 ;--------------------------------------------------------
                                    446 	.area HOME    (CODE)
                                    447 	.area HOME    (CODE)
      000026                        448 __sdcc_program_startup:
      000026 02 01 F4         [24]  449 	ljmp	_main
                                    450 ;	return from main will return to caller
                                    451 ;--------------------------------------------------------
                                    452 ; code
                                    453 ;--------------------------------------------------------
                                    454 	.area CSEG    (CODE)
                                    455 ;------------------------------------------------------------
                                    456 ;Allocation info for local variables in function 'uart_init'
                                    457 ;------------------------------------------------------------
                                    458 ;baudrate                  Allocated to registers r4 r5 r6 r7 
                                    459 ;------------------------------------------------------------
                                    460 ;	main.c:17: void uart_init(unsigned long baudrate)
                                    461 ;	-----------------------------------------
                                    462 ;	 function uart_init
                                    463 ;	-----------------------------------------
      000090                        464 _uart_init:
                           000007   465 	ar7 = 0x07
                           000006   466 	ar6 = 0x06
                           000005   467 	ar5 = 0x05
                           000004   468 	ar4 = 0x04
                           000003   469 	ar3 = 0x03
                           000002   470 	ar2 = 0x02
                           000001   471 	ar1 = 0x01
                           000000   472 	ar0 = 0x00
      000090 AC 82            [24]  473 	mov	r4,dpl
      000092 AD 83            [24]  474 	mov	r5,dph
      000094 AE F0            [24]  475 	mov	r6,b
      000096 FF               [12]  476 	mov	r7,a
                                    477 ;	main.c:26: SCON = 0x50;
      000097 75 98 50         [24]  478 	mov	_SCON,#0x50
                                    479 ;	main.c:29: TMOD &= 0x0F; /* set timer 1 as mode 2, autoload */
      00009A 53 89 0F         [24]  480 	anl	_TMOD,#0x0F
                                    481 ;	main.c:30: TMOD |= 0x20;
      00009D 43 89 20         [24]  482 	orl	_TMOD,#0x20
                                    483 ;	main.c:31: TH1 = TL1 = 256 - (FCLK / (12 * 16 * baudrate));
      0000A0 8C 3D            [24]  484 	mov	__mullong_PARM_2,r4
      0000A2 8D 3E            [24]  485 	mov	(__mullong_PARM_2 + 1),r5
      0000A4 8E 3F            [24]  486 	mov	(__mullong_PARM_2 + 2),r6
      0000A6 8F 40            [24]  487 	mov	(__mullong_PARM_2 + 3),r7
      0000A8 90 00 C0         [24]  488 	mov	dptr,#(0xC0&0x00ff)
      0000AB E4               [12]  489 	clr	a
      0000AC F5 F0            [12]  490 	mov	b,a
      0000AE 12 02 9D         [24]  491 	lcall	__mullong
      0000B1 85 82 3D         [24]  492 	mov	__divulong_PARM_2,dpl
      0000B4 85 83 3E         [24]  493 	mov	(__divulong_PARM_2 + 1),dph
      0000B7 85 F0 3F         [24]  494 	mov	(__divulong_PARM_2 + 2),b
      0000BA F5 40            [12]  495 	mov	(__divulong_PARM_2 + 3),a
      0000BC 90 80 00         [24]  496 	mov	dptr,#0x8000
      0000BF 75 F0 51         [24]  497 	mov	b,#0x51
      0000C2 74 01            [12]  498 	mov	a,#0x01
      0000C4 12 02 38         [24]  499 	lcall	__divulong
      0000C7 AC 82            [24]  500 	mov	r4,dpl
      0000C9 C3               [12]  501 	clr	c
      0000CA E4               [12]  502 	clr	a
      0000CB 9C               [12]  503 	subb	a,r4
      0000CC FC               [12]  504 	mov	r4,a
      0000CD 8C 8B            [24]  505 	mov	_TL1,r4
      0000CF 8C 8D            [24]  506 	mov	_TH1,r4
                                    507 ;	main.c:32: PCON |= 0x80;
      0000D1 43 87 80         [24]  508 	orl	_PCON,#0x80
                                    509 ;	main.c:33: ES = 1; /* enable uart interrupt */
      0000D4 D2 AC            [12]  510 	setb	_ES
                                    511 ;	main.c:34: TR1 = 1; /* start timer 1 */
      0000D6 D2 8E            [12]  512 	setb	_TR1
                                    513 ;	main.c:35: REN = 1; /* enable input */
      0000D8 D2 9C            [12]  514 	setb	_REN
      0000DA 22               [24]  515 	ret
                                    516 ;------------------------------------------------------------
                                    517 ;Allocation info for local variables in function 'putchar'
                                    518 ;------------------------------------------------------------
                                    519 ;c                         Allocated to registers r7 
                                    520 ;------------------------------------------------------------
                                    521 ;	main.c:40: void putchar(char c)
                                    522 ;	-----------------------------------------
                                    523 ;	 function putchar
                                    524 ;	-----------------------------------------
      0000DB                        525 _putchar:
      0000DB AF 82            [24]  526 	mov	r7,dpl
                                    527 ;	main.c:42: while (is_tx_busy);
      0000DD                        528 00101$:
      0000DD E5 10            [12]  529 	mov	a,_is_tx_busy
      0000DF 70 FC            [24]  530 	jnz	00101$
                                    531 ;	main.c:44: ACC = c; /* calculate parity */
      0000E1 8F E0            [24]  532 	mov	_ACC,r7
                                    533 ;	main.c:46: if (P) {
      0000E3 A2 D0            [12]  534 	mov	c,_P
                                    535 ;	main.c:61: is_tx_busy = 1;
      0000E5 75 10 01         [24]  536 	mov	_is_tx_busy,#0x01
                                    537 ;	main.c:62: SBUF = ACC;
      0000E8 85 E0 99         [24]  538 	mov	_SBUF,_ACC
      0000EB 22               [24]  539 	ret
                                    540 ;------------------------------------------------------------
                                    541 ;Allocation info for local variables in function 'uart_isr'
                                    542 ;------------------------------------------------------------
                                    543 ;c                         Allocated to registers r7 
                                    544 ;------------------------------------------------------------
                                    545 ;	main.c:65: void uart_isr(void) __interrupt (4) __using (1)
                                    546 ;	-----------------------------------------
                                    547 ;	 function uart_isr
                                    548 ;	-----------------------------------------
      0000EC                        549 _uart_isr:
                           00000F   550 	ar7 = 0x0F
                           00000E   551 	ar6 = 0x0E
                           00000D   552 	ar5 = 0x0D
                           00000C   553 	ar4 = 0x0C
                           00000B   554 	ar3 = 0x0B
                           00000A   555 	ar2 = 0x0A
                           000009   556 	ar1 = 0x09
                           000008   557 	ar0 = 0x08
      0000EC C0 22            [24]  558 	push	bits
      0000EE C0 E0            [24]  559 	push	acc
      0000F0 C0 F0            [24]  560 	push	b
      0000F2 C0 82            [24]  561 	push	dpl
      0000F4 C0 83            [24]  562 	push	dph
      0000F6 C0 07            [24]  563 	push	(0+7)
      0000F8 C0 06            [24]  564 	push	(0+6)
      0000FA C0 05            [24]  565 	push	(0+5)
      0000FC C0 04            [24]  566 	push	(0+4)
      0000FE C0 03            [24]  567 	push	(0+3)
      000100 C0 02            [24]  568 	push	(0+2)
      000102 C0 01            [24]  569 	push	(0+1)
      000104 C0 00            [24]  570 	push	(0+0)
      000106 C0 D0            [24]  571 	push	psw
      000108 75 D0 08         [24]  572 	mov	psw,#0x08
                                    573 ;	main.c:67: char c = SBUF;
      00010B AF 99            [24]  574 	mov	r7,_SBUF
                                    575 ;	main.c:69: if (RI) {
                                    576 ;	main.c:70: RI = 0;
      00010D 10 98 02         [24]  577 	jbc	_RI,00118$
      000110 80 47            [24]  578 	sjmp	00104$
      000112                        579 00118$:
                                    580 ;	main.c:71: printf("%c", c);
      000112 EF               [12]  581 	mov	a,r7
      000113 FD               [12]  582 	mov	r5,a
      000114 33               [12]  583 	rlc	a
      000115 95 E0            [12]  584 	subb	a,acc
      000117 FE               [12]  585 	mov	r6,a
      000118 C0 0F            [24]  586 	push	ar7
      00011A C0 0D            [24]  587 	push	ar5
      00011C C0 0E            [24]  588 	push	ar6
      00011E 74 48            [12]  589 	mov	a,#___str_0
      000120 C0 E0            [24]  590 	push	acc
      000122 74 09            [12]  591 	mov	a,#(___str_0 >> 8)
      000124 C0 E0            [24]  592 	push	acc
      000126 74 80            [12]  593 	mov	a,#0x80
      000128 C0 E0            [24]  594 	push	acc
      00012A 75 D0 00         [24]  595 	mov	psw,#0x00
      00012D 12 03 2F         [24]  596 	lcall	_printf
      000130 75 D0 08         [24]  597 	mov	psw,#0x08
      000133 E5 81            [12]  598 	mov	a,sp
      000135 24 FB            [12]  599 	add	a,#0xfb
      000137 F5 81            [12]  600 	mov	sp,a
      000139 D0 0F            [24]  601 	pop	ar7
                                    602 ;	main.c:72: if ('\r' == c)
      00013B BF 0D 1B         [24]  603 	cjne	r7,#0x0D,00104$
                                    604 ;	main.c:73: printf("\n");
      00013E 74 4B            [12]  605 	mov	a,#___str_1
      000140 C0 E0            [24]  606 	push	acc
      000142 74 09            [12]  607 	mov	a,#(___str_1 >> 8)
      000144 C0 E0            [24]  608 	push	acc
      000146 74 80            [12]  609 	mov	a,#0x80
      000148 C0 E0            [24]  610 	push	acc
      00014A 75 D0 00         [24]  611 	mov	psw,#0x00
      00014D 12 03 2F         [24]  612 	lcall	_printf
      000150 75 D0 08         [24]  613 	mov	psw,#0x08
      000153 15 81            [12]  614 	dec	sp
      000155 15 81            [12]  615 	dec	sp
      000157 15 81            [12]  616 	dec	sp
      000159                        617 00104$:
                                    618 ;	main.c:76: if (TI) {
                                    619 ;	main.c:77: TI = 0;
      000159 10 99 02         [24]  620 	jbc	_TI,00121$
      00015C 80 03            [24]  621 	sjmp	00107$
      00015E                        622 00121$:
                                    623 ;	main.c:78: is_tx_busy = 0;
      00015E 75 10 00         [24]  624 	mov	_is_tx_busy,#0x00
      000161                        625 00107$:
      000161 D0 D0            [24]  626 	pop	psw
      000163 D0 00            [24]  627 	pop	(0+0)
      000165 D0 01            [24]  628 	pop	(0+1)
      000167 D0 02            [24]  629 	pop	(0+2)
      000169 D0 03            [24]  630 	pop	(0+3)
      00016B D0 04            [24]  631 	pop	(0+4)
      00016D D0 05            [24]  632 	pop	(0+5)
      00016F D0 06            [24]  633 	pop	(0+6)
      000171 D0 07            [24]  634 	pop	(0+7)
      000173 D0 83            [24]  635 	pop	dph
      000175 D0 82            [24]  636 	pop	dpl
      000177 D0 F0            [24]  637 	pop	b
      000179 D0 E0            [24]  638 	pop	acc
      00017B D0 22            [24]  639 	pop	bits
      00017D 32               [24]  640 	reti
                                    641 ;------------------------------------------------------------
                                    642 ;Allocation info for local variables in function 'timer0_init'
                                    643 ;------------------------------------------------------------
                                    644 ;ms                        Allocated to registers r6 r7 
                                    645 ;sloc0                     Allocated with name '_timer0_init_sloc0_1_0'
                                    646 ;------------------------------------------------------------
                                    647 ;	main.c:83: void timer0_init(unsigned ms)
                                    648 ;	-----------------------------------------
                                    649 ;	 function timer0_init
                                    650 ;	-----------------------------------------
      00017E                        651 _timer0_init:
                           000007   652 	ar7 = 0x07
                           000006   653 	ar6 = 0x06
                           000005   654 	ar5 = 0x05
                           000004   655 	ar4 = 0x04
                           000003   656 	ar3 = 0x03
                           000002   657 	ar2 = 0x02
                           000001   658 	ar1 = 0x01
                           000000   659 	ar0 = 0x00
      00017E AE 82            [24]  660 	mov	r6,dpl
      000180 AF 83            [24]  661 	mov	r7,dph
                                    662 ;	main.c:85: TMOD &= 0xF0; /* set timer0 as mode 1, 16-bit timer/counter */
      000182 53 89 F0         [24]  663 	anl	_TMOD,#0xF0
                                    664 ;	main.c:86: TMOD |= 0x01;
      000185 43 89 01         [24]  665 	orl	_TMOD,#0x01
                                    666 ;	main.c:88: TH0 = t0_initval[HI_BYTE] = (65536 - FCLK/1000/12 * ms - MAGIC) / 256;
      000188 8E 3D            [24]  667 	mov	__mullong_PARM_2,r6
      00018A 8F 3E            [24]  668 	mov	(__mullong_PARM_2 + 1),r7
      00018C 75 3F 00         [24]  669 	mov	(__mullong_PARM_2 + 2),#0x00
      00018F 75 40 00         [24]  670 	mov	(__mullong_PARM_2 + 3),#0x00
      000192 90 07 33         [24]  671 	mov	dptr,#0x0733
      000195 E4               [12]  672 	clr	a
      000196 F5 F0            [12]  673 	mov	b,a
      000198 12 02 9D         [24]  674 	lcall	__mullong
      00019B AC 82            [24]  675 	mov	r4,dpl
      00019D AD 83            [24]  676 	mov	r5,dph
      00019F AE F0            [24]  677 	mov	r6,b
      0001A1 FF               [12]  678 	mov	r7,a
      0001A2 E4               [12]  679 	clr	a
      0001A3 C3               [12]  680 	clr	c
      0001A4 9C               [12]  681 	subb	a,r4
      0001A5 F5 13            [12]  682 	mov	_timer0_init_sloc0_1_0,a
      0001A7 E4               [12]  683 	clr	a
      0001A8 9D               [12]  684 	subb	a,r5
      0001A9 F5 14            [12]  685 	mov	(_timer0_init_sloc0_1_0 + 1),a
      0001AB 74 01            [12]  686 	mov	a,#0x01
      0001AD 9E               [12]  687 	subb	a,r6
      0001AE F5 15            [12]  688 	mov	(_timer0_init_sloc0_1_0 + 2),a
      0001B0 E4               [12]  689 	clr	a
      0001B1 9F               [12]  690 	subb	a,r7
      0001B2 F5 16            [12]  691 	mov	(_timer0_init_sloc0_1_0 + 3),a
      0001B4 AA 14            [24]  692 	mov	r2,(_timer0_init_sloc0_1_0 + 1)
      0001B6 8A 11            [24]  693 	mov	_t0_initval,r2
      0001B8 8A 8C            [24]  694 	mov	_TH0,r2
                                    695 ;	main.c:89: TL0 = t0_initval[LO_BYTE] = (65536 - FCLK/1000/12 * ms - MAGIC) % 256;
      0001BA AC 13            [24]  696 	mov	r4,_timer0_init_sloc0_1_0
      0001BC 8C 12            [24]  697 	mov	(_t0_initval + 0x0001),r4
      0001BE 8C 8A            [24]  698 	mov	_TL0,r4
                                    699 ;	main.c:91: ET0 = 1; /* enable timer0 interrupt */
      0001C0 D2 A9            [12]  700 	setb	_ET0
                                    701 ;	main.c:92: TR0 = 1; /* start timer0 */
      0001C2 D2 8C            [12]  702 	setb	_TR0
      0001C4 22               [24]  703 	ret
                                    704 ;------------------------------------------------------------
                                    705 ;Allocation info for local variables in function 'timer0_isr'
                                    706 ;------------------------------------------------------------
                                    707 ;	main.c:98: void timer0_isr(void) __interrupt (1) __using (1)
                                    708 ;	-----------------------------------------
                                    709 ;	 function timer0_isr
                                    710 ;	-----------------------------------------
      0001C5                        711 _timer0_isr:
                           00000F   712 	ar7 = 0x0F
                           00000E   713 	ar6 = 0x0E
                           00000D   714 	ar5 = 0x0D
                           00000C   715 	ar4 = 0x0C
                           00000B   716 	ar3 = 0x0B
                           00000A   717 	ar2 = 0x0A
                           000009   718 	ar1 = 0x09
                           000008   719 	ar0 = 0x08
      0001C5 C0 E0            [24]  720 	push	acc
      0001C7 C0 D0            [24]  721 	push	psw
                                    722 ;	main.c:100: TR0 = 0; /* stop timer0 */
      0001C9 C2 8C            [12]  723 	clr	_TR0
                                    724 ;	main.c:101: TH0 = t0_initval[HI_BYTE];
      0001CB 85 11 8C         [24]  725 	mov	_TH0,_t0_initval
                                    726 ;	main.c:102: TL0 = t0_initval[LO_BYTE]; /*
      0001CE 85 12 8A         [24]  727 	mov	_TL0,(_t0_initval + 0x0001)
                                    728 ;	main.c:110: if (toggle > 10)
      0001D1 C3               [12]  729 	clr	c
      0001D2 74 0A            [12]  730 	mov	a,#0x0A
      0001D4 95 18            [12]  731 	subb	a,_toggle
      0001D6 E4               [12]  732 	clr	a
      0001D7 95 19            [12]  733 	subb	a,(_toggle + 1)
      0001D9 50 07            [24]  734 	jnc	00102$
                                    735 ;	main.c:111: toggle = 0;
      0001DB E4               [12]  736 	clr	a
      0001DC F5 18            [12]  737 	mov	_toggle,a
      0001DE F5 19            [12]  738 	mov	(_toggle + 1),a
      0001E0 80 0B            [24]  739 	sjmp	00103$
      0001E2                        740 00102$:
                                    741 ;	main.c:113: toggle++;
      0001E2 74 01            [12]  742 	mov	a,#0x01
      0001E4 25 18            [12]  743 	add	a,_toggle
      0001E6 F5 18            [12]  744 	mov	_toggle,a
      0001E8 E4               [12]  745 	clr	a
      0001E9 35 19            [12]  746 	addc	a,(_toggle + 1)
      0001EB F5 19            [12]  747 	mov	(_toggle + 1),a
      0001ED                        748 00103$:
                                    749 ;	main.c:115: TR0 = 1; /* start timer0 */
      0001ED D2 8C            [12]  750 	setb	_TR0
      0001EF D0 D0            [24]  751 	pop	psw
      0001F1 D0 E0            [24]  752 	pop	acc
      0001F3 32               [24]  753 	reti
                                    754 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    755 ;	eliminated unneeded push/pop dpl
                                    756 ;	eliminated unneeded push/pop dph
                                    757 ;	eliminated unneeded push/pop b
                                    758 ;------------------------------------------------------------
                                    759 ;Allocation info for local variables in function 'main'
                                    760 ;------------------------------------------------------------
                                    761 ;c                         Allocated with name '_main_c_1_30'
                                    762 ;------------------------------------------------------------
                                    763 ;	main.c:118: void main(void)
                                    764 ;	-----------------------------------------
                                    765 ;	 function main
                                    766 ;	-----------------------------------------
      0001F4                        767 _main:
                           000007   768 	ar7 = 0x07
                           000006   769 	ar6 = 0x06
                           000005   770 	ar5 = 0x05
                           000004   771 	ar4 = 0x04
                           000003   772 	ar3 = 0x03
                           000002   773 	ar2 = 0x02
                           000001   774 	ar1 = 0x01
                           000000   775 	ar0 = 0x00
                                    776 ;	main.c:122: P2 = val;
      0001F4 85 17 A0         [24]  777 	mov	_P2,_val
                                    778 ;	main.c:123: uart_init(115200UL);
      0001F7 90 C2 00         [24]  779 	mov	dptr,#0xC200
      0001FA 75 F0 01         [24]  780 	mov	b,#0x01
      0001FD E4               [12]  781 	clr	a
      0001FE 12 00 90         [24]  782 	lcall	_uart_init
                                    783 ;	main.c:124: timer0_init(100);
      000201 90 00 64         [24]  784 	mov	dptr,#0x0064
      000204 12 01 7E         [24]  785 	lcall	_timer0_init
                                    786 ;	main.c:125: EA = 1;
      000207 D2 AF            [12]  787 	setb	_EA
                                    788 ;	main.c:126: printf("build: %s %s\r\n", __TIME__, __DATE__);	
      000209 74 65            [12]  789 	mov	a,#___str_4
      00020B C0 E0            [24]  790 	push	acc
      00020D 74 09            [12]  791 	mov	a,#(___str_4 >> 8)
      00020F C0 E0            [24]  792 	push	acc
      000211 74 80            [12]  793 	mov	a,#0x80
      000213 C0 E0            [24]  794 	push	acc
      000215 74 5C            [12]  795 	mov	a,#___str_3
      000217 C0 E0            [24]  796 	push	acc
      000219 74 09            [12]  797 	mov	a,#(___str_3 >> 8)
      00021B C0 E0            [24]  798 	push	acc
      00021D 74 80            [12]  799 	mov	a,#0x80
      00021F C0 E0            [24]  800 	push	acc
      000221 74 4D            [12]  801 	mov	a,#___str_2
      000223 C0 E0            [24]  802 	push	acc
      000225 74 09            [12]  803 	mov	a,#(___str_2 >> 8)
      000227 C0 E0            [24]  804 	push	acc
      000229 74 80            [12]  805 	mov	a,#0x80
      00022B C0 E0            [24]  806 	push	acc
      00022D 12 03 2F         [24]  807 	lcall	_printf
      000230 E5 81            [12]  808 	mov	a,sp
      000232 24 F7            [12]  809 	add	a,#0xf7
      000234 F5 81            [12]  810 	mov	sp,a
                                    811 ;	main.c:127: while (1) {
      000236                        812 00102$:
      000236 80 FE            [24]  813 	sjmp	00102$
                                    814 	.area CSEG    (CODE)
                                    815 	.area CONST   (CODE)
      000948                        816 ___str_0:
      000948 25 63                  817 	.ascii "%c"
      00094A 00                     818 	.db 0x00
      00094B                        819 ___str_1:
      00094B 0A                     820 	.db 0x0A
      00094C 00                     821 	.db 0x00
      00094D                        822 ___str_2:
      00094D 62 75 69 6C 64 3A 20   823 	.ascii "build: %s %s"
             25 73 20 25 73
      000959 0D                     824 	.db 0x0D
      00095A 0A                     825 	.db 0x0A
      00095B 00                     826 	.db 0x00
      00095C                        827 ___str_3:
      00095C 31 39 3A 33 33 3A 32   828 	.ascii "19:33:20"
             30
      000964 00                     829 	.db 0x00
      000965                        830 ___str_4:
      000965 4D 61 72 20 20 39 20   831 	.ascii "Mar  9 2017"
             32 30 31 37
      000970 00                     832 	.db 0x00
                                    833 	.area XINIT   (CODE)
                                    834 	.area CABS    (ABS,CODE)
