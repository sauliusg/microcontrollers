
MCU=attiny25
PART=t25
PORT=/dev/ttyUSB0
PROG=dasa2inv

CC=avr-gcc
OBJCOPY=avr-objcopy
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -mcall-prologues

C_FILES   = $(sort ${wildcard *.c})
HEX_FILES = ${C_FILES:%.c=%.hex}

.PHONY: all clean distclean

all: ${HEX_FILES}

%.hex : %.out 
	$(OBJCOPY) -R .eeprom -O ihex $< $@ 

%.out : %.o 
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $< 

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

.PHONY: upload read

# erase the AVR before it is programmed
upload: ${HEX_FILES}
	sudo avrdude -V \
		-p ${PART} \
		-C +dasa2inv-avrdude.conf \
		-c ${PROG} -P ${PORT} \
		-U flash:w:$<
read:
	sudo avrdude \
		-p ${PART} \
		-C +dasa2inv-avrdude.conf \
		-c ${PROG} -P ${PORT} \
		-U flash:r:-:i

clean:
	rm -f *.o *.map *.out *.hex

distclean: clean
