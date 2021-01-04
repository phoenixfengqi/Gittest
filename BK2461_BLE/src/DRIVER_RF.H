#ifndef _DRIVER_RF_H_
#define _DRIVER_RF_H_
#include "bk2461.h"


//extern VOLATILE bit flag_receive_value;
//extern VOLATILE bit flag_openlock;
//extern VOLATILE bit flag_openlock_status;

//extern VOLATILE bit flag_remote_low_batter;
//extern VOLATILE bit 	flag_sensor_motion_hold;



//extern xdata unsigned char wait1ms_done;
extern xdata  uint16  time1ms_cnt;
extern xdata uint8 fifo_data[20];
extern xdata char RX1_Address[4];
extern xdata uint8 u_remoto_batter[2];
//extern uint8 flag_ble_mode;



#define RFDEBUG

// command
#define  FLUSH_TX               { TRX_CMD = 0xA0; }
#define  FLUSH_RX               { TRX_CMD = 0x80; }
#define  REUSE_TX_PL            { TRX_CMD = 0x10; }

#define _RF_DR_250K_ \
	2

#define _RF_DR_1M_ \
	0

#define _RF_DR_2M_ \
	1

#define _RF_DR_TAR_ \
    _RF_DR_250K_

#if 0
#define RF_Set_Chn(chn) \
	{\
	TRX_RF_CH = chn;\
	/*RF_TX_FREQERR()=0x4b000000-0x80000*chn;*/\
	if(chn==0){\
        TRX_TX_FREQ_OFFSET_2 = (0);\
        TRX_TX_FREQ_OFFSET_3 = (0x4b);\
     }\
	else{\
     TRX_TX_FREQ_OFFSET_2 = ((0x100-(chn<<3))&0xff);\
     TRX_TX_FREQ_OFFSET_3 = (0x4a-(((chn<<3)>>8)&0xff));\
	}\
	}
#endif

#define RF_Set_Chn(chn) \
	{\
	TRX_RF_CH = chn;\
	/*RF_TX_FREQERR()=0x4b000000-0x80000*chn;*/\
    TRX_TX_FREQ_OFFSET_2 = ((0x4b00-(chn<<3))&0xff);\
    TRX_TX_FREQ_OFFSET_3 = ((((0x4b00-(chn<<3))>>8)&0xff));\
	}

//#define RF_REG7_POWER 
//    0x0A2c8F87/*谐波优先*/
#define _OPTION_CURRENT_

#ifdef _OPTION_CURRENT_
#define RF_REG7_POWER_L \
    0x0A2C0087/*电流优先*/

#define RF_REG7_POWER \
    0x0A2F8F87/*电流优先*/	  

#define RF_PA0_VAL_N35dBm \
    1

#define RF_PA0_VAL_N30dBm \
    2

#define RF_PA0_VAL_N25dBm \
    2

#define RF_PA0_VAL_N20dBm \
    4

#define RF_PA0_VAL_N15dBm \
    5

#define RF_PA0_VAL_N10dBm \
    7

#define RF_PA0_VAL_N5dBm \
    7

#define RF_PA0_VAL_N2dBm \
    0x0b

#define RF_PA0_VAL_0dBm \
    0x0e

#define RF_PA0_VAL_3dBm \
    0x0b

#define RF_PA0_VAL_6dBm \
    0x0e

#define RF_PA0_VAL_8dBm \
    0x11

#define RF_PA0_VAL_9dBm \
    0x13

#define RF_PA0_VAL_10dBm \
    0x15

#define RF_PA0_VAL_12dBm \
    0x1f

#define RF_PA1_VAL_N35dBm \
    2

#define RF_PA1_VAL_N30dBm \
    2

#define RF_PA1_VAL_N25dBm \
    3

#define RF_PA1_VAL_N20dBm \
    3

#define RF_PA1_VAL_N15dBm \
    5

#define RF_PA1_VAL_N10dBm \
    7

#define RF_PA1_VAL_N5dBm \
    0x0a

#define RF_PA1_VAL_N2dBm \
    0x0a

#define RF_PA1_VAL_0dBm \
    0x0a

#define RF_PA1_VAL_3dBm \
    0x0c

#define RF_PA1_VAL_6dBm \
    0x10

#define RF_PA1_VAL_8dBm \
    0x12

#define RF_PA1_VAL_9dBm \
    0x14

