#include<pic18.h>
void timer1_init(void);
void timer1();
void main()
{
	int i;
	TRISC=0x00;
	LATC=0x00;
	timer1_init();
	while(1)
	{
	LATC=~LATC;//0xff
timer1();
	}	
}

void timer1_init(void)
{
	T1CON=0xb1;
}	
void timer1()
{
	
	TMR1IF=0;
	while(TMR1IF==0);

	
}