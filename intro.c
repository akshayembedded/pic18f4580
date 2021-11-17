#include <pic18.h>
void delay(void);
void main()
{
	TRISC=0x00;	//1010 1010
	while(1)
	{
		
		LATC=0xaa;
		delay();
		LATC=0x00;
		delay();
	}
}

void delay(void)
{
	int i,j;
	for(j=0;j<=400;j++)
	for(i=0;i<=1000;i++);
}