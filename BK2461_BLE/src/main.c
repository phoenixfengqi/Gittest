#include "includes.h"


unsigned char Payload_demo[Payload_len];
bit	tx_data_seted=0;
bit rf_encode_37,rf_encode_38,rf_encode_39;
uint8 rf_encode_state;

uint8 KeyCode=0;
uint8 KeyCode1=0;

uint16 KeyCount=0;
uint8  longCount_scale = 0;
uint8  SequenceNum_1=0;
uint8 long_key_value_temp = 0;  //如果长按同一个键，则会保存当前值
uint8 long_key_value_tempp;
uint8  SequenceNum_inc_1 = 0;
uint8 short_long_touch_flag = 0;

uint8 SrcAddr_1[4];
uint8 CurrentGroup_1[1];
uint8 Static_scene_state = 0;

#define PWM_OPEN_CLOCK() \
	{CLK_EN_CFG |= 0x10;}   //Enable pwm

#define PWM_SetupIOL(bl) \
    PALT1_SETB(((bl)<<3))

#define	PWM1_SetupIOL(b1) \
	PALT1_SETB(((b1)<<4))

#define PWM_Setup(pn,pres,resol,duty) \
	PWM_##pn##_CFG = (((resol>=768)<<7)|(pres));\
	PWM_##pn##_RESOL = ((resol>=768)?(resol-768):(resol));\
	PWM_##pn##_DCLSB = (duty&0xff);\
	PWM_##pn##_DCMSB = ((duty>>8)&0xff)

#define PWM_SET_DUTY(pn,duty) \
	PWM_##pn##_DCLSB = (duty&0xff);\
	PWM_##pn##_DCMSB = ((duty>>8)&0xff)

#define PWM_Open(pn) \
	PWM_##pn##_CFG |= BIT(6)

#define PWM_CLOSE(pn) \
	PWM_##pn##_CFG &= _BIT(6)


uint8   AdvPacket_2[32] = 
{
	//0
    0x02,   // 广播类型
    
    //27,   // 26 Length ( Device Address + Payload )
    //1
    27,
    /* Device Address(6字节) */
    //0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
    //2   3    4    5   6     7
    0xfe,0xee,0xc0,0x07,0xda,0x78,                                 //6个字节
    //0x0A,0xFF,0x5D,0x00,0x02,0x01,0x08,0xFF,0x00,0x00,0x00,
    
    // 0x0b,0xFF,0x5D,0x00,0x02,0x01,0x09,0x02,0x01,0x00,0x35,0xf3,   //12个字节
    //8  9     10   11    12     13   14      15   16    17    18   19     20    21   22     23      24    25    26    27   28
    //0  1     2    3     4       5    6       7    8     9    10    11    12    13   14     15      16    17    18	  19     20    //共21字节
    
    19,0x01,  0x04, 0x11,0x07,  0x00, 0x10,  0xff,0x01,  0x02, 0x03, 0x14, 0x00, 0x00,0x00 , 0x01,  0x00, 0x00, 0xAA//,   0xBB, 0xcc 
};

#define KEY_PUSH_LONG		(0x80)
#define KEY_PUSH_UP			(0x40)
#define KEY_BOND_DOWN		(0x20)
#define KEY_PUSH_DOWN		(0x00)

#define HAL_KEY_NO_KEY			0x00

#define HAL_KEY_POWER_ON		0x01
#define HAL_KEY_POWER_OFF		0x02
#define HAL_KEY_BRIGHT_UP		0x03
#define HAL_KEY_BRIGHT_DOWN		0x04
#define HAL_KEY_TEMP_UP			0x05
#define HAL_KEY_TEMP_DOWN		0x06

#define HAL_KEY_POWER_ON1		0x07
#define HAL_KEY_POWER_ON2		0x08
#define HAL_KEY_POWER_ON3		0x09
#define HAL_KEY_POWER_ON4		0x0a
#define HAL_KEY_POWER_OFF1		0x0b
#define HAL_KEY_POWER_OFF2		0x0c
#define HAL_KEY_POWER_OFF3		0x0d
#define HAL_KEY_POWER_OFF4		0x0e
#define HAL_KEY_FACTORY_RESET   0x0f
#define HAL_KEY_BIND            0x10

#define HAL_TXREAD_EEPROM		0x11
#define HAL_RXREAD_EEPROM		(KEY_PUSH_UP|HAL_TXREAD_EEPROM)

// for key process 
#define POWER_ON1_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_ON1)
#define POWER_OFF1_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_OFF1)
#define POWER_ON2_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_ON2)
#define POWER_OFF2_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_OFF2)
#define POWER_ON3_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_ON3)
#define POWER_OFF3_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_OFF3)
#define POWER_ON4_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_ON4)
#define POWER_OFF4_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_OFF4)
#define FACTORY_RESET_KEY      	(KEY_PUSH_UP|HAL_KEY_FACTORY_RESET)
//#define BIND_KEY            	(KEY_PUSH_UP|HAL_KEY_BIND)

#define POWER_ON_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_ON)
#define POWER_OFF_KEY			(KEY_PUSH_UP|HAL_KEY_POWER_OFF)
#define BRIGHT_UP_KEY			(KEY_PUSH_UP|HAL_KEY_BRIGHT_UP)
#define BRIGHT_DOWN_KEY		    (KEY_PUSH_UP|HAL_KEY_BRIGHT_DOWN)
#define TEMP_UP_KEY				(KEY_PUSH_UP|HAL_KEY_TEMP_UP)
#define TEMP_DOWN_KEY			(KEY_PUSH_UP|HAL_KEY_TEMP_DOWN)

