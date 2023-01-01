#!/usr/bin/env nix-shell
#!nix-shell -p hwinfo -i zsh
set -euxo pipefail

make git-submodule

./keyboards/bastardkb/charybdis/4x6/keymaps/bhipple/regen.py charybdis
./keyboards/bastardkb/scylla/keymaps/bhipple/regen.py scylla

if echo "$1 $(hwinfo)" | grep -i Scylla; then nix-shell --run 'qmk flash -km bhipple -kb bastardkb/scylla/v1/elitec'; fi
if echo "$1 $(hwinfo)" | grep -i Charybdis; then nix-shell --run 'qmk flash -km bhipple -kb bastardkb/charybdis/4x6/v1/elitec'; fi

#nix-shell --run 'qmk flash -km bhipple -kb handwired/dactyl_manuform/5x6'
