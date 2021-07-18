#!/usr/bin/env sh
./keyboards/handwired/dactyl_manuform/5x6/keymaps/bhipple/regen.py && nix-shell --run 'qmk flash'