#define RF_PA1_VAL_10dBm \
    0x16

#define RF_PA1_VAL_12dBm \
    0x1f
#endif
//#define _OPTION_HARMONIC_
#ifdef _OPTION_HARMONIC_
#define RF_REG7_POWER_L \
    0x0A2c8F87/*谐波优先*/

#define RF_REG7_POWER \
    0x0A2c8F87/*谐波优先*/

#define RF_PA0_VAL_N35dBm \
    1

#define RF_PA0_VAL_N30dBm \
    1

#define RF_PA0_VAL_N25dBm \
    2

#define RF_PA0_VAL_N20dBm \
    2

#define RF_PA0_VAL_N15dBm \
    3

#define RF_PA0_VAL_N10dBm \
    5

#define RF_PA0_VAL_N5dBm \
    6

#define RF_PA0_VAL_N2dBm \
    0x08

#define RF_PA0_VAL_0dBm \
    0x09

#define RF_PA0_VAL_3dBm \
    0x0b

#define RF_PA0_VAL_6dBm \
    0x0e

#define RF_PA0_VAL_8dBm \
    0x11

#define RF_PA0_VAL_9dBm \
    0x13

#define RF_PA0_VAL_10dBm \
    0x15

#define RF_PA0_VAL_12dBm \
    0x1f

#define RF_PA1_VAL_N35dBm \
    1

#define RF_PA1_VAL_N30dBm \
    2

#define RF_PA1_VAL_N25dBm \
    2

#define RF_PA1_VAL_N20dBm \
    3

#define RF_PA1_VAL_N15dBm \
    4

#define RF_PA1_VAL_N10dBm \
    5

#define RF_PA1_VAL_N5dBm \
    0x07

#define RF_PA1_VAL_N2dBm \
    0x08

#define RF_PA1_VAL_0dBm \
    0x09

#define RF_PA1_VAL_3dBm \
    0x0c

#define RF_PA1_VAL_6dBm \
    0x10

#define RF_PA1_VAL_8dBm \
    0x12

#define RF_PA1_VAL_9dBm \
    0x14

#define RF_PA1_VAL_10dBm \
    0x16

#define RF_PA1_VAL_12dBm \
    0x1f

#endif

#define RF_SetTxPower(dBm) \
	{\
	TRX_GPA0 |= ((dBm==0)?5:0x1f);\
	TRX_GPA1 |= (0x1f<<3);\
	Write_Reg_Ana(7, (dBm==0)?0x0A2C8987:0x0A2C8F87);\
	}

#define RF_SetTxPower_N35dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N35dBm;\
	TRX_GPA1 = RF_PA1_VAL_N35dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N30dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N30dBm;\
	TRX_GPA1 = RF_PA1_VAL_N30dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N25dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N25dBm;\
	TRX_GPA1 = RF_PA1_VAL_N25dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N20dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N20dBm;\
	TRX_GPA1 = RF_PA1_VAL_N20dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N15dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N15dBm;\
	TRX_GPA1 = RF_PA1_VAL_N15dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N10dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N10dBm;\
	TRX_GPA1 = RF_PA1_VAL_N10dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N5dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N5dBm;\
	TRX_GPA1 = RF_PA1_VAL_N5dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_N2dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_N2dBm;\
	TRX_GPA1 = RF_PA1_VAL_N2dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_0dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_0dBm;\
	TRX_GPA1 = RF_PA1_VAL_0dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER_L);\
	}

#define RF_SetTxPower_3dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_3dBm;\
	TRX_GPA1 = RF_PA1_VAL_3dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER);\
	}

#define RF_SetTxPower_6dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_6dBm;\
	TRX_GPA1 = RF_PA1_VAL_6dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER);\
	}

#define RF_SetTxPower_8dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_8dBm;\
	TRX_GPA1 = RF_PA1_VAL_8dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER);\
	}

#define RF_SetTxPower_9dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_9dBm;\
	TRX_GPA1 = RF_PA1_VAL_9dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER);\
	}

#define RF_SetTxPower_10dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_10dBm;\
	TRX_GPA1 = RF_PA1_VAL_10dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER);\
	}

#define RF_SetTxPower_12dBm() \
	{\
	TRX_GPA0 = RF_PA0_VAL_12dBm;\
	TRX_GPA1 = RF_PA1_VAL_12dBm<<3;\
	Write_Reg_Ana(7, RF_REG7_POWER);\ 
	}

