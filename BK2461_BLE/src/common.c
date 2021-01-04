#include "bk2461.h"

void Delay_ms(int ms)
{
    int i, j;

    for(i=0; i<ms; i++)
        for(j=0; j<1400; j++);
}

void WaitUs(uint32 us)	
{
	uint16 i;
	while (us)
	{
		for (i = 0; i < 1; ++i);
		us--;
	}
}

