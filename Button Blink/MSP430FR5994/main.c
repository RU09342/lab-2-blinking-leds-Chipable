/* Lab 2 Button LED Toggle
 * MSP430FR5994
 * 9/18/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void){

int state = 1;      // tracks the button press

	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // adjust power settings

    /* GPIO INIT*/
    P1SEL0 &= ~BIT0;       // sets port mux
    P1SEL1 &= ~BIT0;       // sets port mux
    P5SEL0 &= ~BIT6;       // sets port mux
    P5SEL1 &= ~BIT6;       // sets port mux
    P1DIR |= (1<<0);    // Sets P1.0 as an output
    P5DIR &= ~BIT6;   // sETS P5.6 as an input
    P5REN |= BIT6;    // Enables pull up resistor on P1.1
    P5OUT |= BIT6;    // Sets pull up to VCC

        /* Button Enabled LED*/
        while(1){
            if((~P5IN & BIT6)&&state){        //executes only once per button press
                P1OUT ^= BIT0;                 // Toggles P1.0
                state = 0;                      //stops if from executing until button is released
            }
            else if(P1IN & BIT6)
                state = 1;                      // resets state
        }
}
