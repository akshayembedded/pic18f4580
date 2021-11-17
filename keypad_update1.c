#include "lcd.h"
#include "keypad.h"
void main()
{
	long  i;
	char pass[]="abcd",in[4];
	ADCON1=0x0f;
	TRISB=0x0f;
	TRISC=0x00;
	TRISD=0x00;
	LATC=0x00;
	lcd_init();
	
	while(1)
	{
		char t;
		cmd(0x01);
		display("Enter a password");
		cmd(0xc0);
		for(t=0;t<4;t++)
		{
		in[t]=keypad();
		data(in[t]);
		while((PORTB&0x0f)!=0x0f);
		}
		for(t=0;t<4;t++)
		{
			if(in[t]!=pass[t])
			{break;}
		}
		for(i=0;i<=100000;i++);
		if(t==4)
		{
		cmd(0x01);
		display("Password Granted");
		}
		else
		{
		cmd(0x01);
		display("Password Denied");
		}
		for(i=0;i<=100000;i++);
	}	
}
