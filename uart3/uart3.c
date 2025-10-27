#include<LPC21xx.h>
void string(unsigned char*);
void uart_config(void);
void uart_tx(unsigned char );
int main()
{
 uart_config();
  string("ganesh");
}
 void string(unsigned char *s)
 {
 while(*s)
 {
 uart_tx(*s);
 s++;
 }
 }
 void uart_tx(unsigned char rxbyte)

{

while(((U0LSR>>5)&1)==0);

U0THR=rxbyte;

}
void uart_config(void)

{

PINSEL0|=1<<0|1<<2;

U0LCR=0x83;

U0DLL=97;

U0DLM=0;

U0LCR=0x03;

}
