#include<LPC21xx.h>
void uart_config();
void uart_tx(unsigned char);
int main()
{
 char a='A';
while(1)
{

uart_config();

uart_tx(a);
a++;
if(a==91)
a=65;
}
}
void uart_config()
{
PINSEL0=0x05;
U0LCR=0x83;
U0DLL=97;
U0DLM=0;
U0LCR=0x03;
}
void uart_tx(unsigned char txbyte)
{
while(((U0LSR>>5)&1)==0);
U0THR=txbyte;

}