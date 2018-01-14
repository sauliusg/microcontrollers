#! /bin/sh

# The dongle that works is FT232 based. The same dongle also works with 'uisp'.

sudo avrdude -p m8 -C +dasa2inv-avrdude.conf -c dasa2inv -P /dev/ttyUSB0 -U lfuse:r:-:h
