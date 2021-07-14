BOOTLOADER = atmel-dfu

TAP_DANCE_ENABLE = yes

generated.h: regen.py keymap.org
	./regen.py
