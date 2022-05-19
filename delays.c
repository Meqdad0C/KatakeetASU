#include "delays.h"

void systick_wait_1ms(){
    NVIC_ST_CTRL_R=0x00;
    NVIC_ST_RELOAD_R=16000-1;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0x05;
    while((NVIC_ST_CTRL_R&0x00010000)==0){}
    NVIC_ST_CTRL_R = 0; //disabling the timer
}

void systick_wait_1us(){
    NVIC_ST_CTRL_R=0x00;
    NVIC_ST_RELOAD_R=16-1;
    NVIC_ST_CURRENT_R=0;
    NVIC_ST_CTRL_R=0x05;
    while((NVIC_ST_CTRL_R&0x00010000)==0){}
    NVIC_ST_CTRL_R = 0; //disabling the timer
}

void delay_ms(uint32_t time){
    uint32_t i;
    for(i=0;i<time;i++){
    systick_wait_1ms();
    }
}

void delay_us(uint32_t time){
    uint32_t i;
    for(i=0;i<time;i++){
    systick_wait_1us();
    }
}