#define DELAY_POWER_OFF_KEY		(KEY_PUSH_LONG|HAL_KEY_POWER_OFF)
#define BRIGHT_MOVE_UP_KEY		(KEY_PUSH_LONG|HAL_KEY_BRIGHT_UP)
#define BRIGHT_MOVE_DOWN_KEY	(KEY_PUSH_LONG|HAL_KEY_BRIGHT_DOWN)
#define TEMP_MOVE_UP_KEY		(KEY_PUSH_LONG|HAL_KEY_TEMP_UP)
#define TEMP_MOVE_DOWN_KEY		(KEY_PUSH_LONG|HAL_KEY_TEMP_DOWN)



code uint8 Key_TBL[17]={ 
	HAL_KEY_NO_KEY,		// 0x0 
	HAL_KEY_POWER_ON,	HAL_KEY_POWER_OFF3,	HAL_KEY_POWER_ON3,	HAL_KEY_BRIGHT_UP,		// 
	HAL_KEY_POWER_OFF,	HAL_KEY_POWER_OFF2,	HAL_KEY_POWER_ON2,	HAL_KEY_BRIGHT_DOWN,		// 
	HAL_TXREAD_EEPROM,	HAL_KEY_POWER_OFF1,	HAL_KEY_POWER_ON1,	HAL_KEY_TEMP_DOWN, 	// 
	HAL_TXREAD_EEPROM,	HAL_KEY_POWER_OFF4,	HAL_KEY_POWER_ON4,	HAL_KEY_TEMP_UP, 	//
};

uint8  XDATA   RF_TxLen_CH3789;  //三个通道要发同一组数据，则其长度也要是一样
volatile uint8  XDATA   RF_TxBuf_CH37[RF_TxBuf_CH3789_len];
volatile uint8  XDATA   RF_TxBuf_CH38[RF_TxBuf_CH3789_len];
volatile uint8  XDATA   RF_TxBuf_CH39[RF_TxBuf_CH3789_len];

uint8  XDATA   BLE_PacketBuf[BLE_PacketBuf_len];
uint8  XDATA   BLE_PacketLen;
uint8  fen_Duan=0,rgb_static_dynamic=0;
void Set_MacAddr(void);

void Ble_Packet_Encode(void){
	if(tx_data_seted){
		switch(rf_encode_state){
			case 0:
				BlePacketEncode( RF_TxBuf_CH37, AdvPacket_2, 29, 37 );  //虽然这里长度写的是29，不过最终还会产生三个CRC校验码，因此fifo_data会多三bytes
				rf_encode_state = 1;
				rf_encode_37  = 1;
				break;
			case 1:
				BlePacketEncode( RF_TxBuf_CH38, AdvPacket_2, 29, 38 );
				rf_encode_state = 2;
				rf_encode_38 = 1;
				break;
			case 2:
				BlePacketEncode( RF_TxBuf_CH39, AdvPacket_2, 29, 39 );
				rf_encode_state = 0;
				rf_encode_39 = 1;
				tx_data_seted = 0;
				break;
			}
	}
}

void FuncLED_Init(void)
{
#if __FQ__
	PWM_OPEN_CLOCK();  //打开pwm功能
#if FangZhen_Mode
	PWM1_SetupIOL(BIT(0));
#else
	PWM_SetupIOL(BIT(0));
#endif
#endif
}

void Open_FuncLED(void)
{
#if __FQ__

#if FangZhen_Mode   //在仿真模式下，不能使用VPP输出pwm信号
	PWM_Setup(1, 39, (768+232), (768));
	PWM_Open(1);
#else
	PWM_Setup(0, 39, (768+232), (768));
	PWM_Open(0);
#endif

#endif
}

void Close_FuncLED(void)
{
#if __FQ__

#if FangZhen_Mode  //在仿真模式下，不能使用VPP输出pwm信号
	PWM_CLOSE(1);
#else
	PWM_CLOSE(0);
#endif

#endif
}

void mcu_io_sleep()
{
#if Package_SOP16
    GPIO_InputSetup(1, 0xff, 0xff,0);
 	GPIO_OutputSetup(2, BIT(0)|BIT(1)|BIT(6)|BIT(7), 0);
	GPIO_InputSetup(2,(~(BIT(0)|BIT(1)|BIT(6)|BIT(7))), (~(BIT(0)|BIT(1)|BIT(6)|BIT(7))),0);
	GPIO_DiablePU(2,BIT(0)|BIT(1)|BIT(6)|BIT(7));
	GPIO_DiablePD(2,0xff);
	key_s0 = 0;
	key_s1 = 0;	
	key_s2 = 0;
	key_s3 = 0;
	GPIO_InputSetup(3, 0xff, 0xff,0);
#else
	GPIO_InputSetup(1, 0xff, 0xff,0);
	GPIO_OutputSetup(2, BIT(2)|BIT(3)|BIT(6)|BIT(7), 0);
	GPIO_InputSetup(2,(~(BIT(2)|BIT(3)|BIT(6)|BIT(7))), (~(BIT(2)|BIT(3)|BIT(6)|BIT(7))),0);
	GPIO_DiablePU(2,BIT(2)|BIT(3)|BIT(6)|BIT(7));
	GPIO_DiablePD(2,0xff);
	key_s0 = 0;
	key_s1 = 0; 
	key_s2 = 0;
	key_s3 = 0;
	GPIO_InputSetup(3, 0xff, 0xff,0);
#endif
	Delay_ms(1);
}

void gpio_init()
{
#if Package_SOP16
	GPIO_OutputSetup(2, BIT(0)|BIT(1)|BIT(6)|BIT(7), 0);
    GPIO_InputSetup(3, BIT(4)|BIT(5)|BIT(6)|BIT(7), BIT(4)|BIT(5)|BIT(6)|BIT(7),0);
#endif
#if Package_QFN24
	GPIO_OutputSetup(2, BIT(2)|BIT(3)|BIT(6)|BIT(7), 0);
	GPIO_InputSetup(3, BIT(3)|BIT(2)|BIT(1)|BIT(0), BIT(3)|BIT(2)|BIT(1)|BIT(0),0);
	GPIO_OutputSetup(1,BIT(1),0);
	GPIO_DiablePU(1, BIT(1));
	LED_Test = 0;
#endif

    key_s0 = 0;
	key_s1 = 0;
	key_s2 = 0;
	key_s3 = 0;
}

