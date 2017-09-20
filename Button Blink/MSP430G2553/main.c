/* Lab 2 Button LED Toggle
 * MSP430G2553
 * 9/20/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int state = 1;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* INIT GPIO*/
    P1DIR |= BIT0;              // sets P1.0 to output
    P1DIR &= ~BIT3;             // sets P1.3 to input
    P1SEL &= ~(BIT0|BIT3);      // sets P1.0 and P1.3 mux
    P1REN |= BIT3;              // Enables P1.3 resistor
    P1OUT |= BIT3;              // configures P1.3 resistor as pull-up

    /* Button Enabled LED*/
    while(1){
        if((~P1IN & BIT3)&&state){          //enters on button press and state == 1
            P1OUT ^= BIT0;                  // Toggles P1.0
            state = 0;                      // prevents re-entry before button is released
        }
        else if(P1IN & (1<<3))              // enters on button released
            state = 1;                      // resets state
    }
}
