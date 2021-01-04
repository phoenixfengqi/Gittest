/*------------------------------------------------------------------------------
bk2461.h

Header file for Beken 2461
------------------------------------------------------------------------------*/
#ifndef _BK24XX_H_
#define _BK24XX_H_


#include <ABSACC.H>
#include "bk51mcu.h"
#include "common.h"



#define  ADDR_BASE_TRX          0x880
#define  ADDR_BASE_XRAM         0x00
#define  ADDR_BASE_PWM          0xA00
#define  ADDR_BASE_RTC          0x918
#define  ADDR_BASE_ADC          0x920


#define  TRX_CONFIG             XBYTE[0x00 + ADDR_BASE_TRX]
#define  TRX_EN_AA              XBYTE[0x01 + ADDR_BASE_TRX]
#define  TRX_EN_RXADDR          XBYTE[0x02 + ADDR_BASE_TRX]
#define  TRX_SETUP_AW           XBYTE[0x03 + ADDR_BASE_TRX]
#define  TRX_SETUP_RETR         XBYTE[0x04 + ADDR_BASE_TRX]
#define  TRX_RF_CH              XBYTE[0x05 + ADDR_BASE_TRX]
#define  TRX_RF_SETUP           XBYTE[0x06 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P0_0       XBYTE[0x07 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P0_1       XBYTE[0x08 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P0_2       XBYTE[0x09 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P0_3       XBYTE[0x0A + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P0_4       XBYTE[0x0B + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P1_0       XBYTE[0x0C + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P1_1       XBYTE[0x0D + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P1_2       XBYTE[0x0E + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P1_3       XBYTE[0x0F + ADDR_BASE_TRX]

#define  TRX_RX_ADDR_P1_4       XBYTE[0x10 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P2         XBYTE[0x11 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P3         XBYTE[0x12 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P4         XBYTE[0x13 + ADDR_BASE_TRX]
#define  TRX_RX_ADDR_P5         XBYTE[0x14 + ADDR_BASE_TRX]
#define  TRX_TX_ADDR_0          XBYTE[0x15 + ADDR_BASE_TRX]
#define  TRX_TX_ADDR_1          XBYTE[0x16 + ADDR_BASE_TRX]
#define  TRX_TX_ADDR_2          XBYTE[0x17 + ADDR_BASE_TRX]
#define  TRX_TX_ADDR_3          XBYTE[0x18 + ADDR_BASE_TRX]
#define  TRX_TX_ADDR_4          XBYTE[0x19 + ADDR_BASE_TRX]
#define  TRX_RX_PW_P0           XBYTE[0x1A + ADDR_BASE_TRX]
#define  TRX_RX_PW_P1           XBYTE[0x1B + ADDR_BASE_TRX]
#define  TRX_RX_PW_P2           XBYTE[0x1C + ADDR_BASE_TRX]
#define  TRX_RX_PW_P3           XBYTE[0x1D + ADDR_BASE_TRX]
#define  TRX_RX_PW_P4           XBYTE[0x1E + ADDR_BASE_TRX]
#define  TRX_RX_PW_P5           XBYTE[0x1F + ADDR_BASE_TRX]

#define  TRX_DYNPD              XBYTE[0x20 + ADDR_BASE_TRX]
#define  TRX_FEATURE            XBYTE[0x21 + ADDR_BASE_TRX]
#define  TRX_CFG_0C_0           XBYTE[0x22 + ADDR_BASE_TRX]
#define  TRX_CFG_0C_1           XBYTE[0x23 + ADDR_BASE_TRX]
#define  TRX_CFG_0C_2           XBYTE[0x24 + ADDR_BASE_TRX]
#define  TRX_CFG_0C_3           XBYTE[0x25 + ADDR_BASE_TRX]
#define  TRX_CFG_0D_0           XBYTE[0x26 + ADDR_BASE_TRX]
#define  TRX_CFG_0D_1           XBYTE[0x27 + ADDR_BASE_TRX]
#define  TRX_CFG_0D_2           XBYTE[0x28 + ADDR_BASE_TRX]
#define  TRX_CFG_0D_3           XBYTE[0x29 + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_0       XBYTE[0x2A + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_1       XBYTE[0x2B + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_2       XBYTE[0x2C + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_3       XBYTE[0x2D + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_4       XBYTE[0x2E + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_5       XBYTE[0x2F + ADDR_BASE_TRX]

