#!/usr/bin/env sh
set -euxo pipefail
./keyboards/handwired/dactyl_manuform/5x6/keymaps/bhipple/regen.py
./keyboards/bastardkb/scylla/keymaps/bhipple/regen.py
nix-shell --run 'qmk flash'
