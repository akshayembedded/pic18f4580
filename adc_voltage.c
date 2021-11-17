#include "lcd.h"

void main()
{
	int c=452;
	int i;
	ADCON1=0x09;
	ADCON2=0x86;
	LATC=LATD=TRISC=TRISD=0x00;
	cmd4(0x33);
	cmd4(0x32);
	cmd4(0x28);
	cmd4(0x01);
	cmd4(0x0E);
	cmd4(0x83);

	while(1)
	{
		long a;
		ADCON0=0x15;
		for(i=0;i<=10000;i++);
		ADCON0=0x17;
		while(ADIF==0);
		cmd4(0x80);
		a=(ADRESH<<8)+(ADRESL);
		a=(a*500)/1023;
		data4((a/100)+48);//0 to 1023 0to 5 0 to 255
		data4('.');
		data4(((a%100)/10)+48);
		data4((a%10)+48);
		data4('v');
		ADCON0=0x05;
		for(i=0;i<=10000;i++);
		ADCON0=0x07;
		while(ADIF==0);
		cmd4(0xc0);
		a=(ADRESH<<8)+(ADRESL);
		a=(a*500)/1023;
		data4((a/100)+48);//0 to 1023 0to 5 0 to 255
		data4('.');
		data4(((a%100)/10)+48);
		data4((a%10)+48);
		data4('v');
		
	}
}
/*

0-> 0
5v ->1023
*/