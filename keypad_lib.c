#include "lcd.h"
#include "keypad.h"

char keypad(void)
{
	while(1)
	{
	LATB=0xe0;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  return('a'); 
	case 0x0b:  return('b'); 
	case 0x0D:  return('c'); 
	case 0x07:  return('d'); 
	}
	LATB=0xD0;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  return('e');      
	case 0x0b:  return('f');      
	case 0x0D:  return('g');      
	case 0x07:  return('h');      
	}
	LATB=0xB0;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  return('i');      
	case 0x0b:  return('j');      
	case 0x0D:  return('k');      
	case 0x07:  return('l');      
	}
	LATB=0x70;
	switch(PORTB&0x0f)//PORTB&0x0f
	{
	case 0x0e:  return('m');      
	case 0x0b:  return('n');      
	case 0x0D:  return('o');      
	case 0x07:  return('p');      
	}
	}
}