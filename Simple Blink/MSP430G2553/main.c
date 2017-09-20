/* Lab 2 Simple Blink
 * MSP430G2553
 * 9/20/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* INIT GPIO*/
    P1DIR |= BIT0;      // sets P1.0 to output
    P1SEL &= ~BIT0;     //sets P1.0 mux

    /* LED FLASHING*/
    while(1){
        _delay_cycles(500000);   //waits 500,000 clk cycles
        P1OUT |= BIT0; // Sets P1.0 High

        _delay_cycles(500000);   //waits 500,000 clk cycles
        P1OUT &= ~BIT0;   // Sets P1.0 low
    }
}
