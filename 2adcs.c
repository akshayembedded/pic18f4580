#include<pic18.h>
void cmd(char);
void data(char);
void display(const char *);
void dispnum(int );
void main()
{
	long i;
	ADCON0=0x01;
	ADCON1=0x0D;
	LATC=LATD=TRISC=TRISD=0x00;
	cmd(0x38);
	cmd(0x01);
	cmd(0x0c);
		while(1)
	{
	ADCON0=0x01;
	for(i=0;i<=1000;i++);	
	GODONE=1;
	while(ADIF==0);//while(GODONE==1);	
	ADIF=0;
	cmd(0x80);
	i=(ADRESH<<2)+(ADRESL>>6);//1023
	//
	dispnum(i);
	ADCON0=0x05;
	for(i=0;i<=1000;i++);	
	GODONE=1;
	while(ADIF==0);//while(GODONE==1);	
	ADIF=0;
	cmd(0xc0);
	i=(ADRESH<<2)+(ADRESL>>6);//1023
	//
	dispnum(i);

	
	
}
}
void cmd(char a)
{
	int i;
	RD0=0;
	LATC=a;
	RD1=1;
	for(i=0;i<=1000;i++);
	RD1=0;
}

void data(char a)
{
	int i;
	RD0=1;
	LATC=a;
	RD1=1;
	for(i=0;i<=1000;i++);
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

void dispnum(int i)
{
	int j=0,k=i;
	char a[5];
	do
	{
		a[j++]=(i%10+48);//526 i=52
	i=i/10;
	}while(i>0);
	//
	for(j--;j>=0;j--)//j=2 1 
	{
		data(a[j]);
	}
		display("   ");
		
}