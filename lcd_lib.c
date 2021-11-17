#include "lcd.h"
void data(char a)//
{
	int i;
	RD0=1;
	LATC=a;
	RD1=1;
	for(i=0;i<=1000;i++);
	RD1=0;
	
}
void lcd_init()
{
cmd(0x38);
cmd(0x01);
cmd(0x0f);
}

void cmd(char a)//
{
	int i;
	RD0=0;
	LATC=a;
	RD1=1;
	for(i=0;i<=1000;i++);//delay()
	RD1=0;
}

void display(const char *p)
{
	while(*p)
	{
	
		data(*p);
		p++;
	}
}

/*  1011 1000 

    xxxx xxxx &   a
    1111 0000
    ----------
    xxxx 0000
    
LATC RC2 to rc5   
*/
void data4(char a)
{
	int i;
	LATC=0x00;
	RC0=1;
	LATC=LATC|((a&0xf0)>>2);
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
	
	LATC=0x00;
	RC0=1;
	LATC=LATC|((a&0x0f)<<2);
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
}
void cmd4(char a)
{
	int i;
	LATC=0x00;
	RC0=0;
	LATC=LATC|((a&0xf0)>>2);
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
	
	LATC=0x00;
	RC0=0;
	LATC=LATC|((a&0x0f)<<2);
	RC1=1;
	for(i=0;i<=1000;i++);
	RC1=0;
}