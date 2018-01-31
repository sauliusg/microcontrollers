#! /bin/sh

# Baud rate (-b) and programmer (-c) settings described in:
# https://electronics.stackexchange.com/questions/104670/arduino-as-avr-programmer-with-avrdude

sudo avrdude -p m8 -c stk500v1 -b 19200 -P /dev/ttyACM0 -U flash:r:-:i
