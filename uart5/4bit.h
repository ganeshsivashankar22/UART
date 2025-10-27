#include<LPC21xx.h>
#define LCD 0xf<<14//D4 TO D7
#define RS 1<<8
#define E 1<<9


void LCD_INIT(void)	;
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char *);

  void delay(int ms)
{
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<ms);
T0TCR=0x03;
T0TCR=0x00;
}
void LCD_INIT(void)
{
IODIR0|=LCD|RS|E;
LCD_CMD(0x01);
LCD_CMD(0x02);
LCD_CMD(0x0c);
LCD_CMD(0x28);
LCD_CMD(0x80);
}
void LCD_CMD(unsigned char cmd)
{
IOCLR0=LCD;
IOSET0=(cmd&0X0F)<<14;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;

IOCLR0=LCD;
IOSET0=(cmd&0XF0)<<10;
IOCLR0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}

void LCD_DATA(unsigned char d)
{
IOCLR0=LCD;
IOSET0=(d&0X0F)<<14;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;

IOCLR0=LCD;
IOSET0=(d&0XF0)<<10;
IOSET0=RS;
IOSET0=E;
delay(2);
IOCLR0=E;
}
		void LCD_STRING(unsigned char* s)
		{
		while(*s)
		{
		LCD_DATA(*s++);
		}
		}
	 