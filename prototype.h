#include "stdint.h"
#include "TM4C123.h"
void delay_ms(uint32_t time);
void delay_us(uint32_t time);
void keypad_Init(void);
char keypad_getkey(void);
void lcd_init (void);
void lcd_command(unsigned char command);
void lcd_data(unsigned char data);
void LCD_String (char *str);
void LCD_printInt(int no);
void LCD_errormsg(void);
void porta_init(void);
void portd_init(void);
void portf_init(void);
void stopwatch_s(int s);
void stopwatch(int s,int m);
void displayTime(int m,int s);
void displayTime_s(int s);
void fini_stopwatch(void);
void getStarted(void);
void popcorn(void);
void Beef(void);
void Chicken(void);
void D(void);




