#!/usr/bin/env nix-shell
#!nix-shell -i zsh
set -euxo pipefail

nix-shell -p qmk --run 'make git-submodules'

./bhipple/regen.py charybdis | tee keyboards/bastardkb/charybdis/4x6/keymaps/bhipple/generated.h
./bhipple/regen.py scylla | tee keyboards/bastardkb/scylla/keymaps/bhipple/generated.h

if hwinfo | grep -i Scylla; then kb=bastardkb/scylla/v1/elitec; fi
if hwinfo | grep -i Charybdis; then kb=bastardkb/charybdis/4x6/v1/elitec; fi

nix-shell --run "qmk compile -km bhipple -kb $kb -t out.hex"
nix-shell --run "sudo qmk flash out.hex"  # TODO: fix the nixos udev rules and drop sudo
