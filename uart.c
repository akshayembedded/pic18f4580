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
		txn(a);
		
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