#include<LPC21xx.h>
#include"uart config.h"
#include "lcd config.h"
#define LED 1<<14
void UART_STRING(unsigned char *);
int main()
{
char ch;
LCD_INIT();
uart_config();
IODIR0|=LED;
IOSET0=LED;
LCD_STRING("LED IS OFF");
while(1)
{
ch=uart_rx();
if(ch=='1')
{
LCD_CMD(0x80);
IOCLR0=LED;
LCD_STRING("LED IS ON");
UART_STRING("LED TURNED ON");
}
else if(ch=='0')
{
 LCD_CMD(0x80);
IOSET0=LED;
LCD_STRING("LED IS OFF");
UART_STRING("LED TURNED OFF");
}
else
{

LCD_CMD(0x80);
LCD_STRING("WRONG COMMAND");
}
}
}

void UART_STRING(unsigned char *s)
{
while(*s)
{
uart_tx(*s);
s++;
}
}
