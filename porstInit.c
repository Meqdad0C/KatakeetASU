#include "portsInit.h"

void portf_init(){

    SYSCTL_RCGCGPIO_R |= 0x20;
    while((SYSCTL_PRGPIO_R &0x20)==0) ;
    GPIO_PORTF_LOCK_R=0x4C4F434B;
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DIR_R &= ~0x11;
    GPIO_PORTF_DEN_R |=0x1F;
    GPIO_PORTF_CR_R |=0x1F;
    GPIO_PORTF_AMSEL_R &= ~0x1F;
    GPIO_PORTF_PCTL_R &= ~0x000FFFFF;
    GPIO_PORTF_AFSEL_R &=~0x1F;
    GPIO_PORTF_PUR_R |=0x10;
    GPIO_PORTF_PUR_R |=0x01;

    //INTERRUPT
    //negative edge triggered (falling ) configuration
    GPIO_PORTF_IS_R &= ~0x11;
    GPIO_PORTF_IBE_R &= ~0x11;
    GPIO_PORTF_IEV_R &= ~0x11;
    GPIO_PORTF_ICR_R &= ~0x11;

    GPIO_PORTF_IM_R |= 0x11;

    NVIC_EN0_R = (1 << 30);

    NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000 ;



    }
void portd_init(){

    SYSCTL_RCGCGPIO_R |= 0x08;
    while((SYSCTL_PRGPIO_R &0x08)==0) ;
    GPIO_PORTD_LOCK_R=0x4C4F434B;

    GPIO_PORTD_DIR_R &= ~0x04;
        GPIO_PORTD_DIR_R |= 0x08;
    GPIO_PORTD_DEN_R |=0x0C;
    GPIO_PORTD_CR_R |=0x0C;
    GPIO_PORTD_AMSEL_R &= ~0x0C;
    GPIO_PORTD_PCTL_R &= ~0x0000FF00;
    GPIO_PORTD_AFSEL_R &=~0x0C;
    GPIO_PORTD_PDR_R |=0x04;


    //INTERRUPT
    //negative edge triggered (falling ) configuration
    GPIO_PORTD_IS_R &= ~0x04;
    GPIO_PORTD_IBE_R &= ~0x04;
    GPIO_PORTD_IEV_R &= ~0x04;
    GPIO_PORTD_ICR_R &= ~0x04;

    GPIO_PORTD_IM_R |= 0x04;

    NVIC_EN0_R = (1 << 3);

    NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0x80000000 ;


    }
void porta_init(){


    GPIO_PORTA_DIR_R &= ~0x04;
    GPIO_PORTA_DEN_R |=0x04;
    GPIO_PORTA_CR_R |=0x04;
    GPIO_PORTA_AMSEL_R &= ~0x04;
    GPIO_PORTA_PCTL_R &= ~0x00000F00;
    GPIO_PORTA_AFSEL_R &=~0x04;
    GPIO_PORTA_PDR_R |=0x04;


    //INTERRUPT
    //negative edge triggered (falling ) configuration
    GPIO_PORTA_IS_R &= ~0x04;
    GPIO_PORTA_IBE_R &= ~0x04;
    //GPIO_PORTA_IEV_R &= ~0x04; falling
        GPIO_PORTA_IEV_R |= 0x04; //rising
    GPIO_PORTA_ICR_R &= ~0x04;

    GPIO_PORTA_IM_R |= 0x04;

    NVIC_EN0_R = (1 << 0);

    NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFFFF00)|0x00000040 ;
 }
