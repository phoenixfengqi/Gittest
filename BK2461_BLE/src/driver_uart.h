#ifndef _DRIVER_UART_H_
#define _DRIVER_UART_H_
#include "bk2461.h"

#define  SYS_CLOCK              16000000
#define  BAUD                   9600

#define CMD_LEN 32

extern unsigned char S_CMD[CMD_LEN];
extern unsigned char B_CmdOK;
extern unsigned char N_CmdLen;

enum {
CMD_TIMER  = 0x10,
CMD_ADC    = 0x11,
CMD_AES    = 0x12,
CMD_PWM    = 0x13,
CMD_SLEEP  = 0x14,
CMD_IDLE   = 0x15,
CMD_GPIO_OUT = 0x16,
CMD_GPIO_IN = 0x17,
CMD_PCA     = 0x18,
CMD_WDT     = 0x19,
CMD_SPI_M   = 0x20,
CMD_SPI_S   = 0x21,
CMD_RNG     = 0x22,
CMD_LBD     = 0x23,
CMD_RSSI    = 0x24,
CMD_RF      = 0x30,
CMD_FLASH   = 0x31,
CMD_UART    = 0x32,

CMD_START   = 0x55,
CMD_END     = 0x7e,
};

void UartConfig(uint16 baud);
//void StdioFuncConfig();
void driver_uart_send_start(uint8 len);
void Close_Uart(void);

#define LOG_DEBUG   1
#ifdef LOG_DEBUG
void loginfo(char *str);
void logvalue(uint8 type,uint8 value1,uint8 value2);
#else
#define loginfo(str)      
#define logvalue(a,b,c) 
#endif


//#define printf
#endif
