/* Lab 2 Simple Blink
 * MSP430FR6989
 * 9/20/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 



int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // adjust power settings

    /* INIT GPIO*/
    P1DIR |= BIT0;      // sets P1.0 to output
    P1SEL0 &= ~BIT0;     //sets P1.0 mux sel bit 0
    P1SEL1 &= ~BIT0;     //sets P1.0 mux sel bit 1

    /* LED FLASHING*/
    while(1){
        _delay_cycles(500000);   //waits 500,000 clk cycles
        P1OUT |= BIT0; // Sets P1.0 High

        _delay_cycles(500000);   //waits 500,000 clk cycles
        P1OUT &= ~BIT0;   // Sets P1.0 low
    }
}
