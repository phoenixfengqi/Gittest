/*------------------------------------------------------------------------------
bk51mcu.h

Header file for Beken Dolphin Flip8051 Cyclone
------------------------------------------------------------------------------*/
#ifndef _BK_51MCU_H_
#define _BK_51MCU_H_

/*  BYTE Register  */
sfr  P0               = 0x80;
sfr  SP               = 0x81;
sfr  DPL              = 0x82;
sfr  DPH              = 0x83;
sfr  CKCON            = 0x84;
sfr  CLK_EN_CFG       = 0x85;
sfr  PCON2            = 0x86;
sfr  PCON             = 0x87;
sfr  TCON             = 0x88;
sfr  TMOD             = 0x89;
sfr  TL0              = 0x8A;
sfr  TL1              = 0x8B;
sfr  TH0              = 0x8C;
sfr  TH1              = 0x8D;
sfr  CCMCON           = 0x8E;
sfr  CCMVAL           = 0x8F;
sfr  P1               = 0x90;
sfr  P0IN_EN          = 0x91;
sfr  DPSEL            = 0x92;
sfr  P1IN_EN          = 0x93;
sfr  P2IN_EN          = 0x94;
sfr  P3IN_EN          = 0x95;
sfr  P4IN_EN          = 0x96;
sfr  MMS              = 0x97;
sfr  SCON0            = 0x98;
sfr  SBUF0            = 0x99;
sfr  P0OUT_EN         = 0x9A;
sfr  PAGE_A           = 0x9B;
sfr  PAGE_B           = 0x9C;
sfr  PAGE_C           = 0x9D;
sfr  P1OUT_EN         = 0x9E;
sfr  P2OUT_EN         = 0x9F;
sfr  P2               = 0xA0;
sfr  MPAGE            = 0xA1;
sfr  PWM0_C           = 0xA2;
sfr  PWM0_DCLSB       = 0XA3;
sfr  PWM0_DCMSB       = 0XA4;
sfr  P3OUT_EN         = 0XA5;
sfr  WDT              = 0XA6;
sfr  P4OUT_EN         = 0xA7;
sfr  IE               = 0xA8;
sfr  P0_PU            = 0xA9;
sfr  P1_PU            = 0xAA;
sfr  P2_PU            = 0xAB;
sfr  P3_PU            = 0xAC;
sfr  P4_PU            = 0xAD;
sfr  P0_PD            = 0xAE;
sfr  P1_PD            = 0xAF;
sfr  P3               = 0xB0;
sfr  SPCR             = 0xB1;
sfr  SPDR             = 0xB2;
sfr  SPSR             = 0xB3;
sfr  P2_PD            = 0xB4;
sfr  P3_PD            = 0xB5;
sfr  P4_PD            = 0xB6;
sfr  P4               = 0xB7;
sfr  IP               = 0xB8;

sfr  ASADDR           = 0xBA;
sfr  ASADEN           = 0xBB;
sfr  ASCON            = 0xBC;
sfr  ASBUF            = 0xBD;

sfr  AIF              = 0xC0;
sfr  MD0              = 0xC1;
sfr  MD1              = 0xC2;
sfr  MD2              = 0xC3;
sfr  MD3              = 0xC4;
sfr  MD4              = 0xC5;
sfr  MD5              = 0xC6;
sfr  MDCTL            = 0xC7;
sfr  T2CON            = 0xC8;
sfr  NMI_EN           = 0xC9;
sfr  RCAP2L           = 0xCA;
sfr  RCAP2H           = 0xCB;
sfr  TL2              = 0xCC;
sfr  TH2              = 0xCD;
sfr  PWM0_RESOL       = 0xCE;
sfr  PWM1_RESOL       = 0xCF;
sfr  PSW              = 0xD0;
//sfr                 = 0xD1;
sfr  I2CM_DATA_IE     = 0xD2;
//sfr  N/A            = 0xD3;
sfr  I2CM_CALLADDR0   = 0xD4;
sfr  I2CS_DATA_IE     = 0xD5;
sfr  I2CS_TXRX_IE     = 0xD6;
sfr  I2CS_SELFADDR0   = 0xD7;
sfr  P0_OPDR          = 0xD8;
sfr  P1_OPDR          = 0xD9;
sfr  P2_OPDR          = 0xDA;
sfr  P3_OPDR          = 0xDB;
sfr  P4_OPDR          = 0xDC;
sfr  PWM1_C           = 0xDD;
sfr  PWM1_DCLSB       = 0xDE;
sfr  PWM1_DCMSB       = 0xDF;
sfr  ACC              = 0xE0;
sfr  I2CM_CTRL        = 0xE1;
sfr  I2CM_RXDATA      = 0xE2;
sfr  I2CM_TXDATA      = 0xE3;
sfr  I2CM_PRESC       = 0xE4;
sfr  I2CM_TXRX_STS    = 0XE5;
sfr  I2CM_DATA_STS    = 0XE6;
sfr  I2CM_TXRX_IE     = 0xE7;
sfr  AIE              = 0xE8;
sfr  PALT0            = 0xE9;
sfr  EXSLEEP          = 0xEA;
sfr  P0_WUEN          = 0xEB;
sfr  P1_WUEN          = 0xEC;
sfr  P2_WUEN          = 0xED;
sfr  P3_WUEN          = 0xEE;
sfr  P4_WUEN          = 0xEF;
sfr  B                = 0xF0;
sfr  I2CS_CTRL        = 0xF1;
sfr  I2CS_RXDATA      = 0xF2;
sfr  I2CS_TXDATA      = 0xF3;
sfr  I2CS_PRESC       = 0xF4;
sfr  I2CS_TXRX_STS    = 0xF5;
sfr  I2CS_DATA_STS    = 0xF6;
sfr  PALT1            = 0xF7;
sfr  AIP              = 0xF8;
sfr  P0_WUMOD         = 0xF9;
sfr  P1_WUMOD         = 0xFA;
sfr  P2_WUMOD         = 0xFB;
sfr  P3_WUMOD         = 0xFC;
sfr  P4_WUMOD         = 0xFD;