void mcu_clk_inital(void)
{
	PCON=0;          // 2018/12/11
	PCON2 = 0 ;	
    CLK_EN_CFG = 0x00 ;
    CKCON = 0x00;    // 2018/12/11
}

void Sys_SleepModeCheck(void)
{
	if(adv_flag)
		return;
    wIdleTime++;
    if(wIdleTime > cRemoteIDLETime)
    {
        bPowerDN = 1;
        wIdleTime = 0;
    }    
}

void Sys_PowerOn(void)
{
	if(power_on)	 				//MCU 从sleep 或 power_down唤醒
	{
        power_on = 0;
        gpio_init();
		WaitUs(80);	
		PowerUp_Rf();
        FLUSH_TX;
        FLUSH_RX;	
        
        #if UART_ENABLE
    	UartConfig(BAUD);
    	WaitUs(60000);	
        #endif
        
		WaitUs(200);						//  120us for PLL locking after power up RF part.		
		InitSysTimer(); 
        
		WaitUs(200);	
        FuncLED_Init();
		wIdleTime = 0;  
	}
} 

void Sys_PowerDown(void)
{
    if(bPowerDN)
    { 
        bPowerDN = 0;

        Close_Uart();
        Close_FuncLED();
        
		EX5  = 0 ;
		PowerDown_Rf();	
		
		SysTimerStop();	
        mcu_io_sleep();
        
        TRX_ANAPWD_CTRL0 |=0x11;

#if FangZhen_Mode
        P3_WUEN = 0x0F; 		// P3.0 P3.1 P3.2 P3.3 wakeup enable 
        P3_WUMOD = 0x00;	
#else
        P3_WUEN = 0xF0; 		// P3.4 P3.5 P3.6 P3.7 wakeup enable 
        P3_WUMOD = 0x00;
#endif

     	TRX_ANAPWD_CTRL0 = 0x53;
     	
		WaitUs(200);
		MCU_SLEEP();
        _nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	    PCON2 = 0x00;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		WaitUs(200);
		power_on = 1;
			
    }
}

#if FangZhen_Mode
#define KSA             0xd1    //P2.7  P2.6  P2.4 P2.0  is 1(high voltag)
#define KS0             0x51    //P2.7 = 0
#define KS1             0x91    //P2.6 = 0
#define KS2             0xc1    //P2.4 = 0
#define KS3             0xd0    //P2.0 = 0
#define KEYSCANBIT(x)   P2=(x)
#define NOKEYPUSH       0x0F    ////P3_1/2/3/4
#define KEYREADBIT     (P3&NOKEYPUSH)
#define KEYP2READ       P2

#else
#define KSA             0xc3    //P2.7  P2.6  P2.1 P2.0  is 1(high voltag)
#define KS0             0x43    //P2.7 = 0
#define KS1       ss      0x83    //P2.6 = 0
#define KS2             0xc1    //P2.1 = 0
#define KS3             0xc2    //P2.0 = 0
#define KEYSCANBIT(x)   P2=(x)
#define NOKEYPUSH       0xF0        //P3_4/5/6/7
#define KEYREADBIT     (P3&NOKEYPUSH)
#define KEYP2READ       P2
#endif

uint8 KeyP2_scan_func(){    
    int8 key_value = 0;
#if FangZhen_Mode   //set P2.7  P2.6  P2.4 P2.0 input
    GPIO_InputSetup(2, BIT(0)|BIT(4)|BIT(6)|BIT(7),BIT(0)|BIT(4)|BIT(6)|BIT(7), 0);
    GPIO_OutputSetup(3, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 0);//P3.7  P3.6  P3.4 P3.5
#else
    //set P2.7  P2.6  P2.1 P2.0 input
	GPIO_InputSetup(2, BIT(0)|BIT(1)|BIT(6)|BIT(7),BIT(0)|BIT(1)|BIT(6)|BIT(7), 0);
#endif

    while((KEYP2READ&KSA) != KSA){        
        //logvalue(P2,P2, 0xb2);
        if(key_s0 == 0){key_value = 1; break;}
        if(key_s1 == 0){key_value = 2; break;}
        if(key_s2 == 0){key_value = 3; break;}
        if(key_s3 == 0){key_value = 4; break;}
     }

#if FangZhen_Mode
    GPIO_OutputSetup(2, BIT(0)|BIT(4)|BIT(6)|BIT(7), 0);
#else
    //set P2.7  P2.6  P2.1 P2.0 output
	GPIO_OutputSetup(2, BIT(0)|BIT(1)|BIT(6)|BIT(7), 0);
#endif    
    return key_value;
}

uint8 Key_scan_func(uint8 keyscan){  
#if FangZhen_Mode
    GPIO_OutputSetup(2, BIT(0)|BIT(4)|BIT(6)|BIT(7), 0);//P2.7  P2.6  P2.4P2.0
    GPIO_InputSetup(3, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7),
                          BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 0);//P3.7  P3.6  P3.4 P3.5
#else
	GPIO_OutputSetup(2, BIT(0)|BIT(1)|BIT(6)|BIT(7), 0);//P2.7  P2.6  P2.1 P2.0
	GPIO_InputSetup(3, BIT(4)|BIT(5)|BIT(6)|BIT(7),BIT(4)|BIT(5)|BIT(6)|BIT(7), 0);//P3.7  P3.6  P3.4 P3.5
	GPIO_InputSetup(3, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7),
                          BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), 0);//P3.7  P3.6  P3.4 P3.5
