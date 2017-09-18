/* Lab 2 Multiple Blink
 * MSP430F5529
 * 9/18/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

	/* GPIO INIT*/
    P1DIR |= BIT0;          //sets P1.0 as output
    P4DIR |= BIT7;          //sets P4.7 as output
    P1SEL &= ~BIT0;         //sets P1.0 mux for gpio
    P4SEL &= ~BIT7;         //sets P4.7 mux for gpio
	
	/* LED FLASHING*/
    while(1){
        _delay_cycles(250000);   //waits 250,000 clk cycles
        P4OUT &= ~BIT7;   // Sets P2.0 low

        _delay_cycles(250000);   //waits 250,000 clk cycles
        P1OUT |=BIT0; // Sets P1.0 High
        P4OUT |=BIT7; // Sets P2.0 High

        _delay_cycles(250000);   //waits 250,000 clk cycles
        P4OUT &= ~BIT7;   // Sets P2.0 low

        _delay_cycles(250000);   //waits 250,000 clk cycles
        P1OUT &= ~BIT0;   // Sets P1.0 low
        P4OUT |=BIT7; // Sets P2.0 High
    }
}
