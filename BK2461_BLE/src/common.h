#ifndef _COMMON_H_
#define _COMMON_H_

#define  TRUE  1
#define  FALSE 0

#define FangZhen_Mode   1  //使用外部Flash仿真

#if FangZhen_Mode
#define	Package_QFN24   0
#define	Package_SOP16	  1
#define	UART_ENABLE		1
#else
#define	Package_QFN24   0    //不仿真，则使用SOP16封装的芯片
#define	Package_SOP16	1
#define	UART_ENABLE		0
#endif

/* 数据类型定义 */
typedef  char			    bool;
typedef  signed char        int8;    // 8位有符号整型数
typedef  signed int         int16;   //16位有符号整型数
typedef  signed long int    int32;   //32位有符号整型数
typedef  unsigned char      uint8;   // 8位无符号整型数
typedef  unsigned int       uint16;  //16位无符号整型数
typedef  unsigned long int  uint32;  //32位无符号整型数

#define VOLATILE        	volatile
#define XDATA				xdata
#define PDATA				pdata
#define IDATA				idata
#define DATA				data
#define CODE				code

#define BIT(n) \
	(1<<(n))
#define _BIT(n) \
	(~ BIT(n))

#define BFD(val,bs,bl) \
	((val&(BIT(bl)-1))<<(bs))
#define _BFD(val,bs,bl) \
	(~ BFD(val,bs,bl))

#define GET_BFD(val,bs,bl) \
	(((val)>>(bs))&(BIT(bl)-1))

//BIG ENDIAN to LITTLE ENDIAN
#define _BYTE(n,v) \
    (((v)>>(8*n))&0xff)
//用于2种格式的变换
#define B2L_32(bv) \
    ((_BYTE(0, bv)<<24)|\
    (_BYTE(1, bv)<<16)|\
    (_BYTE(2, bv)<<8)|\
    (_BYTE(3, bv)))

#define B2L_16(bv) \
    ((_BYTE(0, bv)<<8)|\
    (_BYTE(1, bv)))

#if UART_ENABLE
#define __DEBUG__
#endif

#ifdef __DEBUG__
#define PRINT \
    printf
#else
#define PRINT
#endif

#if Package_SOP16
sbit key_s3 = P2^0;  //output
sbit key_s2 = P2^4;  //P2^1; 
sbit key_s1 = P2^6; 
sbit key_s0 = P2^7; 

sbit key_r3 = P3^0;//P3^4;  //input
sbit key_r2 = P3^1;//P3^5;
sbit key_r1 = P3^2;//P3^6;
sbit key_r0 = P3^3;//P3^7;
#endif
#if Package_QFN24
sbit key_s3 = P2^2;  //output
sbit key_s2 = P2^3; 
sbit key_s1 = P2^7;sss
sbit key_s0 = P2^6;

sbit key_r3 = P3^3;   //input
sbit key_r2 = P3^2;
sbit key_r1 = P3^1;
sbit key_r0 = P3^0;

sbit	LED_Test = P1^1;
#endif

void delay(uint8 dly);

void Delay_ms(int ms);
void WaitUs(uint32 us);

#define	TIMER0_10MS_CNT					    52203	
#define	TIMER0_8MS_CNT  				    54869
#define	TIMER0_7MS_CNT  				    56203
#define	TIMER0_6MS_CNT  				    57536
#define	TIMER0_5MS_CNT  				    58869
#define	TIMER0_4MS_CNT  				    60203
#define	TIMER0_3MS_CNT  				    61536

#define	TIMER0_2_5MS_CNT				    62202
#define	TIMER0_2_5MS_CNT_H8 			    0xF2
#define	TIMER0_2_5MS_CNT_L8				    0xFA


#define	TIMER0_2MS_CNT 					    62870
#define	TIMER0_2MS_CNT_H8				    0xF5
#define	TIMER0_2MS_CNT_L8 				    0x96

#define	TIMER0_1MS_CNT					    64204

#define	TIMER0_100us_CNT				    65405

#define	Tx_Resend_Times	                    200  //一个命令发4ms*200ms = 1s

//-------------------------------------------------------
//		key count time
//#define	SHORT_CNT			            30/10 	// 50ms
#define	SHORT_CNT			                20/10

#define	LONG_CNT			                500/10  //500/10//1000/10//1500/10 //  1000ms
//#define	LONG_CNT			            200/10  //500/10//1000/10//1500/10 //  1000ms
                                        
#define LONG_CNT_ADD                        700/10       

#define	LONG_REPEAT_CNT		                200/10 // 1100ms
#define	LONG_BOND_CNT		                4000/10 // 1100ms
#define	Long_CNT_SCALE		                5

#define		Group_ALL		                0xff
#define		Group_One		                0x01
#define		Group_Two		                0x02
#define		Group_Three		                0x03
#define		Group_Four		                0x04
#define		CMD_turn_on		                0x00     //打开
#define		CMD_turn_off	                0x01     //关灯

#define		cmd_device_return			    0x00	//本设备回传当前状态
#define		cmd_team_set				    0x10	//设置组
#define		cmd_dissolve_set			    0x11	//解散组

