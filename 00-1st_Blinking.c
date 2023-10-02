#include "lm4f120h5qr.h"

// my_first_blinking_program

void delay (void);
int main()
{
  // Clock gate for PORT F
    SYSCTL_RCGCGPIO_R = (1<<5);
  // Digital enable for RGB LEDs
    GPIO_PORTF_DEN_R = (1<<1);
  // enable Direction as output
    GPIO_PORTF_DIR_R = (1<<1);

    
    while (1)
    {
      // Write output Data 
      GPIO_PORTF_DATA_R |= (1<<1);  //SET
      delay();
      GPIO_PORTF_DATA_R &= ~(1<<1);  //CLEAR
      delay();
    }
}

void delay (void){
  volatile unsigned int counter =0;
  while (counter < 1000000)
    counter++ ;
}
