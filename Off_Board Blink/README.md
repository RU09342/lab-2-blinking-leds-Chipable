# Off Board Blink
This portion of the lab 2 was to see if I could get the msp 430 to run off of the development board this was accomplished with the G2553 while running the multiple blink program from another seciton of the lab.

![alt text](https://github.com/RU09342/lab-2-blinking-leds-Chipable/blob/master/Off_Board%20Blink/off%20board%20blink.jpg)
Both leds blinkiing
## Steps taken
* Programming was taken care of on the development board. After the chip was programed it was taken off the development board and put into the bread board.
* After that power and ground connections were made with a decoupling capacitor added. Power and ground were taken from the pins of the development board
* A pull-up resistor was added to the reset pin so that the microcontroller would not reset inadvertantly.
* Finally leds with series resistors were added to the two output pins configured in the program

All of these steps ended with the G2553 working succesfully on a bread board
