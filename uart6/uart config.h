	#include<LPC21xx.h>

void uart_config(void);

void uart_tx(unsigned char);

unsigned char uart_rx(void);


void uart_config(void)

{

PINSEL0|=1<<16|1<<18;

U1LCR=0x83;

U1DLL=97;

U1DLM=0;

U1LCR=0x03;

}

void uart_tx(unsigned char rxbyte)

{

while(((U1LSR>>5)&1)==0);

U1THR=rxbyte;

}

unsigned char uart_rx(void)

{

while((U1LSR&1)==0);

return U1RBR;

}