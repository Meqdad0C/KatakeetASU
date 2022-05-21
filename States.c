#include "States.h"



void popcorn(void){
    state = 'A';
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Popcorn mode");
    delay_ms(1000);
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Press SW1 to ");
    lcd_command(0xC0);
    LCD_String("start cooking");
    while(FlagF==0){}
    FlagF=0;
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Popcorn");
    stopwatch(1,0);



}

void Beef(void){
    state='B';
    int secondsPerKilo;
    delay_ms(200);
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Beef weight?");
    char key = keypad_getkey();
    //int c = key;
    if(key>48 && key<58){
        delay_ms(200);
    lcd_command(0x01);
    lcd_command(0x80);

    lcd_data(key);

    LCD_String(" Kilos");
    delay_ms(1000);
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Press SW1 to ");
    lcd_command(0xC0);
    LCD_String("start cooking");
    secondsPerKilo = (key-48)*30;
    while(FlagF==0){}

    lcd_command(0x01);
    LCD_String("Defrosting ...");
    FlagF=0;
   stopwatch_s(secondsPerKilo);


    }
    else {
    LCD_errormsg();
    Beef();
    }
}

void Chicken(void){
    state='C';
    int secondsPerKilo;
    delay_ms(200);
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Chicken weight?");
    char key = keypad_getkey();

    if(key>48 && key<58){
        delay_ms(200);
    lcd_command(0x01);
    lcd_command(0x80);

    lcd_data(key);

    LCD_String(" Kilos");
    delay_ms(1000);
    lcd_command(0x01);
    lcd_command(0x80);
    LCD_String("Press SW1 to ");
    lcd_command(0xC0);
    LCD_String("start cooking");
    secondsPerKilo = (key-48)*12;
    while(FlagF==0){}

        lcd_command(0x01);
        LCD_String("Defrosting ...");
        FlagF=0;
       stopwatch_s(secondsPerKilo);



    }
    else {
    LCD_errormsg();
    Chicken();
    }
}


void D(void){

    state = 'D';
 l1:
    lcd_command(0x0C);
    delay_ms(200);
    lcd_command(0x01);
    lcd_command(0x80);
    char inputs[4];
    LCD_String("Cooking Time?");
  int sD=0;
  int mD=0;

    lcd_command(0xC0);
    LCD_String("00:00");

    char cmds[4] ={0xc4,0xc3,0xc1,0xc0};

    for(k=0;k<4;k++){

        while(keypad_getkey()==0){
        }
        if(k==-1) k=0;
        if(FlagF==1) {
                            lcd_command(0x01);
                             LCD_String("Cooking ...");
                             FlagF=0;
                             stopwatch(mD,sD);
                             return;
        }

                char c = keypad_getkey();

                    while(c<48||c>57){

                    c = keypad_getkey();}
        inputs[k]=c;



        lcd_command(cmds[0]);
        lcd_data(inputs[k]);
        sD = (inputs[0]-48);


        if(k==1){

            lcd_command(cmds[1]);
            lcd_data(inputs[k-1]);
            sD = 10*(inputs[0]-48)+(inputs[1]-48);
        }
        if(k==2){

        lcd_command(cmds[1]);
        lcd_data(inputs[k-1]);
        lcd_command(cmds[2]);
        lcd_data(inputs[k-2]);

        sD = 10*(inputs[1]-48)+(inputs[2]-48);
        mD=(inputs[0]-48);
                }

        if(k==3){

          lcd_command(cmds[1]);
          lcd_data(inputs[k-1]);
          lcd_command(cmds[2]);
          lcd_data(inputs[k-2]);
          lcd_command(cmds[3]);
           lcd_data(inputs[k-3]);
                sD = 10*(inputs[2]-48)+(inputs[3]-48);
                mD= (inputs[0]-48)*10+(inputs[1]-48);
                    if((mD*60+sD)>1800){
                    sD=0;
                    mD=0;
                        for(int i=0;i<4;i++){
            inputs[i]='0','0','0','0';
                        }

                        lcd_command(0x01);
                        lcd_command(0x80);
                        LCD_String("Max 30 min");
                        delay_ms(1000);
                        goto l1;

                    }

                      }
        while(k==3){}

    delay_ms(500);
    }
}
