 #include<LPC21XX.H>
 #include"uart config.h"
 #include"lcd config.h"
  void uart_string(unsigned char*);
 int main()
 {
 char ch;
 int ind=0;
 unsigned char rxbyte[20];
 LCD_INIT();
 uart_config();
	while(1)
	{
	  ch=uart_rx();
	if(ch=='\r')
	break;
	else
	{
	if(ind<(sizeof(rxbyte)-1))
	{
	 rxbyte[ind++]=ch;
	}
	}
	}
	rxbyte[ind]='\0';
	LCD_CMD(0x80);
	LCD_STRING(rxbyte);
	uart_string(rxbyte);
 }
 void uart_string(unsigned char*s)
 {
 while(*s)
 {
 uart_tx(*s^32);
 s++;

 }
 }
