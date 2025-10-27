#include<lpc21xx.h>
#include "4bit.h"
void uart_config();
void uart_tx(unsigned char);
unsigned char uart_rx();



int main()
{
int i;
char rxbyte[8];
LCD_INIT();
 LCD_STRING("uart testing...");
uart_config();

 for(i=0;i<8;i++)
 {
 rxbyte[i]=uart_rx();
 }
 LCD_STRING(rxbyte);
}
void uart_config()
{
PINSEL0=0x05;
U0LCR=0x83;
U0DLL=97;
U0DLM-0;
U0LCR=0x03;
}
void uart_tx(unsigned char d)
{
while(((U0LSR>>5)&1)==0);
U0THR=d;
}
unsigned char uart_rx()
{
while((U0LSR&1)==0);
return U0RBR;
}

