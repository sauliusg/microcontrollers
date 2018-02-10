MCU=atmega328
CC=avr-gcc
CPP=avr-g++
OBJCOPY=avr-objcopy
INC=-I ../libraries/RFID -I /usr/share/arduino/hardware/arduino/cores/arduino -I /usr/share/arduino/hardware/arduino/variants/mega -I /usr/share/arduino/libraries/SPI
# optimize for size:
CPPFLAGS=-g -mmcu=$(MCU) -mcall-prologues -Os -fno-exceptions -ffunction-sections -fdata-sections -DARDUINO=105 -DF_CPU=16000000L ${INC}
CFLAGS=${CPPFLAGS} -Wstrict-prototypes

ARDUINO_DIR = /usr/share/arduino/hardware/arduino/cores/arduino
ARDUINO_CPP = $(wildcard ${ARDUINO_DIR}/*.cpp)
ARDUINO_OBJ = ${ARDUINO_CPP:${ARDUINO_DIR}/%.cpp=%.o}

C_FILES   = ${wildcard *.ino}
HEX_FILES = ${C_FILES:%.ino=%.hex}
OBJ_FILES = ${C_FILES:%.ino=%.o}

.PHONY: all clean distclean cleanAll

all: ${HEX_FILES}

%.hex : %.out
	$(OBJCOPY) -R .eeprom -O ihex $< $@

%.out : %.o libarduino.a
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $< -x none libarduino.a

%.o : %.c
	$(CC) $(CFLAGS) -c -x c++ $<

%.o : %.ino
	$(CPP) $(CPPFLAGS) -c -x c++ -include Arduino.h $<

%.o : ${ARDUINO_DIR}/%.cpp
	$(CPP) $(CPPFLAGS) -c -x c++ -include Arduino.h $<

libarduino.a: ${ARDUINO_OBJ}
	ar r $@ $^

clean:
	rm -f ${OBJ_FILES}
	rm -f ${ARDUINO_OBJ}

distclean cleanAll: clean
	rm -f ${HEX_FILES}
	rm -f libarduino.a

