#ifndef _DRIVER_GPIO_H_
#define _DRIVER_GPIO_H_
#include "bk2461.h"
/*NOTE:
	1��GPIO����������Ĭ����ʹ�ܵ�
*/

#define GPIO_InputSetup(pn,i,pu,pd) \
    {\
	/*����:��ָ���˿ڽ������������趨*/\
	/*pn:�˿ں�;i��pu��pd:��Ҫ��Ϊ���롢ʹ��������ʹ�������Ĺܽ��б�*/\
	P##pn##IN_EN |= ((i));\
	P##pn##OUT_EN |= (i);\
	if(pu)P##pn##_PU |= ((pu));\
	if(pd)P##pn##_PD |= ((pd));\
     }

#define GPIO_DiablePU(pn,pul) \
    {\
	/*����:����ָ���˿�������������*/\
	/*pn:�˿ں�;pu:��Ҫ��ֹ�����Ĺܽ��б�*/\
	if(pul)P##pn##_PU &= (~(pul));\
     }

#define GPIO_DiablePD(pn,pdl) \
    {\
	/*����:����ָ���˿�������������*/\
	/*pn:�˿ں�;pd:��Ҫ��ֹ�����Ĺܽ��б�*/\
	if(pdl)P##pn##_PD &= (~(pdl));\
     }

#define GPIO_OutputSetup(pn,oe,od) \
    {\
	/*����:��ָ���˿ڽ�����������趨*/\
	/*pn:�˿ں�;od:��Ҫ��Ϊʹ��od�Ĺܽ��б�*/\
	P##pn##IN_EN &= (~(oe));\
	P##pn##OUT_EN &= (~(oe));\
	if(od)P##pn##_OPDR |= ((od));\
     }

#define GPIO_DiableOD(pn,odl) \
    {\
	/*����:����ָ���˿ڵ�OD����*/\
	/*pn:�˿ں�;odl:��Ҫ��ֹopendrain�Ĺܽ��б�*/\
	if(odl)P##pn##_OPDR &= (~(odl));\
     }

#define GPIO_WakeupSetup(pn,enl,modl,modh) \
    {\
	/*����:��ָ���˿ڽ��л��ѹ����趨*/\
	/*pn:�˿ں�;enl��modl��modh:��Ҫ��Ϊ�ܹ����ѡ��͵�ƽ���ѡ��ߵ�ƽ���ѵĹܽ��б�*/\
	if(enl)P##pn##_WUEN |= ((enl));\
	if(modh)P##pn##_WUMOD |= ((modh));\
	if(modl)P##pn##_WUMOD &= (~(modl));\
    }


#define GPIO_HiZ(pn,i) \
    {\
	/*����:��ָ���˿ڵ�ָ����λ��Ϊ����̬*/\
	/*pn:�˿ں�;i:��Ҫ�����̬�Ĺܽ��б�*/\
	P##pn##IN_EN |= (~(i));\
	P##pn##OUT_EN |= (i);\
	GPIO_DiablePD(pn, i);\
	GPIO_DiablePU(pn, i);\
	GPIO_DiableOD(pn, i);\
     }



void gpio_Sleep_init(void);

#endif
