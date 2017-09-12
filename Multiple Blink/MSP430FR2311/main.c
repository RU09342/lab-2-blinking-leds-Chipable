/* Lab 2 Multiple Blink
 * MSP430FR2311
 * 9/11/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // adjust power settings

    /* GPIO INIT*/
    P1SEL0 &= ~(1<<0);       // sets port mux
    P1SEL1 &= ~(1<<0);       // sets port mux
    P1DIR |= (1<<0);    // Sets P1.0 as an output
    P2SEL0 &= ~(1<<0);       // sets port mux
    P2SEL1 &= ~(1<<0);       // sets port mux
    P2DIR |= (1<<0);    // Sets P2.0 as an output

        /* LED FLASHING*/
        while(1){
            _delay_cycles(250000);   //waits 250,000 clk cycles
            P2OUT &= ~(1<<0);   // Sets P2.0 low

            _delay_cycles(250000);   //waits 250,000 clk cycles
            P1OUT |=(1<<0); // Sets P1.0 High
            P2OUT |=(1<<0); // Sets P2.0 High

            _delay_cycles(250000);   //waits 250,000 clk cycles
            P2OUT &= ~(1<<0);   // Sets P2.0 low

            _delay_cycles(250000);   //waits 250,000 clk cycles
            P1OUT &= ~(1<<0);   // Sets P1.0 low
            P2OUT |=(1<<0); // Sets P2.0 High
        }
}
