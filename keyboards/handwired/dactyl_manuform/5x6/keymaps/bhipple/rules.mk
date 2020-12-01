BOOTLOADER = atmel-dfu

generated.h: regen.py keymap.org
	./regen.py
