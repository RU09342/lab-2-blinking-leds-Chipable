/* Lab 2 Button LED Toggle
 * MSP430F5529
 * 9/18/2017
 * Robert Page
 * main.c
 */

#include <msp430.h> 

int state = 1;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer

    /* INIT GPIO*/
    P1DIR |= BIT0;
    P1DIR &= ~BIT1;
    P1SEL &= ~(BIT0|BIT1);
    P1REN |= BIT1;
    P1OUT |= BIT1;
	
	/* Button Enabled LED*/
    while(1){
        if((~P1IN & BIT1)&&state){
            P1OUT ^= BIT0; // Toggles P1.0
            state = 0;
        }
        else if(P1IN & (1<<1))
            state = 1;
    }
}