#define M \
	*1000000
#define K \
	*1000

#define RF_Setup(dr,pwr,_20dbm) \
    {\
    TRX_RF_SETUP &= ~(BIT(5)|BIT(3));\
    if(dr==250 K){\
        TRX_RF_SETUP |= BIT(5);\
        }\
    if(dr == 2 M){\
        TRX_RF_SETUP |= BIT(3);\
        }\
	TRX_RF_SETUP |= (\
	(((pwr==-10)?0:((pwr==-5)?1:((pwr==0)?2:3)))<<1)|\
	(_20dbm) \
	);\
	}

#define RF_SetupDR(dr) \
    {\
    if((dr) == 1 M){\
        TRX_RF_SETUP = 0x07;\
        TRX_MOD_COEF_B8_12 = 0x04;\
        TRX_MOD_COEF_B0_7 = 0xcd;\
        Write_Reg_Ana(0x4, 0xb996821b);\
        }\
    if((dr) == 2 M){\
        TRX_RF_SETUP = 0x0f;\
        TRX_MOD_COEF_B8_12 = 0x09;\
        TRX_MOD_COEF_B0_7 = 0x9a;\
        Write_Reg_Ana(0x4, 0xB996821B);\
        }\
    if((dr) == 250 K){\
        TRX_RF_SETUP = 0x27;\
        TRX_MOD_COEF_B8_12 = 0x02;\
        TRX_MOD_COEF_B0_7 = 0x8f;\
        Write_Reg_Ana(0x4, 0xB9968A1B);\
        }\
    }

#define RF_PLL_MODE(md) \
    {\
    if(md == 0){\
        /*整数模式*/\
        Write_Reg_Ana(0x1, 0x90f7c960);\
        Write_Reg_Ana(0x2, 0x01b6c632);\
        }\
    if(md == 1){\
        /*分数模式*/\
        Write_Reg_Ana(1, 0x90F78960);\
        Write_Reg_Ana(2, 0x01B6C631);\
        }\
    }

#define RF_PowerUp() \
	TRX_CONFIG &= _BIT(1)

#define RF_PowerDown() \
	TRX_CONFIG |= BIT(1)

#define RF_TurnOn_RX() \
	TRX_CONFIG |= BIT(0)

#define RF_TurnOn_TX() \
	TRX_CONFIG &= _BIT(0)

#define RF_EnAA(bl) \
	TRX_EN_AA = bl

#define RF_EnRxAddr(bl) \
	TRX_EN_RXADDR = bl

#define RF_SetAddrWidth(n) \
	TRX_SETUP_AW = ((n==3)?1:((n==4)?2:3))/*默认为5B地址*/

#define RF_SetupRetrans(dly,rpt) \
	TRX_SETUP_RETR = (\
	(rpt)|\
	(((dly)/250-1)<<4)\
	)/*定制重送参数，dly为重送延时，rpt重送次数*/

#define RF_SetupCRC(en,l) \
	TRX_CONFIG &= (~(BIT(2)|BIT(3)));\
	TRX_CONFIG |=(\
	((en)<<3)|\
	(((l==1)?0:1)<<2)\
	)/*定制crc参数，en使能crc，l为1字节或2字节(默认为2)*/

#define RF_SetupFeature(dpl,ackPL,dynACK) \
	TRX_FEATURE = ((dpl<<2)|(ackPL<<1)|dynACK)

#define BK_RF_CMD(cmd) \
	TRX_CMD = (cmd)

#define BK_RF_Write_Bank1(reg,val) \
	while(TRX_SCTRL&BIT(7)==0);\
	TRX_SDATA_0 = (val&0xff);\
	TRX_SDATA_1 = ((val>>8)&0xff);\
	TRX_SDATA_2 = ((val>>16)&0xff);\
	TRX_SDATA_3 = ((val>>24)&0xff);\
	TRX_SCTRL = (reg)

#define RF_CE(s) \
	TRX_CE = (s)

#define RF_GET_RxTotalBits() \
    (*((uint32*)&TRX_BER_CNT_RCV_0))

#define RF_GET_RxErrorBits() \
    (*((uint32*)&TRX_BER_CNT_ERR_0))

#define RF_GET_ChipID() \
    (*((uint16*)&TRX_CHIP_ID_0))


#define RF_TX_FREQERR() \
	(*((uint32*)&TRX_TX_FREQ_OFFSET_0))