#define  TRX_RAMP_TABLE_6       XBYTE[0x30 + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_7       XBYTE[0x31 + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_8       XBYTE[0x32 + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_9       XBYTE[0x33 + ADDR_BASE_TRX]
#define  TRX_RAMP_TABLE_A       XBYTE[0x34 + ADDR_BASE_TRX]
#define  TRX_CE                 XBYTE[0x35 + ADDR_BASE_TRX]
#define  TRX_CMD                XBYTE[0x36 + ADDR_BASE_TRX]
#define  TRX_FIFO               XBYTE[0x37 + ADDR_BASE_TRX]
#define  TRX_SDATA_0            XBYTE[0x38 + ADDR_BASE_TRX]
#define  TRX_SDATA_1            XBYTE[0x39 + ADDR_BASE_TRX]
#define  TRX_SDATA_2            XBYTE[0x3A + ADDR_BASE_TRX]
#define  TRX_SDATA_3            XBYTE[0x3B + ADDR_BASE_TRX]
#define  TRX_SCTRL              XBYTE[0x3C + ADDR_BASE_TRX]
//#define  TRX_                 XBYTE[0x3D + ADDR_BASE_TRX]
#define  TRX_KCAL_OUT_B8_9      XBYTE[0x3E + ADDR_BASE_TRX]
#define  TRX_KCAL_OUT_B0_7      XBYTE[0x3F + ADDR_BASE_TRX]

#define  TRX_IRQ_STATUS         XBYTE[0x40 + ADDR_BASE_TRX]
//interrupt status bit
#define  B_IRQ_RX_DR            0x40
#define  B_IRQ_TX_DS            0x20
#define  B_IRQ_MAX_RT           0x10
#define  B_IRQ_TX_FULL          0x01
#define  TRX_OBSERVE_TX         XBYTE[0x41 + ADDR_BASE_TRX]
#define  TRX_RSSI_IND           XBYTE[0x42 + ADDR_BASE_TRX]
#define  TRX_FIFO_STATUS        XBYTE[0x43 + ADDR_BASE_TRX]
//FIFO status bit
#define  B_FIFO_TX_REUSE        0x40
#define  B_FIFO_TX_FULL         0x20
#define  B_FIFO_TX_EMPTY        0x10
#define  B_FIFO_RX_FULL         0x02
#define  B_FIFO_RX_EMPTY        0x01
#define  TRX_RX_RPL_WIDTH       XBYTE[0x44 + ADDR_BASE_TRX]
#define  TRX_MBIST_STATUS       XBYTE[0x45 + ADDR_BASE_TRX]
//#define  TRX_                 XBYTE[0x46 + ADDR_BASE_TRX]
//#define  TRX_                 XBYTE[0x47 + ADDR_BASE_TRX]
#define  TRX_BER_CNT_RCV_0      XBYTE[0x48 + ADDR_BASE_TRX]
#define  TRX_BER_CNT_RCV_1      XBYTE[0x49 + ADDR_BASE_TRX]
#define  TRX_BER_CNT_RCV_2      XBYTE[0x4A + ADDR_BASE_TRX]
#define  TRX_BER_CNT_RCV_3      XBYTE[0x4B + ADDR_BASE_TRX]
#define  TRX_BER_CNT_ERR_0      XBYTE[0x4C + ADDR_BASE_TRX]
#define  TRX_BER_CNT_ERR_1      XBYTE[0x4D + ADDR_BASE_TRX]
#define  TRX_BER_CNT_ERR_2      XBYTE[0x4E + ADDR_BASE_TRX]
#define  TRX_BER_CNT_ERR_3      XBYTE[0x4F + ADDR_BASE_TRX]

