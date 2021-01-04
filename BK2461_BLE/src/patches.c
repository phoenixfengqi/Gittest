#include "patches.h"
uint8 g_patchPALT1;
bit adv_flag = 0;
uint8  adv_flag_count = 0;
bit bPowerDN = 0;
bit power_on = 0;
uint8 uart_data_len_send;
uint8 uart_data_count_send;
uint8 uart_data_send[UART_DATA_LEN];
uint16 wIdleTime = 0;
uint16 cRemoteIDLETime = 0;
uint8 DATA CLK_EN_CFG_TEMP;
