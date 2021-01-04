
#include "includes.h"
#include "common.h"

//#include <stdio.h>
//#include "patches.h"

//#include "driver_gpio.h"
//#include "driver_pwm.h"

xdata  uint16 time1ms_cnt=0;

uint8  u10msFlag,u2msFlag,u20msFlag;

DATA uint8  uMCUTick=0;
DATA uint8  uMCUTicke=0;
DATA uint8 uMCUTiick=0;

bit b2msFlag=0;


void InitSysTimer(void)
{
#ifdef    EN_TIMER0
    CLK_EN_CFG |= 0x40 ;                    // Enable timer clock.
    DIS_TIMER0INT();                    
    TR0 = 0; 
    TF0 = 0;
    TMOD &= 0xf0;   
    TMOD |= 0x01;                           //using Timer0 as tick base 
    TL0 = (TIMER0_100us_CNT & 0x00FF);
    TH0 = (TIMER0_100us_CNT >> 8);
    EN_TIMER0INT();                        //enable Timer0 int
    TR0 = 1;    
#else
    CLK_EN_CFG |= 0x40 ;                    // Enable timer clock.
    DIS_TIMER1INT();    
    TR1 = 0; 
    TF1 = 0;
    TMOD &= 0x0f;   
    TMOD |= 0x10;                           //using Timer1 as tick base(16bit timer/count)
    TL1 = TIMER0_2MS_CNT_L8;
    TH1 = TIMER0_2MS_CNT_H8;
    EN_TIMER1INT();                         //enable Timer1 int
    TR1 = 1;        
#endif
}

void timer0_int(void) interrupt 1
{
	TR0 = 0;
	TL0 = (TIMER0_100us_CNT & 0x00FF);
	TH0 = (TIMER0_100us_CNT >> 8);		
	TR0 = 1;
	time1ms_cnt++;
}

void et1_isr() interrupt 3          
{                                    //  2ms进入一次中断
	TR1 = 0; 
	TF1 = 0;                                // Timer1 overflow flag.

    TL1 = TIMER0_2MS_CNT_L8;
    TH1 = TIMER0_2MS_CNT_H8;       
	TR1 = 1;                                // used 1.16us.       
	++uMCUTick ;
	++uMCUTicke;
	++uMCUTiick;

    KeyCount++;

	if(uMCUTicke>= cMCUTickDutye){
		uMCUTicke = 0;
		u2msFlag = 0xff;
	}

	if(uMCUTiick>=9){
		uMCUTiick = 0;
		u20msFlag = 0xff;
	}
	if(uMCUTick>= cMCUTickDuty)
	{                                       // 10ms
		u10msFlag = 0xff;
		uMCUTick = 0;
		
	}
}

#if UART_ENABLE
void uart_isr() interrupt 4
{
    static unsigned char bCmdSt = 0;
    static unsigned char bCmdEd = 1;
    unsigned char c;
    unsigned char i;
    if(RI)
    {
        RI = 0;
        //unsigned char c;
        c = SBUF0;
        if( (CMD_START == c) && bCmdEd )
        {
            // just for clean the uart fifo             
            for(i=0;i<N_CmdLen;i++)
            {
                S_CMD[i] = 0;
            }
            bCmdSt = 1;
            bCmdEd = 0;
            N_CmdLen = 0;
        }   
        
        if(bCmdSt == 1)
        {
            S_CMD[N_CmdLen] = c;
            N_CmdLen++;
        }
        
        if( (CMD_END == c) && bCmdSt && ( N_CmdLen >= (S_CMD[2]+4) ) )
        {
            bCmdSt = 0;
            bCmdEd = 1;
            B_CmdOK = 1;
        }
    }
    else if(TI)
    {
        TI = 0;
        if(uart_data_len_send--)
            SBUF0 = uart_data_send[uart_data_count_send++];
    }
}
#endif

