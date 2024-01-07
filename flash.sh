#!/usr/bin/env nix-shell
#!nix-shell -i zsh
set -euxo pipefail

nix-shell -p qmk --run 'make git-submodules'

~/git/qmk_firmware/bhipple/regen.py voyager | tee keyboards/voyager/keymaps/bhipple/generated.h

nix-shell --run "qmk compile -km bhipple -kb voyager"

# TODO [23.05] Switch to nix channel once it's in nixos
cd ~/git/nixpkgs
nix build -Lvf . keymapp
cd ~/git/qmk_voyager

echo "Need to flash with keymapp"
sudo ~/git/nixpkgs/result/bin/keymapp

# nix-shell --run "sudo qmk flash voyager_bhipple.bin"  # TODO: fix the nixos udev rules and drop sudo
