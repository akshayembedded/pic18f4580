#include<pic18.h>

void main()
{
	int min,sec;
T3CON=0x71;
CCP1CON=0x05;
while(1)
{
if(CCP1IF==1)
{
	min;
	sec;
CCPR1H;
CCPR1L;
}
while(TMR3IF==0)
{
sec++;
if(sec==60)
{
min++;
}
}
}

}