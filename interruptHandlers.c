#include "interruptHandlers.h"


void GPIOF_Handler(void){


        GPIO_PORTF_ICR_R = 0x10;
          switch(state){


        case 'A':
       lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Popcorn");
    stopwatch(1,0);
    break;

        case 'B':
            lcd_command(0x01);
            LCD_String("Defrosting ...");
             stopwatch_s(secondsPerKilo);
    break;

        case 'D':
            lcd_command(0x01);
            LCD_String("Cooking ...");
            stopwatch(mD,sD);
//            stopwatch_s(sD);


    break;
        case 'C':
            lcd_command(0x01);
                       LCD_String("Defrosting ...");
              stopwatch_s(secondsPerKilo);


          break;
        default:
            LCD_errormsg();
            getStarted();
          }
}

void GPIOD_Handler(void){


    switch(state){


       case 'D':

               k=-1;

            lcd_command(0xC0);
            LCD_String("00:00");
            for(int i=0;i<4;i++){
            inputs[i]='0';}
            break;



       case 'S':

         GPIO_PORTF_DATA_R&=~ 0X0E;
             while(1){

                    GPIO_PORTF_DATA_R^= 0X02;
                     delay_ms(100);
         if(GPIO_PORTD_DATA_R&0x04){
                     flagD = 1;
                     GPIO_PORTF_DATA_R &=~ 0X0E;
                    break;
                 }
                 if(((GPIO_PORTF_DATA_R&0x10)!=0x10)&&((GPIO_PORTA_DATA_R&0x04)!=0x04)){
                      GPIO_PORTF_DATA_R &=~ 0X0E;
                      GPIO_PORTF_DATA_R|= 0X0E;
                 break;
                 }
             }


        break;

       default:
       LCD_errormsg();
       getStarted();
         }


        delay_ms(400);
    GPIO_PORTD_ICR_R = 0x04;

    NVIC_ST_RELOAD_R=16000-1;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0x05;


}
void GPIOA_Handler(void){
    GPIOD_Handler();

        GPIO_PORTA_ICR_R = 0x04;

}
