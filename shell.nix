{ avr ? true, arm ? true, teensy ? true }:

let
  # nixpkgs = builtins.fetchTarball {
  #   url = "https://github.com/NixOS/nixpkgs/archive/c4b26e702044dbf40f8236136c099d8ab6778514.tar.gz";
  #   sha256 = "0w6hgs01qzni3a7cvgadjlmcdlb6vay3w910vh4k9fc949ii7s60";
  # };
  nixpkgs = /home/bhipple/src/nixpkgs;

  pkgs = import nixpkgs { };

in

with pkgs;
let
  avrlibc = pkgsCross.avr.libcCross;

  avr_incflags = [
    "-isystem ${avrlibc}/avr/include"
    "-B${avrlibc}/avr/lib/avr5"
    "-L${avrlibc}/avr/lib/avr5"
    "-B${avrlibc}/avr/lib/avr35"
    "-L${avrlibc}/avr/lib/avr35"
    "-B${avrlibc}/avr/lib/avr51"
    "-L${avrlibc}/avr/lib/avr51"
  ];
in
mkShell {
  name = "qmk-firmware";

  buildInputs = [ dfu-programmer dfu-util diffutils git qmk ]
    ++ lib.optional avr [
      pkgsCross.avr.buildPackages.binutils
      pkgsCross.avr.buildPackages.gcc8
      avrlibc
      avrdude
    ]
    ++ lib.optional arm [ gcc-arm-embedded ]
    ++ lib.optional teensy [ teensy-loader-cli ];

  AVR_CFLAGS = lib.optional avr avr_incflags;
  AVR_ASFLAGS = lib.optional avr avr_incflags;
  shellHook = ''
    # Prevent the avr-gcc wrapper from picking up host GCC flags
    # like -iframework, which is problematic on Darwin
    unset NIX_TARGET_CFLAGS_COMPILE
  '';
}
