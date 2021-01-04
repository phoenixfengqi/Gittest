/***********************************************************
Copyright (C), 1998-2011, Esense Technology Co., Ltd.
FileName	: 
Author		:  
Date		:
Description	: 
Version		: v0.1
Function List: 
----
History: 
<author>       <time>         <version >           <desc>
                   2011/03/01        0.1             build this moudle 
***********************************************************/

#ifndef _BLE_BOARDCAST_H_
#define _BLE_BOARDCAST_H_

#include "common.h"
#if 1
//type redefine
typedef void				VOID, *PVOID;
typedef char				BOOL;
typedef char				BOOLEAN;
typedef unsigned char		UINT8,BYTE, UCHAR, *PUCHAR;
typedef char				INT8;
typedef short				INT16;
typedef unsigned short	UINT16;
typedef unsigned long		UINT32;
typedef long				INT32;

#define VOLATILE    volatile
#define XDATA				xdata
#define PDATA				pdata
#define IDATA				idata
#define DATA				data
#define CODE				code

uint8 BlePacketEncode(UINT8 *dstPacket, const UINT8 *srcPacket, UINT8 len, UINT8 bleChannel );
UINT8 BlePacketDeductive( UINT8 *dstPacket, const UINT8 *srcPacket, UINT8 len, UINT8 bleChannel);

void MemCopy( UINT8 *dst, const UINT8 *src, UINT8 len );
#endif
void Sys_set_1MHZ_rate(void);
#endif
/***********************************************************
						end file
***********************************************************/
