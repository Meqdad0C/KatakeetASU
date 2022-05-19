#include "lcd.h"

void lcd_init (void)
{
    SYSCTL_RCGCGPIO_R |= 0x02;
  while((SYSCTL_PRGPIO_R &= 0x02)==0){}
    SYSCTL_RCGCGPIO_R |= 0x01;
  while((SYSCTL_PRGPIO_R &= 0x01)==0){}


//    GPIO_PORTA_LOCK_R=0x4C4F434B;
//    GPIO_PORTB_LOCK_R=0x4C4F434B;

    GPIO_PORTB_DIR_R |= 0xFF;
    GPIO_PORTB_DEN_R |=0xFF;
    GPIO_PORTA_DIR_R |= 0xE0;
    GPIO_PORTA_DEN_R |=0xE0;

    GPIO_PORTB_PCTL_R &=~ 0xFFFFFFFF;
    GPIO_PORTA_PCTL_R &=~ 0xFFFFFFFF;






    lcd_command(0x38);
    lcd_command(0x06);
    lcd_command(0x0F);
    lcd_command(0x01);
    lcd_command(0x0C);

}


void lcd_command(unsigned char command)
{
    GPIO_PORTA_DATA_R = 0x00 ; //e=rw=rs=0
    GPIO_PORTB_DATA_R = command;
    GPIO_PORTA_DATA_R |= 0x80; // e=1 (pulse) to secure data


    delay_us(1);
    GPIO_PORTA_DATA_R = 0x00;

    if (command<4)
        delay_ms(2);
    else
        delay_us(37);
}

    


void lcd_data(unsigned char data)
    {
       GPIO_PORTA_DATA_R = 0x20 ;
       GPIO_PORTB_DATA_R = data;
       GPIO_PORTA_DATA_R |= 0x80; // e=1 (pulse) to secure data


      GPIO_PORTA_DATA_R = 0x00;
        delay_ms(1);
    }


void LCD_String (char *str) /* Send string to LCD function */
    {
        int i;
        for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
        {
            lcd_data(str[i]);  /* Call LCD data write */
        }
    }
  void LCD_printInt(int no)
    {

      char toprint[4];
      sprintf(toprint, "%d",no);
            LCD_String(toprint);
    }
		
		void LCD_errormsg(void)
{
    lcd_command(0x01);
    lcd_command(0x80);
  LCD_String("ERR");
    delay_ms(2000);
    lcd_command(0x01);
}