#define  TRX_TX_FREQ_OFFSET_0   XBYTE[0x50 + ADDR_BASE_TRX]
#define  TRX_TX_FREQ_OFFSET_1   XBYTE[0x51 + ADDR_BASE_TRX]
#define  TRX_TX_FREQ_OFFSET_2   XBYTE[0x52 + ADDR_BASE_TRX]
#define  TRX_TX_FREQ_OFFSET_3   XBYTE[0x53 + ADDR_BASE_TRX]
#define  TRX_RX_FREQ_OFFSET_0   XBYTE[0x54 + ADDR_BASE_TRX]
#define  TRX_RX_FREQ_OFFSET_1   XBYTE[0x55 + ADDR_BASE_TRX]
#define  TRX_RX_FREQ_OFFSET_2   XBYTE[0x56 + ADDR_BASE_TRX]
#define  TRX_RX_FREQ_OFFSET_3   XBYTE[0x57 + ADDR_BASE_TRX]
#define  TRX_TWO_POINT_DLY      XBYTE[0x58 + ADDR_BASE_TRX]
#define  TRX_PLL_SDM            XBYTE[0x59 + ADDR_BASE_TRX]
#define  TRX_KCAL_EN_BIT        0x00
#define  TRX_FM_GAIN_B8         XBYTE[0x5A + ADDR_BASE_TRX]
#define  TRX_FM_GAIN_B0_7       XBYTE[0x5B + ADDR_BASE_TRX]
#define  TRX_FM_KMOD_SET_B8     XBYTE[0x5C + ADDR_BASE_TRX]
#define  TRX_FM_KMOD_SET_B0_7   XBYTE[0x5D + ADDR_BASE_TRX]
#define  TRX_MOD_COEF_B8_12     XBYTE[0x5E + ADDR_BASE_TRX]
#define  TRX_MOD_COEF_B0_7      XBYTE[0x5F + ADDR_BASE_TRX]

#define  TRX_ANACTRL0           XBYTE[0x60 + ADDR_BASE_TRX]
#define  TRX_GPA0               XBYTE[0x61 + ADDR_BASE_TRX]
#define  TRX_GPA1               XBYTE[0x62 + ADDR_BASE_TRX]
#define  TRX_ANAPWD_CTRL0       XBYTE[0x63 + ADDR_BASE_TRX]
#define  TRX_ANAPWD_CTRL1       XBYTE[0x64 + ADDR_BASE_TRX]
#define  TRX_ANAPWD_CTRL2       XBYTE[0x65 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x66 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x67 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x68 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x69 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x6A + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x6B + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x6C + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x6D + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x6E + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x6F + ADDR_BASE_TRX]

// #define  TRX_                XBYTE[0x70 + ADDR_BASE_TRX]
 #define  TRX_Reg71H            XBYTE[0x71 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x72 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x73 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x74 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x75 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x76 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x77 + ADDR_BASE_TRX]
// #define  TRX_                XBYTE[0x78 + ADDR_BASE_TRX]
#define  TRX_ANAIND             XBYTE[0x79 + ADDR_BASE_TRX]
#define  TRX_CHIP_ID_1          XBYTE[0x7A + ADDR_BASE_TRX]
#define  TRX_CHIP_ID_0          XBYTE[0x7B + ADDR_BASE_TRX]
#define  TRX_DEVICE_ID_3        XBYTE[0x7C + ADDR_BASE_TRX]
#define  TRX_DEVICE_ID_2        XBYTE[0x7D + ADDR_BASE_TRX]
#define  TRX_DEVICE_ID_1        XBYTE[0x7E + ADDR_BASE_TRX]
#define  TRX_DEVICE_ID_0        XBYTE[0x7F + ADDR_BASE_TRX]

