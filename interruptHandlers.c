#include "interruptHandlers.h"


void GPIOF_Handler(void){

    GPIO_PORTF_ICR_R = 0x10;
    if((GPIO_PORTA_DATA_R&0x04)!=0x04){
    FlagF=1;
    }
//          switch(state){
//
//
//        case 'A':
//       lcd_command(0x01);
//    lcd_command(0x80);
//    LCD_String("Popcorn");
//    stopwatch(1,0);
//    break;
//
//        case 'B':
//            lcd_command(0x01);
//            LCD_String("Defrosting ...");
//             stopwatch_s(secondsPerKilo);
//    break;
//
//        case 'D':
//            lcd_command(0x01);
//            LCD_String("Cooking ...");
//            stopwatch(mD,sD);
//
//
//
//    break;
//        case 'C':
//            lcd_command(0x01);
//                       LCD_String("Defrosting ...");
//              stopwatch_s(secondsPerKilo);
//
//
//          break;
//        default:
//            LCD_errormsg();
//            getStarted();
//          }
//
//          GPIO_PORTF_ICR_R = 0x10;
//          NVIC_ST_RELOAD_R=16000-1;
//             NVIC_ST_CURRENT_R=0;
//             NVIC_ST_CTRL_R=0x05;

}

void GPIOD_Handler(void){
    GPIO_PORTD_ICR_R = 0x04;

    switch(state){


       case 'D':

               k=-1;

            lcd_command(0xC0);
            LCD_String("00:00");
            for(int i=0;i<4;i++){
            inputs[i]='0','0','0','0';}
            break;



       case 'S':

           FlagX=2;

//         GPIO_PORTF_DATA_R&=~ 0X0E;
//             while(1){
//
//                    GPIO_PORTF_DATA_R^= 0X02;
//                     delay_ms(100);
//         if(GPIO_PORTD_DATA_R&0x04){
//                     flagD = 1;
//                     GPIO_PORTF_DATA_R &=~ 0X0E;
//                     state=0;
//
//
//                    break;
//                 }
//                 if(((GPIO_PORTF_DATA_R&0x10)!=0x10)&&((GPIO_PORTA_DATA_R&0x04)!=0x04)){
//                      GPIO_PORTF_DATA_R &=~ 0X0E;
//                      GPIO_PORTF_DATA_R|= 0X0E;
//
//                 break;
//                 }
//             }
       case 0:
       {

       }


        break;

       default:
       LCD_errormsg();
       getStarted();
         }




    NVIC_ST_RELOAD_R=16000-1;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0x05;


}
void GPIOA_Handler(void){


    FlagX=1;
    GPIO_PORTA_ICR_R = 0x04;





}
