                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.5.0 #9253 (Mar 24 2016) (Linux)
                                      4 ; This file was generated Wed Mar  1 19:36:26 2017
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
                                     15 	.globl _P4_6
                                     16 	.globl _P4_5
                                     17 	.globl _P4_4
                                     18 	.globl _P4_3
                                     19 	.globl _P4_2
                                     20 	.globl _P4_1
                                     21 	.globl _P4_0
                                     22 	.globl _CY
                                     23 	.globl _AC
                                     24 	.globl _F0
                                     25 	.globl _RS1
                                     26 	.globl _RS0
                                     27 	.globl _OV
                                     28 	.globl _FL
                                     29 	.globl _P
                                     30 	.globl _TF2
                                     31 	.globl _EXF2
                                     32 	.globl _RCLK
                                     33 	.globl _TCLK
                                     34 	.globl _EXEN2
                                     35 	.globl _TR2
                                     36 	.globl _C_T2
                                     37 	.globl _CP_RL2
                                     38 	.globl _T2CON_7
                                     39 	.globl _T2CON_6
                                     40 	.globl _T2CON_5
                                     41 	.globl _T2CON_4
                                     42 	.globl _T2CON_3
                                     43 	.globl _T2CON_2
                                     44 	.globl _T2CON_1
                                     45 	.globl _T2CON_0
                                     46 	.globl _PT2
                                     47 	.globl _PS
                                     48 	.globl _PT1
                                     49 	.globl _PX1
                                     50 	.globl _PT0
                                     51 	.globl _PX0
                                     52 	.globl _RD
                                     53 	.globl _WR
                                     54 	.globl _T1
                                     55 	.globl _T0
                                     56 	.globl _INT1
                                     57 	.globl _INT0
                                     58 	.globl _TXD
                                     59 	.globl _RXD
                                     60 	.globl _P3_7
                                     61 	.globl _P3_6
                                     62 	.globl _P3_5
                                     63 	.globl _P3_4
                                     64 	.globl _P3_3
                                     65 	.globl _P3_2
                                     66 	.globl _P3_1
                                     67 	.globl _P3_0
                                     68 	.globl _EA
                                     69 	.globl _ET2
                                     70 	.globl _ES
                                     71 	.globl _ET1
                                     72 	.globl _EX1
                                     73 	.globl _ET0
                                     74 	.globl _EX0
                                     75 	.globl _P2_7
                                     76 	.globl _P2_6
                                     77 	.globl _P2_5
                                     78 	.globl _P2_4
                                     79 	.globl _P2_3
                                     80 	.globl _P2_2
                                     81 	.globl _P2_1
                                     82 	.globl _P2_0
                                     83 	.globl _SM0
                                     84 	.globl _SM1
                                     85 	.globl _SM2
                                     86 	.globl _REN
                                     87 	.globl _TB8
                                     88 	.globl _RB8
                                     89 	.globl _TI
                                     90 	.globl _RI
                                     91 	.globl _T2EX
                                     92 	.globl _T2
                                     93 	.globl _P1_7
                                     94 	.globl _P1_6
                                     95 	.globl _P1_5
                                     96 	.globl _P1_4
                                     97 	.globl _P1_3
                                     98 	.globl _P1_2
                                     99 	.globl _P1_1
                                    100 	.globl _P1_0
                                    101 	.globl _TF1
                                    102 	.globl _TR1
                                    103 	.globl _TF0
                                    104 	.globl _TR0
                                    105 	.globl _IE1
                                    106 	.globl _IT1
                                    107 	.globl _IE0
                                    108 	.globl _IT0
                                    109 	.globl _P0_7
                                    110 	.globl _P0_6
                                    111 	.globl _P0_5
                                    112 	.globl _P0_4
                                    113 	.globl _P0_3
                                    114 	.globl _P0_2
                                    115 	.globl _P0_1
                                    116 	.globl _P0_0
                                    117 	.globl _P4
                                    118 	.globl _ISP_CONTR
                                    119 	.globl _ISP_TRIG
                                    120 	.globl _ISP_CMD
                                    121 	.globl _ISP_ADDRL
                                    122 	.globl _ISP_ADDRH
                                    123 	.globl _ISP_DATA
                                    124 	.globl _WDT_CONTR
                                    125 	.globl _XICON
                                    126 	.globl _SADEN
                                    127 	.globl _IPH
                                    128 	.globl _SADDR
                                    129 	.globl _AUXR1
                                    130 	.globl _AUXR
                                    131 	.globl _B
                                    132 	.globl _A
                                    133 	.globl _ACC
                                    134 	.globl _PSW
                                    135 	.globl _TH2
                                    136 	.globl _TL2
                                    137 	.globl _RCAP2H
                                    138 	.globl _RCAP2L
                                    139 	.globl _T2MOD
                                    140 	.globl _T2CON
                                    141 	.globl _IP
                                    142 	.globl _P3
                                    143 	.globl _IE
                                    144 	.globl _P2
                                    145 	.globl _SBUF
                                    146 	.globl _SCON
                                    147 	.globl _P1
                                    148 	.globl _TH1
                                    149 	.globl _TH0
                                    150 	.globl _TL1
                                    151 	.globl _TL0
                                    152 	.globl _TMOD
                                    153 	.globl _TCON
                                    154 	.globl _PCON
                                    155 	.globl _DPH
                                    156 	.globl _DPL
                                    157 	.globl _SP
                                    158 	.globl _P0
                                    159 	.globl _toggle
                                    160 	.globl _val
                                    161 	.globl _t0_initval
                                    162 ;--------------------------------------------------------
                                    163 ; special function registers
                                    164 ;--------------------------------------------------------
                                    165 	.area RSEG    (ABS,DATA)
      000000                        166 	.org 0x0000
                           000080   167 _P0	=	0x0080
                           000081   168 _SP	=	0x0081
                           000082   169 _DPL	=	0x0082
                           000083   170 _DPH	=	0x0083
                           000087   171 _PCON	=	0x0087
                           000088   172 _TCON	=	0x0088
                           000089   173 _TMOD	=	0x0089
                           00008A   174 _TL0	=	0x008a
                           00008B   175 _TL1	=	0x008b
                           00008C   176 _TH0	=	0x008c
                           00008D   177 _TH1	=	0x008d
                           000090   178 _P1	=	0x0090
                           000098   179 _SCON	=	0x0098
                           000099   180 _SBUF	=	0x0099
                           0000A0   181 _P2	=	0x00a0
                           0000A8   182 _IE	=	0x00a8
                           0000B0   183 _P3	=	0x00b0
                           0000B8   184 _IP	=	0x00b8
                           0000C8   185 _T2CON	=	0x00c8
                           0000C9   186 _T2MOD	=	0x00c9
                           0000CA   187 _RCAP2L	=	0x00ca
                           0000CB   188 _RCAP2H	=	0x00cb
                           0000CC   189 _TL2	=	0x00cc
                           0000CD   190 _TH2	=	0x00cd
                           0000D0   191 _PSW	=	0x00d0
                           0000E0   192 _ACC	=	0x00e0
                           0000E0   193 _A	=	0x00e0
                           0000F0   194 _B	=	0x00f0
                           00008E   195 _AUXR	=	0x008e
                           0000A2   196 _AUXR1	=	0x00a2
                           0000A9   197 _SADDR	=	0x00a9
                           0000B7   198 _IPH	=	0x00b7
                           0000B9   199 _SADEN	=	0x00b9
                           0000C0   200 _XICON	=	0x00c0
                           0000E1   201 _WDT_CONTR	=	0x00e1
                           0000E2   202 _ISP_DATA	=	0x00e2
                           0000E3   203 _ISP_ADDRH	=	0x00e3
                           0000E4   204 _ISP_ADDRL	=	0x00e4
                           0000E5   205 _ISP_CMD	=	0x00e5
                           0000E6   206 _ISP_TRIG	=	0x00e6
                           0000E7   207 _ISP_CONTR	=	0x00e7
                           0000E8   208 _P4	=	0x00e8
                                    209 ;--------------------------------------------------------
                                    210 ; special function bits
                                    211 ;--------------------------------------------------------
                                    212 	.area RSEG    (ABS,DATA)
      000000                        213 	.org 0x0000
                           000080   214 _P0_0	=	0x0080
                           000081   215 _P0_1	=	0x0081
                           000082   216 _P0_2	=	0x0082
                           000083   217 _P0_3	=	0x0083
                           000084   218 _P0_4	=	0x0084
                           000085   219 _P0_5	=	0x0085
                           000086   220 _P0_6	=	0x0086
                           000087   221 _P0_7	=	0x0087
                           000088   222 _IT0	=	0x0088
                           000089   223 _IE0	=	0x0089
                           00008A   224 _IT1	=	0x008a
                           00008B   225 _IE1	=	0x008b
                           00008C   226 _TR0	=	0x008c
                           00008D   227 _TF0	=	0x008d
                           00008E   228 _TR1	=	0x008e
                           00008F   229 _TF1	=	0x008f
                           000090   230 _P1_0	=	0x0090
                           000091   231 _P1_1	=	0x0091
                           000092   232 _P1_2	=	0x0092
                           000093   233 _P1_3	=	0x0093
                           000094   234 _P1_4	=	0x0094
                           000095   235 _P1_5	=	0x0095
                           000096   236 _P1_6	=	0x0096
                           000097   237 _P1_7	=	0x0097
                           000090   238 _T2	=	0x0090
                           000091   239 _T2EX	=	0x0091
                           000098   240 _RI	=	0x0098
                           000099   241 _TI	=	0x0099
                           00009A   242 _RB8	=	0x009a
                           00009B   243 _TB8	=	0x009b
                           00009C   244 _REN	=	0x009c
                           00009D   245 _SM2	=	0x009d
                           00009E   246 _SM1	=	0x009e
                           00009F   247 _SM0	=	0x009f
                           0000A0   248 _P2_0	=	0x00a0
                           0000A1   249 _P2_1	=	0x00a1
                           0000A2   250 _P2_2	=	0x00a2
                           0000A3   251 _P2_3	=	0x00a3
                           0000A4   252 _P2_4	=	0x00a4
                           0000A5   253 _P2_5	=	0x00a5
                           0000A6   254 _P2_6	=	0x00a6
                           0000A7   255 _P2_7	=	0x00a7
                           0000A8   256 _EX0	=	0x00a8
                           0000A9   257 _ET0	=	0x00a9
                           0000AA   258 _EX1	=	0x00aa
                           0000AB   259 _ET1	=	0x00ab
                           0000AC   260 _ES	=	0x00ac
                           0000AD   261 _ET2	=	0x00ad
                           0000AF   262 _EA	=	0x00af
                           0000B0   263 _P3_0	=	0x00b0
                           0000B1   264 _P3_1	=	0x00b1
                           0000B2   265 _P3_2	=	0x00b2
                           0000B3   266 _P3_3	=	0x00b3
                           0000B4   267 _P3_4	=	0x00b4
                           0000B5   268 _P3_5	=	0x00b5
                           0000B6   269 _P3_6	=	0x00b6
                           0000B7   270 _P3_7	=	0x00b7
                           0000B0   271 _RXD	=	0x00b0
                           0000B1   272 _TXD	=	0x00b1
                           0000B2   273 _INT0	=	0x00b2
                           0000B3   274 _INT1	=	0x00b3
                           0000B4   275 _T0	=	0x00b4
                           0000B5   276 _T1	=	0x00b5
                           0000B6   277 _WR	=	0x00b6
                           0000B7   278 _RD	=	0x00b7
                           0000B8   279 _PX0	=	0x00b8
                           0000B9   280 _PT0	=	0x00b9
                           0000BA   281 _PX1	=	0x00ba
                           0000BB   282 _PT1	=	0x00bb
                           0000BC   283 _PS	=	0x00bc
                           0000BD   284 _PT2	=	0x00bd
                           0000C8   285 _T2CON_0	=	0x00c8
                           0000C9   286 _T2CON_1	=	0x00c9
                           0000CA   287 _T2CON_2	=	0x00ca
                           0000CB   288 _T2CON_3	=	0x00cb
                           0000CC   289 _T2CON_4	=	0x00cc
                           0000CD   290 _T2CON_5	=	0x00cd
                           0000CE   291 _T2CON_6	=	0x00ce
                           0000CF   292 _T2CON_7	=	0x00cf
                           0000C8   293 _CP_RL2	=	0x00c8
                           0000C9   294 _C_T2	=	0x00c9
                           0000CA   295 _TR2	=	0x00ca
                           0000CB   296 _EXEN2	=	0x00cb
                           0000CC   297 _TCLK	=	0x00cc
                           0000CD   298 _RCLK	=	0x00cd
                           0000CE   299 _EXF2	=	0x00ce
                           0000CF   300 _TF2	=	0x00cf
                           0000D0   301 _P	=	0x00d0
                           0000D1   302 _FL	=	0x00d1
                           0000D2   303 _OV	=	0x00d2
                           0000D3   304 _RS0	=	0x00d3
                           0000D4   305 _RS1	=	0x00d4
                           0000D5   306 _F0	=	0x00d5
                           0000D6   307 _AC	=	0x00d6
                           0000D7   308 _CY	=	0x00d7
                           0000E8   309 _P4_0	=	0x00e8
                           0000E9   310 _P4_1	=	0x00e9
                           0000EA   311 _P4_2	=	0x00ea
                           0000EB   312 _P4_3	=	0x00eb
                           0000EC   313 _P4_4	=	0x00ec
                           0000ED   314 _P4_5	=	0x00ed
                           0000EE   315 _P4_6	=	0x00ee
                                    316 ;--------------------------------------------------------
                                    317 ; overlayable register banks
                                    318 ;--------------------------------------------------------
                                    319 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        320 	.ds 8
                                    321 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        322 	.ds 8
                                    323 ;--------------------------------------------------------
                                    324 ; internal ram data
                                    325 ;--------------------------------------------------------
                                    326 	.area DSEG    (DATA)
      000010                        327 _t0_initval::
      000010                        328 	.ds 2
      000012                        329 _timer0_init_sloc0_1_0:
      000012                        330 	.ds 4
      000016                        331 _val::
      000016                        332 	.ds 1
      000017                        333 _toggle::
      000017                        334 	.ds 2
                                    335 ;--------------------------------------------------------
                                    336 ; overlayable items in internal ram 
                                    337 ;--------------------------------------------------------
                                    338 ;--------------------------------------------------------
                                    339 ; Stack segment in internal ram 
                                    340 ;--------------------------------------------------------
                                    341 	.area	SSEG
      00001D                        342 __start__stack:
      00001D                        343 	.ds	1
                                    344 
                                    345 ;--------------------------------------------------------
                                    346 ; indirectly addressable internal ram data
                                    347 ;--------------------------------------------------------
                                    348 	.area ISEG    (DATA)
                                    349 ;--------------------------------------------------------
                                    350 ; absolute internal ram data
                                    351 ;--------------------------------------------------------
                                    352 	.area IABS    (ABS,DATA)
                                    353 	.area IABS    (ABS,DATA)
                                    354 ;--------------------------------------------------------
                                    355 ; bit data
                                    356 ;--------------------------------------------------------
                                    357 	.area BSEG    (BIT)
                                    358 ;--------------------------------------------------------
                                    359 ; paged external ram data
                                    360 ;--------------------------------------------------------
                                    361 	.area PSEG    (PAG,XDATA)
                                    362 ;--------------------------------------------------------
                                    363 ; external ram data
                                    364 ;--------------------------------------------------------
                                    365 	.area XSEG    (XDATA)
                                    366 ;--------------------------------------------------------
                                    367 ; absolute external ram data
                                    368 ;--------------------------------------------------------
                                    369 	.area XABS    (ABS,XDATA)
                                    370 ;--------------------------------------------------------
                                    371 ; external initialized ram data
                                    372 ;--------------------------------------------------------
                                    373 	.area XISEG   (XDATA)
                                    374 	.area HOME    (CODE)
                                    375 	.area GSINIT0 (CODE)
                                    376 	.area GSINIT1 (CODE)
                                    377 	.area GSINIT2 (CODE)
                                    378 	.area GSINIT3 (CODE)
                                    379 	.area GSINIT4 (CODE)
                                    380 	.area GSINIT5 (CODE)
                                    381 	.area GSINIT  (CODE)
                                    382 	.area GSFINAL (CODE)
                                    383 	.area CSEG    (CODE)
                                    384 ;--------------------------------------------------------
                                    385 ; interrupt vector 
                                    386 ;--------------------------------------------------------
                                    387 	.area HOME    (CODE)
      000000                        388 __interrupt_vect:
      000000 02 00 11         [24]  389 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  390 	reti
      000004                        391 	.ds	7
      00000B 02 00 BC         [24]  392 	ljmp	_timer0_isr
                                    393 ;--------------------------------------------------------
                                    394 ; global & static initialisations
                                    395 ;--------------------------------------------------------
                                    396 	.area HOME    (CODE)
                                    397 	.area GSINIT  (CODE)
                                    398 	.area GSFINAL (CODE)
                                    399 	.area GSINIT  (CODE)
                                    400 	.globl __sdcc_gsinit_startup
                                    401 	.globl __sdcc_program_startup
                                    402 	.globl __start__stack
                                    403 	.globl __mcs51_genXINIT
                                    404 	.globl __mcs51_genXRAMCLEAR
                                    405 	.globl __mcs51_genRAMCLEAR
                                    406 ;	main.c:22: volatile unsigned char val = 0x55;
      00006A 75 16 55         [24]  407 	mov	_val,#0x55
                                    408 ;	main.c:24: volatile unsigned toggle = 0;
      00006D E4               [12]  409 	clr	a
      00006E F5 17            [12]  410 	mov	_toggle,a
      000070 F5 18            [12]  411 	mov	(_toggle + 1),a
                                    412 	.area GSFINAL (CODE)
      000072 02 00 0E         [24]  413 	ljmp	__sdcc_program_startup
                                    414 ;--------------------------------------------------------
                                    415 ; Home
                                    416 ;--------------------------------------------------------
                                    417 	.area HOME    (CODE)
                                    418 	.area HOME    (CODE)
      00000E                        419 __sdcc_program_startup:
      00000E 02 00 EB         [24]  420 	ljmp	_main
                                    421 ;	return from main will return to caller
                                    422 ;--------------------------------------------------------
                                    423 ; code
                                    424 ;--------------------------------------------------------
                                    425 	.area CSEG    (CODE)
                                    426 ;------------------------------------------------------------
                                    427 ;Allocation info for local variables in function 'timer0_init'
                                    428 ;------------------------------------------------------------
                                    429 ;ms                        Allocated to registers r6 r7 
                                    430 ;sloc0                     Allocated with name '_timer0_init_sloc0_1_0'
                                    431 ;------------------------------------------------------------
                                    432 ;	main.c:10: void timer0_init(unsigned ms)
                                    433 ;	-----------------------------------------
                                    434 ;	 function timer0_init
                                    435 ;	-----------------------------------------
      000075                        436 _timer0_init:
                           000007   437 	ar7 = 0x07
                           000006   438 	ar6 = 0x06
                           000005   439 	ar5 = 0x05
                           000004   440 	ar4 = 0x04
                           000003   441 	ar3 = 0x03
                           000002   442 	ar2 = 0x02
                           000001   443 	ar1 = 0x01
                           000000   444 	ar0 = 0x00
      000075 AE 82            [24]  445 	mov	r6,dpl
      000077 AF 83            [24]  446 	mov	r7,dph
                                    447 ;	main.c:12: TMOD &= 0xF0; /* set timer0 as mode 1, 16-bit timer/counter */
      000079 53 89 F0         [24]  448 	anl	_TMOD,#0xF0
                                    449 ;	main.c:13: TMOD |= 0x01;
      00007C 43 89 01         [24]  450 	orl	_TMOD,#0x01
                                    451 ;	main.c:15: TH0 = t0_initval[HI_BYTE] = (65536 - FCLK/1000/12 * ms - MAGIC) / 256;
      00007F 8E 19            [24]  452 	mov	__mullong_PARM_2,r6
      000081 8F 1A            [24]  453 	mov	(__mullong_PARM_2 + 1),r7
      000083 75 1B 00         [24]  454 	mov	(__mullong_PARM_2 + 2),#0x00
      000086 75 1C 00         [24]  455 	mov	(__mullong_PARM_2 + 3),#0x00
      000089 90 07 33         [24]  456 	mov	dptr,#0x0733
      00008C E4               [12]  457 	clr	a
      00008D F5 F0            [12]  458 	mov	b,a
      00008F 12 01 06         [24]  459 	lcall	__mullong
      000092 AC 82            [24]  460 	mov	r4,dpl
      000094 AD 83            [24]  461 	mov	r5,dph
      000096 AE F0            [24]  462 	mov	r6,b
      000098 FF               [12]  463 	mov	r7,a
      000099 E4               [12]  464 	clr	a
      00009A C3               [12]  465 	clr	c
      00009B 9C               [12]  466 	subb	a,r4
      00009C F5 12            [12]  467 	mov	_timer0_init_sloc0_1_0,a
      00009E E4               [12]  468 	clr	a
      00009F 9D               [12]  469 	subb	a,r5
      0000A0 F5 13            [12]  470 	mov	(_timer0_init_sloc0_1_0 + 1),a
      0000A2 74 01            [12]  471 	mov	a,#0x01
      0000A4 9E               [12]  472 	subb	a,r6
      0000A5 F5 14            [12]  473 	mov	(_timer0_init_sloc0_1_0 + 2),a
      0000A7 E4               [12]  474 	clr	a
      0000A8 9F               [12]  475 	subb	a,r7
      0000A9 F5 15            [12]  476 	mov	(_timer0_init_sloc0_1_0 + 3),a
      0000AB AA 13            [24]  477 	mov	r2,(_timer0_init_sloc0_1_0 + 1)
      0000AD 8A 10            [24]  478 	mov	_t0_initval,r2
      0000AF 8A 8C            [24]  479 	mov	_TH0,r2
                                    480 ;	main.c:16: TL0 = t0_initval[LO_BYTE] = (65536 - FCLK/1000/12 * ms - MAGIC) % 256;
      0000B1 AC 12            [24]  481 	mov	r4,_timer0_init_sloc0_1_0
      0000B3 8C 11            [24]  482 	mov	(_t0_initval + 0x0001),r4
      0000B5 8C 8A            [24]  483 	mov	_TL0,r4
                                    484 ;	main.c:18: ET0 = 1; /* enable timer0 interrupt */
      0000B7 D2 A9            [12]  485 	setb	_ET0
                                    486 ;	main.c:19: TR0 = 1; /* start timer0 */
      0000B9 D2 8C            [12]  487 	setb	_TR0
      0000BB 22               [24]  488 	ret
                                    489 ;------------------------------------------------------------
                                    490 ;Allocation info for local variables in function 'timer0_isr'
                                    491 ;------------------------------------------------------------
                                    492 ;	main.c:25: void timer0_isr(void) __interrupt (1) __using (1)
                                    493 ;	-----------------------------------------
                                    494 ;	 function timer0_isr
                                    495 ;	-----------------------------------------
      0000BC                        496 _timer0_isr:
                           00000F   497 	ar7 = 0x0F
                           00000E   498 	ar6 = 0x0E
                           00000D   499 	ar5 = 0x0D
                           00000C   500 	ar4 = 0x0C
                           00000B   501 	ar3 = 0x0B
                           00000A   502 	ar2 = 0x0A
                           000009   503 	ar1 = 0x09
                           000008   504 	ar0 = 0x08
      0000BC C0 E0            [24]  505 	push	acc
      0000BE C0 D0            [24]  506 	push	psw
                                    507 ;	main.c:27: TR0 = 0; /* stop timer0 */
      0000C0 C2 8C            [12]  508 	clr	_TR0
                                    509 ;	main.c:28: TH0 = t0_initval[HI_BYTE];
      0000C2 85 10 8C         [24]  510 	mov	_TH0,_t0_initval
                                    511 ;	main.c:29: TL0 = t0_initval[LO_BYTE]; /*
      0000C5 85 11 8A         [24]  512 	mov	_TL0,(_t0_initval + 0x0001)
                                    513 ;	main.c:37: if (toggle > 10)
      0000C8 C3               [12]  514 	clr	c
      0000C9 74 0A            [12]  515 	mov	a,#0x0A
      0000CB 95 17            [12]  516 	subb	a,_toggle
      0000CD E4               [12]  517 	clr	a
      0000CE 95 18            [12]  518 	subb	a,(_toggle + 1)
      0000D0 50 07            [24]  519 	jnc	00102$
                                    520 ;	main.c:38: toggle = 0;
      0000D2 E4               [12]  521 	clr	a
      0000D3 F5 17            [12]  522 	mov	_toggle,a
      0000D5 F5 18            [12]  523 	mov	(_toggle + 1),a
      0000D7 80 0B            [24]  524 	sjmp	00103$
      0000D9                        525 00102$:
                                    526 ;	main.c:40: toggle++;
      0000D9 74 01            [12]  527 	mov	a,#0x01
      0000DB 25 17            [12]  528 	add	a,_toggle
      0000DD F5 17            [12]  529 	mov	_toggle,a
      0000DF E4               [12]  530 	clr	a
      0000E0 35 18            [12]  531 	addc	a,(_toggle + 1)
      0000E2 F5 18            [12]  532 	mov	(_toggle + 1),a
      0000E4                        533 00103$:
                                    534 ;	main.c:42: TR0 = 1; /* start timer0 */
      0000E4 D2 8C            [12]  535 	setb	_TR0
      0000E6 D0 D0            [24]  536 	pop	psw
      0000E8 D0 E0            [24]  537 	pop	acc
      0000EA 32               [24]  538 	reti
                                    539 ;	eliminated unneeded mov psw,# (no regs used in bank)
                                    540 ;	eliminated unneeded push/pop dpl
                                    541 ;	eliminated unneeded push/pop dph
                                    542 ;	eliminated unneeded push/pop b
                                    543 ;------------------------------------------------------------
                                    544 ;Allocation info for local variables in function 'main'
                                    545 ;------------------------------------------------------------
                                    546 ;	main.c:45: void main(void)
                                    547 ;	-----------------------------------------
                                    548 ;	 function main
                                    549 ;	-----------------------------------------
      0000EB                        550 _main:
                           000007   551 	ar7 = 0x07
                           000006   552 	ar6 = 0x06
                           000005   553 	ar5 = 0x05
                           000004   554 	ar4 = 0x04
                           000003   555 	ar3 = 0x03
                           000002   556 	ar2 = 0x02
                           000001   557 	ar1 = 0x01
                           000000   558 	ar0 = 0x00
                                    559 ;	main.c:48: P2 = val;
      0000EB 85 16 A0         [24]  560 	mov	_P2,_val
                                    561 ;	main.c:49: timer0_init(100);
      0000EE 90 00 64         [24]  562 	mov	dptr,#0x0064
      0000F1 12 00 75         [24]  563 	lcall	_timer0_init
                                    564 ;	main.c:50: EA = 1;
      0000F4 D2 AF            [12]  565 	setb	_EA
                                    566 ;	main.c:52: while (1) {
      0000F6                        567 00104$:
                                    568 ;	main.c:53: if (!toggle) {
      0000F6 E5 17            [12]  569 	mov	a,_toggle
      0000F8 45 18            [12]  570 	orl	a,(_toggle + 1)
      0000FA 70 FA            [24]  571 	jnz	00104$
                                    572 ;	main.c:54: val = ~val;
      0000FC E5 16            [12]  573 	mov	a,_val
      0000FE F4               [12]  574 	cpl	a
      0000FF F5 16            [12]  575 	mov	_val,a
                                    576 ;	main.c:55: P2 = val;
      000101 85 16 A0         [24]  577 	mov	_P2,_val
      000104 80 F0            [24]  578 	sjmp	00104$
                                    579 	.area CSEG    (CODE)
                                    580 	.area CONST   (CODE)
                                    581 	.area XINIT   (CODE)
                                    582 	.area CABS    (ABS,CODE)
