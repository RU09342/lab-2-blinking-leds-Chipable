# Simple Blink
## description
Applicable for code written for the following dev boards:
* FR5994
* FR2311
* F5529
* G2553
* FR6989

The code blinks one of the onboard leds at a constant rate. 
## Similarities 
All of the files go through three main sections
* Turn off watchdog timer
* INIT GPIO
* Loop

### Turn Off Watchdog Timer
All of the source files contain the code "WDTCTL = WDTPW | WDTHOLD;", which stops the watchdog timer

### INIT GPIO
All of the source files contain some kind of GPIO initialzation. They all consist of setting the port direction and setting the port muxes. The only changes between dev boards are on the pins configured

### Loop
Finally all the source files have an infinite while loop. Inside the loop there is code that sets the output pin high and then low with a delay inbetween. This controls the flashing light.

## Differences
One of the main differences is that the FR boards require and extra line of code "PM5CTL0 &= ~LOCKLPM5;" to adjust the power settings in order to be able to adjust the P1 registers