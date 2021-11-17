#include<pic18.h>
void main()
{

TRISC=0x01;
TRISD=0x00;
LATC=0x00;
LATD=0x00;
while(1)
{
	if(RC0==0)//LATC0 LATC1
	{
		LATD=0xff;
	}
	else
	{
	LATD=0x00;
	}
}
}