#include "prototype.h"

int k=0;
int FlagH=0;
int FlagF=0;
char state=0;
int flagD=0;
int FlagX=0;
//int secondsPerKilo=0;
char inputs[4]={'0'};
//int sD=0;
//int mD=0;



int main()
{

    lcd_init ();
    keypad_Init();
    portf_init();
    portd_init();
    porta_init();

    while(1){
        getStarted();
        while(FlagH==0){}
        FlagH=0;
    }
}
