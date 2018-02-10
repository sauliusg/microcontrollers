MCU=atmega328
CC=avr-gcc
CPP=avr-g++
OBJCOPY=avr-objcopy
INC=-I ../libraries/RFID -I /usr/share/arduino/hardware/arduino/cores/arduino -I /usr/share/arduino/hardware/arduino/variants/mega -I /usr/share/arduino/libraries/SPI
# optimize for size:
CPPFLAGS=-g -mmcu=$(MCU) -mcall-prologues ${INC}
CFLAGS=${CPPFLAGS} -Wstrict-prototypes

C_FILES   = ${wildcard *.ino}
HEX_FILES = ${C_FILES:%.ino=%.hex}
OBJ_FILES = ${C_FILES:%.ino=%.o}

.PHONY: all clean distclean cleanAll

all: ${HEX_FILES}

%.hex : %.out
	$(OBJCOPY) -R .eeprom -O ihex $< $@

%.out : %.o
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $<

%.o : %.c
	$(CC) $(CFLAGS) -c -x c++ $<

%.o : %.ino
	$(CPP) $(CPPFLAGS) -c -x c++ $<

clean:
	rm -f ${OBJ_FILES}

distclean cleanAll: clean
	rm -f ${HEX_FILES}
