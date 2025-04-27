#!/usr/bin/env python3
# Super hacky compiler for my org file
import argparse
import os


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

# Hard-code the footers in here, since they're all very different per-keyboard
footers = {
    'voyager':   ['KC_INT2', 'KC_SPACE', 'KC_NO', 'KC_NO'],
    'keychron':  ['KC_LCTL', 'KC_LWIN', 'KC_LALT', 'KC_SPC', 'MO(_FN1)',     'MO(_FN3)', 'KC_SPC', 'KC_RALT', 'KC_LEFT', 'KC_DOWN', 'KC_RGHT'],
}

def main():
    parser = argparse.ArgumentParser('Generator for QMK keymaps')
    parser.add_argument('keyboard', choices=['voyager', 'keychron'], help='Keyboard to generate')
    args = parser.parse_args()

    layout = {
        'voyager':   'LAYOUT_voyager',
        'keychron':  'LAYOUT_ansi_69',
    }[args.keyboard]
    footer = footers[args.keyboard]

    codes = {}
    layers = {}

    with open(f'{os.path.dirname(__file__)}/keymap.org', 'r') as fh:
        lines = fh.readlines()

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
        if ln.startswith('* Layer'):
            if section:
                layers[section] = keys + footer
            section = ln.split()[-1]
            keys = []
        if ln.startswith('|'):
            if '======' in ln:
                continue
            keys += [x.strip() for x in ln.split('|') if x.strip()]

    layers[section] = keys + footer  # last layer

    layer_text = ''
    for layer, keys in layers.items():
        layer_text += f'\n\n[{layer}] = {layout}({", ".join(keys)}),'

    out = f'''\
#include QMK_KEYBOARD_H

{keycodes(codes)}

enum layers{{
  {', '.join(layers.keys())}
}};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {{

{layer_text}

}};
'''

    print(out)

main()
