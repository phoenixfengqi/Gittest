#include "patches.h"
#include "driver_uart.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

unsigned char S_CMD[CMD_LEN] = {0};
unsigned char B_CmdOK = 0;
unsigned char N_CmdLen = 0;


#if UART_ENABLE
void UartConfig(uint16 baud)
{
    uint16 tmp;

    //CLK_EN_CFG = 0xFF;                  //打开UART时钟使能和Timer 的clk
    CLK_EN_CFG  |= BIT(5);  
    //CLK_EN_CFG |= (BIT(5)|BIT(6));
    PALT1_SETB(BIT(2));
    //PALT1 = 0x04;                       //打开I/O第二功能
    PCON2 = 0x080;                       //波特率不加倍
    SCON0 = 0x50;                       //配置串口为模式1
    T2CON = 0x30;                       //RX和TX的波特率生成器都为Timer2

    tmp = 65536 - ( SYS_CLOCK/32 ) / baud;  //计算T2重载值
    RCAP2H = (tmp >> 8);
    RCAP2L = tmp & 0xFF;
    TH2 = RCAP2H;
    TL2 = RCAP2L;
    //EA = 1;                           //不启用UART中断
    ES0 = 1;
    TR2 = 1;                            //启动Timer2

//    StdioFuncConfig();
}

//void StdioFuncConfig()
//{
//    TI = 1;                            //TI:  Set TI to send first char of UART. For using printf, putchar
//}

void Close_Uart(void)
{
    PALT1 &= (~0x04); 
    ES0 = 0;
    TR2 = 0; 
}

void update_str(char *str){
    uint8 i = 0;
    uint8 len = strlen(str);
    if(len >= 16) len = 16;
    
    while(len--){
        uart_data_send[i] = *str++;
        i++;
    }
}

void driver_uart_send_start(uint8 len)
{
    uart_data_len_send = len;
    if(uart_data_len_send--)
    {
        uart_data_count_send = 0;
        SBUF0 = uart_data_send[uart_data_count_send++];
    }
}

#ifdef LOG_DEBUG
void loginfo(char *str){
 #if 1
    memset(uart_data_send, 0, 16);
    update_str(str);
    driver_uart_send_start(strlen(str));
    WaitUs(1000);
#endif    
}

void logvalue(uint8 type,uint8 value1,uint8 value2){
    if(value2){
        memset(uart_data_send, 0, 16);
        uart_data_send[0] = 0xff;
        uart_data_send[1] = type;
        uart_data_send[2] = value1;
        uart_data_send[3] = value2;
        uart_data_send[4] = 0xff;
        driver_uart_send_start(5);
        WaitUs(1000);
    }
}
#endif

#endif

