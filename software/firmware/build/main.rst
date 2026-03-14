                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _handle_vendorcommand
                                     13 	.globl _handle_setupdata
                                     14 	.globl _EIPX6
                                     15 	.globl _EIPX5
                                     16 	.globl _EIPX4
                                     17 	.globl _PI2C
                                     18 	.globl _PUSB
                                     19 	.globl _EIEX6
                                     20 	.globl _EIEX5
                                     21 	.globl _EIEX4
                                     22 	.globl _EI2C
                                     23 	.globl _EUSB
                                     24 	.globl _SMOD1
                                     25 	.globl _ERESI
                                     26 	.globl _RESI
                                     27 	.globl _INT6
                                     28 	.globl _CY
                                     29 	.globl _AC
                                     30 	.globl _F0
                                     31 	.globl _RS1
                                     32 	.globl _RS0
                                     33 	.globl _OV
                                     34 	.globl _FL
                                     35 	.globl _P
                                     36 	.globl _TF2
                                     37 	.globl _EXF2
                                     38 	.globl _RCLK
                                     39 	.globl _TCLK
                                     40 	.globl _EXEN2
                                     41 	.globl _TR2
                                     42 	.globl _C_T2
                                     43 	.globl _CP_RL2
                                     44 	.globl _SM01
                                     45 	.globl _SM11
                                     46 	.globl _SM21
                                     47 	.globl _REN1
                                     48 	.globl _TB81
                                     49 	.globl _RB81
                                     50 	.globl _TI1
                                     51 	.globl _RI1
                                     52 	.globl _PS1
                                     53 	.globl _PT2
                                     54 	.globl _PS0
                                     55 	.globl _PT1
                                     56 	.globl _PX1
                                     57 	.globl _PT0
                                     58 	.globl _PX0
                                     59 	.globl _PD7
                                     60 	.globl _PD6
                                     61 	.globl _PD5
                                     62 	.globl _PD4
                                     63 	.globl _PD3
                                     64 	.globl _PD2
                                     65 	.globl _PD1
                                     66 	.globl _PD0
                                     67 	.globl _EA
                                     68 	.globl _ES1
                                     69 	.globl _ET2
                                     70 	.globl _ES0
                                     71 	.globl _ET1
                                     72 	.globl _EX1
                                     73 	.globl _ET0
                                     74 	.globl _EX0
                                     75 	.globl _PC7
                                     76 	.globl _PC6
                                     77 	.globl _PC5
                                     78 	.globl _PC4
                                     79 	.globl _PC3
                                     80 	.globl _PC2
                                     81 	.globl _PC1
                                     82 	.globl _PC0
                                     83 	.globl _SM0
                                     84 	.globl _SM1
                                     85 	.globl _SM2
                                     86 	.globl _REN
                                     87 	.globl _TB8
                                     88 	.globl _RB8
                                     89 	.globl _TI
                                     90 	.globl _RI
                                     91 	.globl _PB7
                                     92 	.globl _PB6
                                     93 	.globl _PB5
                                     94 	.globl _PB4
                                     95 	.globl _PB3
                                     96 	.globl _PB2
                                     97 	.globl _PB1
                                     98 	.globl _PB0
                                     99 	.globl _TF1
                                    100 	.globl _TR1
                                    101 	.globl _TF0
                                    102 	.globl _TR0
                                    103 	.globl _IE1
                                    104 	.globl _IT1
                                    105 	.globl _IE0
                                    106 	.globl _IT0
                                    107 	.globl _PA7
                                    108 	.globl _PA6
                                    109 	.globl _PA5
                                    110 	.globl _PA4
                                    111 	.globl _PA3
                                    112 	.globl _PA2
                                    113 	.globl _PA1
                                    114 	.globl _PA0
                                    115 	.globl _EIP
                                    116 	.globl _B
                                    117 	.globl _EIE
                                    118 	.globl _ACC
                                    119 	.globl _EICON
                                    120 	.globl _PSW
                                    121 	.globl _TH2
                                    122 	.globl _TL2
                                    123 	.globl _RCAP2H
                                    124 	.globl _RCAP2L
                                    125 	.globl _T2CON
                                    126 	.globl _SBUF1
                                    127 	.globl _SCON1
                                    128 	.globl _GPIFSGLDATLNOX
                                    129 	.globl _GPIFSGLDATLX
                                    130 	.globl _GPIFSGLDATH
                                    131 	.globl _GPIFTRIG
                                    132 	.globl _EP01STAT
                                    133 	.globl _IP
                                    134 	.globl _OEE
                                    135 	.globl _OED
                                    136 	.globl _OEC
                                    137 	.globl _OEB
                                    138 	.globl _OEA
                                    139 	.globl _IOE
                                    140 	.globl _IOD
                                    141 	.globl _AUTOPTRSETUP
                                    142 	.globl _EP68FIFOFLGS
                                    143 	.globl _EP24FIFOFLGS
                                    144 	.globl _EP2468STAT
                                    145 	.globl _IE
                                    146 	.globl _INT4CLR
                                    147 	.globl _INT2CLR
                                    148 	.globl _IOC
                                    149 	.globl _AUTOPTRL2
                                    150 	.globl _AUTOPTRH2
                                    151 	.globl _AUTOPTRL1
                                    152 	.globl _AUTOPTRH1
                                    153 	.globl _SBUF0
                                    154 	.globl _SCON0
                                    155 	.globl __XPAGE
                                    156 	.globl _EXIF
                                    157 	.globl _IOB
                                    158 	.globl _CKCON
                                    159 	.globl _TH1
                                    160 	.globl _TH0
                                    161 	.globl _TL1
                                    162 	.globl _TL0
                                    163 	.globl _TMOD
                                    164 	.globl _TCON
                                    165 	.globl _PCON
                                    166 	.globl _DPS
                                    167 	.globl _DPH1
                                    168 	.globl _DPL1
                                    169 	.globl _DPH
                                    170 	.globl _DPL
                                    171 	.globl _SP
                                    172 	.globl _IOA
                                    173 	.globl _GPCR2
                                    174 	.globl _ECC2B2
                                    175 	.globl _ECC2B1
                                    176 	.globl _ECC2B0
                                    177 	.globl _ECC1B2
                                    178 	.globl _ECC1B1
                                    179 	.globl _ECC1B0
                                    180 	.globl _ECCRESET
                                    181 	.globl _ECCCFG
                                    182 	.globl _EP8FIFOBUF
                                    183 	.globl _EP6FIFOBUF
                                    184 	.globl _EP4FIFOBUF
                                    185 	.globl _EP2FIFOBUF
                                    186 	.globl _EP1INBUF
                                    187 	.globl _EP1OUTBUF
                                    188 	.globl _EP0BUF
                                    189 	.globl _UDMACRCQUAL
                                    190 	.globl _UDMACRCL
                                    191 	.globl _UDMACRCH
                                    192 	.globl _GPIFHOLDAMOUNT
                                    193 	.globl _FLOWSTBHPERIOD
                                    194 	.globl _FLOWSTBEDGE
                                    195 	.globl _FLOWSTB
                                    196 	.globl _FLOWHOLDOFF
                                    197 	.globl _FLOWEQ1CTL
                                    198 	.globl _FLOWEQ0CTL
                                    199 	.globl _FLOWLOGIC
                                    200 	.globl _FLOWSTATE
                                    201 	.globl _GPIFABORT
                                    202 	.globl _GPIFREADYSTAT
                                    203 	.globl _GPIFREADYCFG
                                    204 	.globl _XGPIFSGLDATLNOX
                                    205 	.globl _XGPIFSGLDATLX
                                    206 	.globl _XGPIFSGLDATH
                                    207 	.globl _EP8GPIFTRIG
                                    208 	.globl _EP8GPIFPFSTOP
                                    209 	.globl _EP8GPIFFLGSEL
                                    210 	.globl _EP6GPIFTRIG
                                    211 	.globl _EP6GPIFPFSTOP
                                    212 	.globl _EP6GPIFFLGSEL
                                    213 	.globl _EP4GPIFTRIG
                                    214 	.globl _EP4GPIFPFSTOP
                                    215 	.globl _EP4GPIFFLGSEL
                                    216 	.globl _EP2GPIFTRIG
                                    217 	.globl _EP2GPIFPFSTOP
                                    218 	.globl _EP2GPIFFLGSEL
                                    219 	.globl _GPIFTCB0
                                    220 	.globl _GPIFTCB1
                                    221 	.globl _GPIFTCB2
                                    222 	.globl _GPIFTCB3
                                    223 	.globl _GPIFADRL
                                    224 	.globl _GPIFADRH
                                    225 	.globl _GPIFCTLCFG
                                    226 	.globl _GPIFIDLECTL
                                    227 	.globl _GPIFIDLECS
                                    228 	.globl _GPIFWFSELECT
                                    229 	.globl _SETUPDAT
                                    230 	.globl _SUDPTRCTL
                                    231 	.globl _SUDPTRL
                                    232 	.globl _SUDPTRH
                                    233 	.globl _EP8FIFOBCL
                                    234 	.globl _EP8FIFOBCH
                                    235 	.globl _EP6FIFOBCL
                                    236 	.globl _EP6FIFOBCH
                                    237 	.globl _EP4FIFOBCL
                                    238 	.globl _EP4FIFOBCH
                                    239 	.globl _EP2FIFOBCL
                                    240 	.globl _EP2FIFOBCH
                                    241 	.globl _EP8FIFOFLGS
                                    242 	.globl _EP6FIFOFLGS
                                    243 	.globl _EP4FIFOFLGS
                                    244 	.globl _EP2FIFOFLGS
                                    245 	.globl _EP8CS
                                    246 	.globl _EP6CS
                                    247 	.globl _EP4CS
                                    248 	.globl _EP2CS
                                    249 	.globl _EP1INCS
                                    250 	.globl _EP1OUTCS
                                    251 	.globl _EP0CS
                                    252 	.globl _EP8BCL
                                    253 	.globl _EP8BCH
                                    254 	.globl _EP6BCL
                                    255 	.globl _EP6BCH
                                    256 	.globl _EP4BCL
                                    257 	.globl _EP4BCH
                                    258 	.globl _EP2BCL
                                    259 	.globl _EP2BCH
                                    260 	.globl _EP1INBC
                                    261 	.globl _EP1OUTBC
                                    262 	.globl _EP0BCL
                                    263 	.globl _EP0BCH
                                    264 	.globl _FNADDR
                                    265 	.globl _MICROFRAME
                                    266 	.globl _USBFRAMEL
                                    267 	.globl _USBFRAMEH
                                    268 	.globl _TOGCTL
                                    269 	.globl _WAKEUPCS
                                    270 	.globl _SUSPEND
                                    271 	.globl _USBCS
                                    272 	.globl _XAUTODAT2
                                    273 	.globl _XAUTODAT1
                                    274 	.globl _I2CTL
                                    275 	.globl _I2DAT
                                    276 	.globl _I2CS
                                    277 	.globl _PORTECFG
                                    278 	.globl _PORTCCFG
                                    279 	.globl _PORTACFG
                                    280 	.globl _INTSETUP
                                    281 	.globl _INT4IVEC
                                    282 	.globl _INT2IVEC
                                    283 	.globl _CLRERRCNT
                                    284 	.globl _ERRCNTLIM
                                    285 	.globl _USBERRIRQ
                                    286 	.globl _USBERRIE
                                    287 	.globl _GPIFIRQ
                                    288 	.globl _GPIFIE
                                    289 	.globl _EPIRQ
                                    290 	.globl _EPIE
                                    291 	.globl _USBIRQ
                                    292 	.globl _USBIE
                                    293 	.globl _NAKIRQ
                                    294 	.globl _NAKIE
                                    295 	.globl _IBNIRQ
                                    296 	.globl _IBNIE
                                    297 	.globl _EP8FIFOIRQ
                                    298 	.globl _EP8FIFOIE
                                    299 	.globl _EP6FIFOIRQ
                                    300 	.globl _EP6FIFOIE
                                    301 	.globl _EP4FIFOIRQ
                                    302 	.globl _EP4FIFOIE
                                    303 	.globl _EP2FIFOIRQ
                                    304 	.globl _EP2FIFOIE
                                    305 	.globl _OUTPKTEND
                                    306 	.globl _INPKTEND
                                    307 	.globl _EP8ISOINPKTS
                                    308 	.globl _EP6ISOINPKTS
                                    309 	.globl _EP4ISOINPKTS
                                    310 	.globl _EP2ISOINPKTS
                                    311 	.globl _EP8FIFOPFL
                                    312 	.globl _EP8FIFOPFH
                                    313 	.globl _EP6FIFOPFL
                                    314 	.globl _EP6FIFOPFH
                                    315 	.globl _EP4FIFOPFL
                                    316 	.globl _EP4FIFOPFH
                                    317 	.globl _EP2FIFOPFL
                                    318 	.globl _EP2FIFOPFH
                                    319 	.globl _EP8AUTOINLENL
                                    320 	.globl _EP8AUTOINLENH
                                    321 	.globl _EP6AUTOINLENL
                                    322 	.globl _EP6AUTOINLENH
                                    323 	.globl _EP4AUTOINLENL
                                    324 	.globl _EP4AUTOINLENH
                                    325 	.globl _EP2AUTOINLENL
                                    326 	.globl _EP2AUTOINLENH
                                    327 	.globl _EP8FIFOCFG
                                    328 	.globl _EP6FIFOCFG
                                    329 	.globl _EP4FIFOCFG
                                    330 	.globl _EP2FIFOCFG
                                    331 	.globl _EP8CFG
                                    332 	.globl _EP6CFG
                                    333 	.globl _EP4CFG
                                    334 	.globl _EP2CFG
                                    335 	.globl _EP1INCFG
                                    336 	.globl _EP1OUTCFG
                                    337 	.globl _REVCTL
                                    338 	.globl _REVID
                                    339 	.globl _FIFOPINPOLAR
                                    340 	.globl _UART230
                                    341 	.globl _BPADDRL
                                    342 	.globl _BPADDRH
                                    343 	.globl _BREAKPT
                                    344 	.globl _FIFORESET
                                    345 	.globl _PINFLAGSCD
                                    346 	.globl _PINFLAGSAB
                                    347 	.globl _IFCONFIG
                                    348 	.globl _CPUCS
                                    349 	.globl _RES_WAVEDATA_END
                                    350 	.globl _GPIF_WAVE_DATA
                                    351 	.globl _boot_ifconfig_snapshot
                                    352 ;--------------------------------------------------------
                                    353 ; special function registers
                                    354 ;--------------------------------------------------------
                                    355 	.area RSEG    (ABS,DATA)
      000000                        356 	.org 0x0000
                           000080   357 _IOA	=	0x0080
                           000081   358 _SP	=	0x0081
                           000082   359 _DPL	=	0x0082
                           000083   360 _DPH	=	0x0083
                           000084   361 _DPL1	=	0x0084
                           000085   362 _DPH1	=	0x0085
                           000086   363 _DPS	=	0x0086
                           000087   364 _PCON	=	0x0087
                           000088   365 _TCON	=	0x0088
                           000089   366 _TMOD	=	0x0089
                           00008A   367 _TL0	=	0x008a
                           00008B   368 _TL1	=	0x008b
                           00008C   369 _TH0	=	0x008c
                           00008D   370 _TH1	=	0x008d
                           00008E   371 _CKCON	=	0x008e
                           000090   372 _IOB	=	0x0090
                           000091   373 _EXIF	=	0x0091
                           000092   374 __XPAGE	=	0x0092
                           000098   375 _SCON0	=	0x0098
                           000099   376 _SBUF0	=	0x0099
                           00009A   377 _AUTOPTRH1	=	0x009a
                           00009B   378 _AUTOPTRL1	=	0x009b
                           00009D   379 _AUTOPTRH2	=	0x009d
                           00009E   380 _AUTOPTRL2	=	0x009e
                           0000A0   381 _IOC	=	0x00a0
                           0000A1   382 _INT2CLR	=	0x00a1
                           0000A2   383 _INT4CLR	=	0x00a2
                           0000A8   384 _IE	=	0x00a8
                           0000AA   385 _EP2468STAT	=	0x00aa
                           0000AB   386 _EP24FIFOFLGS	=	0x00ab
                           0000AC   387 _EP68FIFOFLGS	=	0x00ac
                           0000AF   388 _AUTOPTRSETUP	=	0x00af
                           0000B0   389 _IOD	=	0x00b0
                           0000B1   390 _IOE	=	0x00b1
                           0000B2   391 _OEA	=	0x00b2
                           0000B3   392 _OEB	=	0x00b3
                           0000B4   393 _OEC	=	0x00b4
                           0000B5   394 _OED	=	0x00b5
                           0000B6   395 _OEE	=	0x00b6
                           0000B8   396 _IP	=	0x00b8
                           0000BA   397 _EP01STAT	=	0x00ba
                           0000BB   398 _GPIFTRIG	=	0x00bb
                           0000BD   399 _GPIFSGLDATH	=	0x00bd
                           0000BE   400 _GPIFSGLDATLX	=	0x00be
                           0000BF   401 _GPIFSGLDATLNOX	=	0x00bf
                           0000C0   402 _SCON1	=	0x00c0
                           0000C1   403 _SBUF1	=	0x00c1
                           0000C8   404 _T2CON	=	0x00c8
                           0000CA   405 _RCAP2L	=	0x00ca
                           0000CB   406 _RCAP2H	=	0x00cb
                           0000CC   407 _TL2	=	0x00cc
                           0000CD   408 _TH2	=	0x00cd
                           0000D0   409 _PSW	=	0x00d0
                           0000D8   410 _EICON	=	0x00d8
                           0000E0   411 _ACC	=	0x00e0
                           0000E8   412 _EIE	=	0x00e8
                           0000F0   413 _B	=	0x00f0
                           0000F8   414 _EIP	=	0x00f8
                                    415 ;--------------------------------------------------------
                                    416 ; special function bits
                                    417 ;--------------------------------------------------------
                                    418 	.area RSEG    (ABS,DATA)
      000000                        419 	.org 0x0000
                           000080   420 _PA0	=	0x0080
                           000081   421 _PA1	=	0x0081
                           000082   422 _PA2	=	0x0082
                           000083   423 _PA3	=	0x0083
                           000084   424 _PA4	=	0x0084
                           000085   425 _PA5	=	0x0085
                           000086   426 _PA6	=	0x0086
                           000087   427 _PA7	=	0x0087
                           000088   428 _IT0	=	0x0088
                           000089   429 _IE0	=	0x0089
                           00008A   430 _IT1	=	0x008a
                           00008B   431 _IE1	=	0x008b
                           00008C   432 _TR0	=	0x008c
                           00008D   433 _TF0	=	0x008d
                           00008E   434 _TR1	=	0x008e
                           00008F   435 _TF1	=	0x008f
                           000090   436 _PB0	=	0x0090
                           000091   437 _PB1	=	0x0091
                           000092   438 _PB2	=	0x0092
                           000093   439 _PB3	=	0x0093
                           000094   440 _PB4	=	0x0094
                           000095   441 _PB5	=	0x0095
                           000096   442 _PB6	=	0x0096
                           000097   443 _PB7	=	0x0097
                           000098   444 _RI	=	0x0098
                           000099   445 _TI	=	0x0099
                           00009A   446 _RB8	=	0x009a
                           00009B   447 _TB8	=	0x009b
                           00009C   448 _REN	=	0x009c
                           00009D   449 _SM2	=	0x009d
                           00009E   450 _SM1	=	0x009e
                           00009F   451 _SM0	=	0x009f
                           0000A0   452 _PC0	=	0x00a0
                           0000A1   453 _PC1	=	0x00a1
                           0000A2   454 _PC2	=	0x00a2
                           0000A3   455 _PC3	=	0x00a3
                           0000A4   456 _PC4	=	0x00a4
                           0000A5   457 _PC5	=	0x00a5
                           0000A6   458 _PC6	=	0x00a6
                           0000A7   459 _PC7	=	0x00a7
                           0000A8   460 _EX0	=	0x00a8
                           0000A9   461 _ET0	=	0x00a9
                           0000AA   462 _EX1	=	0x00aa
                           0000AB   463 _ET1	=	0x00ab
                           0000AC   464 _ES0	=	0x00ac
                           0000AD   465 _ET2	=	0x00ad
                           0000AE   466 _ES1	=	0x00ae
                           0000AF   467 _EA	=	0x00af
                           0000B0   468 _PD0	=	0x00b0
                           0000B1   469 _PD1	=	0x00b1
                           0000B2   470 _PD2	=	0x00b2
                           0000B3   471 _PD3	=	0x00b3
                           0000B4   472 _PD4	=	0x00b4
                           0000B5   473 _PD5	=	0x00b5
                           0000B6   474 _PD6	=	0x00b6
                           0000B7   475 _PD7	=	0x00b7
                           0000B8   476 _PX0	=	0x00b8
                           0000B9   477 _PT0	=	0x00b9
                           0000BA   478 _PX1	=	0x00ba
                           0000BB   479 _PT1	=	0x00bb
                           0000BC   480 _PS0	=	0x00bc
                           0000BD   481 _PT2	=	0x00bd
                           0000BE   482 _PS1	=	0x00be
                           0000C0   483 _RI1	=	0x00c0
                           0000C1   484 _TI1	=	0x00c1
                           0000C2   485 _RB81	=	0x00c2
                           0000C3   486 _TB81	=	0x00c3
                           0000C4   487 _REN1	=	0x00c4
                           0000C5   488 _SM21	=	0x00c5
                           0000C6   489 _SM11	=	0x00c6
                           0000C7   490 _SM01	=	0x00c7
                           0000C8   491 _CP_RL2	=	0x00c8
                           0000C9   492 _C_T2	=	0x00c9
                           0000CA   493 _TR2	=	0x00ca
                           0000CB   494 _EXEN2	=	0x00cb
                           0000CC   495 _TCLK	=	0x00cc
                           0000CD   496 _RCLK	=	0x00cd
                           0000CE   497 _EXF2	=	0x00ce
                           0000CF   498 _TF2	=	0x00cf
                           0000D0   499 _P	=	0x00d0
                           0000D1   500 _FL	=	0x00d1
                           0000D2   501 _OV	=	0x00d2
                           0000D3   502 _RS0	=	0x00d3
                           0000D4   503 _RS1	=	0x00d4
                           0000D5   504 _F0	=	0x00d5
                           0000D6   505 _AC	=	0x00d6
                           0000D7   506 _CY	=	0x00d7
                           0000DB   507 _INT6	=	0x00db
                           0000DC   508 _RESI	=	0x00dc
                           0000DD   509 _ERESI	=	0x00dd
                           0000DF   510 _SMOD1	=	0x00df
                           0000E8   511 _EUSB	=	0x00e8
                           0000E9   512 _EI2C	=	0x00e9
                           0000EA   513 _EIEX4	=	0x00ea
                           0000EB   514 _EIEX5	=	0x00eb
                           0000EC   515 _EIEX6	=	0x00ec
                           0000F8   516 _PUSB	=	0x00f8
                           0000F9   517 _PI2C	=	0x00f9
                           0000FA   518 _EIPX4	=	0x00fa
                           0000FB   519 _EIPX5	=	0x00fb
                           0000FC   520 _EIPX6	=	0x00fc
                                    521 ;--------------------------------------------------------
                                    522 ; overlayable register banks
                                    523 ;--------------------------------------------------------
                                    524 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        525 	.ds 8
                                    526 ;--------------------------------------------------------
                                    527 ; internal ram data
                                    528 ;--------------------------------------------------------
                                    529 	.area DSEG    (DATA)
      000008                        530 _boot_ifconfig_snapshot::
      000008                        531 	.ds 1
                                    532 ;--------------------------------------------------------
                                    533 ; overlayable items in internal ram
                                    534 ;--------------------------------------------------------
                                    535 	.area	OSEG    (OVR,DATA)
                                    536 ;--------------------------------------------------------
                                    537 ; Stack segment in internal ram
                                    538 ;--------------------------------------------------------
                                    539 	.area SSEG
      000021                        540 __start__stack:
      000021                        541 	.ds	1
                                    542 
                                    543 ;--------------------------------------------------------
                                    544 ; indirectly addressable internal ram data
                                    545 ;--------------------------------------------------------
                                    546 	.area ISEG    (DATA)
                                    547 ;--------------------------------------------------------
                                    548 ; absolute internal ram data
                                    549 ;--------------------------------------------------------
                                    550 	.area IABS    (ABS,DATA)
                                    551 	.area IABS    (ABS,DATA)
                                    552 ;--------------------------------------------------------
                                    553 ; bit data
                                    554 ;--------------------------------------------------------
                                    555 	.area BSEG    (BIT)
                                    556 ;--------------------------------------------------------
                                    557 ; paged external ram data
                                    558 ;--------------------------------------------------------
                                    559 	.area PSEG    (PAG,XDATA)
                                    560 ;--------------------------------------------------------
                                    561 ; uninitialized external ram data
                                    562 ;--------------------------------------------------------
                                    563 	.area XSEG    (XDATA)
                           00E400   564 _GPIF_WAVE_DATA	=	0xe400
                           00E480   565 _RES_WAVEDATA_END	=	0xe480
                           00E600   566 _CPUCS	=	0xe600
                           00E601   567 _IFCONFIG	=	0xe601
                           00E602   568 _PINFLAGSAB	=	0xe602
                           00E603   569 _PINFLAGSCD	=	0xe603
                           00E604   570 _FIFORESET	=	0xe604
                           00E605   571 _BREAKPT	=	0xe605
                           00E606   572 _BPADDRH	=	0xe606
                           00E607   573 _BPADDRL	=	0xe607
                           00E608   574 _UART230	=	0xe608
                           00E609   575 _FIFOPINPOLAR	=	0xe609
                           00E60A   576 _REVID	=	0xe60a
                           00E60B   577 _REVCTL	=	0xe60b
                           00E610   578 _EP1OUTCFG	=	0xe610
                           00E611   579 _EP1INCFG	=	0xe611
                           00E612   580 _EP2CFG	=	0xe612
                           00E613   581 _EP4CFG	=	0xe613
                           00E614   582 _EP6CFG	=	0xe614
                           00E615   583 _EP8CFG	=	0xe615
                           00E618   584 _EP2FIFOCFG	=	0xe618
                           00E619   585 _EP4FIFOCFG	=	0xe619
                           00E61A   586 _EP6FIFOCFG	=	0xe61a
                           00E61B   587 _EP8FIFOCFG	=	0xe61b
                           00E620   588 _EP2AUTOINLENH	=	0xe620
                           00E621   589 _EP2AUTOINLENL	=	0xe621
                           00E622   590 _EP4AUTOINLENH	=	0xe622
                           00E623   591 _EP4AUTOINLENL	=	0xe623
                           00E624   592 _EP6AUTOINLENH	=	0xe624
                           00E625   593 _EP6AUTOINLENL	=	0xe625
                           00E626   594 _EP8AUTOINLENH	=	0xe626
                           00E627   595 _EP8AUTOINLENL	=	0xe627
                           00E630   596 _EP2FIFOPFH	=	0xe630
                           00E631   597 _EP2FIFOPFL	=	0xe631
                           00E632   598 _EP4FIFOPFH	=	0xe632
                           00E633   599 _EP4FIFOPFL	=	0xe633
                           00E634   600 _EP6FIFOPFH	=	0xe634
                           00E635   601 _EP6FIFOPFL	=	0xe635
                           00E636   602 _EP8FIFOPFH	=	0xe636
                           00E637   603 _EP8FIFOPFL	=	0xe637
                           00E640   604 _EP2ISOINPKTS	=	0xe640
                           00E641   605 _EP4ISOINPKTS	=	0xe641
                           00E642   606 _EP6ISOINPKTS	=	0xe642
                           00E643   607 _EP8ISOINPKTS	=	0xe643
                           00E648   608 _INPKTEND	=	0xe648
                           00E649   609 _OUTPKTEND	=	0xe649
                           00E650   610 _EP2FIFOIE	=	0xe650
                           00E651   611 _EP2FIFOIRQ	=	0xe651
                           00E652   612 _EP4FIFOIE	=	0xe652
                           00E653   613 _EP4FIFOIRQ	=	0xe653
                           00E654   614 _EP6FIFOIE	=	0xe654
                           00E655   615 _EP6FIFOIRQ	=	0xe655
                           00E656   616 _EP8FIFOIE	=	0xe656
                           00E657   617 _EP8FIFOIRQ	=	0xe657
                           00E658   618 _IBNIE	=	0xe658
                           00E659   619 _IBNIRQ	=	0xe659
                           00E65A   620 _NAKIE	=	0xe65a
                           00E65B   621 _NAKIRQ	=	0xe65b
                           00E65C   622 _USBIE	=	0xe65c
                           00E65D   623 _USBIRQ	=	0xe65d
                           00E65E   624 _EPIE	=	0xe65e
                           00E65F   625 _EPIRQ	=	0xe65f
                           00E660   626 _GPIFIE	=	0xe660
                           00E661   627 _GPIFIRQ	=	0xe661
                           00E662   628 _USBERRIE	=	0xe662
                           00E663   629 _USBERRIRQ	=	0xe663
                           00E664   630 _ERRCNTLIM	=	0xe664
                           00E665   631 _CLRERRCNT	=	0xe665
                           00E666   632 _INT2IVEC	=	0xe666
                           00E667   633 _INT4IVEC	=	0xe667
                           00E668   634 _INTSETUP	=	0xe668
                           00E670   635 _PORTACFG	=	0xe670
                           00E671   636 _PORTCCFG	=	0xe671
                           00E672   637 _PORTECFG	=	0xe672
                           00E678   638 _I2CS	=	0xe678
                           00E679   639 _I2DAT	=	0xe679
                           00E67A   640 _I2CTL	=	0xe67a
                           00E67B   641 _XAUTODAT1	=	0xe67b
                           00E67C   642 _XAUTODAT2	=	0xe67c
                           00E680   643 _USBCS	=	0xe680
                           00E681   644 _SUSPEND	=	0xe681
                           00E682   645 _WAKEUPCS	=	0xe682
                           00E683   646 _TOGCTL	=	0xe683
                           00E684   647 _USBFRAMEH	=	0xe684
                           00E685   648 _USBFRAMEL	=	0xe685
                           00E686   649 _MICROFRAME	=	0xe686
                           00E687   650 _FNADDR	=	0xe687
                           00E68A   651 _EP0BCH	=	0xe68a
                           00E68B   652 _EP0BCL	=	0xe68b
                           00E68D   653 _EP1OUTBC	=	0xe68d
                           00E68F   654 _EP1INBC	=	0xe68f
                           00E690   655 _EP2BCH	=	0xe690
                           00E691   656 _EP2BCL	=	0xe691
                           00E694   657 _EP4BCH	=	0xe694
                           00E695   658 _EP4BCL	=	0xe695
                           00E698   659 _EP6BCH	=	0xe698
                           00E699   660 _EP6BCL	=	0xe699
                           00E69C   661 _EP8BCH	=	0xe69c
                           00E69D   662 _EP8BCL	=	0xe69d
                           00E6A0   663 _EP0CS	=	0xe6a0
                           00E6A1   664 _EP1OUTCS	=	0xe6a1
                           00E6A2   665 _EP1INCS	=	0xe6a2
                           00E6A3   666 _EP2CS	=	0xe6a3
                           00E6A4   667 _EP4CS	=	0xe6a4
                           00E6A5   668 _EP6CS	=	0xe6a5
                           00E6A6   669 _EP8CS	=	0xe6a6
                           00E6A7   670 _EP2FIFOFLGS	=	0xe6a7
                           00E6A8   671 _EP4FIFOFLGS	=	0xe6a8
                           00E6A9   672 _EP6FIFOFLGS	=	0xe6a9
                           00E6AA   673 _EP8FIFOFLGS	=	0xe6aa
                           00E6AB   674 _EP2FIFOBCH	=	0xe6ab
                           00E6AC   675 _EP2FIFOBCL	=	0xe6ac
                           00E6AD   676 _EP4FIFOBCH	=	0xe6ad
                           00E6AE   677 _EP4FIFOBCL	=	0xe6ae
                           00E6AF   678 _EP6FIFOBCH	=	0xe6af
                           00E6B0   679 _EP6FIFOBCL	=	0xe6b0
                           00E6B1   680 _EP8FIFOBCH	=	0xe6b1
                           00E6B2   681 _EP8FIFOBCL	=	0xe6b2
                           00E6B3   682 _SUDPTRH	=	0xe6b3
                           00E6B4   683 _SUDPTRL	=	0xe6b4
                           00E6B5   684 _SUDPTRCTL	=	0xe6b5
                           00E6B8   685 _SETUPDAT	=	0xe6b8
                           00E6C0   686 _GPIFWFSELECT	=	0xe6c0
                           00E6C1   687 _GPIFIDLECS	=	0xe6c1
                           00E6C2   688 _GPIFIDLECTL	=	0xe6c2
                           00E6C3   689 _GPIFCTLCFG	=	0xe6c3
                           00E6C4   690 _GPIFADRH	=	0xe6c4
                           00E6C5   691 _GPIFADRL	=	0xe6c5
                           00E6CE   692 _GPIFTCB3	=	0xe6ce
                           00E6CF   693 _GPIFTCB2	=	0xe6cf
                           00E6D0   694 _GPIFTCB1	=	0xe6d0
                           00E6D1   695 _GPIFTCB0	=	0xe6d1
                           00E6D2   696 _EP2GPIFFLGSEL	=	0xe6d2
                           00E6D3   697 _EP2GPIFPFSTOP	=	0xe6d3
                           00E6D4   698 _EP2GPIFTRIG	=	0xe6d4
                           00E6DA   699 _EP4GPIFFLGSEL	=	0xe6da
                           00E6DB   700 _EP4GPIFPFSTOP	=	0xe6db
                           00E6DC   701 _EP4GPIFTRIG	=	0xe6dc
                           00E6E2   702 _EP6GPIFFLGSEL	=	0xe6e2
                           00E6E3   703 _EP6GPIFPFSTOP	=	0xe6e3
                           00E6E4   704 _EP6GPIFTRIG	=	0xe6e4
                           00E6EA   705 _EP8GPIFFLGSEL	=	0xe6ea
                           00E6EB   706 _EP8GPIFPFSTOP	=	0xe6eb
                           00E6EC   707 _EP8GPIFTRIG	=	0xe6ec
                           00E6F0   708 _XGPIFSGLDATH	=	0xe6f0
                           00E6F1   709 _XGPIFSGLDATLX	=	0xe6f1
                           00E6F2   710 _XGPIFSGLDATLNOX	=	0xe6f2
                           00E6F3   711 _GPIFREADYCFG	=	0xe6f3
                           00E6F4   712 _GPIFREADYSTAT	=	0xe6f4
                           00E6F5   713 _GPIFABORT	=	0xe6f5
                           00E6C6   714 _FLOWSTATE	=	0xe6c6
                           00E6C7   715 _FLOWLOGIC	=	0xe6c7
                           00E6C8   716 _FLOWEQ0CTL	=	0xe6c8
                           00E6C9   717 _FLOWEQ1CTL	=	0xe6c9
                           00E6CA   718 _FLOWHOLDOFF	=	0xe6ca
                           00E6CB   719 _FLOWSTB	=	0xe6cb
                           00E6CC   720 _FLOWSTBEDGE	=	0xe6cc
                           00E6CD   721 _FLOWSTBHPERIOD	=	0xe6cd
                           00E60C   722 _GPIFHOLDAMOUNT	=	0xe60c
                           00E67D   723 _UDMACRCH	=	0xe67d
                           00E67E   724 _UDMACRCL	=	0xe67e
                           00E67F   725 _UDMACRCQUAL	=	0xe67f
                           00E740   726 _EP0BUF	=	0xe740
                           00E780   727 _EP1OUTBUF	=	0xe780
                           00E7C0   728 _EP1INBUF	=	0xe7c0
                           00F000   729 _EP2FIFOBUF	=	0xf000
                           00F400   730 _EP4FIFOBUF	=	0xf400
                           00F800   731 _EP6FIFOBUF	=	0xf800
                           00FC00   732 _EP8FIFOBUF	=	0xfc00
                           00E628   733 _ECCCFG	=	0xe628
                           00E629   734 _ECCRESET	=	0xe629
                           00E62A   735 _ECC1B0	=	0xe62a
                           00E62B   736 _ECC1B1	=	0xe62b
                           00E62C   737 _ECC1B2	=	0xe62c
                           00E62D   738 _ECC2B0	=	0xe62d
                           00E62E   739 _ECC2B1	=	0xe62e
                           00E62F   740 _ECC2B2	=	0xe62f
                           00E50D   741 _GPCR2	=	0xe50d
                                    742 ;--------------------------------------------------------
                                    743 ; absolute external ram data
                                    744 ;--------------------------------------------------------
                                    745 	.area XABS    (ABS,XDATA)
                                    746 ;--------------------------------------------------------
                                    747 ; initialized external ram data
                                    748 ;--------------------------------------------------------
                                    749 	.area XISEG   (XDATA)
                                    750 	.area HOME    (CODE)
                                    751 	.area GSINIT0 (CODE)
                                    752 	.area GSINIT1 (CODE)
                                    753 	.area GSINIT2 (CODE)
                                    754 	.area GSINIT3 (CODE)
                                    755 	.area GSINIT4 (CODE)
                                    756 	.area GSINIT5 (CODE)
                                    757 	.area GSINIT  (CODE)
                                    758 	.area GSFINAL (CODE)
                                    759 	.area CSEG    (CODE)
                                    760 ;--------------------------------------------------------
                                    761 ; interrupt vector
                                    762 ;--------------------------------------------------------
                                    763 	.area HOME    (CODE)
      000000                        764 __interrupt_vect:
      000000 02 00 06         [24]  765 	ljmp	__sdcc_gsinit_startup
                                    766 ;--------------------------------------------------------
                                    767 ; global & static initialisations
                                    768 ;--------------------------------------------------------
                                    769 	.area HOME    (CODE)
                                    770 	.area GSINIT  (CODE)
                                    771 	.area GSFINAL (CODE)
                                    772 	.area GSINIT  (CODE)
                                    773 	.globl __sdcc_gsinit_startup
                                    774 	.globl __sdcc_program_startup
                                    775 	.globl __start__stack
                                    776 	.globl __mcs51_genXINIT
                                    777 	.globl __mcs51_genXRAMCLEAR
                                    778 	.globl __mcs51_genRAMCLEAR
                                    779 ;	src/main.c:97: BYTE boot_ifconfig_snapshot = 0x00;
      00005F 75 08 00         [24]  780 	mov	_boot_ifconfig_snapshot,#0x00
                                    781 	.area GSFINAL (CODE)
      000074 02 00 03         [24]  782 	ljmp	__sdcc_program_startup
                                    783 ;--------------------------------------------------------
                                    784 ; Home
                                    785 ;--------------------------------------------------------
                                    786 	.area HOME    (CODE)
                                    787 	.area HOME    (CODE)
      000003                        788 __sdcc_program_startup:
      000003 02 01 EC         [24]  789 	ljmp	_main
                                    790 ;	return from main will return to caller
                                    791 ;--------------------------------------------------------
                                    792 ; code
                                    793 ;--------------------------------------------------------
                                    794 	.area CSEG    (CODE)
                                    795 ;------------------------------------------------------------
                                    796 ;Allocation info for local variables in function 'handle_vendorcommand'
                                    797 ;------------------------------------------------------------
                                    798 ;cmd                       Allocated to registers r7 
                                    799 ;mask                      Allocated to registers r6 
                                    800 ;val                       Allocated to registers r5 
                                    801 ;_mcur                     Allocated to registers 
                                    802 ;_mcur                     Allocated to registers 
                                    803 ;_mcur                     Allocated to registers 
                                    804 ;_mcur                     Allocated to registers 
                                    805 ;------------------------------------------------------------
                                    806 ;	src/main.c:41: BOOL handle_vendorcommand(BYTE cmd) {
                                    807 ;	-----------------------------------------
                                    808 ;	 function handle_vendorcommand
                                    809 ;	-----------------------------------------
      000077                        810 _handle_vendorcommand:
                           000007   811 	ar7 = 0x07
                           000006   812 	ar6 = 0x06
                           000005   813 	ar5 = 0x05
                           000004   814 	ar4 = 0x04
                           000003   815 	ar3 = 0x03
                           000002   816 	ar2 = 0x02
                           000001   817 	ar1 = 0x01
                           000000   818 	ar0 = 0x00
      000077 AF 82            [24]  819 	mov	r7, dpl
                                    820 ;	src/main.c:42: switch(cmd) {
      000079 BF B0 00         [24]  821 	cjne	r7,#0xb0,00181$
      00007C                        822 00181$:
      00007C 50 03            [24]  823 	jnc	00182$
      00007E 02 01 E8         [24]  824 	ljmp	00136$
      000081                        825 00182$:
      000081 EF               [12]  826 	mov	a,r7
      000082 24 44            [12]  827 	add	a,#0xff - 0xbb
      000084 50 03            [24]  828 	jnc	00183$
      000086 02 01 E8         [24]  829 	ljmp	00136$
      000089                        830 00183$:
      000089 EF               [12]  831 	mov	a,r7
      00008A 24 50            [12]  832 	add	a,#0x50
      00008C FE               [12]  833 	mov	r6,a
      00008D 24 0A            [12]  834 	add	a,#(00184$-3-.)
      00008F 83               [24]  835 	movc	a,@a+pc
      000090 F5 82            [12]  836 	mov	dpl,a
      000092 EE               [12]  837 	mov	a,r6
      000093 24 10            [12]  838 	add	a,#(00185$-3-.)
      000095 83               [24]  839 	movc	a,@a+pc
      000096 F5 83            [12]  840 	mov	dph,a
      000098 E4               [12]  841 	clr	a
      000099 73               [24]  842 	jmp	@a+dptr
      00009A                        843 00184$:
      00009A B2                     844 	.db	00104$
      00009B 1B                     845 	.db	00128$
      00009C B2                     846 	.db	00104$
      00009D 2D                     847 	.db	00129$
      00009E B2                     848 	.db	00104$
      00009F 3F                     849 	.db	00130$
      0000A0 B2                     850 	.db	00104$
      0000A1 4F                     851 	.db	00131$
      0000A2 5F                     852 	.db	00132$
      0000A3 82                     853 	.db	00133$
      0000A4 A5                     854 	.db	00134$
      0000A5 C8                     855 	.db	00135$
      0000A6                        856 00185$:
      0000A6 00                     857 	.db	00104$>>8
      0000A7 01                     858 	.db	00128$>>8
      0000A8 00                     859 	.db	00104$>>8
      0000A9 01                     860 	.db	00129$>>8
      0000AA 00                     861 	.db	00104$>>8
      0000AB 01                     862 	.db	00130$>>8
      0000AC 00                     863 	.db	00104$>>8
      0000AD 01                     864 	.db	00131$>>8
      0000AE 01                     865 	.db	00132$>>8
      0000AF 01                     866 	.db	00133$>>8
      0000B0 01                     867 	.db	00134$>>8
      0000B1 01                     868 	.db	00135$>>8
                                    869 ;	src/main.c:46: case 0xB6: // SET OEA
      0000B2                        870 00104$:
                                    871 ;	src/main.c:49: if(EP0BCL != 2) return FALSE; // not enough data yet
      0000B2 90 E6 8B         [24]  872 	mov	dptr,#_EP0BCL
      0000B5 E0               [24]  873 	movx	a,@dptr
      0000B6 FE               [12]  874 	mov	r6,a
      0000B7 BE 02 02         [24]  875 	cjne	r6,#0x02,00186$
      0000BA 80 04            [24]  876 	sjmp	00106$
      0000BC                        877 00186$:
      0000BC 75 82 00         [24]  878 	mov	dpl, #0x00
      0000BF 22               [24]  879 	ret
      0000C0                        880 00106$:
                                    881 ;	src/main.c:50: BYTE mask = EP0BUF[0];
      0000C0 90 E7 40         [24]  882 	mov	dptr,#_EP0BUF
      0000C3 E0               [24]  883 	movx	a,@dptr
      0000C4 FE               [12]  884 	mov	r6,a
                                    885 ;	src/main.c:51: BYTE val  = EP0BUF[1];
      0000C5 90 E7 41         [24]  886 	mov	dptr,#(_EP0BUF + 0x0001)
      0000C8 E0               [24]  887 	movx	a,@dptr
      0000C9 FD               [12]  888 	mov	r5,a
                                    889 ;	src/main.c:52: if(cmd == 0xB0) FX2_MASKED_WRITE(CPUCS, mask, val);
      0000CA BF B0 14         [24]  890 	cjne	r7,#0xb0,00126$
      0000CD 90 E6 00         [24]  891 	mov	dptr,#_CPUCS
      0000D0 E0               [24]  892 	movx	a,@dptr
      0000D1 FC               [12]  893 	mov	r4,a
      0000D2 EE               [12]  894 	mov	a,r6
      0000D3 F4               [12]  895 	cpl	a
      0000D4 FB               [12]  896 	mov	r3,a
      0000D5 EC               [12]  897 	mov	a,r4
      0000D6 52 03            [12]  898 	anl	ar3,a
      0000D8 EE               [12]  899 	mov	a,r6
      0000D9 5D               [12]  900 	anl	a,r5
      0000DA 90 E6 00         [24]  901 	mov	dptr,#_CPUCS
      0000DD 4B               [12]  902 	orl	a,r3
      0000DE F0               [24]  903 	movx	@dptr,a
      0000DF 80 36            [24]  904 	sjmp	00127$
      0000E1                        905 00126$:
                                    906 ;	src/main.c:53: else if(cmd == 0xB2) FX2_MASKED_WRITE(IFCONFIG, mask, val);
      0000E1 BF B2 14         [24]  907 	cjne	r7,#0xb2,00123$
      0000E4 90 E6 01         [24]  908 	mov	dptr,#_IFCONFIG
      0000E7 E0               [24]  909 	movx	a,@dptr
      0000E8 FC               [12]  910 	mov	r4,a
      0000E9 EE               [12]  911 	mov	a,r6
      0000EA F4               [12]  912 	cpl	a
      0000EB FB               [12]  913 	mov	r3,a
      0000EC EC               [12]  914 	mov	a,r4
      0000ED 52 03            [12]  915 	anl	ar3,a
      0000EF EE               [12]  916 	mov	a,r6
      0000F0 5D               [12]  917 	anl	a,r5
      0000F1 90 E6 01         [24]  918 	mov	dptr,#_IFCONFIG
      0000F4 4B               [12]  919 	orl	a,r3
      0000F5 F0               [24]  920 	movx	@dptr,a
      0000F6 80 1F            [24]  921 	sjmp	00127$
      0000F8                        922 00123$:
                                    923 ;	src/main.c:54: else if(cmd == 0xB4) FX2_MASKED_WRITE(IOA, mask, val);
      0000F8 BF B4 0F         [24]  924 	cjne	r7,#0xb4,00116$
      0000FB AF 80            [24]  925 	mov	r7,_IOA
      0000FD EE               [12]  926 	mov	a,r6
      0000FE F4               [12]  927 	cpl	a
      0000FF FC               [12]  928 	mov	r4,a
      000100 EF               [12]  929 	mov	a,r7
      000101 52 04            [12]  930 	anl	ar4,a
      000103 EE               [12]  931 	mov	a,r6
      000104 5D               [12]  932 	anl	a,r5
      000105 4C               [12]  933 	orl	a,r4
      000106 F5 80            [12]  934 	mov	_IOA,a
                                    935 ;	src/main.c:55: else FX2_MASKED_WRITE(OEA, mask, val);
      000108 80 0D            [24]  936 	sjmp	00127$
      00010A                        937 00116$:
      00010A AF B2            [24]  938 	mov	r7,_OEA
      00010C EE               [12]  939 	mov	a,r6
      00010D F4               [12]  940 	cpl	a
      00010E FC               [12]  941 	mov	r4,a
      00010F EF               [12]  942 	mov	a,r7
      000110 52 04            [12]  943 	anl	ar4,a
      000112 EE               [12]  944 	mov	a,r6
      000113 5D               [12]  945 	anl	a,r5
      000114 4C               [12]  946 	orl	a,r4
      000115 F5 B2            [12]  947 	mov	_OEA,a
      000117                        948 00127$:
                                    949 ;	src/main.c:56: return TRUE;
      000117 75 82 01         [24]  950 	mov	dpl, #0x01
      00011A 22               [24]  951 	ret
                                    952 ;	src/main.c:58: case 0xB1: // GET CPUCS
      00011B                        953 00128$:
                                    954 ;	src/main.c:59: EP0BUF[0] = CPUCS; EP0BCL = 1; return TRUE;
      00011B 90 E6 00         [24]  955 	mov	dptr,#_CPUCS
      00011E E0               [24]  956 	movx	a,@dptr
      00011F 90 E7 40         [24]  957 	mov	dptr,#_EP0BUF
      000122 F0               [24]  958 	movx	@dptr,a
      000123 90 E6 8B         [24]  959 	mov	dptr,#_EP0BCL
      000126 74 01            [12]  960 	mov	a,#0x01
      000128 F0               [24]  961 	movx	@dptr,a
      000129 75 82 01         [24]  962 	mov	dpl, #0x01
      00012C 22               [24]  963 	ret
                                    964 ;	src/main.c:60: case 0xB3: // GET IFCONFIG
      00012D                        965 00129$:
                                    966 ;	src/main.c:61: EP0BUF[0] = IFCONFIG; EP0BCL = 1; return TRUE;
      00012D 90 E6 01         [24]  967 	mov	dptr,#_IFCONFIG
      000130 E0               [24]  968 	movx	a,@dptr
      000131 90 E7 40         [24]  969 	mov	dptr,#_EP0BUF
      000134 F0               [24]  970 	movx	@dptr,a
      000135 90 E6 8B         [24]  971 	mov	dptr,#_EP0BCL
      000138 74 01            [12]  972 	mov	a,#0x01
      00013A F0               [24]  973 	movx	@dptr,a
      00013B 75 82 01         [24]  974 	mov	dpl, #0x01
      00013E 22               [24]  975 	ret
                                    976 ;	src/main.c:62: case 0xB5: // GET PORTA
      00013F                        977 00130$:
                                    978 ;	src/main.c:63: EP0BUF[0] = IOA; EP0BCL = 1; return TRUE;
      00013F 90 E7 40         [24]  979 	mov	dptr,#_EP0BUF
      000142 E5 80            [12]  980 	mov	a,_IOA
      000144 F0               [24]  981 	movx	@dptr,a
      000145 90 E6 8B         [24]  982 	mov	dptr,#_EP0BCL
      000148 74 01            [12]  983 	mov	a,#0x01
      00014A F0               [24]  984 	movx	@dptr,a
      00014B 75 82 01         [24]  985 	mov	dpl, #0x01
      00014E 22               [24]  986 	ret
                                    987 ;	src/main.c:64: case 0xB7: // GET OEA
      00014F                        988 00131$:
                                    989 ;	src/main.c:65: EP0BUF[0] = OEA; EP0BCL = 1; return TRUE;
      00014F 90 E7 40         [24]  990 	mov	dptr,#_EP0BUF
      000152 E5 B2            [12]  991 	mov	a,_OEA
      000154 F0               [24]  992 	movx	@dptr,a
      000155 90 E6 8B         [24]  993 	mov	dptr,#_EP0BCL
      000158 74 01            [12]  994 	mov	a,#0x01
      00015A F0               [24]  995 	movx	@dptr,a
      00015B 75 82 01         [24]  996 	mov	dpl, #0x01
      00015E 22               [24]  997 	ret
                                    998 ;	src/main.c:66: case 0xB8: // GET EP6CS (FIFO status)
      00015F                        999 00132$:
                                   1000 ;	src/main.c:67: EP0BUF[0] = EP6CS; SD(); EP0BCL = 1; SD(); return TRUE;
      00015F 90 E6 A5         [24] 1001 	mov	dptr,#_EP6CS
      000162 E0               [24] 1002 	movx	a,@dptr
      000163 FF               [12] 1003 	mov	r7,a
      000164 90 E7 40         [24] 1004 	mov	dptr,#_EP0BUF
      000167 F0               [24] 1005 	movx	@dptr,a
      000168 00               [12] 1006 	nop	
      000169 00               [12] 1007 	nop	
      00016A 00               [12] 1008 	nop	
      00016B 00               [12] 1009 	nop	
      00016C 00               [12] 1010 	nop	
      00016D 00               [12] 1011 	nop	
      00016E 00               [12] 1012 	nop	
      00016F 00               [12] 1013 	nop	
      000170 90 E6 8B         [24] 1014 	mov	dptr,#_EP0BCL
      000173 74 01            [12] 1015 	mov	a,#0x01
      000175 F0               [24] 1016 	movx	@dptr,a
      000176 00               [12] 1017 	nop	
      000177 00               [12] 1018 	nop	
      000178 00               [12] 1019 	nop	
      000179 00               [12] 1020 	nop	
      00017A 00               [12] 1021 	nop	
      00017B 00               [12] 1022 	nop	
      00017C 00               [12] 1023 	nop	
      00017D 00               [12] 1024 	nop	
      00017E 75 82 01         [24] 1025 	mov	dpl, #0x01
                                   1026 ;	src/main.c:68: case 0xB9: // GET PINFLAGSAB
      000181 22               [24] 1027 	ret
      000182                       1028 00133$:
                                   1029 ;	src/main.c:69: EP0BUF[0] = PINFLAGSAB; SD(); EP0BCL = 1; SD(); return TRUE;
      000182 90 E6 02         [24] 1030 	mov	dptr,#_PINFLAGSAB
      000185 E0               [24] 1031 	movx	a,@dptr
      000186 FF               [12] 1032 	mov	r7,a
      000187 90 E7 40         [24] 1033 	mov	dptr,#_EP0BUF
      00018A F0               [24] 1034 	movx	@dptr,a
      00018B 00               [12] 1035 	nop	
      00018C 00               [12] 1036 	nop	
      00018D 00               [12] 1037 	nop	
      00018E 00               [12] 1038 	nop	
      00018F 00               [12] 1039 	nop	
      000190 00               [12] 1040 	nop	
      000191 00               [12] 1041 	nop	
      000192 00               [12] 1042 	nop	
      000193 90 E6 8B         [24] 1043 	mov	dptr,#_EP0BCL
      000196 74 01            [12] 1044 	mov	a,#0x01
      000198 F0               [24] 1045 	movx	@dptr,a
      000199 00               [12] 1046 	nop	
      00019A 00               [12] 1047 	nop	
      00019B 00               [12] 1048 	nop	
      00019C 00               [12] 1049 	nop	
      00019D 00               [12] 1050 	nop	
      00019E 00               [12] 1051 	nop	
      00019F 00               [12] 1052 	nop	
      0001A0 00               [12] 1053 	nop	
      0001A1 75 82 01         [24] 1054 	mov	dpl, #0x01
                                   1055 ;	src/main.c:70: case 0xBA: // GET PINFLAGSCD
      0001A4 22               [24] 1056 	ret
      0001A5                       1057 00134$:
                                   1058 ;	src/main.c:71: EP0BUF[0] = PINFLAGSCD; SD(); EP0BCL = 1; SD(); return TRUE;
      0001A5 90 E6 03         [24] 1059 	mov	dptr,#_PINFLAGSCD
      0001A8 E0               [24] 1060 	movx	a,@dptr
      0001A9 FF               [12] 1061 	mov	r7,a
      0001AA 90 E7 40         [24] 1062 	mov	dptr,#_EP0BUF
      0001AD F0               [24] 1063 	movx	@dptr,a
      0001AE 00               [12] 1064 	nop	
      0001AF 00               [12] 1065 	nop	
      0001B0 00               [12] 1066 	nop	
      0001B1 00               [12] 1067 	nop	
      0001B2 00               [12] 1068 	nop	
      0001B3 00               [12] 1069 	nop	
      0001B4 00               [12] 1070 	nop	
      0001B5 00               [12] 1071 	nop	
      0001B6 90 E6 8B         [24] 1072 	mov	dptr,#_EP0BCL
      0001B9 74 01            [12] 1073 	mov	a,#0x01
      0001BB F0               [24] 1074 	movx	@dptr,a
      0001BC 00               [12] 1075 	nop	
      0001BD 00               [12] 1076 	nop	
      0001BE 00               [12] 1077 	nop	
      0001BF 00               [12] 1078 	nop	
      0001C0 00               [12] 1079 	nop	
      0001C1 00               [12] 1080 	nop	
      0001C2 00               [12] 1081 	nop	
      0001C3 00               [12] 1082 	nop	
      0001C4 75 82 01         [24] 1083 	mov	dpl, #0x01
                                   1084 ;	src/main.c:72: case 0xBB: // GET IFCONFIG snapshot
      0001C7 22               [24] 1085 	ret
      0001C8                       1086 00135$:
                                   1087 ;	src/main.c:74: EP0BUF[0] = boot_ifconfig_snapshot; SD(); EP0BCL = 1; SD(); return TRUE;
      0001C8 90 E7 40         [24] 1088 	mov	dptr,#_EP0BUF
      0001CB E5 08            [12] 1089 	mov	a,_boot_ifconfig_snapshot
      0001CD F0               [24] 1090 	movx	@dptr,a
      0001CE 00               [12] 1091 	nop	
      0001CF 00               [12] 1092 	nop	
      0001D0 00               [12] 1093 	nop	
      0001D1 00               [12] 1094 	nop	
      0001D2 00               [12] 1095 	nop	
      0001D3 00               [12] 1096 	nop	
      0001D4 00               [12] 1097 	nop	
      0001D5 00               [12] 1098 	nop	
      0001D6 90 E6 8B         [24] 1099 	mov	dptr,#_EP0BCL
      0001D9 74 01            [12] 1100 	mov	a,#0x01
      0001DB F0               [24] 1101 	movx	@dptr,a
      0001DC 00               [12] 1102 	nop	
      0001DD 00               [12] 1103 	nop	
      0001DE 00               [12] 1104 	nop	
      0001DF 00               [12] 1105 	nop	
      0001E0 00               [12] 1106 	nop	
      0001E1 00               [12] 1107 	nop	
      0001E2 00               [12] 1108 	nop	
      0001E3 00               [12] 1109 	nop	
      0001E4 75 82 01         [24] 1110 	mov	dpl, #0x01
                                   1111 ;	src/main.c:75: }
      0001E7 22               [24] 1112 	ret
      0001E8                       1113 00136$:
                                   1114 ;	src/main.c:76: return FALSE; // not handled
      0001E8 75 82 00         [24] 1115 	mov	dpl, #0x00
                                   1116 ;	src/main.c:77: }
      0001EB 22               [24] 1117 	ret
                                   1118 ;------------------------------------------------------------
                                   1119 ;Allocation info for local variables in function 'main'
                                   1120 ;------------------------------------------------------------
                                   1121 ;blink                     Allocated to registers r4 r5 r6 r7 
                                   1122 ;------------------------------------------------------------
                                   1123 ;	src/main.c:99: void main(void) {
                                   1124 ;	-----------------------------------------
                                   1125 ;	 function main
                                   1126 ;	-----------------------------------------
      0001EC                       1127 _main:
                                   1128 ;	src/main.c:107: CPUCS = 0x0A;  SD(); // 24 MHz, CLKOUT enabled
      0001EC 90 E6 00         [24] 1129 	mov	dptr,#_CPUCS
      0001EF 74 0A            [12] 1130 	mov	a,#0x0a
      0001F1 F0               [24] 1131 	movx	@dptr,a
      0001F2 00               [12] 1132 	nop	
      0001F3 00               [12] 1133 	nop	
      0001F4 00               [12] 1134 	nop	
      0001F5 00               [12] 1135 	nop	
      0001F6 00               [12] 1136 	nop	
      0001F7 00               [12] 1137 	nop	
      0001F8 00               [12] 1138 	nop	
      0001F9 00               [12] 1139 	nop	
                                   1140 ;	src/main.c:109: IFCONFIG = IFCONFIG_VALUE;  SYNCDELAY;
      0001FA 90 E6 01         [24] 1141 	mov	dptr,#_IFCONFIG
      0001FD 74 03            [12] 1142 	mov	a,#0x03
      0001FF F0               [24] 1143 	movx	@dptr,a
      000200 00               [12] 1144 	nop	
      000201 00               [12] 1145 	nop	
      000202 00               [12] 1146 	nop	
      000203 00               [12] 1147 	nop	
                                   1148 ;	src/main.c:113: boot_ifconfig_snapshot = IFCONFIG;
      000204 90 E6 01         [24] 1149 	mov	dptr,#_IFCONFIG
      000207 E0               [24] 1150 	movx	a,@dptr
      000208 F5 08            [12] 1151 	mov	_boot_ifconfig_snapshot,a
                                   1152 ;	src/main.c:115: REVCTL = 0x03;    SYNCDELAY;  // Enhanced Packet Handling (TRM recommendation for slave FIFO)
      00020A 90 E6 0B         [24] 1153 	mov	dptr,#_REVCTL
      00020D 74 03            [12] 1154 	mov	a,#0x03
      00020F F0               [24] 1155 	movx	@dptr,a
      000210 00               [12] 1156 	nop	
      000211 00               [12] 1157 	nop	
      000212 00               [12] 1158 	nop	
      000213 00               [12] 1159 	nop	
                                   1160 ;	src/main.c:118: EP6CFG = 0xE0;  SYNCDELAY; // 1110 0000: VALID + IN + BULK + Quad
      000214 90 E6 14         [24] 1161 	mov	dptr,#_EP6CFG
      000217 74 E0            [12] 1162 	mov	a,#0xe0
      000219 F0               [24] 1163 	movx	@dptr,a
      00021A 00               [12] 1164 	nop	
      00021B 00               [12] 1165 	nop	
      00021C 00               [12] 1166 	nop	
      00021D 00               [12] 1167 	nop	
                                   1168 ;	src/main.c:121: FIFORESET = 0x80;  SYNCDELAY;  // NAK all requests
      00021E 90 E6 04         [24] 1169 	mov	dptr,#_FIFORESET
      000221 74 80            [12] 1170 	mov	a,#0x80
      000223 F0               [24] 1171 	movx	@dptr,a
      000224 00               [12] 1172 	nop	
      000225 00               [12] 1173 	nop	
      000226 00               [12] 1174 	nop	
      000227 00               [12] 1175 	nop	
                                   1176 ;	src/main.c:122: FIFORESET = 0x82;  SYNCDELAY;  // Reset EP2
      000228 90 E6 04         [24] 1177 	mov	dptr,#_FIFORESET
      00022B 74 82            [12] 1178 	mov	a,#0x82
      00022D F0               [24] 1179 	movx	@dptr,a
      00022E 00               [12] 1180 	nop	
      00022F 00               [12] 1181 	nop	
      000230 00               [12] 1182 	nop	
      000231 00               [12] 1183 	nop	
                                   1184 ;	src/main.c:123: FIFORESET = 0x84;  SYNCDELAY;  // Reset EP4
      000232 90 E6 04         [24] 1185 	mov	dptr,#_FIFORESET
      000235 74 84            [12] 1186 	mov	a,#0x84
      000237 F0               [24] 1187 	movx	@dptr,a
      000238 00               [12] 1188 	nop	
      000239 00               [12] 1189 	nop	
      00023A 00               [12] 1190 	nop	
      00023B 00               [12] 1191 	nop	
                                   1192 ;	src/main.c:124: FIFORESET = 0x86;  SYNCDELAY;  // Reset EP6
      00023C 90 E6 04         [24] 1193 	mov	dptr,#_FIFORESET
      00023F 74 86            [12] 1194 	mov	a,#0x86
      000241 F0               [24] 1195 	movx	@dptr,a
      000242 00               [12] 1196 	nop	
      000243 00               [12] 1197 	nop	
      000244 00               [12] 1198 	nop	
      000245 00               [12] 1199 	nop	
                                   1200 ;	src/main.c:125: FIFORESET = 0x88;  SYNCDELAY;  // Reset EP8
      000246 90 E6 04         [24] 1201 	mov	dptr,#_FIFORESET
      000249 74 88            [12] 1202 	mov	a,#0x88
      00024B F0               [24] 1203 	movx	@dptr,a
      00024C 00               [12] 1204 	nop	
      00024D 00               [12] 1205 	nop	
      00024E 00               [12] 1206 	nop	
      00024F 00               [12] 1207 	nop	
                                   1208 ;	src/main.c:126: FIFORESET = 0x00;  SYNCDELAY;  // Release NAKs
      000250 90 E6 04         [24] 1209 	mov	dptr,#_FIFORESET
      000253 E4               [12] 1210 	clr	a
      000254 F0               [24] 1211 	movx	@dptr,a
      000255 00               [12] 1212 	nop	
      000256 00               [12] 1213 	nop	
      000257 00               [12] 1214 	nop	
      000258 00               [12] 1215 	nop	
                                   1216 ;	src/main.c:129: EP6FIFOCFG = 0x0C;  SYNCDELAY;
      000259 90 E6 1A         [24] 1217 	mov	dptr,#_EP6FIFOCFG
      00025C 74 0C            [12] 1218 	mov	a,#0x0c
      00025E F0               [24] 1219 	movx	@dptr,a
      00025F 00               [12] 1220 	nop	
      000260 00               [12] 1221 	nop	
      000261 00               [12] 1222 	nop	
      000262 00               [12] 1223 	nop	
                                   1224 ;	src/main.c:132: PORTACFG = 0x00;  SYNCDELAY;
      000263 90 E6 70         [24] 1225 	mov	dptr,#_PORTACFG
      000266 E4               [12] 1226 	clr	a
      000267 F0               [24] 1227 	movx	@dptr,a
      000268 00               [12] 1228 	nop	
      000269 00               [12] 1229 	nop	
      00026A 00               [12] 1230 	nop	
      00026B 00               [12] 1231 	nop	
                                   1232 ;	src/main.c:135: FIFOPINPOLAR=0x00;  SYNCDELAY;
      00026C 90 E6 09         [24] 1233 	mov	dptr,#_FIFOPINPOLAR
      00026F E4               [12] 1234 	clr	a
      000270 F0               [24] 1235 	movx	@dptr,a
      000271 00               [12] 1236 	nop	
      000272 00               [12] 1237 	nop	
      000273 00               [12] 1238 	nop	
      000274 00               [12] 1239 	nop	
                                   1240 ;	src/main.c:138: EP6AUTOINLENH = 0x02; SYNCDELAY;  // MSB
      000275 90 E6 24         [24] 1241 	mov	dptr,#_EP6AUTOINLENH
      000278 74 02            [12] 1242 	mov	a,#0x02
      00027A F0               [24] 1243 	movx	@dptr,a
      00027B 00               [12] 1244 	nop	
      00027C 00               [12] 1245 	nop	
      00027D 00               [12] 1246 	nop	
      00027E 00               [12] 1247 	nop	
                                   1248 ;	src/main.c:139: EP6AUTOINLENL = 0x00; SYNCDELAY;  // LSB
      00027F 90 E6 25         [24] 1249 	mov	dptr,#_EP6AUTOINLENL
      000282 E4               [12] 1250 	clr	a
      000283 F0               [24] 1251 	movx	@dptr,a
      000284 00               [12] 1252 	nop	
      000285 00               [12] 1253 	nop	
      000286 00               [12] 1254 	nop	
      000287 00               [12] 1255 	nop	
                                   1256 ;	src/main.c:141: PINFLAGSAB = 0x00; SYNCDELAY; // No special flags on Port A/B pins  
      000288 90 E6 02         [24] 1257 	mov	dptr,#_PINFLAGSAB
      00028B E4               [12] 1258 	clr	a
      00028C F0               [24] 1259 	movx	@dptr,a
      00028D 00               [12] 1260 	nop	
      00028E 00               [12] 1261 	nop	
      00028F 00               [12] 1262 	nop	
      000290 00               [12] 1263 	nop	
                                   1264 ;	src/main.c:142: PINFLAGSCD = 0x00; SYNCDELAY; // No special flags on Port C/D pins
      000291 90 E6 03         [24] 1265 	mov	dptr,#_PINFLAGSCD
      000294 E4               [12] 1266 	clr	a
      000295 F0               [24] 1267 	movx	@dptr,a
      000296 00               [12] 1268 	nop	
      000297 00               [12] 1269 	nop	
      000298 00               [12] 1270 	nop	
      000299 00               [12] 1271 	nop	
                                   1272 ;	src/main.c:145: OEA |= 0x01; // PA0 output
      00029A 43 B2 01         [24] 1273 	orl	_OEA,#0x01
                                   1274 ;	src/main.c:148: unsigned long blink = 0UL;
      00029D 7C 00            [12] 1275 	mov	r4,#0x00
      00029F 7D 00            [12] 1276 	mov	r5,#0x00
      0002A1 7E 00            [12] 1277 	mov	r6,#0x00
      0002A3 7F 00            [12] 1278 	mov	r7,#0x00
      0002A5                       1279 00107$:
                                   1280 ;	src/main.c:151: handle_setupdata();
      0002A5 C0 07            [24] 1281 	push	ar7
      0002A7 C0 06            [24] 1282 	push	ar6
      0002A9 C0 05            [24] 1283 	push	ar5
      0002AB C0 04            [24] 1284 	push	ar4
      0002AD 12 03 74         [24] 1285 	lcall	_handle_setupdata
      0002B0 D0 04            [24] 1286 	pop	ar4
      0002B2 D0 05            [24] 1287 	pop	ar5
      0002B4 D0 06            [24] 1288 	pop	ar6
      0002B6 D0 07            [24] 1289 	pop	ar7
                                   1290 ;	src/main.c:152: if(++blink == 40000UL) { PA0 = 1; }
      0002B8 0C               [12] 1291 	inc	r4
      0002B9 BC 00 09         [24] 1292 	cjne	r4,#0x00,00129$
      0002BC 0D               [12] 1293 	inc	r5
      0002BD BD 00 05         [24] 1294 	cjne	r5,#0x00,00129$
      0002C0 0E               [12] 1295 	inc	r6
      0002C1 BE 00 01         [24] 1296 	cjne	r6,#0x00,00129$
      0002C4 0F               [12] 1297 	inc	r7
      0002C5                       1298 00129$:
      0002C5 BC 40 0D         [24] 1299 	cjne	r4,#0x40,00104$
      0002C8 BD 9C 0A         [24] 1300 	cjne	r5,#0x9c,00104$
      0002CB BE 00 07         [24] 1301 	cjne	r6,#0x00,00104$
      0002CE BF 00 04         [24] 1302 	cjne	r7,#0x00,00104$
                                   1303 ;	assignBit
      0002D1 D2 80            [12] 1304 	setb	_PA0
      0002D3 80 D0            [24] 1305 	sjmp	00107$
      0002D5                       1306 00104$:
                                   1307 ;	src/main.c:153: else if(blink == 80000UL) { PA0 = 0; blink = 0UL; }
      0002D5 BC 80 CD         [24] 1308 	cjne	r4,#0x80,00107$
      0002D8 BD 38 CA         [24] 1309 	cjne	r5,#0x38,00107$
      0002DB BE 01 C7         [24] 1310 	cjne	r6,#0x01,00107$
      0002DE BF 00 C4         [24] 1311 	cjne	r7,#0x00,00107$
                                   1312 ;	assignBit
      0002E1 C2 80            [12] 1313 	clr	_PA0
      0002E3 7C 00            [12] 1314 	mov	r4,#0x00
      0002E5 7D 00            [12] 1315 	mov	r5,#0x00
      0002E7 7E 00            [12] 1316 	mov	r6,#0x00
      0002E9 7F 00            [12] 1317 	mov	r7,#0x00
                                   1318 ;	src/main.c:160: }
      0002EB 80 B8            [24] 1319 	sjmp	00107$
                                   1320 	.area CSEG    (CODE)
                                   1321 	.area CONST   (CODE)
                                   1322 	.area XINIT   (CODE)
                                   1323 	.area CABS    (ABS,CODE)
