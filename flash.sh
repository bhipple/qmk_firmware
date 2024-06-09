#!/usr/bin/env nix-shell
#!nix-shell -i zsh
set -euxo pipefail

nix-shell -p qmk --run 'make git-submodules'

./bhipple/regen.py charybdis | tee keyboards/bastardkb/charybdis/4x6/keymaps/bhipple/generated.h
./bhipple/regen.py scylla    | tee keyboards/bastardkb/scylla/keymaps/bhipple/generated.h
./bhipple/regen.py voyager   | tee keyboards/zsa/voyager/keymaps/bhipple/generated.h

km=bhipple
#if hwinfo | grep -i "Keychron V8"; then kb=keychron/v8/ansi_encoder; km=default; fi
#if hwinfo | grep -i Scylla; then kb=bastardkb/scylla/v1/elitec; fi
#if hwinfo | grep -i Charybdis; then kb=bastardkb/charybdis/4x6/v1/elitec; fi
if hwinfo | grep -i Voyager; then kb=zsa/voyager; fi

nix-shell --run "qmk compile -km $km -kb $kb"

bin=$(echo $kb | sed 's|/|_|g')_$km

echo "Flashing km=$km kb=$kb with $bin"
nix-shell --run "sudo qmk flash $bin*"  # TODO: fix the nixos udev rules and drop sudo
