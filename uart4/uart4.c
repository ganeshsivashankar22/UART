#include<LPC21xx.h>
#define LED 1<<0
void uart_config(void);
void uart_interrupt_config(void);
void uart(void)__irq
{
U0THR='A' ;
VICVectAddr=0;
}
int main()
{
IODIR0=LED;
uart_config();
uart_interrupt_config()	;

while(1)
{
if((IOPIN0&(1<<14))==0)
{
IOCLR0=LED;
}
else
IOSET0=LED;
}

}
void uart_interrupt_config(void)
{
  VICIntSelect=0;
VICVectCntl0=(0x20)|6;
VICVectAddr0=(unsigned long)uart;
U0IER=1<<1;
VICIntEnable=1<<6;
}
void uart_config(void)
{
PINSEL0=0x5;
U0LCR=0x83;
U0DLL=97;
U0DLM=0;
U0LCR=0x03;
}
