                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module descriptors
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _USBDSCR
                                     12 	.globl _string_dscrs
                                     13 	.globl _dev_qual_dscr
                                     14 	.globl _fullspd_dscr
                                     15 	.globl _highspd_dscr
                                     16 	.globl _cfg_dscr_ptr
                                     17 	.globl _dev_dscr_ptr
                                     18 	.globl _str2_dscr
                                     19 	.globl _str1_dscr
                                     20 	.globl _str0_dscr
                                     21 	.globl _cfg_dscr
                                     22 	.globl _dev_dscr
                                     23 	.globl _EIPX6
                                     24 	.globl _EIPX5
                                     25 	.globl _EIPX4
                                     26 	.globl _PI2C
                                     27 	.globl _PUSB
                                     28 	.globl _EIEX6
                                     29 	.globl _EIEX5
                                     30 	.globl _EIEX4
                                     31 	.globl _EI2C
                                     32 	.globl _EUSB
                                     33 	.globl _SMOD1
                                     34 	.globl _ERESI
                                     35 	.globl _RESI
                                     36 	.globl _INT6
                                     37 	.globl _CY
                                     38 	.globl _AC
                                     39 	.globl _F0
                                     40 	.globl _RS1
                                     41 	.globl _RS0
                                     42 	.globl _OV
                                     43 	.globl _FL
                                     44 	.globl _P
                                     45 	.globl _TF2
                                     46 	.globl _EXF2
                                     47 	.globl _RCLK
                                     48 	.globl _TCLK
                                     49 	.globl _EXEN2
                                     50 	.globl _TR2
                                     51 	.globl _C_T2
                                     52 	.globl _CP_RL2
                                     53 	.globl _SM01
                                     54 	.globl _SM11
                                     55 	.globl _SM21
                                     56 	.globl _REN1
                                     57 	.globl _TB81
                                     58 	.globl _RB81
                                     59 	.globl _TI1
                                     60 	.globl _RI1
                                     61 	.globl _PS1
                                     62 	.globl _PT2
                                     63 	.globl _PS0
                                     64 	.globl _PT1
                                     65 	.globl _PX1
                                     66 	.globl _PT0
                                     67 	.globl _PX0
                                     68 	.globl _PD7
                                     69 	.globl _PD6
                                     70 	.globl _PD5
                                     71 	.globl _PD4
                                     72 	.globl _PD3
                                     73 	.globl _PD2
                                     74 	.globl _PD1
                                     75 	.globl _PD0
                                     76 	.globl _EA
                                     77 	.globl _ES1
                                     78 	.globl _ET2
                                     79 	.globl _ES0
                                     80 	.globl _ET1
                                     81 	.globl _EX1
                                     82 	.globl _ET0
                                     83 	.globl _EX0
                                     84 	.globl _PC7
                                     85 	.globl _PC6
                                     86 	.globl _PC5
                                     87 	.globl _PC4
                                     88 	.globl _PC3
                                     89 	.globl _PC2
                                     90 	.globl _PC1
                                     91 	.globl _PC0
                                     92 	.globl _SM0
                                     93 	.globl _SM1
                                     94 	.globl _SM2
                                     95 	.globl _REN
                                     96 	.globl _TB8
                                     97 	.globl _RB8
                                     98 	.globl _TI
                                     99 	.globl _RI
                                    100 	.globl _PB7
                                    101 	.globl _PB6
                                    102 	.globl _PB5
                                    103 	.globl _PB4
                                    104 	.globl _PB3
                                    105 	.globl _PB2
                                    106 	.globl _PB1
                                    107 	.globl _PB0
                                    108 	.globl _TF1
                                    109 	.globl _TR1
                                    110 	.globl _TF0
                                    111 	.globl _TR0
                                    112 	.globl _IE1
                                    113 	.globl _IT1
                                    114 	.globl _IE0
                                    115 	.globl _IT0
                                    116 	.globl _PA7
                                    117 	.globl _PA6
                                    118 	.globl _PA5
                                    119 	.globl _PA4
                                    120 	.globl _PA3
                                    121 	.globl _PA2
                                    122 	.globl _PA1
                                    123 	.globl _PA0
                                    124 	.globl _EIP
                                    125 	.globl _B
                                    126 	.globl _EIE
                                    127 	.globl _ACC
                                    128 	.globl _EICON
                                    129 	.globl _PSW
                                    130 	.globl _TH2
                                    131 	.globl _TL2
                                    132 	.globl _RCAP2H
                                    133 	.globl _RCAP2L
                                    134 	.globl _T2CON
                                    135 	.globl _SBUF1
                                    136 	.globl _SCON1
                                    137 	.globl _GPIFSGLDATLNOX
                                    138 	.globl _GPIFSGLDATLX
                                    139 	.globl _GPIFSGLDATH
                                    140 	.globl _GPIFTRIG
                                    141 	.globl _EP01STAT
                                    142 	.globl _IP
                                    143 	.globl _OEE
                                    144 	.globl _OED
                                    145 	.globl _OEC
                                    146 	.globl _OEB
                                    147 	.globl _OEA
                                    148 	.globl _IOE
                                    149 	.globl _IOD
                                    150 	.globl _AUTOPTRSETUP
                                    151 	.globl _EP68FIFOFLGS
                                    152 	.globl _EP24FIFOFLGS
                                    153 	.globl _EP2468STAT
                                    154 	.globl _IE
                                    155 	.globl _INT4CLR
                                    156 	.globl _INT2CLR
                                    157 	.globl _IOC
                                    158 	.globl _AUTOPTRL2
                                    159 	.globl _AUTOPTRH2
                                    160 	.globl _AUTOPTRL1
                                    161 	.globl _AUTOPTRH1
                                    162 	.globl _SBUF0
                                    163 	.globl _SCON0
                                    164 	.globl __XPAGE
                                    165 	.globl _EXIF
                                    166 	.globl _IOB
                                    167 	.globl _CKCON
                                    168 	.globl _TH1
                                    169 	.globl _TH0
                                    170 	.globl _TL1
                                    171 	.globl _TL0
                                    172 	.globl _TMOD
                                    173 	.globl _TCON
                                    174 	.globl _PCON
                                    175 	.globl _DPS
                                    176 	.globl _DPH1
                                    177 	.globl _DPL1
                                    178 	.globl _DPH
                                    179 	.globl _DPL
                                    180 	.globl _SP
                                    181 	.globl _IOA
                                    182 	.globl _GPCR2
                                    183 	.globl _ECC2B2
                                    184 	.globl _ECC2B1
                                    185 	.globl _ECC2B0
                                    186 	.globl _ECC1B2
                                    187 	.globl _ECC1B1
                                    188 	.globl _ECC1B0
                                    189 	.globl _ECCRESET
                                    190 	.globl _ECCCFG
                                    191 	.globl _EP8FIFOBUF
                                    192 	.globl _EP6FIFOBUF
                                    193 	.globl _EP4FIFOBUF
                                    194 	.globl _EP2FIFOBUF
                                    195 	.globl _EP1INBUF
                                    196 	.globl _EP1OUTBUF
                                    197 	.globl _EP0BUF
                                    198 	.globl _UDMACRCQUAL
                                    199 	.globl _UDMACRCL
                                    200 	.globl _UDMACRCH
                                    201 	.globl _GPIFHOLDAMOUNT
                                    202 	.globl _FLOWSTBHPERIOD
                                    203 	.globl _FLOWSTBEDGE
                                    204 	.globl _FLOWSTB
                                    205 	.globl _FLOWHOLDOFF
                                    206 	.globl _FLOWEQ1CTL
                                    207 	.globl _FLOWEQ0CTL
                                    208 	.globl _FLOWLOGIC
                                    209 	.globl _FLOWSTATE
                                    210 	.globl _GPIFABORT
                                    211 	.globl _GPIFREADYSTAT
                                    212 	.globl _GPIFREADYCFG
                                    213 	.globl _XGPIFSGLDATLNOX
                                    214 	.globl _XGPIFSGLDATLX
                                    215 	.globl _XGPIFSGLDATH
                                    216 	.globl _EP8GPIFTRIG
                                    217 	.globl _EP8GPIFPFSTOP
                                    218 	.globl _EP8GPIFFLGSEL
                                    219 	.globl _EP6GPIFTRIG
                                    220 	.globl _EP6GPIFPFSTOP
                                    221 	.globl _EP6GPIFFLGSEL
                                    222 	.globl _EP4GPIFTRIG
                                    223 	.globl _EP4GPIFPFSTOP
                                    224 	.globl _EP4GPIFFLGSEL
                                    225 	.globl _EP2GPIFTRIG
                                    226 	.globl _EP2GPIFPFSTOP
                                    227 	.globl _EP2GPIFFLGSEL
                                    228 	.globl _GPIFTCB0
                                    229 	.globl _GPIFTCB1
                                    230 	.globl _GPIFTCB2
                                    231 	.globl _GPIFTCB3
                                    232 	.globl _GPIFADRL
                                    233 	.globl _GPIFADRH
                                    234 	.globl _GPIFCTLCFG
                                    235 	.globl _GPIFIDLECTL
                                    236 	.globl _GPIFIDLECS
                                    237 	.globl _GPIFWFSELECT
                                    238 	.globl _SETUPDAT
                                    239 	.globl _SUDPTRCTL
                                    240 	.globl _SUDPTRL
                                    241 	.globl _SUDPTRH
                                    242 	.globl _EP8FIFOBCL
                                    243 	.globl _EP8FIFOBCH
                                    244 	.globl _EP6FIFOBCL
                                    245 	.globl _EP6FIFOBCH
                                    246 	.globl _EP4FIFOBCL
                                    247 	.globl _EP4FIFOBCH
                                    248 	.globl _EP2FIFOBCL
                                    249 	.globl _EP2FIFOBCH
                                    250 	.globl _EP8FIFOFLGS
                                    251 	.globl _EP6FIFOFLGS
                                    252 	.globl _EP4FIFOFLGS
                                    253 	.globl _EP2FIFOFLGS
                                    254 	.globl _EP8CS
                                    255 	.globl _EP6CS
                                    256 	.globl _EP4CS
                                    257 	.globl _EP2CS
                                    258 	.globl _EP1INCS
                                    259 	.globl _EP1OUTCS
                                    260 	.globl _EP0CS
                                    261 	.globl _EP8BCL
                                    262 	.globl _EP8BCH
                                    263 	.globl _EP6BCL
                                    264 	.globl _EP6BCH
                                    265 	.globl _EP4BCL
                                    266 	.globl _EP4BCH
                                    267 	.globl _EP2BCL
                                    268 	.globl _EP2BCH
                                    269 	.globl _EP1INBC
                                    270 	.globl _EP1OUTBC
                                    271 	.globl _EP0BCL
                                    272 	.globl _EP0BCH
                                    273 	.globl _FNADDR
                                    274 	.globl _MICROFRAME
                                    275 	.globl _USBFRAMEL
                                    276 	.globl _USBFRAMEH
                                    277 	.globl _TOGCTL
                                    278 	.globl _WAKEUPCS
                                    279 	.globl _SUSPEND
                                    280 	.globl _USBCS
                                    281 	.globl _XAUTODAT2
                                    282 	.globl _XAUTODAT1
                                    283 	.globl _I2CTL
                                    284 	.globl _I2DAT
                                    285 	.globl _I2CS
                                    286 	.globl _PORTECFG
                                    287 	.globl _PORTCCFG
                                    288 	.globl _PORTACFG
                                    289 	.globl _INTSETUP
                                    290 	.globl _INT4IVEC
                                    291 	.globl _INT2IVEC
                                    292 	.globl _CLRERRCNT
                                    293 	.globl _ERRCNTLIM
                                    294 	.globl _USBERRIRQ
                                    295 	.globl _USBERRIE
                                    296 	.globl _GPIFIRQ
                                    297 	.globl _GPIFIE
                                    298 	.globl _EPIRQ
                                    299 	.globl _EPIE
                                    300 	.globl _USBIRQ
                                    301 	.globl _USBIE
                                    302 	.globl _NAKIRQ
                                    303 	.globl _NAKIE
                                    304 	.globl _IBNIRQ
                                    305 	.globl _IBNIE
                                    306 	.globl _EP8FIFOIRQ
                                    307 	.globl _EP8FIFOIE
                                    308 	.globl _EP6FIFOIRQ
                                    309 	.globl _EP6FIFOIE
                                    310 	.globl _EP4FIFOIRQ
                                    311 	.globl _EP4FIFOIE
                                    312 	.globl _EP2FIFOIRQ
                                    313 	.globl _EP2FIFOIE
                                    314 	.globl _OUTPKTEND
                                    315 	.globl _INPKTEND
                                    316 	.globl _EP8ISOINPKTS
                                    317 	.globl _EP6ISOINPKTS
                                    318 	.globl _EP4ISOINPKTS
                                    319 	.globl _EP2ISOINPKTS
                                    320 	.globl _EP8FIFOPFL
                                    321 	.globl _EP8FIFOPFH
                                    322 	.globl _EP6FIFOPFL
                                    323 	.globl _EP6FIFOPFH
                                    324 	.globl _EP4FIFOPFL
                                    325 	.globl _EP4FIFOPFH
                                    326 	.globl _EP2FIFOPFL
                                    327 	.globl _EP2FIFOPFH
                                    328 	.globl _EP8AUTOINLENL
                                    329 	.globl _EP8AUTOINLENH
                                    330 	.globl _EP6AUTOINLENL
                                    331 	.globl _EP6AUTOINLENH
                                    332 	.globl _EP4AUTOINLENL
                                    333 	.globl _EP4AUTOINLENH
                                    334 	.globl _EP2AUTOINLENL
                                    335 	.globl _EP2AUTOINLENH
                                    336 	.globl _EP8FIFOCFG
                                    337 	.globl _EP6FIFOCFG
                                    338 	.globl _EP4FIFOCFG
                                    339 	.globl _EP2FIFOCFG
                                    340 	.globl _EP8CFG
                                    341 	.globl _EP6CFG
                                    342 	.globl _EP4CFG
                                    343 	.globl _EP2CFG
                                    344 	.globl _EP1INCFG
                                    345 	.globl _EP1OUTCFG
                                    346 	.globl _REVCTL
                                    347 	.globl _REVID
                                    348 	.globl _FIFOPINPOLAR
                                    349 	.globl _UART230
                                    350 	.globl _BPADDRL
                                    351 	.globl _BPADDRH
                                    352 	.globl _BREAKPT
                                    353 	.globl _FIFORESET
                                    354 	.globl _PINFLAGSCD
                                    355 	.globl _PINFLAGSAB
                                    356 	.globl _IFCONFIG
                                    357 	.globl _CPUCS
                                    358 	.globl _RES_WAVEDATA_END
                                    359 	.globl _GPIF_WAVE_DATA
                                    360 ;--------------------------------------------------------
                                    361 ; special function registers
                                    362 ;--------------------------------------------------------
                                    363 	.area RSEG    (ABS,DATA)
      000000                        364 	.org 0x0000
                           000080   365 _IOA	=	0x0080
                           000081   366 _SP	=	0x0081
                           000082   367 _DPL	=	0x0082
                           000083   368 _DPH	=	0x0083
                           000084   369 _DPL1	=	0x0084
                           000085   370 _DPH1	=	0x0085
                           000086   371 _DPS	=	0x0086
                           000087   372 _PCON	=	0x0087
                           000088   373 _TCON	=	0x0088
                           000089   374 _TMOD	=	0x0089
                           00008A   375 _TL0	=	0x008a
                           00008B   376 _TL1	=	0x008b
                           00008C   377 _TH0	=	0x008c
                           00008D   378 _TH1	=	0x008d
                           00008E   379 _CKCON	=	0x008e
                           000090   380 _IOB	=	0x0090
                           000091   381 _EXIF	=	0x0091
                           000092   382 __XPAGE	=	0x0092
                           000098   383 _SCON0	=	0x0098
                           000099   384 _SBUF0	=	0x0099
                           00009A   385 _AUTOPTRH1	=	0x009a
                           00009B   386 _AUTOPTRL1	=	0x009b
                           00009D   387 _AUTOPTRH2	=	0x009d
                           00009E   388 _AUTOPTRL2	=	0x009e
                           0000A0   389 _IOC	=	0x00a0
                           0000A1   390 _INT2CLR	=	0x00a1
                           0000A2   391 _INT4CLR	=	0x00a2
                           0000A8   392 _IE	=	0x00a8
                           0000AA   393 _EP2468STAT	=	0x00aa
                           0000AB   394 _EP24FIFOFLGS	=	0x00ab
                           0000AC   395 _EP68FIFOFLGS	=	0x00ac
                           0000AF   396 _AUTOPTRSETUP	=	0x00af
                           0000B0   397 _IOD	=	0x00b0
                           0000B1   398 _IOE	=	0x00b1
                           0000B2   399 _OEA	=	0x00b2
                           0000B3   400 _OEB	=	0x00b3
                           0000B4   401 _OEC	=	0x00b4
                           0000B5   402 _OED	=	0x00b5
                           0000B6   403 _OEE	=	0x00b6
                           0000B8   404 _IP	=	0x00b8
                           0000BA   405 _EP01STAT	=	0x00ba
                           0000BB   406 _GPIFTRIG	=	0x00bb
                           0000BD   407 _GPIFSGLDATH	=	0x00bd
                           0000BE   408 _GPIFSGLDATLX	=	0x00be
                           0000BF   409 _GPIFSGLDATLNOX	=	0x00bf
                           0000C0   410 _SCON1	=	0x00c0
                           0000C1   411 _SBUF1	=	0x00c1
                           0000C8   412 _T2CON	=	0x00c8
                           0000CA   413 _RCAP2L	=	0x00ca
                           0000CB   414 _RCAP2H	=	0x00cb
                           0000CC   415 _TL2	=	0x00cc
                           0000CD   416 _TH2	=	0x00cd
                           0000D0   417 _PSW	=	0x00d0
                           0000D8   418 _EICON	=	0x00d8
                           0000E0   419 _ACC	=	0x00e0
                           0000E8   420 _EIE	=	0x00e8
                           0000F0   421 _B	=	0x00f0
                           0000F8   422 _EIP	=	0x00f8
                                    423 ;--------------------------------------------------------
                                    424 ; special function bits
                                    425 ;--------------------------------------------------------
                                    426 	.area RSEG    (ABS,DATA)
      000000                        427 	.org 0x0000
                           000080   428 _PA0	=	0x0080
                           000081   429 _PA1	=	0x0081
                           000082   430 _PA2	=	0x0082
                           000083   431 _PA3	=	0x0083
                           000084   432 _PA4	=	0x0084
                           000085   433 _PA5	=	0x0085
                           000086   434 _PA6	=	0x0086
                           000087   435 _PA7	=	0x0087
                           000088   436 _IT0	=	0x0088
                           000089   437 _IE0	=	0x0089
                           00008A   438 _IT1	=	0x008a
                           00008B   439 _IE1	=	0x008b
                           00008C   440 _TR0	=	0x008c
                           00008D   441 _TF0	=	0x008d
                           00008E   442 _TR1	=	0x008e
                           00008F   443 _TF1	=	0x008f
                           000090   444 _PB0	=	0x0090
                           000091   445 _PB1	=	0x0091
                           000092   446 _PB2	=	0x0092
                           000093   447 _PB3	=	0x0093
                           000094   448 _PB4	=	0x0094
                           000095   449 _PB5	=	0x0095
                           000096   450 _PB6	=	0x0096
                           000097   451 _PB7	=	0x0097
                           000098   452 _RI	=	0x0098
                           000099   453 _TI	=	0x0099
                           00009A   454 _RB8	=	0x009a
                           00009B   455 _TB8	=	0x009b
                           00009C   456 _REN	=	0x009c
                           00009D   457 _SM2	=	0x009d
                           00009E   458 _SM1	=	0x009e
                           00009F   459 _SM0	=	0x009f
                           0000A0   460 _PC0	=	0x00a0
                           0000A1   461 _PC1	=	0x00a1
                           0000A2   462 _PC2	=	0x00a2
                           0000A3   463 _PC3	=	0x00a3
                           0000A4   464 _PC4	=	0x00a4
                           0000A5   465 _PC5	=	0x00a5
                           0000A6   466 _PC6	=	0x00a6
                           0000A7   467 _PC7	=	0x00a7
                           0000A8   468 _EX0	=	0x00a8
                           0000A9   469 _ET0	=	0x00a9
                           0000AA   470 _EX1	=	0x00aa
                           0000AB   471 _ET1	=	0x00ab
                           0000AC   472 _ES0	=	0x00ac
                           0000AD   473 _ET2	=	0x00ad
                           0000AE   474 _ES1	=	0x00ae
                           0000AF   475 _EA	=	0x00af
                           0000B0   476 _PD0	=	0x00b0
                           0000B1   477 _PD1	=	0x00b1
                           0000B2   478 _PD2	=	0x00b2
                           0000B3   479 _PD3	=	0x00b3
                           0000B4   480 _PD4	=	0x00b4
                           0000B5   481 _PD5	=	0x00b5
                           0000B6   482 _PD6	=	0x00b6
                           0000B7   483 _PD7	=	0x00b7
                           0000B8   484 _PX0	=	0x00b8
                           0000B9   485 _PT0	=	0x00b9
                           0000BA   486 _PX1	=	0x00ba
                           0000BB   487 _PT1	=	0x00bb
                           0000BC   488 _PS0	=	0x00bc
                           0000BD   489 _PT2	=	0x00bd
                           0000BE   490 _PS1	=	0x00be
                           0000C0   491 _RI1	=	0x00c0
                           0000C1   492 _TI1	=	0x00c1
                           0000C2   493 _RB81	=	0x00c2
                           0000C3   494 _TB81	=	0x00c3
                           0000C4   495 _REN1	=	0x00c4
                           0000C5   496 _SM21	=	0x00c5
                           0000C6   497 _SM11	=	0x00c6
                           0000C7   498 _SM01	=	0x00c7
                           0000C8   499 _CP_RL2	=	0x00c8
                           0000C9   500 _C_T2	=	0x00c9
                           0000CA   501 _TR2	=	0x00ca
                           0000CB   502 _EXEN2	=	0x00cb
                           0000CC   503 _TCLK	=	0x00cc
                           0000CD   504 _RCLK	=	0x00cd
                           0000CE   505 _EXF2	=	0x00ce
                           0000CF   506 _TF2	=	0x00cf
                           0000D0   507 _P	=	0x00d0
                           0000D1   508 _FL	=	0x00d1
                           0000D2   509 _OV	=	0x00d2
                           0000D3   510 _RS0	=	0x00d3
                           0000D4   511 _RS1	=	0x00d4
                           0000D5   512 _F0	=	0x00d5
                           0000D6   513 _AC	=	0x00d6
                           0000D7   514 _CY	=	0x00d7
                           0000DB   515 _INT6	=	0x00db
                           0000DC   516 _RESI	=	0x00dc
                           0000DD   517 _ERESI	=	0x00dd
                           0000DF   518 _SMOD1	=	0x00df
                           0000E8   519 _EUSB	=	0x00e8
                           0000E9   520 _EI2C	=	0x00e9
                           0000EA   521 _EIEX4	=	0x00ea
                           0000EB   522 _EIEX5	=	0x00eb
                           0000EC   523 _EIEX6	=	0x00ec
                           0000F8   524 _PUSB	=	0x00f8
                           0000F9   525 _PI2C	=	0x00f9
                           0000FA   526 _EIPX4	=	0x00fa
                           0000FB   527 _EIPX5	=	0x00fb
                           0000FC   528 _EIPX6	=	0x00fc
                                    529 ;--------------------------------------------------------
                                    530 ; overlayable register banks
                                    531 ;--------------------------------------------------------
                                    532 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        533 	.ds 8
                                    534 ;--------------------------------------------------------
                                    535 ; internal ram data
                                    536 ;--------------------------------------------------------
                                    537 	.area DSEG    (DATA)
                                    538 ;--------------------------------------------------------
                                    539 ; overlayable items in internal ram
                                    540 ;--------------------------------------------------------
                                    541 ;--------------------------------------------------------
                                    542 ; indirectly addressable internal ram data
                                    543 ;--------------------------------------------------------
                                    544 	.area ISEG    (DATA)
                                    545 ;--------------------------------------------------------
                                    546 ; absolute internal ram data
                                    547 ;--------------------------------------------------------
                                    548 	.area IABS    (ABS,DATA)
                                    549 	.area IABS    (ABS,DATA)
                                    550 ;--------------------------------------------------------
                                    551 ; bit data
                                    552 ;--------------------------------------------------------
                                    553 	.area BSEG    (BIT)
                                    554 ;--------------------------------------------------------
                                    555 ; paged external ram data
                                    556 ;--------------------------------------------------------
                                    557 	.area PSEG    (PAG,XDATA)
                                    558 ;--------------------------------------------------------
                                    559 ; uninitialized external ram data
                                    560 ;--------------------------------------------------------
                                    561 	.area XSEG    (XDATA)
                           00E400   562 _GPIF_WAVE_DATA	=	0xe400
                           00E480   563 _RES_WAVEDATA_END	=	0xe480
                           00E600   564 _CPUCS	=	0xe600
                           00E601   565 _IFCONFIG	=	0xe601
                           00E602   566 _PINFLAGSAB	=	0xe602
                           00E603   567 _PINFLAGSCD	=	0xe603
                           00E604   568 _FIFORESET	=	0xe604
                           00E605   569 _BREAKPT	=	0xe605
                           00E606   570 _BPADDRH	=	0xe606
                           00E607   571 _BPADDRL	=	0xe607
                           00E608   572 _UART230	=	0xe608
                           00E609   573 _FIFOPINPOLAR	=	0xe609
                           00E60A   574 _REVID	=	0xe60a
                           00E60B   575 _REVCTL	=	0xe60b
                           00E610   576 _EP1OUTCFG	=	0xe610
                           00E611   577 _EP1INCFG	=	0xe611
                           00E612   578 _EP2CFG	=	0xe612
                           00E613   579 _EP4CFG	=	0xe613
                           00E614   580 _EP6CFG	=	0xe614
                           00E615   581 _EP8CFG	=	0xe615
                           00E618   582 _EP2FIFOCFG	=	0xe618
                           00E619   583 _EP4FIFOCFG	=	0xe619
                           00E61A   584 _EP6FIFOCFG	=	0xe61a
                           00E61B   585 _EP8FIFOCFG	=	0xe61b
                           00E620   586 _EP2AUTOINLENH	=	0xe620
                           00E621   587 _EP2AUTOINLENL	=	0xe621
                           00E622   588 _EP4AUTOINLENH	=	0xe622
                           00E623   589 _EP4AUTOINLENL	=	0xe623
                           00E624   590 _EP6AUTOINLENH	=	0xe624
                           00E625   591 _EP6AUTOINLENL	=	0xe625
                           00E626   592 _EP8AUTOINLENH	=	0xe626
                           00E627   593 _EP8AUTOINLENL	=	0xe627
                           00E630   594 _EP2FIFOPFH	=	0xe630
                           00E631   595 _EP2FIFOPFL	=	0xe631
                           00E632   596 _EP4FIFOPFH	=	0xe632
                           00E633   597 _EP4FIFOPFL	=	0xe633
                           00E634   598 _EP6FIFOPFH	=	0xe634
                           00E635   599 _EP6FIFOPFL	=	0xe635
                           00E636   600 _EP8FIFOPFH	=	0xe636
                           00E637   601 _EP8FIFOPFL	=	0xe637
                           00E640   602 _EP2ISOINPKTS	=	0xe640
                           00E641   603 _EP4ISOINPKTS	=	0xe641
                           00E642   604 _EP6ISOINPKTS	=	0xe642
                           00E643   605 _EP8ISOINPKTS	=	0xe643
                           00E648   606 _INPKTEND	=	0xe648
                           00E649   607 _OUTPKTEND	=	0xe649
                           00E650   608 _EP2FIFOIE	=	0xe650
                           00E651   609 _EP2FIFOIRQ	=	0xe651
                           00E652   610 _EP4FIFOIE	=	0xe652
                           00E653   611 _EP4FIFOIRQ	=	0xe653
                           00E654   612 _EP6FIFOIE	=	0xe654
                           00E655   613 _EP6FIFOIRQ	=	0xe655
                           00E656   614 _EP8FIFOIE	=	0xe656
                           00E657   615 _EP8FIFOIRQ	=	0xe657
                           00E658   616 _IBNIE	=	0xe658
                           00E659   617 _IBNIRQ	=	0xe659
                           00E65A   618 _NAKIE	=	0xe65a
                           00E65B   619 _NAKIRQ	=	0xe65b
                           00E65C   620 _USBIE	=	0xe65c
                           00E65D   621 _USBIRQ	=	0xe65d
                           00E65E   622 _EPIE	=	0xe65e
                           00E65F   623 _EPIRQ	=	0xe65f
                           00E660   624 _GPIFIE	=	0xe660
                           00E661   625 _GPIFIRQ	=	0xe661
                           00E662   626 _USBERRIE	=	0xe662
                           00E663   627 _USBERRIRQ	=	0xe663
                           00E664   628 _ERRCNTLIM	=	0xe664
                           00E665   629 _CLRERRCNT	=	0xe665
                           00E666   630 _INT2IVEC	=	0xe666
                           00E667   631 _INT4IVEC	=	0xe667
                           00E668   632 _INTSETUP	=	0xe668
                           00E670   633 _PORTACFG	=	0xe670
                           00E671   634 _PORTCCFG	=	0xe671
                           00E672   635 _PORTECFG	=	0xe672
                           00E678   636 _I2CS	=	0xe678
                           00E679   637 _I2DAT	=	0xe679
                           00E67A   638 _I2CTL	=	0xe67a
                           00E67B   639 _XAUTODAT1	=	0xe67b
                           00E67C   640 _XAUTODAT2	=	0xe67c
                           00E680   641 _USBCS	=	0xe680
                           00E681   642 _SUSPEND	=	0xe681
                           00E682   643 _WAKEUPCS	=	0xe682
                           00E683   644 _TOGCTL	=	0xe683
                           00E684   645 _USBFRAMEH	=	0xe684
                           00E685   646 _USBFRAMEL	=	0xe685
                           00E686   647 _MICROFRAME	=	0xe686
                           00E687   648 _FNADDR	=	0xe687
                           00E68A   649 _EP0BCH	=	0xe68a
                           00E68B   650 _EP0BCL	=	0xe68b
                           00E68D   651 _EP1OUTBC	=	0xe68d
                           00E68F   652 _EP1INBC	=	0xe68f
                           00E690   653 _EP2BCH	=	0xe690
                           00E691   654 _EP2BCL	=	0xe691
                           00E694   655 _EP4BCH	=	0xe694
                           00E695   656 _EP4BCL	=	0xe695
                           00E698   657 _EP6BCH	=	0xe698
                           00E699   658 _EP6BCL	=	0xe699
                           00E69C   659 _EP8BCH	=	0xe69c
                           00E69D   660 _EP8BCL	=	0xe69d
                           00E6A0   661 _EP0CS	=	0xe6a0
                           00E6A1   662 _EP1OUTCS	=	0xe6a1
                           00E6A2   663 _EP1INCS	=	0xe6a2
                           00E6A3   664 _EP2CS	=	0xe6a3
                           00E6A4   665 _EP4CS	=	0xe6a4
                           00E6A5   666 _EP6CS	=	0xe6a5
                           00E6A6   667 _EP8CS	=	0xe6a6
                           00E6A7   668 _EP2FIFOFLGS	=	0xe6a7
                           00E6A8   669 _EP4FIFOFLGS	=	0xe6a8
                           00E6A9   670 _EP6FIFOFLGS	=	0xe6a9
                           00E6AA   671 _EP8FIFOFLGS	=	0xe6aa
                           00E6AB   672 _EP2FIFOBCH	=	0xe6ab
                           00E6AC   673 _EP2FIFOBCL	=	0xe6ac
                           00E6AD   674 _EP4FIFOBCH	=	0xe6ad
                           00E6AE   675 _EP4FIFOBCL	=	0xe6ae
                           00E6AF   676 _EP6FIFOBCH	=	0xe6af
                           00E6B0   677 _EP6FIFOBCL	=	0xe6b0
                           00E6B1   678 _EP8FIFOBCH	=	0xe6b1
                           00E6B2   679 _EP8FIFOBCL	=	0xe6b2
                           00E6B3   680 _SUDPTRH	=	0xe6b3
                           00E6B4   681 _SUDPTRL	=	0xe6b4
                           00E6B5   682 _SUDPTRCTL	=	0xe6b5
                           00E6B8   683 _SETUPDAT	=	0xe6b8
                           00E6C0   684 _GPIFWFSELECT	=	0xe6c0
                           00E6C1   685 _GPIFIDLECS	=	0xe6c1
                           00E6C2   686 _GPIFIDLECTL	=	0xe6c2
                           00E6C3   687 _GPIFCTLCFG	=	0xe6c3
                           00E6C4   688 _GPIFADRH	=	0xe6c4
                           00E6C5   689 _GPIFADRL	=	0xe6c5
                           00E6CE   690 _GPIFTCB3	=	0xe6ce
                           00E6CF   691 _GPIFTCB2	=	0xe6cf
                           00E6D0   692 _GPIFTCB1	=	0xe6d0
                           00E6D1   693 _GPIFTCB0	=	0xe6d1
                           00E6D2   694 _EP2GPIFFLGSEL	=	0xe6d2
                           00E6D3   695 _EP2GPIFPFSTOP	=	0xe6d3
                           00E6D4   696 _EP2GPIFTRIG	=	0xe6d4
                           00E6DA   697 _EP4GPIFFLGSEL	=	0xe6da
                           00E6DB   698 _EP4GPIFPFSTOP	=	0xe6db
                           00E6DC   699 _EP4GPIFTRIG	=	0xe6dc
                           00E6E2   700 _EP6GPIFFLGSEL	=	0xe6e2
                           00E6E3   701 _EP6GPIFPFSTOP	=	0xe6e3
                           00E6E4   702 _EP6GPIFTRIG	=	0xe6e4
                           00E6EA   703 _EP8GPIFFLGSEL	=	0xe6ea
                           00E6EB   704 _EP8GPIFPFSTOP	=	0xe6eb
                           00E6EC   705 _EP8GPIFTRIG	=	0xe6ec
                           00E6F0   706 _XGPIFSGLDATH	=	0xe6f0
                           00E6F1   707 _XGPIFSGLDATLX	=	0xe6f1
                           00E6F2   708 _XGPIFSGLDATLNOX	=	0xe6f2
                           00E6F3   709 _GPIFREADYCFG	=	0xe6f3
                           00E6F4   710 _GPIFREADYSTAT	=	0xe6f4
                           00E6F5   711 _GPIFABORT	=	0xe6f5
                           00E6C6   712 _FLOWSTATE	=	0xe6c6
                           00E6C7   713 _FLOWLOGIC	=	0xe6c7
                           00E6C8   714 _FLOWEQ0CTL	=	0xe6c8
                           00E6C9   715 _FLOWEQ1CTL	=	0xe6c9
                           00E6CA   716 _FLOWHOLDOFF	=	0xe6ca
                           00E6CB   717 _FLOWSTB	=	0xe6cb
                           00E6CC   718 _FLOWSTBEDGE	=	0xe6cc
                           00E6CD   719 _FLOWSTBHPERIOD	=	0xe6cd
                           00E60C   720 _GPIFHOLDAMOUNT	=	0xe60c
                           00E67D   721 _UDMACRCH	=	0xe67d
                           00E67E   722 _UDMACRCL	=	0xe67e
                           00E67F   723 _UDMACRCQUAL	=	0xe67f
                           00E740   724 _EP0BUF	=	0xe740
                           00E780   725 _EP1OUTBUF	=	0xe780
                           00E7C0   726 _EP1INBUF	=	0xe7c0
                           00F000   727 _EP2FIFOBUF	=	0xf000
                           00F400   728 _EP4FIFOBUF	=	0xf400
                           00F800   729 _EP6FIFOBUF	=	0xf800
                           00FC00   730 _EP8FIFOBUF	=	0xfc00
                           00E628   731 _ECCCFG	=	0xe628
                           00E629   732 _ECCRESET	=	0xe629
                           00E62A   733 _ECC1B0	=	0xe62a
                           00E62B   734 _ECC1B1	=	0xe62b
                           00E62C   735 _ECC1B2	=	0xe62c
                           00E62D   736 _ECC2B0	=	0xe62d
                           00E62E   737 _ECC2B1	=	0xe62e
                           00E62F   738 _ECC2B2	=	0xe62f
                           00E50D   739 _GPCR2	=	0xe50d
                                    740 ;--------------------------------------------------------
                                    741 ; absolute external ram data
                                    742 ;--------------------------------------------------------
                                    743 	.area XABS    (ABS,XDATA)
                                    744 ;--------------------------------------------------------
                                    745 ; initialized external ram data
                                    746 ;--------------------------------------------------------
                                    747 	.area XISEG   (XDATA)
                                    748 	.area HOME    (CODE)
                                    749 	.area GSINIT0 (CODE)
                                    750 	.area GSINIT1 (CODE)
                                    751 	.area GSINIT2 (CODE)
                                    752 	.area GSINIT3 (CODE)
                                    753 	.area GSINIT4 (CODE)
                                    754 	.area GSINIT5 (CODE)
                                    755 	.area GSINIT  (CODE)
                                    756 	.area GSFINAL (CODE)
                                    757 	.area CSEG    (CODE)
                                    758 ;--------------------------------------------------------
                                    759 ; global & static initialisations
                                    760 ;--------------------------------------------------------
                                    761 	.area HOME    (CODE)
                                    762 	.area GSINIT  (CODE)
                                    763 	.area GSFINAL (CODE)
                                    764 	.area GSINIT  (CODE)
                                    765 ;--------------------------------------------------------
                                    766 ; Home
                                    767 ;--------------------------------------------------------
                                    768 	.area HOME    (CODE)
                                    769 	.area HOME    (CODE)
                                    770 ;--------------------------------------------------------
                                    771 ; code
                                    772 ;--------------------------------------------------------
                                    773 	.area CSEG    (CODE)
                                    774 	.area CSEG    (CODE)
                                    775 	.area CONST   (CODE)
      00078E                        776 _dev_dscr:
      00078E 12                     777 	.db #0x12	; 18
      00078F 01                     778 	.db #0x01	; 1
      000790 00                     779 	.db #0x00	; 0
      000791 02                     780 	.db #0x02	; 2
      000792 FF                     781 	.db #0xff	; 255
      000793 00                     782 	.db #0x00	; 0
      000794 00                     783 	.db #0x00	; 0
      000795 40                     784 	.db #0x40	; 64
      000796 B4                     785 	.db #0xb4	; 180
      000797 04                     786 	.db #0x04	; 4
      000798 13                     787 	.db #0x13	; 19
      000799 86                     788 	.db #0x86	; 134
      00079A 00                     789 	.db #0x00	; 0
      00079B 01                     790 	.db #0x01	; 1
      00079C 01                     791 	.db #0x01	; 1
      00079D 02                     792 	.db #0x02	; 2
      00079E 00                     793 	.db #0x00	; 0
      00079F 01                     794 	.db #0x01	; 1
      0007A0                        795 _cfg_dscr:
      0007A0 09                     796 	.db #0x09	; 9
      0007A1 02                     797 	.db #0x02	; 2
      0007A2 19                     798 	.db #0x19	; 25
      0007A3 00                     799 	.db #0x00	; 0
      0007A4 01                     800 	.db #0x01	; 1
      0007A5 01                     801 	.db #0x01	; 1
      0007A6 00                     802 	.db #0x00	; 0
      0007A7 80                     803 	.db #0x80	; 128
      0007A8 32                     804 	.db #0x32	; 50	'2'
      0007A9 09                     805 	.db #0x09	; 9
      0007AA 04                     806 	.db #0x04	; 4
      0007AB 00                     807 	.db #0x00	; 0
      0007AC 00                     808 	.db #0x00	; 0
      0007AD 01                     809 	.db #0x01	; 1
      0007AE FF                     810 	.db #0xff	; 255
      0007AF 00                     811 	.db #0x00	; 0
      0007B0 00                     812 	.db #0x00	; 0
      0007B1 00                     813 	.db #0x00	; 0
      0007B2 07                     814 	.db #0x07	; 7
      0007B3 05                     815 	.db #0x05	; 5
      0007B4 86                     816 	.db #0x86	; 134
      0007B5 02                     817 	.db #0x02	; 2
      0007B6 00                     818 	.db #0x00	; 0
      0007B7 02                     819 	.db #0x02	; 2
      0007B8 00                     820 	.db #0x00	; 0
      0007B9                        821 _str0_dscr:
      0007B9 04                     822 	.db #0x04	; 4
      0007BA 03                     823 	.db #0x03	; 3
      0007BB 09                     824 	.db #0x09	; 9
      0007BC 04                     825 	.db #0x04	; 4
      0007BD                        826 _str1_dscr:
      0007BD 10                     827 	.db #0x10	; 16
      0007BE 03                     828 	.db #0x03	; 3
      0007BF 50                     829 	.db #0x50	; 80	'P'
      0007C0 00                     830 	.db #0x00	; 0
      0007C1 68                     831 	.db #0x68	; 104	'h'
      0007C2 00                     832 	.db #0x00	; 0
      0007C3 61                     833 	.db #0x61	; 97	'a'
      0007C4 00                     834 	.db #0x00	; 0
      0007C5 73                     835 	.db #0x73	; 115	's'
      0007C6 00                     836 	.db #0x00	; 0
      0007C7 65                     837 	.db #0x65	; 101	'e'
      0007C8 00                     838 	.db #0x00	; 0
      0007C9 4C                     839 	.db #0x4c	; 76	'L'
      0007CA 00                     840 	.db #0x00	; 0
      0007CB 6D                     841 	.db #0x6d	; 109	'm'
      0007CC 00                     842 	.db #0x00	; 0
      0007CD                        843 _str2_dscr:
      0007CD 12                     844 	.db #0x12	; 18
      0007CE 03                     845 	.db #0x03	; 3
      0007CF 46                     846 	.db #0x46	; 70	'F'
      0007D0 00                     847 	.db #0x00	; 0
      0007D1 58                     848 	.db #0x58	; 88	'X'
      0007D2 00                     849 	.db #0x00	; 0
      0007D3 32                     850 	.db #0x32	; 50	'2'
      0007D4 00                     851 	.db #0x00	; 0
      0007D5 20                     852 	.db #0x20	; 32
      0007D6 00                     853 	.db #0x00	; 0
      0007D7 53                     854 	.db #0x53	; 83	'S'
      0007D8 00                     855 	.db #0x00	; 0
      0007D9 74                     856 	.db #0x74	; 116	't'
      0007DA 00                     857 	.db #0x00	; 0
      0007DB 72                     858 	.db #0x72	; 114	'r'
      0007DC 00                     859 	.db #0x00	; 0
      0007DD 6D                     860 	.db #0x6d	; 109	'm'
      0007DE 00                     861 	.db #0x00	; 0
      0007DF                        862 _dev_dscr_ptr:
      0007DF 8E 07                  863 	.byte _dev_dscr, (_dev_dscr >> 8)
      0007E1                        864 _cfg_dscr_ptr:
      0007E1 A0 07                  865 	.byte _cfg_dscr, (_cfg_dscr >> 8)
      0007E3                        866 _highspd_dscr:
      0007E3 A0 07                  867 	.byte _cfg_dscr, (_cfg_dscr >> 8)
      0007E5                        868 _fullspd_dscr:
      0007E5 A0 07                  869 	.byte _cfg_dscr, (_cfg_dscr >> 8)
      0007E7                        870 _dev_qual_dscr:
      0007E7 00 00                  871 	.byte #0x00,#0x00
      0007E9                        872 _string_dscrs:
      0007E9 B9 07                  873 	.byte _str0_dscr, (_str0_dscr >> 8)
      0007EB BD 07                  874 	.byte _str1_dscr, (_str1_dscr >> 8)
      0007ED CD 07                  875 	.byte _str2_dscr, (_str2_dscr >> 8)
      0007EF                        876 _USBDSCR:
      0007EF 8E 07                  877 	.byte _dev_dscr, (_dev_dscr >> 8)
                                    878 	.area XINIT   (CODE)
                                    879 	.area CABS    (ABS,CODE)
