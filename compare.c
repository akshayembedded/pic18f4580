#include<pic18.h>

void main()
{
TRISC2=0;
T3CON=0x71;
CCP1CON=0x08;
CCPR1H=0xf4;
CCPR1L=0x24;
while(1)
{	
while(CCP1IF=0);
while(TMR3IF==0);
LATC2=0;
CCP1IF=0;
TMR3IF=0;	
}

}