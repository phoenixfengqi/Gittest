#ifndef _COMMON_H_
#define _COMMON_H_

#define  TRUE  1
#define  FALSE 0

#define FangZhen_Mode   1  //ʹ���ⲿFlash����

#if FangZhen_Mode
#define	Package_QFN24   1
#define	Package_SOP16	0
#define	UART_ENABLE		1
#else
#define	Package_QFN24   0    //�����棬��ʹ��SOP16��װ��оƬ
#define	Package_SOP16	1
#define	UART_ENABLE		0
#endif

/* �������Ͷ��� */
typedef  char			    bool;
typedef  signed char        int8;    // 8λ�з���������
typedef  signed int         int16;   //16λ�з���������
typedef  signed long int    int32;   //32λ�з���������
typedef  unsigned char      uint8;   // 8λ�޷���������
typedef  unsigned int       uint16;  //16λ�޷���������
typedef  unsigned long int  uint32;  //32λ�޷���������

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
//����2�ָ�ʽ�ı任
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
sbit key_s2 = P2^1; 
sbit key_s1 = P2^7; 
sbit key_s0 = P2^6; 

sbit key_r3 = P3^4;  //input
sbit key_r2 = P3^5;
sbit key_r1 = P3^6;
sbit key_r0 = P3^7;
#endif
#if Package_QFN24
sbit key_s3 = P2^2;  //output
sbit key_s2 = P2^3; 
sbit key_s1 = P2^7;
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

#define	Tx_Resend_Times	                    200  //һ�����4ms*200ms = 1s

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
#define		CMD_turn_on		                0x00     //��
#define		CMD_turn_off	                0x01     //�ص�

#define		cmd_device_return			    0x00	//���豸�ش���ǰ״̬
#define		cmd_team_set				    0x10	//������
#define		cmd_dissolve_set			    0x11	//��ɢ��

#define		BLE_CMD_onoff	                0x14

#define		DingShing_Time		            0x1E	//��ʱ30��
#define		cmd_time_set				    0x15	//��ʱ
#define		cmd_cw_low_set				    0x26	//Сҹ��
#define		cmd_FenDuan						0x27    //�ֶ�


#define		cmd_rgb_percent				    0x30	//����RGB��ռ�ٷֱ�
#define		cmd_powr_on_off_set			    0x31	//�����鿪�����
#define		cmd_static_scene_change			0x32	//��̬�����л�
#define		cmd_dynamic_scene_change		0x33	//��̬�����л�
#define		cmd_light_inc_long_set			0x34	//���ȳ���
#define		cmd_light_dec_long_set			0x35	//���ȳ���
#define		cmd_temp_inc_long_set			0x36	//ɫ�³���
#define		cmd_temp_dec_long_set			0x37	//ɫ�³���
#define		cmd_static_dynamic_state_set	0x38	//��̬����̬��ʾ״̬�л�
#define		cmd_light_temp_change_stop		0x39    //ֹͣ�仯
//#define		cmd_FenDuan						0x3A


#define		cmd_group_set				    0x50	//����������
#define		cmd_temp_set				    0x51	//����ɫ��ֵ
#define		cmd_light_set				    0x52	//��������ֵ
#define		cmd_half_set				    0x53	//�ƹ�50%���׹�50%
#define		cmd_temp_0_set				    0x54	//ɫ������Ϊ0
#define		cmd_temp_half_set			    0x55	//ɫ�����ó�5
#define		cmd_temp_max_set			    0x56	//ɫ�����ó�10

#define     cmd_setcw_mode                  0x57	//���� ɫ�� ����

#define		cmd_light_inc_set			    0x82	//���ȼ�
#define		cmd_light_dec_set			    0x83	//���ȼ�
#define		cmd_temp_inc_set			    0x84	//ɫ�¼�
#define		cmd_temp_dec_set			    0x85	//ɫ�¼�

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

#endif
