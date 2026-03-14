                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module setup_callbacks
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _handle_set_interface_PARM_2
                                     12 	.globl _handle_get_interface_PARM_2
                                     13 	.globl _dev_strings
                                     14 	.globl _handle_reset_ep
                                     15 	.globl _handle_set_interface
                                     16 	.globl _handle_get_interface
                                     17 	.globl _handle_set_configuration
                                     18 	.globl _handle_get_configuration
                                     19 	.globl _handle_get_descriptor
                                     20 	.globl _EIPX6
                                     21 	.globl _EIPX5
                                     22 	.globl _EIPX4
                                     23 	.globl _PI2C
                                     24 	.globl _PUSB
                                     25 	.globl _EIEX6
                                     26 	.globl _EIEX5
                                     27 	.globl _EIEX4
                                     28 	.globl _EI2C
                                     29 	.globl _EUSB
                                     30 	.globl _SMOD1
                                     31 	.globl _ERESI
                                     32 	.globl _RESI
                                     33 	.globl _INT6
                                     34 	.globl _CY
                                     35 	.globl _AC
                                     36 	.globl _F0
                                     37 	.globl _RS1
                                     38 	.globl _RS0
                                     39 	.globl _OV
                                     40 	.globl _FL
                                     41 	.globl _P
                                     42 	.globl _TF2
                                     43 	.globl _EXF2
                                     44 	.globl _RCLK
                                     45 	.globl _TCLK
                                     46 	.globl _EXEN2
                                     47 	.globl _TR2
                                     48 	.globl _C_T2
                                     49 	.globl _CP_RL2
                                     50 	.globl _SM01
                                     51 	.globl _SM11
                                     52 	.globl _SM21
                                     53 	.globl _REN1
                                     54 	.globl _TB81
                                     55 	.globl _RB81
                                     56 	.globl _TI1
                                     57 	.globl _RI1
                                     58 	.globl _PS1
                                     59 	.globl _PT2
                                     60 	.globl _PS0
                                     61 	.globl _PT1
                                     62 	.globl _PX1
                                     63 	.globl _PT0
                                     64 	.globl _PX0
                                     65 	.globl _PD7
                                     66 	.globl _PD6
                                     67 	.globl _PD5
                                     68 	.globl _PD4
                                     69 	.globl _PD3
                                     70 	.globl _PD2
                                     71 	.globl _PD1
                                     72 	.globl _PD0
                                     73 	.globl _EA
                                     74 	.globl _ES1
                                     75 	.globl _ET2
                                     76 	.globl _ES0
                                     77 	.globl _ET1
                                     78 	.globl _EX1
                                     79 	.globl _ET0
                                     80 	.globl _EX0
                                     81 	.globl _PC7
                                     82 	.globl _PC6
                                     83 	.globl _PC5
                                     84 	.globl _PC4
                                     85 	.globl _PC3
                                     86 	.globl _PC2
                                     87 	.globl _PC1
                                     88 	.globl _PC0
                                     89 	.globl _SM0
                                     90 	.globl _SM1
                                     91 	.globl _SM2
                                     92 	.globl _REN
                                     93 	.globl _TB8
                                     94 	.globl _RB8
                                     95 	.globl _TI
                                     96 	.globl _RI
                                     97 	.globl _PB7
                                     98 	.globl _PB6
                                     99 	.globl _PB5
                                    100 	.globl _PB4
                                    101 	.globl _PB3
                                    102 	.globl _PB2
                                    103 	.globl _PB1
                                    104 	.globl _PB0
                                    105 	.globl _TF1
                                    106 	.globl _TR1
                                    107 	.globl _TF0
                                    108 	.globl _TR0
                                    109 	.globl _IE1
                                    110 	.globl _IT1
                                    111 	.globl _IE0
                                    112 	.globl _IT0
                                    113 	.globl _PA7
                                    114 	.globl _PA6
                                    115 	.globl _PA5
                                    116 	.globl _PA4
                                    117 	.globl _PA3
                                    118 	.globl _PA2
                                    119 	.globl _PA1
                                    120 	.globl _PA0
                                    121 	.globl _EIP
                                    122 	.globl _B
                                    123 	.globl _EIE
                                    124 	.globl _ACC
                                    125 	.globl _EICON
                                    126 	.globl _PSW
                                    127 	.globl _TH2
                                    128 	.globl _TL2
                                    129 	.globl _RCAP2H
                                    130 	.globl _RCAP2L
                                    131 	.globl _T2CON
                                    132 	.globl _SBUF1
                                    133 	.globl _SCON1
                                    134 	.globl _GPIFSGLDATLNOX
                                    135 	.globl _GPIFSGLDATLX
                                    136 	.globl _GPIFSGLDATH
                                    137 	.globl _GPIFTRIG
                                    138 	.globl _EP01STAT
                                    139 	.globl _IP
                                    140 	.globl _OEE
                                    141 	.globl _OED
                                    142 	.globl _OEC
                                    143 	.globl _OEB
                                    144 	.globl _OEA
                                    145 	.globl _IOE
                                    146 	.globl _IOD
                                    147 	.globl _AUTOPTRSETUP
                                    148 	.globl _EP68FIFOFLGS
                                    149 	.globl _EP24FIFOFLGS
                                    150 	.globl _EP2468STAT
                                    151 	.globl _IE
                                    152 	.globl _INT4CLR
                                    153 	.globl _INT2CLR
                                    154 	.globl _IOC
                                    155 	.globl _AUTOPTRL2
                                    156 	.globl _AUTOPTRH2
                                    157 	.globl _AUTOPTRL1
                                    158 	.globl _AUTOPTRH1
                                    159 	.globl _SBUF0
                                    160 	.globl _SCON0
                                    161 	.globl __XPAGE
                                    162 	.globl _EXIF
                                    163 	.globl _IOB
                                    164 	.globl _CKCON
                                    165 	.globl _TH1
                                    166 	.globl _TH0
                                    167 	.globl _TL1
                                    168 	.globl _TL0
                                    169 	.globl _TMOD
                                    170 	.globl _TCON
                                    171 	.globl _PCON
                                    172 	.globl _DPS
                                    173 	.globl _DPH1
                                    174 	.globl _DPL1
                                    175 	.globl _DPH
                                    176 	.globl _DPL
                                    177 	.globl _SP
                                    178 	.globl _IOA
                                    179 	.globl _GPCR2
                                    180 	.globl _ECC2B2
                                    181 	.globl _ECC2B1
                                    182 	.globl _ECC2B0
                                    183 	.globl _ECC1B2
                                    184 	.globl _ECC1B1
                                    185 	.globl _ECC1B0
                                    186 	.globl _ECCRESET
                                    187 	.globl _ECCCFG
                                    188 	.globl _EP8FIFOBUF
                                    189 	.globl _EP6FIFOBUF
                                    190 	.globl _EP4FIFOBUF
                                    191 	.globl _EP2FIFOBUF
                                    192 	.globl _EP1INBUF
                                    193 	.globl _EP1OUTBUF
                                    194 	.globl _EP0BUF
                                    195 	.globl _UDMACRCQUAL
                                    196 	.globl _UDMACRCL
                                    197 	.globl _UDMACRCH
                                    198 	.globl _GPIFHOLDAMOUNT
                                    199 	.globl _FLOWSTBHPERIOD
                                    200 	.globl _FLOWSTBEDGE
                                    201 	.globl _FLOWSTB
                                    202 	.globl _FLOWHOLDOFF
                                    203 	.globl _FLOWEQ1CTL
                                    204 	.globl _FLOWEQ0CTL
                                    205 	.globl _FLOWLOGIC
                                    206 	.globl _FLOWSTATE
                                    207 	.globl _GPIFABORT
                                    208 	.globl _GPIFREADYSTAT
                                    209 	.globl _GPIFREADYCFG
                                    210 	.globl _XGPIFSGLDATLNOX
                                    211 	.globl _XGPIFSGLDATLX
                                    212 	.globl _XGPIFSGLDATH
                                    213 	.globl _EP8GPIFTRIG
                                    214 	.globl _EP8GPIFPFSTOP
                                    215 	.globl _EP8GPIFFLGSEL
                                    216 	.globl _EP6GPIFTRIG
                                    217 	.globl _EP6GPIFPFSTOP
                                    218 	.globl _EP6GPIFFLGSEL
                                    219 	.globl _EP4GPIFTRIG
                                    220 	.globl _EP4GPIFPFSTOP
                                    221 	.globl _EP4GPIFFLGSEL
                                    222 	.globl _EP2GPIFTRIG
                                    223 	.globl _EP2GPIFPFSTOP
                                    224 	.globl _EP2GPIFFLGSEL
                                    225 	.globl _GPIFTCB0
                                    226 	.globl _GPIFTCB1
                                    227 	.globl _GPIFTCB2
                                    228 	.globl _GPIFTCB3
                                    229 	.globl _GPIFADRL
                                    230 	.globl _GPIFADRH
                                    231 	.globl _GPIFCTLCFG
                                    232 	.globl _GPIFIDLECTL
                                    233 	.globl _GPIFIDLECS
                                    234 	.globl _GPIFWFSELECT
                                    235 	.globl _SETUPDAT
                                    236 	.globl _SUDPTRCTL
                                    237 	.globl _SUDPTRL
                                    238 	.globl _SUDPTRH
                                    239 	.globl _EP8FIFOBCL
                                    240 	.globl _EP8FIFOBCH
                                    241 	.globl _EP6FIFOBCL
                                    242 	.globl _EP6FIFOBCH
                                    243 	.globl _EP4FIFOBCL
                                    244 	.globl _EP4FIFOBCH
                                    245 	.globl _EP2FIFOBCL
                                    246 	.globl _EP2FIFOBCH
                                    247 	.globl _EP8FIFOFLGS
                                    248 	.globl _EP6FIFOFLGS
                                    249 	.globl _EP4FIFOFLGS
                                    250 	.globl _EP2FIFOFLGS
                                    251 	.globl _EP8CS
                                    252 	.globl _EP6CS
                                    253 	.globl _EP4CS
                                    254 	.globl _EP2CS
                                    255 	.globl _EP1INCS
                                    256 	.globl _EP1OUTCS
                                    257 	.globl _EP0CS
                                    258 	.globl _EP8BCL
                                    259 	.globl _EP8BCH
                                    260 	.globl _EP6BCL
                                    261 	.globl _EP6BCH
                                    262 	.globl _EP4BCL
                                    263 	.globl _EP4BCH
                                    264 	.globl _EP2BCL
                                    265 	.globl _EP2BCH
                                    266 	.globl _EP1INBC
                                    267 	.globl _EP1OUTBC
                                    268 	.globl _EP0BCL
                                    269 	.globl _EP0BCH
                                    270 	.globl _FNADDR
                                    271 	.globl _MICROFRAME
                                    272 	.globl _USBFRAMEL
                                    273 	.globl _USBFRAMEH
                                    274 	.globl _TOGCTL
                                    275 	.globl _WAKEUPCS
                                    276 	.globl _SUSPEND
                                    277 	.globl _USBCS
                                    278 	.globl _XAUTODAT2
                                    279 	.globl _XAUTODAT1
                                    280 	.globl _I2CTL
                                    281 	.globl _I2DAT
                                    282 	.globl _I2CS
                                    283 	.globl _PORTECFG
                                    284 	.globl _PORTCCFG
                                    285 	.globl _PORTACFG
                                    286 	.globl _INTSETUP
                                    287 	.globl _INT4IVEC
                                    288 	.globl _INT2IVEC
                                    289 	.globl _CLRERRCNT
                                    290 	.globl _ERRCNTLIM
                                    291 	.globl _USBERRIRQ
                                    292 	.globl _USBERRIE
                                    293 	.globl _GPIFIRQ
                                    294 	.globl _GPIFIE
                                    295 	.globl _EPIRQ
                                    296 	.globl _EPIE
                                    297 	.globl _USBIRQ
                                    298 	.globl _USBIE
                                    299 	.globl _NAKIRQ
                                    300 	.globl _NAKIE
                                    301 	.globl _IBNIRQ
                                    302 	.globl _IBNIE
                                    303 	.globl _EP8FIFOIRQ
                                    304 	.globl _EP8FIFOIE
                                    305 	.globl _EP6FIFOIRQ
                                    306 	.globl _EP6FIFOIE
                                    307 	.globl _EP4FIFOIRQ
                                    308 	.globl _EP4FIFOIE
                                    309 	.globl _EP2FIFOIRQ
                                    310 	.globl _EP2FIFOIE
                                    311 	.globl _OUTPKTEND
                                    312 	.globl _INPKTEND
                                    313 	.globl _EP8ISOINPKTS
                                    314 	.globl _EP6ISOINPKTS
                                    315 	.globl _EP4ISOINPKTS
                                    316 	.globl _EP2ISOINPKTS
                                    317 	.globl _EP8FIFOPFL
                                    318 	.globl _EP8FIFOPFH
                                    319 	.globl _EP6FIFOPFL
                                    320 	.globl _EP6FIFOPFH
                                    321 	.globl _EP4FIFOPFL
                                    322 	.globl _EP4FIFOPFH
                                    323 	.globl _EP2FIFOPFL
                                    324 	.globl _EP2FIFOPFH
                                    325 	.globl _EP8AUTOINLENL
                                    326 	.globl _EP8AUTOINLENH
                                    327 	.globl _EP6AUTOINLENL
                                    328 	.globl _EP6AUTOINLENH
                                    329 	.globl _EP4AUTOINLENL
                                    330 	.globl _EP4AUTOINLENH
                                    331 	.globl _EP2AUTOINLENL
                                    332 	.globl _EP2AUTOINLENH
                                    333 	.globl _EP8FIFOCFG
                                    334 	.globl _EP6FIFOCFG
                                    335 	.globl _EP4FIFOCFG
                                    336 	.globl _EP2FIFOCFG
                                    337 	.globl _EP8CFG
                                    338 	.globl _EP6CFG
                                    339 	.globl _EP4CFG
                                    340 	.globl _EP2CFG
                                    341 	.globl _EP1INCFG
                                    342 	.globl _EP1OUTCFG
                                    343 	.globl _REVCTL
                                    344 	.globl _REVID
                                    345 	.globl _FIFOPINPOLAR
                                    346 	.globl _UART230
                                    347 	.globl _BPADDRL
                                    348 	.globl _BPADDRH
                                    349 	.globl _BREAKPT
                                    350 	.globl _FIFORESET
                                    351 	.globl _PINFLAGSCD
                                    352 	.globl _PINFLAGSAB
                                    353 	.globl _IFCONFIG
                                    354 	.globl _CPUCS
                                    355 	.globl _RES_WAVEDATA_END
                                    356 	.globl _GPIF_WAVE_DATA
                                    357 ;--------------------------------------------------------
                                    358 ; special function registers
                                    359 ;--------------------------------------------------------
                                    360 	.area RSEG    (ABS,DATA)
      000000                        361 	.org 0x0000
                           000080   362 _IOA	=	0x0080
                           000081   363 _SP	=	0x0081
                           000082   364 _DPL	=	0x0082
                           000083   365 _DPH	=	0x0083
                           000084   366 _DPL1	=	0x0084
                           000085   367 _DPH1	=	0x0085
                           000086   368 _DPS	=	0x0086
                           000087   369 _PCON	=	0x0087
                           000088   370 _TCON	=	0x0088
                           000089   371 _TMOD	=	0x0089
                           00008A   372 _TL0	=	0x008a
                           00008B   373 _TL1	=	0x008b
                           00008C   374 _TH0	=	0x008c
                           00008D   375 _TH1	=	0x008d
                           00008E   376 _CKCON	=	0x008e
                           000090   377 _IOB	=	0x0090
                           000091   378 _EXIF	=	0x0091
                           000092   379 __XPAGE	=	0x0092
                           000098   380 _SCON0	=	0x0098
                           000099   381 _SBUF0	=	0x0099
                           00009A   382 _AUTOPTRH1	=	0x009a
                           00009B   383 _AUTOPTRL1	=	0x009b
                           00009D   384 _AUTOPTRH2	=	0x009d
                           00009E   385 _AUTOPTRL2	=	0x009e
                           0000A0   386 _IOC	=	0x00a0
                           0000A1   387 _INT2CLR	=	0x00a1
                           0000A2   388 _INT4CLR	=	0x00a2
                           0000A8   389 _IE	=	0x00a8
                           0000AA   390 _EP2468STAT	=	0x00aa
                           0000AB   391 _EP24FIFOFLGS	=	0x00ab
                           0000AC   392 _EP68FIFOFLGS	=	0x00ac
                           0000AF   393 _AUTOPTRSETUP	=	0x00af
                           0000B0   394 _IOD	=	0x00b0
                           0000B1   395 _IOE	=	0x00b1
                           0000B2   396 _OEA	=	0x00b2
                           0000B3   397 _OEB	=	0x00b3
                           0000B4   398 _OEC	=	0x00b4
                           0000B5   399 _OED	=	0x00b5
                           0000B6   400 _OEE	=	0x00b6
                           0000B8   401 _IP	=	0x00b8
                           0000BA   402 _EP01STAT	=	0x00ba
                           0000BB   403 _GPIFTRIG	=	0x00bb
                           0000BD   404 _GPIFSGLDATH	=	0x00bd
                           0000BE   405 _GPIFSGLDATLX	=	0x00be
                           0000BF   406 _GPIFSGLDATLNOX	=	0x00bf
                           0000C0   407 _SCON1	=	0x00c0
                           0000C1   408 _SBUF1	=	0x00c1
                           0000C8   409 _T2CON	=	0x00c8
                           0000CA   410 _RCAP2L	=	0x00ca
                           0000CB   411 _RCAP2H	=	0x00cb
                           0000CC   412 _TL2	=	0x00cc
                           0000CD   413 _TH2	=	0x00cd
                           0000D0   414 _PSW	=	0x00d0
                           0000D8   415 _EICON	=	0x00d8
                           0000E0   416 _ACC	=	0x00e0
                           0000E8   417 _EIE	=	0x00e8
                           0000F0   418 _B	=	0x00f0
                           0000F8   419 _EIP	=	0x00f8
                                    420 ;--------------------------------------------------------
                                    421 ; special function bits
                                    422 ;--------------------------------------------------------
                                    423 	.area RSEG    (ABS,DATA)
      000000                        424 	.org 0x0000
                           000080   425 _PA0	=	0x0080
                           000081   426 _PA1	=	0x0081
                           000082   427 _PA2	=	0x0082
                           000083   428 _PA3	=	0x0083
                           000084   429 _PA4	=	0x0084
                           000085   430 _PA5	=	0x0085
                           000086   431 _PA6	=	0x0086
                           000087   432 _PA7	=	0x0087
                           000088   433 _IT0	=	0x0088
                           000089   434 _IE0	=	0x0089
                           00008A   435 _IT1	=	0x008a
                           00008B   436 _IE1	=	0x008b
                           00008C   437 _TR0	=	0x008c
                           00008D   438 _TF0	=	0x008d
                           00008E   439 _TR1	=	0x008e
                           00008F   440 _TF1	=	0x008f
                           000090   441 _PB0	=	0x0090
                           000091   442 _PB1	=	0x0091
                           000092   443 _PB2	=	0x0092
                           000093   444 _PB3	=	0x0093
                           000094   445 _PB4	=	0x0094
                           000095   446 _PB5	=	0x0095
                           000096   447 _PB6	=	0x0096
                           000097   448 _PB7	=	0x0097
                           000098   449 _RI	=	0x0098
                           000099   450 _TI	=	0x0099
                           00009A   451 _RB8	=	0x009a
                           00009B   452 _TB8	=	0x009b
                           00009C   453 _REN	=	0x009c
                           00009D   454 _SM2	=	0x009d
                           00009E   455 _SM1	=	0x009e
                           00009F   456 _SM0	=	0x009f
                           0000A0   457 _PC0	=	0x00a0
                           0000A1   458 _PC1	=	0x00a1
                           0000A2   459 _PC2	=	0x00a2
                           0000A3   460 _PC3	=	0x00a3
                           0000A4   461 _PC4	=	0x00a4
                           0000A5   462 _PC5	=	0x00a5
                           0000A6   463 _PC6	=	0x00a6
                           0000A7   464 _PC7	=	0x00a7
                           0000A8   465 _EX0	=	0x00a8
                           0000A9   466 _ET0	=	0x00a9
                           0000AA   467 _EX1	=	0x00aa
                           0000AB   468 _ET1	=	0x00ab
                           0000AC   469 _ES0	=	0x00ac
                           0000AD   470 _ET2	=	0x00ad
                           0000AE   471 _ES1	=	0x00ae
                           0000AF   472 _EA	=	0x00af
                           0000B0   473 _PD0	=	0x00b0
                           0000B1   474 _PD1	=	0x00b1
                           0000B2   475 _PD2	=	0x00b2
                           0000B3   476 _PD3	=	0x00b3
                           0000B4   477 _PD4	=	0x00b4
                           0000B5   478 _PD5	=	0x00b5
                           0000B6   479 _PD6	=	0x00b6
                           0000B7   480 _PD7	=	0x00b7
                           0000B8   481 _PX0	=	0x00b8
                           0000B9   482 _PT0	=	0x00b9
                           0000BA   483 _PX1	=	0x00ba
                           0000BB   484 _PT1	=	0x00bb
                           0000BC   485 _PS0	=	0x00bc
                           0000BD   486 _PT2	=	0x00bd
                           0000BE   487 _PS1	=	0x00be
                           0000C0   488 _RI1	=	0x00c0
                           0000C1   489 _TI1	=	0x00c1
                           0000C2   490 _RB81	=	0x00c2
                           0000C3   491 _TB81	=	0x00c3
                           0000C4   492 _REN1	=	0x00c4
                           0000C5   493 _SM21	=	0x00c5
                           0000C6   494 _SM11	=	0x00c6
                           0000C7   495 _SM01	=	0x00c7
                           0000C8   496 _CP_RL2	=	0x00c8
                           0000C9   497 _C_T2	=	0x00c9
                           0000CA   498 _TR2	=	0x00ca
                           0000CB   499 _EXEN2	=	0x00cb
                           0000CC   500 _TCLK	=	0x00cc
                           0000CD   501 _RCLK	=	0x00cd
                           0000CE   502 _EXF2	=	0x00ce
                           0000CF   503 _TF2	=	0x00cf
                           0000D0   504 _P	=	0x00d0
                           0000D1   505 _FL	=	0x00d1
                           0000D2   506 _OV	=	0x00d2
                           0000D3   507 _RS0	=	0x00d3
                           0000D4   508 _RS1	=	0x00d4
                           0000D5   509 _F0	=	0x00d5
                           0000D6   510 _AC	=	0x00d6
                           0000D7   511 _CY	=	0x00d7
                           0000DB   512 _INT6	=	0x00db
                           0000DC   513 _RESI	=	0x00dc
                           0000DD   514 _ERESI	=	0x00dd
                           0000DF   515 _SMOD1	=	0x00df
                           0000E8   516 _EUSB	=	0x00e8
                           0000E9   517 _EI2C	=	0x00e9
                           0000EA   518 _EIEX4	=	0x00ea
                           0000EB   519 _EIEX5	=	0x00eb
                           0000EC   520 _EIEX6	=	0x00ec
                           0000F8   521 _PUSB	=	0x00f8
                           0000F9   522 _PI2C	=	0x00f9
                           0000FA   523 _EIPX4	=	0x00fa
                           0000FB   524 _EIPX5	=	0x00fb
                           0000FC   525 _EIPX6	=	0x00fc
                                    526 ;--------------------------------------------------------
                                    527 ; overlayable register banks
                                    528 ;--------------------------------------------------------
                                    529 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        530 	.ds 8
                                    531 ;--------------------------------------------------------
                                    532 ; internal ram data
                                    533 ;--------------------------------------------------------
                                    534 	.area DSEG    (DATA)
                                    535 ;--------------------------------------------------------
                                    536 ; overlayable items in internal ram
                                    537 ;--------------------------------------------------------
                                    538 	.area	OSEG    (OVR,DATA)
                                    539 	.area	OSEG    (OVR,DATA)
                                    540 	.area	OSEG    (OVR,DATA)
      000010                        541 _handle_get_interface_PARM_2:
      000010                        542 	.ds 3
                                    543 	.area	OSEG    (OVR,DATA)
      000010                        544 _handle_set_interface_PARM_2:
      000010                        545 	.ds 1
                                    546 	.area	OSEG    (OVR,DATA)
                                    547 ;--------------------------------------------------------
                                    548 ; indirectly addressable internal ram data
                                    549 ;--------------------------------------------------------
                                    550 	.area ISEG    (DATA)
                                    551 ;--------------------------------------------------------
                                    552 ; absolute internal ram data
                                    553 ;--------------------------------------------------------
                                    554 	.area IABS    (ABS,DATA)
                                    555 	.area IABS    (ABS,DATA)
                                    556 ;--------------------------------------------------------
                                    557 ; bit data
                                    558 ;--------------------------------------------------------
                                    559 	.area BSEG    (BIT)
                                    560 ;--------------------------------------------------------
                                    561 ; paged external ram data
                                    562 ;--------------------------------------------------------
                                    563 	.area PSEG    (PAG,XDATA)
                                    564 ;--------------------------------------------------------
                                    565 ; uninitialized external ram data
                                    566 ;--------------------------------------------------------
                                    567 	.area XSEG    (XDATA)
                           00E400   568 _GPIF_WAVE_DATA	=	0xe400
                           00E480   569 _RES_WAVEDATA_END	=	0xe480
                           00E600   570 _CPUCS	=	0xe600
                           00E601   571 _IFCONFIG	=	0xe601
                           00E602   572 _PINFLAGSAB	=	0xe602
                           00E603   573 _PINFLAGSCD	=	0xe603
                           00E604   574 _FIFORESET	=	0xe604
                           00E605   575 _BREAKPT	=	0xe605
                           00E606   576 _BPADDRH	=	0xe606
                           00E607   577 _BPADDRL	=	0xe607
                           00E608   578 _UART230	=	0xe608
                           00E609   579 _FIFOPINPOLAR	=	0xe609
                           00E60A   580 _REVID	=	0xe60a
                           00E60B   581 _REVCTL	=	0xe60b
                           00E610   582 _EP1OUTCFG	=	0xe610
                           00E611   583 _EP1INCFG	=	0xe611
                           00E612   584 _EP2CFG	=	0xe612
                           00E613   585 _EP4CFG	=	0xe613
                           00E614   586 _EP6CFG	=	0xe614
                           00E615   587 _EP8CFG	=	0xe615
                           00E618   588 _EP2FIFOCFG	=	0xe618
                           00E619   589 _EP4FIFOCFG	=	0xe619
                           00E61A   590 _EP6FIFOCFG	=	0xe61a
                           00E61B   591 _EP8FIFOCFG	=	0xe61b
                           00E620   592 _EP2AUTOINLENH	=	0xe620
                           00E621   593 _EP2AUTOINLENL	=	0xe621
                           00E622   594 _EP4AUTOINLENH	=	0xe622
                           00E623   595 _EP4AUTOINLENL	=	0xe623
                           00E624   596 _EP6AUTOINLENH	=	0xe624
                           00E625   597 _EP6AUTOINLENL	=	0xe625
                           00E626   598 _EP8AUTOINLENH	=	0xe626
                           00E627   599 _EP8AUTOINLENL	=	0xe627
                           00E630   600 _EP2FIFOPFH	=	0xe630
                           00E631   601 _EP2FIFOPFL	=	0xe631
                           00E632   602 _EP4FIFOPFH	=	0xe632
                           00E633   603 _EP4FIFOPFL	=	0xe633
                           00E634   604 _EP6FIFOPFH	=	0xe634
                           00E635   605 _EP6FIFOPFL	=	0xe635
                           00E636   606 _EP8FIFOPFH	=	0xe636
                           00E637   607 _EP8FIFOPFL	=	0xe637
                           00E640   608 _EP2ISOINPKTS	=	0xe640
                           00E641   609 _EP4ISOINPKTS	=	0xe641
                           00E642   610 _EP6ISOINPKTS	=	0xe642
                           00E643   611 _EP8ISOINPKTS	=	0xe643
                           00E648   612 _INPKTEND	=	0xe648
                           00E649   613 _OUTPKTEND	=	0xe649
                           00E650   614 _EP2FIFOIE	=	0xe650
                           00E651   615 _EP2FIFOIRQ	=	0xe651
                           00E652   616 _EP4FIFOIE	=	0xe652
                           00E653   617 _EP4FIFOIRQ	=	0xe653
                           00E654   618 _EP6FIFOIE	=	0xe654
                           00E655   619 _EP6FIFOIRQ	=	0xe655
                           00E656   620 _EP8FIFOIE	=	0xe656
                           00E657   621 _EP8FIFOIRQ	=	0xe657
                           00E658   622 _IBNIE	=	0xe658
                           00E659   623 _IBNIRQ	=	0xe659
                           00E65A   624 _NAKIE	=	0xe65a
                           00E65B   625 _NAKIRQ	=	0xe65b
                           00E65C   626 _USBIE	=	0xe65c
                           00E65D   627 _USBIRQ	=	0xe65d
                           00E65E   628 _EPIE	=	0xe65e
                           00E65F   629 _EPIRQ	=	0xe65f
                           00E660   630 _GPIFIE	=	0xe660
                           00E661   631 _GPIFIRQ	=	0xe661
                           00E662   632 _USBERRIE	=	0xe662
                           00E663   633 _USBERRIRQ	=	0xe663
                           00E664   634 _ERRCNTLIM	=	0xe664
                           00E665   635 _CLRERRCNT	=	0xe665
                           00E666   636 _INT2IVEC	=	0xe666
                           00E667   637 _INT4IVEC	=	0xe667
                           00E668   638 _INTSETUP	=	0xe668
                           00E670   639 _PORTACFG	=	0xe670
                           00E671   640 _PORTCCFG	=	0xe671
                           00E672   641 _PORTECFG	=	0xe672
                           00E678   642 _I2CS	=	0xe678
                           00E679   643 _I2DAT	=	0xe679
                           00E67A   644 _I2CTL	=	0xe67a
                           00E67B   645 _XAUTODAT1	=	0xe67b
                           00E67C   646 _XAUTODAT2	=	0xe67c
                           00E680   647 _USBCS	=	0xe680
                           00E681   648 _SUSPEND	=	0xe681
                           00E682   649 _WAKEUPCS	=	0xe682
                           00E683   650 _TOGCTL	=	0xe683
                           00E684   651 _USBFRAMEH	=	0xe684
                           00E685   652 _USBFRAMEL	=	0xe685
                           00E686   653 _MICROFRAME	=	0xe686
                           00E687   654 _FNADDR	=	0xe687
                           00E68A   655 _EP0BCH	=	0xe68a
                           00E68B   656 _EP0BCL	=	0xe68b
                           00E68D   657 _EP1OUTBC	=	0xe68d
                           00E68F   658 _EP1INBC	=	0xe68f
                           00E690   659 _EP2BCH	=	0xe690
                           00E691   660 _EP2BCL	=	0xe691
                           00E694   661 _EP4BCH	=	0xe694
                           00E695   662 _EP4BCL	=	0xe695
                           00E698   663 _EP6BCH	=	0xe698
                           00E699   664 _EP6BCL	=	0xe699
                           00E69C   665 _EP8BCH	=	0xe69c
                           00E69D   666 _EP8BCL	=	0xe69d
                           00E6A0   667 _EP0CS	=	0xe6a0
                           00E6A1   668 _EP1OUTCS	=	0xe6a1
                           00E6A2   669 _EP1INCS	=	0xe6a2
                           00E6A3   670 _EP2CS	=	0xe6a3
                           00E6A4   671 _EP4CS	=	0xe6a4
                           00E6A5   672 _EP6CS	=	0xe6a5
                           00E6A6   673 _EP8CS	=	0xe6a6
                           00E6A7   674 _EP2FIFOFLGS	=	0xe6a7
                           00E6A8   675 _EP4FIFOFLGS	=	0xe6a8
                           00E6A9   676 _EP6FIFOFLGS	=	0xe6a9
                           00E6AA   677 _EP8FIFOFLGS	=	0xe6aa
                           00E6AB   678 _EP2FIFOBCH	=	0xe6ab
                           00E6AC   679 _EP2FIFOBCL	=	0xe6ac
                           00E6AD   680 _EP4FIFOBCH	=	0xe6ad
                           00E6AE   681 _EP4FIFOBCL	=	0xe6ae
                           00E6AF   682 _EP6FIFOBCH	=	0xe6af
                           00E6B0   683 _EP6FIFOBCL	=	0xe6b0
                           00E6B1   684 _EP8FIFOBCH	=	0xe6b1
                           00E6B2   685 _EP8FIFOBCL	=	0xe6b2
                           00E6B3   686 _SUDPTRH	=	0xe6b3
                           00E6B4   687 _SUDPTRL	=	0xe6b4
                           00E6B5   688 _SUDPTRCTL	=	0xe6b5
                           00E6B8   689 _SETUPDAT	=	0xe6b8
                           00E6C0   690 _GPIFWFSELECT	=	0xe6c0
                           00E6C1   691 _GPIFIDLECS	=	0xe6c1
                           00E6C2   692 _GPIFIDLECTL	=	0xe6c2
                           00E6C3   693 _GPIFCTLCFG	=	0xe6c3
                           00E6C4   694 _GPIFADRH	=	0xe6c4
                           00E6C5   695 _GPIFADRL	=	0xe6c5
                           00E6CE   696 _GPIFTCB3	=	0xe6ce
                           00E6CF   697 _GPIFTCB2	=	0xe6cf
                           00E6D0   698 _GPIFTCB1	=	0xe6d0
                           00E6D1   699 _GPIFTCB0	=	0xe6d1
                           00E6D2   700 _EP2GPIFFLGSEL	=	0xe6d2
                           00E6D3   701 _EP2GPIFPFSTOP	=	0xe6d3
                           00E6D4   702 _EP2GPIFTRIG	=	0xe6d4
                           00E6DA   703 _EP4GPIFFLGSEL	=	0xe6da
                           00E6DB   704 _EP4GPIFPFSTOP	=	0xe6db
                           00E6DC   705 _EP4GPIFTRIG	=	0xe6dc
                           00E6E2   706 _EP6GPIFFLGSEL	=	0xe6e2
                           00E6E3   707 _EP6GPIFPFSTOP	=	0xe6e3
                           00E6E4   708 _EP6GPIFTRIG	=	0xe6e4
                           00E6EA   709 _EP8GPIFFLGSEL	=	0xe6ea
                           00E6EB   710 _EP8GPIFPFSTOP	=	0xe6eb
                           00E6EC   711 _EP8GPIFTRIG	=	0xe6ec
                           00E6F0   712 _XGPIFSGLDATH	=	0xe6f0
                           00E6F1   713 _XGPIFSGLDATLX	=	0xe6f1
                           00E6F2   714 _XGPIFSGLDATLNOX	=	0xe6f2
                           00E6F3   715 _GPIFREADYCFG	=	0xe6f3
                           00E6F4   716 _GPIFREADYSTAT	=	0xe6f4
                           00E6F5   717 _GPIFABORT	=	0xe6f5
                           00E6C6   718 _FLOWSTATE	=	0xe6c6
                           00E6C7   719 _FLOWLOGIC	=	0xe6c7
                           00E6C8   720 _FLOWEQ0CTL	=	0xe6c8
                           00E6C9   721 _FLOWEQ1CTL	=	0xe6c9
                           00E6CA   722 _FLOWHOLDOFF	=	0xe6ca
                           00E6CB   723 _FLOWSTB	=	0xe6cb
                           00E6CC   724 _FLOWSTBEDGE	=	0xe6cc
                           00E6CD   725 _FLOWSTBHPERIOD	=	0xe6cd
                           00E60C   726 _GPIFHOLDAMOUNT	=	0xe60c
                           00E67D   727 _UDMACRCH	=	0xe67d
                           00E67E   728 _UDMACRCL	=	0xe67e
                           00E67F   729 _UDMACRCQUAL	=	0xe67f
                           00E740   730 _EP0BUF	=	0xe740
                           00E780   731 _EP1OUTBUF	=	0xe780
                           00E7C0   732 _EP1INBUF	=	0xe7c0
                           00F000   733 _EP2FIFOBUF	=	0xf000
                           00F400   734 _EP4FIFOBUF	=	0xf400
                           00F800   735 _EP6FIFOBUF	=	0xf800
                           00FC00   736 _EP8FIFOBUF	=	0xfc00
                           00E628   737 _ECCCFG	=	0xe628
                           00E629   738 _ECCRESET	=	0xe629
                           00E62A   739 _ECC1B0	=	0xe62a
                           00E62B   740 _ECC1B1	=	0xe62b
                           00E62C   741 _ECC1B2	=	0xe62c
                           00E62D   742 _ECC2B0	=	0xe62d
                           00E62E   743 _ECC2B1	=	0xe62e
                           00E62F   744 _ECC2B2	=	0xe62f
                           00E50D   745 _GPCR2	=	0xe50d
                                    746 ;--------------------------------------------------------
                                    747 ; absolute external ram data
                                    748 ;--------------------------------------------------------
                                    749 	.area XABS    (ABS,XDATA)
                                    750 ;--------------------------------------------------------
                                    751 ; initialized external ram data
                                    752 ;--------------------------------------------------------
                                    753 	.area XISEG   (XDATA)
                                    754 	.area HOME    (CODE)
                                    755 	.area GSINIT0 (CODE)
                                    756 	.area GSINIT1 (CODE)
                                    757 	.area GSINIT2 (CODE)
                                    758 	.area GSINIT3 (CODE)
                                    759 	.area GSINIT4 (CODE)
                                    760 	.area GSINIT5 (CODE)
                                    761 	.area GSINIT  (CODE)
                                    762 	.area GSFINAL (CODE)
                                    763 	.area CSEG    (CODE)
                                    764 ;--------------------------------------------------------
                                    765 ; global & static initialisations
                                    766 ;--------------------------------------------------------
                                    767 	.area HOME    (CODE)
                                    768 	.area GSINIT  (CODE)
                                    769 	.area GSFINAL (CODE)
                                    770 	.area GSINIT  (CODE)
                                    771 ;--------------------------------------------------------
                                    772 ; Home
                                    773 ;--------------------------------------------------------
                                    774 	.area HOME    (CODE)
                                    775 	.area HOME    (CODE)
                                    776 ;--------------------------------------------------------
                                    777 ; code
                                    778 ;--------------------------------------------------------
                                    779 	.area CSEG    (CODE)
                                    780 ;------------------------------------------------------------
                                    781 ;Allocation info for local variables in function 'handle_get_descriptor'
                                    782 ;------------------------------------------------------------
                                    783 ;idx                       Allocated to registers r7 
                                    784 ;p                         Allocated to registers r6 r7 
                                    785 ;------------------------------------------------------------
                                    786 ;	src/setup_callbacks.c:20: BOOL handle_get_descriptor(void) {
                                    787 ;	-----------------------------------------
                                    788 ;	 function handle_get_descriptor
                                    789 ;	-----------------------------------------
      0002ED                        790 _handle_get_descriptor:
                           000007   791 	ar7 = 0x07
                           000006   792 	ar6 = 0x06
                           000005   793 	ar5 = 0x05
                           000004   794 	ar4 = 0x04
                           000003   795 	ar3 = 0x03
                           000002   796 	ar2 = 0x02
                           000001   797 	ar1 = 0x01
                           000000   798 	ar0 = 0x00
                                    799 ;	src/setup_callbacks.c:21: if (SETUPDAT[3] == DSCR_STRING_TYPE) {
      0002ED 90 E6 BB         [24]  800 	mov	dptr,#(_SETUPDAT + 0x0003)
      0002F0 E0               [24]  801 	movx	a,@dptr
      0002F1 FF               [12]  802 	mov	r7,a
      0002F2 BF 03 39         [24]  803 	cjne	r7,#0x03,00107$
                                    804 ;	src/setup_callbacks.c:22: BYTE idx = SETUPDAT[2];
      0002F5 90 E6 BA         [24]  805 	mov	dptr,#(_SETUPDAT + 0x0002)
      0002F8 E0               [24]  806 	movx	a,@dptr
                                    807 ;	src/setup_callbacks.c:24: switch (idx) {
      0002F9 FF               [12]  808 	mov	r7,a
      0002FA 60 0A            [24]  809 	jz	00101$
      0002FC BF 01 02         [24]  810 	cjne	r7,#0x01,00137$
      0002FF 80 0B            [24]  811 	sjmp	00102$
      000301                        812 00137$:
                                    813 ;	src/setup_callbacks.c:25: case 0: p = str0_dscr; break;
      000301 BF 02 14         [24]  814 	cjne	r7,#0x02,00104$
      000304 80 0C            [24]  815 	sjmp	00103$
      000306                        816 00101$:
      000306 7E B9            [12]  817 	mov	r6,#_str0_dscr
      000308 7F 07            [12]  818 	mov	r7,#(_str0_dscr >> 8)
                                    819 ;	src/setup_callbacks.c:26: case 1: p = str1_dscr; break;
      00030A 80 10            [24]  820 	sjmp	00105$
      00030C                        821 00102$:
      00030C 7E BD            [12]  822 	mov	r6,#_str1_dscr
      00030E 7F 07            [12]  823 	mov	r7,#(_str1_dscr >> 8)
                                    824 ;	src/setup_callbacks.c:27: case 2: p = str2_dscr; break;
      000310 80 0A            [24]  825 	sjmp	00105$
      000312                        826 00103$:
      000312 7E CD            [12]  827 	mov	r6,#_str2_dscr
      000314 7F 07            [12]  828 	mov	r7,#(_str2_dscr >> 8)
                                    829 ;	src/setup_callbacks.c:28: default: return FALSE;
      000316 80 04            [24]  830 	sjmp	00105$
      000318                        831 00104$:
      000318 75 82 00         [24]  832 	mov	dpl, #0x00
                                    833 ;	src/setup_callbacks.c:29: }
      00031B 22               [24]  834 	ret
      00031C                        835 00105$:
                                    836 ;	src/setup_callbacks.c:30: SUDPTRH = MSB((WORD)p);
      00031C 8E 04            [24]  837 	mov	ar4,r6
      00031E 8F 05            [24]  838 	mov	ar5,r7
      000320 90 E6 B3         [24]  839 	mov	dptr,#_SUDPTRH
      000323 ED               [12]  840 	mov	a,r5
      000324 F0               [24]  841 	movx	@dptr,a
                                    842 ;	src/setup_callbacks.c:31: SUDPTRL = LSB((WORD)p);
      000325 90 E6 B4         [24]  843 	mov	dptr,#_SUDPTRL
      000328 EE               [12]  844 	mov	a,r6
      000329 F0               [24]  845 	movx	@dptr,a
                                    846 ;	src/setup_callbacks.c:32: return TRUE;
      00032A 75 82 01         [24]  847 	mov	dpl, #0x01
      00032D 22               [24]  848 	ret
      00032E                        849 00107$:
                                    850 ;	src/setup_callbacks.c:34: return FALSE;
      00032E 75 82 00         [24]  851 	mov	dpl, #0x00
                                    852 ;	src/setup_callbacks.c:35: }
      000331 22               [24]  853 	ret
                                    854 ;------------------------------------------------------------
                                    855 ;Allocation info for local variables in function 'handle_get_configuration'
                                    856 ;------------------------------------------------------------
                                    857 ;	src/setup_callbacks.c:37: BYTE handle_get_configuration(void) {
                                    858 ;	-----------------------------------------
                                    859 ;	 function handle_get_configuration
                                    860 ;	-----------------------------------------
      000332                        861 _handle_get_configuration:
                                    862 ;	src/setup_callbacks.c:38: return 1; // single configuration
      000332 75 82 01         [24]  863 	mov	dpl, #0x01
                                    864 ;	src/setup_callbacks.c:39: }
      000335 22               [24]  865 	ret
                                    866 ;------------------------------------------------------------
                                    867 ;Allocation info for local variables in function 'handle_set_configuration'
                                    868 ;------------------------------------------------------------
                                    869 ;cfg                       Allocated to registers 
                                    870 ;------------------------------------------------------------
                                    871 ;	src/setup_callbacks.c:41: BOOL handle_set_configuration(BYTE cfg) {
                                    872 ;	-----------------------------------------
                                    873 ;	 function handle_set_configuration
                                    874 ;	-----------------------------------------
      000336                        875 _handle_set_configuration:
                                    876 ;	src/setup_callbacks.c:43: return TRUE;
      000336 75 82 01         [24]  877 	mov	dpl, #0x01
                                    878 ;	src/setup_callbacks.c:44: }
      000339 22               [24]  879 	ret
                                    880 ;------------------------------------------------------------
                                    881 ;Allocation info for local variables in function 'handle_get_interface'
                                    882 ;------------------------------------------------------------
                                    883 ;alt_ifc                   Allocated with name '_handle_get_interface_PARM_2'
                                    884 ;ifc                       Allocated to registers 
                                    885 ;------------------------------------------------------------
                                    886 ;	src/setup_callbacks.c:46: BOOL handle_get_interface(BYTE ifc, BYTE* alt_ifc) {
                                    887 ;	-----------------------------------------
                                    888 ;	 function handle_get_interface
                                    889 ;	-----------------------------------------
      00033A                        890 _handle_get_interface:
                                    891 ;	src/setup_callbacks.c:48: if (alt_ifc) *alt_ifc = 0;
      00033A E5 10            [12]  892 	mov	a,_handle_get_interface_PARM_2
      00033C 45 11            [12]  893 	orl	a,(_handle_get_interface_PARM_2 + 1)
      00033E 60 10            [24]  894 	jz	00102$
      000340 AD 10            [24]  895 	mov	r5,_handle_get_interface_PARM_2
      000342 AE 11            [24]  896 	mov	r6,(_handle_get_interface_PARM_2 + 1)
      000344 AF 12            [24]  897 	mov	r7,(_handle_get_interface_PARM_2 + 2)
      000346 8D 82            [24]  898 	mov	dpl,r5
      000348 8E 83            [24]  899 	mov	dph,r6
      00034A 8F F0            [24]  900 	mov	b,r7
      00034C E4               [12]  901 	clr	a
      00034D 12 03 59         [24]  902 	lcall	__gptrput
      000350                        903 00102$:
                                    904 ;	src/setup_callbacks.c:49: return TRUE;
      000350 75 82 01         [24]  905 	mov	dpl, #0x01
                                    906 ;	src/setup_callbacks.c:50: }
      000353 22               [24]  907 	ret
                                    908 ;------------------------------------------------------------
                                    909 ;Allocation info for local variables in function 'handle_set_interface'
                                    910 ;------------------------------------------------------------
                                    911 ;alt_ifc                   Allocated with name '_handle_set_interface_PARM_2'
                                    912 ;ifc                       Allocated to registers 
                                    913 ;------------------------------------------------------------
                                    914 ;	src/setup_callbacks.c:52: BOOL handle_set_interface(BYTE ifc, BYTE alt_ifc) {
                                    915 ;	-----------------------------------------
                                    916 ;	 function handle_set_interface
                                    917 ;	-----------------------------------------
      000354                        918 _handle_set_interface:
                                    919 ;	src/setup_callbacks.c:54: return TRUE;
      000354 75 82 01         [24]  920 	mov	dpl, #0x01
                                    921 ;	src/setup_callbacks.c:55: }
      000357 22               [24]  922 	ret
                                    923 ;------------------------------------------------------------
                                    924 ;Allocation info for local variables in function 'handle_reset_ep'
                                    925 ;------------------------------------------------------------
                                    926 ;ep                        Allocated to registers 
                                    927 ;------------------------------------------------------------
                                    928 ;	src/setup_callbacks.c:57: void handle_reset_ep(BYTE ep) {
                                    929 ;	-----------------------------------------
                                    930 ;	 function handle_reset_ep
                                    931 ;	-----------------------------------------
      000358                        932 _handle_reset_ep:
                                    933 ;	src/setup_callbacks.c:59: }
      000358 22               [24]  934 	ret
                                    935 	.area CSEG    (CODE)
                                    936 	.area CONST   (CODE)
      0007F1                        937 _dev_strings:
      0007F1 B9 07                  938 	.byte _str0_dscr, (_str0_dscr >> 8)
      0007F3 BD 07                  939 	.byte _str1_dscr, (_str1_dscr >> 8)
      0007F5 CD 07                  940 	.byte _str2_dscr, (_str2_dscr >> 8)
                                    941 	.area XINIT   (CODE)
                                    942 	.area CABS    (ABS,CODE)