#endif
   // if(!key_r0)       {loginfo("37Low\r\n");}   else       {loginfo("37High\r\n");}    return 0;  // for test
   
    KEYSCANBIT(keyscan); 
    //logvalue(P3,P3, 0xb3); 
    if(KEYREADBIT != NOKEYPUSH){
        if(!key_r3) return 5;
        if(!key_r2) return 6;
        if(!key_r1) return 7;
        if(!key_r0) return 8;        
    }
    return 0;
}

//key value: 1 2 3 4 5 6 ... 24
//8 6 5 7   11 10 9  16 15 13
uint8 Key24_Detect_GPIO(void){
    int8 key_value = 0;
    if(key_value = KeyP2_scan_func()) { logvalue(0xEA,key_value, 1);      return (key_value);}
    if(key_value = Key_scan_func(KSA)){ logvalue(0xEF,(key_value+16), 1); return (key_value+16);} 
    
    if(key_value = Key_scan_func(KS0)){ logvalue(0xEB,key_value, 1);       return (key_value);}
    if(key_value = Key_scan_func(KS1)){ logvalue(0xEC,(key_value+4), 1);   return (key_value+4);}
    if(key_value = Key_scan_func(KS2)){ logvalue(0xED,(key_value+8), 1);   return (key_value+8);}
    if(key_value = Key_scan_func(KS3)){ logvalue(0xEE,(key_value+12), 1);  return (key_value+12);} 
    
    return key_value;
}

#if 0
uint8 Key_Detect_GPIO(void)
{
	uint8 keybuf[2];
	uint8 i, j, KeyTempCode;

	keybuf[0] = 0;
	keybuf[1] = 0;

	key_s0 = 0;
	key_s1 = 1;
	key_s2 = 1;
	key_s3 = 1;

	i = 0;
	if(!key_r0)
		keybuf[i] |= 0x01;
	else if(!key_r1)
		keybuf[i] |= 0x02;
	else if(!key_r2)
		keybuf[i] |= 0x04;
	else if(!key_r3)
		keybuf[i] |= 0x08;

	key_s0 = 1;
	key_s1 = 0;
	if(!key_r0)
		keybuf[i] |= 0x10;
	else if(!key_r1)
		keybuf[i] |= 0x20;
	else if(!key_r2)
		keybuf[i] |= 0x40;
	else if(!key_r3)
		keybuf[i] |= 0x80;

	key_s1 = 1;
	key_s2 = 0;	
	i = 1;
	if(!key_r0)
		keybuf[i] |= 0x01;
	else if(!key_r1)
		keybuf[i] |= 0x02;
	else if(!key_r2)
		keybuf[i] |= 0x04;
	else if(!key_r3)
		keybuf[i] |= 0x08;

	key_s2 = 1;
	key_s3 = 0;
	if(!key_r0)
		keybuf[i] |= 0x10;
	else if(!key_r1)
		keybuf[i] |= 0x20;
	else if(!key_r2)
		keybuf[i] |= 0x40;
	else if(!key_r3)
		keybuf[i] |= 0x80;

	key_s0 = 0;
	key_s1 = 0;	
	key_s2 = 0;
	key_s3 = 0;

	key_r0^=1;

	KeyTempCode = 1;
	for(i=0;i<2;i++) 
	{
		for(j=0;j<8;j++)
		{
			if(keybuf[i]&0x01)
			{
				return (KeyTempCode);
			}
			keybuf[i] >>= 1;
			KeyTempCode++;
		}
			
	}
	return 0;
}
#endif

#define	CRC_CHECK_START	13
#define	CRC_CHECK_STOP	(CRC_CHECK_START+11)
uint8 Calc_CRC_Value(void){
	uint8 i;
	uint8 sum_1;
	sum_1 = AdvPacket_2[CRC_CHECK_START];
	for(i=(CRC_CHECK_START+1);i<CRC_CHECK_STOP;i++){
		sum_1 += AdvPacket_2[i];
	}
	return sum_1;
}

void Set_Common_com_Data(void){
	Set_MacAddr();
	AdvPacket_2[1] = Adv_Packet_Len;  //数据长度，定长  装载的数据长度  ,19+6+2 = 27
	
	AdvPacket_2[8] = 20;   // payload数据长度
	AdvPacket_2[9] = 0x01;
	AdvPacket_2[10] = 0x04;
	AdvPacket_2[11] = 0x11;
	AdvPacket_2[12] = 0x07;   //
	
	AdvPacket_2[13] = 0x00;    //company set,厂家码
	AdvPacket_2[14] = 0x10;    //遥控器，遥控器用0x10来识别
}

void Set_Common_Tx_Data(void){
	AdvPacket_2[22] = 0;
    
	SequenceNum_1 ++;

	AdvPacket_2[23] = SequenceNum_1;
	AdvPacket_2[24] = Calc_CRC_Value();
	AdvPacket_2[25] = 0x00;
	AdvPacket_2[26] = 0xAA;  //幸好在接收模块上只识别到0xAA
}


void ShortKey_PowerOn(void){
    loginfo("Pwon\r\n");
    CurrentGroup_1[0] = Group_ALL;
    AdvPacket_2[15] = Group_ALL;    //组
    AdvPacket_2[19] = BLE_CMD_onoff;    //on/off cmd
    AdvPacket_2[20] = CMD_turn_on;
    
}
void ShortKey_PowerOff(void){
    loginfo("Pwoff\r\n");
    CurrentGroup_1[0] = Group_ALL;
    AdvPacket_2[15] = Group_ALL;    //组
    AdvPacket_2[19] = BLE_CMD_onoff;    //on/off cmd
    AdvPacket_2[20] = CMD_turn_off;
}
void ShortKey_E(void){
    loginfo("K_E\r\n");

}
void ShortKey_S_sub(void){
    loginfo("K_S sub\r\n");

}
void ShortKey_S_add(void){
    loginfo("K_S add\r\n");

}
void ShortKey_White(void){
    loginfo("K_white\r\n");
}
void ShortKey_Red(void){
    loginfo("K_red\r\n");

}
void ShortKey_B_add(void){
    loginfo("K_b add\r\n");

}
void ShortKey_Yellow(void){
    loginfo("K_yellow\r\n");

}
void ShortKey_Green(void){
    loginfo("K_green\r\n");

}
void ShortKey_Scale(void){
    loginfo("K_scale\r\n");

}
void ShortKey_Color(void){
    loginfo("K_color\r\n");

}

