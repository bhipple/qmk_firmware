#!/usr/bin/env python3
# Super hacky compiler for my org file
import os
import re


def keycodes(keycodes):
    res = 'enum my_keycodes {\n    M_UNUSED = SAFE_RANGE,\n'
    for key in keycodes.keys():
        res += f'    {key},\n'

    res += '};\n'

    res += '''
bool generated_keycode_process(uint16_t keycode) {
    switch (keycode) {
'''

    for key, val in keycodes.items():
        res += f'''\
        case {key}:
            SEND_STRING({val});
            break;
'''

    res += '''\
        default:
            break;
    }

    return true;
}
'''
    return res


def main():
    codes = {}
    os.chdir(os.path.dirname(__file__))

    with open('keymap.org', 'r') as fh:
        lines = fh.readlines()

    keymap = ''
    section = None
    i = -1
    while i < len(lines) - 1:
        i += 1
        ln = lines[i]
        if ln.startswith('* Keycodes'):
            i += 1
            ln = lines[i]
            while ln.startswith('|'):
                parts = [x.strip() for x in ln.split('|')]
                codes[parts[1]] = parts[2]
                i += 1
                ln = lines[i]
        if ln.startswith('* Notes'):
            continue
        if ln.startswith('*'):
            if section:
                keymap += '\n  ),\n\n'
            section = ln.split()[1]
            keymap += f'  [{section}] = LAYOUT_5x6(\n'
            keys = None
        if ln.startswith('|'):
            if '======' in ln:
                continue
            if keys:
                keymap += '    , '
            else:
                keymap += '      '
            keys = ln.replace('|', ',')
            keys = re.sub('\s*,(\s*,)+', ',', keys)
            keys = re.sub('^\s*,', '', keys)
            keys = re.sub(',\s*$', '', keys)
            keymap += f'{keys}\n'

    par = '{'
    out = f'''\
#include QMK_KEYBOARD_H

{keycodes(codes)}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {par}

{keymap}

  ),

''' + '};'

    with open('generated.h', 'w') as fh:
        fh.write(out)

main()
