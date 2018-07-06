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

.PHONY: all clean distclean cleanAll

all: ${HEX_FILES}

%.hex : %.out 
	$(OBJCOPY) -R .eeprom -O ihex $< $@ 

%.out : %.o 
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $< 

define AVRLOAD
	sudo avrdude \
		-V -p t2313 \
		-C +dasa2inv-avrdude.conf \
		-c dasa2inv \
		-P ${PORT}
endef

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

.PHONY: lsfuses lsfuse refuse wrfuse wrfuses

# List fuse bits:

lsfuses lsfuse:
	${AVRLOAD} -U lfuse:r:-:h

# Restore original fuses:

refuse:
	${AVRLOAD} -U lfuse:w:0x64:m
	${AVRLOAD} -U hfuse:w:0xDF:m
	${AVRLOAD} -U efuse:w:0xFF:m

# Write fuse bytes needed for this project:

LFUSE = lfuses.txt

wrfuse wrfuses: ${LFUSE}
	${AVRLOAD} -U lfuse:w:$(shell grep -v '^#' $<):m

# Load HEX file to the AVR controller; erase the AVR before it is
# programmed if necessary:

.PHONY: load upload rdflash

upload load: ${HEX_FILES}
	${AVRLOAD} -U flash:w:$<

rdflash:
	${AVRLOAD} -U flash:r:-:i

clean:
	rm -f ${O_FILES} ${MAP_FILES} ${OUT_FILES}

distclean cleanAll: clean
	rm -f ${HEX_FILES}