void ShortKey_Blue(void){
    loginfo("K_blue\r\n");

}
void ShortKey_B_sub(void){
    loginfo("K_b sub\r\n");

}
void ShortKey_M1(void){
    loginfo("K m1\r\n");

}
void ShortKey_M2(void){
    loginfo("K m2\r\n");

}
void ShortKey_M3(void){
    loginfo("K m3\r\n");

}
void ShortKey_M4(void){
    loginfo("K m4\r\n");

}
void ShortKey_M5(void){
    loginfo("K m5\r\n");

}
void ShortKey_M6(void){
    loginfo("K m6\r\n");

}
void ShortKey_M7(void){
    loginfo("K m7\r\n");

}
void ShortKey_M8(void){
    loginfo("K m8\r\n");

}
void ShortKey_M9(void){
    loginfo("K m9\r\n");

}

uint8 LongKey_Indentify(uint8 keyvalue){
    if(keyvalue == SKEY_POWER_ON){
        return LKEY_POWER_ON;
    }
    if(keyvalue == SKEY_POWER_OFF){
        return LKEY_POWER_OFF;
    }
    if(keyvalue == SKEY_E){
        return LKEY_E;
    }
    if(keyvalue == SKEY_COLOR){
        return LKEY_COLOR;
    }
    return keyvalue;
}

void LongKey_PowerOn(void){
    loginfo("LK pwon\r\n");
}
void LongKey_PowerOff(void){
    loginfo("LK pwoff\r\n");
    CurrentGroup_1[0] = Group_ALL;
    AdvPacket_2[15] = Group_ALL;    //组
    AdvPacket_2[19] = BLE_CMD_onoff;    //on/off cmd
    AdvPacket_2[20] = CMD_turn_off;  

}
void LongKey_E(void){
    loginfo("LK e\r\n");

}
void LongKey_Color(void){
    loginfo("LK cl\r\n");

}


code st_key_handle_map Key24_TBL[]={ 
    {NO_KEY_PRESS,	NULL,},	// 0x0 
    //短按键处理
    
    {SKEY_M3,      	 ShortKey_M3,},         // 1
    {SKEY_YELLOW,    ShortKey_Yellow,},     // 2
    {SKEY_M8,        ShortKey_M8,},         // 3
    {SKEY_M1,        ShortKey_M1,},
    {SKEY_B_SUB,     ShortKey_B_sub,},
    {SKEY_S_ADD,     ShortKey_S_add,},
    {SKEY_M6,        ShortKey_M6,},  //7

    {SKEY_POWER_ON,  ShortKey_PowerOn,},
    {SKEY_SCALE,     ShortKey_Scale,},
    {SKEY_RED,       ShortKey_Red,},  // 10
    {SKEY_M5,        ShortKey_M5,},
    {SKEY_S1,	     	 NULL,},	// 12
    {SKEY_GREEN,     ShortKey_Green,},
    {SKEY_WHITE,     ShortKey_White,},
    {SKEY_M7,        ShortKey_M7,},
    {SKEY_M9,        ShortKey_M9,}, //15
    {SKEY_COLOR,     ShortKey_Color,},
    {SKEY_S_SUB,     ShortKey_S_sub,},
    {SKEY_M2,        ShortKey_M2,},
    {SKEY_E,         ShortKey_E,},
    {SKEY_BLUE,      ShortKey_Blue,}, //20
    {SKEY_B_ADD,     ShortKey_B_add,},
    {SKEY_M4,      	 ShortKey_M4,}, //22
    {SKEY_POWER_OFF, ShortKey_PowerOff,}, //23

    {LKEY_POWER_ON,  LongKey_PowerOn,},
    {LKEY_POWER_OFF, LongKey_PowerOff,},    
    {LKEY_E,         LongKey_E,},
    {LKEY_COLOR,     LongKey_Color}
};


//K_green   K_white  K_S add  K_color
#define KEYRELEASE  0
void Key_Scan(void){
	uint8 inKey;
    
    inKey = Key24_Detect_GPIO();
    if(inKey == KEYRELEASE){//按键释放
        if(KeyCode){
            if((KeyCount >= 50) && (KeyCount < 1000))  //短按的释放
            {
                if(Key24_TBL[KeyCode].index == KeyCode){
                    Key24_TBL[KeyCode].handle();
                }else{
                    //logvalue(0xAA,KeyCode, Key24_TBL[KeyCode].index); 
                    loginfo("Kerr");
                }
            }else if(KeyCount > 1200){//长按按键
                if(Key24_TBL[KeyCode].index == KeyCode){
                   Key24_TBL[KeyCode].handle();
                }
            }
            
            adv_flag = 1 ;
            KeyCode = 0;
        }
    }else{//按键
        if(KeyCode == 0){
            KeyCount = 0;
        }
        
        if(KeyCount > 1000){
            KeyCode = LongKey_Indentify(inKey);
        }else{
            KeyCode = inKey;
        }
#if 0
		if(KeyCount < 10000){	
			KeyCount++;	
		}else{
			KeyCount = LONG_CNT+1;
		}
#endif        
    }
}