#define  TRX_ANA_CTRL13         XBYTE[0xE3 + ADDR_BASE_TRX]

/*
#define  TRX_                   XBYTE[0x10 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x11 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x12 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x13 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x14 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x15 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x16 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x17 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x18 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x19 + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x1A + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x1B + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x1C + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x1D + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x1E + ADDR_BASE_TRX]
#define  TRX_                   XBYTE[0x1F + ADDR_BASE_TRX]
*/


#define  PWM_0_CFG              XBYTE[0x00 + ADDR_BASE_PWM]
#define  PWM_0_DCLSB            XBYTE[0x01 + ADDR_BASE_PWM]
#define  PWM_0_DCMSB            XBYTE[0x02 + ADDR_BASE_PWM]
#define  PWM_0_RESOL            XBYTE[0x03 + ADDR_BASE_PWM]
#define  PWM_1_CFG              XBYTE[0x04 + ADDR_BASE_PWM]
#define  PWM_1_DCLSB            XBYTE[0x05 + ADDR_BASE_PWM]
#define  PWM_1_DCMSB            XBYTE[0x06 + ADDR_BASE_PWM]
#define  PWM_1_RESOL            XBYTE[0x07 + ADDR_BASE_PWM]
#define  PWM_2_CFG              XBYTE[0x08 + ADDR_BASE_PWM]
#define  PWM_2_DCLSB            XBYTE[0x09 + ADDR_BASE_PWM]
#define  PWM_2_DCMSB            XBYTE[0x0A + ADDR_BASE_PWM]
#define  PWM_2_RESOL            XBYTE[0x0B + ADDR_BASE_PWM]
#define  PWM_3_CFG              XBYTE[0x0C + ADDR_BASE_PWM]
#define  PWM_3_DCLSB            XBYTE[0x0D + ADDR_BASE_PWM]
#define  PWM_3_DCMSB            XBYTE[0x0E + ADDR_BASE_PWM]
#define  PWM_3_RESOL            XBYTE[0x0F + ADDR_BASE_PWM]
#define  PWM_4_CFG              XBYTE[0x11 + ADDR_BASE_PWM]
#define  PWM_4_DCLSB            XBYTE[0x12 + ADDR_BASE_PWM]
#define  PWM_4_DCMSB            XBYTE[0x13 + ADDR_BASE_PWM]
#define  PWM_4_RESOL            XBYTE[0x14 + ADDR_BASE_PWM]


#define  ADC_DATAL              XBYTE[0x00 + ADDR_BASE_ADC]
#define  ADC_DATAH              XBYTE[0x01 + ADDR_BASE_ADC]
#define  ADC_CTL                XBYTE[0x02 + ADDR_BASE_ADC]
#define  ADC_RATE               XBYTE[0x03 + ADDR_BASE_ADC]
#define  ADC_CTL2               XBYTE[0x04 + ADDR_BASE_ADC]

#define  RTC_CFG                XBYTE[0x00 + ADDR_BASE_RTC]
//#define  RTC_COUNTER              XBYTE[0x01 + ADDR_BASE_ADC]
#define  RTC_DATAH               XBYTE[0x01 + ADDR_BASE_RTC]
#define  RTC_DATAL                XBYTE[0x02 + ADDR_BASE_RTC]

#define  TIMES_FOR_LOOP_PIPES   20
#define  MAX_PIPE_NUMBER        6
#define  RX_PLOAD_MAX_WIDTH     0x20

#if		FangZhen_Mode
#define ID4   0x11
#define ID3  0x22
#define ID2  0x33
#define ID1  0x44
#define ID0  0x55
#else
#define ID4    CBYTE[0x1ffb]
#define ID3    CBYTE[0x1ffc]
#define ID2    CBYTE[0x1ffd]
#define ID1    CBYTE[0x1ffe]
#define ID0    CBYTE[0x1fff]
#endif


#endif
