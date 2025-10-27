	#include<LPC21xx.h>


#define LCD 0xff


#define RS  1<<10


#define E   1<<11


void LCD_INIT(void);


void LCD_CMD(unsigned char);


void LCD_DATA(unsigned char);
void LCD_STRING(unsigned char *);
void delay(int ms)


{


T0PR=15000-1;
T0TCR=0x01;
while(T0TC<1);
T0TCR=0x03;
T0TCR=0x00;


}
void LCD_INIT(void)


 {


	  IODIR0=LCD|RS|E;


	  LCD_CMD(0x01);


	  LCD_CMD(0x02);


	  LCD_CMD(0x0c);


	  LCD_CMD(0x38);


	  LCD_CMD(0x80);


	                    


 }


 void LCD_CMD(unsigned char s)


 {


  IOCLR0=LCD;


  IOSET0=s;


  IOCLR0=RS;


  IOSET0=E;


  delay(2);


  IOCLR0=E;


  }


  void LCD_DATA(unsigned char s)


  {


  IOCLR0=LCD;


  IOSET0=s;


  IOSET0=RS;


  IOSET0=E;


  delay(2);


  IOCLR0=E;


  }
  void LCD_STRING(unsigned char *s)
  {
  while(*s)
  {
  LCD_DATA(*s);
  s++;
  }

  }