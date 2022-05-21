#include "menu.h"


void menu(void){

    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Select mode from");
    lcd_command(0xC0);
    LCD_String("A    B    C    D");
}



void getStarted(void){
	
    GPIO_PORTF_DATA_R &=~ 0X0E;
    FlagH=0;
    menu();
    char c = keypad_getkey();

    switch(c){
        case 'A':
					
    popcorn();
    break;

        case 'B':
    Beef();
    break;

        case 'C':
    Chicken();
    break;

        case 'D':
    D();
    break;

        default:
    LCD_errormsg();
    getStarted();
        }

}
