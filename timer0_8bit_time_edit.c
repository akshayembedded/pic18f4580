#include<pic18.h>
void timer0_init(void);
timer0(int );
void main()
{
	int i;
	TRISC=0x00;
	LATC=0x00;
	timer0_init();
	while(1)
	{
	LATC=~LATC;//0xff
timer0(2);
	}	
}

void timer0_init(void)
{
	T0CON=0xc7;
}	
void timer0(int t)
{
	for(i=0;i<t;i++)
	{
	TMR0=60;
	TMR0IF=0;
	while(TMR0IF==0);
	}
	
}