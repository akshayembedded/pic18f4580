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
		t=keypad();
		data(t);
		while((PORTB&0x0f)!=0x0f);
	}	
}