/*  BIT Registers  */
/*  PSW */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit FL    = PSW^1;
sbit P     = PSW^0;

/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  IE  */
sbit EA    = IE^7;
sbit ES1   = IE^6;
sbit ET2   = IE^5;
sbit ES0   = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;

/*  P1  */
sbit INT5  = P1^7;
sbit INT4  = P1^6;
sbit INT3  = P1^5;
sbit INT2  = P1^4;
sbit TXD1  = P1^3;
sbit RXD1  = P1^2;
sbit T2EX  = P1^1;
sbit T2    = P1^0;

/*  P3  */
sbit RD    = P3^7;
sbit WR    = P3^6;
sbit T1    = P3^5;
sbit T0    = P3^4;
sbit INT1  = P3^3;
sbit INT0  = P3^2;
sbit TXD0  = P3^1;
sbit RXD0  = P3^0;

/*  SCON0  */
sbit SM0   = SCON0^7; /* alternative SM0_FE_0 */
sbit SM1   = SCON0^6; /* alternative SM1_0 */
sbit SM2   = SCON0^5; /* alternative SM2_0 */
sbit REN   = SCON0^4; /* alternative REN_0 */
sbit TB8   = SCON0^3; /* alternative TB8_0 */
sbit RB8   = SCON0^2; /* alternative RB8_0 */
sbit TI    = SCON0^1; /* alternative TI_0  */
sbit RI    = SCON0^0; /* alternative RI_0  */

/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;

/*  EIE  */
sbit EX9   = AIE^7;
sbit EX8   = AIE^6;
sbit EX7   = AIE^5;
sbit EX6   = AIE^4;
sbit EX5   = AIE^3;
sbit EX4   = AIE^2;
sbit EX3   = AIE^1;
sbit EX2   = AIE^0;

// AIF: additional interrupt flag
sbit INT_AES = AIF^7;
sbit INT_ADC = AIF^6;
sbit INT_PCA = AIF^5;
sbit INT_EXT = AIF^4;
sbit INT_XVR = AIF^3;
sbit INT_USB = AIF^2;
sbit INT_LBD = AIF^1;
sbit INT_SPI = AIF^0;

/*  P0  */
sbit P00  = P0^0;
sbit P01  = P0^1;
sbit P02  = P0^2;
sbit P03  = P0^3;
sbit P04  = P0^4;
sbit P05  = P0^5;
sbit P06  = P0^6;
sbit P07  = P0^7;
/*  P1  */
sbit P10  = P1^0;
sbit P11  = P1^1;
sbit P12  = P1^2;
sbit P13  = P1^3;
sbit P14  = P1^4;
sbit P15  = P1^5;
sbit P16  = P1^6;
sbit P17  = P1^7;
/*  P2  */
sbit P20  = P2^0;
sbit P21  = P2^1;
sbit P22  = P2^2;
sbit P23  = P2^3;
sbit P24  = P2^4;
sbit P25  = P2^5;
sbit P26  = P2^6;
sbit P27  = P2^7;
/*  P3  */
sbit P30  = P3^0;
sbit P31  = P3^1;
sbit P32  = P3^2;
sbit P33  = P3^3;
sbit P34  = P3^4;
sbit P35  = P3^5;
sbit P36  = P3^6;
sbit P37  = P3^7;


//=======BK2461ÍÑ»úÉÕÂ¼ËµÃ÷==============
//=======ID Address===========================
#define		BK2461ID0		CBYTE[0x1FFc]	//0x11//0x89//CBYTE[0x1FFc]		
#define		BK2461ID1		CBYTE[0x1FFc+1]	//0x22;//0x86//CBYTE[0x1FFc+1]
#define		BK2461ID2		CBYTE[0x1FFc+2]//	0x33;//0x99//CBYTE[0x1FFc+2]
#define		BK2461ID3		CBYTE[0x1FFc+3]//	0xa5;//0xaa//CBYTE[0x1FFc+3]


#endif
