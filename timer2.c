#include<pic18.h>
void timer2_init(void);
void timer2();
void main()
{
	int i;
	TRISC=0x00;
	LATC=0x00;
	timer2_init();
	while(1)
	{
	LATC=~LATC;//0xff
timer2();
	}	
}

void timer2_init(void)
{
	T2CON=0x7e;
}	
void timer2()
{
	
	TMR2IF=0;
	while(TMR2IF==0);

	
}