# Multiple Blink
## description
Applicable for code written for the following dev boards:
* FR5994
* FR2311
* F5529
* G2553
* FR6989

The code blinks two of the onboard leds at a different rates. 
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
Finally all the source files have an infinite while loop. Inside the loop there is code that sets the output pin high and then low with a delay inbetween. This controls the flashing lights and is how one light is made to flash faster than the other.

## Differences
The main difference between all the source files is that the FR boards contain another line of code "PM5CTL0 &= ~LOCKLPM5;" that adjust the power settings allowing the P1 registers to be configured