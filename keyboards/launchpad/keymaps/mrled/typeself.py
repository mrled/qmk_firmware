#!/usr/bin/env python3

import base64
import os
import string

thisfile = os.path.realpath(__file__)
thisdir = os.path.dirname(thisfile)
kmbase = os.path.join(thisdir, 'keymap_base.c')
keymap = os.path.join(thisdir, 'keymap.c')

with open(thisfile) as tf:
    thisfile_b64 = base64.b64encode(tf.read().encode())
with open(kmbase) as kmbf:
    kmcontents = kmbf.read()
    kmbase_b64 = base64.b64encode(kmcontents.encode())

templ = string.Template(kmcontents)
keymap_content = templ.safe_substitute({'___keymap': kmbase_b64, '___typeself': thisfile_b64})
with open(keymap, 'w') as kmf:
    kmf.write(keymap_content)

