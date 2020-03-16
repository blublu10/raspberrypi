#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 08:55:04 2018

@author: kaniska
"""

import RPi.GPIO as GPIO
import time
import argparse

all_pins = [11, 12, 13, 15, 16, 18, 22, 3, 5, 24]

def setup(ledPin):
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(ledPin, GPIO.OUT)
    GPIO.output(ledPin, GPIO.LOW)
    
        
        
def destroy(ledPin):
    GPIO.output(ledPin, GPIO.LOW)
    GPIO.cleanup()
    print('Cleaned up pin {}'.format(ledPin))
    
    
if __name__ == '__main__':
    for pin in all_pins:
        setup(pin)
        destroy(pin)
