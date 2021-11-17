#include<pic18.h>
void main()
{
	char count=0;
TRISC=0x01;
LATC=0x00;
while(1)
{
	if(RC0==0)//LATC0 LATC1
	{
		if(count%3==0)
		{
		LATC=0x02;
		}
		else if(count%3==1)
		{
		LATC=0x04;
		}
		else
		{
		LATC=0x00;
	
		}
		count++;
		while(RC0==0);
	}
}
}