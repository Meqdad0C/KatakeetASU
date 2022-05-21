#include "stopwatch.h"


void stopwatch(int m, int s)
{

    state='S';
    GPIO_PORTF_DATA_R&=~ 0X0E;
    GPIO_PORTF_DATA_R|= 0X0E;
    displayTime(m,s);
    while(m>=0){
        if(s==0) {m--; s=59;}
        while(s < 60)
  {
    if(s>=0){
    displayTime(m,s);
   for(int i=1;i<=20;i++){
    if(FlagX==1||FlagX==2){
        delay_ms(300);
        FlagX=0;
      GPIO_PORTF_DATA_R&=~ 0X0E;
                   while(1){

                          GPIO_PORTF_DATA_R^= 0X02;
                           delay_ms(100);


               if(FlagX==2){
                           flagD = 1;
                           GPIO_PORTF_DATA_R &=~ 0X0E;


                           FlagX=0;
                          break;
                       }
                       if(FlagF==1){
                            GPIO_PORTF_DATA_R &=~ 0X0E;
                            GPIO_PORTF_DATA_R|= 0X0E;
                            FlagF=0;
                            FlagX=0;

                       break;
                       }

                   }
      }

    if(flagD==1){flagD=0; FlagH=1;FlagF=0;return; }
    delay_ms(50);

   }
    s--;

    }
    else break;
    }
        m--;
        s=59;
}
    fini_stopwatch();

}

void stopwatch_s(int s){

    GPIO_PORTF_DATA_R&=~ 0X0E;
    GPIO_PORTF_DATA_R|= 0X0E;
    state='S';
    while(s>0){
    displayTime_s(s);
    for(int i=1;i<=20;i++){
        if(FlagX==1||FlagX==2){
            delay_ms(300);
            FlagX=0;
          GPIO_PORTF_DATA_R&=~ 0X0E;
                       while(1){

                              GPIO_PORTF_DATA_R^= 0X02;
                               delay_ms(100);


                   if(FlagX==2){
                               flagD = 1;
                               GPIO_PORTF_DATA_R &=~ 0X0E;


                               FlagX=0;
                              break;
                           }
                           if(FlagF==1){
                                GPIO_PORTF_DATA_R &=~ 0X0E;
                                GPIO_PORTF_DATA_R|= 0X0E;
                                FlagF=0;
                                FlagX=0;

                           break;
                           }

                       }
          }

        if(flagD==1){flagD=0; FlagH=1;FlagF=0;return; }
        delay_ms(50);

       }
        s--;

        }
    fini_stopwatch();

}


void displayTime_s(int s){
    lcd_command(0xC0);
        LCD_printInt(s);
        //lcd_data(' ');
        LCD_String(" Remaining");
}


void displayTime(int m,int s) // POSITIONING
{

  lcd_command(0x0c);
    lcd_command(0xC0);
  LCD_printInt(m);
  lcd_data(':');

    if(s<10){lcd_data('0');}
    LCD_printInt(s);
    lcd_data(' ');
}

void fini_stopwatch(void)
{
      GPIO_PORTF_DATA_R&=~ 0X0E;
    GPIO_PORTF_DATA_R|= 0X0E;
    delay_ms(200);
    lcd_command(0x01);
        lcd_command(0x80);
    LCD_String("Done !");
    for(int i=0;i<3;i++){
    GPIO_PORTD_DATA_R |= 0x08;
    delay_ms(600);
        GPIO_PORTD_DATA_R &= ~0x08;
        delay_ms(200);

    }

     GPIO_PORTF_DATA_R&=~ 0X0E;
        lcd_command(0x0e);
        FlagH=1;

//    getStarted();

}
