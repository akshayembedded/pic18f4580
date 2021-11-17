#include<pic18.h>
void pwm_init(void);
void main()
{
	long  i;
	ADCON0=0x01;
	ADCON1=0x0E;
	TRISC=0x00;
	LATC=0x00;
	pwm_init();
	for(i=0;i<=1000;i++);
	while(1)
	{
		ADCON0=0x03;
	while(ADIF==0);//while(GODONE==1);	
	ADIF=0;	
	CCPR1L=ADRESH;
	for(i=0;i<=100000;i++);
	}	
}

void pwm_init(void)
{
	T2CON=0x06;
	PR2=155;//2khz
	CCP1CON=0x0c;
	CCPR1L=0x4e;
	
}	
/*
0.0004992*(50/100)


*/