#if 0
void Key_Scan_old(void)
{
	uint8 inKey;
	uint8 KeyMode = 0;
	uint8 newKey;
	newKey=HAL_KEY_NO_KEY;
	inKey = Key_Detect_GPIO();  //读取按键值
	short_long_touch_flag = 0;
	if(inKey != KeyCode)
	{
		if(KeyCode)
		{
      		Close_FuncLED();
			if((KeyCount >= SHORT_CNT) && (KeyCount < LONG_CNT))  //短按的释放
			{
				KeyMode = KEY_PUSH_UP;  //释放按键
				newKey  = Key_TBL[KeyCode];
				switch(newKey)
				{
                    case HAL_KEY_POWER_ON:    // all on/off
					case HAL_KEY_POWER_OFF:
                        CurrentGroup_1[0] = Group_ALL;
                        AdvPacket_2[15] = Group_ALL;    //组
						AdvPacket_2[19] = BLE_CMD_onoff;    //on/off cmd
                        if(newKey == HAL_KEY_POWER_ON){  //on
                            AdvPacket_2[20] = CMD_turn_on;
                        }else if(newKey == HAL_KEY_POWER_OFF){
                        	AdvPacket_2[20] = CMD_turn_off;  
                        }
						goto exit_0;
						break;  

                   case HAL_KEY_POWER_OFF1:  //小夜灯 -> 中性光 
                    AdvPacket_2[15] = CurrentGroup_1[0];
				    AdvPacket_2[19] = cmd_setcw_mode;	//on/off cmd
				    AdvPacket_2[20] = 255; //打开
				    AdvPacket_2[21] = 255; //打开
				    goto exit_2;
					//AdvPacket_2[15] = CurrentGroup_1[0];
					//AdvPacket_2[19] = cmd_cw_low_set;	//on/off cmd
					//AdvPacket_2[20] = 0; //打开
                    //goto exit_0;
						break;
                        
					//case HAL_KEY_POWER_ON1:   //在长条形中是小夜灯
					case HAL_KEY_POWER_ON2:  // // 开1 //  休闲  -> 定时
					    AdvPacket_2[15] = CurrentGroup_1[0];
					    AdvPacket_2[19] = cmd_time_set;	//on/off cmd
					    AdvPacket_2[20] = DingShing_Time; //打开
					    //AdvPacket_2[21] = 0x0f; //打开
						//CurrentGroup_1[0] = Group_One;
						//AdvPacket_2[15] = CurrentGroup_1[0];
						//AdvPacket_2[19] = BLE_CMD_onoff;	//on/off cmd
						//AdvPacket_2[20] = CMD_turn_on; //打开
						goto exit_0;
						break;
					//组2开
					//case HAL_KEY_POWER_ON2:
					 case HAL_KEY_POWER_OFF2:  //   开2   // 阅读  -> 小夜灯
					    AdvPacket_2[15] = CurrentGroup_1[0];
					    AdvPacket_2[19] = cmd_setcw_mode;	//on/off cmd
					    AdvPacket_2[20] = 15; //打开
					    AdvPacket_2[21] = 15; //打开
						//CurrentGroup_1[0] = Group_Two;
						//AdvPacket_2[15] = CurrentGroup_1[0];
						//AdvPacket_2[19] = BLE_CMD_onoff;	//on/off cmd
						//AdvPacket_2[20] = CMD_turn_on; //打开
						goto exit_2;
						break;	
                 
                    
					case HAL_KEY_POWER_ON3:    // 关1      学习   ->  暖光
					    AdvPacket_2[15] = CurrentGroup_1[0];
					    AdvPacket_2[19] = cmd_setcw_mode;	//on/off cmd
					    AdvPacket_2[20] = 0; //打开
					    AdvPacket_2[21] = 255; //打开
                        goto exit_2;
						break;
					//case HAL_KEY_POWER_OFF2:
					 case HAL_KEY_POWER_OFF3:  // 关2      工作   ->  白光
                        AdvPacket_2[15] = CurrentGroup_1[0];
					    AdvPacket_2[19] = cmd_setcw_mode;	//on/off cmd
					    AdvPacket_2[20] = 255; //打开
					    AdvPacket_2[21] = 0; //打开
                        goto exit_2;
						break;	
  
                    case HAL_KEY_BRIGHT_UP:
                    case HAL_KEY_BRIGHT_DOWN:
						AdvPacket_2[15] = CurrentGroup_1[0];//组号  off时，不切换组，只对当前操作发组号
						if(newKey==HAL_KEY_BRIGHT_UP)
							AdvPacket_2[19] = cmd_light_inc_set;	//亮度
						else if(newKey==HAL_KEY_BRIGHT_DOWN)
							AdvPacket_2[19] = cmd_light_dec_set;	//亮度
						goto exit_0;
						break;
                    case HAL_KEY_TEMP_DOWN:
                    case HAL_KEY_TEMP_UP:
						AdvPacket_2[15] = CurrentGroup_1[0];//组号  off时，不切换组，只对当前操作发组号
						if(newKey==HAL_KEY_TEMP_UP)
							AdvPacket_2[19] = cmd_temp_inc_set;	//色温
						else if(newKey==HAL_KEY_TEMP_DOWN)
							AdvPacket_2[19] = cmd_temp_dec_set;	//色温

						AdvPacket_2[20] = 0x00;
					exit_0:
						fen_Duan = 0;
						rgb_static_dynamic = 0;
					//exit_1:
						AdvPacket_2[21] = 0x00;
                    exit_2:
						short_long_touch_flag = 1;
						AdvPacket_2[22] = 0x00;
						SequenceNum_inc_1 = 0;
                        break;
					default:
						{
                        KeyMode = 0 ;
                        newKey = 0 ;
						break;
						}
				}			
			}
			else if(KeyCount > LONG_CNT){   //长按的释放
				KeyMode = KEY_PUSH_UP;  //释放按键
				newKey  = Key_TBL[KeyCode];
				long_key_value_tempp = 0;  //长按只要释放了，就算重新按键
				SequenceNum_1++;
				switch(newKey)
				{
                    case HAL_KEY_BRIGHT_UP:
                    case HAL_KEY_BRIGHT_DOWN:
                    case HAL_KEY_TEMP_DOWN:
                    case HAL_KEY_TEMP_UP:
						short_long_touch_flag = 3;
						long_key_value_temp = 0;
						AdvPacket_2[15] = CurrentGroup_1[0];			//组号  off时，不切换组，只对当前操作发组号
						AdvPacket_2[19] = cmd_light_temp_change_stop;	//停止变化
						AdvPacket_2[21] = 0x00;
						AdvPacket_2[22] = 0x00;
						SequenceNum_inc_1 = 0;
						break;
				}
			}
		}
		KeyCode = inKey;
		KeyCount = 0;
		longCount_scale = 0;
        wIdleTime = 0;
        KeyCode1 = 0;
	}
	else if(KeyCode)
	{
		if(KeyCount < 10000){	
			KeyCount++;	
		}else{
			KeyCount = LONG_CNT+1;
		}
			
        if(KeyCount == SHORT_CNT){
            Open_FuncLED();
        }

        if(KeyCount >= LONG_CNT_ADD){
            KeyCount = LONG_CNT+1; 
            KeyMode = KEY_PUSH_LONG;
			newKey = Key_TBL[KeyCode];
             switch(newKey){

                case HAL_KEY_BRIGHT_UP:
                case HAL_KEY_BRIGHT_DOWN:
					AdvPacket_2[15] = CurrentGroup_1[0];//组号  off时，不切换组，只对当前操作发组号
					if(newKey==HAL_KEY_BRIGHT_UP)
						AdvPacket_2[19] = cmd_light_inc_set;	//亮度长加
					else if(newKey==HAL_KEY_BRIGHT_DOWN)
						AdvPacket_2[19] = cmd_light_dec_set;	//亮度长减
					AdvPacket_2[20] = 0x00;
					short_long_touch_flag = 2;
					AdvPacket_2[21] = 0x00;
					AdvPacket_2[22] = 0x00;	
					break;
                    
                case HAL_KEY_TEMP_DOWN:
                case HAL_KEY_TEMP_UP:
						AdvPacket_2[15] = CurrentGroup_1[0];//组号  off时，不切换组，只对当前操作发组号
						if(newKey==HAL_KEY_TEMP_UP)
							AdvPacket_2[19] = cmd_temp_inc_set;	//色温长增
						else if(newKey==HAL_KEY_TEMP_DOWN)
							AdvPacket_2[19] = cmd_temp_dec_set;	//色温长减
						AdvPacket_2[20] = 0x00;
						short_long_touch_flag = 2;
						AdvPacket_2[21] = 0x00;
						AdvPacket_2[22] = 0x00;
                    break;
                
                default:	
					newKey  = HAL_KEY_NO_KEY;
                    KeyMode = 0;
				break;   
             }
            
        }

		
		if(KeyCount == LONG_CNT)	// long key
		{
			longCount_scale++;
			if(longCount_scale>=Long_CNT_SCALE){
				longCount_scale = 0;
			}
			KeyMode = KEY_PUSH_LONG;
			newKey = Key_TBL[KeyCode];
			{
            switch(newKey)
			{
                case HAL_KEY_POWER_ON1:
					
						CurrentGroup_1[0] =  Group_One;

						AdvPacket_2[15] = Group_ALL;//组号  off时，不切换组，只对当前操作发组号		
						AdvPacket_2[19] = cmd_team_set; //组设置命令
						AdvPacket_2[20] = CurrentGroup_1[0];
						short_long_touch_flag = 2;
					    AdvPacket_2[21] = 0x00;
					    AdvPacket_2[22] = 0x00;						
				   		break;
												
                case HAL_KEY_BRIGHT_UP:
                case HAL_KEY_BRIGHT_DOWN:
					AdvPacket_2[15] = CurrentGroup_1[0];//组号  off时，不切换组，只对当前操作发组号
					if(newKey==HAL_KEY_BRIGHT_UP)
						AdvPacket_2[19] = cmd_light_inc_set;	//亮度长加
					else if(newKey==HAL_KEY_BRIGHT_DOWN)
						AdvPacket_2[19] = cmd_light_dec_set;	//亮度长减
					AdvPacket_2[20] = 0x00;
					short_long_touch_flag = 2;
					AdvPacket_2[21] = 0x00;
					AdvPacket_2[22] = 0x00;					
					break;
                case HAL_KEY_TEMP_DOWN:
                case HAL_KEY_TEMP_UP:
					AdvPacket_2[15] = CurrentGroup_1[0];//组号  off时，不切换组，只对当前操作发组号
					if(newKey==HAL_KEY_TEMP_UP)
						AdvPacket_2[19] = cmd_temp_inc_set;	//色温长增
					else if(newKey==HAL_KEY_TEMP_DOWN)
						AdvPacket_2[19] = cmd_temp_dec_set;	//色温长减
					AdvPacket_2[20] = 0x00;

					short_long_touch_flag = 2;
					AdvPacket_2[21] = 0x00;
					AdvPacket_2[22] = 0x00;	
                    break;
                case HAL_KEY_POWER_ON:
					CurrentGroup_1[0] =  Group_ALL;
					AdvPacket_2[15] = Group_ALL;//组号  off时，不切换组，只对当前操作发组号
					AdvPacket_2[19] = cmd_team_set; //组设置命令
					AdvPacket_2[20] = Group_ALL;
					short_long_touch_flag = 2;
					AdvPacket_2[21] = 0x00;
					AdvPacket_2[22] = 0x00;	
                    break;
				case HAL_KEY_POWER_OFF:
					AdvPacket_2[15] = Group_ALL;//组号  off时，不切换组，只对当前操作发组号
					AdvPacket_2[19] = cmd_dissolve_set; //组设置命令
					AdvPacket_2[20] = Group_ALL;
					short_long_touch_flag = 2;
					AdvPacket_2[21] = 0x00;
					AdvPacket_2[22] = 0x00;						
				    break;
				default:	
					newKey  = HAL_KEY_NO_KEY;
                    KeyMode = 0;
				break;
			}	
			}
		}		
	} 

	if((newKey != HAL_KEY_NO_KEY)&&(short_long_touch_flag!=0))
	{
		Set_Common_Tx_Data(); //设置一些公用的Tx数据
        adv_flag = 1 ;
        adv_flag_count = 0;
		tx_data_seted = 1;
		rf_encode_37 = 0;
		rf_encode_38 = 0;
		rf_encode_39 = 0;
		rf_encode_state = 0;
	}
}
#endif

