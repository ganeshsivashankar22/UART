#include<LPC21xx.h>
void uart_config(void);
void uart_tx(unsigned char);
unsigned char uart_rx();
int main()
{
char rxbyte;
uart_config();
while(1)
{
rxbyte=uart_rx();
uart_tx(rxbyte^32);
}
}
void uart_config(void)
{
PINSEL0|=1<<0|1<<2;
U0LCR=0x83;
U0DLL=97;
U0DLM=0;
U0LCR=0x03;
}
void uart_tx(unsigned char rxbyte)
{
while(((U0LSR>>5)&1)==0);
U0THR=rxbyte;
}
unsigned char uart_rx()
{
while((U0LSR&1)==0);
return U0RBR;
}