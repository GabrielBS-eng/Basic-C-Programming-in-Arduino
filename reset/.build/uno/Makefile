


















.build/uno/src/main.o : src/main.c
	@echo [93msrc/main.c[0m
	@mkdir -p .build/uno/src
	@/usr/share/arduino/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=105 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard   -o $@ -c src/main.c
include .build/uno/src/main.d















.build/uno/firmware.elf : .build/uno/src/main.o
	@echo [92mLinking firmware.elf[0m
	@/usr/share/arduino/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -Wl,-Os -Wl,--gc-sections -o $@ $^ -lm


.build/uno/firmware.hex : .build/uno/firmware.elf
	@echo [92mConverting to firmware.hex[0m
	@/usr/share/arduino/hardware/tools/avr/bin/avr-objcopy -O ihex -R .eeprom $^ $@

include .build/uno/src/dependencies.d

all : .build/uno/firmware.hex
	@true

