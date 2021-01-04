
#include "includes.h"


unsigned char RF_TxFlag;

uint32 anaRegs[9];
uint8 fifo_data[20]={0};
uint8 u_remoto_batter[2]={0};



void Write_Reg_Ana(uint8 addr, uint32 val)
{
//    uint8 buf[4];
//    buf[3] = (val>>24) & 0xFF;        // MSB
//    buf[2] = (val>>16) & 0xFF;
//    buf[1] = (val>>8) & 0xFF;
//    buf[0] =  val & 0xFF;             // LSB
    anaRegs[addr]=val;
    while( !(TRX_SCTRL & 0x80) );
    TRX_SDATA_0=_BYTE(0, val);
    TRX_SDATA_1=_BYTE(1, val);
    TRX_SDATA_2=_BYTE(2, val);
    TRX_SDATA_3=_BYTE(3, val);
    //memcpy (&TRX_SDATA_0, buf, 4);    // data
    TRX_SCTRL = addr;                 // address
}

void PowerUp_Rf(void)
{
    TRX_CONFIG |= 0x02;
}

void PowerDown_Rf(void)
{
    TRX_CONFIG &= 0xFD;
}

#if  0
void SwitchToRxMode(void)
{
    PowerUp_Rf();
	Delay_ms(1);	
    FLUSH_RX;
    TRX_CE = 0;
    TRX_CONFIG |= 0x01;
    TRX_CE = 1;
}
#endif

void SwitchToTxMode(void)
{
    PowerUp_Rf();
	Delay_ms(1);
    FLUSH_TX;
    TRX_CE = 0;
    TRX_CONFIG &= 0xFE;
    TRX_CE = 1;
}
void SwitchToTxMode_wait1ms(void)
{
	PowerUp_Rf();
    FLUSH_TX;
    TRX_CE = 0;
    TRX_CONFIG &= 0xFE;
    TRX_CE = 1;
}

#if 0
void ChangeTxPipe(uint8 pipe)
{
    uint8 tmp_address[5];

    switch(pipe)
    {
        case 0:
            memcpy(&TRX_RX_ADDR_P0_0, P0_Address, 5);
            memcpy(&TRX_TX_ADDR_0, P0_Address, 5);
            memcpy(&TRX_RX_ADDR_P1_0, P1_Address, 5);
            break;

        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            memcpy(tmp_address, P1_Address, 5);

            if(pipe == 2)                              // For P1, need not change LSB
                tmp_address[0] = TRX_RX_ADDR_P2;
            else if(pipe == 3)
                tmp_address[0] = TRX_RX_ADDR_P3;
            else if(pipe == 4)
                tmp_address[0] = TRX_RX_ADDR_P4;
            else if(pipe == 5)
                tmp_address[0] = TRX_RX_ADDR_P5;

            memcpy(&TRX_RX_ADDR_P0_0, tmp_address, 5);
            memcpy(&TRX_TX_ADDR_0, tmp_address, 5);
            memcpy(tmp_address, P1_Address, 5);
            tmp_address[2] = 0x37;                          // avoid for 2 same address for R1, R2, ... R5
            memcpy(&TRX_RX_ADDR_P1_0, tmp_address, 5);
            break;

        default:
            break;
    }
}

void R_RX_PAYLOAD(uint8 *pBuf, uint8 bytes)
{
    uint8 i;

    TRX_CMD = 0x40;                   // command
    for(i=0; i<bytes; i++)
        pBuf[i] = TRX_FIFO;           // data
    TRX_CMD = 0x00;                   // end: nop command
}
void W_TX_PAYLOAD(uint8 *pBuf, uint8 bytes)
{
    uint8 i;

    TRX_CMD = 0x60;
    for(i=0; i<bytes; i++)
        TRX_FIFO = pBuf[i];
    TRX_CMD = 0x00;
}
#endif
void W_TX_PAYLOAD_NOACK(uint8 *pBuf, uint8 bytes)
{
    uint8 i;

    TRX_CMD = 0x68;
    for(i=0; i<bytes; i++)
        TRX_FIFO = pBuf[i];
    TRX_CMD = 0x00;
}

#if 0
void W_ACK_PAYLOAD(uint8 *pBuf, uint8 bytes, uint8 pipe)
{
    uint8 i;

    TRX_CMD = 0x68 + pipe;
    for(i=0; i<bytes; i++)
        TRX_FIFO = pBuf[i];
    TRX_CMD = 0x00;
}
#endif

void RF_TXNoAck(char*buf,uint8 len)
{
    SwitchToTxMode_wait1ms();
    FLUSH_TX;
    FLUSH_RX;	
    W_TX_PAYLOAD_NOACK(buf, len);
}

void rf_isr() interrupt 11
{
//extern void Open_FuncLED(void);	
	if(TRX_IRQ_STATUS&B_IRQ_RX_DR)
	{
		//RF接收数据ready
		TRX_IRQ_STATUS |= B_IRQ_RX_DR;
	 	// R_RX_PAYLOAD(fifo_data, TRX_RX_RPL_WIDTH);		
//		flag_receive_value=1;
	}
	if(TRX_IRQ_STATUS&B_IRQ_TX_DS){
		RF_TxFlag=1;//RF数据已经发送
		TRX_IRQ_STATUS |= B_IRQ_TX_DS;
	}
	 AIF &= 0xf7 ; 
}
