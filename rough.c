#include<lpc21xx.h>
#define led 0x01
void ext__isr(void) __irq;
void time(unsigned ms)
{
 int i;
	for(;ms>0;ms--)
	  for(i=120000;i>0;i--);
}
int main()
{ PINSEL1=0x01;
 IODIR0=led;
 VICIntSelect=0x14;
 VICVectCntl0=0X20|14;
 VICVectAddr0=(unsigned long)ext__isr;
 EXTMODE=0x00;
 EXTPOLAR=0x00;
 VICIntEnable=1<<14;
 while(1);
}

void ext__isr(void) __irq

{
EXTINT=0x01;
IOCLR0=led;
	time(20);
	IOSET0=led;

VICVectAddr=0;

}