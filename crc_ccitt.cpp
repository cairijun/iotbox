#include "crc_ccitt.h"

unsigned int crc(const char *data, int len)
{
	unsigned int rst = 0x0;
	int i,j;
	for(i=0 ; i < len ; i++)
	{
		rst ^= data[i] << 8;
		for(j=0 ; j < 8 ; j++)
		{
			if(rst & 0x8000)
				rst = (rst << 1) ^ MASK;
			else
				rst <<= 1;
		}
	}
	return rst & 0xFFFF;
}

