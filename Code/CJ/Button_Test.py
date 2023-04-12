# This file follows the guide on https://learn.sparkfun.com/tutorials/raspberry-gpio/all
# We want to test the basic IO of a Raspberry Pi using Raspbian and VS code

# Import Libraries
import RPi.GPIO as GPIO
import time

# Pinout Definition
GPIO.setmode(GPIO.BCM)
GPIO.setup(4, GPIO.IN)

# Process
# We want the code to loop this so that it is always checking if the button is pressed (connected to ground)
while(1):
    #If the button is pressed, (GPIO.input(4)) should read as "0" since it will be connected to ground through the button
    if not GPIO.input(4):
        print("Button 1 is pressed.")
        #Delay for 3 seconds
        time.sleep(3)