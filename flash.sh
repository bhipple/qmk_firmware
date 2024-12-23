#!/usr/bin/env nix-shell
#!nix-shell -p qmk -i zsh
set -euxo pipefail

make git-submodules

./bhipple/regen.py voyager | tee keyboards/zsa/voyager/keymaps/bhipple/generated.h

qmk compile -km default -kb keychron/v8/ansi_encoder &
qmk compile -km bhipple -kb zsa/voyager &
wait

km=bhipple ; kb=zsa/voyager
km=default ; kb=keychron/v8/ansi_encoder

fname=$(echo $kb | sed 's|/|_|g')_$km
if [ -e "$fname.bin" ]; then
    fname="$fname.bin"
elif [ -e "$fname.hex" ]; then
    fname="$fname.hex"
else
    echo "Failed to find fname" && exit 1
fi

echo Flashing km=$km kb=$kb with fname=$fname
make ${kb}:${km}:flash  # This works for Voyager, no sudo!