void TX_CMD_USE_BLE_mode(void)
{  //使用BLE方式发码
	//三个通道约3ms
	/* 在BLE三个广播信道中发送BLE Packet */
	++adv_flag_count;
	if( adv_flag_count > Tx_Resend_Times){  //发15次
		long_key_value_tempp = long_key_value_temp;//用于判断本次的长按与上一次的长按键是否一致。
		long_key_value_temp = 0;
		adv_flag = 0;
		adv_flag_count = 0;
	}
	
	RF_TxLen_CH3789 = 32;
	//三个通道发一次的时间约2ms,每4ms发一个轮回，则不会有冲突
	//一个通道发一次的时间约800us
	if(rf_encode_37  == 1){
		memcpy(&Payload_demo[0],&RF_TxBuf_CH37[0],RF_TxLen_CH3789);
		RF_Set_Chn(2);
		RF_TXNoAck(Payload_demo, RF_TxLen_CH3789);
		while(RF_TxFlag==0);
		RF_TxFlag=0;
	}
	if(rf_encode_38  == 1){	
		memcpy(&Payload_demo[0],&RF_TxBuf_CH38[0],RF_TxLen_CH3789);
		RF_Set_Chn(26);
		RF_TXNoAck(Payload_demo, RF_TxLen_CH3789);
		while(RF_TxFlag==0);
		RF_TxFlag=0;
	}
	if(rf_encode_39  == 1){
		memcpy(&Payload_demo[0],&RF_TxBuf_CH39[0],RF_TxLen_CH3789);
		RF_Set_Chn(80);
		RF_TXNoAck(Payload_demo, RF_TxLen_CH3789);
		while(RF_TxFlag==0);
		RF_TxFlag=0;
	}
}