#define		BLE_CMD_onoff	                0x14

#define		DingShing_Time		            0x1E	//定时30分
#define		cmd_time_set				    0x15	//定时
#define		cmd_cw_low_set				    0x26	//小夜灯
#define		cmd_FenDuan						0x27    //分段


#define		cmd_rgb_percent				    0x30	//设置RGB各占百分比
#define		cmd_powr_on_off_set			    0x31	//设置组开或组关
#define		cmd_static_scene_change			0x32	//静态场景切换
#define		cmd_dynamic_scene_change		0x33	//动态场景切换
#define		cmd_light_inc_long_set			0x34	//亮度长加
#define		cmd_light_dec_long_set			0x35	//亮度长减
#define		cmd_temp_inc_long_set			0x36	//色温长加
#define		cmd_temp_dec_long_set			0x37	//色温长减
#define		cmd_static_dynamic_state_set	0x38	//静态、动态显示状态切换
#define		cmd_light_temp_change_stop		0x39    //停止变化
//#define		cmd_FenDuan						0x3A


#define		cmd_group_set				    0x50	//设置组命令
#define		cmd_temp_set				    0x51	//设置色温值
#define		cmd_light_set				    0x52	//设置亮度值
#define		cmd_half_set				    0x53	//黄光50%，白光50%
#define		cmd_temp_0_set				    0x54	//色温设置为0
#define		cmd_temp_half_set			    0x55	//色温设置成5
#define		cmd_temp_max_set			    0x56	//色温设置成10

#define     cmd_setcw_mode                  0x57	//设置 色温 亮度

#define		cmd_light_inc_set			    0x82	//亮度加
#define		cmd_light_dec_set			    0x83	//亮度减
#define		cmd_temp_inc_set			    0x84	//色温加
#define		cmd_temp_dec_set			    0x85	//色温减

#define		Payload_len                     32
#define		Adv_Packet_Len                  27 
#define		Packet_length                   29
#define		BLE_PacketBuf_len	            32
#define		RF_TxBuf_CH3789_len	            BLE_PacketBuf_len

extern unsigned char Payload_demo[Payload_len];

extern unsigned char RF_TxFlag;

extern uint8  KeyCode;
extern uint8  KeyCode1;

extern uint16 KeyCount;
extern uint8  longCount_scale;
extern uint8  SequenceNum_1;
extern uint8  SequenceNum_inc_1;


extern uint8  SrcAddr_1[4];
extern uint8  CurrentGroup_1[1];
extern uint8  Static_scene_state;

extern uint8 u10msFlag,u2msFlag,u20msFlag;

void InitSysTimer(void);


typedef struct
{
    uint8 index;
    void (*handle)(void);
} st_key_handle_map;

#if 0
enum {
    NO_KEY_PRESS,		// 0x0 
    //短按键处理
    SKEY_POWER_ON,  // 1  
    SKEY_POWER_OFF, // 2  
    
    SKEY_E,         // 3
    SKEY_S_SUB,         // 4
    SKEY_S_ADD,         // 5
    
    SKEY_WHITE,         // 6
    SKEY_RED,         // 7
    SKEY_B_ADD,         // 8
    
    SKEY_YELLOW,         // 9
    SKEY_GREEN,         // 10
    SKEY_SCALE,         // 11
    
    SKEY_COLOR,         // 12
    SKEY_BLUE,         // 13
    SKEY_B_SUB,         // 14
    
    SKEY_M1,         // 15
    SKEY_M2,         // 16
    SKEY_M3,           // 17  
    SKEY_M4,         // 18
    SKEY_M5,         // 19
    SKEY_M6,           // 20  
    SKEY_M7,         // 21
    SKEY_M8,         // 22
    SKEY_M9,         // 23

    //长按键处理
    LKEY_POWER_ON,     // 24
    LKEY_POWER_OFF,    // 25   
    LKEY_E,             // 26
    LKEY_COLOR,         // 27
};
#else
enum {
    NO_KEY_PRESS  	=  0, 
    //短按键处理  
	SKEY_M3         =  1,  
	SKEY_YELLOW     =  2, 
	SKEY_M8         =  3,   
	SKEY_M1         =  4,
	SKEY_B_SUB      =  5,
	SKEY_S_ADD      =  6,
	SKEY_M6         =  7,
	SKEY_POWER_ON   =  8, 	
	SKEY_SCALE      =  9,	
	SKEY_RED        =  10,
	SKEY_M5         =  11,
	SKEY_S1         =  12,
	SKEY_GREEN      =  13,
	SKEY_WHITE      =  14,
	SKEY_M7         =  15,      
	SKEY_M9         =  16,
	SKEY_COLOR      =  17,
	SKEY_S_SUB      =  18,
	SKEY_M2         =  19,
	SKEY_E          =  20,
	SKEY_BLUE       =  21,		  
	SKEY_B_ADD      =  22,    
	SKEY_M4         =  23,
	SKEY_POWER_OFF  =  24,
  
//长按键处理
    LKEY_POWER_ON,   
    LKEY_POWER_OFF,  
    LKEY_E,          
    LKEY_COLOR
};



#endif

#endif