#define RF_RX_FREQERR() \
	(*((uint32*)&TRX_RX_FREQ_OFFSET_0))


#define RF_Get_PipePL(pn) \
	((TRX_RX_PW_P##pn)&0x3f)

#define RF_Set_PipePL(pn,l) \
	((TRX_RX_PW_P##pn)= (l))

#define RF_TxSwitch2_PipeAddr0() \
	memcpy(&TRX_TX_ADDR_0,&TRX_RX_ADDR_P0_0,5);\
	RF_EnRxAddr(BIT(0))

#define RF_TxSwitch2_PipeAddr1() \
	memcpy(&TRX_TX_ADDR_0,&TRX_RX_ADDR_P1_0,5);\
	RF_EnRxAddr(BIT(1))

#define RF_TxSwitch2_PipeAddr2() \
	memcpy(&TRX_TX_ADDR_1,&TRX_RX_ADDR_P1_1,5);\
	TRX_TX_ADDR_0 = TRX_RX_ADDR_P2;\
	RF_EnRxAddr(BIT(2))

#define RF_TxSwitch2_PipeAddr3() \
	memcpy(&TRX_TX_ADDR_1,&TRX_RX_ADDR_P1_1,5);\
	TRX_TX_ADDR_0 = TRX_RX_ADDR_P3;\
	RF_EnRxAddr(BIT(3))

#define RF_TxSwitch2_PipeAddr4() \
	memcpy(&TRX_TX_ADDR_1,&TRX_RX_ADDR_P1_1,5);\
	TRX_TX_ADDR_0 = TRX_RX_ADDR_P4;\
	RF_EnRxAddr(BIT(4))

#define RF_TxSwitch2_PipeAddr5() \
	memcpy(&TRX_TX_ADDR_1,&TRX_RX_ADDR_P1_1,5);\
	TRX_TX_ADDR_0 = TRX_RX_ADDR_P5;\
	RF_EnRxAddr(BIT(5))

#define RF_TxSwitch2_PipeAddr(n) \
	RF_TxSwitch2_PipeAddr##n()

#define RF_EnDyncPL(bl) \
	TRX_DYNPD |= (bl)

#define RF_CLEAR_INTF(bl) \
    {\
	/*清除RF中断标志*/TRX_IRQ_STATUS |=(bl);\
	/*清除中断标志*/INT_XVR = 0;\
	}

#define RF_SetupInterrupt(bl) \
    {\
	/*清除RF中断标志*/TRX_IRQ_STATUS |=(B_IRQ_RX_DR|B_IRQ_TX_DS|B_IRQ_MAX_RT);\
	/*清除中断标志*/INT_XVR = 0;\
	/*关闭RF中断允许位*/EX5 = 0;\
	/*除能所有RF中断源*/TRX_CONFIG |= ((B_IRQ_RX_DR|B_IRQ_TX_DS|B_IRQ_MAX_RT));\
	/*使能相应的RF中断源*/TRX_CONFIG &= (~(bl));\
	/*打开RF中断允许位*/EX5 = 1;\
	}

void PowerUp_Rf(void);
void PowerDown_Rf(void);
void SwitchToRxMode(void);
void SwitchToTxMode(void);
void SwitchToTxMode_wait1ms(void);
void ChangeTxPipe(uint8 pipe_num);
void R_RX_PAYLOAD(uint8 *pBuf, uint8 bytes);
void W_TX_PAYLOAD( uint8 *pBuf, uint8 bytes);
void W_TX_PAYLOAD_NOACK(uint8 *pBuf, uint8 bytes);
void W_ACK_PAYLOAD(uint8 *pBuf, uint8 bytes, uint8 pipe);

void RF_Init(uint8 mode);
void RF_BerRX(uint8 chn);
void RF_Pn9TX(uint8 chn);

void Write_Reg_Ana(uint8 addr, uint32 val);

void RF_StartTX(uint8 chn,char*buf,uint8 len);
void RF_TXNoAck(char*buf,uint8 len);
void RF_StartRX(uint8 chn);
void RF_StartTX_ACK(uint8 chn,char*buf,uint8 len);

void RF_StartRX_ACK(uint8 chn,char*buf,uint8 len,uint8 pipe);

void	Sys_set_1MHZ_rate(void);
void	Sys_set_250K_rate(void);
void RF_SingleWaveTest(void);

#endif