void Get_MacAddr(void){   //从IC的寄存器中获取 mac地址
   // SrcAddr_1[4] = ID4;
	SrcAddr_1[3] = ID3;
	SrcAddr_1[2] = ID2;
    SrcAddr_1[1] = ID1;
	SrcAddr_1[0] = ID0;
}

void Set_MacAddr(void){
    AdvPacket_2[2] = SrcAddr_1[0];
    AdvPacket_2[3] = SrcAddr_1[1];
    AdvPacket_2[4] = SrcAddr_1[2];
    AdvPacket_2[5] = SrcAddr_1[3];
    AdvPacket_2[6] = 0;//SrcAddr_1[4];  //原来BLE包需要的数据

    AdvPacket_2[16] = SrcAddr_1[0];  //ID的LSB ，1586从数据包抓取的mac地址
    AdvPacket_2[17] = SrcAddr_1[1];
    AdvPacket_2[18] = SrcAddr_1[2];
}
void Power_On_Init(void){
    uint8 i = 10;
	EA = 0;
	InitSysTimer();
	Sys_set_1MHZ_rate();
	EA = 1;

#if UART_ENABLE
    UartConfig(BAUD);
    WaitUs(60000);	
#endif

    BlePacketDeductive( RF_TxBuf_CH37, AdvPacket_2, 29, 37);
#if UART_ENABLE
    uart_data_send[0] = '2';
    uart_data_send[1] = '4';
    uart_data_send[2] = '6';
    uart_data_send[3] = '1';
    uart_data_send[4] = 'i';
    uart_data_send[5] = 'n';
    uart_data_send[6] = 'i';
    uart_data_send[7] = 't';
    uart_data_send[8] = '\n';
    uart_data_send[9] = '\r';
    driver_uart_send_start(9);
    WaitUs(60000); 
#if 0    
	while(i){ //
	   // driver_uart_send_start(9);
       //  WaitUs(60000); 
       
		WaitUs(10); 
        Key_Scan();
	}
#endif

#else
    PALT1_CLB(BIT(2)); // 除能串口脚  
#endif
    
    Delay_ms(1);
    
    FuncLED_Init();
	CurrentGroup_1[0] = Group_ALL;
	Get_MacAddr();
	cRemoteIDLETime = 500;
	fen_Duan = 0;  //分段
	Set_Common_com_Data();	
}

uint8 single_RF_test=0;
void main(void)  
{
	PALT1_INIT();  	//PALT1:(0x87):bit[]7:0]=PWM4_IO_EN,PWM3_IO_EN,PWM2_IO_EN,PWM1_IO_EN,PWM0_IO_EN,UART0_IO,SPI_IO,IIC_IO
	mcu_clk_inital();
	gpio_init();
    WaitUs(500);
	
	Power_On_Init();   
    
	while(1)
	{
		EX5  = 1;								//RF interrupt
		if(u10msFlag)
		{
            u10msFlag = 0;
            Key_Scan();
            Sys_SleepModeCheck();
		}
		if(u2msFlag){	//每4ms执行一次
			u2msFlag = 0;
			if(adv_flag)
				TX_CMD_USE_BLE_mode();  //使用BLE模式发码		
		}
		if(u20msFlag){
			u20msFlag = 0;
			if(adv_flag){
				Ble_Packet_Encode();
			}
		}
		//Sys_PowerDown(); //git revert后 按键扫码影响
		Sys_PowerOn();
		MCU_IDLE();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
	}
}

