#include "lcd.h"

void main()
{
	long  i;
	ADCON1=0x0f;
	TRISB=0x0f;
	TRISC=0x00;
	TRISD=0x00;
	LATC=0x00;
	lcd_init();
	while(1)
	{
	LATB=0xe0;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  data('a'); break;
	case 0x0b:  data('b'); break;
	case 0x0D:  data('c'); break;
	case 0x07:  data('d'); break;
	}
	LATB=0xD0;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  data('e'); break;
	case 0x0b:  data('f'); break;
	case 0x0D:  data('g'); break;
	case 0x07:  data('h'); break;
	}
	LATB=0xB0;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  data('i'); break;
	case 0x0b:  data('j'); break;
	case 0x0D:  data('k'); break;
	case 0x07:  data('l'); break;
	}
	LATB=0x70;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  data('m'); break;
	case 0x0b:  data('n'); break;
	case 0x0D:  data('o'); break;
	case 0x07:  data('p'); break;
	}
	}	
}
