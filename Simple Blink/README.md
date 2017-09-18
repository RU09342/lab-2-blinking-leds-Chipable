# Simple Blink
## description
Applicable for code written for the following dev boards:
* FR5994
* FR2311
* F5529

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