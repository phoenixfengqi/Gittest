#ifndef _DRIVER_GPIO_H_
#define _DRIVER_GPIO_H_
#include "bk2461.h"
/*NOTE:
	1、GPIO的上拉电阻默认是使能的
*/

#define GPIO_InputSetup(pn,i,pu,pd) \
    {\
	/*功能:对指定端口进行输入特性设定*/\
	/*pn:端口号;i、pu、pd:将要设为输入、使能上拉、使能下拉的管脚列表*/\
	P##pn##IN_EN |= ((i));\
	P##pn##OUT_EN |= (i);\
	if(pu)P##pn##_PU |= ((pu));\
	if(pd)P##pn##_PD |= ((pd));\
     }

#define GPIO_DiablePU(pn,pul) \
    {\
	/*功能:禁用指定端口上拉电阻特性*/\
	/*pn:端口号;pu:将要禁止上拉的管脚列表*/\
	if(pul)P##pn##_PU &= (~(pul));\
     }

#define GPIO_DiablePD(pn,pdl) \
    {\
	/*功能:禁用指定端口下拉电阻特性*/\
	/*pn:端口号;pd:将要禁止下拉的管脚列表*/\
	if(pdl)P##pn##_PD &= (~(pdl));\
     }

#define GPIO_OutputSetup(pn,oe,od) \
    {\
	/*功能:对指定端口进行输出特性设定*/\
	/*pn:端口号;od:将要设为使能od的管脚列表*/\
	P##pn##IN_EN &= (~(oe));\
	P##pn##OUT_EN &= (~(oe));\
	if(od)P##pn##_OPDR |= ((od));\
     }

#define GPIO_DiableOD(pn,odl) \
    {\
	/*功能:禁用指定端口的OD特性*/\
	/*pn:端口号;odl:将要禁止opendrain的管脚列表*/\
	if(odl)P##pn##_OPDR &= (~(odl));\
     }

#define GPIO_WakeupSetup(pn,enl,modl,modh) \
    {\
	/*功能:对指定端口进行唤醒功能设定*/\
	/*pn:端口号;enl、modl、modh:将要设为能够唤醒、低电平唤醒、高电平唤醒的管脚列表*/\
	if(enl)P##pn##_WUEN |= ((enl));\
	if(modh)P##pn##_WUMOD |= ((modh));\
	if(modl)P##pn##_WUMOD &= (~(modl));\
    }


#define GPIO_HiZ(pn,i) \
    {\
	/*功能:将指定端口的指定脚位设为高阻态*/\
	/*pn:端口号;i:将要设高阻态的管脚列表*/\
	P##pn##IN_EN |= (~(i));\
	P##pn##OUT_EN |= (i);\
	GPIO_DiablePD(pn, i);\
	GPIO_DiablePU(pn, i);\
	GPIO_DiableOD(pn, i);\
     }



void gpio_Sleep_init(void);

#endif
