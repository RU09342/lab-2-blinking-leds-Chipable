/* Lab 2 Button LED Toggle
 * MSP430FR2311
 * 9/12/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void){

int state = 1;      // tracks the button press

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // adjust power settings

    /* GPIO INIT*/
    P1SEL0 &= ~(1<<0);       // sets port mux
    P1SEL1 &= ~(1<<0);       // sets port mux
    P1DIR |= (1<<0);    // Sets P1.0 as an output
    P1DIR &= ~(1<<1);   // sETS P1.1 as an input
    P1REN |= (1<<1);    // Enables pull up resistor on P1.1
    P1OUT |= (1<<1);    // Sets pull up to VCC

        /* Button Enabled LED*/
        while(1){
            if((~P1IN & (1<<1))&&state){        //executes only once per button press
                P1OUT ^=(1<<0);                 // Toggles P1.0
                state = 0;                      //stops if from executing until button is released
            }
            else if(P1IN & (1<<1))
                state = 1;                      // resets state
        }
}
