MCU=atmega328
CC=avr-gcc
CPP=avr-g++
OBJCOPY=avr-objcopy
INC=-I ../libraries/RFID -I /usr/share/arduino/hardware/arduino/cores/arduino -I /usr/share/arduino/hardware/arduino/variants/standard -I /usr/share/arduino/libraries/SPI -I /usr/share/arduino/libraries/Wire
# optimize for size:
CPPFLAGS=-g -mmcu=$(MCU) -mcall-prologues -Os -fno-exceptions -ffunction-sections -fdata-sections -DARDUINO=105 -DF_CPU=16000000L ${INC}
CFLAGS=${CPPFLAGS} -Wstrict-prototypes

ARDUINO_DIR = /usr/share/arduino/hardware/arduino/cores/arduino /usr/share/arduino/libraries/SPI
ARDUINO_CPP = $(wildcard $(addsuffix /*.cpp,${ARDUINO_DIR}))
ARDUINO_C   = $(wildcard $(addsuffix /*.c,${ARDUINO_DIR}))
ARDUINO_OBJ = $(notdir ${ARDUINO_CPP:%.cpp=%.o}) $(notdir ${ARDUINO_C:%.c=%.o})

LIB_DIR  = ../libraries
LIB_CPP  = $(filter-out ${LIB_DIR}/RC522/%,$(shell find ${LIB_DIR} -name '*.cpp'))
LIB_OBJ  = $(notdir ${LIB_CPP:%.cpp=%.o})
LIB_DIRS = $(sort $(dir ${LIB_CPP}))

vpath %.cpp ${LIB_DIRS} ${ARDUINO_DIR}
vpath %.c ${ARDUINO_DIR}

C_FILES   = ${wildcard *.ino}
HEX_FILES = ${C_FILES:%.ino=%.hex}
OBJ_FILES = ${C_FILES:%.ino=%.o} ${CPP_OBJ}

.PHONY: all clean distclean cleanAll upload

all: ${HEX_FILES}

.PHONY: display

display:
	echo ${LIB_CPP}

%.hex : %.out
	$(OBJCOPY) -R .eeprom -O ihex $< $@

%.out : %.o  | libarduino.a liblocal.a
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $^ -x none libarduino.a liblocal.a

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o : %.ino
	$(CPP) $(CPPFLAGS) -o $@ -c -x c++ -include Arduino.h $<

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c -x c++ -include Arduino.h $<

libarduino.a: ${ARDUINO_OBJ}
	ar r $@ $^

liblocal.a: ${LIB_OBJ}
	ar r $@ $^

upload:
	avrdude -c arduino -p atmega328p -P /dev/ttyUSB3 -b57600 -U flash:w:${HEX_FILES}

clean:
	rm -f ${OBJ_FILES}
	rm -f ${LIB_OBJ}
	rm -f ${ARDUINO_OBJ}

distclean cleanAll: clean
	rm -f ${HEX_FILES}
	rm -f libarduino.a
	rm -f liblocal.a

