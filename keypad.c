#include "keypad.h"



/* Array of 4x4 to define characters which will be printe on specific key pressed */
unsigned  char keymap[4][4] = {{ '1', '2', '3', 'A'},
                               { '4', '5', '6', 'B'},
                               { '7', '8', '9', 'C'},
                               { '*', '0', '#', 'D'}};


void keypad_Init(void)
{
	SYSCTL_RCGCGPIO_R |= 0x14;            //enable clock for port C , E
	while ((SYSCTL_RCGCGPIO_R&0x14)==0);  //wait for clock to be enabled
	GPIO_PORTC_LOCK_R=0x4C4F434B;
	GPIO_PORTC_CR_R  |= 0xF0;           //allow changes to all the bits in port C
	GPIO_PORTC_DIR_R |= 0xF0;            //set directions col are o/p PORT C4-7
	GPIO_PORTC_DEN_R |= 0xF0;             //digital enable pins in port C
	GPIO_PORTC_PCTL_R &= ~0xFFFF0000;
	GPIO_PORTC_PDR_R |= 0xF0;                           //pull up resistor to output 0 when not pressed

	GPIO_PORTE_CR_R  |= 0x1E;           //allow changes to all the bits in port E
	GPIO_PORTE_DIR_R |= 0x00;             //set directions row are i/p PORT E1-4
	GPIO_PORTE_DEN_R |= 0x1E;             //digital enable pins in port E
	GPIO_PORTE_PCTL_R &= ~0x000FFFF0;
	//GPIO_PORTE_ODR_R |= 0x1E;             //open drain to prevent damage when 2 keys pressed
}

char keypad_getkey(void)
{
  while(1)
  {

    for(int i = 0; i < 4; i++)                        //columns traverse
    {
      GPIO_PORTC_DATA_R = (1U << (i+4));
      delay_ms(10);
      for(int j = 0; j < 4; j++)                     //rows traverse
      {
        if((GPIO_PORTE_DATA_R & 0x1E) & (1U << (j+1)))
          return keymap[j][i];
      }
    }
  }
}
