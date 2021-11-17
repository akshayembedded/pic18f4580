
#include "lcd.h"

void main()
{
	int c=452;
	int i;
	LATC=LATD=TRISC=TRISD=0x00;
	cmd4(0x33);
	cmd4(0x32);
	cmd4(0x28);
	cmd4(0x01);
	cmd4(0x0E);
	cmd4(0x83);

	while(1)
	{
		cmd4(0x80);
		data4(c/100+48);
		data4(((c/10)%10)+48);//452%10  45
		data4(c%10+48);
		for(i=0;i<=30000;i++);
		c++;
	}
}

