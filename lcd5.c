//printing A char
#include<lpc21xx.h>
void cmd (unsigned char cmd1);
#define pins  0xff
#define rs 1<<8
#define enable  1<<9
void delay(int ms)
{
	int i;
	for(;ms>0;ms--)
	 for(i=12000;i>0;i--);
 }
void intial()
{
 IODIR0=pins|rs|enable;
	cmd(0x01);
	cmd(0x02);
	cmd(0x0C);
	cmd(0x80);
	cmd(0x38);
}

void cmd(unsigned char cmd1)
{
 IOCLR0=pins;
 IOSET0=cmd1;
 IOCLR0=rs;
 IOSET0=enable;
 delay(20);
 IOCLR0=enable;
}
void data(unsigned char A)
{ int address;
	address=0x80;
	
while(1)
{	cmd(0x01);
IOCLR0=pins;
IOSET0=A;
IOSET0=rs;
IOSET0=enable;
	delay(20);
	IOCLR0=enable;
cmd(address++);
}
}

int main()
{  //int address;
	 char ch='A';
	//address=0x80;
   intial();
	//while(1)
	{data(ch);
		//cmd(0x01);
	  
	}
	 
   
	 
}