AUTO_SHIFT_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes

# Slimming down firmware size
RGB_MATRIX_ENABLE = no

generated.h: regen.py keymap.org
	./regen.py charybdis
