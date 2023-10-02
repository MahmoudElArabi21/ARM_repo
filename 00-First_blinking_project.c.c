#include "lm4f120h5qr.h"

// my_first_blinking_program

unsigned int coun =0;
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
      coun = 0;
      while (coun < 1000000)
      {
        coun++;
      }
      GPIO_PORTF_DATA_R &= ~(1<<1);  //CLEAR
      while (coun < 1000000)
      {
        coun++;
      }
    }
}
