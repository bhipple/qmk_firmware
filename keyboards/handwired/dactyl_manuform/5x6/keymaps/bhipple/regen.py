#!/usr/bin/env python3
# Super hack to parse the org file
import os
import re


def main():
    os.chdir(os.path.dirname(__file__))

    with open('keymap.org', 'r') as fh:
        lines = fh.readlines()

    out = '''
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
'''

    section = None
    for ln in lines:
        if ln.startswith('* Notes'):
            continue
        if ln.startswith('*'):
            if section:
                out += '\n  ),\n\n'
            section = ln.split()[1]
            out += f'  [{section}] = LAYOUT_5x6(\n'
            keys = None
        if ln.startswith('|'):
            if '======' in ln:
                continue
            if keys:
                out += '    , '
            else:
                out += '      '
            keys = ln.replace('|', ',')
            keys = re.sub('\s*,(\s*,)+', ',', keys)
            keys = re.sub('^\s*,', '', keys)
            keys = re.sub(',\s*$', '', keys)
            out += f'{keys}\n'
    out += '\n  ),\n};'

    with open('generated.h', 'w') as fh:
        fh.write(out)

main()
