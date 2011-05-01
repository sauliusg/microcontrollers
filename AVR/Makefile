MCU=atmega16
CC=avr-gcc
OBJCOPY=avr-objcopy
# optimize for size:
CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -mcall-prologues

C_FILES   = ${wildcard *.c}
HEX_FILES = ${C_FILES:%.c=%.hex}

all: ${HEX_FILES}

%.hex : %.out 
	$(OBJCOPY) -R .eeprom -O ihex $< $@ 

%.out : %.o 
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,$*.map $< 

%.o : %.c 
	$(CC) $(CFLAGS) -c $<

# erase the AVR before it is programmed
load: ${HEX_FILES}
	sudo uisp -dlpt=/dev/parport0 --erase  -dprog=dapa
	sudo uisp -dlpt=/dev/parport0 --upload if=$< -dprog=dapa  -v=3 --hash=32

load2: buttons.hex
	sudo uisp -dlpt=/dev/parport0 --erase  -dprog=dapa
	sudo uisp -dlpt=/dev/parport0 --upload if=$< -dprog=dapa  -v=3 --hash=32

clean:
	rm -f *.o *.map *.out *.hex
