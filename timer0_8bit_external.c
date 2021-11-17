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
		if(TMR0L%2==0)
		{
		LATC=0xff;
		}
		else
		{
		LATC=0x00;
		}
	}	
}

void timer0_init(void)
{
	T0CON=0xE8;
}	
