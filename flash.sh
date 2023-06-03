#!/usr/bin/env nix-shell
#!nix-shell -i zsh
set -euxo pipefail

nix-shell -p qmk --run 'make git-submodules'

./keyboards/bastardkb/charybdis/4x6/keymaps/bhipple/regen.py charybdis
./keyboards/bastardkb/scylla/keymaps/bhipple/regen.py scylla

# TODO: fix the nixos udev rules and drop sudo
if hwinfo | grep -i Scylla; then nix-shell --run 'sudo qmk flash -km bhipple -kb bastardkb/scylla/v1/elitec'; fi
if hwinfo | grep -i Charybdis; then nix-shell --run 'sudo qmk flash -km bhipple -kb bastardkb/charybdis/4x6/v1/elitec'; fi
