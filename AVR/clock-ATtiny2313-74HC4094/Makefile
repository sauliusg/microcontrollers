MCU=attiny2313
PORT=/dev/ttyUSB0

CC=avr-gcc
OBJCOPY=avr-objcopy
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -mcall-prologues

C_FILES   = ${wildcard *.c}
O_FILES   = ${C_FILES:%.c=%.o}
MAP_FILES = ${C_FILES:%.c=%.map}
OUT_FILES = ${C_FILES:%.c=%.out}
HEX_FILES = ${C_FILES:%.c=%.hex}

.PHONY: all clean distclean cleanAll upload load

all: ${HEX_FILES}

%.hex : %.out 
	$(OBJCOPY) -R .eeprom -O ihex $< $@ 

%.out : %.o 
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $< 

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

# erase the AVR before it is programmed
upload load: ${HEX_FILES}
	sudo avrdude \
		-V -p t2313 \
		-C +dasa2inv-avrdude.conf \
		-c dasa2inv \
		-P ${PORT} \
		-U flash:w:$<

clean:
	rm -f ${O_FILES} ${MAP_FILES} ${OUT_FILES}

distclean cleanAll: clean
	rm -f ${HEX_FILES}
