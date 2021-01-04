#ifndef _DRIVER_TIMER_H_
#define _DRIVER_TIMER_H_
#include "bk2461.h"
#define SYS_CLOCK \
    16000000
#define CALC_13bitUP(freq) \
    (BIT(13)-(SYS_CLOCK/(freq)/12))

#define CALC_16bitUP(freq) \
    (BIT(16)-(SYS_CLOCK/(freq)/12))

#define CALC_8bitUP(freq) \
    (BIT(8)-(SYS_CLOCK/(freq)/12))

#define TIMER0_RELOAD(freq,bs16_13) \
    {\
    if(bs16_13==1)TL0 = (CALC_16bitUP(freq)&0xff);\
    if(bs16_13==1)TH0 = ((CALC_16bitUP(freq)>>8)&0xff);\
    if(bs16_13==0)TL0 = (CALC_13bitUP(freq)&0xff);\
    if(bs16_13==0)TH0 = ((CALC_13bitUP(freq)>>8)&0x1f);\
    }
#define TIMER0_13bit_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(0)|BIT(1)));\
    if(c_t)TMOD |= ((c_t)<<2);\
    TIMER0_RELOAD(freq, 0);\
    }

#define TIMER0_16bit_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(0)|BIT(1)));\
    TMOD |= (0x01|((c_t)<<2));\
    TIMER0_RELOAD(freq, 1);\
    }

#define TIMER0_8bitAR_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(0)|BIT(1)));\
    TMOD |= (0x02|((c_t)<<2));\
    TH0 = ((CALC_8bitUP(freq))&0xff);\
    TL0 = TH0;\
    }

#define TIMER0_8bit_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(0)|BIT(1)));\
    TMOD |= (0x03|((c_t)<<2));\
    TL0 = ((CALC_8bitUP(freq))&0xff);\
    }

#define TIMER0_INT_SETUP(en) \
    {ET0 = en;}

#define TIMER0_CLEAR_INTF() \
    {TF0 = 0;}


#define TIMER0_OPEN() \
    {TR0 = 1;}

#define TIMER0_CLOSE() \
    {TR0 = 0;}

#define TIMER1_RELOAD(freq,bs16_13) \
    {\
    if(bs16_13==1)TL1 = (CALC_16bitUP(freq)&0xff);\
    if(bs16_13==1)TH1 = ((CALC_16bitUP(freq)>>8)&0xff);\
    if(bs16_13==0)TL1 = (CALC_13bitUP(freq)&0x1f);\
    if(bs16_13==0)TH1 = ((CALC_13bitUP(freq)>>5)&0xff);\
    }
#define TIMER1_13bit_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(4)|BIT(5)));\
    TMOD |= (((c_t)<<6));\
    TIMER1_RELOAD(freq, 0);\
    }

#define TIMER1_16bit_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(4)|BIT(5)));\
    TMOD |= (0x10|((c_t)<<6));\
    TIMER1_RELOAD(freq, 1);\
    }

#define TIMER1_8bitAR_SETUP(freq,c_t) \
    {\
    TMOD &= (~(BIT(4)|BIT(5)));\
    TMOD |= (0x20|((c_t)<<6));\
    TH1 = ((CALC_8bitUP(freq))&0xff);\
    TL1 = TH1;\
    }

#define TIMER1_OPEN() \
    {TR1 = 1;}

#define TIMER1_CLOSE() \
    {TR1 = 0;}

#define TIMER1_INT_SETUP(en) \
    {ET1 = en;}

#define TIMER1_CLEAR_INTF() \
    {TF1 = 0;}

#define TIMER2_RELOAD(freq,bs16_13) \
    {\
    if(bs16_13==1)TL2 = (CALC_16bitUP(freq)&0xff);\
    if(bs16_13==1)TH2 = ((CALC_16bitUP(freq)>>8)&0xff);\
    if(bs16_13==0)TL2 = (CALC_13bitUP(freq)&0xff);\
    if(bs16_13==0)TH2 = ((CALC_13bitUP(freq)>>8)&0x1f);\
    }

#define TIMER2_16bit_SETUP(freq,c_t) \
    {\
    T2CON = 0;\
    TL2 = (CALC_16bitUP(freq)&0xff);\
    TH2 = ((CALC_16bitUP(freq)>>8)&0xff);\
    }

#define TIMER2_OPEN() \
    {TR2 = 1;}

#define TIMER2_CLOSE() \
    {TR2 = 0;}

#define TIMER2_INT_SETUP(en) \
    {ET2 = en;}

#define TIMER2_CLEAR_INTF() \
    {TF2 = 0;}


#define	cDeltaTime1					666			// 0.5ms
#define	cDeltaTime						66			// 500us



#endif
