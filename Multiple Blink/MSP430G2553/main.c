/* Lab 2 Multiple Blink
 * MSP430G2553
 * 9/20/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* GPIO INIT*/
    P1DIR |= BIT0;          //sets P1.0 as output
    P1DIR |= BIT6;          //sets P1.6 as output
    P1SEL &= ~BIT0;         //sets P1.0 mux for gpio
    P1SEL &= ~BIT6;         //sets P1.6 mux for gpio

    /* LED FLASHING*/
    while(1){
        _delay_cycles(250000);   //waits 250,000 clk cycles
        P1OUT &= ~BIT6;   // Sets P1.6 low

        _delay_cycles(250000);   //waits 250,000 clk cycles
        P1OUT |=BIT0|BIT6; // Sets P1.0 and P1.6 High

        _delay_cycles(250000);   //waits 250,000 clk cycles
        P1OUT &= ~BIT6;   // Sets P1.6 low

        _delay_cycles(250000);   //waits 250,000 clk cycles
        P1OUT &= ~BIT0;   // Sets P1.0 low
        P1OUT |=BIT6; // Sets P1.6 High
    }
}
