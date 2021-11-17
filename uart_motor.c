#include<pic18.h>
void uart_init(void);
void txn(char a);
void display(const char *p);
char rec(void);

void main()
{
	char a;
	uart_init();
	while(1)
	{
		a=rec();
		switch(a)
		{
			case 'A':
			case 'a':
			RC0=0;
			RC1=1;
			break;
			case 'C':
			case 'c':
			RC0=1;
			RC1=0;
			break;
			case 'S':
			case 's':
			RC0=RC1=0;
			default:
			break;
		}
		
	}	
	
}

char rec(void)
{
	while(RCIF==0);
	return RCREG;
}
void uart_init(void)
{
	SPBRG=0x08;
	SPBRGH=0x02;
	TXSTA=0x24;
	RCSTA=0x90;
	BAUDCON=0x08;
	TRISC=0x80;
}

void txn(char a)
{
		while(TXIF==0);//stage
		TXREG=a;
}

void display(const char *p)
{
	while(*p)
	{
		txn(*p);
		p++;
	}
}