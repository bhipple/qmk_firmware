#!/usr/bin/env nix-shell
#!nix-shell -i zsh
set -euxo pipefail

nix-shell -p qmk --run 'make git-submodules'

./bhipple/regen.py charybdis | tee keyboards/bastardkb/charybdis/4x6/keymaps/bhipple/generated.h
./bhipple/regen.py scylla    | tee keyboards/bastardkb/scylla/keymaps/bhipple/generated.h
./bhipple/regen.py voyager   | tee keyboards/zsa/voyager/keymaps/bhipple/generated.h

nix-shell --run "qmk compile -km bhipple -kb bastardkb/charybdis/4x6/v1/elitec" &
nix-shell --run "qmk compile -km bhipple -kb bastardkb/scylla/v1/elitec" &
nix-shell --run "qmk compile -km bhipple -kb zsa/voyager" &
nix-shell --run "qmk compile -km default -kb keychron/v8/ansi_encoder" &

km=bhipple
#if hwinfo | grep -i "Keychron V8"; then kb=keychron/v8/ansi_encoder; km=default; fi
#if hwinfo | grep -i Scylla; then kb=bastardkb/scylla/v1/elitec; fi
#if hwinfo | grep -i Charybdis; then kb=bastardkb/charybdis/4x6/v1/elitec; fi
if hwinfo | grep -i Voyager; then kb=zsa/voyager; fi

wait

fname=$(echo $kb | sed 's|/|_|g')_$km
if [ -e "$fname.bin" ]; then
    fname="$fname.bin"
elif [ -e "$fname.hex" ]; then
    fname="$fname.hex"
else
    echo "Failed to find fname" && exit 1
fi

echo Flashing km=$km kb=$kb with fname=$fname
nix-shell --run "make ${kb}:${km}:flash"  # This works for Voyager, no sudo!
