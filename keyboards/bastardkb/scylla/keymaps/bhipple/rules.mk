AUTO_SHIFT_ENABLE = no

# Slimming down firmware size
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
RGB_MATRIX_ENABLE = no

generated.h: regen.py keymap.org
	./regen.py
