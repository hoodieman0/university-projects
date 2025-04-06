<a name="readme-top"></a>

<h3 align="center"> <b><u>CSCI-3331 Digital Systems Labs</u></b> </h3> 

[[GitHub Link](https://github.com/hoodieman0/CSCI-3331-Projects)] |
 [[Author GitHub](https://github.com/hoodieman0)]

---
# Overview
This repository is a showcase of the projects done in the author's Digital Systems class in Fall 2022. It uses the Arduino Uno and related components. The Arduino 1.8.19 IDE was used to create the code files. The Graphics lab uses an online Arduino simulator whose name is unknown. Each directory has the runnable .ino files and associated hardware diagrams for the Uno. For programs with a button, a debounce checker was added due to a buggy button.

## Button Toggle
A simple program that lights up an LED if the button is pressed.

## Morse Code
Displays the morse code of a digit on every button press. Input each digit onto an array of eight ints. If all numbers were displayed, revert to the start of the array. Use the tilt switch to also revert to the start of the array.

## RGB Morse Code
The same program as Morse Code, with the exception that The dot and dash color can be changed using serial inputs. 

## EEPROM
The same program as RGB Morse Code, except that the state is stored between device shutdowns. 

## Analog
A demonstration of analog properties of the Arduino. The user can use the serial monitor to input a selection between an analog-brightness LED, printing out the joystick coordinates, and the normalized values of a light sensor. 

## Interrupts
A demonstration of interrupts on the Arduino. The interrupt function only changes the state variable. In the time sensitive area, the state is read and either inputs a number into the array, sorts one element in the arry, or prints one element in the array.

## Graphics
Creates a graphical display with a different shape in each corner. The user uses the buttons to navigate the cursor on the screen. When the cursor is over a shape, display the name of the shape in the center. 

<center>
<a href="#readme-top">[Back to Top]</a>
</center>