#ifndef _PATCHES_H_
#define _PATCHES_H_
#include "bk2461.h"
#define PALT1_INIT() \
    {g_patchPALT1=0;PALT1=g_patchPALT1;}

#define PALT1_SETB(bl) \
    {g_patchPALT1|=bl;PALT1=g_patchPALT1;}

#define PALT1_CLB(bl) \
    {g_patchPALT1&=~bl;PALT1=g_patchPALT1;}

#define PALT1_NEGB(bl) \
    {g_patchPALT1^=bl;PALT1=g_patchPALT1;}
extern uint8 g_patchPALT1;

extern bit b2msFlag;

#define	EN_TIMER0INT()			ET0	= 1
#define	DIS_TIMER0INT()			ET0 = 0

#define	EN_TIMER1INT()			ET1	= 1
#define	DIS_TIMER1INT()			ET1 = 0

#define	EN_TIMER2INT()			ET2	= 1
#define	DIS_TIMER2INT()			ET2 = 0

//#ifdef	EN_TIMER0
#define SysTimerStop()		TR0 = 0; 	\
							ET0 = 0;	\
							TR1 = 0; 	\
							ET1 = 0;	\
							CLK_EN_CFG_TEMP = CLK_EN_CFG; 	\
							CLK_EN_CFG = 0x00
							
							
#define SysTimerStart() 		CLK_EN_CFG = CLK_EN_CFG_TEMP;	\		
							TR0 = 1 ; 	\
							ET0 = 1	;	\		
							TR1 = 1 ; 	\
							ET1 = 1	

							
//
//	mcu idle sleep
// MCU Idle, system clock not change. 
#define MCU_IDLE() 			PCON2 = 0x01	
// MCU Idle, system clock changed to RC32K. Bit0: Idle, Bit2: RC32K selected. 
#define MCU_IDLE_32K() 	PCON2 = 0x05	
// MCU Idle, system clock changed to OSC32K. Bit0: Idle, Bit1: OSC32K selected.
#define MCU_SLEEP() 		PCON2 = 0x03		



#define	cMCUTickDuty		 	5
#define	cMCUTickDutye		 	2

#define UART_DATA_LEN               16	
extern bit adv_flag;
extern uint8  adv_flag_count;

extern bit bPowerDN;
extern bit power_on;

extern uint8 uart_data_len_send;
extern uint8 uart_data_count_send;
extern uint8 uart_data_send[UART_DATA_LEN];	

extern DATA uint8  uMCUTick;
extern DATA uint8  uMCUTicke;

extern uint16 wIdleTime,cRemoteIDLETime;

extern DATA uint8  CLK_EN_CFG_TEMP;

#endif
