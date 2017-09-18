/* Lab 2 Multiple Blink
 * MSP430FR5994
 * 9/18/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;  // adjust power settings

    /* GPIO INIT*/
    P1SEL0 &= ~(BIT0|BIT1);          // sets port mux
    P1SEL1 &= ~(BIT0|BIT1);          // sets port mux
    P1DIR |= BIT0|BIT1;            // Sets P1.0 and P1.1 as an output


        /* LED FLASHING*/
        while(1){
            _delay_cycles(250000);   //waits 250,000 clk cycles
            P1OUT &= ~BIT1;   // Sets P1.1 low

            _delay_cycles(250000);   //waits 250,000 clk cycles
            P1OUT |=BIT0; // Sets P1.0 High
            P1OUT |=BIT1; // Sets P1.1 High

            _delay_cycles(250000);   //waits 250,000 clk cycles
            P1OUT &= ~BIT1;   // Sets P1.1 low

            _delay_cycles(250000);   //waits 250,000 clk cycles
            P1OUT &= ~BIT0;   // Sets P1.0 low
            P1OUT |=BIT1; // Sets P1.1 High
        }
}
